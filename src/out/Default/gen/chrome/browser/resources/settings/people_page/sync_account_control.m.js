// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
/**
 * @fileoverview
 * 'settings-sync-account-section' is the settings page containing sign-in
 * settings.
 */
import {Polymer, html} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '//resources/cr_elements/cr_action_menu/cr_action_menu.m.js';
import '//resources/cr_elements/cr_button/cr_button.m.js';
import '//resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import '//resources/cr_elements/icons.m.js';
import '//resources/cr_elements/shared_style_css.m.js';
import '//resources/cr_elements/shared_vars_css.m.js';
import {assert} from '//resources/js/assert.m.js';
import {WebUIListenerBehavior} from '//resources/js/web_ui_listener_behavior.m.js';
import '//resources/polymer/v3_0/iron-icon/iron-icon.js';
import './profile_info_browser_proxy.m.js';
import {SyncBrowserProxy, SyncBrowserProxyImpl, SyncStatus, StatusAction, StoredAccount} from './sync_browser_proxy.m.js';
import {loadTimeData} from '../i18n_setup.js';
import '../icons.m.js';
import '../prefs/prefs.m.js';
import {PrefsBehavior} from '../prefs/prefs_behavior.m.js';
import {Route, Router} from '../router.m.js';
import '../settings_shared_css.m.js';

  /** @const {number} */
  export const MAX_SIGNIN_PROMO_IMPRESSION = 10;

  Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared">
      :host {
        --shown-avatar-size: 40px;
        --sync-icon-border-size: 2px;
        --sync-icon-size: 16px;
      }

      .account-icon {
        border-radius: 20px;
        flex-shrink: 0;
        height: var(--shown-avatar-size);
        width: var(--shown-avatar-size);
      }

      .account-icon.small {
        height: 20px;
        width: 20px;
      }

      #menu .dropdown-item {
        padding: 12px;
      }

      #menu .dropdown-item span {
        margin-inline-start: 8px;
      }

      .flex {
        display: flex;
        flex: 1;
        flex-direction: column;
      }

      #avatar-container {
        height: var(--shown-avatar-size);
        position: relative;
      }

      #sync-icon-container {
        align-items: center;
        background: var(--google-green-700);
        border: var(--sync-icon-border-size) solid white;
        border-radius: 50%;
        display: flex;
        height: var(--sync-icon-size);
        position: absolute;
        right: -6px;
        top: calc(var(--shown-avatar-size) - var(--sync-icon-size) -
            var(--sync-icon-border-size));
        width: var(--sync-icon-size);
      }

      :host-context([dir='rtl']) #sync-icon-container {
        left: -6px;
        right: initial;
      }

      @media (prefers-color-scheme: dark) {
        #sync-icon-container {
          background: var(--google-green-refresh-300);
          border-color: var(--google-grey-900);
        }
      }

      #sync-icon-container.sync-problem {
        background: var(--settings-error-color);
      }

      #sync-icon-container.sync-paused {
        background: var(--google-blue-500);
      }

      @media (prefers-color-scheme: dark) {
        #sync-icon-container.sync-paused {
          background: var(--google-blue-refresh-300);
        }
      }

      #sync-icon-container.sync-disabled {
        background: var(--google-grey-400);
      }

      @media (prefers-color-scheme: dark) {
        #sync-icon-container.sync-disabled {
          background: var(--google-grey-refresh-500);
        }
      }

      #sync-icon-container iron-icon {
        fill: white;  /* Same in light and dark modes. */
        height: 12px;
        margin: auto;
        width: 12px;
      }

      #sign-in {
        min-width: 100px;
      }

      #banner {
        background: url(chrome://settings/images/sync_banner.svg) no-repeat;
        background-size: 100% auto;
        display: none;
        padding-top: calc(120 / 680 * 100%); /* Keep background ratio. */
      }

      @media (prefers-color-scheme: dark) {
        #banner {
          background-image: url(chrome://settings/images/sync_banner_dark.svg);
        }
      }

      :host([showing-promo]) #banner {
        display: block;
      }
    </style>
    <!-- TODO(jamescook): Show the promo on Chrome OS if the user is signed-in
         but has sync disabled. -->
    <div id="banner" hidden="[[syncStatus.signedIn]]" part="banner"></div>
    <div class="cr-row first"
        id="promo-header" hidden="[[syncStatus.signedIn]]">
      <div class="flex cr-padded-text">
        <div id="promo-title" part="title">
          [[getLabel_(promoLabelWithAccount,
              promoLabelWithNoAccount, shownAccount_)]]
        </div>
        <div class="secondary">[[subLabel_]]</div>
      </div>
      <cr-button class="action-button cr-button-gap" on-click="onSigninTap_"
          id="sign-in"
          disabled="[[shouldDisableSyncButton_(showSetupButtons_,
                  syncStatus.firstSetupInProgress,
                  prefs.signin.allowed_on_next_startup.value)]]"
          hidden="[[shouldShowAvatarRow_]]">
        $i18n{peopleSignIn}
      </cr-button>
    </div>
    <template is="dom-if" if="[[shouldShowAvatarRow_]]">
      <div class="cr-row first two-line" id="avatar-row">
        <div id="avatar-container">
          <img class="account-icon" alt=""
              src="[[getAccountImageSrc_(shownAccount_.avatarImage)]]">
          <div id="sync-icon-container" hidden="[[!syncStatus.signedIn]]"
              class$="[[getSyncIconStyle_(
                  syncStatus.hasError, syncStatus.statusAction,
                  syncStatus.disabled)]]">
            <iron-icon icon$="[[getSyncIcon_(
                syncStatus.hasError, syncStatus.statusAction,
                syncStatus.disabled)]]"></iron-icon>
          </div>
        </div>
        <div class="cr-row-gap cr-padded-text flex no-min-width" id="user-info">
          <div class="text-elide">
            [[getAvatarRowTitle_(shownAccount_.fullName,
                '$i18nPolymer{syncNotWorking}',
                '$i18nPolymer{syncPasswordsNotWorking}',
                '$i18nPolymer{syncPaused}',
                '$i18nPolymer{syncDisabled}', syncStatus.hasError,
                syncStatus.statusAction, syncStatus.disabled)]]
          </div>
          <div class="secondary text-elide">
            [[getAccountLabel_(
                '$i18nPolymer{syncingTo}', shownAccount_.email,
                syncStatus.hasError, syncStatus.signedIn,
                syncStatus.disabled, syncStatus.firstSetupInProgress)]]
          </div>
        </div>
