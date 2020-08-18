// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_radio_group/cr_radio_group.m.js';
import 'chrome://resources/cr_elements/cr_link_row/cr_link_row.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import './collapse_radio_button.js';
import './disable_safebrowsing_dialog.js';
import './passwords_leak_detection_toggle.js';
import './secure_dns.js';
import '../controls/settings_toggle_button.m.js';
import '../icons.m.js';
import '../prefs/prefs.m.js';
import '../settings_shared_css.m.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';
import {MetricsBrowserProxy, MetricsBrowserProxyImpl, PrivacyElementInteractions} from '../metrics_browser_proxy.js';
import {SyncStatus} from '../people_page/sync_browser_proxy.m.js';
import {PrefsBehavior} from '../prefs/prefs_behavior.m.js';
import {routes} from '../route.js';
import {Router} from '../router.m.js';

import {PrivacyPageBrowserProxy, PrivacyPageBrowserProxyImpl} from './privacy_page_browser_proxy.m.js';
import {SafeBrowsingBrowserProxy, SafeBrowsingBrowserProxyImpl, SafeBrowsingRadioManagedState} from './safe_browsing_browser_proxy.js';

/**
 * Enumeration of all safe browsing modes.
 * @enum {string}
 */
const SafeBrowsing = {
  ENHANCED: 'enhanced',
  STANDARD: 'standard',
  DISABLED: 'disabled',
};

