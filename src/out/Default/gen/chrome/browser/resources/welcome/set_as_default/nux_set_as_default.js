// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
// <if expr="is_win">
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
// </if>
import '../shared/animations_css.js';
import '../shared/step_indicator.js';
import '../strings.m.js';

import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {navigateTo, navigateToNextStep, NavigationBehavior, Routes} from '../navigation_behavior.js';
import {DefaultBrowserInfo, stepIndicatorModel} from '../shared/nux_types.js';

import {NuxSetAsDefaultProxy, NuxSetAsDefaultProxyImpl} from './nux_set_as_default_proxy.js';

Polymer({
  is: 'nux-set-as-default',

  _template: html`<!--_html_template_start_-->
<style include="animations">
  .container {
    text-align: center;
  }

  .logo {
    content: url(../images/module_icons/set_default_light.svg);
    display: inline-block;
    height: 38px;
    margin-bottom: 16px;
    width: 42px;
  }

  @media (prefers-color-scheme: dark) {
    .logo {
      content: url(../images/module_icons/set_default_dark.svg);
    }
  }

  .illustration {
    content: url(../images/set_default_light.svg);
    margin: auto;
    width: 454px;
  }

  @media (prefers-color-scheme: dark) {
    .illustration {
      content: url(../images/set_default_dark.svg);
    }
  }

  h1 {
    color: var(--cr-primary-text-color);
    font-size: 1.5rem;
    font-weight: 500;
    line-height: 2.5rem;
    margin: 0;
    outline: none;
  }

  h2 {
    color: var(--cr-secondary-text-color);
    font-size: 1.25rem;
    font-weight: unset;
    line-height: 1.875rem;
    margin: auto;
    margin-bottom: 48px;
    margin-top: 16px;
    max-width: 400px;
  }

  .button-bar {
    display: flex;
    justify-content: space-between;
    margin-top: 64px;
  }

<if expr="is_win">
  iron-icon[icon='cr:open-in-new'] {
    height: 20px;
    margin-inline-start: 6px;
    margin-inline-end: -10px;
    width: 20px;
  }
</if>
</style>
<div class="container">
  <div class="logo"></div>
  <h1 tabindex="-1">$i18n{setDefaultHeader}</h1>
  <h2>$i18n{setDefaultSubHeader}</h2>
  <div class="illustration slide-in" aria-hidden="true"></div>
  <div class="button-bar">
    <cr-button id="decline-button" on-click="onDeclineClick_">
      $i18n{skip}
    </cr-button>
    <step-indicator model="[[indicatorModel]]"></step-indicator>
    <cr-button class="action-button" on-click="onSetDefaultClick_">
      $i18n{setDefaultConfirm}
<if expr="is_win">
      <iron-icon icon="cr:open-in-new" hidden="[[!isWin10]]"></iron-icon>
</if>
    </cr-button>
  </div>
</div>
<!--_html_template_end_-->`,

  behaviors: [
    WebUIListenerBehavior,
    NavigationBehavior,
  ],

  properties: {
    /** @type {stepIndicatorModel} */
    indicatorModel: Object,

    // <if expr="is_win">
    isWin10: {
      type: Boolean,
      value: loadTimeData.getBoolean('is_win10'),
    },
    // </if>
  },

  /** @private {NuxSetAsDefaultProxy} */
  browserProxy_: null,

  /** @private {boolean} */
  finalized_: false,

  /** @private {!Function} */
  navigateToNextStep_: navigateToNextStep,

  /** @override */
  ready() {
    this.browserProxy_ = NuxSetAsDefaultProxyImpl.getInstance();

    this.addWebUIListener(
        'browser-default-state-changed',
        this.onDefaultBrowserChange_.bind(this));
  },

  onRouteEnter() {
    this.finalized_ = false;
    this.browserProxy_.recordPageShown();
  },

  onRouteExit() {
    if (this.finalized_) {
      return;
    }
    this.finalized_ = true;
    this.browserProxy_.recordNavigatedAwayThroughBrowserHistory();
  },

  onRouteUnload() {
    if (this.finalized_) {
      return;
    }
    this.finalized_ = true;
    this.browserProxy_.recordNavigatedAway();
  },

  /** @private */
  onDeclineClick_() {
    if (this.finalized_) {
      return;
    }

    this.browserProxy_.recordSkip();
    this.finished_();
  },

  /** @private */
  onSetDefaultClick_() {
    if (this.finalized_) {
      return;
    }

    this.browserProxy_.recordBeginSetDefault();
    this.browserProxy_.setAsDefault();
  },

  /**
   * Automatically navigate to the next onboarding step once default changed.
   * @param {!DefaultBrowserInfo} status
   * @private
   */
  onDefaultBrowserChange_(status) {
    if (status.isDefault) {
      this.browserProxy_.recordSuccessfullySetDefault();
      // Triggers toast in the containing welcome-app.
      this.fire('default-browser-change');
      this.finished_();
      return;
    }

    // <if expr="is_macosx">
    // On Mac OS, we do not get a notification when the default browser changes.
    // This will fake the notification.
    window.setTimeout(() => {
      this.browserProxy_.requestDefaultBrowserState().then(
          this.onDefaultBrowserChange_.bind(this));
    }, 100);
    // </if>
  },

  /** @private */
  finished_() {
    this.finalized_ = true;
    this.navigateToNextStep_();
  },
});
