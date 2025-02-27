// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/platform_window/x11/x11_window.h"

#include "base/command_line.h"
#include "base/run_loop.h"
#include "base/test/task_environment.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "third_party/skia/include/core/SkPath.h"
#include "ui/base/x/test/x11_property_change_waiter.h"
#include "ui/base/x/x11_util.h"
#include "ui/display/display_switches.h"
#include "ui/display/screen_base.h"
#include "ui/events/devices/x11/touch_factory_x11.h"
#include "ui/events/event.h"
#include "ui/events/test/events_test_utils_x11.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/transform.h"
#include "ui/gfx/x/x11.h"
#include "ui/gfx/x/x11_atom_cache.h"
#include "ui/platform_window/extensions/x11_extension_delegate.h"

namespace ui {

namespace {

constexpr int kPointerDeviceId = 1;

class TestPlatformWindowDelegate : public PlatformWindowDelegate {
 public:
  TestPlatformWindowDelegate() = default;
  TestPlatformWindowDelegate(const TestPlatformWindowDelegate&) = delete;
  TestPlatformWindowDelegate& operator=(const TestPlatformWindowDelegate&) =
      delete;
  ~TestPlatformWindowDelegate() override = default;

  gfx::AcceleratedWidget widget() const { return widget_; }
  PlatformWindowState state() const { return state_; }

  void WaitForBoundsSet(const gfx::Rect& expected_bounds) {
    if (changed_bounds_ == expected_bounds)
      return;
    expected_bounds_ = expected_bounds;
    base::RunLoop run_loop;
    quit_closure_ = run_loop.QuitClosure();
    run_loop.Run();
  }

  // PlatformWindowDelegate:
  void OnBoundsChanged(const gfx::Rect& new_bounds) override {
    changed_bounds_ = new_bounds;
    if (!quit_closure_.is_null() && changed_bounds_ == expected_bounds_)
      std::move(quit_closure_).Run();
  }
  void OnDamageRect(const gfx::Rect& damaged_region) override {}
  void DispatchEvent(Event* event) override {}
  void OnCloseRequest() override {}
  void OnClosed() override {}
  void OnWindowStateChanged(PlatformWindowState new_state) override {
    state_ = new_state;
  }
  void OnLostCapture() override {}
  void OnAcceleratedWidgetAvailable(gfx::AcceleratedWidget widget) override {
    widget_ = widget;
  }
  void OnAcceleratedWidgetDestroyed() override {
    widget_ = gfx::kNullAcceleratedWidget;
  }
  void OnActivationChanged(bool active) override {}
  void OnMouseEnter() override {}

 private:
  gfx::AcceleratedWidget widget_ = gfx::kNullAcceleratedWidget;
  PlatformWindowState state_ = PlatformWindowState::kUnknown;
  gfx::Rect changed_bounds_;
  gfx::Rect expected_bounds_;

  // Ends the run loop.
  base::OnceClosure quit_closure_;
};

class ShapedX11ExtensionDelegate : public X11ExtensionDelegate {
 public:
  ShapedX11ExtensionDelegate() = default;
  ~ShapedX11ExtensionDelegate() override = default;

  void OnLostMouseGrab() override {}
  void GetWindowMask(const gfx::Size& size, SkPath* window_mask) override {
    int right = size.width();
    int bottom = size.height();

    window_mask->moveTo(0, 0);
    window_mask->lineTo(0, bottom);
    window_mask->lineTo(right, bottom);
    window_mask->lineTo(right, 10);
    window_mask->lineTo(right - 10, 10);
    window_mask->lineTo(right - 10, 0);
    window_mask->close();
  }
#if BUILDFLAG(USE_ATK)
  bool OnAtkKeyEvent(AtkKeyEventStruct* atk_key_event) override {
    return false;
  }
#endif
  bool IsOverrideRedirect(bool is_tiling_wm) const override { return false; }
};

// Blocks till the window state hint, |hint|, is set or unset.
class WMStateWaiter : public X11PropertyChangeWaiter {
 public:
  WMStateWaiter(x11::Window window, const char* hint, bool wait_till_set)
      : X11PropertyChangeWaiter(window, "_NET_WM_STATE"),
        hint_(hint),
        wait_till_set_(wait_till_set) {}
  WMStateWaiter(const WMStateWaiter&) = delete;
  WMStateWaiter& operator=(const WMStateWaiter&) = delete;
  ~WMStateWaiter() override = default;

