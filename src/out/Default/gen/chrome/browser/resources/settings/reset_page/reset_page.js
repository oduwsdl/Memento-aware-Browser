// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'settings-reset-page' is the settings page containing reset
 * settings.
 */
import 'chrome://resources/cr_elements/cr_lazy_render/cr_lazy_render.m.js';
import './reset_profile_dialog.js';
import '../settings_page/settings_animated_pages.m.js';
import '../settings_shared_css.m.js';

// <if expr="_google_chrome and is_win">
import '../chrome_cleanup_page/chrome_cleanup_page.js';
import '../incompatible_applications_page/incompatible_applications_page.js';
// </if>

import {assert} from 'chrome://resources/js/assert.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';
import {routes} from '../route.js';
import {Route, RouteObserverBehavior, Router} from '../router.m.js';


Polymer({
  is: 'settings-reset-page',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared"></style>
    <settings-animated-pages id="reset-pages" section="reset">
      <div route-path="default">
        <cr-link-row id="resetProfile" label="$i18n{resetTrigger}"
            on-click="onShowResetProfileDialog_"></cr-link-row>
        <!-- Keep a single instance of reset-profile-dialog on purpose, to
          preserve state across show/hide operations. -->
        <cr-lazy-render id="resetProfileDialog">
          <template>
            <settings-reset-profile-dialog
                on-close="onResetProfileDialogClose_">
            </settings-reset-profile-dialog>
          </template>
        </cr-lazy-render>
<if expr="_google_chrome and is_win">
        <cr-link-row class="hr" id="chromeCleanupSubpageTrigger"
            label="$i18n{resetCleanupComputerTrigger}"
            on-click="onChromeCleanupTap_"
            role-description="$i18n{subpageArrowRoleDescription}"></cr-link-row>
        <template is="dom-if" if="[[showIncompatibleApplications_]]" restamp>
          <cr-link-row class="hr" id="incompatibleApplicationsSubpageTrigger"
              label="$i18n{incompatibleApplicationsResetCardTitle}"
              on-click="onIncompatibleApplicationsTap_"
              role-description="$i18n{subpageArrowRoleDescription}">
          </cr-link-row>
        </template>
</if>
      </div>
<if expr="_google_chrome and is_win">
      <template is="dom-if" route-path="/cleanup">
        <settings-subpage id="chromeCleanupSubpage"
            associated-control="[[$$('#chromeCleanupSubpageTrigger')]]"
            page-title="$i18n{resetCleanupComputerTrigger}"
            learn-more-url="$i18n{chromeCleanupLearnMoreUrl}">
          <settings-chrome-cleanup-page prefs="{{prefs}}">
          </settings-chrome-cleanup-page>
        </settings-subpage>
      </template>
      <template is="dom-if" if="[[showIncompatibleApplications_]]">
        <template is="dom-if" route-path="/incompatibleApplications">
          <settings-subpage id="incompatibleApplicationsSubpage"
              associated-control="[[$$('#incompatibleApplicationsSubpageTrigger')]]"
              page-title="$i18n{incompatibleApplicationsResetCardTitle}">
            <settings-incompatible-applications-page>
            </settings-incompatible-applications-page>
          </settings-subpage>
        </template>
      </template>
</if>
    </settings-animated-pages>
<!--_html_template_end_-->`,

  behaviors: [RouteObserverBehavior],

  properties: {
    /** Preferences state. */
    prefs: Object,

    // <if expr="_google_chrome and is_win">
    /** @private */
    showIncompatibleApplications_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('showIncompatibleApplications');
      },
    },
    // </if>
  },

  /**
   * RouteObserverBehavior
   * @param {!Route} route
   * @protected
   */
  currentRouteChanged(route) {
    const lazyRender =
        /** @type {!CrLazyRenderElement} */ (this.$.resetProfileDialog);

    if (route === routes.TRIGGERED_RESET_DIALOG ||
        route === routes.RESET_DIALOG) {
      /** @type {!SettingsResetProfileDialogElement} */ (lazyRender.get())
          .show();
    } else {
      const dialog = /** @type {?SettingsResetProfileDialogElement} */ (
          lazyRender.getIfExists());
      if (dialog) {
        dialog.cancel();
      }
    }
  },

  /** @private */
  onShowResetProfileDialog_() {
    Router.getInstance().navigateTo(
        routes.RESET_DIALOG, new URLSearchParams('origin=userclick'));
  },

  /** @private */
  onResetProfileDialogClose_() {
    Router.getInstance().navigateToPreviousRoute();
    focusWithoutInk(assert(this.$.resetProfile));
  },

  // <if expr="_google_chrome and is_win">
  /** @private */
  onChromeCleanupTap_() {
    Router.getInstance().navigateTo(routes.CHROME_CLEANUP);
  },

  /** @private */
  onIncompatibleApplicationsTap_() {
    Router.getInstance().navigateTo(routes.INCOMPATIBLE_APPLICATIONS);
  },
  // </if>
});