<!-- Chrome OS does not allow switching users for sync. -->
<if expr="not chromeos">
        <cr-icon-button class="icon-arrow-dropdown cr-button-gap"
            hidden="[[syncStatus.signedIn]]" on-click="onMenuButtonTap_"
            id="dropdown-arrow" aria-label="$i18n{useAnotherAccount}">
        </cr-icon-button>
        <div class="separator" hidden="[[syncStatus.signedIn]]"></div>
</if>
        <cr-button id="sync-button" class="action-button cr-button-gap"
            hidden="[[syncStatus.signedIn]]" on-click="onSyncButtonTap_"
            disabled="[[shouldDisableSyncButton_(showSetupButtons_,
                    syncStatus.firstSetupInProgress,
                    prefs.signin.allowed_on_next_startup.value)]]">
          $i18n{peopleSignIn}
        </cr-button>
        <cr-button id="turn-off"
            class="cr-button-gap"
            hidden="[[!shouldShowTurnOffButton_(syncStatus.signedIn,
                syncStatus.domain, showSetupButtons_)]]"
            on-click="onTurnOffButtonTap_"
            disabled="[[syncStatus.firstSetupInProgress]]">
          $i18n{turnOffSync}
        </cr-button>
        <cr-button id="sync-error-button" class="action-button cr-button-gap"
            hidden="[[!shouldShowErrorActionButton_(syncStatus,
                showSetupButtons_)]]"
            on-click="onErrorButtonTap_"
            disabled="[[syncStatus.firstSetupInProgress]]">
          [[syncStatus.statusActionText]]
        </cr-button>
        <div id="setup-buttons" hidden="[[!showSetupButtons_]]"
            class="cr-button-gap">
          <cr-button on-click="onSetupCancel_">$i18n{cancel}</cr-button>
          <cr-button class="action-button cr-button-gap"
              on-click="onSetupConfirm_">
            $i18n{confirm}
          </cr-button>
        </div>
      </div>
