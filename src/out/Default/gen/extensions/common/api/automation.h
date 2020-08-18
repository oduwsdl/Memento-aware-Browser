// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/automation.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_AUTOMATION_H__
#define EXTENSIONS_COMMON_API_AUTOMATION_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace automation {

//
// Types
//

// Possible events fired on an $(ref:automation.AutomationNode).
enum EventType {
  EVENT_TYPE_NONE,
  EVENT_TYPE_ACTIVEDESCENDANTCHANGED,
  EVENT_TYPE_ALERT,
  EVENT_TYPE_ARIAATTRIBUTECHANGED,
  EVENT_TYPE_AUTOCORRECTIONOCCURED,
  EVENT_TYPE_BLUR,
  EVENT_TYPE_CHECKEDSTATECHANGED,
  EVENT_TYPE_CHILDRENCHANGED,
  EVENT_TYPE_CLICKED,
  EVENT_TYPE_CONTROLSCHANGED,
  EVENT_TYPE_DOCUMENTSELECTIONCHANGED,
  EVENT_TYPE_DOCUMENTTITLECHANGED,
  EVENT_TYPE_ENDOFTEST,
  EVENT_TYPE_EXPANDEDCHANGED,
  EVENT_TYPE_FOCUS,
  EVENT_TYPE_FOCUSAFTERMENUCLOSE,
  EVENT_TYPE_FOCUSCONTEXT,
  EVENT_TYPE_HIDE,
  EVENT_TYPE_HITTESTRESULT,
  EVENT_TYPE_HOVER,
  EVENT_TYPE_IMAGEFRAMEUPDATED,
  EVENT_TYPE_INVALIDSTATUSCHANGED,
  EVENT_TYPE_LAYOUTCOMPLETE,
  EVENT_TYPE_LIVEREGIONCHANGED,
  EVENT_TYPE_LIVEREGIONCREATED,
  EVENT_TYPE_LOADCOMPLETE,
  EVENT_TYPE_LOADSTART,
  EVENT_TYPE_LOCATIONCHANGED,
  EVENT_TYPE_MEDIASTARTEDPLAYING,
  EVENT_TYPE_MEDIASTOPPEDPLAYING,
  EVENT_TYPE_MENUEND,
  EVENT_TYPE_MENULISTITEMSELECTED,
  EVENT_TYPE_MENULISTVALUECHANGED,
  EVENT_TYPE_MENUPOPUPEND,
  EVENT_TYPE_MENUPOPUPSTART,
  EVENT_TYPE_MENUSTART,
  EVENT_TYPE_MOUSECANCELED,
  EVENT_TYPE_MOUSEDRAGGED,
  EVENT_TYPE_MOUSEMOVED,
  EVENT_TYPE_MOUSEPRESSED,
  EVENT_TYPE_MOUSERELEASED,
  EVENT_TYPE_ROWCOLLAPSED,
  EVENT_TYPE_ROWCOUNTCHANGED,
  EVENT_TYPE_ROWEXPANDED,
  EVENT_TYPE_SCROLLPOSITIONCHANGED,
  EVENT_TYPE_SCROLLEDTOANCHOR,
  EVENT_TYPE_SELECTEDCHILDRENCHANGED,
  EVENT_TYPE_SELECTION,
  EVENT_TYPE_SELECTIONADD,
  EVENT_TYPE_SELECTIONREMOVE,
  EVENT_TYPE_SHOW,
  EVENT_TYPE_STATECHANGED,
  EVENT_TYPE_TEXTCHANGED,
  EVENT_TYPE_TEXTSELECTIONCHANGED,
  EVENT_TYPE_TOOLTIPCLOSED,
  EVENT_TYPE_TOOLTIPOPENED,
  EVENT_TYPE_WINDOWACTIVATED,
  EVENT_TYPE_WINDOWDEACTIVATED,
  EVENT_TYPE_WINDOWVISIBILITYCHANGED,
  EVENT_TYPE_TREECHANGED,
  EVENT_TYPE_VALUECHANGED,
  EVENT_TYPE_LAST = EVENT_TYPE_VALUECHANGED,
};


