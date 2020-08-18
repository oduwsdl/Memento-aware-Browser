// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'settings-cookies-page' is the settings page containing cookies
 * settings.
 */

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_link_row/cr_link_row.m.js';
import 'chrome://resources/cr_elements/cr_radio_group/cr_radio_group.m.js';
import '../controls/settings_toggle_button.m.js';
import '../icons.m.js';
import '../prefs/prefs.m.js';
import '../settings_shared_css.m.js';
import '../site_settings/site_list.js';
import './collapse_radio_button.js';
import './do_not_track_toggle.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';
import {MetricsBrowserProxy, MetricsBrowserProxyImpl, PrivacyElementInteractions} from '../metrics_browser_proxy.js';
import {PrefsBehavior} from '../prefs/prefs_behavior.m.js';
import {routes} from '../route.js';
import {Router} from '../router.m.js';
import {ContentSetting, ContentSettingsTypes} from '../site_settings/constants.js';

/**
 * The primary cookie setting associated with each radio button. Must be kept in
 * sync with the C++ enum of the same name in
 * chrome/browser/content_settings/generated_cookie_prefs.h
 * @enum {number}
 */
const CookiePrimarySetting = {
  ALLOW_ALL: 0,
  BLOCK_THIRD_PARTY_INCOGNITO: 1,
  BLOCK_THIRD_PARTY: 2,
  BLOCK_ALL: 3,
};

/**
 * Must be kept in sync with the C++ enum of the same name (see
 * chrome/browser/net/prediction_options.h).
 * @enum {number}
 */
const NetworkPredictionOptions = {
  ALWAYS: 0,
  WIFI_ONLY: 1,
  NEVER: 2,
  DEFAULT: 1,
};

