// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_radio_group/cr_radio_group.m.js';
import 'chrome://resources/cr_elements/cr_link_row/cr_link_row.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import './collapse_radio_button.js';
import './disable_safebrowsing_dialog.js';
import './secure_dns.js';
import '../controls/settings_toggle_button.m.js';
import '../icons.m.js';
import '../prefs/prefs.m.js';
import '../settings_shared_css.m.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';
import {MetricsBrowserProxy, MetricsBrowserProxyImpl, PrivacyElementInteractions, SafeBrowsingInteractions} from '../metrics_browser_proxy.js';
import {SyncStatus} from '../people_page/sync_browser_proxy.m.js';
import {PrefsBehavior} from '../prefs/prefs_behavior.m.js';
import {routes} from '../route.js';
import {Route, RouteObserverBehavior, Router} from '../router.m.js';

import {PrivacyPageBrowserProxy, PrivacyPageBrowserProxyImpl} from './privacy_page_browser_proxy.m.js';

/**
 * Enumeration of all safe browsing modes. Must be kept in sync with the enum
 * of the same name located in:
 * chrome/browser/safe_browsing/generated_safe_browsing_pref.h
 * @enum {number}
 */
export const SafeBrowsingSetting = {
  ENHANCED: 0,
  STANDARD: 1,
  DISABLED: 2,
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

      settings-toggle-button {
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
      <settings-radio-group id="safeBrowsingRadioGroup" no-set-pref
          pref="{{prefs.generated.safe_browsing}}"
          selectable-elements="cr-radio-button, settings-collapse-radio-button"
          on-change="onSafeBrowsingRadioChange_">
        <settings-collapse-radio-button id="safeBrowsingEnhanced"
            name="[[safeBrowsingSettingEnum_.ENHANCED]]"
            pref="[[prefs.generated.safe_browsing]]"
            label="$i18n{safeBrowsingEnhanced}"
            sub-label="$i18n{safeBrowsingEnhancedDesc}"
            hidden="[[!safeBrowsingEnhancedEnabled_]]"
            on-expand-clicked="onEnhancedProtectionExpandButtonClicked_"
            no-automatic-collapse>
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
        <settings-collapse-radio-button id="safeBrowsingStandard"
            name="[[safeBrowsingSettingEnum_.STANDARD]]"
            pref="[[prefs.generated.safe_browsing]]"
            label="$i18n{safeBrowsingStandard}"
            sub-label="$i18n{safeBrowsingStandardDesc}"
            info-opened="{{infoOpened_}}"
            on-expand-clicked="onStandardProtectionExpandButtonClicked_"
            no-automatic-collapse>
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
                disabled="[[getDisabledExtendedSafeBrowsing_(
                              prefs.generated.safe_browsing.*)]]">
            </settings-toggle-button>
            <settings-toggle-button id="passwordsLeakToggle"
                label="$i18n{passwordsLeakDetectionLabel}"
                pref="{{prefs.generated.password_leak_detection}}"
                sub-label="[[getPasswordsLeakToggleSubLabel_(
                              prefs.profile.password_manager_leak_detection.*,
                              syncStatus.*)]]">
            </settings-toggle-button>
          </div>
        </settings-collapse-radio-button>
        <settings-collapse-radio-button id="safeBrowsingDisabled" no-collapse
            name="[[safeBrowsingSettingEnum_.DISABLED]]"
            pref="[[prefs.generated.safe_browsing]]"
            label="$i18n{safeBrowsingNone}"
            sub-label="$i18n{safeBrowsingNoneDesc}">
        </settings-collapse-radio-button>
      </settings-radio-group>
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
          on-click="onSecurityKeysClick_"
          role-description="$i18n{subpageArrowRoleDescription}"></cr-link-row>
    </template>
<if expr="use_nss_certs or is_win or is_macosx">
    <cr-link-row id="manageCertificates"
        class="hr"
<if expr="not use_nss_certs">
        external