 private:
  // X11PropertyChangeWaiter:
  bool ShouldKeepOnWaiting(x11::Event* event) override {
    std::vector<x11::Atom> hints;
    if (GetAtomArrayProperty(xwindow(), "_NET_WM_STATE", &hints))
      return base::Contains(hints, gfx::GetAtom(hint_)) != wait_till_set_;
    return true;
  }

  // The name of the hint to wait to get set or unset.
  const char* hint_;

  // Whether we are waiting for |hint| to be set or unset.
  bool wait_till_set_;
};

class TestScreen : public display::ScreenBase {
 public:
  TestScreen() { ProcessDisplayChanged({}, true); }
  ~TestScreen() override = default;
  TestScreen(const TestScreen& screen) = delete;
  TestScreen& operator=(const TestScreen& screen) = delete;

  void SetScaleAndBoundsForPrimaryDisplay(float scale,
                                          const gfx::Rect& bounds_in_pixels) {
    auto display = GetPrimaryDisplay();
    display.SetScaleAndBounds(scale, bounds_in_pixels);
    ProcessDisplayChanged(display, true);
  }
};  // namespace

// Returns the list of rectangles which describe |window|'s bounding region via
// the X shape extension.
std::vector<gfx::Rect> GetShapeRects(x11::Window window) {
  int dummy;
  int shape_rects_size;
  gfx::XScopedPtr<XRectangle[]> shape_rects(
      XShapeGetRectangles(gfx::GetXDisplay(), static_cast<uint32_t>(window),
                          ShapeBounding, &shape_rects_size, &dummy));

  std::vector<gfx::Rect> shape_vector;
  for (int i = 0; i < shape_rects_size; ++i) {
    const XRectangle& rect = shape_rects[i];
    shape_vector.emplace_back(rect.x, rect.y, rect.width, rect.height);
  }
  return shape_vector;
}

// Returns true if one of |rects| contains point (x,y).
bool ShapeRectContainsPoint(const std::vector<gfx::Rect>& shape_rects,
                            int x,
                            int y) {
  gfx::Point point(x, y);
  return std::any_of(
      shape_rects.cbegin(), shape_rects.cend(),
      [&point](const auto& rect) { return rect.Contains(point); });
}

}  // namespace

class X11WindowTest : public testing::Test {
 public:
  X11WindowTest()
      : task_env_(std::make_unique<base::test::TaskEnvironment>(
            base::test::TaskEnvironment::MainThreadType::UI)) {}
  X11WindowTest(const X11WindowTest&) = delete;
  X11WindowTest& operator=(const X11WindowTest&) = delete;
  ~X11WindowTest() override = default;

  void SetUp() override {
    XDisplay* display = gfx::GetXDisplay();
    event_source_ = std::make_unique<X11EventSource>(display);

    std::vector<int> pointer_devices;
    pointer_devices.push_back(kPointerDeviceId);
    ui::TouchFactory::GetInstance()->SetPointerDeviceForTest(pointer_devices);

    // X11 requires display::Screen instance.
    test_screen_ = new TestScreen();
    display::Screen::SetScreenInstance(test_screen_);

    // Make X11 synchronous for our display connection. This does not force the
    // window manager to behave synchronously.
    XSynchronize(gfx::GetXDisplay(), x11::True);
  }

 protected:
  void TearDown() override { XSynchronize(gfx::GetXDisplay(), x11::False); }

  std::unique_ptr<X11Window> CreateX11Window(
      PlatformWindowDelegate* delegate,
      const gfx::Rect& bounds,
      X11ExtensionDelegate* x11_extension_delegate) {
    PlatformWindowInitProperties init_params(bounds);
    init_params.x11_extension_delegate = x11_extension_delegate;
    auto window = std::make_unique<X11Window>(delegate);
    window->Initialize(std::move(init_params));
    // Remove native frame so that X server doesn't change our bounds.
    window->SetUseNativeFrame(false);
    return window;
  }

