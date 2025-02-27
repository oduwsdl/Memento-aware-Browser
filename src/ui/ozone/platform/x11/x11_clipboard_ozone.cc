// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/ozone/platform/x11/x11_clipboard_ozone.h"

#include <algorithm>
#include <vector>

#include "base/containers/span.h"
#include "base/logging.h"
#include "base/stl_util.h"
#include "ui/base/clipboard/clipboard_constants.h"
#include "ui/base/x/x11_util.h"
#include "ui/gfx/x/x11_atom_cache.h"
#include "ui/gfx/x/x11_types.h"

using base::Contains;

namespace ui {

namespace {

const char kChromeSelection[] = "CHROME_SELECTION";
const char kClipboard[] = "CLIPBOARD";
const char kString[] = "STRING";
const char kTargets[] = "TARGETS";
const char kTimestamp[] = "TIMESTAMP";
const char kUtf8String[] = "UTF8_STRING";

// Helps to allow conversions for text/plain[;charset=utf-8] <=> [UTF8_]STRING.
void ExpandTypes(std::vector<std::string>* list) {
  bool has_mime_type_text = Contains(*list, ui::kMimeTypeText);
  bool has_string = Contains(*list, kString);
  bool has_mime_type_utf8 = Contains(*list, kMimeTypeTextUtf8);
  bool has_utf8_string = Contains(*list, kUtf8String);
  if (has_mime_type_text && !has_string)
    list->push_back(kString);
  if (has_string && !has_mime_type_text)
    list->push_back(ui::kMimeTypeText);
  if (has_mime_type_utf8 && !has_utf8_string)
    list->push_back(kUtf8String);
  if (has_utf8_string && !has_mime_type_utf8)
    list->push_back(kMimeTypeTextUtf8);
}

x11::Window FindXEventTarget(const x11::Event& x11_event) {
  const XEvent& xev = x11_event.xlib_event();
  XID target = xev.xany.window;
  if (xev.type == x11::GeGenericEvent::opcode)
    target = static_cast<XIDeviceEvent*>(xev.xcookie.data)->event;
  return static_cast<x11::Window>(target);
}

}  // namespace

// Maintains state of a single selection (aka system clipboard buffer).
struct X11ClipboardOzone::SelectionState {
  SelectionState() = default;
  ~SelectionState() = default;

  // DataMap we keep from |OfferClipboardData| to service remote requests for
  // the clipboard.
  PlatformClipboard::DataMap offer_data_map;

  // DataMap from |RequestClipboardData| that we write remote clipboard
  // contents to before calling the completion callback.
  PlatformClipboard::DataMap* request_data_map = nullptr;

  // Mime types supported by remote clipboard.
  std::vector<std::string> mime_types;

  // Data most recently read from remote clipboard.
  std::vector<unsigned char> data;

  // Mime type of most recently read data from remote clipboard.
  std::string data_mime_type;

  // Callbacks are stored when we haven't already prefetched the remote
  // clipboard.
  PlatformClipboard::GetMimeTypesClosure get_available_mime_types_callback;
  PlatformClipboard::RequestDataClosure request_clipboard_data_callback;