</if>
<if expr="use_nss_certs">
        role-description="$i18n{subpageArrowRoleDescription}"
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
    I18nBehavior,
    PrefsBehavior,
    RouteObserverBehavior,
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
    safeBrowsingSettingEnum_: {
      type: Object,
      value: SafeBrowsingSetting,
    },

    /** @private */
    safeBrowsingEnhancedEnabled_: {
      type: Boolean,
      readOnly: true,
      value: function() {
        return loadTimeData.getBoolean('safeBrowsingEnhancedEnabled');
      },
    },

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

  /** @private {PrivacyPageBrowserProxy} */
  browserProxy_: null,

  /** @private {MetricsBrowserProxy} */
  metricsBrowserProxy_: null,

  /** @override */
  ready() {
    // Expand initial pref value manually because automatic
    // expanding is disabled.
    const prefValue = this.getPref('generated.safe_browsing').value;
    if (prefValue === SafeBrowsingSetting.ENHANCED) {
      this.$.safeBrowsingEnhanced.expanded = true;
    } else if (prefValue === SafeBrowsingSetting.STANDARD) {
      this.$.safeBrowsingStandard.expanded = true;
    }
    this.browserProxy_ = PrivacyPageBrowserProxyImpl.getInstance();

    this.metricsBrowserProxy_ = MetricsBrowserProxyImpl.getInstance();
  },

  /**
   * RouteObserverBehavior
   * @param {!Route} route
   * @protected
   */
  currentRouteChanged(route) {
    if (route === routes.SECURITY) {
      this.metricsBrowserProxy_.recordSafeBrowsingInteractionHistogram(
          SafeBrowsingInteractions.SAFE_BROWSING_SHOWED);
      const queryParams = Router.getInstance().getQueryParameters();
      const section = queryParams.get('q');
      if (section === 'enhanced') {
        this.$.safeBrowsingEnhanced.expanded = true;
        this.$.safeBrowsingStandard.expanded = false;
      }
    }
  },

  /**
   * Updates the buttons' expanded status by propagating previous click
   * events
   * @private
   */
  updateCollapsedButtons_() {
    this.$.safeBrowsingEnhanced.updateCollapsed();
    this.$.safeBrowsingStandard.updateCollapsed();
  },

  /**
   * Possibly displays the Safe Browsing disable dialog based on the users
   * selection.
   * @private
   */
  onSafeBrowsingRadioChange_: function() {
    const selected =
        Number.parseInt(this.$.safeBrowsingRadioGroup.selected, 10);
    const prefValue = this.getPref('generated.safe_browsing').value;
    if (prefValue !== selected) {
      this.recordInteractionHistogramOnRadioChange_(
          /** @type {!SafeBrowsingSetting} */ (selected));
      this.recordActionOnRadioChange_(
          /** @type {!SafeBrowsingSetting} */ (selected));
    }
    if (selected === SafeBrowsingSetting.DISABLED) {
      this.showDisableSafebrowsingDialog_ = true;
    } else {
      this.updateCollapsedButtons_();
      this.$.safeBrowsingRadioGroup.sendPrefChange();
    }
  },

  /**
   * @return {boolean}
   * @private
   */
  getDisabledExtendedSafeBrowsing_() {
    return this.getPref('generated.safe_browsing').value !==
        SafeBrowsingSetting.STANDARD;
  },

  /**
   * @return {string}
   * @private
   */
  getPasswordsLeakToggleSubLabel_() {
    let subLabel = this.i18n('passwordsLeakDetectionGeneralDescription');
    if (this.getPref('profile.password_manager_leak_detection').value &&
        (!this.syncStatus.signedIn ||
         !!this.syncStatus.signedIn && !!this.syncStatus.hasError)) {
      subLabel +=
          ' ' +  // Whitespace is a valid sentence separator w.r.t. i18n.
          this.i18n('passwordsLeakDetectionSignedOutEnabledDescription');
    }
    return subLabel;
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
    const confirmed =
        /** @type {!SettingsDisableSafebrowsingDialogElement} */ (
            this.$$('settings-disable-safebrowsing-dialog'))
            .wasConfirmed();
    this.recordInteractionHistogramOnSafeBrowsingDialogClose_(confirmed);
    this.recordActionOnSafeBrowsingDialogClose_(confirmed);
    // Check if the dialog was confirmed before closing it.
    if (confirmed) {
      this.$.safeBrowsingRadioGroup.sendPrefChange();
      this.updateCollapsedButtons_();
    } else {
      this.$.safeBrowsingRadioGroup.resetToPrefValue();
    }

    this.showDisableSafebrowsingDialog_ = false;

    // Set focus back to the no protection button regardless of user interaction
    // with the dialog, as it was the entry point to the dialog.
    focusWithoutInk(assert(this.$.safeBrowsingDisabled));
  },

  /** @private */
  onEnhancedProtectionExpandButtonClicked_() {
    this.recordInteractionHistogramOnExpandButtonClicked_(
        SafeBrowsingSetting.ENHANCED);
    this.recordActionOnExpandButtonClicked_(SafeBrowsingSetting.ENHANCED);
  },

  /** @private */
  onStandardProtectionExpandButtonClicked_() {
    this.recordInteractionHistogramOnExpandButtonClicked_(
        SafeBrowsingSetting.STANDARD);
    this.recordActionOnExpandButtonClicked_(SafeBrowsingSetting.STANDARD);
  },

  /**
   * @param {!SafeBrowsingSetting} safeBrowsingSetting
   * @private
   */
  recordInteractionHistogramOnRadioChange_(safeBrowsingSetting) {
    let action;
    if (safeBrowsingSetting === SafeBrowsingSetting.ENHANCED) {
      action =
          SafeBrowsingInteractions.SAFE_BROWSING_ENHANCED_PROTECTION_CLICKED;
    } else if (safeBrowsingSetting === SafeBrowsingSetting.STANDARD) {
      action =
          SafeBrowsingInteractions.SAFE_BROWSING_STANDARD_PROTECTION_CLICKED;
    } else {
      action =
          SafeBrowsingInteractions.SAFE_BROWSING_DISABLE_SAFE_BROWSING_CLICKED;
    }
    this.metricsBrowserProxy_.recordSafeBrowsingInteractionHistogram(action);
  },

  /**
   * @param {!SafeBrowsingSetting} safeBrowsingSetting
   * @private
   */
  recordInteractionHistogramOnExpandButtonClicked_(safeBrowsingSetting) {
    this.metricsBrowserProxy_.recordSafeBrowsingInteractionHistogram(
        safeBrowsingSetting === SafeBrowsingSetting.ENHANCED ?
            SafeBrowsingInteractions
                .SAFE_BROWSING_ENHANCED_PROTECTION_EXPAND_ARROW_CLICKED :
            SafeBrowsingInteractions
                .SAFE_BROWSING_STANDARD_PROTECTION_EXPAND_ARROW_CLICKED);
  },

  /**
   * @param {boolean} confirmed
   * @private
   */
  recordInteractionHistogramOnSafeBrowsingDialogClose_(confirmed) {
    this.metricsBrowserProxy_.recordSafeBrowsingInteractionHistogram(
        confirmed ? SafeBrowsingInteractions
                        .SAFE_BROWSING_DISABLE_SAFE_BROWSING_DIALOG_CONFIRMED :
                    SafeBrowsingInteractions
                        .SAFE_BROWSING_DISABLE_SAFE_BROWSING_DIALOG_DENIED);
  },

  /**
   * @param {!SafeBrowsingSetting} safeBrowsingSetting
   * @private
   */
  recordActionOnRadioChange_(safeBrowsingSetting) {
    let actionName;
    if (safeBrowsingSetting === SafeBrowsingSetting.ENHANCED) {
      actionName = 'SafeBrowsing.Settings.EnhancedProtectionClicked';
    } else if (safeBrowsingSetting === SafeBrowsingSetting.STANDARD) {
      actionName = 'SafeBrowsing.Settings.StandardProtectionClicked';
    } else {
      actionName = 'SafeBrowsing.Settings.DisableSafeBrowsingClicked';
    }
    this.metricsBrowserProxy_.recordAction(actionName);
  },

  /**
   * @param {!SafeBrowsingSetting} safeBrowsingSetting
   * @private
   */
  recordActionOnExpandButtonClicked_(safeBrowsingSetting) {
    this.metricsBrowserProxy_.recordAction(
        safeBrowsingSetting === SafeBrowsingSetting.ENHANCED ?
            'SafeBrowsing.Settings.EnhancedProtectionExpandArrowClicked' :
            'SafeBrowsing.Settings.StandardProtectionExpandArrowClicked');
  },

  /**
   * @param {boolean} confirmed
   * @private
   */
  recordActionOnSafeBrowsingDialogClose_(confirmed) {
    this.metricsBrowserProxy_.recordAction(
        confirmed ? 'SafeBrowsing.Settings.DisableSafeBrowsingDialogConfirmed' :
                    'SafeBrowsing.Settings.DisableSafeBrowsingDialogDenied');
  },
});