  void DispatchSingleEventToWidget(x11::Event* x11_event, x11::Window window) {
    XEvent* xev = &x11_event->xlib_event();
    XIDeviceEvent* device_event =
        static_cast<XIDeviceEvent*>(xev->xcookie.data);
    device_event->event = static_cast<uint32_t>(window);
    LOG(ERROR) << "____PROCESS " << xev;
    event_source_->ProcessXEvent(x11_event);
  }

 private:
  std::unique_ptr<base::test::TaskEnvironment> task_env_;
  std::unique_ptr<X11EventSource> event_source_;

  TestScreen* test_screen_ = nullptr;
};

// https://crbug.com/898742: Test might be flaky. Disable again if it is still
// flaky after it is moved from views_unittests to x11_unittests. Tests that the
// shape is properly set on the x window.
TEST_F(X11WindowTest, Shape) {
  if (!IsShapeExtensionAvailable())
    return;

  // 1) Test setting the window shape via the ShapedX11ExtensionDelegate. This
  // technique is used to get rounded corners on Chrome windows when not using
  // the native window frame.
  TestPlatformWindowDelegate delegate;
  ShapedX11ExtensionDelegate x11_extension_delegate;
  constexpr gfx::Rect bounds(100, 100, 100, 100);
  auto window = CreateX11Window(&delegate, bounds, &x11_extension_delegate);
  window->Show(false);

  const x11::Window x11_window = window->window();
  ASSERT_TRUE(x11_window != x11::Window::None);

  // Force update the window region.
  window->ResetWindowRegion();

  X11EventSource::GetInstance()->DispatchXEvents();

  std::vector<gfx::Rect> shape_rects = GetShapeRects(x11_window);
  ASSERT_FALSE(shape_rects.empty());

  // The widget was supposed to be 100x100, but the WM might have ignored this
  // suggestion.
  int window_width = window->GetBounds().width();
  EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, window_width - 15, 5));
  EXPECT_FALSE(ShapeRectContainsPoint(shape_rects, window_width - 5, 5));
  EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, window_width - 5, 15));
  EXPECT_FALSE(ShapeRectContainsPoint(shape_rects, window_width + 5, 15));

  // Changing window's size should update the shape.
  window->SetBounds(gfx::Rect(100, 100, 200, 200));
  X11EventSource::GetInstance()->DispatchXEvents();

  if (window->GetBounds().width() == 200) {
    shape_rects = GetShapeRects(x11_window);
    ASSERT_FALSE(shape_rects.empty());
    EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 85, 5));
    EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 95, 5));
    EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 185, 5));
    EXPECT_FALSE(ShapeRectContainsPoint(shape_rects, 195, 5));
    EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 195, 15));
    EXPECT_FALSE(ShapeRectContainsPoint(shape_rects, 205, 15));
  }

  if (WmSupportsHint(gfx::GetAtom("_NET_WM_STATE_MAXIMIZED_VERT"))) {
    // The shape should be changed to a rectangle which fills the entire screen
    // when |widget1| is maximized.
    {
      WMStateWaiter waiter(x11_window, "_NET_WM_STATE_MAXIMIZED_VERT", true);
      window->Maximize();
      waiter.Wait();
    }

    // Ensure that the task which is posted when a window is resized is run.
    base::RunLoop().RunUntilIdle();

    // xvfb does not support Xrandr so we cannot check the maximized window's
    // bounds.
    gfx::Rect maximized_bounds;
    GetOuterWindowBounds(x11_window, &maximized_bounds);

    shape_rects = GetShapeRects(x11_window);
    ASSERT_FALSE(shape_rects.empty());
    EXPECT_TRUE(
        ShapeRectContainsPoint(shape_rects, maximized_bounds.width() - 1, 5));
    EXPECT_TRUE(
        ShapeRectContainsPoint(shape_rects, maximized_bounds.width() - 1, 15));
  }

  // 2) Test setting the window shape via PlatformWindow::SetShape().
  auto shape_region = std::make_unique<std::vector<gfx::Rect>>();
  shape_region->emplace_back(10, 0, 90, 10);
  shape_region->emplace_back(0, 10, 10, 90);
  shape_region->emplace_back(10, 10, 90, 90);

  TestPlatformWindowDelegate delegate2;
  constexpr gfx::Rect bounds2(30, 80, 800, 600);
  auto window2 = CreateX11Window(&delegate2, bounds2, nullptr);
  window2->Show(false);

  const x11::Window x11_window2 = window2->window();
  ASSERT_TRUE(x11_window2 != x11::Window::None);

  gfx::Transform transform;
  transform.Scale(1.0f, 1.0f);
  window2->SetShape(std::move(shape_region), transform);

  X11EventSource::GetInstance()->DispatchXEvents();

  shape_rects = GetShapeRects(x11_window2);
  ASSERT_FALSE(shape_rects.empty());
  EXPECT_FALSE(ShapeRectContainsPoint(shape_rects, 5, 5));
  EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 15, 5));
  EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 95, 15));
  EXPECT_FALSE(ShapeRectContainsPoint(shape_rects, 105, 15));

  // Changing the windows's size should not affect the shape.
  window2->SetBounds(gfx::Rect(100, 100, 200, 200));
  shape_rects = GetShapeRects(x11_window2);
  ASSERT_FALSE(shape_rects.empty());
  EXPECT_FALSE(ShapeRectContainsPoint(shape_rects, 5, 5));
  EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 15, 5));
  EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 95, 15));
  EXPECT_FALSE(ShapeRectContainsPoint(shape_rects, 105, 15));

  // Setting the shape to nullptr resets the shape back to the entire
  // window bounds.
  window2->SetShape(nullptr, transform);
  shape_rects = GetShapeRects(x11_window2);
  ASSERT_FALSE(shape_rects.empty());
  EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 5, 5));
  EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 15, 5));
  EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 95, 15));
  EXPECT_TRUE(ShapeRectContainsPoint(shape_rects, 105, 15));
  EXPECT_FALSE(ShapeRectContainsPoint(shape_rects, 500, 500));
}

