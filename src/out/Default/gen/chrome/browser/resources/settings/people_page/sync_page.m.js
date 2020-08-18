// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html, flush} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {assert, assertNotReached} from '//resources/js/assert.m.js';
import '//resources/js/util.m.js';
import {focusWithoutInk} from '//resources/js/cr/ui/focus_without_ink.m.js';
import {WebUIListenerBehavior} from '//resources/js/web_ui_listener_behavior.m.js';
import '//resources/cr_elements/cr_button/cr_button.m.js';
import '//resources/cr_elements/cr_dialog/cr_dialog.m.js';
import '//resources/cr_elements/cr_input/cr_input.m.js';
import '//resources/cr_elements/cr_link_row/cr_link_row.m.js';
import '//resources/cr_elements/icons.m.js';
import '//resources/cr_elements/shared_style_css.m.js';
import '//resources/cr_elements/shared_vars_css.m.js';
import '//resources/cr_elements/cr_expand_button/cr_expand_button.m.js';
import '//resources/polymer/v3_0/iron-collapse/iron-collapse.js';
import '//resources/polymer/v3_0/iron-icon/iron-icon.js';
import '//resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import './sync_account_control.m.js';
import './sync_encryption_options.m.js';
import {SyncBrowserProxy, SyncBrowserProxyImpl, PageStatus, StatusAction, SyncStatus, SyncPrefs} from './sync_browser_proxy.m.js';
import {loadTimeData} from '../i18n_setup.js';
import '../privacy_page/personalization_options.m.js';
import {Route, Router, RouteObserverBehavior} from '../router.m.js';
import '../settings_shared_css.m.js';
import '../settings_vars_css.m.js';

// <if expr="not chromeos">
import '//resources/cr_elements/cr_toast/cr_toast.m.js';
// </if>


// TODO(rbpotter): Remove this typedef when this file is no longer needed by OS
// Settings.
/**
 * @typedef {{
 *   BASIC: !Route,
 *   PEOPLE: !Route,
 *   SYNC: !Route,
 *   SYNC_ADVANCED: !Route,
 * }}
 */
let SyncRoutes;

/** @return {!SyncRoutes} */
function getSyncRoutes() {
  const router = Router.getInstance();
  return /** @type {!SyncRoutes} */ (router.getRoutes());
}