<!-- Chrome OS does not allow switching users for sync. -->
<if expr="not chromeos">
      <template is="dom-if" if="[[!syncStatus.signedIn]]" restamp>
        <cr-action-menu id="menu" auto-reposition
            role-description="$i18n{menu}">
          <template is="dom-repeat" items="[[storedAccounts_]]">
            <button class="dropdown-item" on-click="onAccountTap_">
              <img class="account-icon small" alt=""
                  src="[[getAccountImageSrc_(item.avatarImage)]]">
              <span>[[item.email]]</span>
            </button>
          </template>
          <button class="dropdown-item" on-click="onSigninTap_"
              disabled="[[syncStatus.firstSetupInProgress]]" id="sign-in-item">
            <img class="account-icon small" alt=""
                src="chrome://theme/IDR_PROFILE_AVATAR_PLACEHOLDER_LARGE">
            <span>$i18n{useAnotherAccount}</span>
          </button>
          <button class="dropdown-item" on-click="onSignoutTap_"
              disabled="[[syncStatus.firstSetupInProgress]]" id="sign-out-item">
            <iron-icon icon="settings:exit-to-app"></iron-icon>
            <span>$i18n{peopleSignOut}</span>
          </button>
        </cr-action-menu>
      </template>
</if>
    </template>