Polymer({
  is: 'settings-security-page',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared">
      img {
        width: 100%;
      }

      #safeBrowsingSection {
        padding: 0 var(--cr-section-padding);
      }

      .bullet-line {
        align-items: center;
        display: flex;
        min-height: var(--settings-row-min-height);
      }

      .bullet-line.three-line {
        min-height: var(--settings-row-three-line-min-height);
      }

      .bullet-line > div {
        padding-inline-start: var(--cr-radio-button-size);
      }

      settings-collapse-radio-button {
        --settings-collapse-toggle-min-height:
            var(--settings-row-three-line-min-height);
      }

      settings-collapse-radio-button:not(:first-of-type) {
        --settings-collapse-separator-line: var(--cr-separator-line);
      }

      settings-collapse-radio-button[hidden] + settings-collapse-radio-button {
          --settings-collapse-separator-line: 0;
      }

      settings-collapse-radio-button .bullet-line:last-child {
        padding-bottom: 12px;
      }

      settings-passwords-leak-detection-toggle,
      settings-toggle-button:not([disabled]) {
        pointer-events: all;
      }

      #safeBrowsingReportingToggle {
        padding-inline-end: 0;
        padding-inline-start: 0;
      }

      #safeBrowsingEnhanced .bullet-line:last-of-type {
        padding-bottom: 12px;
      }
    </style>
    <picture>
      <source
          srcset="chrome://settings/images/safe_browsing_banner_dark.svg"
          media="(prefers-color-scheme: dark">
      <img id="banner" alt=""
          src="chrome://settings/images/safe_browsing_banner.svg">
    </picture>
    <div id="safeBrowsingSection">
      <h2>$i18n{safeBrowsingSectionLabel}</h2>
      <cr-radio-group id="safeBrowsingRadio"
          selected="[[selectSafeBrowsingRadio_]]"
          selectable-elements="cr-radio-button, settings-collapse-radio-button"
          on-selected-changed="onSafeBrowsingRadioChange_">
        <settings-collapse-radio-button name="[[safeBrowsingEnum_.ENHANCED]]"
            id="safeBrowsingEnhanced"
            label="$i18n{safeBrowsingEnhanced}"
            sub-label="$i18n{safeBrowsingEnhancedDesc}"
            hidden="[[!safeBrowsingEnhancedEnabled_]]"
            disabled="[[safeBrowsingRadioManagedState_.enhanced.disabled]]"
            policy-indicator-type=
                "[[safeBrowsingRadioManagedState_.enhanced.indicator]]">
          <div slot="collapse">
            <div class="bullet-line">
              <iron-icon icon="cr:security"></iron-icon>
              <div class="secondary">
                $i18n{safeBrowsingEnhancedBulOne}
              </div>
            </div>
            <div class="bullet-line">
              <iron-icon icon="settings20:googleg"></iron-icon>
              <div class="secondary">
                $i18n{safeBrowsingEnhancedBulTwo}
              </div>
            </div>
            <div class="bullet-line">
              <iron-icon icon="settings:public"></iron-icon>
              <div class="secondary">
                $i18n{safeBrowsingEnhancedBulThree}
              </div>
            </div>
            <div class="bullet-line">
              <iron-icon icon="settings20:vpn-key"></iron-icon>
              <div class="secondary">
                $i18n{safeBrowsingEnhancedBulFour}
              </div>
            </div>
            <div class="bullet-line three-line last-collapse-item">
              <iron-icon icon="settings20:data"></iron-icon>
              <div class="secondary">
                $i18n{safeBrowsingEnhancedBulFive}
              </div>
            </div>
          </div>
        </settings-collapse-radio-button>
        <settings-collapse-radio-button name="[[safeBrowsingEnum_.STANDARD]]"
            id="safeBrowsingStandard"
            label="$i18n{safeBrowsingStandard}"
            sub-label="$i18n{safeBrowsingStandardDesc}"
            info-opened="{{infoOpened_}}"
            disabled="[[safeBrowsingRadioManagedState_.standard.disabled]]"
            policy-indicator-type=
                "[[safeBrowsingRadioManagedState_.standard.indicator]]">
          <div slot="collapse">
            <div class="bullet-line">
              <iron-icon icon="cr:security"></iron-icon>
              <div class="secondary">
                  $i18n{safeBrowsingStandardBulOne}
              </div>
            </div>
            <div class="bullet-line three-line">
              <iron-icon icon="settings20:data"></iron-icon>
              <div class="secondary">
                  $i18n{safeBrowsingStandardBulTwo}
              </div>
            </div>
          </div>
          <div slot="noSelectionCollapse">
            <settings-toggle-button id="safeBrowsingReportingToggle"
                pref="{{prefs.safebrowsing.scout_reporting_enabled}}"
                label="$i18n{safeBrowsingStandardReportingLabel}"
                sub-label="$i18n{safeBrowsingEnableExtendedReportingDesc}"
                on-change="onSafeBrowsingExtendedReportingChange_"
                disabled="[[
                    getDisabledExtendedSafeBrowsing_(prefs.safebrowsing.*)]]">
            </settings-toggle-button>
            <settings-passwords-leak-detection-toggle id="passwordsLeakToggle"
                class="collapsable"
                prefs="{{prefs}}"
                sync-status="[[syncStatus]]">
            </settings-passwords-leak-detection-toggle>
          </div>
        </settings-collapse-radio-button>
        <settings-collapse-radio-button name="[[safeBrowsingEnum_.DISABLED]]"
            id="safeBrowsingDisabled" no-collapse
            label="$i18n{safeBrowsingNone}"
            sub-label="$i18n{safeBrowsingNoneDesc}"
            disabled="[[safeBrowsingRadioManagedState_.disabled.disabled]]"
            policy-indicator-type=
                "[[safeBrowsingRadioManagedState_.disabled.indicator]]">
        </settings-collapse-radio-button>
      </cr-radio-group>
    </div>
    <div class="cr-row first">
      <h2>$i18n{advancedPageTitle}</h2>
    </div>
    <template is="dom-if" if="[[showSecureDnsSetting_]]">
      <settings-secure-dns prefs="{{prefs}}"></settings-secure-dns>
    </template>
    <template is="dom-if" if="[[enableSecurityKeysSubpage_]]">
        <cr-link-row id="security-keys-subpage-trigger"
          class="hr"
          label="$i18n{securityKeysTitle}"
          sub-label="$i18n{securityKeysDesc}"
          on-click="onSecurityKeysClick_"></cr-link-row>
    </template>
