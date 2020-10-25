// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'settings-privacy-page' is the settings page containing privacy and
 * security settings.
 */
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_link_row/cr_link_row.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import '../controls/settings_toggle_button.m.js';
import '../prefs/prefs.m.js';
import '../site_settings/settings_category_default_radio_group.js';
import '../settings_page/settings_animated_pages.m.js';
import '../settings_page/settings_subpage.m.js';
import '../settings_shared_css.m.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {HatsBrowserProxyImpl} from '../hats_browser_proxy.js';
import {loadTimeData} from '../i18n_setup.js';
import {MetricsBrowserProxy, MetricsBrowserProxyImpl, PrivacyElementInteractions} from '../metrics_browser_proxy.js';
import {SyncBrowserProxyImpl, SyncStatus} from '../people_page/sync_browser_proxy.m.js';
import {PrefsBehavior} from '../prefs/prefs_behavior.m.js';
import {routes} from '../route.js';
import {RouteObserverBehavior, Router} from '../router.m.js';
import {ChooserType, ContentSettingsTypes, CookieControlsMode, NotificationSetting} from '../site_settings/constants.js';
import {SiteSettingsPrefsBrowserProxyImpl} from '../site_settings/site_settings_prefs_browser_proxy.js';

import {PrivacyPageBrowserProxy, PrivacyPageBrowserProxyImpl} from './privacy_page_browser_proxy.m.js';

/**
 * @typedef {{
 *   enabled: boolean,
 *   pref: !chrome.settingsPrivate.PrefObject
 * }}
 */
let BlockAutoplayStatus;

Polymer({
  is: 'settings-privacy-page',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared iron-flex">
      .content-settings-header,
      #notificationRadioGroup {
        padding: 0 var(--cr-section-padding);
      }

      #notificationSubHeading {
        padding-bottom: 10px;
      }

      settings-collapse-radio-button {
        --settings-collapse-toggle-min-height: var(--settings-row-min-height);
      }

      settings-collapse-radio-button.two-line {
        --settings-collapse-toggle-min-height:
            var(--settings-row-two-line-min-height);
      }

      settings-collapse-radio-button:not(:first-of-type) {
        --settings-collapse-separator-line: var(--cr-separator-line);
      }
    </style>
    <template is="dom-if" if="[[showClearBrowsingDataDialog_]]" restamp>
      <settings-clear-browsing-data-dialog prefs="{{prefs}}"
          on-close="onDialogClosed_">
      </settings-clear-browsing-data-dialog>
    </template>
    <settings-animated-pages id="pages" section="privacy"
        focus-config="[[focusConfig_]]">
      <div route-path="default">
        <cr-link-row id="clearBrowsingData"
            class="hr" start-icon="cr:delete"
            label="$i18n{clearBrowsingData}"
            sub-label="$i18n{clearBrowsingDataDescription}"
            on-click="onClearBrowsingDataTap_"></cr-link-row>
        <cr-link-row id="cookiesLinkRow" start-icon="settings:cookie"
            class="hr" label="$i18n{cookiePageTitle}"
            sub-label="[[cookieSettingDescription_]]"
            on-click="onCookiesClick_"
            role-description="$i18n{subpageArrowRoleDescription}"></cr-link-row>
        <cr-link-row id="securityLinkRow" start-icon="cr:security"
            class="hr" label="$i18n{securityPageTitle}"
            sub-label="$i18n{securityPageDescription}"
            on-click="onSecurityPageClick_"
            role-description="$i18n{subpageArrowRoleDescription}"></cr-link-row>
        <cr-link-row id="permissionsLinkRow" start-icon="settings:permissions"
            class="hr" label="$i18n{siteSettings}"
            sub-label="$i18n{permissionsPageDescription}"
            on-click="onPermissionsPageClick_"
            role-description="$i18n{subpageArrowRoleDescription}"></cr-link-row>
      </div>

<if expr="use_nss_certs">
      <template is="dom-if" route-path="/certificates">
        <settings-subpage
            associated-control="[[$$('#securityLinkRow')]]"
            page-title="$i18n{manageCertificates}">
          <certificate-manager></certificate-manager>
        </settings-subpage>
      </template>