const char* ToString(EventType as_enum);
EventType ParseEventType(const std::string& as_string);

// Describes the purpose of an $(ref:automation.AutomationNode).
enum RoleType {
  ROLE_TYPE_NONE,
  ROLE_TYPE_ABBR,
  ROLE_TYPE_ALERT,
  ROLE_TYPE_ALERTDIALOG,
  ROLE_TYPE_ANCHOR,
  ROLE_TYPE_APPLICATION,
  ROLE_TYPE_ARTICLE,
  ROLE_TYPE_AUDIO,
  ROLE_TYPE_BANNER,
  ROLE_TYPE_BLOCKQUOTE,
  ROLE_TYPE_BUTTON,
  ROLE_TYPE_CANVAS,
  ROLE_TYPE_CAPTION,
  ROLE_TYPE_CARET,
  ROLE_TYPE_CELL,
  ROLE_TYPE_CHECKBOX,
  ROLE_TYPE_CLIENT,
  ROLE_TYPE_CODE,
  ROLE_TYPE_COLORWELL,
  ROLE_TYPE_COLUMN,
  ROLE_TYPE_COLUMNHEADER,
  ROLE_TYPE_COMBOBOXGROUPING,
  ROLE_TYPE_COMBOBOXMENUBUTTON,
  ROLE_TYPE_COMMENT,
  ROLE_TYPE_COMPLEMENTARY,
  ROLE_TYPE_CONTENTDELETION,
  ROLE_TYPE_CONTENTINSERTION,
  ROLE_TYPE_CONTENTINFO,
  ROLE_TYPE_DATE,
  ROLE_TYPE_DATETIME,
  ROLE_TYPE_DEFINITION,
  ROLE_TYPE_DESCRIPTIONLIST,
  ROLE_TYPE_DESCRIPTIONLISTDETAIL,
  ROLE_TYPE_DESCRIPTIONLISTTERM,
  ROLE_TYPE_DESKTOP,
  ROLE_TYPE_DETAILS,
  ROLE_TYPE_DIALOG,
  ROLE_TYPE_DIRECTORY,
  ROLE_TYPE_DISCLOSURETRIANGLE,
  ROLE_TYPE_DOCABSTRACT,
  ROLE_TYPE_DOCACKNOWLEDGMENTS,
  ROLE_TYPE_DOCAFTERWORD,
  ROLE_TYPE_DOCAPPENDIX,
  ROLE_TYPE_DOCBACKLINK,
  ROLE_TYPE_DOCBIBLIOENTRY,
  ROLE_TYPE_DOCBIBLIOGRAPHY,
  ROLE_TYPE_DOCBIBLIOREF,
  ROLE_TYPE_DOCCHAPTER,
  ROLE_TYPE_DOCCOLOPHON,
  ROLE_TYPE_DOCCONCLUSION,
  ROLE_TYPE_DOCCOVER,
  ROLE_TYPE_DOCCREDIT,
  ROLE_TYPE_DOCCREDITS,
  ROLE_TYPE_DOCDEDICATION,
  ROLE_TYPE_DOCENDNOTE,
  ROLE_TYPE_DOCENDNOTES,
  ROLE_TYPE_DOCEPIGRAPH,
  ROLE_TYPE_DOCEPILOGUE,
  ROLE_TYPE_DOCERRATA,
  ROLE_TYPE_DOCEXAMPLE,
  ROLE_TYPE_DOCFOOTNOTE,
  ROLE_TYPE_DOCFOREWORD,
  ROLE_TYPE_DOCGLOSSARY,
  ROLE_TYPE_DOCGLOSSREF,
  ROLE_TYPE_DOCINDEX,
  ROLE_TYPE_DOCINTRODUCTION,
  ROLE_TYPE_DOCNOTEREF,
  ROLE_TYPE_DOCNOTICE,
  ROLE_TYPE_DOCPAGEBREAK,
  ROLE_TYPE_DOCPAGELIST,
  ROLE_TYPE_DOCPART,
  ROLE_TYPE_DOCPREFACE,
  ROLE_TYPE_DOCPROLOGUE,
  ROLE_TYPE_DOCPULLQUOTE,
  ROLE_TYPE_DOCQNA,
  ROLE_TYPE_DOCSUBTITLE,
  ROLE_TYPE_DOCTIP,
  ROLE_TYPE_DOCTOC,
  ROLE_TYPE_DOCUMENT,
  ROLE_TYPE_EMBEDDEDOBJECT,
  ROLE_TYPE_EMPHASIS,
  ROLE_TYPE_FEED,
  ROLE_TYPE_FIGCAPTION,
  ROLE_TYPE_FIGURE,
  ROLE_TYPE_FOOTER,
  ROLE_TYPE_FOOTERASNONLANDMARK,
  ROLE_TYPE_FORM,
  ROLE_TYPE_GENERICCONTAINER,
  ROLE_TYPE_GRAPHICSDOCUMENT,
  ROLE_TYPE_GRAPHICSOBJECT,
  ROLE_TYPE_GRAPHICSSYMBOL,
  ROLE_TYPE_GRID,
  ROLE_TYPE_GROUP,
  ROLE_TYPE_HEADER,
  ROLE_TYPE_HEADERASNONLANDMARK,
  ROLE_TYPE_HEADING,
  ROLE_TYPE_IFRAME,
  ROLE_TYPE_IFRAMEPRESENTATIONAL,
  ROLE_TYPE_IGNORED,
  ROLE_TYPE_IMAGE,
  ROLE_TYPE_IMAGEMAP,
  ROLE_TYPE_IMECANDIDATE,
  ROLE_TYPE_INLINETEXTBOX,
  ROLE_TYPE_INPUTTIME,
  ROLE_TYPE_KEYBOARD,
  ROLE_TYPE_LABELTEXT,
  ROLE_TYPE_LAYOUTTABLE,
  ROLE_TYPE_LAYOUTTABLECELL,
  ROLE_TYPE_LAYOUTTABLEROW,
  ROLE_TYPE_LEGEND,
  ROLE_TYPE_LINEBREAK,
  ROLE_TYPE_LINK,
  ROLE_TYPE_LIST,
  ROLE_TYPE_LISTBOX,
  ROLE_TYPE_LISTBOXOPTION,
  ROLE_TYPE_LISTGRID,
  ROLE_TYPE_LISTITEM,
  ROLE_TYPE_LISTMARKER,
  ROLE_TYPE_LOG,
  ROLE_TYPE_MAIN,
  ROLE_TYPE_MARK,
  ROLE_TYPE_MARQUEE,
  ROLE_TYPE_MATH,
  ROLE_TYPE_MENU,
  ROLE_TYPE_MENUBAR,
  ROLE_TYPE_MENUBUTTON,
  ROLE_TYPE_MENUITEM,
  ROLE_TYPE_MENUITEMCHECKBOX,
  ROLE_TYPE_MENUITEMRADIO,
  ROLE_TYPE_MENULISTOPTION,
  ROLE_TYPE_MENULISTPOPUP,
  ROLE_TYPE_METER,
  ROLE_TYPE_NAVIGATION,
  ROLE_TYPE_NOTE,
  ROLE_TYPE_PANE,
  ROLE_TYPE_PARAGRAPH,
  ROLE_TYPE_PDFACTIONABLEHIGHLIGHT,
  ROLE_TYPE_PLUGINOBJECT,
  ROLE_TYPE_POPUPBUTTON,
  ROLE_TYPE_PORTAL,
  ROLE_TYPE_PRE,
  ROLE_TYPE_PRESENTATIONAL,
  ROLE_TYPE_PROGRESSINDICATOR,
  ROLE_TYPE_RADIOBUTTON,
  ROLE_TYPE_RADIOGROUP,
  ROLE_TYPE_REGION,
  ROLE_TYPE_ROOTWEBAREA,
  ROLE_TYPE_ROW,
  ROLE_TYPE_ROWGROUP,
  ROLE_TYPE_ROWHEADER,
  ROLE_TYPE_RUBY,
  ROLE_TYPE_RUBYANNOTATION,
  ROLE_TYPE_SCROLLBAR,
  ROLE_TYPE_SCROLLVIEW,
  ROLE_TYPE_SEARCH,
  ROLE_TYPE_SEARCHBOX,
  ROLE_TYPE_SECTION,
  ROLE_TYPE_SLIDER,
  ROLE_TYPE_SLIDERTHUMB,
  ROLE_TYPE_SPINBUTTON,
  ROLE_TYPE_SPLITTER,
  ROLE_TYPE_STATICTEXT,
  ROLE_TYPE_STATUS,
  ROLE_TYPE_STRONG,
  ROLE_TYPE_SUGGESTION,
  ROLE_TYPE_SVGROOT,
  ROLE_TYPE_SWITCH,
  ROLE_TYPE_TAB,
  ROLE_TYPE_TABLIST,
  ROLE_TYPE_TABPANEL,
  ROLE_TYPE_TABLE,
  ROLE_TYPE_TABLEHEADERCONTAINER,
  ROLE_TYPE_TERM,
  ROLE_TYPE_TEXTFIELD,
  ROLE_TYPE_TEXTFIELDWITHCOMBOBOX,
  ROLE_TYPE_TIME,
  ROLE_TYPE_TIMER,
  ROLE_TYPE_TITLEBAR,
  ROLE_TYPE_TOGGLEBUTTON,
  ROLE_TYPE_TOOLBAR,
  ROLE_TYPE_TOOLTIP,
  ROLE_TYPE_TREE,
  ROLE_TYPE_TREEGRID,
  ROLE_TYPE_TREEITEM,
  ROLE_TYPE_UNKNOWN,
  ROLE_TYPE_VIDEO,
  ROLE_TYPE_WEBAREA,
  ROLE_TYPE_WEBVIEW,
  ROLE_TYPE_WINDOW,
  ROLE_TYPE_LAST = ROLE_TYPE_WINDOW,
};


