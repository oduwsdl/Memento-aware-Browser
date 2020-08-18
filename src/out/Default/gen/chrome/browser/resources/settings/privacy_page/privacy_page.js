// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'settings-privacy-page' is the settings page containing privacy and
 * security settings.
 */
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_expand_button/cr_expand_button.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_link_row/cr_link_row.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-collapse/iron-collapse.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import './do_not_track_toggle.js';
import './secure_dns.js';
import './passwords_leak_detection_toggle.js';
import '../controls/settings_toggle_button.m.js';
import '../prefs/prefs.m.js';
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
import {PrivacyPageVisibility} from '../page_visibility.js';
import {SyncBrowserProxyImpl, SyncStatus} from '../people_page/sync_browser_proxy.m.js';
import {PrefsBehavior} from '../prefs/prefs_behavior.m.js';
import {routes} from '../route.js';
import {RouteObserverBehavior, Router} from '../router.m.js';
import {ChooserType, ContentSettingsTypes, CookieControlsMode} from '../site_settings/constants.js';
import {SiteSettingsPrefsBrowserProxyImpl} from '../site_settings/site_settings_prefs_browser_proxy.js';

import {PrivacyPageBrowserProxy, PrivacyPageBrowserProxyImpl} from './privacy_page_browser_proxy.m.js';

/**
 * @typedef {{
 *   enabled: boolean,
 *   pref: !chrome.settingsPrivate.PrefObject
 * }}
 */
let BlockAutoplayStatus;

/**
 * Must be kept in sync with the C++ enum of the same name.
 * @enum {number}
 */
const NetworkPredictionOptions = {
  ALWAYS: 0,
  WIFI_ONLY: 1,
  NEVER: 2,
  DEFAULT: 1,
};