</if>

      <template is="dom-if" if="[[enableSecurityKeysSubpage_]]">
        <template is="dom-if" route-path="/securityKeys">
          <settings-subpage associated-control="[[$$('#securityLinkRow')]]"
              page-title="$i18n{securityKeysTitle}">
            <security-keys-subpage></security-keys-subpage>
          </settings-subpage>
        </template>
      </template>

      <template is="dom-if" route-path="/content">
        <settings-subpage
            associated-control="[[$$('#permissionsLinkRow')]]"
            id="site-settings"
            page-title="$i18n{siteSettings}"
            learn-more-url="$i18n{exceptionsLearnMoreURL}">
          <settings-site-settings-page focus-config="[[focusConfig_]]">
          </settings-site-settings-page>
        </settings-subpage>
      </template>

      <template is="dom-if" route-path="/security">
        <settings-subpage id="security" page-title="$i18n{securityPageTitle}"
            associated-control="[[$$('#securityLinkRow')]]"
            learn-more-url="$i18n{safeBrowsingHelpCenterURL}">
          <settings-security-page prefs="{{prefs}}"
              focus-config="[[focusConfig_]]"
              sync-status="[[syncStatus]]">
          </settings-security-page>
        </settings-subpage>
      </template>

      <template is="dom-if" route-path="/content/all" no-search>
        <settings-subpage page-title="$i18n{siteSettingsAllSites}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}"
            preserve-search-term>
          <all-sites filter="[[searchFilter_]]"></all-sites>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/automaticDownloads" no-search>
        <settings-subpage page-title="$i18n{siteSettingsAutomaticDownloads}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
                <h2>$i18n{siteSettingsAutomaticDownloadsDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.AUTOMATIC_DOWNLOADS]]"
                allow-option-label=
                        "$i18n{siteSettingsAutomaticDownloadsAllowed}"
                allow-option-icon="cr:file-download"
                block-option-label
                    ="$i18n{siteSettingsAutomaticDownloadsBlocked}"
                block-option-icon="settings:block">
            <!-- TODO(https://crbug.com/1033607): use corresponding block
                  icons instead of generic ones throughout this page -->
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.AUTOMATIC_DOWNLOADS]]"
                allow-header=
                    "$i18n{siteSettingsAutomaticDownloadsAllowedExceptions}"
                block-header=
                    "$i18n{siteSettingsAutomaticDownloadsBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsAutoDownloadBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsAutoDownloadAskRecommended}"
                category="[[ContentSettingsTypes.AUTOMATIC_DOWNLOADS]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.AUTOMATIC_DOWNLOADS]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/backgroundSync" no-search>
        <settings-subpage page-title="$i18n{siteSettingsBackgroundSync}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsBackgroundSyncDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.BACKGROUND_SYNC]]"
                allow-option-label=
                    "$i18n{siteSettingsBackgroundSyncAllowed}"
                allow-option-icon="cr:sync"
                block-option-label="$i18n{siteSettingsBackgroundSyncBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.BACKGROUND_SYNC]]"
                allow-header=
                    "$i18n{siteSettingsBackgroundSyncAllowedExceptions}"
                block-header=
                    "$i18n{siteSettingsBackgroundSyncBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsBackgroundSyncBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsAllowRecentlyClosedSitesRecommended}"
                category="[[ContentSettingsTypes.BACKGROUND_SYNC]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.BACKGROUND_SYNC]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/camera" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryCamera}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <media-picker label="$i18n{siteSettingsCameraLabel}" type="camera">
          </media-picker>
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsCameraDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.CAMERA]]"
                allow-option-label=
                    "$i18n{siteSettingsCameraAllowed}"
                allow-option-icon="cr:videocam"
                block-option-label="$i18n{siteSettingsCameraBlocked}"
                block-option-sub-label=
                    "$i18n{siteSettingsCameraBlockedSubLabel}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.CAMERA]]" read-only-list
                allow-header="$i18n{siteSettingsCameraAllowedExceptions}"
                block-header="$i18n{siteSettingsCameraBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                category="[[ContentSettingsTypes.CAMERA]]"
                toggle-off-label="$i18n{siteSettingsBlocked}"
                toggle-on-label=
                    "$i18n{siteSettingsAskBeforeAccessingRecommended}">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.CAMERA]]" read-only-list
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/cookies">
        <settings-subpage id="cookies" page-title="$i18n{cookiePageTitle}"
            learn-more-url="$i18n{cookiesSettingsHelpCenterURL}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}"
            associated-control="[[$$('#cookiesLinkRow')]]">
          <settings-cookies-page prefs="{{prefs}}"
              focus-config="[[focusConfig_]]"
              search-term="[[searchFilter_]]">
          </settings-cookies-page>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/siteData" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCookieHeader}"
            search-label="$i18n{siteSettingsCookieSearch}"
            search-term="{{siteDataFilter_}}"
            preserve-search-term>
          <site-data filter="[[siteDataFilter_]]"
              focus-config="[[focusConfig_]]">
          </site-data>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/images" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryImages}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsImagesDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.IMAGES]]"
                allow-option-label="$i18n{siteSettingsImagesAllowed}"
                allow-option-icon="settings:photo"
                block-option-label="$i18n{siteSettingsImagesBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.IMAGES]]"
                allow-header="$i18n{siteSettingsImagesAllowedExceptions}"
                block-header="$i18n{siteSettingsImagedBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                category="[[ContentSettingsTypes.IMAGES]]"
                toggle-off-label="$i18n{siteSettingsDontShowImages}"
                toggle-on-label="$i18n{siteSettingsShowAllRecommended}">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.IMAGES]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/insecureContent" no-search>
        <settings-subpage
            page-title="$i18n{siteSettingsCategoryInsecureContent}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <div class="cr-row first">
            $i18n{siteSettingsInsecureContentBlock}
          </div>
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <category-setting-exceptions
                category="[[ContentSettingsTypes.MIXEDSCRIPT]]"
                allow-header=
                    "$i18n{siteSettingsInsecureContentAllowedExceptions}"
                block-header=
                    "$i18n{siteSettingsInsecureContentBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-setting-exceptions
                category="[[ContentSettingsTypes.MIXEDSCRIPT]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/location" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryLocation}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsLocationDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.GEOLOCATION]]"
                allow-option-label=
                    "$i18n{siteSettingsLocationAllowed}"
                allow-option-icon="settings20:location-on"
                block-option-label="$i18n{siteSettingsLocationBlocked}"
                block-option-sub-label=
                    "$i18n{siteSettingsLocationBlockedSubLabel}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.GEOLOCATION]]" read-only-list
                allow-header="$i18n{siteSettingsLocationAllowedExceptions}"
                block-header="$i18n{siteSettingsLocationBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsBlocked}"
                toggle-on-label=
                    "$i18n{siteSettingsAskBeforeAccessingRecommended}"
                category="[[ContentSettingsTypes.GEOLOCATION]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.GEOLOCATION]]" read-only-list
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/handlers" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryHandlers}">
          <protocol-handlers
              toggle-off-label="$i18n{siteSettingsHandlersBlocked}"
              toggle-on-label="$i18n{siteSettingsHandlersAskRecommended}">
          </protocol-handlers>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/zoomLevels" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryZoomLevels}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsZoomLevelsDescription}</h2>
            </div>
          </template>
          <zoom-levels></zoom-levels>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/pdfDocuments" no-search>
        <settings-subpage page-title="$i18n{siteSettingsPdfDocuments}">
          <settings-pdf-documents prefs="{{prefs}}"></settings-pdf-documents>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/javascript" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryJavascript}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsJavascriptDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.JAVASCRIPT]]"
                allow-option-label="$i18n{siteSettingsJavascriptAllowed}"
                allow-option-icon="settings:code"
                block-option-label="$i18n{siteSettingsJavascriptBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.JAVASCRIPT]]"
                allow-header="$i18n{siteSettingsJavascriptAllowedExceptions}"
                block-header="$i18n{siteSettingsJavascriptBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsBlocked}"
                toggle-on-label="$i18n{siteSettingsAllowedRecommended}"
                category="[[ContentSettingsTypes.JAVASCRIPT]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.JAVASCRIPT]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/sound" no-search>
        <settings-subpage page-title="$i18n{siteSettingsSound}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsSoundDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.SOUND]]"
                allow-option-label="$i18n{siteSettingsSoundAllowed}"
                allow-option-icon="settings:volume-up"
                block-option-label="$i18n{siteSettingsSoundBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsSoundBlock}"
                toggle-on-label="$i18n{siteSettingsSoundAllowRecommended}"
                category="[[ContentSettingsTypes.SOUND]]">
            </category-default-setting>
          </template>
          <settings-toggle-button
              id="block-autoplay-setting"
              class="hr"
              label="$i18n{siteSettingsBlockAutoplaySetting}"
              pref="{{blockAutoplayStatus_.pref}}"
              disabled="[[!blockAutoplayStatus_.enabled]]"
              hidden="[[!enableBlockAutoplayContentSetting_]]"
              on-settings-boolean-control-change="onBlockAutoplayToggleChange_"
              no-set-pref>
          </settings-toggle-button>
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <category-setting-exceptions
                category="[[ContentSettingsTypes.SOUND]]"
                allow-header="$i18n{siteSettingsSoundAllowedExceptions}"
                block-header="$i18n{siteSettingsSoundBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-setting-exceptions
                category="[[ContentSettingsTypes.SOUND]]"
                block-header="$i18n{siteSettingsBlockSound}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/microphone" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryMicrophone}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <media-picker label="$i18n{siteSettingsMicrophoneLabel}" type="mic">
          </media-picker>
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsMicDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.MIC]]"
                allow-option-label=
                    "$i18n{siteSettingsMicAllowed}"
                allow-option-icon="cr:mic"
                block-option-label="$i18n{siteSettingsMicBlocked}"
                block-option-sub-label="$i18n{siteSettingsMicBlockedSubLabel}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.MIC]]" read-only-list
                allow-header="$i18n{siteSettingsMicAllowedExceptions}"
                block-header="$i18n{siteSettingsMicBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                category="[[ContentSettingsTypes.MIC]]"
                toggle-off-label="$i18n{siteSettingsBlocked}"
                toggle-on-label=
                    "$i18n{siteSettingsAskBeforeAccessingRecommended}">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.MIC]]" read-only-list
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/sensors" no-search>
        <settings-subpage page-title="$i18n{siteSettingsSensors}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsMotionSensorsDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.SENSORS]]"
                allow-option-label="$i18n{siteSettingsMotionSensorsAllowed}"
                allow-option-icon="settings:sensors"
                block-option-label="$i18n{siteSettingsMotionSensorsBlocked}"
                block-option-sub-label=
                    "$i18n{siteSettingsMotionSensorsBlockedSubLabel}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.SENSORS]]" read-only-list
                allow-header="$i18n{siteSettingsMotionSensorsAllowedExceptions}"
                block-header="$i18n{siteSettingsMotionSensorsBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsSensorsBlock}"
                toggle-on-label="$i18n{siteSettingsSensorsAllow}"
                category="[[ContentSettingsTypes.SENSORS]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.SENSORS]]" read-only-list
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
     </template>
      <template is="dom-if" route-path="/content/notifications" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryNotifications}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div id="notificationRadioGroup">
              <h2>$i18n{siteSettingsNotificationsDescription}</h2>
              <h2>$i18n{siteSettingsDefaultBehavior}</h2>
              <div id="notificationSubHeading" class="secondary">
                $i18n{siteSettingsDefaultBehaviorDescription}
              </div>
              <settings-radio-group
                  pref="{{prefs.generated.notification}}"
                  selectable-elements="settings-collapse-radio-button">
                <settings-collapse-radio-button no-collapse
                    name="[[notificationSettingEnum_.ASK]]"
                    pref="[[prefs.generated.notification]]"
                    label="$i18n{siteSettingsNotificationsAllowed}"
                    icon="settings:notifications">
                </settings-collapse-radio-button>
                <template is="dom-if"
                    if="[[enableQuietNotificationPromptsSetting_]]">
                  <settings-collapse-radio-button no-collapse class="two-line"
                      name="[[notificationSettingEnum_.QUIETER_MESSAGING]]"
                      pref="[[prefs.generated.notification]]"
                      label="$i18n{siteSettingsNotificationsAllowed}"
                      sub-label="$i18n{siteSettingsNotificationsPartial}"
                      icon="settings:notifications">
                  </settings-collapse-radio-button>
                </template>
                <settings-collapse-radio-button no-collapse class="two-line"
                    name="[[notificationSettingEnum_.BLOCK]]"
                    pref="[[prefs.generated.notification]]"
                    label="$i18n{siteSettingsNotificationsBlocked}"
                    sub-label="$i18n{siteSettingsNotificationsBlockedSubLabel}"
                    icon="settings:block">
                </settings-collapse-radio-button>
              </settings-radio-group>
            </div>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.NOTIFICATIONS]]"
                allow-header="$i18n{siteSettingsNotificationsAllowedExceptions}"
                block-header="$i18n{siteSettingsNotificationsBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <template is="dom-if"
                if="[[enableQuietNotificationPromptsSetting_]]">
              <category-default-setting
                  toggle-off-label="$i18n{siteSettingsNotificationsAsk}"
                  toggle-on-label="$i18n{siteSettingsNotificationsAsk}"
                  category="[[ContentSettingsTypes.NOTIFICATIONS]]"
                  sub-option-pref="{{prefs.profile.content_settings.enable_quiet_permission_ui.notifications}}"
                  sub-option-label=
                      "$i18n{siteSettingsEnableQuietNotificationPrompts}"
                  sub-option-mode="pref">
              </category-default-setting>
            </template>
            <template is="dom-if"
                if="[[!enableQuietNotificationPromptsSetting_]]">
              <category-default-setting
                  toggle-off-label="$i18n{siteSettingsCategoryNotifications}"
                  toggle-on-label="$i18n{siteSettingsCategoryNotifications}"
                  toggle-off-description="$i18n{siteSettingsNotificationsBlock}"
                  toggle-on-description="$i18n{siteSettingsNotificationsAsk}"
                  category="[[ContentSettingsTypes.NOTIFICATIONS]]"
                  sub-option-mode="none">
              </category-default-setting>
            </template>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.NOTIFICATIONS]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/flash" no-search>
        <settings-subpage page-title="$i18n{siteSettingsFlash}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <div class="cr-row first no-outline">
            $i18n{siteSettingsFlashPermissionsEphemeral}
          </div>
          <div class="cr-row-gap cr-secondary-text"
              hidden="[[!pluginsHasDiscardedExceptions_]]">
            $i18nRaw{warningAboutIgnoredWildcardedPatternsForFlash}
          </div>
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsFlashDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.PLUGINS]]"
                allow-option-label="$i18n{siteSettingsFlashAllowed}"
                allow-option-icon="cr:extension"
                block-option-label="$i18n{siteSettingsFlashBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                category="[[ContentSettingsTypes.PLUGINS]]"
                toggle-off-label="$i18n{siteSettingsFlashBlockRecommended}"
                toggle-on-label="$i18n{siteSettingsFlashAskFirst}">
            </category-default-setting>
          </template>
