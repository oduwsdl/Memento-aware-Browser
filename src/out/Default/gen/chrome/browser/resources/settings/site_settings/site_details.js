// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'site-details' show the details (permissions and usage) for a given origin
 * under Site Settings.
 */
import 'chrome://resources/js/action_link.js';
import 'chrome://resources/cr_elements/action_link_css.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_link_row/cr_link_row.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import '../icons.m.js';
import '../settings_shared_css.m.js';
import './all_sites_icons.js';
import './clear_storage_dialog_css.js';
import './site_details_permission.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';
import {routes} from '../route.js';
import {Route, RouteObserverBehavior, Router} from '../router.m.js';

import {ContentSetting, ContentSettingsTypes} from './constants.js';
import {SiteSettingsBehavior} from './site_settings_behavior.js';
import {WebsiteUsageBrowserProxy, WebsiteUsageBrowserProxyImpl} from './website_usage_browser_proxy.js';

Polymer({
  is: 'site-details',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared action-link iron-flex">
      .favicon-image {
        margin: 2px;
      }

      #storage {
        padding-inline-end: 0;
      }

      #storageText {
        display: flex;
      }

      #resetSettingsButton {
        margin-top: 24px;
      }

      #usageHeader {
        padding: 0 var(--cr-section-padding);
      }
    </style>
    <!-- Confirm reset settings dialog. -->
    <cr-dialog id="confirmResetSettings" close-text="$i18n{close}"
        on-close="onResetSettingsDialogClosed_">
      <div slot="body">
        [[i18n('siteSettingsSiteResetConfirmation', pageTitle)]]
      </div>
      <div slot="button-container">
        <cr-button class="cancel-button" on-click="onCloseDialog_">
          $i18n{cancel}
        </cr-button>
        <cr-button class="action-button" on-click="onResetSettings_">
          $i18n{siteSettingsSiteResetAll}
        </cr-button>
      </div>
    </cr-dialog>

    <!-- Confirm clear storage dialog. -->
    <cr-dialog id="confirmClearStorage" close-text="$i18n{close}"
        on-close="onClearStorageDialogClosed_">
      <style include="clear-storage-dialog-shared"></style>
      <div slot="title">
        $i18n{siteSettingsSiteClearStorageDialogTitle}
      </div>
      <div slot="body">
        [[i18n('siteSettingsSiteClearStorageConfirmation', pageTitle)]]
      </div>
      <div slot="button-container">
        <cr-button class="cancel-button" on-click="onCloseDialog_">
          $i18n{cancel}
        </cr-button>
        <cr-button class="action-button" on-click="onClearStorage_">
          $i18n{siteSettingsSiteClearStorage}
        </cr-button>
      </div>
    </cr-dialog>

    <!-- New version of confirm clear data dialog to show if storage
         pressure UI flag is enabled. -->
    <cr-dialog id="confirmClearStorageNew" close-text="$i18n{close}"
        on-close="onClearStorageDialogClosed_">
      <style include="clear-storage-dialog-shared"></style>
      <div slot="title">
        $i18n{siteSettingsSiteClearStorageDialogTitle}
      </div>
      <div slot="body">
        [[i18n('siteSettingsSiteClearStorageConfirmationNew', pageTitle)]]
        <div class="detail-list">
          <div class="detail">
            <iron-icon icon="all-sites:logout"></iron-icon>
            $i18n{siteSettingsSiteClearStorageSignOut}
          </div>
          <div class="detail">
            <iron-icon icon="all-sites:offline"></iron-icon>
            $i18n{siteSettingsSiteClearStorageOfflineData}
          </div>
        </div>
      </div>
      <div slot="button-container">
        <cr-button class="cancel-button" on-click="onCloseDialog_">
          $i18n{cancel}
        </cr-button>
        <cr-button class="action-button" on-click="onClearStorage_">
          $i18n{siteSettingsSiteClearStorage}
        </cr-button>
      </div>
    </cr-dialog>

    <div id="usage">
      <div id="usageHeader">
        <h2 class="first">$i18n{siteSettingsUsage}</h2>
      </div>
      <div class="list-frame">
        <div class="list-item" id="noStorage"
            hidden$="[[hasUsage_(storedData_, numCookies_)]]">
          <div class="start">$i18n{siteSettingsUsageNone}</div>
        </div>
        <div class="list-item" id="storage"
            hidden$="[[!hasUsage_(storedData_, numCookies_)]]">
          <div class="start" id="storageText">
            <div hidden$="[[!storedData_]]">[[storedData_]]</div>
            <div hidden$="[[!hasDataAndCookies_(storedData_, numCookies_)]]">
              &nbsp;&middot;&nbsp;
            </div>
            <div hidden$="[[!numCookies_]]">[[numCookies_]]</div>
          </div>
          <cr-button id="clearStorage" role="button" aria-disabled="false"
              on-click="onConfirmClearStorage_"
              aria-label="$i18n{siteSettingsDelete}">
            $i18n{siteSettingsDelete}
          </cr-button>
        </div>
      </div>
    </div>

    <div class="cr-row first">
      <h2 class="flex">$i18n{siteSettingsPermissions}</h2>
      <cr-button id="resetSettingsButton" class="header-aligned-button"
          role="button" aria-disabled="false"
          on-click="onConfirmClearSettings_">
        $i18n{siteSettingsReset}
      </cr-button>
    </div>
    <div class="list-frame">
      <site-details-permission category="{{ContentSettingsTypes.GEOLOCATION}}"
          icon="cr:location-on" id="geolocation"
          label="$i18n{siteSettingsLocation}">
      </site-details-permission>
      <site-details-permission category="{{ContentSettingsTypes.CAMERA}}"
          icon="cr:videocam" id="camera"
          label="$i18n{siteSettingsCamera}">
      </site-details-permission>
      <site-details-permission category="{{ContentSettingsTypes.MIC}}"
          icon="cr:mic" id="mic"
          label="$i18n{siteSettingsMic}">
      </site-details-permission>
      <site-details-permission
          category="{{ContentSettingsTypes.SENSORS}}"
          icon="settings:sensors" id="sensors"
          label="$i18n{siteSettingsSensors}">
      </site-details-permission>
      <site-details-permission category="{{ContentSettingsTypes.NOTIFICATIONS}}"
          icon="settings:notifications" id="notifications"
          label="$i18n{siteSettingsNotifications}">
      </site-details-permission>
      <site-details-permission category="{{ContentSettingsTypes.JAVASCRIPT}}"
          icon="settings:code" id="javascript"
          label="$i18n{siteSettingsJavascript}">
      </site-details-permission>
      <site-details-permission category="{{ContentSettingsTypes.PLUGINS}}"
          icon="cr:extension" id="plugins" label="$i18n{siteSettingsFlash}">
      </site-details-permission>
      <site-details-permission category="{{ContentSettingsTypes.IMAGES}}"
          icon="settings:photo" id="images" label="$i18n{siteSettingsImages}">
      </site-details-permission>
      <site-details-permission category="{{ContentSettingsTypes.POPUPS}}"
          icon="cr:open-in-new" id="popups" label="$i18n{siteSettingsPopups}">
      </site-details-permission>
      <site-details-permission
          category="{{ContentSettingsTypes.ADS}}"
          icon="settings:ads" id="ads"
          label="$i18n{siteSettingsAds}">
      </site-details-permission>
      <site-details-permission
          category="{{ContentSettingsTypes.BACKGROUND_SYNC}}"
          icon="cr:sync" id="backgroundSync"
          label="$i18n{siteSettingsBackgroundSync}">
      </site-details-permission>
      <site-details-permission category="{{ContentSettingsTypes.SOUND}}"
          icon="settings:volume-up" id="sound"
          label="$i18n{siteSettingsSound}"
          use-automatic-label="[[blockAutoplayEnabled]]">
      </site-details-permission>
      <site-details-permission
          category="{{ContentSettingsTypes.AUTOMATIC_DOWNLOADS}}"
          icon="cr:file-download" id="automaticDownloads"
          label="$i18n{siteSettingsAutomaticDownloads}">
      </site-details-permission>
      <site-details-permission
          category="{{ContentSettingsTypes.MIDI_DEVICES}}" icon="settings:midi"
          id="midiDevices" label="$i18n{siteSettingsMidiDevices}">
      </site-details-permission>
      <site-details-permission
          category="{{ContentSettingsTypes.USB_DEVICES}}" icon="settings:usb"
          id="usbDevices" label="$i18n{siteSettingsUsbDevices}">
      </site-details-permission>
      <site-details-permission
          category="{{ContentSettingsTypes.SERIAL_PORTS}}"
          icon="settings:serial-port" id="serialPorts"
          label="$i18n{siteSettingsSerialPorts}">
      </site-details-permission>
      <template is="dom-if" if="[[enableWebBluetoothNewPermissionsBackend_]]">
        <site-details-permission
            category="{{ContentSettingsTypes.BLUETOOTH_DEVICES}}"
            icon="settings:bluetooth" id="bluetoothDevices"
            label="$i18n{siteSettingsBluetoothDevices}">
        </site-details-permission>
      </template>
      <template is="dom-if" if="[[enableNativeFileSystemWriteContentSetting_]]">
        <site-details-permission
            category="{{ContentSettingsTypes.NATIVE_FILE_SYSTEM_WRITE}}"
            icon="settings:save-original" id="nativeFileSystemWrite"
            label="$i18n{siteSettingsNativeFileSystemWrite}">
        </site-details-permission>
      </template>
      <template is="dom-if" if="[[enableExperimentalWebPlatformFeatures_]]">
        <site-details-permission
            category="[[ContentSettingsTypes.HID_DEVICES]]"
            icon="settings:hid-device" id="hidDevices"
            label="$i18n{siteSettingsHidDevices}">
        </site-details-permission>
      </template>
      <site-details-permission
          category="{{ContentSettingsTypes.UNSANDBOXED_PLUGINS}}"
          icon="cr:extension" id="unsandboxedPlugins"
          label="$i18n{siteSettingsUnsandboxedPlugins}">
      </site-details-permission>