  // The time that this instance took ownership of the clipboard.
  Time acquired_selection_timestamp;
};

X11ClipboardOzone::X11ClipboardOzone()
    : atom_clipboard_(gfx::GetAtom(kClipboard)),
      atom_targets_(gfx::GetAtom(kTargets)),
      atom_timestamp_(gfx::GetAtom(kTimestamp)),
      x_property_(gfx::GetAtom(kChromeSelection)),
      x_display_(gfx::GetXDisplay()),
      x_window_(static_cast<x11::Window>(
          XCreateSimpleWindow(x_display_,
                              DefaultRootWindow(x_display_),
                              /*x=*/-100,
                              /*y=*/-100,
                              /*width=*/10,
                              /*height=*/10,
                              /*border_width=*/0,
                              /*border=*/0,
                              /*background=*/0))) {
  int ignored;  // xfixes_error_base.
  if (!XFixesQueryExtension(x_display_, &xfixes_event_base_, &ignored)) {
    LOG(ERROR) << "X server does not support XFixes.";
    return;
  }
  using_xfixes_ = true;

  // Register to receive standard X11 events.
  X11EventSource::GetInstance()->AddXEventDispatcher(this);

  for (auto atom : {atom_clipboard_, x11::Atom::PRIMARY}) {
    // Register the selection state.
    selection_state_.emplace(atom, std::make_unique<SelectionState>());
    // Register to receive XFixes notification when selection owner changes.
    XFixesSelectSelectionInput(x_display_, static_cast<uint32_t>(x_window_),
                               static_cast<uint32_t>(atom),
                               XFixesSetSelectionOwnerNotifyMask);
    // Prefetch the current remote clipboard contents.
    QueryTargets(atom);
  }
}

X11ClipboardOzone::~X11ClipboardOzone() {
  X11EventSource::GetInstance()->RemoveXEventDispatcher(this);
}

bool X11ClipboardOzone::DispatchXEvent(x11::Event* x11_event) {
  XEvent* xev = &x11_event->xlib_event();
  if (FindXEventTarget(*x11_event) != x_window_)
    return false;

  switch (xev->type) {
    case x11::SelectionRequestEvent::opcode:
      return OnSelectionRequest(xev->xselectionrequest);
    case x11::SelectionNotifyEvent::opcode:
      return OnSelectionNotify(xev->xselection);
  }

  if (using_xfixes_ &&
      xev->type == xfixes_event_base_ + XFixesSetSelectionOwnerNotify) {
    return OnSetSelectionOwnerNotify(x11_event);
  }

  return false;
}

// We are the clipboard owner, and a remote peer has requested either:
// TARGETS: List of mime types that we support for the clipboard.
// TIMESTAMP: Time when we took ownership of the clipboard.
// <mime-type>: Mime type to receive clipboard as.
bool X11ClipboardOzone::OnSelectionRequest(
    const XSelectionRequestEvent& event) {
  // The property must be set.
  if (event.property == x11::None)
    return false;

  // target=TARGETS.
  auto& selection_state =
      GetSelectionState(static_cast<x11::Atom>(event.selection));
  auto target = static_cast<x11::Atom>(event.target);
  PlatformClipboard::DataMap& offer_data_map = selection_state.offer_data_map;
  if (target == atom_targets_) {
    std::vector<std::string> targets;
    // Add TIMESTAMP.
    targets.push_back(kTimestamp);
    for (auto& entry : offer_data_map) {
      targets.push_back(entry.first);
    }
    // Expand types, then convert from string to atom.
    ExpandTypes(&targets);
    std::vector<x11::Atom> atoms;
    for (auto& entry : targets) {
      atoms.push_back(gfx::GetAtom(entry.c_str()));
    }
    XChangeProperty(x_display_, event.requestor, event.property, XA_ATOM,
                    /*format=*/32, PropModeReplace,
                    reinterpret_cast<unsigned char*>(atoms.data()),
                    atoms.size());

  } else if (target == atom_timestamp_) {
    // target=TIMESTAMP.
    XChangeProperty(x_display_, event.requestor, event.property, XA_INTEGER,
                    /*format=*/32, PropModeReplace,
                    reinterpret_cast<unsigned char*>(
                        &selection_state.acquired_selection_timestamp),
                    1);

  } else {
    // Send clipboard data.
    char* target_name = XGetAtomName(x_display_, event.target);

    std::string key = target_name;
    // Allow conversions for text/plain[;charset=utf-8] <=> [UTF8_]STRING.
    if (key == kUtf8String && !Contains(offer_data_map, kUtf8String)) {
      key = kMimeTypeTextUtf8;
    } else if (key == kString && !Contains(offer_data_map, kString)) {
      key = kMimeTypeText;
    }
    auto it = offer_data_map.find(key);
    if (it != offer_data_map.end()) {
      XChangeProperty(x_display_, event.requestor, event.property, event.target,
                      /*format=*/8, PropModeReplace,
                      const_cast<unsigned char*>(it->second.data()),
                      it->second.size());
    }
    XFree(target_name);
  }

  // Notify remote peer that clipboard has been sent.
  XSelectionEvent selection_event;
  selection_event.type = SelectionNotify;
  selection_event.display = event.display;
  selection_event.requestor = event.requestor;
  selection_event.selection = event.selection;
  selection_event.target = event.target;
  selection_event.property = event.property;
  selection_event.time = event.time;
  XSendEvent(x_display_, selection_event.requestor, /*propagate=*/x11::False,
             /*event_mask=*/0, reinterpret_cast<XEvent*>(&selection_event));
  return true;
}

// A remote peer owns the clipboard.  This event is received in response to
// our request for TARGETS (GetAvailableMimeTypes), or a specific mime type
// (RequestClipboardData).
bool X11ClipboardOzone::OnSelectionNotify(const XSelectionEvent& event) {
  // GetAvailableMimeTypes.
  auto selection = static_cast<x11::Atom>(event.selection);
  auto& selection_state = GetSelectionState(selection);
  if (static_cast<x11::Atom>(event.target) == atom_targets_) {
    std::vector<x11::Atom> targets;
    ui::GetArrayProperty(x_window_, x_property_, &targets);

    selection_state.mime_types.clear();
    for (auto target : targets) {
      char* atom_name = XGetAtomName(x_display_, static_cast<uint32_t>(target));
      if (atom_name) {
        selection_state.mime_types.push_back(atom_name);
        XFree(atom_name);
      }
    }

    // If we have a saved callback, invoke it now with expanded types, otherwise
    // guess that we will want 'text/plain' and fetch it now.
    if (selection_state.get_available_mime_types_callback) {
      std::vector<std::string> result(selection_state.mime_types);
      ExpandTypes(&result);
      std::move(selection_state.get_available_mime_types_callback)
          .Run(std::move(result));
    } else {
      selection_state.data_mime_type = kMimeTypeText;
      ReadRemoteClipboard(selection);
    }

    return true;
  }

  // RequestClipboardData.
  if (static_cast<x11::Atom>(event.property) == x_property_) {
    x11::Atom type;
    std::vector<uint8_t> data;
    ui::GetArrayProperty(x_window_, x_property_, &data, &type);
    ui::DeleteProperty(x_window_, x_property_);
    if (type != x11::Atom::None)
      selection_state.data = std::move(data);

    // If we have a saved callback, invoke it now, otherwise this was a prefetch
    // and we have already saved |data_| for the next call to
    // |RequestClipboardData|.
    if (selection_state.request_clipboard_data_callback) {
      selection_state.request_data_map->emplace(selection_state.data_mime_type,
                                                selection_state.data);
      std::move(selection_state.request_clipboard_data_callback)
          .Run(selection_state.data);
    }
    return true;
  }

  return false;
}

bool X11ClipboardOzone::OnSetSelectionOwnerNotify(x11::Event* xev) {
  XFixesSelectionNotifyEvent* event =
      reinterpret_cast<XFixesSelectionNotifyEvent*>(&xev->xlib_event());

  // Reset state and fetch remote clipboard if there is a new remote owner.
  auto selection = static_cast<x11::Atom>(event->selection);
  if (!IsSelectionOwner(BufferForSelectionAtom(selection))) {
    auto& selection_state = GetSelectionState(selection);
    selection_state.mime_types.clear();
    selection_state.data_mime_type.clear();
    selection_state.data.clear();
    QueryTargets(selection);
  }

  // Increase the sequence number if the callback is set.
  if (update_sequence_cb_)
    update_sequence_cb_.Run(BufferForSelectionAtom(selection));

  return true;
}

x11::Atom X11ClipboardOzone::SelectionAtomForBuffer(
    ClipboardBuffer buffer) const {
  switch (buffer) {
    case ClipboardBuffer::kCopyPaste:
      return atom_clipboard_;
    case ClipboardBuffer::kSelection:
      return x11::Atom::PRIMARY;
    default:
      NOTREACHED();
      return x11::Atom::None;
  }
}

ClipboardBuffer X11ClipboardOzone::BufferForSelectionAtom(
    x11::Atom selection) const {
  if (selection == x11::Atom::PRIMARY)
    return ClipboardBuffer::kSelection;
  if (selection == atom_clipboard_)
    return ClipboardBuffer::kCopyPaste;
  NOTREACHED();
  return ClipboardBuffer::kCopyPaste;
}

X11ClipboardOzone::SelectionState& X11ClipboardOzone::GetSelectionState(
    x11::Atom selection) {
  DCHECK(Contains(selection_state_, selection));
  return *selection_state_[selection];
}

void X11ClipboardOzone::QueryTargets(x11::Atom selection) {
  GetSelectionState(selection).mime_types.clear();
  XConvertSelection(x_display_, static_cast<uint32_t>(selection),
                    static_cast<uint32_t>(atom_targets_),
                    static_cast<uint32_t>(x_property_),
                    static_cast<uint32_t>(x_window_), x11::CurrentTime);
}

void X11ClipboardOzone::ReadRemoteClipboard(x11::Atom selection) {
  auto& selection_state = GetSelectionState(selection);
  selection_state.data.clear();
  // Allow conversions for text/plain[;charset=utf-8] <=> [UTF8_]STRING.
  std::string target = selection_state.data_mime_type;
  if (!Contains(selection_state.mime_types, target)) {
    if (target == kMimeTypeText) {
      target = kString;
    } else if (target == kMimeTypeTextUtf8) {
      target = kUtf8String;
    }
  }

  XConvertSelection(x_display_, static_cast<uint32_t>(selection),
                    static_cast<uint32_t>(gfx::GetAtom(target)),
                    static_cast<uint32_t>(x_property_),
                    static_cast<uint32_t>(x_window_), x11::CurrentTime);
}

void X11ClipboardOzone::OfferClipboardData(
    ClipboardBuffer buffer,
    const PlatformClipboard::DataMap& data_map,
    PlatformClipboard::OfferDataClosure callback) {
  const x11::Atom selection = SelectionAtomForBuffer(buffer);
  auto& selection_state = GetSelectionState(selection);
  const auto timestamp = X11EventSource::GetInstance()->GetTimestamp();
  selection_state.acquired_selection_timestamp = timestamp;
  selection_state.offer_data_map = data_map;
  // Only take ownership if we are using xfixes.
  // TODO(joelhockey): Make clipboard work without xfixes.
  if (using_xfixes_) {
    XSetSelectionOwner(x_display_, static_cast<uint32_t>(selection),
                       static_cast<uint32_t>(x_window_), timestamp);
  }
  std::move(callback).Run();
}

void X11ClipboardOzone::RequestClipboardData(
    ClipboardBuffer buffer,
    const std::string& mime_type,
    PlatformClipboard::DataMap* data_map,
    PlatformClipboard::RequestDataClosure callback) {
  const x11::Atom selection = SelectionAtomForBuffer(buffer);
  auto& selection_state = GetSelectionState(selection);
  // If we are not using xfixes, return empty data.
  // TODO(joelhockey): Make clipboard work without xfixes.
  // If we have already prefetched the clipboard for the correct mime type,
  // then send it right away, otherwise save the callback and attempt to get the
  // requested mime type from the remote clipboard.
  if (!using_xfixes_ || (selection_state.data_mime_type == mime_type &&
                         !selection_state.data.empty())) {
    data_map->emplace(mime_type, selection_state.data);
    std::move(callback).Run(selection_state.data);
    return;
  }
  selection_state.data_mime_type = mime_type;
  selection_state.request_data_map = data_map;
  DCHECK(selection_state.request_clipboard_data_callback.is_null());
  selection_state.request_clipboard_data_callback = std::move(callback);
  ReadRemoteClipboard(selection);
}

void X11ClipboardOzone::GetAvailableMimeTypes(
    ClipboardBuffer buffer,
    PlatformClipboard::GetMimeTypesClosure callback) {
  const x11::Atom selection = SelectionAtomForBuffer(buffer);
  auto& selection_state = GetSelectionState(selection);
  // If we are not using xfixes, return empty data.
  // TODO(joelhockey): Make clipboard work without xfixes.
  // If we already have the list of supported mime types, send the expanded list
  // of types right away, otherwise save the callback and get the list of
  // TARGETS from the remote clipboard.
  if (!using_xfixes_ || !selection_state.mime_types.empty()) {
    std::vector<std::string> result(selection_state.mime_types);
    ExpandTypes(&result);
    std::move(callback).Run(std::move(result));
    return;
  }
  DCHECK(selection_state.get_available_mime_types_callback.is_null());
  selection_state.get_available_mime_types_callback = std::move(callback);
  QueryTargets(selection);
}

bool X11ClipboardOzone::IsSelectionOwner(ClipboardBuffer buffer) {
  // If we are not using xfixes, then we are always the owner.
  // TODO(joelhockey): Make clipboard work without xfixes.
  if (!using_xfixes_)
    return true;

  return XGetSelectionOwner(x_display_, static_cast<uint32_t>(
                                            SelectionAtomForBuffer(buffer))) ==
         static_cast<uint32_t>(x_window_);
}

void X11ClipboardOzone::SetSequenceNumberUpdateCb(
    PlatformClipboard::SequenceNumberUpdateCb cb) {
  update_sequence_cb_ = std::move(cb);
}

}  // namespace ui