const char* ToString(RoleType as_enum);
RoleType ParseRoleType(const std::string& as_string);

// Describes characteristics of an $(ref:automation.AutomationNode).
enum StateType {
  STATE_TYPE_NONE,
  STATE_TYPE_AUTOFILLAVAILABLE,
  STATE_TYPE_COLLAPSED,
  STATE_TYPE_DEFAULT,
  STATE_TYPE_EDITABLE,
  STATE_TYPE_EXPANDED,
  STATE_TYPE_FOCUSABLE,
  STATE_TYPE_FOCUSED,
  STATE_TYPE_HORIZONTAL,
  STATE_TYPE_HOVERED,
  STATE_TYPE_IGNORED,
  STATE_TYPE_INVISIBLE,
  STATE_TYPE_LINKED,
  STATE_TYPE_MULTILINE,
  STATE_TYPE_MULTISELECTABLE,
  STATE_TYPE_OFFSCREEN,
  STATE_TYPE_PROTECTED,
  STATE_TYPE_REQUIRED,
  STATE_TYPE_RICHLYEDITABLE,
  STATE_TYPE_VERTICAL,
  STATE_TYPE_VISITED,
  STATE_TYPE_LAST = STATE_TYPE_VISITED,
};


const char* ToString(StateType as_enum);
StateType ParseStateType(const std::string& as_string);