<if expr="chromeos">
          <a class="cr-row inherit-color no-outline" tabindex="-1"
              target="_blank"
              href="https://www.macromedia.com/support/documentation/en/flashplayer/help/settings_manager07.html">
            <div class="flex">$i18n{adobeFlashStorage}</div>
            <cr-icon-button class="icon-external"
                aria-label="$i18n{adobeFlashStorage}"></cr-icon-button>
          </a>
</if>
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <category-setting-exceptions
                category="[[ContentSettingsTypes.PLUGINS]]"
                allow-header="$i18n{siteSettingsFlashAllowedExceptions}"
                block-header="$i18n{siteSettingsFlashBlockedExceptions}"
                read-only-list
                search-filter="[[searchFilter_]]"
                site-lists-have-discarded-exceptions=
                    "{{pluginsHasDiscardedExceptions_}}">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-setting-exceptions
                category="[[ContentSettingsTypes.PLUGINS]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                read-only-list
                search-filter="[[searchFilter_]]"
                site-lists-have-discarded-exceptions=
                    "{{pluginsHasDiscardedExceptions_}}">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/popups" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryPopups}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsPopupsDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.POPUPS]]"
                allow-option-label="$i18n{siteSettingsPopupsAllowed}"
                allow-option-icon="cr:open-in-new"
                block-option-label="$i18n{siteSettingsPopupsBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.POPUPS]]"
                allow-header="$i18n{siteSettingsPopupsAllowedExceptions}"
                block-header="$i18n{siteSettingsPopupsBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                category="[[ContentSettingsTypes.POPUPS]]"
                toggle-off-label="$i18n{siteSettingsBlockedRecommended}"
                toggle-on-label="$i18n{siteSettingsAllowed}">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.POPUPS]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" if="[[enableSafeBrowsingSubresourceFilter_]]"
          no-search>
        <template is="dom-if" route-path="/content/ads" no-search>
          <settings-subpage page-title="$i18n{siteSettingsAds}"
              search-label="$i18n{siteSettingsAllSitesSearch}"
              search-term="{{searchFilter_}}">
            <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
              <div class="content-settings-header">
                <h2>$i18n{siteSettingsAdsDescription}</h2>
              </div>
              <settings-category-default-radio-group
                  category="[[ContentSettingsTypes.ADS]]"
                  allow-option-label="$i18n{siteSettingsAdsAllowed}"
                  allow-option-icon="settings:ads"
                  block-option-label="$i18n{siteSettingsAdsBlocked}"
                  block-option-icon="settings:block">
              </settings-category-default-radio-group>
              <category-setting-exceptions
                  category="[[ContentSettingsTypes.ADS]]"
                  read-only-list
                  allow-header="$i18n{siteSettingsAdsAllowedExceptions}"
                  block-header="$i18n{siteSettingsAdsBlockedExceptions}"
                  search-filter="[[searchFilter_]]">
              </category-setting-exceptions>
            </template>
            <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
              <category-default-setting
                  category="[[ContentSettingsTypes.ADS]]"
                  toggle-off-label="$i18n{siteSettingsAdsBlockRecommended}"
                  toggle-on-label="$i18n{siteSettingsAllowed}">
              </category-default-setting>
              <category-setting-exceptions
                  category="[[ContentSettingsTypes.ADS]]"
                  read-only-list
                  block-header="$i18n{siteSettingsBlock}"
                  allow-header="$i18n{siteSettingsAllow}"
                  search-filter="[[searchFilter_]]">
              </category-setting-exceptions>
            </template>
          </settings-subpage>
       </template>
     </template>
     <template is="dom-if" route-path="/content/unsandboxedPlugins" no-search>
        <settings-subpage page-title="$i18n{siteSettingsUnsandboxedPlugins}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsUnsandboxedPluginsDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.UNSANDBOXED_PLUGINS]]"
                allow-option-label=
                    "$i18n{siteSettingsUnsandboxedPluginsAllowed}"
                allow-option-icon="cr:extension"
                block-option-label=
                    "$i18n{siteSettingsUnsandboxedPluginsBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.UNSANDBOXED_PLUGINS]]"
                allow-header=
                    "$i18n{siteSettingsUnsandboxedPluginsAllowedExceptions}"
                block-header=
                    "$i18n{siteSettingsUnsandboxedPluginsBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsUnsandboxedPluginsBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsUnsandboxedPluginsAskRecommended}"
                category="[[ContentSettingsTypes.UNSANDBOXED_PLUGINS]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.UNSANDBOXED_PLUGINS]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/midiDevices" no-search>
        <settings-subpage page-title="$i18n{siteSettingsMidiDevices}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsMidiDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.MIDI_DEVICES]]"
                allow-option-label=
                    "$i18n{siteSettingsMidiAllowed}"
                allow-option-icon="settings:midi"
                block-option-label="$i18n{siteSettingsMidiBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.MIDI_DEVICES]]" read-only-list
                allow-header="$i18n{siteSettingsMidiAllowedExceptions}"
                block-header="$i18n{siteSettingsMidiBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsMidiDevicesBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsMidiDevicesAskRecommended}"
                category="[[ContentSettingsTypes.MIDI_DEVICES]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.MIDI_DEVICES]]" read-only-list
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/usbDevices" no-search>
        <settings-subpage page-title="$i18n{siteSettingsUsbDevices}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsUsbDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.USB_DEVICES]]"
                allow-option-label="$i18n{siteSettingsUsbAllowed}"
                allow-option-icon="settings:usb"
                block-option-label="$i18n{siteSettingsUsbBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsUsbDevicesBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsUsbDevicesAskRecommended}"
                category="[[ContentSettingsTypes.USB_DEVICES]]">
            </category-default-setting>
          </template>
          <chooser-exception-list
              category="[[ContentSettingsTypes.USB_DEVICES]]"
              chooser-type="[[ChooserType.USB_DEVICES]]">
          </chooser-exception-list>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/serialPorts" no-search>
        <settings-subpage page-title="$i18n{siteSettingsSerialPorts}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsSerialPortsDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.SERIAL_PORTS]]"
                allow-option-label=
                    "$i18n{siteSettingsSerialPortsAllowed}"
                allow-option-icon="settings:serial-port"
                block-option-label="$i18n{siteSettingsSerialPortsBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsSerialPortsBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsSerialPortsAskRecommended}"
                category="[[ContentSettingsTypes.SERIAL_PORTS]]">
            </category-default-setting>
          </template>
          <chooser-exception-list
              category="[[ContentSettingsTypes.SERIAL_PORTS]]"
              chooser-type="[[ChooserType.SERIAL_PORTS]]">
          </chooser-exception-list>
        </settings-subpage>
      </template>
      <template is="dom-if" if="[[enableWebBluetoothNewPermissionsBackend_]]">
        <template is="dom-if" route-path="/content/bluetoothDevices" no-search>
          <settings-subpage page-title="$i18n{siteSettingsBluetoothDevices}">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsBluetoothDevicesBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsBluetoothDevicesAskRecommended}"
                category="[[ContentSettingsTypes.BLUETOOTH_DEVICES]]">
            </category-default-setting>
            <chooser-exception-list
                category="[[ContentSettingsTypes.BLUETOOTH_DEVICES]]"
                chooser-type="[[ChooserType.BLUETOOTH_DEVICES]]">
            </chooser-exception-list>
          </settings-subpage>
        </template>
      </template>
      <template is="dom-if" route-path="/content/filesystem" no-search>
        <settings-subpage
            page-title="$i18n{siteSettingsFileSystemWrite}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsFileSystemWriteDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.FILE_SYSTEM_WRITE]]"
                allow-option-label=
                    "$i18n{siteSettingsFileSystemWriteAllowed}"
                allow-option-icon="settings:save-original"
                block-option-label=
                    "$i18n{siteSettingsFileSystemWriteBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.FILE_SYSTEM_WRITE]]"
                read-only-list
                block-header=
                    "$i18n{siteSettingsFileSystemWriteBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsFileSystemWriteBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsFileSystemWriteAskRecommended}"
                category="[[ContentSettingsTypes.FILE_SYSTEM_WRITE]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.FILE_SYSTEM_WRITE]]"
                read-only-list
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/hidDevices" no-search>
        <settings-subpage page-title="$i18n{siteSettingsHidDevices}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsHidDevicesBlock}"
              toggle-on-label=
                  "$i18n{siteSettingsHidDevicesAskRecommended}"
              category="[[ContentSettingsTypes.HID_DEVICES]]">
          </category-default-setting>
          <chooser-exception-list
              category="[[ContentSettingsTypes.HID_DEVICES]]"
              chooser-type="[[ChooserType.HID_DEVICES]]">
          </chooser-exception-list>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/siteDetails" no-search>
        <settings-subpage page-title="[[pageTitle]]">
          <site-details
            page-title="{{pageTitle}}"
            block-autoplay-enabled="[[blockAutoplayStatus_.pref.value]]">
          </site-details>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/cookies/detail" no-search>
        <settings-subpage page-title="[[pageTitle]]">
          <cr-button slot="subpage-title-extra"
              on-click="onRemoveAllCookiesFromSite_">
            $i18n{siteSettingsCookieRemoveAll}
          </cr-button>
          <site-data-details-subpage page-title="{{pageTitle}}">
          </site-data-details-subpage>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/protectedContent" no-search>
