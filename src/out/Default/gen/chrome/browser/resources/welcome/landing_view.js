// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import './shared/action_link_style_css.js';
import './shared/onboarding_background.js';
import './shared/splash_pages_shared_css.js';
import '../strings.m.js';

import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {LandingViewProxy, LandingViewProxyImpl} from './landing_view_proxy.js';
import {navigateTo, navigateToNextStep, NavigationBehavior, Routes} from './navigation_behavior.js';
import {WelcomeBrowserProxyImpl} from './welcome_browser_proxy.js';

Polymer({
  is: 'landing-view',

  _template: html`<!--_html_template_start_-->
<style include="animations action-link-style splash-pages-shared-css">
  onboarding-background {
    --animation-delay: 275ms;
  }

  h1 {
    outline: none;
  }

  .action-button,
  .action-link {
    --animation-delay: 150ms;
  }
</style>
<div id="container">
  <onboarding-background class="fade-in"></onboarding-background>
  <h2 class="fade-in">$i18n{landingDescription}</h2>
  <h1 class="fade-in" tabindex="-1">$i18n{landingTitle}</h1>
  <cr-button class="action-button fade-in" on-click="onNewUserClick_">
    $i18n{landingNewUser}
  </cr-button>
  <button class="action-link fade-in" on-click="onExistingUserClick_">
    <span hidden$="[[!signinAllowed_]]">$i18n{landingExistingUser}</span>
    <span hidden$="[[signinAllowed_]]">$i18n{skip}</span>
  </button>
</div>
<!--_html_template_end_-->`,

  behaviors: [NavigationBehavior],

  properties: {
    /** @private */
    signinAllowed_: {
      type: Boolean,
      value: () => loadTimeData.getBoolean('signinAllowed'),
    }
  },

  /** @private {?LandingViewProxy} */
  landingViewProxy_: null,

  /** @private {boolean} */
  finalized_: false,

  /** @override */
  ready() {
    this.landingViewProxy_ = LandingViewProxyImpl.getInstance();
  },

  onRouteEnter() {
    this.finalized_ = false;
    this.landingViewProxy_.recordPageShown();
  },

  onRouteUnload() {
    // Clicking on 'Returning user' will change the URL.
    if (this.finalized_) {
      return;
    }
    this.finalized_ = true;
    this.landingViewProxy_.recordNavigatedAway();
  },

  /** @private */
  onExistingUserClick_() {
    this.finalized_ = true;
    this.landingViewProxy_.recordExistingUser();
    if (this.signinAllowed_) {
      WelcomeBrowserProxyImpl.getInstance().handleActivateSignIn(
        'chrome://welcome/returning-user');
    } else {
      navigateTo(Routes.RETURNING_USER, 1);
    }
  },

  /** @private */
  onNewUserClick_() {
    this.finalized_ = true;
    this.landingViewProxy_.recordNewUser();
    navigateTo(Routes.NEW_USER, 1);
  }
});
