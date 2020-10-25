// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'settings-people-page' is the settings page containing sign-in settings.
 */
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_link_row/cr_link_row.m.js';
import 'chrome://resources/cr_elements/cr_toast/cr_toast.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/policy/cr_policy_indicator.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import '../controls/settings_toggle_button.m.js';
import './sync_account_control.m.js';
import '../icons.m.js';
import '../settings_page/settings_animated_pages.m.js';
import '../settings_page/settings_subpage.m.js';
import '../settings_shared_css.m.js';

// <if expr="chromeos">
import {convertImageSequenceToPng} from 'chrome://resources/cr_elements/chromeos/cr_picture/png.m.js';
// </if>
import {assert} from 'chrome://resources/js/assert.m.js';
import {isChromeOS} from 'chrome://resources/js/cr.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {getImage} from 'chrome://resources/js/icon.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';
import {OpenWindowProxyImpl} from '../open_window_proxy.js';
import {PageVisibility} from '../page_visibility.js';
import {routes} from '../route.js';
import {RouteObserverBehavior, Router} from '../router.m.js';

// <if expr="chromeos">
import {AccountManagerBrowserProxyImpl} from './account_manager_browser_proxy.m.js';
// </if>
import {ProfileInfo, ProfileInfoBrowserProxy, ProfileInfoBrowserProxyImpl} from './profile_info_browser_proxy.m.js';
import {StoredAccount, SyncBrowserProxy, SyncBrowserProxyImpl, SyncStatus} from './sync_browser_proxy.m.js';

Polymer({
  is: 'settings-people-page',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared iron-flex">
      .sync-row {
        align-items: center;
        flex: auto;
      }

      #profile-icon {
        background: center / cover no-repeat;
        border-radius: 20px;
        flex-shrink: 0;
        height: 40px;
        width: 40px;
      }

      #sync-setup {
        --cr-secondary-text-color: var(--settings-error-color);
      }

      cr-link-row {
        --cr-link-row-icon-width: 40px;
        border-top: var(--cr-separator-line);
      }

      .icon-container {
        display: flex;
        flex-shrink: 0;
        justify-content: center;
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

      settings-sync-account-control[showing-promo]::part(banner) {
        /* Make the banner image stay within setting-section's card border
           radius. */
        border-top-left-radius: var(--cr-card-border-radius);
        border-top-right-radius: var(--cr-card-border-radius);
      }

      settings-sync-account-control[showing-promo]::part(title) {
        font-size: 1.1rem;
        line-height: 1.625rem;
      }
    </style>
    <settings-animated-pages id="pages" section="people"
        focus-config="[[focusConfig_]]">
      <div route-path="default">
        <template is="dom-if" if="[[shouldShowSyncAccountControl_(
            syncStatus.syncSystemEnabled)]]">
          <settings-sync-account-control
              sync-status="[[syncStatus]]"
              prefs="{{prefs}}"
              promo-label-with-account="$i18n{peopleSignInPrompt}"
              promo-label-with-no-account="$i18n{peopleSignInPrompt}"
              promo-secondary-label-with-account=
                  "$i18n{peopleSignInPromptSecondaryWithAccount}"
              promo-secondary-label-with-no-account=
                  "$i18n{peopleSignInPromptSecondaryWithNoAccount}">
          </settings-sync-account-control>
        </template>
        <template is="dom-if" if="[[!shouldShowSyncAccountControl_(
            syncStatus.syncSystemEnabled, signinAllowed_)]]" restamp>
          <div id="profile-row" class="cr-row first two-line"
                  actionable$="[[isProfileActionable_]]"
                  on-click="onProfileTap_">
            <template is="dom-if" if="[[syncStatus]]">
              <div id="profile-icon"
                  style="background-image: [[getIconImageSet_(
                      profileIconUrl_)]]">
              </div>
              <div class="flex cr-row-gap cr-padded-text text-elide">
                <span id="profile-name">[[profileName_]]</span>
<!-- When the user is signed-in, the settings-sync-account-control is always
shown on non-ChromeOS platforms -->
<if expr="chromeos">
                <div class="secondary" hidden="[[!syncStatus.signedIn]]">
                  [[syncStatus.signedInUsername]]
                </div>
</if>
              </div>
<if expr="not chromeos">
              <cr-icon-button class="subpage-arrow"
                  aria-label="$i18n{editPerson}"
                  aria-describedby="profile-name"
                  aria-roledescription="$i18n{subpageArrowRoleDescription}">
              </cr-icon-button>
