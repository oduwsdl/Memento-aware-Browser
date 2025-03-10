// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ash/shelf/hotseat_widget.h"
#include <memory>
#include <utility>

#include "ash/focus_cycler.h"
#include "ash/keyboard/ui/keyboard_ui_controller.h"
#include "ash/public/cpp/ash_features.h"
#include "ash/public/cpp/shelf_config.h"
#include "ash/public/cpp/shelf_model.h"
#include "ash/public/cpp/wallpaper_controller_observer.h"
#include "ash/shelf/hotseat_transition_animator.h"
#include "ash/shelf/scrollable_shelf_view.h"
#include "ash/shelf/shelf_layout_manager.h"
#include "ash/shelf/shelf_navigation_widget.h"
#include "ash/shelf/shelf_view.h"
#include "ash/shell.h"
#include "ash/system/status_area_widget.h"
#include "ash/wallpaper/wallpaper_controller_impl.h"
#include "ash/wm/overview/overview_controller.h"
#include "ash/wm/overview/overview_observer.h"
#include "ash/wm/tablet_mode/tablet_mode_controller.h"
#include "base/metrics/histogram_macros.h"
#include "chromeos/constants/chromeos_switches.h"
#include "ui/aura/scoped_window_targeter.h"
#include "ui/aura/window_targeter.h"
#include "ui/compositor/animation_metrics_reporter.h"
#include "ui/compositor/layer_animation_sequence.h"
#include "ui/compositor/scoped_layer_animation_settings.h"
#include "ui/gfx/color_analysis.h"
#include "ui/gfx/color_palette.h"
#include "ui/gfx/color_utils.h"
#include "ui/gfx/geometry/rounded_corners_f.h"
#include "ui/views/layout/fill_layout.h"
#include "ui/views/widget/widget_delegate.h"

namespace ash {
namespace {

void DoScopedAnimationSetting(
    ui::ScopedLayerAnimationSettings* animation_setter,
    ui::AnimationMetricsReporter* metrics_reporter) {
  animation_setter->SetTransitionDuration(
      ShelfConfig::Get()->shelf_animation_duration());
  animation_setter->SetTweenType(gfx::Tween::EASE_OUT);
  animation_setter->SetPreemptionStrategy(
      ui::LayerAnimator::IMMEDIATELY_ANIMATE_TO_NEW_TARGET);
  if (metrics_reporter) {
    animation_setter->SetAnimationMetricsReporter(metrics_reporter);
  }
}

// Calculates the state transition type for the given previous state and
// the target state.
HotseatWidget::StateTransition CalculateHotseatStateTransition(
    HotseatState previous_state,
    HotseatState target_state) {
  if (previous_state == HotseatState::kNone ||
      target_state == HotseatState::kNone) {
    return HotseatWidget::StateTransition::kOther;
  }

  if (previous_state == target_state)
    return HotseatWidget::StateTransition::kOther;

  const bool related_to_homelauncher =
      (previous_state == HotseatState::kShownHomeLauncher ||
       target_state == HotseatState::kShownHomeLauncher);
  const bool related_to_extended = (previous_state == HotseatState::kExtended ||
                                    target_state == HotseatState::kExtended);
  const bool related_to_hidden = (previous_state == HotseatState::kHidden ||
                                  target_state == HotseatState::kHidden);

  if (related_to_homelauncher && related_to_extended)
    return HotseatWidget::StateTransition::kHomeLauncherAndExtended;

  if (related_to_homelauncher && related_to_hidden)
    return HotseatWidget::StateTransition::kHomeLauncherAndHidden;

  if (related_to_extended && related_to_hidden)
    return HotseatWidget::StateTransition::kHiddenAndExtended;

  return HotseatWidget::StateTransition::kOther;
}

// Animation implemented specifically for the transition between the home
// launcher state and the extended state.
class HomeAndExtendedTransitionAnimation : public ui::LayerAnimationElement {
 public:
  HomeAndExtendedTransitionAnimation(const gfx::Rect& target_bounds_in_screen,
                                     double target_opacity,
                                     ui::Layer* hotseat_layer,
                                     HotseatWidget* hotseat_widget)
      : ui::LayerAnimationElement(
            LayerAnimationElement::BOUNDS | LayerAnimationElement::OPACITY,
            hotseat_layer->GetAnimator()->GetTransitionDuration()),
        target_widget_bounds_(target_bounds_in_screen),
        target_opacity_(target_opacity),
        tween_type_(hotseat_layer->GetAnimator()->tween_type()),
        hotseat_widget_(hotseat_widget) {}
  ~HomeAndExtendedTransitionAnimation() override = default;

  HomeAndExtendedTransitionAnimation(
      const HomeAndExtendedTransitionAnimation& rhs) = delete;
  HomeAndExtendedTransitionAnimation& operator=(
      const HomeAndExtendedTransitionAnimation& rhs) = delete;