Polymer({
  is: 'settings-privacy-page',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared iron-flex">
      .iron-collapse-indented {
        margin-inline-start: var(--cr-section-indent-width);
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
        <template is="dom-if" if="[[!privacySettingsRedesignEnabled_]]" restamp>
          <cr-link-row id="clearBrowsingData"
              class="hr"
              label="$i18n{clearBrowsingData}"
              sub-label="$i18n{clearBrowsingDataDescription}"
              on-click="onClearBrowsingDataTap_"></cr-link-row>
          <cr-link-row id="site-settings-subpage-trigger"
              class="hr"
              label="$i18n{siteSettings}"
              sub-label="$i18n{siteSettingsDescription}"
              on-click="onSiteSettingsTap_"></cr-link-row>
          <cr-expand-button id="moreExpansion"
              alt="$i18n{privacyPageMore}"
              class="cr-row"
              expanded="{{moreOpened_}}">
              <div>$i18n{privacyPageMore}</div>
          </cr-expand-button>
          <iron-collapse id="moreCollapse" opened="[[moreOpened_]]"
              class="iron-collapse-indented">
            <settings-toggle-button id="safeBrowsingToggle"
                pref="{{prefs.safebrowsing.enabled}}"
                label="$i18n{safeBrowsingEnableProtection}"
                sub-label="$i18n{safeBrowsingEnableProtectionDesc}"
                on-settings-boolean-control-change=
                    "onSafeBrowsingToggleChange_">
            </settings-toggle-button>
            <settings-passwords-leak-detection-toggle
                id="passwordsLeakDetectionToggle"
                prefs="{{prefs}}"
                sync-status="[[syncStatus]]">
            </settings-passwords-leak-detection-toggle>
            <settings-toggle-button id="safeBrowsingReportingToggle"
                class="hr"
                pref="[[safeBrowsingReportingPref_]]" no-set-pref
                label="$i18n{safeBrowsingEnableExtendedReporting}"
                sub-label="$i18n{safeBrowsingEnableExtendedReportingDesc}"
                disabled="[[getDisabledExtendedSafeBrowsing_(prefs.*)]]"
                on-settings-boolean-control-change=
                    "onSafeBrowsingReportingToggleChange_">
            </settings-toggle-button>
            <settings-do-not-track-toggle id="doNotTrack" prefs="{{prefs}}">
            </settings-do-not-track-toggle>
            <settings-toggle-button id="canMakePaymentToggle"
                class="hr"
                aria-label="$i18n{canMakePaymentToggleLabel}"
                label="$i18n{canMakePaymentToggleLabel}"
                pref="{{prefs.payments.can_make_payment_enabled}}"
                on-settings-boolean-control-change="onCanMakePaymentChange_">
            </settings-toggle-button>
            <settings-toggle-button class="hr"
                hidden="[[!pageVisibility.networkPrediction]]"
                pref="{{prefs.net.network_prediction_options}}"
                label="$i18n{networkPredictionEnabled}"
                sub-label="$i18n{networkPredictionEnabledDesc}"
                numeric-unchecked-value="[[networkPredictionUncheckedValue_]]"
                on-settings-boolean-control-change="onNetworkPredictionChange_">
            </settings-toggle-button>
            <template is="dom-if" if="[[showSecureDnsSetting_]]">
              <settings-secure-dns prefs="{{prefs}}"></settings-secure-dns>
            </template>
<if expr="use_nss_certs or is_win or is_macosx">
            <cr-link-row id="manageCertificates"
                class="hr"
<if expr="not use_nss_certs">
                external
</if>
                label="$i18n{manageCertificates}"
                sub-label="$i18n{manageCertificatesDescription}"
                on-click="onManageCertificatesTap_"></cr-link-row>
</if>
            <template is="dom-if" if="[[enableSecurityKeysSubpage_]]">
              <cr-link-row id="security-keys-subpage-trigger"
                class="hr"
                label="$i18n{securityKeysTitle}"
                sub-label="$i18n{securityKeysDesc}"
                on-click="onSecurityKeysTap_"></cr-link-row>
            </template>
          </iron-collapse>
        </template>
        <template is="dom-if" if="[[privacySettingsRedesignEnabled_]]" restamp>
          <cr-link-row id="clearBrowsingData"
              class="hr" start-icon="cr:delete"
              label="$i18n{clearBrowsingData}"
              sub-label="$i18n{clearBrowsingDataDescription}"
              on-click="onClearBrowsingDataTap_"></cr-link-row>
          <cr-link-row id="cookiesLinkRow" start-icon="settings:cookie"
              class="hr" label="$i18n{cookiePageTitle}"
              sub-label="[[cookieSettingDescription_]]"
              on-click="onCookiesClick_"></cr-link-row>
          <cr-link-row id="securityLinkRow" start-icon="cr:security"
              class="hr" label="$i18n{securityPageTitle}"
              sub-label="$i18n{securityPageDescription}"
              on-click="onSecurityPageClick_"></cr-link-row>
          <cr-link-row id="permissionsLinkRow" start-icon="settings:permissions"
              class="hr" label="$i18n{siteSettings}"
              sub-label="$i18n{permissionsPageDescription}"
              on-click="onPermissionsPageClick_"></cr-link-row>
        </template>
      </div>

<if expr="use_nss_certs">
      <template is="dom-if" route-path="/certificates">
        <settings-subpage
            associated-control="[[getControlForCertificatesSubpage_(
                privacySettingsRedesignEnabled_)]]"
            page-title="$i18n{manageCertificates}">
          <certificate-manager></certificate-manager>
        </settings-subpage>
      </template>