</if>
<if expr="chromeos">
              <cr-icon-button class="icon-external"
                  id="profile-subpage-arrow"
                  hidden="[[!isProfileActionable_]]"
                  aria-label="$i18n{accountManagerSubMenuLabel}"
                  aria-describedby="profile-name"></cr-icon-button>
</if>
            </template>
          </div>
        </template> <!-- if="[[!shouldShowSyncAccountControl_()]]" -->

        <cr-link-row id="sync-setup"
            label="$i18n{syncAndNonPersonalizedServices}"
            sub-label="[[getSyncAndGoogleServicesSubtext_(syncStatus)]]"
            on-click="onSyncTap_"
            role-description="$i18n{subpageArrowRoleDescription}">
        </cr-link-row>

<if expr="not chromeos">
        <template is="dom-if" if="[[signinAllowed_]]">
          <cr-link-row id="manage-google-account"
              label="$i18n{manageGoogleAccount}"
              hidden="[[!shouldShowGoogleAccount_]]"
              on-click="openGoogleAccount_" external></cr-link-row>

          <div class="cr-row" id="edit-profile" on-click="onProfileTap_"
              actionable>
            <div class="flex cr-padded-text">
              $i18n{profileNameAndPicture}
            </div>
            <cr-icon-button class="subpage-arrow" aria-label="$i18n{editPerson}"
                aria-roledescription="$i18n{subpageArrowRoleDescription}">
            </cr-icon-button>
          </div>
        </template>
</if>

<if expr="not chromeos">
        <cr-link-row id="importDataDialogTrigger"
            label="$i18n{importTitle}"
            on-click="onImportDataTap_"></cr-link-row>
</if>

      </div>
      <template is="dom-if" route-path="/syncSetup">
        <settings-subpage
            associated-control="[[$$('#sync-setup')]]"
            page-title="$i18n{syncPageTitle}"
            learn-more-url="$i18n{syncAndGoogleServicesLearnMoreURL}">
          <settings-sync-page
              sync-status="[[syncStatus]]" prefs="{{prefs}}"
              page-visibility="[[pageVisibility.privacy]]"
              focus-config="[[focusConfig_]]">
          </settings-sync-page>
        </settings-subpage>
      </template>

      <template is="dom-if" route-path="/syncSetup/advanced">
        <settings-subpage page-title="$i18n{syncAdvancedPageTitle}"
            associated-control="[[$$('#sync-setup')]]"
            learn-more-url="$i18n{syncAndGoogleServicesLearnMoreURL}">
          <settings-sync-controls sync-status="[[syncStatus]]">
          </settings-sync-controls>
        </settings-subpage>
      </template>

<if expr="not chromeos">
      <template is="dom-if" route-path="/manageProfile">
        <settings-subpage
            associated-control=
                "[[getEditPersonAssocControl_(signinAllowed_)]]"
            page-title="$i18n{editPerson}">
          <settings-manage-profile profile-name="[[profileName_]]"
              sync-status="[[syncStatus]]">
          </settings-manage-profile>
        </settings-subpage>
      </template>
</if>
    </settings-animated-pages>

    <template is="dom-if" if="[[showSignoutDialog_]]" restamp>
      <settings-signout-dialog sync-status="[[syncStatus]]"
          on-close="onDisconnectDialogClosed_">
      </settings-signout-dialog>
    </template>

    <template is="dom-if" if="[[showImportDataDialog_]]" restamp>
      <settings-import-data-dialog prefs="{{prefs}}"
          on-close="onImportDataDialogClosed_">
      </settings-import-data-dialog>
    </template>
    <cr-toast duration="3000" id="toast">
      <span>$i18n{syncSettingsSavedToast}</span>
    </cr-toast>
