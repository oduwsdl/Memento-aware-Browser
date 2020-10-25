// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'settings-on-startup-page' is a settings page.
 */
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import '../controls/controlled_radio_button.m.js';
import '../controls/extension_controlled_indicator.m.js';
import '../controls/settings_radio_group.m.js';
import './startup_urls_page.js';
import '../i18n_setup.js';
import '../settings_shared_css.m.js';

import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {NtpExtension, OnStartupBrowserProxyImpl} from './on_startup_browser_proxy.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared iron-flex">
      .block {
        display: block;
      }
    </style>
    <div class="cr-row first">
      <settings-radio-group id="onStartupRadioGroup"
          class="flex"
          pref="{{prefs.session.restore_on_startup}}"
          group-aria-label="$i18n{onStartup}">
        <controlled-radio-button name="[[getName_(prefValues_.OPEN_NEW_TAB)]]"
            pref="[[prefs.session.restore_on_startup]]"
            label="$i18n{onStartupOpenNewTab}"
            no-extension-indicator>
        </controlled-radio-button>
        <template is="dom-if" if="[[ntpExtension_]]">
          <extension-controlled-indicator
              extension-id="[[ntpExtension_.id]]"
              extension-name="[[ntpExtension_.name]]"
              extension-can-be-disabled="[[ntpExtension_.canBeDisabled]]">
          </extension-controlled-indicator>
        </template>
        <controlled-radio-button name="[[getName_(prefValues_.CONTINUE)]]"
            pref="[[prefs.session.restore_on_startup]]"
            label="$i18n{onStartupContinue}">
        </controlled-radio-button>
        <controlled-radio-button name="[[getName_(prefValues_.OPEN_SPECIFIC)]]"
            pref="[[prefs.session.restore_on_startup]]"
            label="$i18n{onStartupOpenSpecific}">
        </controlled-radio-button>
      </settings-radio-group>
    </div>
    <template is="dom-if"
        if="[[showStartupUrls_(prefs.session.restore_on_startup.value)]]">
      <settings-startup-urls-page prefs="[[prefs]]">
      </settings-startup-urls-page>
    </template>
<!--_html_template_end_-->`,
  is: 'settings-on-startup-page',

  behaviors: [WebUIListenerBehavior],

  properties: {
    prefs: {
      type: Object,
      notify: true,
    },

    /** @private {?NtpExtension} */
    ntpExtension_: Object,

    /**
     * Enum values for the 'session.restore_on_startup' preference.
     * @private {!Object<string, number>}
     */
    prefValues_: {
      readOnly: true,
      type: Object,
      value: {
        CONTINUE: 1,
        OPEN_NEW_TAB: 5,
        OPEN_SPECIFIC: 4,
      },
    },
  },

  /** @override */
  attached() {
    const updateNtpExtension = ntpExtension => {
      // Note that |ntpExtension| is empty if there is no NTP extension.
      this.ntpExtension_ = ntpExtension;
    };
    OnStartupBrowserProxyImpl.getInstance().getNtpExtension().then(
        updateNtpExtension);
    this.addWebUIListener('update-ntp-extension', updateNtpExtension);
  },

  /**
   * @param {number} value
   * @return {string}
   * @private
   */
  getName_(value) {
    return value.toString();
  },

  /**
   * Determine whether to show the user defined startup pages.
   * @param {number} restoreOnStartup Enum value from prefValues_.
   * @return {boolean} Whether the open specific pages is selected.
   * @private
   */
  showStartupUrls_(restoreOnStartup) {
    return restoreOnStartup === this.prefValues_.OPEN_SPECIFIC;
  },
});