<if expr="not chromeos">
        <settings-subpage page-title="$i18n{siteSettingsProtectedContent}">
</if>
<if expr="chromeos">
        <settings-subpage page-title="$i18n{siteSettingsProtectedContent}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
</if>
          <settings-toggle-button
              pref="{{prefs.webkit.webprefs.encrypted_media_enabled}}"
              label="[[getProtectedContentLabel_(
                  prefs.webkit.webprefs.encrypted_media_enabled.value)]]"
              disabled$="[[isGuest_]]">
          </settings-toggle-button>
<if expr="chromeos or is_win">
          <div class="cr-row first two-line cr-padded-text">
            $i18n{siteSettingsProtectedContentIdentifiersExplanation}
          </div>
          <settings-toggle-button
              pref="{{prefs.settings.privacy.drm_enabled}}"
              label="[[getProtectedContentIdentifiersLabel_(
                  prefs.settings.privacy.drm_enabled.value)]]"
              disabled$="[[isGuest_]]">
          </settings-toggle-button>
</if>
<if expr="chromeos">
          <template is="dom-if"
              if="[[prefs.settings.privacy.drm_enabled.value]]">
            <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
              <category-setting-exceptions
                  category="[[ContentSettingsTypes.PROTECTED_CONTENT]]"
                  allow-header=
                      "$i18n{siteSettingsProtectedContentAllowedExceptions}"
                  block-header=
                      "$i18n{siteSettingsProtectedContentBlockedExceptions}"
                  search-filter="[[searchFilter_]]">
              </category-setting-exceptions>
            </template>
            <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
              <category-setting-exceptions
                  category="[[ContentSettingsTypes.PROTECTED_CONTENT]]"
                  block-header="$i18n{siteSettingsBlock}"
                  allow-header="$i18n{siteSettingsAllow}"
                  search-filter="[[searchFilter_]]">
              </category-setting-exceptions>
            </template>
          </template>