<!--_html_template_end_-->`,

  behaviors: [
    RouteObserverBehavior,
    I18nBehavior,
    WebUIListenerBehavior,
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
     * This flag is used to conditionally show a set of new sign-in UIs to the
     * profiles that have been migrated to be consistent with the web sign-ins.
     * TODO(tangltom): In the future when all profiles are completely migrated,
     * this should be removed, and UIs hidden behind it should become default.
     * @private
     */
    signinAllowed_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('signinAllowed');
      },
    },

    // <if expr="not chromeos">
    /**
     * Stored accounts to the system, supplied by SyncBrowserProxy.
     * @type {?Array<!StoredAccount>}
     */
    storedAccounts: Object,
    // </if>

    /**
     * The current sync status, supplied by SyncBrowserProxy.
     * @type {?SyncStatus}
     */
    syncStatus: Object,

    /**
     * Dictionary defining page visibility.
     * @type {!PageVisibility}
     */
    pageVisibility: Object,

    /**
     * Authentication token provided by settings-lock-screen.
     * @private
     */
    authToken_: {
      type: String,
      value: '',
    },

    /**
     * The currently selected profile icon URL. May be a data URL.
     * @private
     */
    profileIconUrl_: String,

    /**
     * Whether the profile row is clickable. The behavior depends on the
     * platform.
     * @private
     */
    isProfileActionable_: {
      type: Boolean,
      value() {
        if (!isChromeOS) {
          // Opens profile manager.
          return true;
        }
        // Post-SplitSettings links out to account manager if it is available.
        return loadTimeData.getBoolean('isAccountManagerEnabled');
      },
      readOnly: true,
    },

    /**
     * The current profile name.
     * @private
     */
    profileName_: String,

    // <if expr="not chromeos">
    /** @private {boolean} */
    shouldShowGoogleAccount_: {
      type: Boolean,
      value: false,
      computed: 'computeShouldShowGoogleAccount_(storedAccounts, syncStatus,' +
          'storedAccounts.length, syncStatus.signedIn, syncStatus.hasError)',
    },

    /** @private */
    showImportDataDialog_: {
      type: Boolean,
      value: false,
    },
    // </if>

    /** @private */
    showSignoutDialog_: Boolean,

    /** @private {!Map<string, string>} */
    focusConfig_: {
      type: Object,
      value() {
        const map = new Map();
        if (routes.SYNC) {
          map.set(routes.SYNC.path, '#sync-setup');
        }
        // <if expr="not chromeos">
        if (routes.MANAGE_PROFILE) {
          map.set(
              routes.MANAGE_PROFILE.path,
              this.signinAllowed_ ? '#edit-profile .subpage-arrow' :
                                    '#profile-row .subpage-arrow');
        }
        // </if>
        return map;
      },
    },
  },

  /** @private {?SyncBrowserProxy} */
  syncBrowserProxy_: null,

  /** @override */
  attached() {
    let useProfileNameAndIcon = true;
    // <if expr="chromeos">
    if (loadTimeData.getBoolean('isAccountManagerEnabled')) {
      // If this is SplitSettings and we have the Google Account manager,
      // prefer the GAIA name and icon.
      useProfileNameAndIcon = false;
      this.addWebUIListener(
          'accounts-changed', this.updateAccounts_.bind(this));
      this.updateAccounts_();
    }
    // </if>
    if (useProfileNameAndIcon) {
      /** @type {!ProfileInfoBrowserProxy} */ (
          ProfileInfoBrowserProxyImpl.getInstance())
          .getProfileInfo()
          .then(this.handleProfileInfo_.bind(this));
      this.addWebUIListener(
          'profile-info-changed', this.handleProfileInfo_.bind(this));
    }

    this.syncBrowserProxy_ = SyncBrowserProxyImpl.getInstance();
    this.syncBrowserProxy_.getSyncStatus().then(
        this.handleSyncStatus_.bind(this));
    this.addWebUIListener(
        'sync-status-changed', this.handleSyncStatus_.bind(this));

    // <if expr="not chromeos">
    const handleStoredAccounts = accounts => {
      this.storedAccounts = accounts;
    };
    this.syncBrowserProxy_.getStoredAccounts().then(handleStoredAccounts);
    this.addWebUIListener('stored-accounts-updated', handleStoredAccounts);

    this.addWebUIListener('sync-settings-saved', () => {
      /** @type {!CrToastElement} */ (this.$.toast).show();
    });
    // </if>
  },

  /** @protected */
  currentRouteChanged() {
    this.showImportDataDialog_ =
        Router.getInstance().getCurrentRoute() === routes.IMPORT_DATA;

    if (Router.getInstance().getCurrentRoute() === routes.SIGN_OUT) {
      // If the sync status has not been fetched yet, optimistically display
      // the sign-out dialog. There is another check when the sync status is
      // fetched. The dialog will be closed when the user is not signed in.
      if (this.syncStatus && !this.syncStatus.signedIn) {
        Router.getInstance().navigateToPreviousRoute();
      } else {
        this.showSignoutDialog_ = true;
      }
    }
  },

  /**
   * @return {!Element}
   * @private
   */
  getEditPersonAssocControl_() {
    return this.signinAllowed_ ? assert(this.$$('#edit-profile')) :
                                 assert(this.$$('#profile-row'));
  },

  /**
   * @return {string}
   * @private
   */
  getSyncAndGoogleServicesSubtext_() {
    if (this.syncStatus && this.syncStatus.hasError &&
        this.syncStatus.statusText) {
      return this.syncStatus.statusText;
    }
    return '';
  },

  /**
   * Handler for when the profile's icon and name is updated.
   * @private
   * @param {!ProfileInfo} info
   */
  handleProfileInfo_(info) {
    this.profileName_ = info.name;
    /**
     * Extract first frame from image by creating a single frame PNG using
     * url as input if base64 encoded and potentially animated.
     */
    // <if expr="chromeos">
    if (info.iconUrl.startsWith('data:image/png;base64')) {
      this.profileIconUrl_ = convertImageSequenceToPng([info.iconUrl]);
      return;
    }
    // </if>

    this.profileIconUrl_ = info.iconUrl;
  },

  // <if expr="chromeos">
  /**
   * @private
   * @suppress {checkTypes} The types only exists in Chrome OS builds, but
   * Closure doesn't understand the <if> above.
   */
  updateAccounts_: async function() {
    const /** @type {!Array<{Account}>} */ accounts =
        await AccountManagerBrowserProxyImpl.getInstance().getAccounts();
    // The user might not have any GAIA accounts (e.g. guest mode or Active
    // Directory). In these cases the profile row is hidden, so there's nothing
    // to do.
    if (accounts.length === 0) {
      return;
    }
    this.profileName_ = accounts[0].fullName;
    this.profileIconUrl_ = accounts[0].pic;
  },
  // </if>

  /**
   * Handler for when the sync state is pushed from the browser.
   * @param {?SyncStatus} syncStatus
   * @private
   */
  handleSyncStatus_(syncStatus) {
    // Sign-in impressions should be recorded only if the sign-in promo is
    // shown. They should be recorder only once, the first time
    // |this.syncStatus| is set.
    const shouldRecordSigninImpression = !this.syncStatus && syncStatus &&
        this.signinAllowed_ && !syncStatus.signedIn;

    this.syncStatus = syncStatus;

    if (shouldRecordSigninImpression && !this.shouldShowSyncAccountControl_()) {
      // SyncAccountControl records the impressions user actions.
      chrome.metricsPrivate.recordUserAction('Signin_Impression_FromSettings');
    }
  },

  // <if expr="not chromeos">
  /**
   * @return {boolean}
   * @private
   */
  computeShouldShowGoogleAccount_() {
    if (this.storedAccounts === undefined || this.syncStatus === undefined) {
      return false;
    }

    return (this.storedAccounts.length > 0 || !!this.syncStatus.signedIn) &&
        !this.syncStatus.hasError;
  },
  // </if>

  /** @private */
  onProfileTap_() {
    // <if expr="chromeos">
    if (loadTimeData.getBoolean('isAccountManagerEnabled')) {
      // Post-SplitSettings. The browser C++ code loads OS settings in a window.
      // Don't use window.open() because that creates an extra empty tab.
      window.location.href = 'chrome://os-settings/accountManager';
    }
    // </if>
    // <if expr="not chromeos">
    Router.getInstance().navigateTo(routes.MANAGE_PROFILE);
    // </if>
  },

  /** @private */
  onDisconnectDialogClosed_(e) {
    this.showSignoutDialog_ = false;

    if (Router.getInstance().getCurrentRoute() === routes.SIGN_OUT) {
      Router.getInstance().navigateToPreviousRoute();
    }
  },

  /** @private */
  onSyncTap_() {
    // Users can go to sync subpage regardless of sync status.
    Router.getInstance().navigateTo(routes.SYNC);
  },

  // <if expr="not chromeos">
  /** @private */
  onImportDataTap_() {
    Router.getInstance().navigateTo(routes.IMPORT_DATA);
  },

  /** @private */
  onImportDataDialogClosed_() {
    Router.getInstance().navigateToPreviousRoute();
    focusWithoutInk(assert(this.$.importDataDialogTrigger));
  },
  // </if>

  /**
   * Open URL for managing your Google Account.
   * @private
   */
  openGoogleAccount_() {
    OpenWindowProxyImpl.getInstance().openURL(
        loadTimeData.getString('googleAccountUrl'));
    chrome.metricsPrivate.recordUserAction('ManageGoogleAccount_Clicked');
  },

  /**
   * @return {boolean}
   * @private
   */
  shouldShowSyncAccountControl_() {
    if (this.syncStatus === undefined) {
      return false;
    }
    // <if expr="chromeos">
    if (!loadTimeData.getBoolean('useBrowserSyncConsent')) {
      return false;
    }
    // </if>
    return !!this.syncStatus.syncSystemEnabled && this.signinAllowed_;
  },

  /**
   * @param {string} iconUrl
   * @return {string} A CSS image-set for multiple scale factors.
   * @private
   */
  getIconImageSet_(iconUrl) {
    return getImage(iconUrl);
  },
});