/**
 * @fileoverview
 * 'settings-sync-page' is the settings page containing sync settings.
 */
Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared iron-flex">
      #sync-separator {
        border-bottom: var(--cr-separator-line);
      }

      #create-password-box {
        /* In order to line up with the encryption radio box text. */
        margin-inline-start: var(--cr-section-indent-width);
      }

      #create-password-box {
        margin-bottom: 1em;
      }

      #create-password-box .list-item {
        margin-bottom: var(--cr-form-field-bottom-spacing);
      }

      cr-input {
        --cr-input-width: var(--settings-input-max-width);
      }

      #existingPassphrase {
        border-bottom: var(--cr-separator-line);
        border-top: var(--cr-separator-line);
        /* This particular list frame is not indented. */
        padding-inline-start: var(--cr-section-padding);
      }

      #submitExistingPassphrase {
        /* The submit button for the existing passphrase is on the same line. */
        margin-inline-start: 16px;
      }

      #passphraseRecoverHint {
        align-items: center;
      }

      #other-sync-items {
        padding-bottom: 8px;
      }

      #other-sync-items > .list-item:not(.first) {
        border-top: var(--cr-separator-line);
      }

      .passphrase-reset-icon {
        margin-inline-end: 8px;
      }

      #disabled-by-admin-icon {
        text-align: center;
        width: 40px;
      }

      #toast {
        left: 0;
        z-index: 1;
      }

      :host-context([dir='rtl']) #toast {
        left: auto;
        right: 0;
      }

      cr-link-row {
        padding-inline-start: 0;
        padding-inline-end: 8px;
      }
    </style>
    <template is="dom-if" if="[[shouldShowSyncAccountControl_(
        syncStatus.syncSystemEnabled)]]">
      <settings-sync-account-control embedded-in-subpage
          sync-status="[[syncStatus]]" prefs="{{prefs}}"
          promo-label-with-account=
              "$i18n{peopleSignInSyncPagePromptSecondaryWithAccount}"
          promo-label-with-no-account=
              "$i18n{peopleSignInSyncPagePromptSecondaryWithNoAccount}"
          on-sync-setup-done="onSyncSetupDone_">
      </settings-sync-account-control>
    </template>
    <div class="cr-row first" hidden="[[!syncDisabledByAdmin_]]">
      <iron-icon id="disabled-by-admin-icon" icon="cr20:domain"></iron-icon>
      <div class="flex cr-padded-text">
        $i18n{syncDisabledByAdministrator}
      </div>
    </div>

    <template is="dom-if" if="[[shouldShowExistingPassphraseBelowAccount_(
        syncPrefs.passphraseRequired)]]"
        on-dom-change="focusPassphraseInput_">
      <div id="existingPassphrase" class="list-frame">
        <div id="existingPassphraseTitle" class="list-item">
            <div class="start cr-padded-text">
              <div>$i18n{existingPassphraseTitle}</div>
              <div class="secondary"
                  inner-h-t-m-l="[[syncPrefs.enterPassphraseBody]]">
              </div>
            </div>
        </div>
        <div id="existingPassphraseContainer" class="list-item">
          <cr-input id="existingPassphraseInput" type="password"
              value="{{existingPassphrase_}}"
              placeholder="$i18n{passphrasePlaceholder}"
              error-message="$i18n{incorrectPassphraseError}"
              on-keypress="onSubmitExistingPassphraseTap_">
            <cr-button id="submitExistingPassphrase" slot="suffix"
                on-click="onSubmitExistingPassphraseTap_"
                class="action-button" disabled="[[!existingPassphrase_]]">
              $i18n{submitPassphraseButton}
            </cr-button>
          </cr-input>
        </div>
        <div id="passphraseRecoverHint" class="list-item">
          <div class="cr-padded-text">$i18nRaw{passphraseRecover}</div>
        </div>
      </div>
    </template>

    <div id="sync-separator" hidden="[[!syncSectionDisabled_]]"></div>

    <div id="sync-section" hidden="[[syncSectionDisabled_]]">
      <div class="cr-row first">
        <h2 class="cr-title-text">$i18n{sync}</h2>
      </div>

      <div id="[[pages_.SPINNER]]" class="cr-row first cr-padded-text"
          hidden$="[[!isStatus_(pages_.SPINNER, pageStatus_)]]">
        $i18n{syncLoading}
      </div>
      <div id="[[pages_.CONFIGURE]]"
          hidden$="[[!isStatus_(pages_.CONFIGURE, pageStatus_)]]">
        <div id="other-sync-items" class="list-frame">
          <cr-link-row id="sync-advanced-row"
              label="$i18n{syncAdvancedPageTitle}"
              on-click="onSyncAdvancedClick_"></cr-link-row>

          <cr-link-row class="hr"
              label="$i18n{personalizeGoogleServicesTitle}"
              on-click="onActivityControlsClick_" external></cr-link-row>

          <cr-link-row id="syncDashboardLink" class="hr"
              label="$i18n{manageSyncedDataTitle}"
              on-click="onSyncDashboardLinkClick_"
              hidden="[[syncStatus.supervisedUser]]" external></cr-link-row>

          <template is="dom-if" if="[[!syncSetupFriendlySettings_]]">
            <div id="encryptionDescription"
                hidden="[[syncPrefs.passphraseRequired]]"
                class$="single-column cr-padded-text
                    [[getPassphraseHintLines_(syncPrefs.encryptAllData)]]
                    list-item">
              $i18n{encryptionOptionsTitle}
              <div class="secondary">
                $i18n{syncDataEncryptedText}
                <div hidden="[[!syncPrefs.encryptAllData]]">
                  <iron-icon icon="cr:info-outline"
                      class="passphrase-reset-icon">
                  </iron-icon>
                  $i18nRaw{passphraseResetHintEncryption}
                </div>
              </div>
            </div>

            <settings-sync-encryption-options
                sync-status="[[syncStatus]]" sync-prefs="{{syncPrefs}}"
                on-passphrase-changed="onPassphraseChanged_">
            </settings-sync-encryption-options>
          </template>

          <template is="dom-if" if="[[syncSetupFriendlySettings_]]">
            <cr-expand-button id="encryptionDescription"
                hidden="[[syncPrefs.passphraseRequired]]"
                expanded="{{encryptionExpanded_}}"
                class$="list-item
                    [[getPassphraseHintLines_(syncPrefs.encryptAllData)]]">
              $i18n{encryptionOptionsTitle}
              <div class="secondary">
                $i18n{syncDataEncryptedText}
                <div on-click="onResetSyncClick_"
                    hidden="[[!syncPrefs.encryptAllData]]">
                  <iron-icon icon="cr:info-outline"
                      class="passphrase-reset-icon">
                  </iron-icon>
                  $i18nRaw{passphraseResetHintEncryption}
                </div>
              </div>
            </cr-expand-button>

            <iron-collapse id="encryptionCollapse"
                opened="[[encryptionExpanded_]]">
              <settings-sync-encryption-options
                  sync-status="[[syncStatus]]" sync-prefs="{{syncPrefs}}"
                  on-passphrase-changed="onPassphraseChanged_">
              </settings-sync-encryption-options>
            </iron-collapse>
          </template>

        </div>
      </div>
    </div>

    <div class="cr-row first">
      <h2 class="cr-title-text">
        $i18n{nonPersonalizedServicesSectionLabel}
      </h2>
    </div>
    <settings-personalization-options class="list-frame" prefs="{{prefs}}"
        page-visibility="[[pageVisibility]]" sync-status="[[syncStatus]]">
    </settings-personalization-options>