// All possible actions that can be performed on automation nodes.
enum ActionType {
  ACTION_TYPE_NONE,
  ACTION_TYPE_ANNOTATEPAGEIMAGES,
  ACTION_TYPE_BLUR,
  ACTION_TYPE_CLEARACCESSIBILITYFOCUS,
  ACTION_TYPE_COLLAPSE,
  ACTION_TYPE_CUSTOMACTION,
  ACTION_TYPE_DECREMENT,
  ACTION_TYPE_DODEFAULT,
  ACTION_TYPE_EXPAND,
  ACTION_TYPE_FOCUS,
  ACTION_TYPE_GETIMAGEDATA,
  ACTION_TYPE_GETTEXTLOCATION,
  ACTION_TYPE_HIDETOOLTIP,
  ACTION_TYPE_HITTEST,
  ACTION_TYPE_INCREMENT,
  ACTION_TYPE_INTERNALINVALIDATETREE,
  ACTION_TYPE_LOADINLINETEXTBOXES,
  ACTION_TYPE_REPLACESELECTEDTEXT,
  ACTION_TYPE_SCROLLBACKWARD,
  ACTION_TYPE_SCROLLDOWN,
  ACTION_TYPE_SCROLLFORWARD,
  ACTION_TYPE_SCROLLLEFT,
  ACTION_TYPE_SCROLLRIGHT,
  ACTION_TYPE_SCROLLUP,
  ACTION_TYPE_SCROLLTOMAKEVISIBLE,
  ACTION_TYPE_SCROLLTOPOINT,
  ACTION_TYPE_SETACCESSIBILITYFOCUS,
  ACTION_TYPE_SETSCROLLOFFSET,
  ACTION_TYPE_SETSELECTION,
  ACTION_TYPE_SETSEQUENTIALFOCUSNAVIGATIONSTARTINGPOINT,
  ACTION_TYPE_SETVALUE,
  ACTION_TYPE_SHOWCONTEXTMENU,
  ACTION_TYPE_SIGNALENDOFTEST,
  ACTION_TYPE_SHOWTOOLTIP,
  ACTION_TYPE_LAST = ACTION_TYPE_SHOWTOOLTIP,
};