<if expr="chromeos">
      <site-details-permission
          category="{{ContentSettingsTypes.PROTECTED_CONTENT}}"
          icon="settings:protected-content" id="protectedContent"
          label="$i18n{siteSettingsProtectedContentIdentifiers}">
      </site-details-permission>
</if>
      <site-details-permission
          category="{{ContentSettingsTypes.CLIPBOARD}}"
          icon="settings:clipboard" id="clipboard"
          label="$i18n{siteSettingsClipboard}">
      </site-details-permission>
      <site-details-permission
          category="{{ContentSettingsTypes.PAYMENT_HANDLER}}"
          icon="settings:payment-handler" id="paymentHandler"
          label="$i18n{siteSettingsPaymentHandler}">
      </site-details-permission>
      <template is="dom-if" if="[[enableExperimentalWebPlatformFeatures_]]">
        <site-details-permission
            category="{{ContentSettingsTypes.BLUETOOTH_SCANNING}}"
            icon="settings:bluetooth-scanning" id="bluetoothScanning"
            label="$i18n{siteSettingsBluetoothScanning}">
        </site-details-permission>
      </template>
      <template is="dom-if" if="[[enableInsecureContentContentSetting_]]">
        <site-details-permission
            category="{{ContentSettingsTypes.MIXEDSCRIPT}}"
            icon="settings:insecure-content" id="mixed-script"
            label="$i18n{siteSettingsInsecureContent}">
        </site-details-permission>
      </template>
      <site-details-permission
          category="{{ContentSettingsTypes.AR}}"
          icon="settings:vr-headset" id="ar"
          label="$i18n{siteSettingsAr}">
      </site-details-permission>
      <site-details-permission
          category="{{ContentSettingsTypes.VR}}"
          icon="settings:vr-headset" id="vr"
          label="$i18n{siteSettingsVr}">
      </site-details-permission>
      <template is="dom-if" if="[[enableExperimentalWebPlatformFeatures_]]">
        <site-details-permission
            category="{{ContentSettingsTypes.WINDOW_PLACEMENT}}"
            icon="settings:window-placement" id="windowPlacement"
            label="$i18n{siteSettingsWindowPlacement}">
        </site-details-permission>
      </template>
    </div>
