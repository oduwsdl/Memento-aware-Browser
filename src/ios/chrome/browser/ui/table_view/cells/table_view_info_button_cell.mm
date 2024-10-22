// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/chrome/browser/ui/table_view/cells/table_view_info_button_cell.h"

#import "ios/chrome/browser/ui/settings/cells/settings_cells_constants.h"
#include "ios/chrome/browser/ui/table_view/cells/table_view_cells_constants.h"
#import "ios/chrome/browser/ui/util/uikit_ui_util.h"
#import "ios/chrome/common/ui/colors/UIColor+cr_semantic_colors.h"
#import "ios/chrome/common/ui/colors/semantic_color_names.h"
#import "ios/chrome/common/ui/util/constraints_ui_util.h"
#include "ios/chrome/grit/ios_strings.h"
#include "ui/base/l10n/l10n_util_mac.h"

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

namespace {

// Padding used between the icon and the text labels.
const CGFloat kIconTrailingPadding = 12;

// Size of the icon image.
const CGFloat kIconImageSize = 28;

// Proportion of |textLayoutGuide| and |statusTextLabel|. This guarantees both
// of them at least occupies 20% of the cell.
const CGFloat kCellLabelsWidthProportion = 0.2f;

}  // namespace

@interface TableViewInfoButtonCell ()

// The image view for the leading icon.
@property(nonatomic, readonly, strong) UIImageView* iconImageView;

// Constraints that are used when the iconImageView is visible and hidden.
@property(nonatomic, strong) NSLayoutConstraint* iconVisibleConstraint;
@property(nonatomic, strong) NSLayoutConstraint* iconHiddenConstraint;

// Constraints that are used when the preferred content size is an
// "accessibility" category.
@property(nonatomic, strong) NSArray* accessibilityConstraints;
// Constraints that are used when the preferred content size is *not* an
// "accessibility" category.
@property(nonatomic, strong) NSArray* standardConstraints;

@end

@implementation TableViewInfoButtonCell

@synthesize textLabel = _textLabel;
@synthesize detailTextLabel = _detailTextLabel;

