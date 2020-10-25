// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'personalization-options' contains several toggles related to
 * personalizations.
 */
import {Polymer, html} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '//resources/cr_elements/cr_button/cr_button.m.js';
import '//resources/cr_elements/cr_toggle/cr_toggle.m.js';
import {WebUIListenerBehavior} from '//resources/js/web_ui_listener_behavior.m.js';
import '../controls/settings_toggle_button.m.js';
import {loadTimeData} from '../i18n_setup.js';
import {LifetimeBrowserProxyImpl} from '../lifetime_browser_proxy.m.js';
import '../people_page/signout_dialog.m.js';
import {StatusAction, SyncStatus} from '../people_page/sync_browser_proxy.m.js';
import '../prefs/prefs.m.js';
import {PrefsBehavior} from '../prefs/prefs_behavior.m.js';
import '../settings_shared_css.m.js';
import {PrivacyPageBrowserProxy, PrivacyPageBrowserProxyImpl, MetricsReporting} from './privacy_page_browser_proxy.m.js';

// <if expr="not chromeos">
import '//resources/cr_elements/cr_toast/cr_toast.m.js';
// </if>


Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="settings-shared">
      :host(.list-frame) settings-toggle-button {
        padding-inline-end: 0;
        padding-inline-start: 0;
      }

      :host(.list-frame) settings-toggle-button:first-of-type {
        border-top: none;
      }
    </style>
<if expr="not chromeos">
    <settings-toggle-button id="signinAllowedToggle"
        class="hr"
        disabled="[[syncFirstSetupInProgress_]]"
        pref="{{prefs.signin.allowed_on_next_startup}}"
        label="$i18n{signinAllowedTitle}"
        sub-label="$i18n{signinAllowedDescription}"
        on-settings-boolean-control-change="onSigninAllowedChange_"
        no-set-pref>
    </settings-toggle-button>
</if><!-- not chromeos -->
    <settings-toggle-button id="searchSuggestToggle"
        class="hr"
        hidden="[[!pageVisibility.searchPrediction]]"
        pref="{{prefs.search.suggest_enabled}}"
        label="$i18n{searchSuggestPref}"
        sub-label="$i18n{searchSuggestPrefDesc}">
    </settings-toggle-button>
<if expr="_google_chrome">
<if expr="chromeos">
    <settings-toggle-button class="hr"
        pref="{{prefs.cros.metrics.reportingEnabled}}"
        label="$i18n{enablePersonalizationLogging}"
        sub-label="$i18n{enablePersonalizationLoggingDesc}">
    </settings-toggle-button>
</if><!-- chromeos -->
<if expr="not chromeos">
    <settings-toggle-button id="metricsReportingControl"
        class="hr"
        pref="[[metricsReportingPref_]]"
        label="$i18n{enablePersonalizationLogging}"
        sub-label="$i18n{enablePersonalizationLoggingDesc}" no-set-pref
        on-settings-boolean-control-change="onMetricsReportingChange_">
      <template is="dom-if" if="[[showRestart_]]" restamp>
        <cr-button on-click="onRestartTap_" id="restart"
            slot="more-actions">
          $i18n{restart}
        </cr-button>
      </template>
    </settings-toggle-button>
</if><!-- not chromeos -->
</if><!-- _google_chrome -->
    <settings-toggle-button id="urlCollectionToggle"
        class="hr"
        pref="{{prefs.url_keyed_anonymized_data_collection.enabled}}"
        label="$i18n{urlKeyedAnonymizedDataCollection}"
        sub-label="$i18n{urlKeyedAnonymizedDataCollectionDesc}">
    </settings-toggle-button>
<if expr="_google_chrome">
    <settings-toggle-button id="spellCheckControl"
        class="hr"
        pref="{{prefs.spellcheck.use_spelling_service}}"
        on-settings-boolean-control-change="onUseSpellingServiceToggle_"
        label="$i18n{spellingPref}"
        sub-label="$i18n{spellingDescription}"
        hidden="[[!showSpellCheckControl_(prefs.spellcheck.dictionaries)]]">
    </settings-toggle-button>
</if><!-- _google_chrome -->
    <template is="dom-if" if="[[shouldShowDriveSuggest_(
        syncStatus, syncStatus.signedIn, syncStatus.statusAction)]]" restamp>
      <settings-toggle-button id="driveSuggestControl" class="hr"
          pref="{{prefs.documentsuggest.enabled}}"
          label="$i18n{driveSuggestPref}"
          sub-label="$i18n{driveSuggestPrefDesc}">
      </settings-toggle-button>
    </template>

    <template is="dom-if" if="[[showSignoutDialog_]]" restamp>
      <settings-signout-dialog sync-status="[[syncStatus]]"
          on-close="onSignoutDialogClosed_">
      </settings-signout-dialog>
    </template>

<if expr="not chromeos">
    <cr-toast id="toast">
      <div>$i18n{restartToApplyChanges}</div>
      <cr-button on-click="onRestartTap_">$i18n{restart}</cr-button>
    </cr-toast>