</if>

      <template is="dom-if" if="[[enableSecurityKeysSubpage_]]">
        <template is="dom-if" route-path="/securityKeys">
          <settings-subpage
              associated-control="[[getControlForSecurityKeysSubpage_(
                  privacySettingsRedesignEnabled_)]]"
              page-title="$i18n{securityKeysTitle}">
            <security-keys-subpage></security-keys-subpage>
          </settings-subpage>
        </template>
      </template>

      <template is="dom-if" route-path="/content">
        <settings-subpage
            associated-control="[[getControlForSiteSettingsSubpage_(
                privacySettingsRedesignEnabled_)]]"
            id="site-settings"
            page-title="$i18n{siteSettings}"
            learn-more-url="$i18n{exceptionsLearnMoreURL}">
          <settings-site-settings-page focus-config="[[focusConfig_]]">
          </settings-site-settings-page>
        </settings-subpage>
      </template>

      <template is="dom-if" route-path="/security"
          no-search="[[!privacySettingsRedesignEnabled_]]">
        <settings-subpage id="security" page-title="$i18n{securityPageTitle}"
            no-search$="[[!privacySettingsRedesignEnabled_]]"
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
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsAutoDownloadBlock}"
              toggle-on-label="$i18n{siteSettingsAutoDownloadAskRecommended}"
              category="{{ContentSettingsTypes.AUTOMATIC_DOWNLOADS}}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.AUTOMATIC_DOWNLOADS}}"
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/backgroundSync" no-search>
        <settings-subpage page-title="$i18n{siteSettingsBackgroundSync}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsBackgroundSyncBlocked}"
              toggle-on-label=
                  "$i18n{siteSettingsAllowRecentlyClosedSitesRecommended}"
              category="{{ContentSettingsTypes.BACKGROUND_SYNC}}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.BACKGROUND_SYNC}}"
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/camera" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryCamera}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <media-picker label="$i18n{siteSettingsCameraLabel}" type="camera">
          </media-picker>
          <category-default-setting category="{{ContentSettingsTypes.CAMERA}}"
              toggle-off-label="$i18n{siteSettingsBlocked}"
              toggle-on-label=
                  "$i18n{siteSettingsAskBeforeAccessingRecommended}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.CAMERA}}" read-only-list
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/cookies"
          no-search="[[!privacySettingsRedesignEnabled_]]">
        <settings-subpage id="cookies" page-title="$i18n{cookiePageTitle}"
            learn-more-url="$i18n{cookiesSettingsHelpCenterURL}"
            no-search$="[[!privacySettingsRedesignEnabled_]]"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}"
            associated-control="[[$$('#cookiesLinkRow')]]">
          <settings-cookies-page prefs="{{prefs}}"
              focus-config="[[focusConfig_]]"
              search-term="[[searchFilter_]]">
          </settings-cookies-page>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/cookies" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryCookies}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting category="{{ContentSettingsTypes.COOKIES}}"
              toggle-off-label="$i18n{siteSettingsBlocked}"
              toggle-on-label="$i18n{siteSettingsCookiesAllowedRecommended}"
              sub-option-label="$i18n{deleteDataPostSession}"
              sub-option-mode="cookies-session-only">
          </category-default-setting>
          <settings-toggle-button
              id="blockThirdPartyCookies"
              class="hr"
              pref="{{prefs.profile.block_third_party_cookies}}"
              label="$i18n{thirdPartyCookie}"
              sub-label="$i18n{thirdPartyCookieSublabel}"
              on-settings-boolean-control-change=
                  "onBlockThirdPartyCookiesToggleChange_"
              no-set-pref>
          </settings-toggle-button>
          <cr-link-row id="site-data-trigger" class="hr"
              on-click="onSiteDataTap_" label="$i18n{siteSettingsCookieLink}">
          </cr-link-row>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.COOKIES}}"
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
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
          <category-default-setting category="{{ContentSettingsTypes.IMAGES}}"
              toggle-off-label="$i18n{siteSettingsDontShowImages}"
              toggle-on-label="$i18n{siteSettingsShowAllRecommended}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.IMAGES}}"
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" if="[[enableInsecureContentContentSetting_]]">
        <template is="dom-if" route-path="/content/insecureContent" no-search>
          <settings-subpage
              page-title="$i18n{siteSettingsCategoryInsecureContent}"
              search-label="$i18n{siteSettingsAllSitesSearch}"
              search-term="{{searchFilter_}}">
            <div class="cr-row first">
              $i18n{siteSettingsInsecureContentBlock}
            </div>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.MIXEDSCRIPT]]"
                block-header="$i18n{siteSettingsBlock}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </settings-subpage>
        </template>
      </template>
      <template is="dom-if" route-path="/content/location" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryLocation}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsBlocked}"
              toggle-on-label="$i18n{siteSettingsAskBeforeAccessingRecommended}"
              category="{{ContentSettingsTypes.GEOLOCATION}}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.GEOLOCATION}}" read-only-list
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
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
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsBlocked}"
              toggle-on-label="$i18n{siteSettingsAllowedRecommended}"
              category="{{ContentSettingsTypes.JAVASCRIPT}}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.JAVASCRIPT}}"
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/sound" no-search>
        <settings-subpage page-title="$i18n{siteSettingsSound}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsSoundBlock}"
              toggle-on-label="$i18n{siteSettingsSoundAllowRecommended}"
              category="{{ContentSettingsTypes.SOUND}}">
          </category-default-setting>
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
          <category-setting-exceptions
              category="{{ContentSettingsTypes.SOUND}}"
              block-header="$i18n{siteSettingsBlockSound}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/microphone" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryMicrophone}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <media-picker label="$i18n{siteSettingsMicrophoneLabel}" type="mic">
          </media-picker>
          <category-default-setting category="{{ContentSettingsTypes.MIC}}"
              toggle-off-label="$i18n{siteSettingsBlocked}"
              toggle-on-label=
                  "$i18n{siteSettingsAskBeforeAccessingRecommended}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.MIC}}" read-only-list
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/sensors" no-search>
        <settings-subpage page-title="$i18n{siteSettingsSensors}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsSensorsBlock}"
              toggle-on-label="$i18n{siteSettingsSensorsAllow}"
              category="{{ContentSettingsTypes.SENSORS}}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.SENSORS}}" read-only-list
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
     </template>
      <template is="dom-if" route-path="/content/notifications" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryNotifications}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <template is="dom-if" if="[[enableQuietNotificationPromptsSetting_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsNotificationsAsk}"
                toggle-on-label="$i18n{siteSettingsNotificationsAsk}"
                category="{{ContentSettingsTypes.NOTIFICATIONS}}"
                sub-option-pref="{{prefs.profile.content_settings.enable_quiet_permission_ui.notifications}}"
                sub-option-label=
                    "$i18n{siteSettingsEnableQuietNotificationPrompts}"
                sub-option-mode="pref">
            </category-default-setting>
          </template>
          <template is="dom-if" if="[[!enableQuietNotificationPromptsSetting_]]">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsCategoryNotifications}"
                toggle-on-label="$i18n{siteSettingsCategoryNotifications}"
                toggle-off-description="$i18n{siteSettingsNotificationsBlock}"
                toggle-on-description="$i18n{siteSettingsNotificationsAsk}"
                category="{{ContentSettingsTypes.NOTIFICATIONS}}"
                sub-option-mode="none">
            </category-default-setting>
          </template>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.NOTIFICATIONS}}"
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/flash" no-search>
        <settings-subpage page-title="$i18n{siteSettingsFlash}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <a class="cr-row first no-outline" tabindex="-1"
              target="_blank">
            $i18n{siteSettingsFlashPermissionsEphemeral}
          </a>
          <category-default-setting category="{{ContentSettingsTypes.PLUGINS}}"
              toggle-off-label="$i18n{siteSettingsFlashBlockRecommended}"
              toggle-on-label="$i18n{siteSettingsFlashAskFirst}">
          </category-default-setting>