- (instancetype)initWithStyle:(UITableViewCellStyle)style
              reuseIdentifier:(NSString*)reuseIdentifier {
  self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
  if (self) {
    self.isAccessibilityElement = YES;

    _iconImageView = [[UIImageView alloc] init];
    _iconImageView.translatesAutoresizingMaskIntoConstraints = NO;
    _iconImageView.hidden = YES;
    [self.contentView addSubview:_iconImageView];

    UILayoutGuide* textLayoutGuide = [[UILayoutGuide alloc] init];
    [self.contentView addLayoutGuide:textLayoutGuide];

    _textLabel = [[UILabel alloc] init];
    _textLabel.translatesAutoresizingMaskIntoConstraints = NO;
    _textLabel.font = [UIFont preferredFontForTextStyle:UIFontTextStyleBody];
    _textLabel.adjustsFontForContentSizeCategory = YES;
    _textLabel.textColor = UIColor.cr_labelColor;
    _textLabel.numberOfLines = 0;
    [self.contentView addSubview:_textLabel];

    _detailTextLabel = [[UILabel alloc] init];
    _detailTextLabel.translatesAutoresizingMaskIntoConstraints = NO;
    _detailTextLabel.font =
        [UIFont preferredFontForTextStyle:kTableViewSublabelFontStyle];
    _detailTextLabel.adjustsFontForContentSizeCategory = YES;
    _detailTextLabel.textColor = UIColor.cr_secondaryLabelColor;
    [self.contentView addSubview:_detailTextLabel];

    _statusTextLabel = [[UILabel alloc] init];
    _statusTextLabel.translatesAutoresizingMaskIntoConstraints = NO;
    _statusTextLabel.font =
        [UIFont preferredFontForTextStyle:UIFontTextStyleBody];
    _statusTextLabel.adjustsFontForContentSizeCategory = YES;
    _statusTextLabel.textColor = UIColor.cr_secondaryLabelColor;
    [self.contentView addSubview:_statusTextLabel];

    _trailingButton = [UIButton buttonWithType:UIButtonTypeDetailDisclosure];
    _trailingButton.translatesAutoresizingMaskIntoConstraints = NO;
    [_trailingButton
        setContentCompressionResistancePriority:UILayoutPriorityDefaultHigh + 1
                                        forAxis:
                                            UILayoutConstraintAxisHorizontal];
    [self.contentView addSubview:_trailingButton];

    // Set up the constraints assuming that the icon image is hidden.
    _iconVisibleConstraint = [textLayoutGuide.leadingAnchor
        constraintEqualToAnchor:_iconImageView.trailingAnchor
                       constant:kIconTrailingPadding];
    _iconHiddenConstraint = [textLayoutGuide.leadingAnchor
        constraintEqualToAnchor:self.contentView.leadingAnchor
                       constant:kTableViewHorizontalSpacing];

    // Set the constranits of |textLabel| and |statusTextLabel| to make their
    // width >= 20% of the cell to ensure both of them have a space.
    NSLayoutConstraint* widthConstraintStatus = [_statusTextLabel.widthAnchor
        constraintGreaterThanOrEqualToAnchor:self.contentView.widthAnchor
                                  multiplier:kCellLabelsWidthProportion];
    widthConstraintStatus.priority = UILayoutPriorityDefaultHigh + 1;

    NSLayoutConstraint* widthConstraintLayoutGuide =
        [textLayoutGuide.widthAnchor
            constraintGreaterThanOrEqualToAnchor:self.contentView.widthAnchor
                                      multiplier:kCellLabelsWidthProportion];
    widthConstraintLayoutGuide.priority = UILayoutPriorityDefaultHigh + 1;

    // Set the content hugging property to |statusTextLabel| to wrap the text
    // and give other label more space.
    [_statusTextLabel
        setContentHuggingPriority:UILayoutPriorityDefaultHigh + 2
                          forAxis:UILayoutConstraintAxisHorizontal];

    _standardConstraints = @[
      [_statusTextLabel.centerYAnchor
          constraintEqualToAnchor:self.contentView.centerYAnchor],
      [_statusTextLabel.trailingAnchor
          constraintEqualToAnchor:_trailingButton.leadingAnchor
                         constant:-kTableViewHorizontalSpacing],
      [_trailingButton.centerYAnchor
          constraintEqualToAnchor:self.contentView.centerYAnchor],
      [_trailingButton.trailingAnchor
          constraintEqualToAnchor:self.contentView.trailingAnchor
                         constant:-kTableViewHorizontalSpacing],
      [textLayoutGuide.trailingAnchor
          constraintLessThanOrEqualToAnchor:_statusTextLabel.leadingAnchor
                                   constant:-kTableViewHorizontalSpacing],
      [textLayoutGuide.centerYAnchor
          constraintEqualToAnchor:self.contentView.centerYAnchor],
      [textLayoutGuide.widthAnchor
          constraintGreaterThanOrEqualToAnchor:self.contentView.widthAnchor
                                    multiplier:kCellLabelsWidthProportion],
      widthConstraintStatus,
      widthConstraintLayoutGuide,

    ];

    _accessibilityConstraints = @[
      [_statusTextLabel.topAnchor
          constraintEqualToAnchor:textLayoutGuide.bottomAnchor
                         constant:kTableViewLargeVerticalSpacing],
      [_statusTextLabel.leadingAnchor
          constraintEqualToAnchor:self.contentView.leadingAnchor
                         constant:kTableViewHorizontalSpacing],
      [_statusTextLabel.trailingAnchor
          constraintEqualToAnchor:self.contentView.trailingAnchor
                         constant:-kTableViewHorizontalSpacing],
      [_trailingButton.topAnchor
          constraintEqualToAnchor:_statusTextLabel.bottomAnchor
                         constant:kTableViewLargeVerticalSpacing],
      [_trailingButton.leadingAnchor
          constraintEqualToAnchor:self.contentView.leadingAnchor
                         constant:kTableViewHorizontalSpacing],
      [_trailingButton.bottomAnchor
          constraintEqualToAnchor:self.contentView.bottomAnchor
                         constant:-kTableViewLargeVerticalSpacing],
      [textLayoutGuide.trailingAnchor
          constraintLessThanOrEqualToAnchor:self.contentView.trailingAnchor
                                   constant:-kTableViewHorizontalSpacing],
    ];

    [NSLayoutConstraint activateConstraints:@[
      [_iconImageView.leadingAnchor
          constraintEqualToAnchor:self.contentView.leadingAnchor
                         constant:kTableViewHorizontalSpacing],
      [_iconImageView.widthAnchor constraintEqualToConstant:kIconImageSize],
      [_iconImageView.heightAnchor constraintEqualToConstant:kIconImageSize],

      [_iconImageView.centerYAnchor
          constraintEqualToAnchor:textLayoutGuide.centerYAnchor],

      _iconHiddenConstraint,

      [textLayoutGuide.leadingAnchor
          constraintEqualToAnchor:_textLabel.leadingAnchor],
      [textLayoutGuide.leadingAnchor
          constraintEqualToAnchor:_detailTextLabel.leadingAnchor],
      [textLayoutGuide.trailingAnchor
          constraintEqualToAnchor:_textLabel.trailingAnchor],
      [textLayoutGuide.trailingAnchor
          constraintEqualToAnchor:_detailTextLabel.trailingAnchor],
      [textLayoutGuide.topAnchor constraintEqualToAnchor:_textLabel.topAnchor],
      [textLayoutGuide.bottomAnchor
          constraintEqualToAnchor:_detailTextLabel.bottomAnchor],
      [_textLabel.bottomAnchor
          constraintEqualToAnchor:_detailTextLabel.topAnchor],
    ]];

    if (UIContentSizeCategoryIsAccessibilityCategory(
            self.traitCollection.preferredContentSizeCategory)) {
      [NSLayoutConstraint activateConstraints:_accessibilityConstraints];
    } else {
      [NSLayoutConstraint activateConstraints:_standardConstraints];
    }

    AddOptionalVerticalPadding(self.contentView, textLayoutGuide,
                               kTableViewOneLabelCellVerticalSpacing);
  }
  return self;
}