 private:
  void OnStart(ui::LayerAnimationDelegate* delegate) override {
    DCHECK(hotseat_widget_->GetShelfView()->shelf()->IsHorizontalAlignment());

    ScrollableShelfView* scrollable_shelf_view = GetScrollableShelfView();
    scrollable_shelf_view->set_is_padding_configured_externally(
        /*is_padding_configured_externally=*/true);

    // Save initial and target padding insets.
    initial_padding_insets_ = scrollable_shelf_view->edge_padding_insets();
    target_padding_insets_ =
        scrollable_shelf_view->CalculateEdgePadding(/*use_target_bounds=*/true);

    // Save initial opacity.
    start_opacity_ = hotseat_widget_->GetNativeView()->layer()->opacity();

    // Save initial hotseat background bounds.
    initial_hotseat_background_in_screen_ =
        hotseat_widget_->GetWindowBoundsInScreen();
    initial_hotseat_background_in_screen_.Inset(initial_padding_insets_);

    // Save target hotseat background bounds.
    target_hotseat_background_in_screen_ = target_widget_bounds_;
    target_hotseat_background_in_screen_.Inset(target_padding_insets_);
  }

  bool OnProgress(double current,
                  ui::LayerAnimationDelegate* delegate) override {
    const double tweened = gfx::Tween::CalculateValue(tween_type_, current);

    // Set scrollable shelf view's padding insets.
    gfx::Insets insets_in_animation_progress;
    insets_in_animation_progress.set_left(gfx::Tween::LinearIntValueBetween(
        tweened, initial_padding_insets_.left(),
        target_padding_insets_.left()));
    insets_in_animation_progress.set_right(gfx::Tween::LinearIntValueBetween(
        tweened, initial_padding_insets_.right(),
        target_padding_insets_.right()));
    ScrollableShelfView* scrollable_shelf_view = GetScrollableShelfView();
    scrollable_shelf_view->SetEdgePaddingInsets(insets_in_animation_progress);

    // Update hotseat widget opacity.
    delegate->SetOpacityFromAnimation(
        gfx::Tween::DoubleValueBetween(tweened, start_opacity_,
                                       target_opacity_),
        ui::PropertyChangeReason::FROM_ANIMATION);

    // Calculate the hotseat widget's bounds.
    const gfx::Rect hotseat_background_in_progress =
        gfx::Tween::RectValueBetween(tweened,
                                     initial_hotseat_background_in_screen_,
                                     target_hotseat_background_in_screen_);
    gfx::Rect widget_bounds_in_progress = hotseat_background_in_progress;
    widget_bounds_in_progress.Inset(
        -scrollable_shelf_view->edge_padding_insets());

    // Update hotseat widget bounds.
    delegate->SetBoundsFromAnimation(widget_bounds_in_progress,
                                     ui::PropertyChangeReason::FROM_ANIMATION);

    // Do recovering when the animation ends.
    if (current == 1.f) {
      scrollable_shelf_view->set_is_padding_configured_externally(
          /*is_padding_configured_externally=*/false);
    }

    return true;
  }

  void OnGetTarget(TargetValue* target) const override {}
  void OnAbort(ui::LayerAnimationDelegate* delegate) override {
    GetScrollableShelfView()->set_is_padding_configured_externally(
        /*is_padding_configured_externally=*/false);
  }

  ScrollableShelfView* GetScrollableShelfView() {
    return hotseat_widget_->scrollable_shelf_view();
  }

  // Scrollable shelf's initial padding insets.
  gfx::Insets initial_padding_insets_;

  // Scrollable shelf's target padding insets.
  gfx::Insets target_padding_insets_;

  // Hotseat background's initial bounds in screen.
  gfx::Rect initial_hotseat_background_in_screen_;

  // Hotseat background's target bounds in screen.
  gfx::Rect target_hotseat_background_in_screen_;

  // Hotseat widget's target bounds in screen.
  gfx::Rect target_widget_bounds_;

  // Hotseat widget's initial opacity.
  double start_opacity_ = 0.f;

  // Hotseat widget's target opacity.
  double target_opacity_ = 0.f;

  gfx::Tween::Type tween_type_ = gfx::Tween::LINEAR;

  HotseatWidget* hotseat_widget_ = nullptr;
};

// Custom window targeter for the hotseat. Used so the hotseat only processes
// events that land on the visible portion of the hotseat, and only while the
// hotseat is not animating.
class HotseatWindowTargeter : public aura::WindowTargeter {
 public:
  explicit HotseatWindowTargeter(HotseatWidget* hotseat_widget)
      : hotseat_widget_(hotseat_widget) {}
  ~HotseatWindowTargeter() override = default;

  HotseatWindowTargeter(const HotseatWindowTargeter& other) = delete;
  HotseatWindowTargeter& operator=(const HotseatWindowTargeter& rhs) = delete;

  // aura::WindowTargeter:
  bool SubtreeShouldBeExploredForEvent(aura::Window* window,
                                       const ui::LocatedEvent& event) override {
    // Do not handle events if the hotseat window is animating as it may animate
    // over other items which want to process events.
    if (hotseat_widget_->GetLayer()->GetAnimator()->is_animating())
      return false;
    return aura::WindowTargeter::SubtreeShouldBeExploredForEvent(window, event);
  }