<if expr="use_nss_certs or is_win or is_macosx">
    <cr-link-row id="manageCertificates"
        class="hr"
<if expr="not use_nss_certs">
        external
</if>
        label="$i18n{manageCertificates}"
        sub-label="$i18n{manageCertificatesDescription}"
        on-click="onManageCertificatesClick_"></cr-link-row>
</if>
    <cr-link-row id="advanced-protection-program-link"
        class="hr"
        label="$i18n{advancedProtectionProgramTitle}"
        sub-label="$i18n{advancedProtectionProgramDesc}"
        on-click="onAdvancedProtectionProgramLinkClick_"
        external>
    </cr-link-row>
    <template is="dom-if" if="[[showDisableSafebrowsingDialog_]]" restamp>
      <settings-disable-safebrowsing-dialog prefs="{{prefs}}"
          on-close="onDisableSafebrowsingDialogClose_">
      </settings-disable-safebrowsing-dialog>
    </template>
<!--_html_template_end_-->`,

  behaviors: [
    PrefsBehavior,
  ],

  properties: {
    /** @type {SyncStatus} */
    syncStatus: Object,

    /**
     * Preferences state.
     */
    prefs: {
      type: Object,
      notify: true,
    },

    /**
     * Whether the secure DNS setting should be displayed.
     * @private
     */
    showSecureDnsSetting_: {
      type: Boolean,
      readOnly: true,
      value: function() {
        return loadTimeData.getBoolean('showSecureDnsSetting');
      },
    },

    /**
     * Valid safe browsing states.
     * @private
     */
    safeBrowsingEnum_: {
      type: Object,
      value: SafeBrowsing,
    },

    /** @private */
    selectSafeBrowsingRadio_: {
      type: String,
      computed: 'computeSelectSafeBrowsingRadio_(prefs.safebrowsing.*)',
    },

    /** @private */
    safeBrowsingEnhancedEnabled_: {
      type: Boolean,
      readOnly: true,
      value: function() {
        return loadTimeData.getBoolean('safeBrowsingEnhancedEnabled');
      },
    },

    /** @private {!SafeBrowsingRadioManagedState} */
    safeBrowsingRadioManagedState_: Object,

    /** @private */
    enableSecurityKeysSubpage_: {
      type: Boolean,
      readOnly: true,
      value() {
        return loadTimeData.getBoolean('enableSecurityKeysSubpage');
      }
    },

    /** @type {!Map<string, (string|Function)>} */
    focusConfig: {
      type: Object,
      observer: 'focusConfigChanged_',
    },

    /** @private */
    showDisableSafebrowsingDialog_: Boolean,
  },

  observers: [
    'onSafeBrowsingPrefChange_(prefs.safebrowsing.*)',
  ],

  /*
   * @param {!Map<string, string>} newConfig
   * @param {?Map<string, string>} oldConfig
   * @private
   */
  focusConfigChanged_(newConfig, oldConfig) {
    assert(!oldConfig);
    // <if expr="use_nss_certs">
    if (routes.CERTIFICATES) {
      this.focusConfig.set(routes.CERTIFICATES.path, () => {
        focusWithoutInk(assert(this.$$('#manageCertificates')));
      });
    }
    // </if>

    if (routes.SECURITY_KEYS) {
      this.focusConfig.set(routes.SECURITY_KEYS.path, () => {
        focusWithoutInk(assert(this.$$('#security-keys-subpage-trigger')));
      });
    }
  },

  /**
   * @return {string}
   * @private
   */
  computeSelectSafeBrowsingRadio_() {
    if (this.prefs === undefined) {
      return SafeBrowsing.STANDARD;
    }
    if (!this.getPref('safebrowsing.enabled').value) {
      return SafeBrowsing.DISABLED;
    }
    return this.getPref('safebrowsing.enhanced').value ? SafeBrowsing.ENHANCED :
                                                         SafeBrowsing.STANDARD;
  },

  /** @private {PrivacyPageBrowserProxy} */
  browserProxy_: null,

  /** @private {MetricsBrowserProxy} */
  metricsBrowserProxy_: null,

  /** @override */
  ready() {
    this.browserProxy_ = PrivacyPageBrowserProxyImpl.getInstance();

    this.metricsBrowserProxy_ = MetricsBrowserProxyImpl.getInstance();
  },

  /** @override */
  attached() {
    SafeBrowsingBrowserProxyImpl.getInstance().validateSafeBrowsingEnhanced();
  },

  /**
   * Updates the various underlying cookie prefs based on the newly selected
   * radio button.
   * @param {!CustomEvent<{value: string}>} event
   * @private
   */
  onSafeBrowsingRadioChange_: function(event) {
    if (event.detail.value === SafeBrowsing.ENHANCED) {
      this.setPrefValue('safebrowsing.enabled', true);
      this.setPrefValue('safebrowsing.enhanced', true);
    } else if (event.detail.value === SafeBrowsing.STANDARD) {
      this.setPrefValue('safebrowsing.enabled', true);
      this.setPrefValue('safebrowsing.enhanced', false);
    } else {  // disabled state
      this.showDisableSafebrowsingDialog_ = true;
    }
  },

  /**
   * @return {boolean}
   * @private
   */
  getDisabledExtendedSafeBrowsing_() {
    return !this.getPref('safebrowsing.enabled').value ||
        !!this.getPref('safebrowsing.enhanced').value;
  },

  /** @private */
  async onSafeBrowsingPrefChange_() {
    // Retrieve and update safe browsing radio managed state.
    this.safeBrowsingRadioManagedState_ =
        await SafeBrowsingBrowserProxyImpl.getInstance()
            .getSafeBrowsingRadioManagedState();
  },

  /** @private */
  onManageCertificatesClick_() {
    // <if expr="use_nss_certs">
    Router.getInstance().navigateTo(routes.CERTIFICATES);
    // </if>
    // <if expr="is_win or is_macosx">
    this.browserProxy_.showManageSSLCertificates();
    // </if>
    this.metricsBrowserProxy_.recordSettingsPageHistogram(
        PrivacyElementInteractions.MANAGE_CERTIFICATES);
  },

  /** @private */
  onAdvancedProtectionProgramLinkClick_() {
    window.open(loadTimeData.getString('advancedProtectionURL'));
  },

  /** @private */
  onSecurityKeysClick_() {
    Router.getInstance().navigateTo(routes.SECURITY_KEYS);
  },

  /** @private */
  onSafeBrowsingExtendedReportingChange_() {
    this.metricsBrowserProxy_.recordSettingsPageHistogram(
        PrivacyElementInteractions.IMPROVE_SECURITY);
  },

  /**
   * Handles the closure of the disable safebrowsing dialog, reselects the
   * appropriate radio button if the user cancels the dialog, and puts focus on
   * the disable safebrowsing button.
   * @private
   */
  onDisableSafebrowsingDialogClose_() {
    // Check if the dialog was confirmed before closing it.
    if (/** @type {!SettingsDisableSafebrowsingDialogElement} */
        (this.$$('settings-disable-safebrowsing-dialog')).wasConfirmed()) {
      this.setPrefValue('safebrowsing.enabled', false);
      this.setPrefValue('safebrowsing.enhanced', false);
    }

    this.showDisableSafebrowsingDialog_ = false;

    // Have the correct radio button highlighted.
    this.$.safeBrowsingRadio.selected = this.selectSafeBrowsingRadio_;

    // Set focus back to the no protection button regardless of user interaction
    // with the dialog, as it was the entry point to the dialog.
    focusWithoutInk(assert(this.$.safeBrowsingDisabled));
  },
});