- (void)setIconImage:(UIImage*)image {
  BOOL hidden = (image == nil);
  self.iconImageView.image = image;
  if (hidden == self.iconImageView.hidden)
    return;
  self.iconImageView.hidden = hidden;
  if (hidden) {
    self.iconVisibleConstraint.active = NO;
    self.iconHiddenConstraint.active = YES;
  } else {
    self.iconHiddenConstraint.active = NO;
    self.iconVisibleConstraint.active = YES;
  }
}

#pragma mark - UIView

- (void)traitCollectionDidChange:(UITraitCollection*)previousTraitCollection {
  [super traitCollectionDidChange:previousTraitCollection];
  BOOL isCurrentContentSizeAccessibility =
      UIContentSizeCategoryIsAccessibilityCategory(
          self.traitCollection.preferredContentSizeCategory);
  if (UIContentSizeCategoryIsAccessibilityCategory(
          previousTraitCollection.preferredContentSizeCategory) !=
      isCurrentContentSizeAccessibility) {
    if (isCurrentContentSizeAccessibility) {
      [NSLayoutConstraint deactivateConstraints:_standardConstraints];
      [NSLayoutConstraint activateConstraints:_accessibilityConstraints];
    } else {
      [NSLayoutConstraint deactivateConstraints:_accessibilityConstraints];
      [NSLayoutConstraint activateConstraints:_standardConstraints];
    }
  }
}

#pragma mark - UITableViewCell

- (void)prepareForReuse {
  [super prepareForReuse];

  self.textLabel.text = nil;
  self.detailTextLabel.text = nil;
  self.statusTextLabel.text = nil;
  self.trailingButton.tag = 0;
  [self setIconImage:nil];
  [_trailingButton removeTarget:nil
                         action:nil
               forControlEvents:[_trailingButton allControlEvents]];
}

#pragma mark - UIAccessibility

- (CGPoint)accessibilityActivationPoint {
  // Center the activation point over the button.
  CGRect buttonFrame = UIAccessibilityConvertFrameToScreenCoordinates(
      self.contentView.frame, self);
  return CGPointMake(CGRectGetMidX(buttonFrame), CGRectGetMidY(buttonFrame));
}

- (NSString*)accessibilityHint {
  return l10n_util::GetNSString(
      IDS_IOS_TOGGLE_SETTING_MANAGED_ACCESSIBILITY_HINT);
}

- (NSString*)accessibilityLabel {
  if (!self.detailTextLabel.text)
    return self.textLabel.text;
  return [NSString stringWithFormat:@"%@, %@", self.textLabel.text,
                                    self.detailTextLabel.text];
}

- (NSString*)accessibilityValue {
  return self.statusTextLabel.text;
}

@end