const char* ToString(ActionType as_enum);
ActionType ParseActionType(const std::string& as_string);

// <p>Possible changes to the automation tree. For any given atomic change to
// the tree, each node that's added, removed, or changed, will appear in exactly
// one TreeChange, with one of these types.</p><p>nodeCreated means that this
// node was added to the tree and its parent is new as well, so it's just one
// node in a new subtree that was added.</p>
enum TreeChangeType {
  TREE_CHANGE_TYPE_NONE,
  TREE_CHANGE_TYPE_NODECREATED,
  TREE_CHANGE_TYPE_SUBTREECREATED,
  TREE_CHANGE_TYPE_NODECHANGED,
  TREE_CHANGE_TYPE_TEXTCHANGED,
  TREE_CHANGE_TYPE_NODEREMOVED,
  TREE_CHANGE_TYPE_SUBTREEUPDATEEND,
  TREE_CHANGE_TYPE_LAST = TREE_CHANGE_TYPE_SUBTREEUPDATEEND,
};


const char* ToString(TreeChangeType as_enum);
TreeChangeType ParseTreeChangeType(const std::string& as_string);

// Where the node's name is from.
enum NameFromType {
  NAME_FROM_TYPE_NONE,
  NAME_FROM_TYPE_UNINITIALIZED,
  NAME_FROM_TYPE_ATTRIBUTE,
  NAME_FROM_TYPE_ATTRIBUTEEXPLICITLYEMPTY,
  NAME_FROM_TYPE_CAPTION,
  NAME_FROM_TYPE_CONTENTS,
  NAME_FROM_TYPE_PLACEHOLDER,
  NAME_FROM_TYPE_RELATEDELEMENT,
  NAME_FROM_TYPE_TITLE,
  NAME_FROM_TYPE_VALUE,
  NAME_FROM_TYPE_LAST = NAME_FROM_TYPE_VALUE,
};


const char* ToString(NameFromType as_enum);
NameFromType ParseNameFromType(const std::string& as_string);