<if expr="chromeos">
          <a class="cr-row inherit-color no-outline" tabindex="-1"
              target="_blank"
              href="https://www.macromedia.com/support/documentation/en/flashplayer/help/settings_manager07.html">
            <div class="flex">$i18n{adobeFlashStorage}</div>
            <cr-icon-button class="icon-external"
                aria-label="$i18n{adobeFlashStorage}"></cr-icon-button>
          </a>
</if>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.PLUGINS}}"
              block-header="$i18n{siteSettingsBlock}" read-only-list
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/popups" no-search>
        <settings-subpage page-title="$i18n{siteSettingsCategoryPopups}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting category="{{ContentSettingsTypes.POPUPS}}"
              toggle-off-label="$i18n{siteSettingsBlockedRecommended}"
              toggle-on-label="$i18n{siteSettingsAllowed}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.POPUPS}}"
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" if="[[enableSafeBrowsingSubresourceFilter_]]"
          no-search>
        <template is="dom-if" route-path="/content/ads" no-search>
          <settings-subpage page-title="$i18n{siteSettingsAds}"
              search-label="$i18n{siteSettingsAllSitesSearch}"
              search-term="{{searchFilter_}}">
            <category-default-setting
                category="{{ContentSettingsTypes.ADS}}"
                toggle-off-label="$i18n{siteSettingsAdsBlockRecommended}"
                toggle-on-label="$i18n{siteSettingsAllowed}">
            </category-default-setting>
            <category-setting-exceptions
                category="{{ContentSettingsTypes.ADS}}"
                read-only-list
                block-header="$i18n{siteSettingsBlock}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </settings-subpage>
       </template>
     </template>
     <template is="dom-if" route-path="/content/unsandboxedPlugins" no-search>
        <settings-subpage page-title="$i18n{siteSettingsUnsandboxedPlugins}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsUnsandboxedPluginsBlock}"
              toggle-on-label=
                  "$i18n{siteSettingsUnsandboxedPluginsAskRecommended}"
              category="{{ContentSettingsTypes.UNSANDBOXED_PLUGINS}}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.UNSANDBOXED_PLUGINS}}"
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/midiDevices" no-search>
        <settings-subpage page-title="$i18n{siteSettingsMidiDevices}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsMidiDevicesBlock}"
              toggle-on-label=
                  "$i18n{siteSettingsMidiDevicesAskRecommended}"
              category="{{ContentSettingsTypes.MIDI_DEVICES}}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.MIDI_DEVICES}}" read-only-list
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/usbDevices" no-search>
        <settings-subpage page-title="$i18n{siteSettingsUsbDevices}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsUsbDevicesBlock}"
              toggle-on-label=
                  "$i18n{siteSettingsUsbDevicesAskRecommended}"
              category="{{ContentSettingsTypes.USB_DEVICES}}">
          </category-default-setting>
          <chooser-exception-list
              category="{{ContentSettingsTypes.USB_DEVICES}}"
              chooser-type="{{ChooserType.USB_DEVICES}}">
          </chooser-exception-list>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/serialPorts" no-search>
        <settings-subpage page-title="$i18n{siteSettingsSerialPorts}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsSerialPortsBlock}"
              toggle-on-label=
                  "$i18n{siteSettingsSerialPortsAskRecommended}"
              category="{{ContentSettingsTypes.SERIAL_PORTS}}">
          </category-default-setting>
          <chooser-exception-list
              category="{{ContentSettingsTypes.SERIAL_PORTS}}"
              chooser-type="{{ChooserType.SERIAL_PORTS}}">
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
                category="{{ContentSettingsTypes.BLUETOOTH_DEVICES}}">
            </category-default-setting>
            <chooser-exception-list
                category="{{ContentSettingsTypes.BLUETOOTH_DEVICES}}"
                chooser-type="{{ChooserType.BLUETOOTH_DEVICES}}">
            </chooser-exception-list>
          </settings-subpage>
        </template>
      </template>
      <template is="dom-if" if="[[enableNativeFileSystemWriteContentSetting_]]">
        <template is="dom-if" route-path="/content/filesystem" no-search>
          <settings-subpage
              page-title="$i18n{siteSettingsNativeFileSystemWrite}">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsNativeFileSystemWriteBlock}"
                toggle-on-label=
                    "$i18n{siteSettingsNativeFileSystemWriteAskRecommended}"
                category="{{ContentSettingsTypes.NATIVE_FILE_SYSTEM_WRITE}}">
            </category-default-setting>
            <category-setting-exceptions
                category="{{ContentSettingsTypes.NATIVE_FILE_SYSTEM_WRITE}}"
                read-only-list
                block-header="$i18n{siteSettingsBlock}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </settings-subpage>
        </template>
      </template>
      <template is="dom-if" if="[[enableExperimentalWebPlatformFeatures_]]">
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
            <category-setting-exceptions
                category="{{ContentSettingsTypes.PROTECTED_CONTENT}}"
                block-header="$i18n{siteSettingsBlock}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </template>