// Test that the widget reacts on changes in fullscreen state initiated by the
// window manager (e.g. via a window manager accelerator key).
TEST_F(X11WindowTest, WindowManagerTogglesFullscreen) {
  if (!WmSupportsHint(gfx::GetAtom("_NET_WM_STATE_FULLSCREEN")))
    return;

  Display* display = gfx::GetXDisplay();

  TestPlatformWindowDelegate delegate;
  ShapedX11ExtensionDelegate x11_extension_delegate;
  constexpr gfx::Rect bounds(100, 100, 100, 100);
  auto window = CreateX11Window(&delegate, bounds, &x11_extension_delegate);
  x11::Window x11_window = window->window();
  window->Show(false);

  X11EventSource::GetInstance()->DispatchXEvents();

  EXPECT_NE(window->GetPlatformWindowState(), PlatformWindowState::kFullScreen);

  gfx::Rect initial_bounds = window->GetBounds();
  {
    WMStateWaiter waiter(x11_window, "_NET_WM_STATE_FULLSCREEN", true);
    window->ToggleFullscreen();
    waiter.Wait();
  }
  EXPECT_EQ(window->GetPlatformWindowState(), PlatformWindowState::kFullScreen);

  // Emulate the window manager exiting fullscreen via a window manager
  // accelerator key.
  {
    XEvent xclient;
    memset(&xclient, 0, sizeof(xclient));
    xclient.type = ClientMessage;
    xclient.xclient.window = static_cast<uint32_t>(x11_window);
    xclient.xclient.message_type =
        static_cast<uint32_t>(gfx::GetAtom("_NET_WM_STATE"));
    xclient.xclient.format = 32;
    xclient.xclient.data.l[0] = 0;
    xclient.xclient.data.l[1] =
        static_cast<uint32_t>(gfx::GetAtom("_NET_WM_STATE_FULLSCREEN"));
    xclient.xclient.data.l[2] = 0;
    xclient.xclient.data.l[3] = 1;
    xclient.xclient.data.l[4] = 0;
    XSendEvent(display, DefaultRootWindow(display), x11::False,
               SubstructureRedirectMask | SubstructureNotifyMask, &xclient);

    WMStateWaiter waiter(x11_window, "_NET_WM_STATE_FULLSCREEN", false);
    waiter.Wait();
  }

  // Ensure it continues in browser fullscreen mode and bounds are restored to
  // |initial_bounds|.
  EXPECT_EQ(window->GetPlatformWindowState(), PlatformWindowState::kFullScreen);
  delegate.WaitForBoundsSet(initial_bounds);
  EXPECT_EQ(initial_bounds, window->GetBounds());

  // Emulate window resize (through X11 configure events) while in browser
  // fullscreen mode and ensure bounds are tracked correctly.
  initial_bounds.set_size({400, 400});
  {
    XWindowChanges changes = {0};
    changes.width = initial_bounds.width();
    changes.height = initial_bounds.height();
    XConfigureWindow(display, static_cast<uint32_t>(x11_window),
                     CWHeight | CWWidth, &changes);
    // Ensure that the task which is posted when a window is resized is run.
    base::RunLoop().RunUntilIdle();
  }
  EXPECT_EQ(window->GetPlatformWindowState(), PlatformWindowState::kFullScreen);
  delegate.WaitForBoundsSet(initial_bounds);
  EXPECT_EQ(initial_bounds, window->GetBounds());

  // Calling Widget::SetFullscreen(false) should clear the widget's fullscreen
  // state and clean things up.
  window->ToggleFullscreen();
  EXPECT_NE(window->GetPlatformWindowState(), PlatformWindowState::kFullScreen);
  delegate.WaitForBoundsSet(initial_bounds);
  EXPECT_EQ(initial_bounds, window->GetBounds());
}