Polymer({
  is: 'settings-cookies-page',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared">
      img {
        width: 100%;
      }

      #generalControls {
        padding: 0 var(--cr-section-padding);
      }

      .bullet-line {
        align-items: center;
        display: flex;
        min-height: var(--settings-row-two-line-min-height);
      }

      .bullet-line.one-line {
        min-height: var(--settings-row-min-height);
      }

      .bullet-line > div {
        padding-inline-start: var(--cr-radio-button-size);
      }

      settings-collapse-radio-button {
        --settings-collapse-toggle-min-height: var(--settings-row-min-height);
      }

      settings-collapse-radio-button:not(:first-of-type) {
        --settings-collapse-separator-line: var(--cr-separator-line);
      }

      settings-collapse-radio-button .bullet-line:last-child {
        padding-bottom: 12px;
      }
    </style>
    <picture>
      <source
          srcset="chrome://settings/images/cookies_banner_dark.svg"
          media="(prefers-color-scheme: dark">
      <img id="banner" alt=""
          src="chrome://settings/images/cookies_banner.svg">
    </picture>
    <div id="generalControls">
      <h2>$i18n{cookiePageGeneralControls}</h2>
      <settings-radio-group id="primarySettingGroup"
          pref="{{prefs.generated.cookie_primary_setting}}"
          selectable-elements="cr-radio-button, settings-collapse-radio-button"
          on-change="onCookiePrimarySettingChanged_">
        <settings-collapse-radio-button id="allowAll"
            pref="[[prefs.generated.cookie_primary_setting]]"
            name="[[cookiePrimarySettingEnum_.ALLOW_ALL]]"
            label="$i18n{cookiePageAllowAll}">
          <div slot="collapse">
            <div class="bullet-line">
              <iron-icon icon="settings:cookie"></iron-icon>
              <div class="secondary">$i18n{cookiePageAllowAllBulOne}</div>
            </div>
            <div class="bullet-line">
              <iron-icon icon="settings:cookie"></iron-icon>
              <div class="secondary">$i18n{cookiePageAllowAllBulTwo}</div>
            </div>
          </div>
        </settings-collapse-radio-button>
        <template is="dom-if" if="[[improvedCookieControlsEnabled_]]">
          <settings-collapse-radio-button id="blockThirdPartyIncognito"
              pref="[[prefs.generated.cookie_primary_setting]]"
              name="[[cookiePrimarySettingEnum_.BLOCK_THIRD_PARTY_INCOGNITO]]"
              label="$i18n{cookiePageBlockThirdIncognito}">
            <div slot="collapse">
              <div class="bullet-line">
                <iron-icon icon="settings:cookie"></iron-icon>
                <div class="secondary">
                      $i18n{cookiePageBlockThirdIncognitoBulOne}
                </div>
              </div>
              <div class="bullet-line">
                <iron-icon icon="settings:block"></iron-icon>
                <div class="secondary">
                      $i18n{cookiePageBlockThirdIncognitoBulTwo}
                </div>
              </div>
            </div>
          </settings-collapse-radio-button>
        </template>
        <settings-collapse-radio-button id="blockThirdParty"
            pref="[[prefs.generated.cookie_primary_setting]]"
            name="[[cookiePrimarySettingEnum_.BLOCK_THIRD_PARTY]]"
            label="$i18n{cookiePageBlockThird}">
          <div slot="collapse">
            <div class="bullet-line">
              <iron-icon icon="settings:cookie"></iron-icon>
              <div class="secondary">$i18n{cookiePageBlockThirdBulOne}</div>
            </div>
            <div class="bullet-line">
              <iron-icon icon="settings:block"></iron-icon>
              <div class="secondary">$i18n{cookiePageBlockThirdBulTwo}</div>
            </div>
          </div>
        </settings-collapse-radio-button>
        <settings-collapse-radio-button id="blockAll"
            pref="[[blockAllPref_]]"
            name="[[cookiePrimarySettingEnum_.BLOCK_ALL]]"
            label="$i18n{cookiePageBlockAll}">
          <div slot="collapse">
            <div class="bullet-line">
              <iron-icon icon="settings:block"></iron-icon>
              <div class="secondary">$i18n{cookiePageBlockAllBulOne}</div>
            </div>
            <div class="bullet-line">
              <iron-icon icon="settings:block"></iron-icon>
              <div class="secondary">$i18n{cookiePageBlockAllBulTwo}</div>
            </div>
            <div class="bullet-line one-line">
              <iron-icon icon="settings:block"></iron-icon>
              <div class="secondary">$i18n{cookiePageBlockAllBulThree}</div>
            </div>
          </div>
        </settings-collapse-radio-button>
      </settings-radio-group>
    </div>
    <settings-toggle-button id="clearOnExit" class="hr"
        pref="{{prefs.generated.cookie_session_only}}"
        label="$i18n{deleteDataPostSession}"
        on-settings-boolean-control-change="onClearOnExitChange_">
    </settings-toggle-button>
    <settings-do-not-track-toggle id="doNotTrack"
        prefs="{{prefs}}">
    </settings-do-not-track-toggle>
    <settings-toggle-button id="networkPrediction"
        class="hr"
        hidden="[[!pageVisibility.networkPrediction]]"
        label="$i18n{networkPredictionEnabled}"
        sub-label="$i18n{networkPredictionEnabledDescCookiesPage}"
        pref="{{prefs.net.network_prediction_options}}"
        numeric-unchecked-value="[[networkPredictionUncheckedValue_]]"
        on-settings-boolean-control-change="onNetworkPredictionChange_">
    </settings-toggle-button>
    <cr-link-row id="site-data-trigger" class="hr"
        on-click="onSiteDataClick_" label="$i18n{siteSettingsCookieLink}">
    </cr-link-row>
    <site-list id="allowExceptionsList"
        category="[[cookiesContentSettingType_]]"
        category-subtype="[[contentSetting_.ALLOW]]"
        category-header="$i18n{cookiePageAllowExceptions}"
        read-only-list="[[exceptionListsReadOnly_]]"
        search-filter="[[searchTerm]]">
    </site-list>
    <site-list id="sessionOnlyExceptionsList"
        category="[[cookiesContentSettingType_]]"
        category-subtype="[[contentSetting_.SESSION_ONLY]]"
        category-header="$i18n{cookiePageSessionOnlyExceptions}"
        read-only-list="[[exceptionListsReadOnly_]]"
        search-filter="[[searchTerm]]">
    </site-list>
    <site-list id="blockExceptionsList"
        category="[[cookiesContentSettingType_]]"
        category-subtype="[[contentSetting_.BLOCK]]"
        category-header="$i18n{cookiePageBlockExceptions}"
        read-only-list="[[exceptionListsReadOnly_]]"
        search-filter="[[searchTerm]]">
    </site-list>
<!--_html_template_end_-->`,

  behaviors: [PrefsBehavior, WebUIListenerBehavior],

  properties: {
    /**
     * Preferences state.
     */
    prefs: {
      type: Object,
      notify: true,
    },

    /**
     * Current search term.
     */
    searchTerm: {
      type: String,
      notify: true,
      value: '',
    },

    /**
     * Primary cookie control states for use in bindings.
     * @private
     */
    cookiePrimarySettingEnum_: {
      type: Object,
      value: CookiePrimarySetting,
    },

    /**
     * Used for HTML bindings. This is defined as a property rather than
     * within the ready callback, because the value needs to be available
     * before local DOM initialization - otherwise, the toggle has unexpected
     * behavior.
     * @private {!NetworkPredictionOptions}
     */
    networkPredictionUncheckedValue_: {
      type: Number,
      value: NetworkPredictionOptions.NEVER,
    },

    /** @private */
    contentSetting_: {
      type: Object,
      value: ContentSetting,
    },

    /**
     * @private {!ContentSettingsTypes}
     */
    cookiesContentSettingType_: {
      type: String,
      value: ContentSettingsTypes.COOKIES,
    },

    /** @private */
    exceptionListsReadOnly_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    improvedCookieControlsEnabled_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('improvedCookieControlsEnabled');
      }
    },

    /** @private {!chrome.settingsPrivate.PrefObject} */
    blockAllPref_: {
      type: Object,
      value() {
        return /** @type {chrome.settingsPrivate.PrefObject} */ ({});
      },
    },

    /** @type {!Map<string, (string|Function)>} */
    focusConfig: {
      type: Object,
      observer: 'focusConfigChanged_',
    },
  },

  observers: [`onGeneratedPrefsUpdated_(prefs.generated.cookie_session_only,
      prefs.generated.cookie_primary_setting)`],

  /** @type {?MetricsBrowserProxy} */
  metricsBrowserProxy_: null,

  /** @override */
  ready() {
    this.metricsBrowserProxy_ = MetricsBrowserProxyImpl.getInstance();
  },

  /*
   * @param {!Map<string, string>} newConfig
   * @param {?Map<string, string>} oldConfig
   * @private
   */
  focusConfigChanged_(newConfig, oldConfig) {
    assert(!oldConfig);
    assert(routes.SITE_SETTINGS_SITE_DATA);
    this.focusConfig.set(routes.SITE_SETTINGS_SITE_DATA.path, () => {
      focusWithoutInk(assert(this.$$('#site-data-trigger')));
    });
  },

  /** @private */
  onSiteDataClick_() {
    Router.getInstance().navigateTo(routes.SITE_SETTINGS_SITE_DATA);
  },

  /** @private */
  onGeneratedPrefsUpdated_() {
    const sessionOnlyPref = this.getPref('generated.cookie_session_only');

    // If the clear on exit toggle is managed this implies a content setting
    // policy is present and the exception lists should be disabled.
    this.exceptionListsReadOnly_ = sessionOnlyPref.enforcement ==
        chrome.settingsPrivate.Enforcement.ENFORCED;

    // It is not currently possible to represent multiple management sources
    // for a single a preference. In all management scenarios, the blockAll
    // setting shares the same controlledBy as the cookie_session_only pref.
    // To support this, the controlledBy fields for the |cookie_primary_setting|
    // pref provided to the blockAll control are overwritten with values from
    // the session_only preference.
    this.set(
        'blockAllPref_',
        Object.assign(this.getPref('generated.cookie_primary_setting'), {
          controlledBy: sessionOnlyPref.controlledBy,
          controlledByName: sessionOnlyPref.controlledByName
        }));
  },

  /**
   * Record interaction metrics for the primary cookie radio setting.
   * @private
   */
  onCookiePrimarySettingChanged_() {
    const selection = Number(this.$.primarySettingGroup.selected);
    if (selection === CookiePrimarySetting.ALLOW_ALL) {
      this.metricsBrowserProxy_.recordSettingsPageHistogram(
          PrivacyElementInteractions.COOKIES_ALL);
    } else if (selection === CookiePrimarySetting.BLOCK_THIRD_PARTY_INCOGNITO) {
      this.metricsBrowserProxy_.recordSettingsPageHistogram(
          PrivacyElementInteractions.COOKIES_INCOGNITO);
    } else if (selection === CookiePrimarySetting.BLOCK_THIRD_PARTY) {
      this.metricsBrowserProxy_.recordSettingsPageHistogram(
          PrivacyElementInteractions.COOKIES_THIRD);
    } else {  // CookiePrimarySetting.BLOCK_ALL
      this.metricsBrowserProxy_.recordSettingsPageHistogram(
          PrivacyElementInteractions.COOKIES_BLOCK);
    }
  },

  /** @private */
  onClearOnExitChange_() {
    this.metricsBrowserProxy_.recordSettingsPageHistogram(
        PrivacyElementInteractions.COOKIES_SESSION);
  },

  /**
   * Records changes made to the network prediction setting for logging, the
   * logic of actually changing the setting is taken care of by the
   * net.network_prediction_options pref.
   * @private
   */
  onNetworkPredictionChange_() {
    this.metricsBrowserProxy_.recordSettingsPageHistogram(
        PrivacyElementInteractions.NETWORK_PREDICTION);
  },
});
