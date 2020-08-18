// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'settings-clear-browsing-data-dialog' allows the user to
 * delete browsing data that has been cached by Chromium.
 */

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/cr_tabs/cr_tabs.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-pages/iron-pages.js';
import 'chrome://resources/polymer/v3_0/paper-spinner/paper-spinner-lite.js';
import './history_deletion_dialog.js';
import './installed_app_checkbox.js';
import '../controls/settings_checkbox.js';
import '../icons.m.js';
import '../settings_shared_css.m.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {DropdownMenuOptionList} from '../controls/settings_dropdown_menu.m.js';
import {loadTimeData} from '../i18n_setup.js';
import {StatusAction, SyncBrowserProxy, SyncBrowserProxyImpl, SyncStatus} from '../people_page/sync_browser_proxy.m.js';
import {routes} from '../route.js';
import {Route, RouteObserverBehavior, Router} from '../router.m.js';

import {ClearBrowsingDataBrowserProxy, ClearBrowsingDataBrowserProxyImpl, InstalledApp} from './clear_browsing_data_browser_proxy.js';

/**
 * @param {!Object} oldDialog the dialog to close
 * @param {!Object} newDialog the dialog to open
 * @private
 */
function replaceDialog(oldDialog, newDialog) {
  oldDialog.addEventListener('close', e => {
    e.stopPropagation();
  }, {once: true});
  oldDialog.close();
  if (!newDialog.open) {
    newDialog.showModal();
  }
}