// Tests that the minimization information is propagated to the
// PlatformWindowDelegate.
TEST_F(X11WindowTest, ToggleMinimizePropogateToPlatformWindowDelegate) {
  TestPlatformWindowDelegate delegate;
  constexpr gfx::Rect bounds(10, 10, 100, 100);
  auto window = CreateX11Window(&delegate, bounds, nullptr);
  window->Show(false);
  window->Activate();

  ui::X11EventSource::GetInstance()->DispatchXEvents();

  x11::Window x11_window = window->window();
  Display* display = gfx::GetXDisplay();

  // Minimize by sending _NET_WM_STATE_HIDDEN
  {
    std::vector<x11::Atom> atom_list;
    atom_list.push_back(gfx::GetAtom("_NET_WM_STATE_HIDDEN"));
    ui::SetAtomArrayProperty(x11_window, "_NET_WM_STATE", "ATOM", atom_list);

    XEvent xevent;
    memset(&xevent, 0, sizeof(xevent));
    xevent.type = PropertyNotify;
    xevent.xproperty.type = PropertyNotify;
    xevent.xproperty.send_event = 1;
    xevent.xproperty.display = display;
    xevent.xproperty.window = static_cast<uint32_t>(x11_window);
    xevent.xproperty.atom =
        static_cast<uint32_t>(gfx::GetAtom("_NET_WM_STATE"));
    xevent.xproperty.state = 0;
    XSendEvent(display, DefaultRootWindow(display), x11::False,
               SubstructureRedirectMask | SubstructureNotifyMask, &xevent);

    WMStateWaiter waiter(x11_window, "_NET_WM_STATE_HIDDEN", true);
    waiter.Wait();
  }
  EXPECT_TRUE(window->IsMinimized());
  EXPECT_EQ(delegate.state(), PlatformWindowState::kMinimized);

  // Show from minimized by sending _NET_WM_STATE_FOCUSED
  {
    std::vector<x11::Atom> atom_list;
    atom_list.push_back(gfx::GetAtom("_NET_WM_STATE_FOCUSED"));
    ui::SetAtomArrayProperty(x11_window, "_NET_WM_STATE", "ATOM", atom_list);

    XEvent xevent;
    memset(&xevent, 0, sizeof(xevent));
    xevent.type = PropertyNotify;
    xevent.xproperty.type = PropertyNotify;
    xevent.xproperty.send_event = 1;
    xevent.xproperty.display = display;
    xevent.xproperty.window = static_cast<uint32_t>(x11_window);
    xevent.xproperty.atom =
        static_cast<uint32_t>(gfx::GetAtom("_NET_WM_STATE"));
    xevent.xproperty.state = 0;
    XSendEvent(display, DefaultRootWindow(display), x11::False,
               SubstructureRedirectMask | SubstructureNotifyMask, &xevent);

    WMStateWaiter waiter(x11_window, "_NET_WM_STATE_FOCUSED", true);
    waiter.Wait();
  }
  EXPECT_FALSE(window->IsMinimized());
  EXPECT_EQ(delegate.state(), PlatformWindowState::kNormal);
}

}  // namespace ui
