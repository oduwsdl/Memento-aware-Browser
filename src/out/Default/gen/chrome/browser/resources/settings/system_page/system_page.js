// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview Settings that affect how Chrome interacts with the underlying
 * operating system (i.e. network, background processes, hardware).
 */

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/policy/cr_policy_pref_indicator.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import '../controls/extension_controlled_indicator.m.js';
import '../controls/settings_toggle_button.m.js';
import '../prefs/prefs.m.js';
import '../settings_shared_css.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {LifetimeBrowserProxyImpl} from '../lifetime_browser_proxy.m.js';

import {SystemPageBrowserProxyImpl} from './system_page_browser_proxy.js';

Polymer({
  is: 'settings-system-page',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared iron-flex"></style>
<if expr="not is_macosx">
    <settings-toggle-button
        pref="{{prefs.background_mode.enabled}}"
        label="$i18n{backgroundAppsLabel}">
    </settings-toggle-button>
</if>
    <settings-toggle-button id="hardwareAcceleration" class="hr"
        pref="{{prefs.hardware_acceleration_mode.enabled}}"
        label="$i18n{hardwareAccelerationLabel}">
      <template is="dom-if" if="[[shouldShowRestart_(
          prefs.hardware_acceleration_mode.enabled.value)]]">
        <cr-button on-click="onRestartTap_" slot="more-actions">
          $i18n{restart}
        </cr-button>
      </template>
    </settings-toggle-button>

    <div id="proxy" class="cr-row" on-click="onProxyTap_"
        actionable$="[[isProxyDefault_]]">
      <div class="flex cr-row-text" hidden$="[[!isProxyDefault_]]">
        $i18n{proxySettingsLabel}
      </div>
      <div class="flex cr-row-text"
          hidden$="[[!prefs.proxy.extensionId]]">
        $i18n{proxySettingsExtensionLabel}
      </div>
      <div class="flex cr-row-text"
          hidden$="[[!isProxyEnforcedByPolicy_]]">
        $i18n{proxySettingsPolicyLabel}
      </div>
      <cr-icon-button class="icon-external"
          hidden$="[[isProxyEnforcedByPolicy_]]"
          aria-label="$i18n{proxySettingsLabel}"></cr-icon-button>
      <template is="dom-if" if="[[isProxyEnforcedByPolicy_]]">
        <cr-policy-pref-indicator pref="[[prefs.proxy]]"
            icon-aria-label="$i18n{proxySettingsLabel}">
        </cr-policy-pref-indicator>
      </template>
    </div>
    <template is="dom-if" if="[[prefs.proxy.extensionId]]">
      <div class="cr-row continuation">
        <extension-controlled-indicator class="flex"
            extension-id="[[prefs.proxy.extensionId]]"
            extension-name="[[prefs.proxy.controlledByName]]"
            extension-can-be-disabled="[[prefs.proxy.extensionCanBeDisabled]]"
            on-extension-disable="onExtensionDisable_">
        </extension-controlled-indicator>
      </div>
    </template>
<!--_html_template_end_-->`,

  properties: {
    prefs: {
      type: Object,
      notify: true,
    },

    /** @private */
    isProxyEnforcedByPolicy_: {
      type: Boolean,
    },

    /** @private */
    isProxyDefault_: {
      type: Boolean,
    },
  },

  observers: [
    'observeProxyPrefChanged_(prefs.proxy.*)',
  ],

  /**
   * @private
   */
  observeProxyPrefChanged_() {
    /** @type {!chrome.settingsPrivate.PrefObject} */
    const pref = this.prefs.proxy;
    // TODO(dbeam): do types of policy other than USER apply on ChromeOS?
    this.isProxyEnforcedByPolicy_ =
        pref.enforcement === chrome.settingsPrivate.Enforcement.ENFORCED &&
        pref.controlledBy === chrome.settingsPrivate.ControlledBy.USER_POLICY;
    this.isProxyDefault_ = !this.isProxyEnforcedByPolicy_ && !pref.extensionId;
  },

  /** @private */
  onExtensionDisable_() {
    // TODO(dbeam): this is a pretty huge bummer. It means there are things
    // (inputs) that our prefs system is not observing. And that changes from
    // other sources (i.e. disabling/enabling an extension from
    // chrome://extensions or from the omnibox directly) will not update
    // |this.prefs.proxy| directly (nor the UI). We should fix this eventually.
    this.fire('refresh-pref', 'proxy');
  },

  /** @private */
  onProxyTap_() {
    if (this.isProxyDefault_) {
      SystemPageBrowserProxyImpl.getInstance().showProxySettings();
    }
  },

  /** @private */
  onRestartTap_(e) {
    // Prevent event from bubbling up to the toggle button.
    e.stopPropagation();
    // TODO(dbeam): we should prompt before restarting the browser.
    LifetimeBrowserProxyImpl.getInstance().restart();
  },

  /**
   * @param {boolean} enabled Whether hardware acceleration is currently
   *     enabled.
   * @private
   */
  shouldShowRestart_(enabled) {
    const proxy = SystemPageBrowserProxyImpl.getInstance();
    return enabled !== proxy.wasHardwareAccelerationEnabledAtStartup();
  },
});