Polymer({
  is: 'settings-clear-browsing-data-dialog',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared">
      :host {
        /* Fixed height to allow multiple tabs with different height.
         * The last entry in the advanced tab should show half an entry.
         * crbug.com/652027 */
        --body-container-height: 322px;
      }

      #clearBrowsingDataDialog {
        --border-top-color: var(--paper-grey-300);
        --cr-dialog-top-container-min-height: 42px;
        --cr-dialog-body-border-top: 1px solid var(--border-top-color);
      }

      @media (prefers-color-scheme: dark) {
        #clearBrowsingDataDialog {
          --border-top-color: var(--cr-separator-color);
        }
      }

      #clearBrowsingDataDialog:not(.fully-rendered) {
        visibility: hidden;
      }

      #clearBrowsingDataDialog [slot=title] {
        padding-bottom: 8px;
      }

      #clearBrowsingDataDialog::part(body-container) {
        height: var(--body-container-height);
      }

      #clearBrowsingDataDialog [slot=body] {
        padding-top: 8px;
      }

      #clearBrowsingDataDialog [slot=footer] {
        background: var(--paper-grey-50);
        border-top: none;
        padding: 0;
      }

      @media (prefers-color-scheme: dark) {
        #clearBrowsingDataDialog [slot=footer] {
          background: rgb(50, 54, 57);  /* Custom color from Namrata. */
        }
      }

      .row {
        align-items: center;
        display: flex;
        min-height: 40px;
      }

      paper-spinner-lite {
        margin-bottom: auto;
        margin-inline-end: 16px;
        margin-top: auto;
      }

      settings-checkbox,
      installed-app-checkbox {
        --settings-row-two-line-min-height: 48px;
      }

      #basic-tab settings-checkbox + settings-checkbox {
        --settings-checkbox-margin-top: 12px;
      }

      cr-tabs {
        --cr-tabs-font-size: 100%;
        --cr-tabs-height: 40px;
      }

      .time-range-row {
        margin-bottom: 12px;
      }

      .time-range-select {
        margin-inline-start: 12px;
      }

      [slot=title] .secondary {
        font-size: calc(13 / 15 * 100%);
        padding-top: 8px;
      }

      .divider {
        border-top: var(--cr-separator-line);
        margin: 0 16px;
      }

      #footer-description {
        color: var(--cr-secondary-text-color);
        padding: 16px;
      }
    </style>

    <cr-dialog id="clearBrowsingDataDialog"
        close-text="$i18n{close}" ignore-popstate has-tabs>
      <div slot="title">
        <div>$i18n{clearBrowsingData}</div>
      </div>
      <div slot="header">
        <cr-tabs tab-names="[[tabsNames_]]"
            selected="{{prefs.browser.last_clear_browsing_data_tab.value}}"
            on-selected-changed="recordTabChange_"></cr-tabs>
      </div>
      <div slot="body">
        <iron-pages id="tabs"
            selected="[[prefs.browser.last_clear_browsing_data_tab.value]]"
            on-selected-item-changed="updateClearButtonState_">
          <div id="basic-tab">
            <div class="row time-range-row">
              <span class="time-range-label" aria-hidden="true">
                $i18n{clearTimeRange}
              </span>
              <settings-dropdown-menu id="clearFromBasic"
                  class="time-range-select"
                  label="$i18n{clearTimeRange}"
                  pref="{{prefs.browser.clear_data.time_period_basic}}"
                  menu-options="[[clearFromOptions_]]">
              </settings-dropdown-menu>
            </div>
            <!-- Note: whether these checkboxes are checked are ignored if
                 deleting history is disabled (i.e. supervised users, policy),
                 so it's OK to have a hidden checkbox that's also checked (as
                 the C++ accounts for whether a user is allowed to delete
                 history independently). -->
            <settings-checkbox id="browsingCheckboxBasic"
                pref="{{prefs.browser.clear_data.browsing_history_basic}}"
                label="$i18n{clearBrowsingHistory}"
                sub-label-html="[[browsingCheckboxLabel_(
                    isSignedIn_, isSyncingHistory_, syncStatus.hasError,
                    '$i18nPolymer{clearBrowsingHistorySummary}',
                    '$i18nPolymer{clearBrowsingHistorySummarySignedIn}',
                    '$i18nPolymer{clearBrowsingHistorySummarySynced}')]]"
                disabled="[[clearingInProgress_]]"
                hidden="[[isSupervised_]]" no-set-pref>
            </settings-checkbox>
            <settings-checkbox id="cookiesCheckboxBasic"
                class="cookies-checkbox"
                pref="{{prefs.browser.clear_data.cookies_basic}}"
                label="$i18n{clearCookies}"
                sub-label="[[cookiesCheckboxLabel_(
                    shouldShowCookieException_,
                    '$i18nPolymer{clearCookiesSummary}',
                    '$i18nPolymer{clearCookiesSummarySignedIn}')]]"
                disabled="[[clearingInProgress_]]" no-set-pref>
            </settings-checkbox>
            <settings-checkbox id="cacheCheckboxBasic"
                class="cache-checkbox"
                pref="{{prefs.browser.clear_data.cache_basic}}"
                label="$i18n{clearCache}"
                sub-label="[[counters_.cache_basic]]"
                disabled="[[clearingInProgress_]]" no-set-pref>
            </settings-checkbox>
          </div>
          <div id="advanced-tab">
            <div class="row time-range-row">
              <span class="time-range-label" aria-hidden="true">
                $i18n{clearTimeRange}
              </span>
              <settings-dropdown-menu id="clearFrom"
                  class="time-range-select"
                  label="$i18n{clearTimeRange}"
                  pref="{{prefs.browser.clear_data.time_period}}"
                  menu-options="[[clearFromOptions_]]">
              </settings-dropdown-menu>
            </div>
            <settings-checkbox id="browsingCheckbox"
                pref="{{prefs.browser.clear_data.browsing_history}}"
                label="$i18n{clearBrowsingHistory}"
                sub-label="[[counters_.browsing_history]]"
                disabled="[[clearingInProgress_]]"
                hidden="[[isSupervised_]]" no-set-pref>
            </settings-checkbox>
            <settings-checkbox id="downloadCheckbox"
                pref="{{prefs.browser.clear_data.download_history}}"
                label="$i18n{clearDownloadHistory}"
                sub-label="[[counters_.download_history]]"
                disabled="[[clearingInProgress_]]"
                hidden="[[isSupervised_]]" no-set-pref>
            </settings-checkbox>
            <settings-checkbox id="cookiesCheckbox"
                class="cookies-checkbox"
                pref="{{prefs.browser.clear_data.cookies}}"
                label="$i18n{clearCookies}"
                sub-label="[[counters_.cookies]]"
                disabled="[[clearingInProgress_]]" no-set-pref>
            </settings-checkbox>
            <settings-checkbox id="cacheCheckbox"
                class="cache-checkbox"
                pref="{{prefs.browser.clear_data.cache}}"
                label="$i18n{clearCache}"
                sub-label="[[counters_.cache]]"
                disabled="[[clearingInProgress_]]" no-set-pref>
            </settings-checkbox>
            <settings-checkbox
                pref="{{prefs.browser.clear_data.passwords}}"
                label="$i18n{clearPasswords}"
                sub-label="[[counters_.passwords]]"
                disabled="[[clearingInProgress_]]" no-set-pref>
            </settings-checkbox>
            <settings-checkbox
                pref="{{prefs.browser.clear_data.form_data}}"
                label="$i18n{clearFormData}"
                sub-label="[[counters_.form_data]]"
                disabled="[[clearingInProgress_]]" no-set-pref>
            </settings-checkbox>
            <settings-checkbox
                pref="{{prefs.browser.clear_data.site_settings}}"
                label="$i18nPolymer{siteSettings}"
                sub-label="[[counters_.site_settings]]"
                disabled="[[clearingInProgress_]]" no-set-pref>
            </settings-checkbox>
            <settings-checkbox
                pref="{{prefs.browser.clear_data.hosted_apps_data}}"
                label="$i18n{clearHostedAppData}"
                sub-label="[[counters_.hosted_apps_data]]"
                disabled="[[clearingInProgress_]]" no-set-pref>
            </settings-checkbox>
          </div>
        </iron-pages>
      </div>
      <div slot="button-container">
        <paper-spinner-lite active="[[clearingInProgress_]]">
        </paper-spinner-lite>
        <cr-button class="cancel-button" disabled="[[clearingInProgress_]]"
            on-click="onCancelTap_">$i18n{cancel}</cr-button>
        <cr-button id="clearBrowsingDataConfirm"
            class="action-button" on-click="onClearBrowsingDataClick_"
            disabled="[[isClearButtonDisabled_(clearingInProgress_,
                                               clearButtonDisabled_)]]">
            $i18n{clearData}
        </cr-button>
      </div>
      <template is="dom-if" if="[[shouldShowFooter_(syncStatus.signedIn)]]"
          restamp>
        <div slot="footer">
          <settings-sync-account-control sync-status="[[syncStatus]]"
              prefs="{{prefs}}" hide-buttons>
          </settings-sync-account-control>
          <div class="divider"></div>
          <div id="footer-description" on-click="onSyncDescriptionLinkClicked_">
            <span id="sync-info" hidden="[[syncStatus.hasError]]">
              $i18nRaw{clearBrowsingDataWithSync}
            </span>
            <span id="sync-paused-info" hidden="[[!isSyncPaused_]]">
              $i18nRaw{clearBrowsingDataWithSyncPaused}
            </span>
            <span id="sync-passphrase-error-info"
                hidden="[[!hasPassphraseError_]]">
              $i18nRaw{clearBrowsingDataWithSyncPassphraseError}
            </span>
            <span id="sync-other-error-info" hidden="[[!hasOtherSyncError_]]">
              $i18nRaw{clearBrowsingDataWithSyncError}
            </span>
          </div>
        </div>
      </template>
    </cr-dialog>

    <cr-dialog id="installedAppsDialog" close-text="$i18n{close}"
               ignore-popstate show-scroll-borders
               on-close="hideInstalledApps_">
      <div slot="title">
        $i18n{installedAppsTitle}
      </div>
      <div slot="body">
        <template is="dom-repeat" items="[[installedApps_]]">
          <div class="row">
            <installed-app-checkbox
              installed_app="[[item]]"
              disabled="[[clearingInProgress_]]">
            </installed-app-checkbox>
          </div>
        </template>
      </div>
      <div slot="button-container">
        <paper-spinner-lite active="[[clearingInProgress_]]">
        </paper-spinner-lite>
        <cr-button class="cancel-button" disabled="[[clearingInProgress_]]"
            on-click="hideInstalledApps_">
          $i18n{cancel}
        </cr-button>
        <cr-button id="installedAppsConfirm" class="action-button"
            disabled="[[clearingInProgress_]]"
            on-click="onInstalledAppsConfirmClick_">
          $i18n{installedAppsConfirm}
        </cr-button>
      </div>
    </cr-dialog>

    <template is="dom-if" if="[[showHistoryDeletionDialog_]]" restamp>
      <settings-history-deletion-dialog id="notice"
          on-close="onHistoryDeletionDialogClose_">
      </settings-history-deletion-dialog>
    </template>