</if>
<!--_html_template_end_-->`,
  is: 'settings-personalization-options',

  behaviors: [
    PrefsBehavior,
    WebUIListenerBehavior,
  ],

  properties: {
    prefs: {
      type: Object,
      notify: true,
    },

    /**
     * TODO(dpapad): Restore actual type !PrivacyPageVisibility after this file
     * is no longer reused by chrome://os-settings.
     * Dictionary defining page visibility.
     * @type {!Object}
     */
    pageVisibility: Object,

    /** @type {SyncStatus} */
    syncStatus: Object,

    // <if expr="_google_chrome and not chromeos">
    // TODO(dbeam): make a virtual.* pref namespace and set/get this normally
    // (but handled differently in C++).
    /** @private {chrome.settingsPrivate.PrefObject} */
    metricsReportingPref_: {
      type: Object,
      value() {
        // TODO(dbeam): this is basically only to appease PrefControlBehavior.
        // Maybe add a no-validate attribute instead? This makes little sense.
        return /** @type {chrome.settingsPrivate.PrefObject} */ ({});
      },
    },

    /** @private */
    showRestart_: Boolean,
    // </if>

    /** @private */
    showSignoutDialog_: Boolean,

    /** @private */
    syncFirstSetupInProgress_: {
      type: Boolean,
      value: false,
      computed: 'computeSyncFirstSetupInProgress_(syncStatus)',
    },
  },

  /** @private {?PrivacyPageBrowserProxy} */
  browserProxy_: null,

  /**
   * @return {boolean}
   * @private
   */
  computeSyncFirstSetupInProgress_() {
    return !!this.syncStatus && !!this.syncStatus.firstSetupInProgress;
  },

  /** @override */
  ready() {
    this.browserProxy_ = PrivacyPageBrowserProxyImpl.getInstance();

    // <if expr="_google_chrome and not chromeos">
    const setMetricsReportingPref = this.setMetricsReportingPref_.bind(this);
    this.addWebUIListener('metrics-reporting-change', setMetricsReportingPref);
    this.browserProxy_.getMetricsReporting().then(setMetricsReportingPref);
    // </if>
  },

  /**
   * Returns the autocomplete search suggestions CrToggleElement.
   * @return {?CrToggleElement}
   */
  getSearchSuggestToggle() {
    return /** @type {?CrToggleElement} */ (this.$$('#searchSuggestToggle'));
  },

  /**
   * Returns the anonymized URL collection CrToggleElement.
   * @return {?CrToggleElement}
   */
  getUrlCollectionToggle() {
    return /** @type {?CrToggleElement} */ (this.$$('#urlCollectionToggle'));
  },

  /**
   * Returns the Drive suggestions CrToggleElement.
   * @return {?CrToggleElement}
   */
  getDriveSuggestToggle() {
    return /** @type {?CrToggleElement} */ (this.$$('#driveSuggestControl'));
  },

  // <if expr="_google_chrome and not chromeos">
  /** @private */
  onMetricsReportingChange_() {
    const enabled = this.$.metricsReportingControl.checked;
    this.browserProxy_.setMetricsReportingEnabled(enabled);
  },

  /**
   * @param {!MetricsReporting} metricsReporting
   * @private
   */
  setMetricsReportingPref_(metricsReporting) {
    const hadPreviousPref = this.metricsReportingPref_.value !== undefined;
    const pref = {
      key: '',
      type: chrome.settingsPrivate.PrefType.BOOLEAN,
      value: metricsReporting.enabled,
    };
    if (metricsReporting.managed) {
      pref.enforcement = chrome.settingsPrivate.Enforcement.ENFORCED;
      pref.controlledBy = chrome.settingsPrivate.ControlledBy.USER_POLICY;
    }

    // Ignore the next change because it will happen when we set the pref.
    this.metricsReportingPref_ = pref;

    // TODO(dbeam): remember whether metrics reporting was enabled when Chrome
    // started.
    if (metricsReporting.managed) {
      this.showRestart_ = false;
    } else if (hadPreviousPref) {
      this.showRestart_ = true;
    }
  },
  // </if>

  // <if expr="_google_chrome">
  /**
   * @param {!Event} event
   * @private
   */
  onUseSpellingServiceToggle_(event) {
    // If turning on using the spelling service, automatically turn on
    // spellcheck so that the spelling service can run.
    if (event.target.checked) {
      this.setPrefValue('browser.enable_spellchecking', true);
    }
  },
  // </if>

  /**
   * @return {boolean}
   * @private
   */
  showSpellCheckControl_() {
    return (
        !!this.prefs.spellcheck &&
        /** @type {!Array<string>} */
        (this.prefs.spellcheck.dictionaries.value).length > 0);
  },

  /**
   * @return {boolean}
   * @private
   */
  shouldShowDriveSuggest_() {
    return loadTimeData.getBoolean('driveSuggestAvailable') &&
        !!this.syncStatus && !!this.syncStatus.signedIn &&
        this.syncStatus.statusAction !== StatusAction.REAUTHENTICATE;
  },

  /** @private */
  onSigninAllowedChange_() {
    if (this.syncStatus.signedIn && !this.$$('#signinAllowedToggle').checked) {
      // Switch the toggle back on and show the signout dialog.
      this.$$('#signinAllowedToggle').checked = true;
      this.showSignoutDialog_ = true;
    } else {
      /** @type {!SettingsToggleButtonElement} */ (
          this.$$('#signinAllowedToggle'))
          .sendPrefChange();
      this.$.toast.show();
    }
  },

  /** @private */
  onSignoutDialogClosed_() {
    if (/** @type {!SettingsSignoutDialogElement} */ (
            this.$$('settings-signout-dialog'))
            .wasConfirmed()) {
      this.$$('#signinAllowedToggle').checked = false;
      /** @type {!SettingsToggleButtonElement} */ (
          this.$$('#signinAllowedToggle'))
          .sendPrefChange();
      this.$.toast.show();
    }
    this.showSignoutDialog_ = false;
  },

  /**
   * @param {!Event} e
   * @private
   */
  onRestartTap_(e) {
    e.stopPropagation();
    LifetimeBrowserProxyImpl.getInstance().restart();
  },
});