enum DescriptionFromType {
  DESCRIPTION_FROM_TYPE_NONE,
  DESCRIPTION_FROM_TYPE_UNINITIALIZED,
  DESCRIPTION_FROM_TYPE_ATTRIBUTE,
  DESCRIPTION_FROM_TYPE_CONTENTS,
  DESCRIPTION_FROM_TYPE_RELATEDELEMENT,
  DESCRIPTION_FROM_TYPE_TITLE,
  DESCRIPTION_FROM_TYPE_LAST = DESCRIPTION_FROM_TYPE_TITLE,
};


const char* ToString(DescriptionFromType as_enum);
DescriptionFromType ParseDescriptionFromType(const std::string& as_string);

// The input restriction for a object -- even non-controls can be disabled.
enum Restriction {
  RESTRICTION_NONE,
  RESTRICTION_DISABLED,
  RESTRICTION_READONLY,
  RESTRICTION_LAST = RESTRICTION_READONLY,
};


const char* ToString(Restriction as_enum);
Restriction ParseRestriction(const std::string& as_string);

// Indicates the availability and type of interactive popup element
enum HasPopup {
  HAS_POPUP_NONE,
  HAS_POPUP_TRUE,
  HAS_POPUP_MENU,
  HAS_POPUP_LISTBOX,
  HAS_POPUP_TREE,
  HAS_POPUP_GRID,
  HAS_POPUP_DIALOG,
  HAS_POPUP_LAST = HAS_POPUP_DIALOG,
};


const char* ToString(HasPopup as_enum);
HasPopup ParseHasPopup(const std::string& as_string);

// Describes possible actions when performing a do default action.
enum DefaultActionVerb {
  DEFAULT_ACTION_VERB_NONE,
  DEFAULT_ACTION_VERB_ACTIVATE,
  DEFAULT_ACTION_VERB_CHECK,
  DEFAULT_ACTION_VERB_CLICK,
  DEFAULT_ACTION_VERB_CLICKANCESTOR,
  DEFAULT_ACTION_VERB_JUMP,
  DEFAULT_ACTION_VERB_OPEN,
  DEFAULT_ACTION_VERB_PRESS,
  DEFAULT_ACTION_VERB_SELECT,
  DEFAULT_ACTION_VERB_UNCHECK,
  DEFAULT_ACTION_VERB_LAST = DEFAULT_ACTION_VERB_UNCHECK,
};


const char* ToString(DefaultActionVerb as_enum);
DefaultActionVerb ParseDefaultActionVerb(const std::string& as_string);

// Types of markers on text. See <code>AutomationNode.markerTypes</code>.
enum MarkerType {
  MARKER_TYPE_NONE,
  MARKER_TYPE_SPELLING,
  MARKER_TYPE_GRAMMAR,
  MARKER_TYPE_TEXTMATCH,
  MARKER_TYPE_ACTIVESUGGESTION,
  MARKER_TYPE_SUGGESTION,
  MARKER_TYPE_LAST = MARKER_TYPE_SUGGESTION,
};


const char* ToString(MarkerType as_enum);
MarkerType ParseMarkerType(const std::string& as_string);

// A command associated with an AutomationEvent.
enum EventCommandType {
  EVENT_COMMAND_TYPE_NONE,
  EVENT_COMMAND_TYPE_CLEARSELECTION,
  EVENT_COMMAND_TYPE_CUT,
  EVENT_COMMAND_TYPE_DELETE,
  EVENT_COMMAND_TYPE_DICTATE,
  EVENT_COMMAND_TYPE_EXTENDSELECTION,
  EVENT_COMMAND_TYPE_FORMAT,
  EVENT_COMMAND_TYPE_INSERT,
  EVENT_COMMAND_TYPE_MARKER,
  EVENT_COMMAND_TYPE_MOVESELECTION,
  EVENT_COMMAND_TYPE_PASTE,
  EVENT_COMMAND_TYPE_REPLACE,
  EVENT_COMMAND_TYPE_SETSELECTION,
  EVENT_COMMAND_TYPE_TYPE,
  EVENT_COMMAND_TYPE_LAST = EVENT_COMMAND_TYPE_TYPE,
};