<!--_html_template_end_-->`,
    is: 'settings-sync-account-control',

    behaviors: [
      WebUIListenerBehavior,
      PrefsBehavior,
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
       * The current sync status, supplied by parent element.
       * @type {!SyncStatus}
       */
      syncStatus: Object,

      // String to be used as a title when the promo has an account.
      promoLabelWithAccount: String,

      // String to be used as title of the promo has no account.
      promoLabelWithNoAccount: String,

      // String to be used as a subtitle when the promo has an account.
      promoSecondaryLabelWithAccount: String,

      // String to be used as subtitle of the promo has no account.
      promoSecondaryLabelWithNoAccount: String,

      /**
       * Proxy variable for syncStatus.signedIn to shield observer from being
       * triggered multiple times whenever syncStatus changes.
       * @private {boolean}
       */
      signedIn_: {
        type: Boolean,
        computed: 'computeSignedIn_(syncStatus.signedIn)',
        observer: 'onSignedInChanged_',
      },

      /** @private {!Array<!StoredAccount>} */
      storedAccounts_: Object,

      /** @private {?StoredAccount} */
      shownAccount_: Object,

      showingPromo: {
        type: Boolean,
        value: false,
        reflectToAttribute: true,
      },

      // This property should be set by the parent only and should not change
      // after the element is created.
      embeddedInSubpage: {
        type: Boolean,
        reflectToAttribute: true,
      },

      // This property should be set by the parent only and should not change
      // after the element is created.
      hideButtons: {
        type: Boolean,
        value: false,
        reflectToAttribute: true,
      },

      /** @private {boolean} */
      shouldShowAvatarRow_: {
        type: Boolean,
        value: false,
        computed: 'computeShouldShowAvatarRow_(storedAccounts_, syncStatus,' +
            'storedAccounts_.length, syncStatus.signedIn)',
        observer: 'onShouldShowAvatarRowChange_',
      },

      /** @private */
      subLabel_: {
        type: String,
        computed: 'computeSubLabel_(promoSecondaryLabelWithAccount,' +
            'promoSecondaryLabelWithNoAccount, shownAccount_)',
      },

      /** @private */
      showSetupButtons_: {
        type: Boolean,
        computed: 'computeShowSetupButtons_(' +
            'hideButtons, syncStatus.firstSetupInProgress)',
      },
    },

    observers: [
      'onShownAccountShouldChange_(storedAccounts_, syncStatus)',
    ],

    /** @private {?SyncBrowserProxy} */
    syncBrowserProxy_: null,

    created() {
      this.syncBrowserProxy_ = SyncBrowserProxyImpl.getInstance();
    },

    /** @override */
    attached() {
      this.syncBrowserProxy_.getStoredAccounts().then(
          this.handleStoredAccounts_.bind(this));
      this.addWebUIListener(
          'stored-accounts-updated', this.handleStoredAccounts_.bind(this));
    },

    /**
     * Records the following user actions:
     * - Signin_Impression_FromSettings and
     * - Signin_ImpressionWithAccount_FromSettings
     * - Signin_ImpressionWithNoAccount_FromSettings
     * @private
     */
    recordImpressionUserActions_() {
      assert(!this.syncStatus.signedIn);
      assert(this.shownAccount_ !== undefined);

      chrome.metricsPrivate.recordUserAction('Signin_Impression_FromSettings');
      if (this.shownAccount_) {
        chrome.metricsPrivate.recordUserAction(
            'Signin_ImpressionWithAccount_FromSettings');
      } else {
        chrome.metricsPrivate.recordUserAction(
            'Signin_ImpressionWithNoAccount_FromSettings');
      }
    },

    /**
     * @return {boolean}
     * @private
     */
    computeSignedIn_() {
      return !!this.syncStatus && !!this.syncStatus.signedIn;
    },

    /** @private */
    onSignedInChanged_() {
      if (this.embeddedInSubpage) {
        this.showingPromo = true;
        return;
      }

      if (!this.showingPromo && !this.syncStatus.signedIn &&
          this.syncBrowserProxy_.getPromoImpressionCount() <
              MAX_SIGNIN_PROMO_IMPRESSION) {
        this.showingPromo = true;
        this.syncBrowserProxy_.incrementPromoImpressionCount();
      } else {
        // Turn off the promo if the user is signed in.
        this.showingPromo = false;
      }
      if (!this.syncStatus.signedIn && this.shownAccount_ !== undefined) {
        this.recordImpressionUserActions_();
      }
    },

    /**
     * @param {string} labelWithAccount
     * @param {string} labelWithNoAccount
     * @return {string}
     * @private
     */
    getLabel_(labelWithAccount, labelWithNoAccount) {
      return this.shownAccount_ ? labelWithAccount : labelWithNoAccount;
    },

    /**
     * @return {string}
     * @private
     */
    computeSubLabel_() {
      return this.getLabel_(
          this.promoSecondaryLabelWithAccount,
          this.promoSecondaryLabelWithNoAccount);
    },

    /**
     * @param {string} label
     * @param {string} name
     * @return {string}
     * @private
     */
    getSubstituteLabel_(label, name) {
      return loadTimeData.substituteString(label, name);
    },

    /**
     * @param {string} label
     * @param {string} account
     * @return {string}
     * @private
     */
    getAccountLabel_(label, account) {
      if (this.syncStatus.firstSetupInProgress) {
        return this.syncStatus.statusText || account;
      }
      return this.syncStatus.signedIn && !this.syncStatus.hasError &&
              !this.syncStatus.disabled ?
          loadTimeData.substituteString(label, account) :
          account;
    },

    /**
     * @param {?string} image
     * @return {string}
     * @private
     */
    getAccountImageSrc_(image) {
      // image can be undefined if the account has not set an avatar photo.
      return image || 'chrome://theme/IDR_PROFILE_AVATAR_PLACEHOLDER_LARGE';
    },

    /**
     * Returns the class of the sync icon.
     * @return {string}
     * @private
     */
    getSyncIconStyle_() {
      if (this.syncStatus.disabled) {
        return 'sync-disabled';
      }
      if (!this.syncStatus.hasError) {
        return 'sync';
      }
      // Specific error cases below.
      if (this.syncStatus.hasUnrecoverableError) {
        return 'sync-problem';
      }
      if (this.syncStatus.statusAction ===
          StatusAction.REAUTHENTICATE) {
        return 'sync-paused';
      }
      return 'sync-problem';
    },

    /**
     * Returned value must match one of iron-icon's settings:(*) icon name.
     * @return {string}
     * @private
     */
    getSyncIcon_() {
      switch (this.getSyncIconStyle_()) {
        case 'sync-problem':
          return 'settings:sync-problem';
        case 'sync-paused':
          return 'settings:sync-disabled';
        default:
          return 'cr:sync';
      }
    },

    /**
     * @param {string} accountName
     * @param {string} syncErrorLabel
     * @param {string} syncPasswordsOnlyErrorLabel
     * @param {string} authErrorLabel
     * @param {string} disabledLabel
     * @return {string}
     * @private
     */
    getAvatarRowTitle_(
        accountName, syncErrorLabel, syncPasswordsOnlyErrorLabel,
        authErrorLabel, disabledLabel) {
      if (this.syncStatus.disabled) {
        return disabledLabel;
      }
      if (!this.syncStatus.hasError) {
        return accountName;
      }
      // Specific error cases below.
      if (this.syncStatus.hasUnrecoverableError) {
        return syncErrorLabel;
      }
      if (this.syncStatus.statusAction ===
          StatusAction.REAUTHENTICATE) {
        return authErrorLabel;
      }
      if (this.syncStatus.hasPasswordsOnlyError) {
        return syncPasswordsOnlyErrorLabel;
      }
      return syncErrorLabel;
    },

    /**
     * Determines if the sync button should be disabled in response to
     * either a first setup flow or chrome sign-in being disabled.
     * @return {boolean}
     * @private
     */
    shouldDisableSyncButton_() {
      if (this.hideButtons || this.prefs === undefined) {
        return this.computeShowSetupButtons_();
      }
      return !!this.syncStatus.firstSetupInProgress ||
          !this.getPref('signin.allowed_on_next_startup').value;
    },

    /**
     * @return {boolean}
     * @private
     */
    shouldShowTurnOffButton_() {
      // <if expr="chromeos">
      if (this.syncStatus.domain) {
        // Chrome OS cannot delete the user's profile like other platforms, so
        // hide the turn off sync button for enterprise users who are not
        // allowed to sign out.
        return false;
      }
      // </if>
      return !this.hideButtons && !this.showSetupButtons_ &&
          !!this.syncStatus.signedIn;
    },

    /**
     * @return {boolean}
     * @private
     */
    shouldShowErrorActionButton_() {
      if (this.embeddedInSubpage &&
          this.syncStatus.statusAction ===
              StatusAction.ENTER_PASSPHRASE) {
        // In a subpage the passphrase button is not required.
        return false;
      }
      return !this.hideButtons && !this.showSetupButtons_ &&
          !!this.syncStatus.signedIn && !!this.syncStatus.hasError &&
          this.syncStatus.statusAction !== StatusAction.NO_ACTION;
    },

    /**
     * @param {!Array<!StoredAccount>} accounts
     * @private
     */
    handleStoredAccounts_(accounts) {
      this.storedAccounts_ = accounts;
    },

    /**
     * @return {boolean}
     * @private
     */
    computeShouldShowAvatarRow_() {
      if (this.storedAccounts_ === undefined || this.syncStatus === undefined) {
        return false;
      }

      return this.syncStatus.signedIn || this.storedAccounts_.length > 0;
    },

    /** @private */
    onErrorButtonTap_() {
      const router = Router.getInstance();
      const routes =
          /** @type {{ SIGN_OUT: !Route }} */ (router.getRoutes());
      switch (this.syncStatus.statusAction) {
        case StatusAction.REAUTHENTICATE:
          this.syncBrowserProxy_.startSignIn();
          break;
        case StatusAction.SIGNOUT_AND_SIGNIN:
          if (this.syncStatus.domain) {
            router.navigateTo(routes.SIGN_OUT);
          } else {
            // Silently sign the user out without deleting their profile and
            // prompt them to sign back in.
            this.syncBrowserProxy_.signOut(false);
            this.syncBrowserProxy_.startSignIn();
          }
          break;
        case StatusAction.UPGRADE_CLIENT:
          router.navigateTo(router.getRoutes().ABOUT);
          break;
        case StatusAction.RETRIEVE_TRUSTED_VAULT_KEYS:
          this.syncBrowserProxy_.startKeyRetrieval();
          break;
        case StatusAction.ENTER_PASSPHRASE:
        case StatusAction.CONFIRM_SYNC_SETTINGS:
        default:
          router.navigateTo(router.getRoutes().SYNC);
      }
    },

    /** @private */
    onSigninTap_() {
      // <if expr="not chromeos">
      this.syncBrowserProxy_.startSignIn();
      // </if>
      // <if expr="chromeos">
      // Chrome OS is always signed-in, so just turn on sync.
      this.syncBrowserProxy_.turnOnSync();
      // </if>
      // Need to close here since one menu item also triggers this function.
      if (this.$$('#menu')) {
        /** @type {!CrActionMenuElement} */ (this.$$('#menu')).close();
      }
    },

    /** @private */
    onSignoutTap_() {
      this.syncBrowserProxy_.signOut(false /* deleteProfile */);
      /** @type {!CrActionMenuElement} */ (this.$$('#menu')).close();
    },

    /** @private */
    onSyncButtonTap_() {
      assert(this.shownAccount_);
      assert(this.storedAccounts_.length > 0);
      const isDefaultPromoAccount =
          (this.shownAccount_.email === this.storedAccounts_[0].email);

      this.syncBrowserProxy_.startSyncingWithEmail(
          this.shownAccount_.email, isDefaultPromoAccount);
    },

    /** @private */
    onTurnOffButtonTap_() {
      /* This will route to people_page's disconnect dialog. */
      const router = Router.getInstance();
      router.navigateTo(
          /** @type {{ SIGN_OUT: !Route }} */ (router.getRoutes())
              .SIGN_OUT);
    },

    /** @private */
    onMenuButtonTap_() {
      const actionMenu =
          /** @type {!CrActionMenuElement} */ (this.$$('#menu'));
      actionMenu.showAt(assert(this.$$('#dropdown-arrow')));
    },

    /** @private */
    onShouldShowAvatarRowChange_() {
      // Close dropdown when avatar-row hides, so if it appears again, the menu
      // won't be open by default.
      const actionMenu = this.$$('#menu');
      if (!this.shouldShowAvatarRow_ && actionMenu && actionMenu.open) {
        actionMenu.close();
      }
    },

    /**
     * @param {!{model:
     *          !{item: !StoredAccount},
     *        }} e
     * @private
     */
    onAccountTap_(e) {
      this.shownAccount_ = e.model.item;
      /** @type {!CrActionMenuElement} */ (this.$$('#menu')).close();
    },

    /** @private */
    onShownAccountShouldChange_() {
      if (this.storedAccounts_ === undefined || this.syncStatus === undefined) {
        return;
      }

      if (this.syncStatus.signedIn) {
        for (let i = 0; i < this.storedAccounts_.length; i++) {
          if (this.storedAccounts_[i].email ===
              this.syncStatus.signedInUsername) {
            this.shownAccount_ = this.storedAccounts_[i];
            return;
          }
        }
      } else {
        const firstStoredAccount =
            (this.storedAccounts_.length > 0) ? this.storedAccounts_[0] : null;

        // Sign-in impressions should be recorded in the following cases:
        // 1. When the promo is first shown, i.e. when |shownAccount_| is
        //   initialized;
        // 2. When the impression account state changes, i.e. promo impression
        //   state changes (WithAccount -> WithNoAccount) or
        //   (WithNoAccount -> WithAccount).
        const shouldRecordImpression = (this.shownAccount_ === undefined) ||
            (!this.shownAccount_ && firstStoredAccount) ||
            (this.shownAccount_ && !firstStoredAccount);

        this.shownAccount_ = firstStoredAccount;

        if (shouldRecordImpression) {
          this.recordImpressionUserActions_();
        }
      }
    },

    /**
     * @return {boolean}
     * @private
     */
    computeShowSetupButtons_() {
      return !this.hideButtons && !!this.syncStatus.firstSetupInProgress;
    },

    /** @private */
    onSetupCancel_() {
      this.fire('sync-setup-done', false);
    },

    /** @private */
    onSetupConfirm_() {
      this.fire('sync-setup-done', true);
    },
  });