</if>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/clipboard" no-search>
        <settings-subpage page-title="$i18n{siteSettingsClipboard}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsClipboardBlock}"
              toggle-on-label="$i18n{siteSettingsClipboardAskRecommended}"
              category="{{ContentSettingsTypes.CLIPBOARD}}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.CLIPBOARD}}"
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" if="[[enablePaymentHandlerContentSetting_]]">
        <template is="dom-if" route-path="/content/paymentHandler" no-search>
          <settings-subpage page-title="$i18n{siteSettingsPaymentHandler}"
              search-label="$i18n{siteSettingsAllSitesSearch}"
              search-term="{{searchFilter_}}">
            <category-default-setting
                toggle-off-label="$i18n{siteSettingsPaymentHandlerBlock}"
                toggle-on-label="$i18n{siteSettingsPaymentHandlerAllowRecommended}"
                category="[[ContentSettingsTypes.PAYMENT_HANDLER]]">
            </category-default-setting>
            <category-setting-exceptions
                category="[[ContentSettingsTypes.PAYMENT_HANDLER]]"
                block-header="$i18n{siteSettingsBlocked}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
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
                category="{{ContentSettingsTypes.BLUETOOTH_SCANNING}}">
            </category-default-setting>
            <category-setting-exceptions
                category="{{ContentSettingsTypes.BLUETOOTH_SCANNING}}"
                read-only-list
                block-header="$i18n{siteSettingsBlock}"
                search-filter="[[searchFilter_]]">
            </category-setting-exceptions>
          </settings-subpage>
        </template>
      </template>
      <template is="dom-if" route-path="/content/vr" no-search>
        <settings-subpage page-title="$i18n{siteSettingsVr}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsVrBlock}"
              toggle-on-label=
                  "$i18n{siteSettingsVrAskRecommended}"
              category="{{ContentSettingsTypes.VR}}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.VR}}"
              read-only-list
              block-header="$i18n{siteSettingsBlock}"
              search-filter="[[searchFilter_]]">
          </category-setting-exceptions>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/content/ar" no-search>
        <settings-subpage page-title="$i18n{siteSettingsAr}"
            search-label="$i18n{siteSettingsAllSitesSearch}"
            search-term="{{searchFilter_}}">
          <category-default-setting
              toggle-off-label="$i18n{siteSettingsArBlock}"
              toggle-on-label=
                  "$i18n{siteSettingsArAskRecommended}"
              category="{{ContentSettingsTypes.AR}}">
          </category-default-setting>
          <category-setting-exceptions
              category="{{ContentSettingsTypes.AR}}"
              read-only-list
              block-header="$i18n{siteSettingsBlock}"
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
                toggle-on-label="$i18n{siteSettingsWindowPlacementAsk}"
                category="{{ContentSettingsTypes.WINDOW_PLACEMENT}}">
            </category-default-setting>
            <category-setting-exceptions
                category="{{ContentSettingsTypes.WINDOW_PLACEMENT}}"
                block-header="$i18n{siteSettingsBlock}"
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

    /**
     * Dictionary defining page visibility.
     * @type {!PrivacyPageVisibility}
     */
    pageVisibility: Object,

    /** @private {chrome.settingsPrivate.PrefObject} */
    safeBrowsingReportingPref_: {
      type: Object,
      value() {
        return /** @type {chrome.settingsPrivate.PrefObject} */ ({
          key: '',
          type: chrome.settingsPrivate.PrefType.BOOLEAN,
          value: false,
        });
      },
    },

    /** @private */
    isGuest_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('isGuest');
      }
    },

    /** @private */
    showClearBrowsingDataDialog_: Boolean,

    /**
     * Used for HTML bindings. This is defined as a property rather than
     * within the ready callback, because the value needs to be available
     * before local DOM initialization - otherwise, the toggle has unexpected
     * behavior.
     * @private
     */
    networkPredictionUncheckedValue_: {
      type: Number,
      value: NetworkPredictionOptions.NEVER,
    },

    /** @private */
    enableSafeBrowsingSubresourceFilter_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('enableSafeBrowsingSubresourceFilter');
      }
    },

    /** @private */
    privacySettingsRedesignEnabled_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('privacySettingsRedesignEnabled');
      },
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
     * Whether the more settings list is opened.
     * @private
     */
    moreOpened_: {
      type: Boolean,
      value: false,
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
    enableInsecureContentContentSetting_: {
      type: Boolean,
      value() {
        return loadTimeData.getBoolean('enableInsecureContentContentSetting');
      }
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

        if (this.privacySettingsRedesignEnabled_) {
          if (routes.SECURITY) {
            map.set(routes.SECURITY.path, '#securityLinkRow');
          }

          if (routes.COOKIES) {
            map.set(
                `${routes.COOKIES.path}_${routes.PRIVACY.path}`,
                '#cookiesLinkRow');
            map.set(
                `${routes.COOKIES.path}_${routes.BASIC.path}`,
                '#cookiesLinkRow');
          }

          if (routes.SITE_SETTINGS) {
            map.set(routes.SITE_SETTINGS.path, '#permissionsLinkRow');
          }
        } else {
          // <if expr="use_nss_certs">
          if (routes.CERTIFICATES) {
            map.set(routes.CERTIFICATES.path, '#manageCertificates');
          }
          // </if>
          if (routes.SITE_SETTINGS) {
            map.set(
                routes.SITE_SETTINGS.path, '#site-settings-subpage-trigger');
          }

          if (routes.SITE_SETTINGS_SITE_DATA) {
            map.set(routes.SITE_SETTINGS_SITE_DATA.path, '#site-data-trigger');
          }

          if (routes.SECURITY_KEYS) {
            map.set(
                routes.SECURITY_KEYS.path, '#security-keys-subpage-trigger');
          }
        }

        return map;
      },
    },

    /** @private */
    searchFilter_: String,

    /** @private */
    siteDataFilter_: String,
  },

  observers: [
    'onSafeBrowsingReportingPrefChange_(prefs.safebrowsing.*)',
  ],

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
   * @return {Element}
   * @private
   */
  getControlForSiteSettingsSubpage_() {
    return this.$$(
        this.privacySettingsRedesignEnabled_ ?
            '#permissionsLinkRow' :
            '#site-settings-subpage-trigger');
  },

  /**
   * @return {Element}
   * @private
   */
  getControlForCertificatesSubpage_() {
    return this.$$(
        this.privacySettingsRedesignEnabled_ ? '#securityLinkRow' :
                                               '#manageCertificates');
  },

  /**
   * @return {Element}
   * @private
   */
  getControlForSecurityKeysSubpage_() {
    return this.$$(
        this.privacySettingsRedesignEnabled_ ?
            '#securityLinkRow' :
            '#security-keys-subpage-trigger');
  },

  /**
   * @return {boolean}
   * @private
   */
  getDisabledExtendedSafeBrowsing_() {
    return !this.getPref('safebrowsing.enabled').value;
  },

  /** @private */
  onSafeBrowsingReportingToggleChange_() {
    this.metricsBrowserProxy_.recordSettingsPageHistogram(
        PrivacyElementInteractions.IMPROVE_SECURITY);
    this.setPrefValue(
        'safebrowsing.scout_reporting_enabled',
        this.$$('#safeBrowsingReportingToggle').checked);
  },

  /** @private */
  onSafeBrowsingReportingPrefChange_() {
    if (this.prefs === undefined) {
      return;
    }
    const safeBrowsingScoutPref =
        this.getPref('safebrowsing.scout_reporting_enabled');
    const prefValue = !!this.getPref('safebrowsing.enabled').value &&
        !!safeBrowsingScoutPref.value;
    this.safeBrowsingReportingPref_ = {
      key: '',
      type: chrome.settingsPrivate.PrefType.BOOLEAN,
      value: prefValue,
      enforcement: safeBrowsingScoutPref.enforcement,
      controlledBy: safeBrowsingScoutPref.controlledBy,
    };
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
   * Updates both required block third party cookie preferences.
   * @param {!Event} event
   * @private
   */
  onBlockThirdPartyCookiesToggleChange_(event) {
    const target = /** @type {!SettingsToggleButtonElement} */ (event.target);
    this.setPrefValue('profile.block_third_party_cookies', target.checked);
    this.setPrefValue(
        'profile.cookie_controls_mode',
        target.checked ? CookieControlsMode.BLOCK_THIRD_PARTY :
                         CookieControlsMode.OFF);
  },

  /**
   * Records changes made to the "can a website check if you have saved
   * payment methods" setting for logging, the logic of actually changing the
   * setting is taken care of by the webUI pref.
   * @private
   */
  onCanMakePaymentChange_() {
    this.metricsBrowserProxy_.recordSettingsPageHistogram(
        PrivacyElementInteractions.PAYMENT_METHOD);
  },

  /** @private */
  onManageCertificatesTap_() {
    this.metricsBrowserProxy_.recordSettingsPageHistogram(
        PrivacyElementInteractions.MANAGE_CERTIFICATES);
    // <if expr="use_nss_certs">
    Router.getInstance().navigateTo(routes.CERTIFICATES);
    // </if>
    // <if expr="is_win or is_macosx">
    this.browserProxy_.showManageSSLCertificates();
    // </if>
  },

  /**
   * Records changes made to the network prediction setting for logging, the
   * logic of actually changing the setting is taken care of by the webUI
   * pref.
   * @private
   */
  onNetworkPredictionChange_() {
    this.metricsBrowserProxy_.recordSettingsPageHistogram(
        PrivacyElementInteractions.NETWORK_PREDICTION);
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
  onSiteDataTap_() {
    Router.getInstance().navigateTo(routes.SITE_SETTINGS_SITE_DATA);
  },

  /** @private */
  onSiteSettingsTap_() {
    Router.getInstance().navigateTo(routes.SITE_SETTINGS);
  },

  /** @private */
  onSafeBrowsingToggleChange_: function() {
    this.metricsBrowserProxy_.recordSettingsPageHistogram(
        PrivacyElementInteractions.SAFE_BROWSING);
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
  onSecurityKeysTap_() {
    Router.getInstance().navigateTo(routes.SECURITY_KEYS);
  },

  /** @private */
  onSecurityPageClick_() {
    this.tryShowHatsSurvey_();

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