</if>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/clipboard" no-search>
        <settings-subpage page-title="$i18n{siteSettingsClipboard}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsClipboardDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.CLIPBOARD]]"
                allow-option-label="$i18n{siteSettingsClipboardAllowed}"
                allow-option-icon="settings:clipboard"
                block-option-label="$i18n{siteSettingsClipboardBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.CLIPBOARD]]"
                allow-header="$i18n{siteSettingsClipboardAllowedExceptions}"
                block-header="$i18n{siteSettingsClipboardBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsClipboardBlock}"
                toggle-on-label="$i18n{siteSettingsClipboardAskRecommended}"
                category="[[ContentSettingsTypes.CLIPBOARD]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.CLIPBOARD]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" if="[[enablePaymentHandlerContentSetting_]]">
        <template is="dom-if" route-path="/content/paymentHandler" no-search>
          <settings-subpage page-title="$i18n{siteSettingsPaymentHandler}"
              search-label="$i18n{siteSettingsAllSitesSearch}"
              search-term="{{searchFilter_}}">
            <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
              <div class="content-settings-header">
                <h2>$i18n{siteSettingsPaymentHandlersDescription}</h2>
              </div>
              <settings-category-default-radio-group
                  category="[[ContentSettingsTypes.PAYMENT_HANDLER]]"
                  allow-option-label=
                      "$i18n{siteSettingsPaymentHandlersAllowed}"
                  allow-option-icon="settings:payment-handler"
                  block-option-label="$i18n{siteSettingsPaymentHandlersBlocked}"
                  block-option-icon="settings:block">
              </settings-category-default-radio-group>
              <category-setting-exceptions
                  category="[[ContentSettingsTypes.PAYMENT_HANDLER]]"
                  allow-header=
                      "$i18n{siteSettingsPaymentHandlersAllowedExceptions}"
                  block-header=
                      "$i18n{siteSettingsPaymentHandlersBlockedExceptions}"
                  search-filter="[[searchFilter_]]">
              </category-setting-exceptions>
            </template>
            <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
              <category-default-setting
                  toggle-off-label="$i18n{siteSettingsPaymentHandlerBlock}"
                  toggle-on-label=
                      "$i18n{siteSettingsPaymentHandlerAllowRecommended}"
                  category="[[ContentSettingsTypes.PAYMENT_HANDLER]]">
              </category-default-setting>
              <category-setting-exceptions
                  category="[[ContentSettingsTypes.PAYMENT_HANDLER]]"
                  block-header="$i18n{siteSettingsBlocked}"
                  allow-header="$i18n{siteSettingsAllow}"
                  search-filter="[[searchFilter_]]">
              </category-setting-exceptions>
            </template>
          </settings-subpage>
       </template>
      </template>
      <template is="dom-if" if="[[enableExperimentalWebPlatformFeatures_]]">
        <template is="dom-if" route-path="/content/bluetoothScanning" no-search>
          <settings-subpage page-title="$i18n{siteSettingsBluetoothScanning}"
              search-label="$i18n{siteSettingsAllSitesSearch}"
              search-term="{{searchFilter_}}">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsBluetoothScanningBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsBluetoothScanningAskRecommended}"
                category="[[ContentSettingsTypes.BLUETOOTH_SCANNING]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.BLUETOOTH_SCANNING]]"
                read-only-list
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </settings-subpage>
        </template>
      </template>
      <template is="dom-if" route-path="/content/vr" no-search>
        <settings-subpage page-title="$i18n{siteSettingsVr}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsVrDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.VR]]"
                allow-option-label="$i18n{siteSettingsVrAllowed}"
                allow-option-icon="settings:vr-headset"
                block-option-label="$i18n{siteSettingsVrBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.VR]]"
                read-only-list
                allow-header="$i18n{siteSettingsVrAllowedExceptions}"
                block-header="$i18n{siteSettingsVrBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsVrBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsVrAskRecommended}"
                category="[[ContentSettingsTypes.VR]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.VR]]"
                read-only-list
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/ar" no-search>
        <settings-subpage page-title="$i18n{siteSettingsAr}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableContentSettingsRedesign_]]">
            <div class="content-settings-header">
              <h2>$i18n{siteSettingsArDescription}</h2>
            </div>
            <settings-category-default-radio-group
                category="[[ContentSettingsTypes.AR]]"
                allow-option-label="$i18n{siteSettingsArAllowed}"
                allow-option-icon="settings:vr-headset"
                block-option-label="$i18n{siteSettingsArBlocked}"
                block-option-icon="settings:block">
            </settings-category-default-radio-group>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.AR]]"
                read-only-list
                allow-header="$i18n{siteSettingsArAllowedExceptions}"
                block-header="$i18n{siteSettingsArBlockedExceptions}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
          <template is="dom-if" if="[[!enableContentSettingsRedesign_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsArBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsArAskRecommended}"
                category="[[ContentSettingsTypes.AR]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.AR]]"
                read-only-list
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/idleDetection" no-search>
        <settings-subpage page-title="$i18n{siteSettingsIdleDetection}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsIdleDetectionBlock}"
              toggle-on-label="$i18n{siteSettingsIdleDetectionAsk}"
              category="[[ContentSettingsTypes.IDLE_DETECTION]]">
          </category-default-setting>
          <category-setting-exceptions
              category="[[ContentSettingsTypes.IDLE_DETECTION]]"
              block-header="$i18n{siteSettingsBlock}"
              allow-header="$i18n{siteSettingsAllow}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" if="[[enableExperimentalWebPlatformFeatures_]]">
        <template is="dom-if" route-path="/content/windowPlacement" no-search>
          <settings-subpage page-title="$i18n{siteSettingsWindowPlacement}"
              search-label="$i18n{siteSettingsAllSitesSearch}"
              search-term="{{searchFilter_}}">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsWindowPlacementBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsWindowPlacementAskRecommended}"
                category="[[ContentSettingsTypes.WINDOW_PLACEMENT]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.WINDOW_PLACEMENT]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </settings-subpage>
        </template>
      </template>
      <template is="dom-if" if="[[enableFontAccessContentSetting_]]">
        <template is="dom-if" route-path="/content/fontAccess" no-search>
          <settings-subpage page-title="$i18n{fonts}"
              search-label="$i18n{siteSettingsAllSitesSearch}"
              search-term="{{searchFilter_}}">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsFontAccessBlock}"
                toggle-on-label="$i18n{siteSettingsFontAccessAsk}"
                category="[[ContentSettingsTypes.FONT_ACCESS]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.FONT_ACCESS]]"
                block-header="$i18n{siteSettingsBlock}"
                allow-header="$i18n{siteSettingsAllow}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </settings-subpage>
        </template>
      </template>
    </settings-animated-pages>