  bool GetHitTestRects(aura::Window* target,
                       gfx::Rect* hit_test_rect_mouse,
                       gfx::Rect* hit_test_rect_touch) const override {
    if (target == hotseat_widget_->GetNativeWindow()) {
      // Shrink the hit bounds from the size of the window to the size of the
      // hotseat translucent background.
      gfx::Rect hit_bounds = target->bounds();
      hit_bounds.ClampToCenteredSize(
          hotseat_widget_->GetTranslucentBackgroundSize());
      *hit_test_rect_mouse = *hit_test_rect_touch = hit_bounds;
      return true;
    }
    return aura::WindowTargeter::GetHitTestRects(target, hit_test_rect_mouse,
                                                 hit_test_rect_touch);
  }

 private:
  // Unowned and guaranteed to be not null for the duration of |this|.
  HotseatWidget* const hotseat_widget_;
};

}  // namespace

class HotseatWidget::DelegateView : public HotseatTransitionAnimator::Observer,
                                    public views::WidgetDelegateView,
                                    public OverviewObserver,
                                    public WallpaperControllerObserver {
 public:
  DelegateView() : translucent_background_(ui::LAYER_SOLID_COLOR) {
    translucent_background_.SetName("hotseat/Background");
  }
  ~DelegateView() override;

  // Initializes the view.
  void Init(ScrollableShelfView* scrollable_shelf_view,
            ui::Layer* parent_layer,
            HotseatWidget* hotseat_widget);

  // Updates the hotseat background.
  void UpdateTranslucentBackground();

  void SetTranslucentBackground(const gfx::Rect& translucent_background_bounds);

  // Sets whether the background should be blurred as requested by the argument,
  // unless the feature flag is disabled or |disable_blur_for_animations_| is
  // true, in which case this disables background blur.
  void SetBackgroundBlur(bool enable_blur);

  // HotseatTransitionAnimator::Observer:
  void OnHotseatTransitionAnimationWillStart(HotseatState from_state,
                                             HotseatState to_state) override;
  void OnHotseatTransitionAnimationEnded(HotseatState from_state,
                                         HotseatState to_state) override;
  void OnHotseatTransitionAnimationAborted() override;

  // views::WidgetDelegateView:
  bool CanActivate() const override;
  void ReorderChildLayers(ui::Layer* parent_layer) override;

  // OverviewObserver:
  void OnOverviewModeWillStart() override;
  void OnOverviewModeEndingAnimationComplete(bool canceled) override;

  // WallpaperControllerObserver:
  void OnWallpaperColorsChanged() override;

  void set_focus_cycler(FocusCycler* focus_cycler) {
    focus_cycler_ = focus_cycler;
  }

  int background_blur() const {
    return translucent_background_.background_blur();
  }

  bool is_translucent_background_visible_for_test() {
    return translucent_background_.GetTargetVisibility();
  }

 private:
  void SetParentLayer(ui::Layer* layer);

  FocusCycler* focus_cycler_ = nullptr;
  // A background layer that may be visible depending on HotseatState.
  ui::Layer translucent_background_;
  ScrollableShelfView* scrollable_shelf_view_ = nullptr;  // unowned.
  HotseatWidget* hotseat_widget_ = nullptr;               // unowned.
  // Blur is disabled during animations to improve performance.
  int blur_lock_ = 0;

  // The most recent color that the |translucent_background_| has been animated
  // to.
  SkColor target_color_ = SK_ColorTRANSPARENT;

  DISALLOW_COPY_AND_ASSIGN(DelegateView);
};

HotseatWidget::DelegateView::~DelegateView() {
  WallpaperControllerImpl* wallpaper_controller =
      Shell::Get()->wallpaper_controller();
  OverviewController* overview_controller = Shell::Get()->overview_controller();
  if (wallpaper_controller)
    wallpaper_controller->RemoveObserver(this);
  if (overview_controller)
    overview_controller->RemoveObserver(this);
}

void HotseatWidget::DelegateView::Init(
    ScrollableShelfView* scrollable_shelf_view,
    ui::Layer* parent_layer,
    HotseatWidget* hotseat_widget) {
  hotseat_widget_ = hotseat_widget;
  SetLayoutManager(std::make_unique<views::FillLayout>());

  WallpaperControllerImpl* wallpaper_controller =
      Shell::Get()->wallpaper_controller();
  OverviewController* overview_controller = Shell::Get()->overview_controller();
  if (wallpaper_controller)
    wallpaper_controller->AddObserver(this);
  if (overview_controller) {
    overview_controller->AddObserver(this);
    if (overview_controller->InOverviewSession())
      ++blur_lock_;
  }
  SetParentLayer(parent_layer);

  DCHECK(scrollable_shelf_view);
  scrollable_shelf_view_ = scrollable_shelf_view;
}

void HotseatWidget::DelegateView::UpdateTranslucentBackground() {
  if (!HotseatWidget::ShouldShowHotseatBackground()) {
    translucent_background_.SetVisible(false);
    SetBackgroundBlur(false);
    return;
  }

  SetTranslucentBackground(
      scrollable_shelf_view_->GetHotseatBackgroundBounds());
}

void HotseatWidget::DelegateView::SetTranslucentBackground(
    const gfx::Rect& background_bounds) {
  DCHECK(HotseatWidget::ShouldShowHotseatBackground());

  translucent_background_.SetVisible(true);
  SetBackgroundBlur(/*enable_blur=*/true);
  ui::AnimationMetricsReporter* metrics_reporter =
      hotseat_widget_
          ? hotseat_widget_->GetTranslucentBackgroundMetricsReporter()
          : nullptr;

  if (ShelfConfig::Get()->GetDefaultShelfColor() != target_color_) {
    ui::ScopedLayerAnimationSettings color_animation_setter(
        translucent_background_.GetAnimator());
    DoScopedAnimationSetting(&color_animation_setter, metrics_reporter);
    target_color_ = ShelfConfig::Get()->GetDefaultShelfColor();
    translucent_background_.SetColor(target_color_);
  }

  // Animate the bounds change if there's a change of width (for instance when
  // dragging an app into, or out of, the shelf) and meanwhile scrollable
  // shelf's bounds does not update at the same time.
  const bool animate_bounds =
      background_bounds.width() != translucent_background_.bounds().width() &&
      (scrollable_shelf_view_ &&
       !scrollable_shelf_view_->NeedUpdateToTargetBounds());
  base::Optional<ui::ScopedLayerAnimationSettings> bounds_animation_setter;
  if (animate_bounds) {
    bounds_animation_setter.emplace(translucent_background_.GetAnimator());
    DoScopedAnimationSetting(&bounds_animation_setter.value(),
                             metrics_reporter);
  }

  const int radius = hotseat_widget_->GetHotseatSize() / 2;
  gfx::RoundedCornersF rounded_corners = {radius, radius, radius, radius};
  if (translucent_background_.rounded_corner_radii() != rounded_corners)
    translucent_background_.SetRoundedCornerRadius(rounded_corners);

  if (translucent_background_.bounds() != background_bounds)
    translucent_background_.SetBounds(background_bounds);
}

void HotseatWidget::DelegateView::SetBackgroundBlur(bool enable_blur) {
  if (!features::IsBackgroundBlurEnabled() || blur_lock_ > 0)
    return;

  const int blur_radius =
      enable_blur ? ShelfConfig::Get()->shelf_blur_radius() : 0;
  if (translucent_background_.background_blur() != blur_radius)
    translucent_background_.SetBackgroundBlur(blur_radius);
}

void HotseatWidget::DelegateView::OnHotseatTransitionAnimationWillStart(
    HotseatState from_state,
    HotseatState to_state) {
  DCHECK_LE(blur_lock_, 2);

  SetBackgroundBlur(false);
  ++blur_lock_;
}

void HotseatWidget::DelegateView::OnHotseatTransitionAnimationEnded(
    HotseatState from_state,
    HotseatState to_state) {
  DCHECK_GT(blur_lock_, 0);

  --blur_lock_;
  SetBackgroundBlur(true);
}

void HotseatWidget::DelegateView::OnHotseatTransitionAnimationAborted() {
  DCHECK_GT(blur_lock_, 0);

  --blur_lock_;
}

bool HotseatWidget::DelegateView::CanActivate() const {
  // We don't want mouse clicks to activate us, but we need to allow
  // activation when the user is using the keyboard (FocusCycler).
  return focus_cycler_ && focus_cycler_->widget_activating() == GetWidget();
}

void HotseatWidget::DelegateView::ReorderChildLayers(ui::Layer* parent_layer) {
  views::View::ReorderChildLayers(parent_layer);
  parent_layer->StackAtBottom(&translucent_background_);
}

void HotseatWidget::DelegateView::OnOverviewModeWillStart() {
  DCHECK_LE(blur_lock_, 2);

  SetBackgroundBlur(false);
  ++blur_lock_;
}

void HotseatWidget::DelegateView::OnOverviewModeEndingAnimationComplete(
    bool canceled) {
  DCHECK_GT(blur_lock_, 0);

  --blur_lock_;
  SetBackgroundBlur(true);
}

void HotseatWidget::DelegateView::OnWallpaperColorsChanged() {
  UpdateTranslucentBackground();
}

void HotseatWidget::DelegateView::SetParentLayer(ui::Layer* layer) {
  layer->Add(&translucent_background_);
  ReorderLayers();
}

////////////////////////////////////////////////////////////////////////////////
// ScopedInStateTransition

HotseatWidget::ScopedInStateTransition::ScopedInStateTransition(
    HotseatWidget* hotseat_widget,
    HotseatState old_state,
    HotseatState target_state)
    : hotseat_widget_(hotseat_widget) {
  hotseat_widget_->state_transition_in_progress_ =
      CalculateHotseatStateTransition(old_state, target_state);
}

HotseatWidget::ScopedInStateTransition::~ScopedInStateTransition() {
  hotseat_widget_->state_transition_in_progress_.reset();
}

////////////////////////////////////////////////////////////////////////////////
// HotseatWidget

HotseatWidget::HotseatWidget() : delegate_view_(new DelegateView()) {
  ShelfConfig::Get()->AddObserver(this);
}

HotseatWidget::~HotseatWidget() {
  ui::LayerAnimator* hotseat_layer_animator =
      GetNativeView()->layer()->GetAnimator();
  if (hotseat_layer_animator->is_animating())
    hotseat_layer_animator->AbortAllAnimations();

  ShelfConfig::Get()->RemoveObserver(this);
  shelf_->shelf_widget()->hotseat_transition_animator()->RemoveObserver(
      delegate_view_);
}

bool HotseatWidget::ShouldShowHotseatBackground() {
  return chromeos::switches::ShouldShowShelfHotseat() &&
         Shell::Get()->tablet_mode_controller() &&
         Shell::Get()->tablet_mode_controller()->InTabletMode();
}

void HotseatWidget::Initialize(aura::Window* container, Shelf* shelf) {
  DCHECK(container);
  DCHECK(shelf);
  shelf_ = shelf;
  views::Widget::InitParams params(
      views::Widget::InitParams::TYPE_WINDOW_FRAMELESS);
  params.name = "HotseatWidget";
  params.delegate = delegate_view_;
  params.opacity = views::Widget::InitParams::WindowOpacity::kTranslucent;
  params.ownership = views::Widget::InitParams::WIDGET_OWNS_NATIVE_WIDGET;
  params.parent = container;
  params.layer_type = ui::LAYER_NOT_DRAWN;
  Init(std::move(params));
  set_focus_on_creation(false);
  GetFocusManager()->set_arrow_key_traversal_enabled_for_widget(true);

  scrollable_shelf_view_ = GetContentsView()->AddChildView(
      std::make_unique<ScrollableShelfView>(ShelfModel::Get(), shelf));
  delegate_view_->Init(scrollable_shelf_view(), GetLayer(), this);

  // The initialization of scrollable shelf should update the translucent
  // background which is stored in |delegate_view_|. So initializes
  // |scrollable_shelf_view_| after |delegate_view_|.
  scrollable_shelf_view_->Init();
}

void HotseatWidget::OnHotseatTransitionAnimatorCreated(
    HotseatTransitionAnimator* animator) {
  shelf_->shelf_widget()->hotseat_transition_animator()->AddObserver(
      delegate_view_);
}

void HotseatWidget::OnMouseEvent(ui::MouseEvent* event) {
  if (event->type() == ui::ET_MOUSE_PRESSED)
    keyboard::KeyboardUIController::Get()->HideKeyboardImplicitlyByUser();
  views::Widget::OnMouseEvent(event);
}

void HotseatWidget::OnGestureEvent(ui::GestureEvent* event) {
  if (event->type() == ui::ET_GESTURE_TAP_DOWN)
    keyboard::KeyboardUIController::Get()->HideKeyboardImplicitlyByUser();

  if (!event->handled())
    views::Widget::OnGestureEvent(event);
}

bool HotseatWidget::OnNativeWidgetActivationChanged(bool active) {
  if (!Widget::OnNativeWidgetActivationChanged(active))
    return false;

  scrollable_shelf_view_->OnFocusRingActivationChanged(active);
  return true;
}

void HotseatWidget::OnShelfConfigUpdated() {
  set_manually_extended(false);
}

bool HotseatWidget::IsExtended() const {
  DCHECK(GetShelfView()->shelf()->IsHorizontalAlignment());
  const int extended_bottom =
      display::Screen::GetScreen()
          ->GetDisplayNearestView(GetShelfView()->GetWidget()->GetNativeView())
          .bounds()
          .bottom() -
      (ShelfConfig::Get()->shelf_size() +
       ShelfConfig::Get()->hotseat_bottom_padding());
  return GetWindowBoundsInScreen().bottom() == extended_bottom;
}

void HotseatWidget::FocusFirstOrLastFocusableChild(bool last) {
  GetShelfView()->FindFirstOrLastFocusableChild(last)->RequestFocus();
}

void HotseatWidget::OnTabletModeChanged() {
  GetShelfView()->OnTabletModeChanged();
}

float HotseatWidget::CalculateShelfViewOpacity() const {
  const float target_opacity =
      GetShelfView()->shelf()->shelf_layout_manager()->GetOpacity();
  // Hotseat's shelf view should not be dimmed if hotseat is kExtended.
  return (state() == HotseatState::kExtended) ? 1.0f : target_opacity;
}

void HotseatWidget::SetTranslucentBackground(
    const gfx::Rect& translucent_background_bounds) {
  delegate_view_->SetTranslucentBackground(translucent_background_bounds);
}

int HotseatWidget::CalculateHotseatYInScreen(
    HotseatState hotseat_target_state) const {
  DCHECK(shelf_->IsHorizontalAlignment());
  int hotseat_distance_from_bottom_of_display = 0;
  const int hotseat_size = GetHotseatSize();
  switch (hotseat_target_state) {
    case HotseatState::kShownClamshell:
      hotseat_distance_from_bottom_of_display = hotseat_size;
      break;
    case HotseatState::kShownHomeLauncher:
      // When the hotseat state is HotseatState::kShownHomeLauncher, the home
      // launcher is showing in tablet mode. Elevate the hotseat a few px to
      // match the navigation and status area.
      hotseat_distance_from_bottom_of_display =
          hotseat_size + ShelfConfig::Get()->hotseat_bottom_padding();
      break;
    case HotseatState::kHidden:
      // Show the hotseat offscreen.
      hotseat_distance_from_bottom_of_display = 0;
      break;
    case HotseatState::kExtended:
      // Show the hotseat at its extended position.
      hotseat_distance_from_bottom_of_display =
          ShelfConfig::Get()->in_app_shelf_size() +
          ShelfConfig::Get()->hotseat_bottom_padding() + hotseat_size;
      break;
    case HotseatState::kNone:
      NOTREACHED();
  }
  const int target_shelf_size =
      shelf_->shelf_widget()->GetTargetBounds().size().height();
  const int hotseat_y_in_shelf =
      -(hotseat_distance_from_bottom_of_display - target_shelf_size);
  const int shelf_y = shelf_->shelf_widget()->GetTargetBounds().y();
  return hotseat_y_in_shelf + shelf_y;
}

void HotseatWidget::CalculateTargetBounds() {
  ShelfLayoutManager* layout_manager = shelf_->shelf_layout_manager();
  const HotseatState hotseat_target_state =
      layout_manager->CalculateHotseatState(layout_manager->visibility_state(),
                                            layout_manager->auto_hide_state());
  const gfx::Size status_size =
      shelf_->status_area_widget()->GetTargetBounds().size();
  const gfx::Rect shelf_bounds = shelf_->shelf_widget()->GetTargetBounds();
  const int horizontal_edge_spacing =
      ShelfConfig::Get()->control_button_edge_spacing(
          shelf_->IsHorizontalAlignment());
  const int vertical_edge_spacing =
      ShelfConfig::Get()->control_button_edge_spacing(
          !shelf_->IsHorizontalAlignment());
  gfx::Rect nav_bounds = shelf_->navigation_widget()->GetTargetBounds();
  gfx::Point hotseat_origin;
  int hotseat_width;
  int hotseat_height;

  // The minimum gap between hotseat widget and other shelf components including
  // the status area widget and shelf navigation widget (or the edge of display,
  // if the shelf navigation widget does not show).
  const int group_margin = ShelfConfig::Get()->app_icon_group_margin();

  if (shelf_->IsHorizontalAlignment()) {
    hotseat_width = shelf_bounds.width() - nav_bounds.size().width() -
                    horizontal_edge_spacing - 2 * group_margin -
                    status_size.width();
    int hotseat_x =
        base::i18n::IsRTL()
            ? nav_bounds.x() - horizontal_edge_spacing - group_margin -
                  hotseat_width
            : nav_bounds.right() + horizontal_edge_spacing + group_margin;
    if (hotseat_target_state != HotseatState::kShownHomeLauncher &&
        hotseat_target_state != HotseatState::kShownClamshell) {
      // Give the hotseat more space if it is shown outside of the shelf.
      hotseat_width = shelf_bounds.width();
      hotseat_x = shelf_bounds.x();
    }
    hotseat_origin =
        gfx::Point(hotseat_x, CalculateHotseatYInScreen(hotseat_target_state));
    hotseat_height = GetHotseatSize();
  } else {
    hotseat_origin =
        gfx::Point(shelf_bounds.x(),
                   nav_bounds.bottom() + vertical_edge_spacing + group_margin);
    hotseat_width = shelf_bounds.width();
    hotseat_height = shelf_bounds.height() - nav_bounds.size().height() -
                     vertical_edge_spacing - 2 * group_margin -
                     status_size.height();
  }
  target_bounds_ =
      gfx::Rect(hotseat_origin, gfx::Size(hotseat_width, hotseat_height));

  // Check whether |target_bounds_| will change the state of app scaling. If
  // so, update |target_bounds_| here to avoid re-layout later.
  MaybeAdjustTargetBoundsForAppScaling(hotseat_target_state);
}

gfx::Rect HotseatWidget::GetTargetBounds() const {
  return target_bounds_;
}

void HotseatWidget::UpdateLayout(bool animate) {
  const LayoutInputs new_layout_inputs = GetLayoutInputs();
  if (layout_inputs_ == new_layout_inputs)
    return;

  // Never show this widget outside of an active session.
  if (!new_layout_inputs.is_active_session_state)
    Hide();

  ui::Layer* shelf_view_layer = GetShelfView()->layer();
  {
    ui::ScopedLayerAnimationSettings animation_setter(
        shelf_view_layer->GetAnimator());
    animation_setter.SetTransitionDuration(
        animate ? ShelfConfig::Get()->shelf_animation_duration()
                : base::TimeDelta::FromMilliseconds(0));
    animation_setter.SetTweenType(gfx::Tween::EASE_OUT);
    animation_setter.SetPreemptionStrategy(
        ui::LayerAnimator::IMMEDIATELY_ANIMATE_TO_NEW_TARGET);
    animation_setter.SetAnimationMetricsReporter(
        shelf_->GetHotseatTransitionMetricsReporter(state_));

    shelf_view_layer->SetOpacity(new_layout_inputs.shelf_view_opacity);
  }

  // If shelf view is invisible, the hotseat should be as well. Otherwise the
  // hotseat opacit should be 1.0f to preserve background blur.
  const double target_opacity =
      (new_layout_inputs.shelf_view_opacity == 0.f ? 0.f : 1.f);
  const gfx::Rect& target_bounds = new_layout_inputs.bounds;

  if (animate) {
    LayoutHotseatByAnimation(target_opacity, target_bounds);
  } else {
    ui::Layer* hotseat_layer = GetNativeView()->layer();

    // If the running bounds animation is not aborted, it will be interrupted
    // and set hotseat widget with the old target bounds which may differ from
    // |target_bounds| greatly and bring DCHECK errors. For example,
    // if hotseat animation is interrupted by the bounds setting triggered by
    // shelf alignment update, hotseat will be caught in an intermediate state
    // where the shelf alignment is new and the hotseat bounds are old.
    hotseat_layer->GetAnimator()->AbortAllAnimations();

    hotseat_layer->SetOpacity(target_opacity);
    SetBounds(target_bounds);
  }

  layout_inputs_ = new_layout_inputs;
  delegate_view_->UpdateTranslucentBackground();

  // Setting visibility during an animation causes the visibility property to
  // animate. Set the visibility property without an animation.
  if (new_layout_inputs.shelf_view_opacity != 0.0f &&
      new_layout_inputs.is_active_session_state) {
    ShowInactive();
  }
}

void HotseatWidget::UpdateTargetBoundsForGesture(int shelf_position) {
  if (shelf_->IsHorizontalAlignment())
    target_bounds_.set_y(shelf_position);
  else
    target_bounds_.set_x(shelf_position);
}

gfx::Size HotseatWidget::GetTranslucentBackgroundSize() const {
  DCHECK(scrollable_shelf_view_);
  return scrollable_shelf_view_->GetHotseatBackgroundBounds().size();
}

void HotseatWidget::SetFocusCycler(FocusCycler* focus_cycler) {
  delegate_view_->set_focus_cycler(focus_cycler);
  if (focus_cycler)
    focus_cycler->AddWidget(this);
}

ShelfView* HotseatWidget::GetShelfView() {
  DCHECK(scrollable_shelf_view_);
  return scrollable_shelf_view_->shelf_view();
}

int HotseatWidget::GetHotseatSize() const {
  return ShelfConfig::Get()->GetShelfButtonSize(target_hotseat_density_);
}

int HotseatWidget::GetHotseatFullDragAmount() const {
  ShelfConfig* shelf_config = ShelfConfig::Get();
  return shelf_config->shelf_size() + shelf_config->hotseat_bottom_padding() +
         GetHotseatSize();
}

bool HotseatWidget::UpdateTargetHotseatDensityIfNeeded() {
  if (CalculateTargetHotseatDensity(target_bounds_.size(), state_) ==
      target_hotseat_density_) {
    return false;
  }

  shelf_->shelf_layout_manager()->LayoutShelf(/*animate=*/true);
  return true;
}

int HotseatWidget::GetHotseatBackgroundBlurForTest() const {
  return delegate_view_->background_blur();
}

bool HotseatWidget::GetIsTranslucentBackgroundVisibleForTest() const {
  return delegate_view_->is_translucent_background_visible_for_test();
}

bool HotseatWidget::IsShowingShelfMenu() const {
  return GetShelfView()->IsShowingMenu();
}

const ShelfView* HotseatWidget::GetShelfView() const {
  return const_cast<const ShelfView*>(
      const_cast<HotseatWidget*>(this)->GetShelfView());
}

ui::AnimationMetricsReporter*
HotseatWidget::GetTranslucentBackgroundMetricsReporter() {
  return shelf_->GetTranslucentBackgroundMetricsReporter(state_);
}

void HotseatWidget::SetState(HotseatState state) {
  if (state_ == state)
    return;

  state_ = state;

  // If the hotseat is not extended we can use the normal targeting as the
  // hidden parts of the hotseat will not block non-shelf items from taking
  if (state == HotseatState::kExtended) {
    hotseat_window_targeter_ = std::make_unique<aura::ScopedWindowTargeter>(
        GetNativeWindow(), std::make_unique<HotseatWindowTargeter>(this));
  } else {
    hotseat_window_targeter_.reset();
  }
}

HotseatWidget::LayoutInputs HotseatWidget::GetLayoutInputs() const {
  const ShelfLayoutManager* layout_manager = shelf_->shelf_layout_manager();
  return {target_bounds_, CalculateShelfViewOpacity(),
          layout_manager->is_active_session_state()};
}

void HotseatWidget::MaybeAdjustTargetBoundsForAppScaling(
    HotseatState hotseat_target_state) {
  // Return early if app scaling state does not change.
  HotseatDensity new_target_hotseat_density = CalculateTargetHotseatDensity(
      target_bounds_.size(), hotseat_target_state);
  if (new_target_hotseat_density == target_hotseat_density_)
    return;

  target_hotseat_density_ = new_target_hotseat_density;

  // Update app icons of shelf view.
  scrollable_shelf_view_->shelf_view()->OnShelfConfigUpdated();

  const gfx::Point adjusted_hotseat_origin = gfx::Point(
      target_bounds_.x(), CalculateHotseatYInScreen(hotseat_target_state));
  target_bounds_ =
      gfx::Rect(adjusted_hotseat_origin,
                gfx::Size(target_bounds_.width(), GetHotseatSize()));
}

HotseatDensity HotseatWidget::CalculateTargetHotseatDensity(
    const gfx::Size& available_size,
    HotseatState hotseat_target_state) const {
  if (!ash::features::IsAppScalingEnabled())
    return HotseatDensity::kNormal;

  // App scaling is only applied to the standard shelf. So the hotseat density
  // should not update in dense shelf.
  if (ShelfConfig::Get()->is_dense())
    return target_hotseat_density_;

  // Currently we only update app scaling in home launcher due to performance
  // concerns in hotseat animation transition between home launcher state
  // and extended state.
  // TODO(crbug.com/1081476).
  if (hotseat_target_state != HotseatState::kShownHomeLauncher)
    return target_hotseat_density_;

  // Try candidate button sizes in decreasing order. If shelf buttons in one
  // size can show without scrolling, return the density type corresponding to
  // that particular size; if no candidate size can make it, return
  // HotseatDensity::kDense.
  const std::vector<HotseatDensity> kCandidates = {HotseatDensity::kNormal,
                                                   HotseatDensity::kSemiDense};
  for (const auto& candidate : kCandidates) {
    if (!scrollable_shelf_view_->RequiresScrollingForItemSize(
            available_size,
            ShelfConfig::Get()->GetShelfButtonSize(candidate))) {
      return candidate;
    }
  }
  return HotseatDensity::kDense;
}

void HotseatWidget::LayoutHotseatByAnimation(double target_opacity,
                                             const gfx::Rect& target_bounds) {
  ui::Layer* hotseat_layer = GetNativeView()->layer();

  ui::ScopedLayerAnimationSettings animation_setter(
      hotseat_layer->GetAnimator());
  animation_setter.SetTransitionDuration(
      ShelfConfig::Get()->shelf_animation_duration());
  animation_setter.SetTweenType(gfx::Tween::EASE_OUT);
  animation_setter.SetPreemptionStrategy(
      ui::LayerAnimator::IMMEDIATELY_ANIMATE_TO_NEW_TARGET);
  animation_setter.SetAnimationMetricsReporter(
      shelf_->GetHotseatTransitionMetricsReporter(state_));

  if (!state_transition_in_progress_.has_value()) {
    // Hotseat animation is not triggered by the update in |state_|. So apply
    // the normal bounds animation.
    StartNormalBoundsAnimation(target_opacity, target_bounds);
    return;
  }

  switch (*state_transition_in_progress_) {
    case StateTransition::kHomeLauncherAndExtended:
      // Start the hotseat animation specifically for the transition between
      // the home launcher mode and the extended mode.
      StartHomeLauncherExtendedTransitionAnimation(target_opacity,
                                                   target_bounds);
      break;
    case StateTransition::kHomeLauncherAndHidden:
    case StateTransition::kHiddenAndExtended:
    case StateTransition::kOther:
      StartNormalBoundsAnimation(target_opacity, target_bounds);
  }
}

void HotseatWidget::StartHomeLauncherExtendedTransitionAnimation(
    double target_opacity,
    const gfx::Rect& target_bounds) {
  ui::Layer* hotseat_layer = GetNativeView()->layer();
  auto animation_elements =
      std::make_unique<HomeAndExtendedTransitionAnimation>(
          target_bounds, target_opacity, hotseat_layer,
          /*hotseat_widget=*/this);
  auto* sequence =
      new ui::LayerAnimationSequence(std::move(animation_elements));
  hotseat_layer->GetAnimator()->StartAnimation(sequence);
}

void HotseatWidget::StartNormalBoundsAnimation(double target_opacity,
                                               const gfx::Rect& target_bounds) {
  GetNativeView()->layer()->SetOpacity(target_opacity);
  SetBounds(target_bounds);
}

}  // namespace ash