const char* ToString(EventCommandType as_enum);
EventCommandType ParseEventCommandType(const std::string& as_string);

// A text boundary associated with an AutomationEvent.
enum EventTextBoundaryType {
  EVENT_TEXT_BOUNDARY_TYPE_NONE,
  EVENT_TEXT_BOUNDARY_TYPE_CHARACTER,
  EVENT_TEXT_BOUNDARY_TYPE_FORMAT,
  EVENT_TEXT_BOUNDARY_TYPE_LINEEND,
  EVENT_TEXT_BOUNDARY_TYPE_LINESTART,
  EVENT_TEXT_BOUNDARY_TYPE_LINESTARTOREND,
  EVENT_TEXT_BOUNDARY_TYPE_OBJECT,
  EVENT_TEXT_BOUNDARY_TYPE_PAGEEND,
  EVENT_TEXT_BOUNDARY_TYPE_PAGESTART,
  EVENT_TEXT_BOUNDARY_TYPE_PAGESTARTOREND,
  EVENT_TEXT_BOUNDARY_TYPE_PARAGRAPHEND,
  EVENT_TEXT_BOUNDARY_TYPE_PARAGRAPHSTART,
  EVENT_TEXT_BOUNDARY_TYPE_PARAGRAPHSTARTOREND,
  EVENT_TEXT_BOUNDARY_TYPE_SENTENCEEND,
  EVENT_TEXT_BOUNDARY_TYPE_SENTENCESTART,
  EVENT_TEXT_BOUNDARY_TYPE_SENTENCESTARTOREND,
  EVENT_TEXT_BOUNDARY_TYPE_WEBPAGE,
  EVENT_TEXT_BOUNDARY_TYPE_WORDEND,
  EVENT_TEXT_BOUNDARY_TYPE_WORDSTART,
  EVENT_TEXT_BOUNDARY_TYPE_WORDSTARTOREND,
  EVENT_TEXT_BOUNDARY_TYPE_LAST = EVENT_TEXT_BOUNDARY_TYPE_WORDSTARTOREND,
};


const char* ToString(EventTextBoundaryType as_enum);
EventTextBoundaryType ParseEventTextBoundaryType(const std::string& as_string);

// A move direction associated with an AutomationEvent.
enum EventMoveDirectionType {
  EVENT_MOVE_DIRECTION_TYPE_NONE,
  EVENT_MOVE_DIRECTION_TYPE_FORWARD,
  EVENT_MOVE_DIRECTION_TYPE_BACKWARD,
  EVENT_MOVE_DIRECTION_TYPE_LAST = EVENT_MOVE_DIRECTION_TYPE_BACKWARD,
};


const char* ToString(EventMoveDirectionType as_enum);
EventMoveDirectionType ParseEventMoveDirectionType(const std::string& as_string);

struct Rect {
  Rect();
  ~Rect();
  Rect(Rect&& rhs);
  Rect& operator=(Rect&& rhs);

  // Populates a Rect object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Rect* out);

  // Creates a Rect object from a base::Value, or NULL on failure.
  static std::unique_ptr<Rect> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Rect object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int left;

  int top;

  int width;

  int height;


 private:
  DISALLOW_COPY_AND_ASSIGN(Rect);
};

struct FindParams {
  FindParams();
  ~FindParams();
  FindParams(FindParams&& rhs);
  FindParams& operator=(FindParams&& rhs);

  // Populates a FindParams object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, FindParams* out);

  // Creates a FindParams object from a base::Value, or NULL on failure.
  static std::unique_ptr<FindParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FindParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(FindParams);
};

struct SetDocumentSelectionParams {
  SetDocumentSelectionParams();
  ~SetDocumentSelectionParams();
  SetDocumentSelectionParams(SetDocumentSelectionParams&& rhs);
  SetDocumentSelectionParams& operator=(SetDocumentSelectionParams&& rhs);

  // Populates a SetDocumentSelectionParams object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, SetDocumentSelectionParams* out);