<!--_html_template_end_-->`,

  behaviors: [
    PrefsBehavior,
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
     * The current sync status, supplied by SyncBrowserProxy.
     * @type {?SyncStatus}
     */
    syncStatus: Object,

    /** @private */
    isGuest_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('isGuest');
      }
    },

    /** @private */
    showClearBrowsingDataDialog_: Boolean,

    /** @private */
    enableSafeBrowsingSubresourceFilter_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('enableSafeBrowsingSubresourceFilter');
      }
    },

    /** @private */
    cookieSettingDescription_: String,

    /** @private */
    enableBlockAutoplayContentSetting_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('enableBlockAutoplayContentSetting');
      }
    },

    /** @private {BlockAutoplayStatus} */
    blockAutoplayStatus_: {
      type: Object,
      value() {
        return /** @type {BlockAutoplayStatus} */ ({});
      }
    },

    /** @private */
    enableContentSettingsRedesign_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('enableContentSettingsRedesign');
      }
    },

    /** @private */
    enablePaymentHandlerContentSetting_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('enablePaymentHandlerContentSetting');
      }
    },

    /** @private */
    enableExperimentalWebPlatformFeatures_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('enableExperimentalWebPlatformFeatures');
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

    /** @private */
    enableFontAccessContentSetting_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('enableFontAccessContentSetting');
      }
    },

    /** @private */
    enableQuietNotificationPromptsSetting_: {
      type: Boolean,
      value: () =>
          loadTimeData.getBoolean('enableQuietNotificationPromptsSetting'),
    },

    /** @private */
    enableWebBluetoothNewPermissionsBackend_: {
      type: Boolean,
      value: () =>
          loadTimeData.getBoolean('enableWebBluetoothNewPermissionsBackend'),
    },

    /** @private {!Map<string, string>} */
    focusConfig_: {
      type: Object,
      value() {
        const map = new Map();

        if (routes.SECURITY) {
          map.set(routes.SECURITY.path, '#securityLinkRow');
        }

        if (routes.COOKIES) {
          map.set(
              `${routes.COOKIES.path}_${routes.PRIVACY.path}`,
              '#cookiesLinkRow');
          map.set(
              `${routes.COOKIES.path}_${routes.BASIC.path}`, '#cookiesLinkRow');
        }

        if (routes.SITE_SETTINGS) {
          map.set(routes.SITE_SETTINGS.path, '#permissionsLinkRow');
        }

        return map;
      },
    },

    /**
     * Expose NotificationSetting enum to HTML bindings.
     * @private
     */
    notificationSettingEnum_: {
      type: Object,
      value: NotificationSetting,
    },

    /** @private */
    searchFilter_: String,

    /** @private */
    siteDataFilter_: String,

    /**
     * Boolean which keeps a track if any of the displayed lists has discarded
     * content setting patterns and hides the warning message accordingly.
     * @private
     */
    pluginsHasDiscardedExceptions_: {
      type: Boolean,
      value: false,
    },
  },

  /** @private {?PrivacyPageBrowserProxy} */
  browserProxy_: null,

  /** @private {?MetricsBrowserProxy} */
  metricsBrowserProxy_: null,

  /** @override */
  ready() {
    this.ContentSettingsTypes = ContentSettingsTypes;
    this.ChooserType = ChooserType;

    this.browserProxy_ = PrivacyPageBrowserProxyImpl.getInstance();
    this.metricsBrowserProxy_ = MetricsBrowserProxyImpl.getInstance();

    this.onBlockAutoplayStatusChanged_({
      pref: /** @type {chrome.settingsPrivate.PrefObject} */ ({value: false}),
      enabled: false
    });

    this.addWebUIListener(
        'onBlockAutoplayStatusChanged',
        this.onBlockAutoplayStatusChanged_.bind(this));

    SyncBrowserProxyImpl.getInstance().getSyncStatus().then(
        this.handleSyncStatus_.bind(this));
    this.addWebUIListener(
        'sync-status-changed', this.handleSyncStatus_.bind(this));

    SiteSettingsPrefsBrowserProxyImpl.getInstance()
        .getCookieSettingDescription()
        .then(description => this.cookieSettingDescription_ = description);
    this.addWebUIListener(
        'cookieSettingDescriptionChanged',
        description => this.cookieSettingDescription_ = description);
  },

  /**
   * Handler for when the sync state is pushed from the browser.
   * @param {?SyncStatus} syncStatus
   * @private
   */
  handleSyncStatus_(syncStatus) {
    this.syncStatus = syncStatus;
  },

  /** @protected */
  currentRouteChanged() {
    this.showClearBrowsingDataDialog_ =
        Router.getInstance().getCurrentRoute() === routes.CLEAR_BROWSER_DATA;
  },

  /**
   * Called when the block autoplay status changes.
   * @param {BlockAutoplayStatus} autoplayStatus
   * @private
   */
  onBlockAutoplayStatusChanged_(autoplayStatus) {
    this.blockAutoplayStatus_ = autoplayStatus;
  },

  /**
   * Updates the block autoplay pref when the toggle is changed.
   * @param {!Event} event
   * @private
   */
  onBlockAutoplayToggleChange_(event) {
    const target = /** @type {!SettingsToggleButtonElement} */ (event.target);
    this.browserProxy_.setBlockAutoplayEnabled(target.checked);
  },

  /**
   * This is a workaround to connect the remove all button to the subpage.
   * @private
   */
  onRemoveAllCookiesFromSite_() {
    const node = /** @type {?SiteDataDetailsSubpageElement} */ (
        this.$$('site-data-details-subpage'));
    if (node) {
      node.removeAll();
    }
  },

  /** @private */
  onClearBrowsingDataTap_() {
    this.tryShowHatsSurvey_();

    Router.getInstance().navigateTo(routes.CLEAR_BROWSER_DATA);
  },

  /** @private */
  onCookiesClick_() {
    this.tryShowHatsSurvey_();

    Router.getInstance().navigateTo(routes.COOKIES);
  },

  /** @private */
  onDialogClosed_() {
    Router.getInstance().navigateTo(assert(routes.CLEAR_BROWSER_DATA.parent));
    focusWithoutInk(assert(this.$$('#clearBrowsingData')));
  },

  /** @private */
  onPermissionsPageClick_() {
    this.tryShowHatsSurvey_();

    Router.getInstance().navigateTo(routes.SITE_SETTINGS);
  },

  /** @private */
  onSecurityPageClick_() {
    this.tryShowHatsSurvey_();
    this.metricsBrowserProxy_.recordAction(
        'SafeBrowsing.Settings.ShowedFromParentSettings');
    Router.getInstance().navigateTo(routes.SECURITY);
  },

  /** @private */
  getProtectedContentLabel_(value) {
    return value ? this.i18n('siteSettingsProtectedContentEnable') :
                   this.i18n('siteSettingsBlocked');
  },

  /** @private */
  getProtectedContentIdentifiersLabel_(value) {
    return value ? this.i18n('siteSettingsProtectedContentEnableIdentifiers') :
                   this.i18n('siteSettingsBlocked');
  },

  /** @private */
  tryShowHatsSurvey_() {
    HatsBrowserProxyImpl.getInstance().tryShowSurvey();
  },
});