<!--_html_template_end_-->`,

  behaviors: [
    I18nBehavior, SiteSettingsBehavior, RouteObserverBehavior,
    WebUIListenerBehavior
  ],

  properties: {
    /**
     * Whether unified autoplay blocking is enabled.
     */
    blockAutoplayEnabled: Boolean,

    /**
     * Use the string representing the origin or extension name as the page
     * title of the settings-subpage parent.
     */
    pageTitle: {
      type: String,
      notify: true,
    },

    /**
     * The origin that this widget is showing details for.
     * @private
     */
    origin_: String,

    /**
     * The amount of data stored for the origin.
     * @private
     */
    storedData_: {
      type: String,
      value: '',
    },

    /**
     * The number of cookies stored for the origin.
     * @private
     */
    numCookies_: {
      type: String,
      value: '',
    },

    /** @private */
    enableExperimentalWebPlatformFeatures_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('enableExperimentalWebPlatformFeatures');
      },
    },

    /** @private */
    enableNativeFileSystemWriteContentSetting_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean(
            'enableNativeFileSystemWriteContentSetting');
      }
    },

    /** @private */
    enableInsecureContentContentSetting_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('enableInsecureContentContentSetting');
      }
    },

    /** @private */
    storagePressureFlagEnabled_: {
      type: Boolean,
      value: () => loadTimeData.getBoolean('enableStoragePressureUI'),
    },

    /** @private */
    enableWebBluetoothNewPermissionsBackend_: {
      type: Boolean,
      value: () =>
          loadTimeData.getBoolean('enableWebBluetoothNewPermissionsBackend'),
    },
  },

  /** @private {string} */
  fetchingForHost_: '',

  /** @private {?WebsiteUsageBrowserProxy} */
  websiteUsageProxy_: null,

  /** @override */
  attached() {
    this.websiteUsageProxy_ = WebsiteUsageBrowserProxyImpl.getInstance();
    this.addWebUIListener('usage-total-changed', (host, data, cookies) => {
      this.onUsageTotalChanged_(host, data, cookies);
    });

    this.addWebUIListener(
        'contentSettingSitePermissionChanged',
        this.onPermissionChanged_.bind(this));

    // <if expr="chromeos">
    this.addWebUIListener(
        'prefEnableDrmChanged', this.prefEnableDrmChanged_.bind(this));
    // </if>

    // Refresh block autoplay status from the backend.
    this.browserProxy.fetchBlockAutoplayStatus();
  },

  /** @override */
  ready() {
    this.ContentSettingsTypes = ContentSettingsTypes;
  },

  /**
   * RouteObserverBehavior
   * @param {!Route} route
   * @protected
   */
  currentRouteChanged(route) {
    if (route !== routes.SITE_SETTINGS_SITE_DETAILS) {
      return;
    }
    const site = Router.getInstance().getQueryParameters().get('site');
    if (!site) {
      return;
    }
    this.origin_ = site;
    this.browserProxy.isOriginValid(this.origin_).then((valid) => {
      if (!valid) {
        Router.getInstance().navigateToPreviousRoute();
      } else {
        this.fetchingForHost_ = this.toUrl(this.origin_).hostname;
        this.storedData_ = '';
        this.websiteUsageProxy_.fetchUsageTotal(this.fetchingForHost_);
        this.updatePermissions_(this.getCategoryList());
      }
    });
  },

  /**
   * Called when a site within a category has been changed.
   * @param {!ContentSettingsTypes} category The category that
   *     changed.
   * @param {string} origin The origin of the site that changed.
   * @param {string} embeddingOrigin The embedding origin of the site that
   *     changed.
   * @private
   */
  onPermissionChanged_(category, origin, embeddingOrigin) {
    if (this.origin_ === undefined || this.origin_ === '' ||
        origin === undefined || origin === '') {
      return;
    }
    if (!this.getCategoryList().includes(category)) {
      return;
    }

    // Site details currently doesn't support embedded origins, so ignore it
    // and just check whether the origins are the same.
    this.updatePermissions_([category]);
  },

  /**
   * Callback for when the usage total is known.
   * @param {string} host The host that the usage was fetched for.
   * @param {string} usage The string showing how much data the given host
   *     is using.
   * @param {string} cookies The string showing how many cookies the given host
   *     is using.
   * @private
   */
  onUsageTotalChanged_(host, usage, cookies) {
    if (this.fetchingForHost_ === host) {
      this.storedData_ = usage;
      this.numCookies_ = cookies;
    }
  },

  // <if expr="chromeos">
  prefEnableDrmChanged_() {
    this.updatePermissions_([ContentSettingsTypes.PROTECTED_CONTENT]);
  },
  // </if>

  /**
   * Retrieves the permissions listed in |categoryList| from the backend for
   * |this.origin_|.
   * @param {!Array<!ContentSettingsTypes>} categoryList The list
   *     of categories to update permissions for.
   * @private
   */
  updatePermissions_(categoryList) {
    const permissionsMap =
        /**
         * @type {!Object<!ContentSettingsTypes,
         *         !SiteDetailsPermissionElement>}
         */
        (Array.prototype.reduce.call(
            this.root.querySelectorAll('site-details-permission'),
            (map, element) => {
              if (categoryList.includes(element.category)) {
                map[element.category] = element;
              }
              return map;
            },
            {}));

    this.browserProxy.getOriginPermissions(this.origin_, categoryList)
        .then((exceptionList) => {
          exceptionList.forEach((exception, i) => {
            // |exceptionList| should be in the same order as
            // |categoryList|.
            if (permissionsMap[categoryList[i]]) {
              permissionsMap[categoryList[i]].site = exception;
            }
          });

          // The displayName won't change, so just use the first
          // exception.
          assert(exceptionList.length > 0);
          this.pageTitle =
              this.originRepresentation(exceptionList[0].displayName);
        });
  },

  /** @private */
  onCloseDialog_(e) {
    e.target.closest('cr-dialog').close();
  },

  /**
   * Confirms the resetting of all content settings for an origin.
   * @param {!Event} e
   * @private
   */
  onConfirmClearSettings_(e) {
    e.preventDefault();
    this.$.confirmResetSettings.showModal();
  },

  /**
   * Confirms the clearing of storage for an origin.
   * @param {!Event} e
   * @private
   */
  onConfirmClearStorage_(e) {
    e.preventDefault();
    if (this.storagePressureFlagEnabled_) {
      this.$.confirmClearStorageNew.showModal();
    } else {
      this.$.confirmClearStorage.showModal();
    }
  },

  /**
   * Resets all permissions for the current origin.
   * @private
   */
  onResetSettings_(e) {
    this.browserProxy.setOriginPermissions(
        this.origin_, this.getCategoryList(), ContentSetting.DEFAULT);
    if (this.getCategoryList().includes(ContentSettingsTypes.PLUGINS)) {
      this.browserProxy.clearFlashPref(this.origin_);
    }

    this.onCloseDialog_(e);
  },

  /**
   * Clears all data stored, except cookies, for the current origin.
   * @private
   */
  onClearStorage_(e) {
    if (this.hasUsage_(this.storedData_, this.numCookies_)) {
      this.websiteUsageProxy_.clearUsage(this.toUrl(this.origin_).href);
      this.storedData_ = '';
      this.numCookies_ = '';
    }

    this.onCloseDialog_(e);
  },

  /**
   * Checks whether this site has any usage information to show.
   * @return {boolean} Whether there is any usage information to show (e.g.
   *     disk or battery).
   * @private
   */
  hasUsage_(storage, cookies) {
    return storage !== '' || cookies !== '';
  },

  /**
   * Checks whether this site has both storage and cookies information to show.
   * @return {boolean} Whether there are both storage and cookies information to
   *     show.
   * @private
   */
  hasDataAndCookies_(storage, cookies) {
    return storage !== '' && cookies !== '';
  },

  /** @private */
  onResetSettingsDialogClosed_() {
    focusWithoutInk(assert(this.$$('#resetSettingsButton')));
  },

  /** @private */
  onClearStorageDialogClosed_() {
    focusWithoutInk(assert(this.$$('#clearStorage')));
  },
});