<!--_html_template_end_-->`,

  behaviors: [
    WebUIListenerBehavior,
    RouteObserverBehavior,
  ],

  properties: {
    /**
     * Preferences state.
     */
    prefs: {
      type: Object,
      notify: true,
    },

    /**
     * The current sync status, supplied by SyncBrowserProxy.
     * TODO(dpapad): make |syncStatus| private.
     * @type {?SyncStatus}
     */
    syncStatus: Object,

    /**
     * Results of browsing data counters, keyed by the suffix of
     * the corresponding data type deletion preference, as reported
     * by the C++ side.
     * @private {!Object<string>}
     */
    counters_: {
      type: Object,
      // Will be filled as results are reported.
      value() {
        return {};
      }
    },

    /**
     * List of options for the dropdown menu.
     * @private {!DropdownMenuOptionList}
     */
    clearFromOptions_: {
      readOnly: true,
      type: Array,
      value: [
        {value: 0, name: loadTimeData.getString('clearPeriodHour')},
        {value: 1, name: loadTimeData.getString('clearPeriod24Hours')},
        {value: 2, name: loadTimeData.getString('clearPeriod7Days')},
        {value: 3, name: loadTimeData.getString('clearPeriod4Weeks')},
        {value: 4, name: loadTimeData.getString('clearPeriodEverything')},
      ],
    },

    /** @private */
    clearingInProgress_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    clearButtonDisabled_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    isSupervised_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('isSupervised');
      },
    },

    /** @private */
    showHistoryDeletionDialog_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    isSignedIn_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    isSyncingHistory_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    shouldShowCookieException_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    isSyncPaused_: {
      type: Boolean,
      value: false,
      computed: 'computeIsSyncPaused_(syncStatus)',
    },

    /** @private */
    hasPassphraseError_: {
      type: Boolean,
      value: false,
      computed: 'computeHasPassphraseError_(syncStatus)',
    },

    /** @private */
    hasOtherSyncError_: {
      type: Boolean,
      value: false,
      computed:
          'computeHasOtherError_(syncStatus, isSyncPaused_, hasPassphraseError_)',
    },

    /**
     * Time in ms, when the dialog was opened.
     * @private
     */
    dialogOpenedTime_: {
      type: Number,
      value: 0,
    },

    /** @private {Array<string>} */
    tabsNames_: {
      type: Array,
      value: () =>
          [loadTimeData.getString('basicPageTitle'),
           loadTimeData.getString('advancedPageTitle'),
],
    },

    /**
     * Installed apps that might be cleared if the user clears browsing data
     * for the selected time period.
     * @private {!Array<!InstalledApp>}
     */
    installedApps_: {
      type: Array,
      value: () => [],
    },

    /** @private */
    installedAppsFlagEnabled_: {
      type: Boolean,
      value: () => loadTimeData.getBoolean('installedAppsInCbd'),
    },
  },

  listeners: {'settings-boolean-control-change': 'updateClearButtonState_'},

  /** @private {ClearBrowsingDataBrowserProxy} */
  browserProxy_: null,

  /** @private {?SyncBrowserProxy} */
  syncBrowserProxy_: null,

  /** @override */
  ready() {
    this.syncBrowserProxy_ = SyncBrowserProxyImpl.getInstance();
    this.syncBrowserProxy_.getSyncStatus().then(
        this.handleSyncStatus_.bind(this));
    this.addWebUIListener(
        'sync-status-changed', this.handleSyncStatus_.bind(this));

    this.addWebUIListener(
        'update-sync-state', this.updateSyncState_.bind(this));
    this.addWebUIListener(
        'update-counter-text', this.updateCounterText_.bind(this));
  },

  /** @override */
  attached() {
    this.browserProxy_ = ClearBrowsingDataBrowserProxyImpl.getInstance();
    this.dialogOpenedTime_ = Date.now();
    this.browserProxy_.initialize().then(() => {
      this.$.clearBrowsingDataDialog.showModal();
    });
  },

  /**
   * Handler for when the sync state is pushed from the browser.
   * @param {?SyncStatus} syncStatus
   * @private
   */
  handleSyncStatus_(syncStatus) {
    this.syncStatus = syncStatus;
  },

  /**
   * Returns true if either clearing is in progress or no data type is selected.
   * @param {boolean} clearingInProgress
   * @param {boolean} clearButtonDisabled
   * @return {boolean}
   * @private
   */
  isClearButtonDisabled_(clearingInProgress, clearButtonDisabled) {
    return clearingInProgress || clearButtonDisabled;
  },

  /**
   * Disables the Clear Data button if no data type is selected.
   * @private
   */
  updateClearButtonState_() {
    // on-select-item-changed gets called with undefined during a tab change.
    // https://github.com/PolymerElements/iron-selector/issues/95
    const tab = this.$.tabs.selectedItem;
    if (!tab) {
      return;
    }
    this.clearButtonDisabled_ = this.getSelectedDataTypes_(tab).length === 0;
  },

  /**
   * Record visits to the CBD dialog.
   *
   * RouteObserverBehavior
   * @param {!Route} currentRoute
   * @protected
   */
  currentRouteChanged(currentRoute) {
    if (currentRoute === routes.CLEAR_BROWSER_DATA) {
      chrome.metricsPrivate.recordUserAction('ClearBrowsingData_DialogCreated');
      this.dialogOpenedTime_ = Date.now();
    }
  },

  /**
   * Updates the history description to show the relevant information
   * depending on sync and signin state.
   *
   * @param {boolean} signedIn Whether the user is signed in.
   * @param {boolean} syncing Whether the user is syncing history.
   * @param {boolean} shouldShowCookieException Whether the exception about not
   *    being signed out of your Google account should be shown.
   * @private
   */
  updateSyncState_(signedIn, syncing, shouldShowCookieException) {
    this.isSignedIn_ = signedIn;
    this.isSyncingHistory_ = syncing;
    this.shouldShowCookieException_ = shouldShowCookieException;
    this.$.clearBrowsingDataDialog.classList.add('fully-rendered');
  },

  /**
   * Choose a label for the history checkbox.
   * @param {boolean} isSignedIn
   * @param {boolean} isSyncingHistory
   * @param {string} historySummary
   * @param {string} historySummarySignedIn
   * @param {string} historySummarySynced
   * @return {string}
   * @private
   */
  browsingCheckboxLabel_(
      isSignedIn, isSyncingHistory, hasSyncError, historySummary,
      historySummarySignedIn, historySummarySynced) {
    if (isSyncingHistory && !hasSyncError) {
      return historySummarySynced;
    } else if (isSignedIn && !this.isSyncPaused_) {
      return historySummarySignedIn;
    }
    return historySummary;
  },

  /**
   * Choose a label for the cookie checkbox.
   * @param {boolean} shouldShowCookieException
   * @param {string} cookiesSummary
   * @param {string} cookiesSummarySignedIn
   * @return {string}
   * @private
   */
  cookiesCheckboxLabel_(
      shouldShowCookieException, cookiesSummary, cookiesSummarySignedIn) {
    if (shouldShowCookieException) {
      return cookiesSummarySignedIn;
    }
    return cookiesSummary;
  },

  /**
   * Updates the text of a browsing data counter corresponding to the given
   * preference.
   * @param {string} prefName Browsing data type deletion preference.
   * @param {string} text The text with which to update the counter
   * @private
   */
  updateCounterText_(prefName, text) {
    // Data type deletion preferences are named "browser.clear_data.<datatype>".
    // Strip the common prefix, i.e. use only "<datatype>".
    const matches = prefName.match(/^browser\.clear_data\.(\w+)$/);
    this.set('counters_.' + assert(matches[1]), text);
  },

  /**
   * Returns a list of selected data types.
   * @param {!HTMLElement} tab
   * @return {!Array<string>}
   * @private
   */
  getSelectedDataTypes_(tab) {
    const checkboxes = tab.querySelectorAll('settings-checkbox');
    const dataTypes = [];
    checkboxes.forEach((checkbox) => {
      if (checkbox.checked && !checkbox.hidden) {
        dataTypes.push(checkbox.pref.key);
      }
    });
    return dataTypes;
  },

  /**
   * Gets a list of top 5 installed apps that have been launched
   * within the time period selected. This is used to warn the user
   * that data for these apps will be cleared as well, and offers
   * them the option to exclude deletion of this data.
   * @return {!Promise}
   * @private
   */
  getInstalledApps_: async function() {
    const tab = this.$.tabs.selectedItem;
    const timePeriod = tab.querySelector('.time-range-select').pref.value;
    this.installedApps_ = await this.browserProxy_.getInstalledApps(timePeriod);
  },

  /** @private */
  shouldShowInstalledApps_() {
    if (!this.installedAppsFlagEnabled_) {
      return false;
    }
    const haveInstalledApps = this.installedApps_.length > 0;
    chrome.send('metricsHandler:recordBooleanHistogram', [
      'History.ClearBrowsingData.InstalledAppsDialogShown', haveInstalledApps
    ]);
    return haveInstalledApps;
  },

  /**
   * Logs interactions with the installed app dialog to UMA.
   * @private
   */
  recordInstalledAppsInteractions_: function() {
    if (this.installedApps_.length === 0) {
      return;
    }

    const uncheckedAppCount =
        this.installedApps_.filter(app => !app.isChecked).length;
    chrome.metricsPrivate.recordBoolean(
        'History.ClearBrowsingData.InstalledAppExcluded', !!uncheckedAppCount);
    chrome.metricsPrivate.recordCount(
        'History.ClearBrowsingData.InstalledDeselectedNum', uncheckedAppCount);
    chrome.metricsPrivate.recordPercentage(
        'History.ClearBrowsingData.InstalledDeselectedPercent',
        Math.round(100 * uncheckedAppCount / this.installedApps_.length));
  },

  /**
   * Clears browsing data and maybe shows a history notice.
   * @return {!Promise}
   * @private
   */
  clearBrowsingData_: async function() {
    this.clearingInProgress_ = true;
    const tab = this.$.tabs.selectedItem;
    const dataTypes = this.getSelectedDataTypes_(tab);
    const timePeriod = tab.querySelector('.time-range-select').pref.value;

    if (tab.id === 'basic-tab') {
      chrome.metricsPrivate.recordUserAction('ClearBrowsingData_BasicTab');
    } else {
      chrome.metricsPrivate.recordUserAction('ClearBrowsingData_AdvancedTab');
    }

    this.shadowRoot.querySelectorAll('settings-checkbox[no-set-pref]')
        .forEach(checkbox => checkbox.sendPrefChange());

    this.recordInstalledAppsInteractions_();
    const shouldShowNotice = await this.browserProxy_.clearBrowsingData(
        dataTypes, timePeriod, this.installedApps_);
    this.clearingInProgress_ = false;
    this.showHistoryDeletionDialog_ = shouldShowNotice;
    chrome.metricsPrivate.recordMediumTime(
        'History.ClearBrowsingData.TimeSpentInDialog',
        Date.now() - this.dialogOpenedTime_);
    if (!shouldShowNotice) {
      this.closeDialogs_();
    }
  },

  /**
   * Closes clear brtowsing data or installed app dialog if they are open.
   * @private
   */
  closeDialogs_() {
    if (this.$.clearBrowsingDataDialog.open) {
      this.$.clearBrowsingDataDialog.close();
    }
    if (this.$.installedAppsDialog.open) {
      this.$.installedAppsDialog.close();
    }
  },

  /** @private */
  onCancelTap_() {
    this.$.clearBrowsingDataDialog.cancel();
  },

  /**
   * Handles the closing of the notice about other forms of browsing history.
   * @private
   */
  onHistoryDeletionDialogClose_() {
    this.showHistoryDeletionDialog_ = false;
    this.closeDialogs_();
  },

  /**
   * Records an action when the user changes between the basic and advanced tab.
   * @param {!Event} event
   * @private
   */
  recordTabChange_(event) {
    if (event.detail.value === 0) {
      chrome.metricsPrivate.recordUserAction(
          'ClearBrowsingData_SwitchTo_BasicTab');
    } else {
      chrome.metricsPrivate.recordUserAction(
          'ClearBrowsingData_SwitchTo_AdvancedTab');
    }
  },

  /**
   * Called when the user clicks the link in the footer.
   * @param {!Event} e
   * @private
   */
  onSyncDescriptionLinkClicked_(e) {
    if (e.target.tagName === 'A') {
      e.preventDefault();
      if (!this.syncStatus.hasError) {
        chrome.metricsPrivate.recordUserAction('ClearBrowsingData_Sync_Pause');
        this.syncBrowserProxy_.pauseSync();
      } else if (this.isSyncPaused_) {
        chrome.metricsPrivate.recordUserAction('ClearBrowsingData_Sync_SignIn');
        this.syncBrowserProxy_.startSignIn();
      } else {
        if (this.hasPassphraseError_) {
          chrome.metricsPrivate.recordUserAction(
              'ClearBrowsingData_Sync_NavigateToPassphrase');
        } else {
          chrome.metricsPrivate.recordUserAction(
              'ClearBrowsingData_Sync_NavigateToError');
        }
        // In any other error case, navigate to the sync page.
        Router.getInstance().navigateTo(routes.SYNC);
      }
    }
  },

  /**
   * @return {boolean}
   * @private
   */
  computeIsSyncPaused_() {
    return !!this.syncStatus.hasError &&
        this.syncStatus.statusAction === StatusAction.REAUTHENTICATE;
  },

  /**
   * @return {boolean}
   * @private
   */
  computeHasPassphraseError_() {
    return !!this.syncStatus.hasError &&
        this.syncStatus.statusAction === StatusAction.ENTER_PASSPHRASE;
  },

  /**
   * @return {boolean}
   * @private
   */
  computeHasOtherError_() {
    return this.syncStatus !== undefined && !!this.syncStatus.hasError &&
        !this.isSyncPaused_ && !this.hasPassphraseError_;
  },

  /**
   * @return {boolean}
   * @private
   */
  shouldShowFooter_() {
    let showFooter = false;
    // <if expr="not chromeos">
    showFooter = !!this.syncStatus && !!this.syncStatus.signedIn;
    // </if>
    return showFooter;
  },

  /**
   * @return {!Promise}
   * @private
   */
  onClearBrowsingDataClick_: async function() {
    await this.getInstalledApps_();
    if (this.shouldShowInstalledApps_()) {
      replaceDialog(this.$.clearBrowsingDataDialog, this.$.installedAppsDialog);
    } else {
      await this.clearBrowsingData_();
    }
  },

  /** @private */
  hideInstalledApps_() {
    replaceDialog(this.$.installedAppsDialog, this.$.clearBrowsingDataDialog);
  },

  /**
   * Handles the tap confirm button in installed apps.
   * @private
   */
  onInstalledAppsConfirmClick_: async function() {
    await this.clearBrowsingData_();
  }
});