  // Creates a SetDocumentSelectionParams object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<SetDocumentSelectionParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SetDocumentSelectionParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(SetDocumentSelectionParams);
};

struct AutomationIntent {
  AutomationIntent();
  ~AutomationIntent();
  AutomationIntent(AutomationIntent&& rhs);
  AutomationIntent& operator=(AutomationIntent&& rhs);

  // Populates a AutomationIntent object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AutomationIntent* out);

  // Creates a AutomationIntent object from a base::Value, or NULL on failure.
  static std::unique_ptr<AutomationIntent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AutomationIntent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(AutomationIntent);
};

struct AutomationEvent {
  AutomationEvent();
  ~AutomationEvent();
  AutomationEvent(AutomationEvent&& rhs);
  AutomationEvent& operator=(AutomationEvent&& rhs);

  // Populates a AutomationEvent object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AutomationEvent* out);

  // Creates a AutomationEvent object from a base::Value, or NULL on failure.
  static std::unique_ptr<AutomationEvent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AutomationEvent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(AutomationEvent);
};

struct TreeChange {
  TreeChange();
  ~TreeChange();
  TreeChange(TreeChange&& rhs);
  TreeChange& operator=(TreeChange&& rhs);

  // Populates a TreeChange object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, TreeChange* out);

  // Creates a TreeChange object from a base::Value, or NULL on failure.
  static std::unique_ptr<TreeChange> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this TreeChange object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(TreeChange);
};

// Possible tree changes to listen to using addTreeChangeObserver. Note that
// listening to all tree changes can be expensive.
enum TreeChangeObserverFilter {
  TREE_CHANGE_OBSERVER_FILTER_NONE,
  TREE_CHANGE_OBSERVER_FILTER_NOTREECHANGES,
  TREE_CHANGE_OBSERVER_FILTER_LIVEREGIONTREECHANGES,
  TREE_CHANGE_OBSERVER_FILTER_TEXTMARKERCHANGES,
  TREE_CHANGE_OBSERVER_FILTER_ALLTREECHANGES,
  TREE_CHANGE_OBSERVER_FILTER_LAST = TREE_CHANGE_OBSERVER_FILTER_ALLTREECHANGES,
};


const char* ToString(TreeChangeObserverFilter as_enum);
TreeChangeObserverFilter ParseTreeChangeObserverFilter(const std::string& as_string);

struct CustomAction {
  CustomAction();
  ~CustomAction();
  CustomAction(CustomAction&& rhs);
  CustomAction& operator=(CustomAction&& rhs);

  // Populates a CustomAction object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, CustomAction* out);

  // Creates a CustomAction object from a base::Value, or NULL on failure.
  static std::unique_ptr<CustomAction> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CustomAction object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(CustomAction);
};

struct LanguageSpan {
  LanguageSpan();
  ~LanguageSpan();
  LanguageSpan(LanguageSpan&& rhs);
  LanguageSpan& operator=(LanguageSpan&& rhs);

  // Populates a LanguageSpan object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, LanguageSpan* out);

  // Creates a LanguageSpan object from a base::Value, or NULL on failure.
  static std::unique_ptr<LanguageSpan> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this LanguageSpan object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(LanguageSpan);
};

struct Marker {
  Marker();
  ~Marker();
  Marker(Marker&& rhs);
  Marker& operator=(Marker&& rhs);

  // Populates a Marker object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Marker* out);

  // Creates a Marker object from a base::Value, or NULL on failure.
  static std::unique_ptr<Marker> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Marker object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(Marker);
};

struct AutomationNode {
  AutomationNode();
  ~AutomationNode();
  AutomationNode(AutomationNode&& rhs);
  AutomationNode& operator=(AutomationNode&& rhs);

  // Populates a AutomationNode object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, AutomationNode* out);

  // Creates a AutomationNode object from a base::Value, or NULL on failure.
  static std::unique_ptr<AutomationNode> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AutomationNode object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(AutomationNode);
};


}  // namespace automation
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_AUTOMATION_H__
