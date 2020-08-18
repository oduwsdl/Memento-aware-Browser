// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/js/cr.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import '../shared/animations_css.js';
import '../shared/chooser_shared_css.js';
import '../shared/step_indicator.js';
import '../strings.m.js';

import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {isRTL} from 'chrome://resources/js/util.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {navigateTo, navigateToNextStep, NavigationBehavior, Routes} from '../navigation_behavior.js';
import {ModuleMetricsManager} from '../shared/module_metrics_proxy.js';
import {stepIndicatorModel} from '../shared/nux_types.js';

import {NtpBackgroundMetricsProxyImpl} from './ntp_background_metrics_proxy.js';
import {NtpBackgroundData, NtpBackgroundProxy, NtpBackgroundProxyImpl} from './ntp_background_proxy.js';

const KEYBOARD_FOCUSED_CLASS = 'keyboard-focused';

Polymer({
  is: 'nux-ntp-background',

  _template: html`<!--_html_template_start_-->
<style include="animations chooser-shared-css">
  :host {
    text-align: center;
  }

  #backgroundPreview {
    background-position: center center;
    background-repeat: no-repeat;
    background-size: cover;
    bottom: 0;
    left: 0;
    opacity: 0;
    position: fixed;
    right: 0;
    top: 0;
    transition: background 300ms, opacity 400ms;
  }

  #backgroundPreview.active {
    opacity: 1;
  }

  #backgroundPreview::before {
    /* Copied from browser/resources/local_ntp/custom_backgrounds.js */
    background-image: linear-gradient(rgba(0, 0, 0, 0), rgba(0, 0, 0, .3));
    /* Pseudo element needs some content (even an empty string) to be
     * displayed. */
    content: '';
    display: block;
    height: 100%;
    width: 100%;
  }

  .content {
    /* Put a non-static position on the content so that it can have a
     * higher stacking level than its previous sibling,
     * the #backgroundPreview element. */
    position: relative;
  }

  .ntp-background-logo {
    content: url(../images/module_icons/wallpaper_light.svg);
    height: 39px;
    margin: auto;
    margin-bottom: 16px;
    width: 44px;
  }

  @media (prefers-color-scheme: dark) {
    .ntp-background-logo {
      content: url(../images/module_icons/wallpaper_dark.svg);
    }
  }

  h1 {
    color: var(--cr-primary-text-color);
    font-size: 1.5rem;
    font-weight: 500;
    margin: 0;
    margin-bottom: 46px;
    outline: none;
    transition: color 400ms;
  }

  #backgroundPreview.active + .content h1 {
    color: white;
  }

  .ntp-backgrounds-grid {
    display: grid;
    grid-gap: 32px;
    grid-template-columns: repeat(3, 176px);
    grid-template-rows: repeat(2, 176px);
    width: 592px;
  }

  .option {
    align-items: stretch;
    border-radius: 4px;
    display: flex;
    height: 100%;
    overflow: hidden;
    padding: 0;
    text-align: start;
    transition: border-color 400ms, box-shadow 500ms;
    width: 100%;
  }

  #backgroundPreview.active + .content .option {
    border-color: var(--google-grey-refresh-700);
  }

  /* Remove outline when button is focused using the mouse. */
  .option:focus:not(.keyboard-focused) {
    outline: none;
  }

  .ntp-background-thumbnail {
    background-color: var(--cr-card-background-color);
    background-position: center center;
    background-repeat: no-repeat;
    background-size: cover;
    flex: 1;
  }

  .option-name {
    border-top: var(--cr-separator-line);
    color: var(--navi-wallpaper-text-color);
    height: 3rem;
    line-height: 3rem;
    overflow: hidden;
    padding: 0 .75rem;
    text-overflow: ellipsis;
  }

  .option[active] .option-name {
    background: var(--cr-checked-color);
    color: var(--cr-card-background-color);
  }

  .button-bar {
    margin-top: 56px;
  }

  #skipButton {
    background-color: var(--cr-card-background-color)
  }

  #skipButton:hover {
    background-image:
        linear-gradient(var(--hover-bg-color), var(--hover-bg-color));
  }

  /* Wallpaper Thumbnails */
  .art {
    background-image: url(../images/ntp_thumbnails/art.jpg);
  }

  .cityscape {
    background-image: url(../images/ntp_thumbnails/cityscape.jpg);
  }

  .earth {
    background-image: url(../images/ntp_thumbnails/earth.jpg);
  }

  .geometric-shapes {
    background-image: url(../images/ntp_thumbnails/geometric_shapes.jpg);
  }

  .landscape {
    background-image: url(../images/ntp_thumbnails/landscape.jpg);
  }
</style>
<div
    id="backgroundPreview"
    on-transitionend="onBackgroundPreviewTransitionEnd_">
</div>

<div class="content">
  <div class="ntp-background-logo"></div>
  <h1 tabindex="-1">$i18n{ntpBackgroundDescription}</h1>

  <div class="ntp-backgrounds-grid slide-in">
    <template is="dom-repeat" items="[[backgrounds_]]">
      <button
          active$="[[isSelectedBackground_(item, selectedBackground_)]]"
          class="option"
          on-click="onBackgroundClick_"
          on-keyup="onBackgroundKeyUp_"
          on-pointerdown="onBackgroundPointerDown_">
        <div
            class$="ntp-background-thumbnail [[item.thumbnailClass]]">
        </div>
        <div class="option-name">[[item.title]]</div>
      </button>
    </template>
  </div>

  <div class="button-bar">
    <cr-button id="skipButton" on-click="onSkipClicked_">
      $i18n{skip}
    </cr-button>
    <step-indicator model="[[indicatorModel]]"></step-indicator>
    <cr-button class="action-button" on-click="onNextClicked_">
      $i18n{next}
      <iron-icon icon="cr:chevron-right"></iron-icon>
    </cr-button>
  </div>
</div>
<!--_html_template_end_-->`,

  behaviors: [
    I18nBehavior,
    NavigationBehavior,
  ],

  properties: {
    /** @type {stepIndicatorModel} */
    indicatorModel: Object,

    /** @private {?NtpBackgroundData} */
    selectedBackground_: {
      observer: 'onSelectedBackgroundChange_',
      type: Object,
    },
  },

  /** @private {?Array<!NtpBackgroundData>} */
  backgrounds_: null,

  /** @private */
  finalized_: false,

  /** @private {boolean} */
  imageIsLoading_: false,

  /** @private {?ModuleMetricsManager} */
  metricsManager_: null,

  /** @private {?NtpBackgroundProxy} */
  ntpBackgroundProxy_: null,

  /** @override */
  ready() {
    this.ntpBackgroundProxy_ = NtpBackgroundProxyImpl.getInstance();
    this.metricsManager_ =
        new ModuleMetricsManager(NtpBackgroundMetricsProxyImpl.getInstance());
  },

  onRouteEnter() {
    this.finalized_ = false;
    const defaultBackground = {
      id: -1,
      imageUrl: '',
      thumbnailClass: '',
      title: this.i18n('ntpBackgroundDefault'),
    };
    if (!this.selectedBackground_) {
      this.selectedBackground_ = defaultBackground;
    }
    if (!this.backgrounds_) {
      this.ntpBackgroundProxy_.getBackgrounds().then((backgrounds) => {
        this.backgrounds_ = [
          defaultBackground,
          ...backgrounds,
        ];
      });
    }
    this.metricsManager_.recordPageInitialized();
  },

  onRouteExit() {
    if (this.imageIsLoading_) {
      this.ntpBackgroundProxy_.recordBackgroundImageNeverLoaded();
    }

    if (this.finalized_) {
      return;
    }
    this.metricsManager_.recordBrowserBackOrForward();
  },

  onRouteUnload() {
    if (this.imageIsLoading_) {
      this.ntpBackgroundProxy_.recordBackgroundImageNeverLoaded();
    }

    if (this.finalized_) {
      return;
    }
    this.metricsManager_.recordNavigatedAway();
  },

  /**
   * @return {boolean}
   * @private
   */
  hasValidSelectedBackground_() {
    return this.selectedBackground_.id > -1;
  },

  /**
   * @param {!NtpBackgroundData} background
   * @private
   */
  isSelectedBackground_(background) {
    return background === this.selectedBackground_;
  },

  /** @private */
  onSelectedBackgroundChange_() {
    const id = this.selectedBackground_.id;

    if (id > -1) {
      this.imageIsLoading_ = true;
      const imageUrl = this.selectedBackground_.imageUrl;
      const beforeLoadTime = window.performance.now();
      this.ntpBackgroundProxy_.preloadImage(imageUrl).then(
          () => {
            if (this.selectedBackground_.id === id) {
              this.imageIsLoading_ = false;
              this.$.backgroundPreview.classList.add('active');
              this.$.backgroundPreview.style.backgroundImage =
                  `url(${imageUrl})`;
            }

            this.ntpBackgroundProxy_.recordBackgroundImageLoadTime(
                Math.floor(performance.now() - beforeLoadTime));
          },
          () => {
            this.ntpBackgroundProxy_.recordBackgroundImageFailedToLoad();
          });
    } else {
      this.$.backgroundPreview.classList.remove('active');
    }
  },

  /** @private */
  onBackgroundPreviewTransitionEnd_() {
    // Whenever the #backgroundPreview transitions to a non-active, hidden
    // state, remove the background image. This way, when the element
    // transitions back to active, the previous background is not displayed.
    if (!this.$.backgroundPreview.classList.contains('active')) {
      this.$.backgroundPreview.style.backgroundImage = '';
    }
  },

  /**
   * @param {!{model: !{item: !NtpBackgroundData}}} e
   * @private
   */
  onBackgroundClick_(e) {
    this.selectedBackground_ = e.model.item;
    this.metricsManager_.recordClickedOption();
    this.fire('iron-announce', {
      text: this.i18n(
          'ntpBackgroundPreviewUpdated', this.selectedBackground_.title)
    });
  },

  /**
   * @param {!Event} e
   * @private
   */
  onBackgroundKeyUp_(e) {
    if (e.key === 'ArrowRight' || e.key === 'ArrowDown') {
      this.changeFocus_(e.currentTarget, 1);
    } else if (e.key === 'ArrowLeft' || e.key === 'ArrowUp') {
      this.changeFocus_(e.currentTarget, -1);
    } else {
      this.changeFocus_(e.currentTarget, 0);
    }
  },

  /**
   * @param {EventTarget} element
   * @param {number} direction
   * @private
   */
  changeFocus_(element, direction) {
    if (isRTL()) {
      direction *= -1;  // Reverse direction if RTL.
    }

    const buttons = this.root.querySelectorAll('.option');
    const targetIndex = Array.prototype.indexOf.call(buttons, element);

    const oldFocus = buttons[targetIndex];
    if (!oldFocus) {
      return;
    }

    const newFocus = buttons[targetIndex + direction];

    if (newFocus && direction) {
      newFocus.classList.add(KEYBOARD_FOCUSED_CLASS);
      oldFocus.classList.remove(KEYBOARD_FOCUSED_CLASS);
      newFocus.focus();
    } else {
      oldFocus.classList.add(KEYBOARD_FOCUSED_CLASS);
    }
  },

  /**
   * @param {!Event} e
   * @private
   */
  onBackgroundPointerDown_(e) {
    e.currentTarget.classList.remove(KEYBOARD_FOCUSED_CLASS);
  },

  /** @private */
  onNextClicked_() {
    this.finalized_ = true;

    if (this.selectedBackground_ && this.selectedBackground_.id > -1) {
      this.ntpBackgroundProxy_.setBackground(this.selectedBackground_.id);
    } else {
      this.ntpBackgroundProxy_.clearBackground();
    }
    this.metricsManager_.recordGetStarted();
    navigateToNextStep();
  },

  /** @private */
  onSkipClicked_() {
    this.finalized_ = true;
    this.metricsManager_.recordNoThanks();
    navigateToNextStep();

    if (this.hasValidSelectedBackground_()) {
      this.fire('iron-announce', {text: this.i18n('ntpBackgroundReset')});
    }
  },
});