<if expr="not chromeos">
    <template is="dom-if" if="[[showSetupCancelDialog_]]" restamp>
      <cr-dialog id="setupCancelDialog" on-close="onSetupCancelDialogClose_"
          ignore-popstate>
        <div slot="title">$i18n{syncSetupCancelDialogTitle}</div>
        <div slot="body">$i18n{syncSetupCancelDialogBody}</div>
        <div slot="button-container">
          <cr-button class="cancel-button"
              on-click="onSetupCancelDialogBack_">
            $i18n{back}
          </cr-button>
          <cr-button class="action-button"
              on-click="onSetupCancelDialogConfirm_">
            $i18n{cancelSync}
          </cr-button>
        </div>
      </cr-dialog>
    </template>
</if>
<!--_html_template_end_-->`,
  is: 'settings-sync-page',

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

    /** @private {!Map<string, (string|Function)>} */
    focusConfig: {
      type: Object,
      observer: 'onFocusConfigChange_',
    },

    /** @private */
    pages_: {
      type: Object,
      value: PageStatus,
      readOnly: true,
    },

    /**
     * The current page status. Defaults to |CONFIGURE| such that the searching
     * algorithm can search useful content when the page is not visible to the
     * user.
     * @private {?PageStatus}
     */
    pageStatus_: {
      type: String,
      value: PageStatus.CONFIGURE,
    },

    /**
     * Dictionary defining page visibility.
     * TODO(dpapad): Restore the type information here (PrivacyPageVisibility),
     * when this file is no longer shared with chrome://os-settings.
     */
    pageVisibility: Object,

    /**
     * The current sync preferences, supplied by SyncBrowserProxy.
     * @type {SyncPrefs|undefined}
     */
    syncPrefs: {
      type: Object,
    },

    /** @type {SyncStatus} */
    syncStatus: {
      type: Object,
    },

    /** @private */
    encryptionExpanded_: {
      type: Boolean,
      value: false,
      computed: 'computeEncryptionExpanded_(syncPrefs.encryptAllData)',
    },

    /**
     * The existing passphrase input field value.
     * @private
     */
    existingPassphrase_: {
      type: String,
      value: '',
    },

    /** @private */
    signedIn_: {
      type: Boolean,
      value: true,
      computed: 'computeSignedIn_(syncStatus.signedIn)',
    },

    /** @private */
    syncDisabledByAdmin_: {
      type: Boolean,
      value: false,
      computed: 'computeSyncDisabledByAdmin_(syncStatus.managed)',
    },

    /** @private */
    syncSectionDisabled_: {
      type: Boolean,
      value: false,
      computed: 'computeSyncSectionDisabled_(' +
          'syncStatus.signedIn, syncStatus.disabled, ' +
          'syncStatus.hasError, syncStatus.statusAction, ' +
          'syncPrefs.trustedVaultKeysRequired)',
    },

    /** @private */
    showSetupCancelDialog_: {
      type: Boolean,
      value: false,
    },

    /**
     * If sync page friendly settings is enabled.
     * @private
     */
    syncSetupFriendlySettings_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('syncSetupFriendlySettings');
      }
    },
  },

  /** @private {?SyncBrowserProxy} */
  browserProxy_: null,

  /**
   * The beforeunload callback is used to show the 'Leave site' dialog. This
   * makes sure that the user has the chance to go back and confirm the sync
   * opt-in before leaving.
   *
   * This property is non-null if the user is currently navigated on the sync
   * settings route.
   *
   * @private {?Function}
   */
  beforeunloadCallback_: null,

  /**
   * The unload callback is used to cancel the sync setup when the user hits
   * the browser back button after arriving on the page.
   * Note: Cases like closing the tab or reloading don't need to be handled,
   * because they are already caught in |PeopleHandler::~PeopleHandler|
   * from the C++ code.
   *
   * @private {?Function}
   */
  unloadCallback_: null,

  /**
   * Whether the initial layout for collapsible sections has been computed. It
   * is computed only once, the first time the sync status is updated.
   * @private {boolean}
   */
  collapsibleSectionsInitialized_: false,

  /**
   * Whether the user decided to abort sync.
   * @private {boolean}
   */
  didAbort_: true,

  /**
   * Whether the user confirmed the cancellation of sync.
   * @private {boolean}
   */
  setupCancelConfirmed_: false,

  /** @override */
  created() {
    this.browserProxy_ = SyncBrowserProxyImpl.getInstance();
  },

  /** @override */
  attached() {
    this.addWebUIListener(
        'page-status-changed', this.handlePageStatusChanged_.bind(this));
    this.addWebUIListener(
        'sync-prefs-changed', this.handleSyncPrefsChanged_.bind(this));

    const router = Router.getInstance();
    if (router.getCurrentRoute() === getSyncRoutes().SYNC) {
      this.onNavigateToPage_();
    }
  },

  /** @override */
  detached() {
    const router = Router.getInstance();
    if (getSyncRoutes().SYNC.contains(router.getCurrentRoute())) {
      this.onNavigateAwayFromPage_();
    }

    if (this.beforeunloadCallback_) {
      window.removeEventListener('beforeunload', this.beforeunloadCallback_);
      this.beforeunloadCallback_ = null;
    }
    if (this.unloadCallback_) {
      window.removeEventListener('unload', this.unloadCallback_);
      this.unloadCallback_ = null;
    }
  },

  /**
   * @return {boolean}
   * @private
   */
  computeSignedIn_() {
    return !!this.syncStatus.signedIn;
  },

  /**
   * @return {boolean}
   * @private
   */
  computeSyncSectionDisabled_() {
    return this.syncStatus !== undefined &&
        (!this.syncStatus.signedIn || !!this.syncStatus.disabled ||
         (!!this.syncStatus.hasError &&
          this.syncStatus.statusAction !==
              StatusAction.ENTER_PASSPHRASE &&
          this.syncStatus.statusAction !==
              StatusAction.RETRIEVE_TRUSTED_VAULT_KEYS));
  },

  /**
   * @return {boolean}
   * @private
   */
  computeSyncDisabledByAdmin_() {
    return this.syncStatus !== undefined && !!this.syncStatus.managed;
  },

  /** @private */
  onFocusConfigChange_() {
    const router = Router.getInstance();
    this.focusConfig.set(getSyncRoutes().SYNC_ADVANCED.path, () => {
      focusWithoutInk(assert(this.$$('#sync-advanced-row')));
    });
  },

  /** @private */
  onSetupCancelDialogBack_() {
    /** @type {!CrDialogElement} */ (this.$$('#setupCancelDialog')).cancel();
    chrome.metricsPrivate.recordUserAction(
        'Signin_Signin_CancelCancelAdvancedSyncSettings');
  },

  /** @private */
  onSetupCancelDialogConfirm_() {
    this.setupCancelConfirmed_ = true;
    /** @type {!CrDialogElement} */ (this.$$('#setupCancelDialog')).close();
    const router = Router.getInstance();
    router.navigateTo(getSyncRoutes().BASIC);
    chrome.metricsPrivate.recordUserAction(
        'Signin_Signin_ConfirmCancelAdvancedSyncSettings');
  },

  /** @private */
  onSetupCancelDialogClose_() {
    this.showSetupCancelDialog_ = false;
  },

  /** @protected */
  currentRouteChanged() {
    const router = Router.getInstance();
    if (router.getCurrentRoute() === getSyncRoutes().SYNC) {
      this.onNavigateToPage_();
      return;
    }

    if (getSyncRoutes().SYNC.contains(router.getCurrentRoute())) {
      return;
    }

    const searchParams =
        Router.getInstance().getQueryParameters().get('search');
    if (searchParams) {
      // User navigated away via searching. Cancel sync without showing
      // confirmation dialog.
      this.onNavigateAwayFromPage_();
      return;
    }

    const userActionCancelsSetup = this.syncStatus &&
        this.syncStatus.firstSetupInProgress && this.didAbort_;
    if (userActionCancelsSetup && !this.setupCancelConfirmed_) {
      chrome.metricsPrivate.recordUserAction(
          'Signin_Signin_BackOnAdvancedSyncSettings');
      // Show the 'Cancel sync?' dialog.
      // Yield so that other |currentRouteChanged| observers are called,
      // before triggering another navigation (and another round of observers
      // firing). Triggering navigation from within an observer leads to some
      // undefined behavior and runtime errors.
      requestAnimationFrame(() => {
        router.navigateTo(getSyncRoutes().SYNC);
        this.showSetupCancelDialog_ = true;
        // Flush to make sure that the setup cancel dialog is attached.
        flush();
        this.$$('#setupCancelDialog').showModal();
      });
      return;
    }

    // Reset variable.
    this.setupCancelConfirmed_ = false;

    this.onNavigateAwayFromPage_();
  },

  /**
   * @param {!PageStatus} expectedPageStatus
   * @return {boolean}
   * @private
   */
  isStatus_(expectedPageStatus) {
    return expectedPageStatus === this.pageStatus_;
  },

  /** @private */
  onNavigateToPage_() {
    const router = Router.getInstance();
    assert(router.getCurrentRoute() === getSyncRoutes().SYNC);
    if (this.beforeunloadCallback_) {
      return;
    }

    this.collapsibleSectionsInitialized_ = false;

    // Display loading page until the settings have been retrieved.
    this.pageStatus_ = PageStatus.SPINNER;

    this.browserProxy_.didNavigateToSyncPage();

    this.beforeunloadCallback_ = event => {
      // When the user tries to leave the sync setup, show the 'Leave site'
      // dialog.
      if (this.syncStatus && this.syncStatus.firstSetupInProgress) {
        event.preventDefault();
        event.returnValue = '';

        chrome.metricsPrivate.recordUserAction(
            'Signin_Signin_AbortAdvancedSyncSettings');
      }
    };
    window.addEventListener('beforeunload', this.beforeunloadCallback_);

    this.unloadCallback_ = this.onNavigateAwayFromPage_.bind(this);
    window.addEventListener('unload', this.unloadCallback_);
  },

  /** @private */
  onNavigateAwayFromPage_() {
    if (!this.beforeunloadCallback_) {
      return;
    }

    // Reset the status to CONFIGURE such that the searching algorithm can
    // search useful content when the page is not visible to the user.
    this.pageStatus_ = PageStatus.CONFIGURE;

    this.browserProxy_.didNavigateAwayFromSyncPage(this.didAbort_);

    window.removeEventListener('beforeunload', this.beforeunloadCallback_);
    this.beforeunloadCallback_ = null;

    if (this.unloadCallback_) {
      window.removeEventListener('unload', this.unloadCallback_);
      this.unloadCallback_ = null;
    }
  },

  /**
   * Handler for when the sync preferences are updated.
   * @private
   */
  handleSyncPrefsChanged_(syncPrefs) {
    this.syncPrefs = syncPrefs;
    this.pageStatus_ = PageStatus.CONFIGURE;

    // Hide the new passphrase box if (a) full data encryption is enabled,
    // (b) encrypting all data is not allowed (so far, only applies to
    // supervised accounts), or (c) the user is a supervised account.
    if (this.syncPrefs.encryptAllData ||
        !this.syncPrefs.encryptAllDataAllowed ||
        (this.syncStatus && this.syncStatus.supervisedUser)) {
      this.creatingNewPassphrase_ = false;
    }
  },

  /** @private */
  onActivityControlsClick_() {
    chrome.metricsPrivate.recordUserAction('Sync_OpenActivityControlsPage');
    this.browserProxy_.openActivityControlsUrl();
    window.open(loadTimeData.getString('activityControlsUrl'));
  },

  /** @private */
  onSyncDashboardLinkClick_() {
    window.open(loadTimeData.getString('syncDashboardUrl'));
  },

  /**
   * Whether the encryption dropdown should be expanded by default.
   * @return {boolean}
   * @private
   */
  computeEncryptionExpanded_() {
    return !!this.syncPrefs && this.syncPrefs.encryptAllData;
  },

  /**
   * @param {!Event} event
   * @private
   */
  onResetSyncClick_(event) {
    if (event.target.tagName === 'A') {
      // Stop the propagation of events as the |cr-expand-button|
      // prevents the default which will prevent the navigation to the link.
      event.stopPropagation();
    }
  },

  /**
   * Sends the user-entered existing password to re-enable sync.
   * @private
   * @param {!Event} e
   */
  onSubmitExistingPassphraseTap_(e) {
    if (e.type === 'keypress' && e.key !== 'Enter') {
      return;
    }

    this.syncPrefs.setNewPassphrase = false;

    this.syncPrefs.passphrase = this.existingPassphrase_;
    this.existingPassphrase_ = '';

    this.browserProxy_.setSyncEncryption(this.syncPrefs)
        .then(this.handlePageStatusChanged_.bind(this));
  },

  /**
   * @private
   * @param {!CustomEvent<!PageStatus>} e
   */
  onPassphraseChanged_(e) {
    this.handlePageStatusChanged_(
        /** @type {!PageStatus} */ (e.detail));
  },

  /**
   * Called when the page status updates.
   * @param {!PageStatus} pageStatus
   * @private
   */
  handlePageStatusChanged_(pageStatus) {
    const router = Router.getInstance();
    switch (pageStatus) {
      case PageStatus.SPINNER:
      case PageStatus.CONFIGURE:
        this.pageStatus_ = pageStatus;
        return;
      case PageStatus.DONE:
        if (router.getCurrentRoute() === getSyncRoutes().SYNC) {
          router.navigateTo(getSyncRoutes().PEOPLE);
        }
        return;
      case PageStatus.PASSPHRASE_FAILED:
        if (this.pageStatus_ === this.pages_.CONFIGURE && this.syncPrefs &&
            this.syncPrefs.passphraseRequired) {
          const passphraseInput = /** @type {!CrInputElement} */ (
              this.$$('#existingPassphraseInput'));
          passphraseInput.invalid = true;
          passphraseInput.focusInput();
        }
        return;
    }

    assertNotReached();
  },

  /**
   * @param {!Event} event
   * @private
   */
  onLearnMoreTap_(event) {
    if (event.target.tagName === 'A') {
      // Stop the propagation of events, so that clicking on links inside
      // checkboxes or radio buttons won't change the value.
      event.stopPropagation();
    }
  },

  /**
   * When there is a sync passphrase, some items have an additional line for the
   * passphrase reset hint, making them three lines rather than two.
   * @return {string}
   * @private
   */
  getPassphraseHintLines_() {
    return this.syncPrefs.encryptAllData ? 'three-line' : 'two-line';
  },

  /**
   * @return {boolean}
   * @private
   */
  shouldShowSyncAccountControl_() {
    // <if expr="chromeos">
    if (!loadTimeData.getBoolean('useBrowserSyncConsent')) {
      return false;
    }
    // </if>
    return this.syncStatus !== undefined &&
        !!this.syncStatus.syncSystemEnabled &&
        loadTimeData.getBoolean('signinAllowed');
  },

  /**
   * @return {boolean}
   * @private
   */
  shouldShowExistingPassphraseBelowAccount_() {
    return this.syncPrefs !== undefined && !!this.syncPrefs.passphraseRequired;
  },

  /** @private */
  onSyncAdvancedClick_() {
    const router = Router.getInstance();
    router.navigateTo(getSyncRoutes().SYNC_ADVANCED);
  },

  /**
   * @param {!CustomEvent<boolean>} e The event passed from
   *     settings-sync-account-control.
   * @private
   */
  onSyncSetupDone_(e) {
    if (e.detail) {
      this.didAbort_ = false;
      chrome.metricsPrivate.recordUserAction(
          'Signin_Signin_ConfirmAdvancedSyncSettings');
    } else {
      this.setupCancelConfirmed_ = true;
      chrome.metricsPrivate.recordUserAction(
          'Signin_Signin_CancelAdvancedSyncSettings');
    }
    const router = Router.getInstance();
    router.navigateTo(getSyncRoutes().BASIC);
  },

  /**
   * Focuses the passphrase input element if it is available and the page is
   * visible.
   * @private
   */
  focusPassphraseInput_() {
    const passphraseInput =
        /** @type {!CrInputElement} */ (this.$$('#existingPassphraseInput'));
    const router = Router.getInstance();
    if (passphraseInput && router.getCurrentRoute() === getSyncRoutes().SYNC) {
      passphraseInput.focus();
    }
  },
});
