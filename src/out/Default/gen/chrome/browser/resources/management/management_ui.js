// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/cr_elements/cr_page_host_style_css.m.js';
import 'chrome://resources/cr_elements/cr_toolbar/cr_toolbar.m.js';
import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import './icons.js';
import './strings.m.js';

import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {BrowserReportingResponse, Extension, ManagementBrowserProxy, ManagementBrowserProxyImpl, ReportingType, ThreatProtectionInfo} from './management_browser_proxy.js';
// <if expr="chromeos">
import {DeviceReportingResponse, DeviceReportingType} from './management_browser_proxy.js';
// </if>

/**
 * @typedef {{
 *   messageIds: !Array<string>,
 *   icon: string,
 * }}
 */
let BrowserReportingData;

Polymer({
  is: 'management-ui',

  _template: html`<!--_html_template_start_-->

    <style include="cr-icons cr-hidden-style cr-page-host-style
        cr-shared-style">
      :host {
        color: var(--cr-secondary-text-color);
        display: flex;
        flex-direction: column;
        height: 100%;
      }

      a {
        color: var(--cr-link-color);
        text-decoration: none;
      }

      cr-toolbar {
        flex-shrink: 0;
      }

      main {
        height: 100%;
        overflow: overlay;
      }

      .card {
        background-color: var(--cr-card-background-color);
        box-shadow: var(--cr-card-shadow);
        margin: 0 3px;
        min-height: 100%;
      }

      .page-subtitle {
        align-items: center;
        box-sizing: border-box;
        flex-direction: row;
        justify-content: start;
        min-height: 73px;
        padding-bottom: 24px;
        padding-top: 6px;
      }

      .page-subtitle cr-icon-button {
        margin-inline-end: 10px;
        margin-inline-start: -10px;
      }

      .overview-section div + div {
        margin-top: 16px;
      }

      .overview-container img {
        float: left;
        margin-inline-end: 10px;
        vertical-align: top;
        width: 20%;
      }

      .overview-container div {
        display: block;
        overflow: hidden;
        width: auto;
      }

      .overview-messages {
        margin-top: 0;
      }

      .overview-messages li {
        margin-top: 8px;
      }

      th {
        font-weight: 500;
      }

      .subtitle {
        margin-top: 16px;
      }

      section {
        align-items: flex-start;
        display: flex;
        flex-direction: column;
        justify-content: center;
        min-height: var(--cr-section-min-height);
        padding: 12px var(--cr-section-padding);
      }

      section:not(.page-subtitle) h2 {
        font-size: 100%;
        margin: 0;
      }

      .report iron-icon {
        height: 20px;
        margin-inline-end: 16px;
        width: 20px;
      }

      .report {
        align-items: start;
        display: flex;
        margin-top: 16px;
      }

      .content-indented {
        padding-inline-start: 24px;
      }

      table {
        border-spacing: 0 16px;
        box-sizing: border-box;
        width: 100%;
      }

      th,
      td {
        text-align: start;
      }

      td > div {
        align-items: center;
        display: flex;
      }

      .extension-name,
      .protection-name {
        width: 40%;
      }

      .extension-name span {
        max-width: 200px;
        overflow: hidden;
        text-overflow: ellipsis;
        white-space: nowrap;
      }

      .extension-permissions,
      .protection-permissions {
        width: 60%;
      }

      .protection-name,
      .protection-permissions {
        vertical-align: top;
      }

      .extension-name img {
        height: 20px;
        margin-inline-end: 12px;
        width: 20px;
      }

      .extension-permissions ul,
      .report ul {
        list-style: none;
        margin: 0;
        padding: 0;
      }
    </style>

    <cr-toolbar page-name="$i18n{toolbarTitle}" role="banner"
        on-search-changed="onSearchChanged_" clear-label="$i18n{clearSearch}"
        search-prompt="$i18n{searchPrompt}">
    </cr-toolbar>
    <main id="mainContent">
      <div class="cr-centered-card-container">
        <div class="card">
          <section hidden="[[!managed_]]" class="page-subtitle">
            <cr-icon-button class="icon-arrow-back" id="closeButton"
                on-click="onTapBack_" aria-label="$i18n{backButton}">
            </cr-icon-button>
            <h2 class="cr-title-text">
              [[subtitle_]]
            </h2>
          </section>
          <section class="overview-section" hidden="[[!managementOverview_]]">
<if expr="not chromeos">
            <div inner-h-t-m-l="[[managementNoticeHtml_]]"></div>
</if>
<if expr="chromeos">
            <div class="overview-container">
              <img src="[[customerLogo_]]" alt="" aria-hidden="true"
                  hidden="[[!customerLogo_]]">
              <div>[[managementOverview_]]</div>
            </div>
</if>
          </section>
          <template is="dom-if"
              if="[[showThreatProtectionInfo_(threatProtectionInfo_)]]">
            <section>
              <h2 class="cr-title-text">$i18n{threatProtectionTitle}</h2>
              <div class="subtitle">
                [[threatProtectionInfo_.description]]
              </div>
              <table class="content-indented">
                <tr>
                  <th class="protection-name">$i18n{extensionName}</th>
                  <th class="protection-permissions">
                    $i18n{extensionPermissions}
                  </th>
                </tr>
                <template is="dom-repeat"
                    items="[[threatProtectionInfo_.info]]">
                  <tr>
                    <td class="protection-name">[[i18n(item.title)]]</td>
                    <td class="protection-permissions">
                      [[i18n(item.permission)]]
                    </td>
                  </tr>
                </template>
              </table>
            </section>
          </template>

<if expr="chromeos">
          <div hidden="[[!localTrustRoots_]]">
            <section>
              <h2 class="cr-title-text">$i18n{localTrustRoots}</h2>
              <div class="subtitle" id="trust-roots-configuration">
                [[localTrustRoots_]]</div>
            </section>
          </div>
          <template is="dom-if"
              if="[[showDeviceReportingInfo_(deviceReportingInfo_)]]">
            <section>
              <h2 class="cr-title-text">$i18n{deviceReporting}</h2>
              <div class="subtitle">
                $i18n{deviceConfiguration}
              </div>
              <div class="content-indented">
                <template is="dom-repeat" items="[[deviceReportingInfo_]]">
                  <div class="report">
                    <iron-icon icon="[[getIconForDeviceReportingType_(
                        item.reportingType)]]"></iron-icon>
                    [[i18n(item.messageId)]]
                  </div>
                </template>
              </div>
            </section>
          </template>
</if>
<if expr="not chromeos">
          <template is="dom-if"
              if="[[showBrowserReportingInfo_(browserReportingInfo_)]]">
            <section>
              <h2 class="cr-title-text">$i18n{browserReporting}</h2>
              <div class="subtitle">
                $i18n{browserReportingExplanation}
              </div>
              <div>
                <template is="dom-repeat" items="[[browserReportingInfo_]]">
                  <div class="report">
                    <iron-icon icon="[[item.icon]]"></iron-icon>
                    <ul>
                      <template is="dom-repeat" items="[[item.messageIds]]"
                          as="messageId">
                        <li inner-h-t-m-l="[[i18nAdvanced(messageId)]]"></li>
                      </template>
                    </ul>
                  </div>
                </template>
              </div>
            </section>
          </template>
</if>
          <template is="dom-if"
              if="[[showExtensionReportingInfo_(extensions_)]]">
            <section class="extension-reporting">
              <h2 class="cr-title-text">$i18n{extensionReporting}</h2>
              <div class="subtitle">
                [[extensionReportingSubtitle_]]
              </div>
              <table class="content-indented">
                <tr>
                  <th class="extension-name">$i18n{extensionName}</th>
                  <th class="extension-permissions">
                    $i18n{extensionPermissions}
                  </th>
                </tr>
                <template is="dom-repeat" items="[[extensions_]]">
                  <tr>
                    <td class="extension-name">
                      <div title="[[item.name]]" role="presentation">
                        <img src="[[item.icon]]" alt="" aria-hidden="true">
                        <span>[[item.name]]</span>
                      </div>
                    </td>
                    <td class="extension-permissions">
                      <ul>
                        <template is="dom-repeat" items="[[item.permissions]]"
                            as="permission">
                          <li>[[permission]]</li>
                        </template>
                      </ul>
                    </td>
                  </tr>
                </template>
              </table>
            </section>
          </template>
        </div>
      </div>
    </main>
<!--_html_template_end_-->`,

  behaviors: [
    I18nBehavior,
    WebUIListenerBehavior,
  ],

  properties: {
    /**
     * List of messages related to browser reporting.
     * @private {?Array<!BrowserReportingData>}
     */
    browserReportingInfo_: Array,

    /**
     * List of messages related to browser reporting.
     * @private {?Array<!Extension>}
     */
    extensions_: Array,

    // <if expr="chromeos">
    /**
     * List of messages related to device reporting.
     * @private {?Array<!DeviceReportingResponse>}
     */
    deviceReportingInfo_: Array,

    /**
     * Message stating if the Trust Roots are configured.
     * @private
     */
    localTrustRoots_: String,

    /** @private */
    customerLogo_: String,

    /** @private */
    managementOverview_: String,

    // </if>

    /** @private */
    subtitle_: String,

    // <if expr="not chromeos">
    /** @private */
    managementNoticeHtml_: String,
    // </if>

    /** @private */
    managed_: Boolean,

    /** @private */
    extensionReportingSubtitle_: String,

    /** @private {!ThreatProtectionInfo} */
    threatProtectionInfo_: Object,
  },

  /** @private {?ManagementBrowserProxy} */
  browserProxy_: null,

  /** @override */
  attached() {
    document.documentElement.classList.remove('loading');
    this.browserProxy_ = ManagementBrowserProxyImpl.getInstance();
    this.updateManagedFields_();
    this.initBrowserReportingInfo_();
    this.getThreatProtectionInfo_();

    this.addWebUIListener(
        'browser-reporting-info-updated',
        reportingInfo => this.onBrowserReportingInfoReceived_(reportingInfo));

    this.addWebUIListener('managed_data_changed', () => {
      this.updateManagedFields_();
    });

    this.addWebUIListener(
        'threat-protection-info-updated',
        info => this.threatProtectionInfo_ = info);

    this.getExtensions_();
    // <if expr="chromeos">
    this.getDeviceReportingInfo_();
    this.getLocalTrustRootsInfo_();
    // </if>
  },

  /** @private */
  initBrowserReportingInfo_() {
    this.browserProxy_.initBrowserReportingInfo().then(
        reportingInfo => this.onBrowserReportingInfoReceived_(reportingInfo));
  },

  /**
   * @param {!Array<!BrowserReportingResponse>} reportingInfo
   * @private
   */
  onBrowserReportingInfoReceived_(reportingInfo) {
    const reportingInfoMap = reportingInfo.reduce((info, response) => {
      info[response.reportingType] = info[response.reportingType] || {
        icon: this.getIconForReportingType_(response.reportingType),
        messageIds: []
      };
      info[response.reportingType].messageIds.push(response.messageId);
      return info;
    }, {});

    const reportingTypeOrder = {
      [ReportingType.SECURITY]: 1,
      [ReportingType.EXTENSIONS]: 2,
      [ReportingType.USER]: 3,
      [ReportingType.USER_ACTIVITY]: 4,
      [ReportingType.DEVICE]: 5,
    };

    this.browserReportingInfo_ =
        Object.keys(reportingInfoMap)
            .sort((a, b) => reportingTypeOrder[a] - reportingTypeOrder[b])
            .map(reportingType => reportingInfoMap[reportingType]);
  },

  /** @private */
  getExtensions_() {
    this.browserProxy_.getExtensions().then(extensions => {
      this.extensions_ = extensions;
    });
  },

  /** @private */
  getThreatProtectionInfo_() {
    this.browserProxy_.getThreatProtectionInfo().then(info => {
      this.threatProtectionInfo_ = info;
    });
  },

  /**
   * @return {boolean} True if there is threat protection info to show.
   * @private
   */
  showThreatProtectionInfo_() {
    return !!this.threatProtectionInfo_ &&
        this.threatProtectionInfo_.info.length > 0;
  },

  // <if expr="chromeos">
  /** @private */
  getLocalTrustRootsInfo_() {
    this.browserProxy_.getLocalTrustRootsInfo().then(trustRootsConfigured => {
      this.localTrustRoots_ = trustRootsConfigured ?
          loadTimeData.getString('managementTrustRootsConfigured') :
          '';
    });
  },

  /** @private */
  getDeviceReportingInfo_() {
    this.browserProxy_.getDeviceReportingInfo().then(reportingInfo => {
      this.deviceReportingInfo_ = reportingInfo;
    });
  },

  /**
   * @return {boolean} True of there are device reporting info to show.
   * @private
   */
  showDeviceReportingInfo_() {
    return !!this.deviceReportingInfo_ && this.deviceReportingInfo_.length > 0;
  },

  /**
   * @param {DeviceReportingType} reportingType
   * @return {string} The associated icon.
   * @private
   */
  getIconForDeviceReportingType_(reportingType) {
    switch (reportingType) {
      case DeviceReportingType.SUPERVISED_USER:
        return 'management:supervised-user';
      case DeviceReportingType.DEVICE_ACTIVITY:
        return 'management:timelapse';
      case DeviceReportingType.STATISTIC:
        return 'management:bar-chart';
      case DeviceReportingType.DEVICE:
        return 'cr:computer';
      case DeviceReportingType.CRASH_REPORT:
        return 'management:crash';
      case DeviceReportingType.LOGS:
        return 'management:report';
      case DeviceReportingType.PRINT:
        return 'cr:print';
      case DeviceReportingType.CROSTINI:
        return 'management:linux';
      case DeviceReportingType.USERNAME:
        return 'management:account-circle';
      case DeviceReportingType.EXTENSION:
        return 'cr:extension';
      case DeviceReportingType.ANDROID_APPLICATION:
        return 'management:play-store';
      case DeviceReportingType.PROXY_SERVER:
        return 'management:vpn-lock';
      default:
        return 'cr:computer';
    }
  },
  // </if>

  /**
   * @return {boolean} True of there are browser reporting info to show.
   * @private
   */
  showBrowserReportingInfo_() {
    return !!this.browserReportingInfo_ &&
        this.browserReportingInfo_.length > 0;
  },

  /**
   * @return {boolean} True of there are extension reporting info to show.
   * @private
   */
  showExtensionReportingInfo_() {
    return !!this.extensions_ && this.extensions_.length > 0;
  },

  /**
   * @param {ReportingType} reportingType
   * @returns {string} The associated icon.
   * @private
   */
  getIconForReportingType_(reportingType) {
    switch (reportingType) {
      case ReportingType.SECURITY:
        return 'cr:security';
      case ReportingType.DEVICE:
        return 'cr:computer';
      case ReportingType.EXTENSIONS:
        return 'cr:extension';
      case ReportingType.USER:
        return 'management:account-circle';
      case ReportingType.USER_ACTIVITY:
        return 'management:public';
      default:
        return 'cr:security';
    }
  },

  /**
   * Handles the 'search-changed' event fired from the toolbar.
   * Redirects to the settings page initialized the the current
   * search query.
   * @param {!CustomEvent<string>} e
   * @private
   */
  onSearchChanged_(e) {
    const query = e.detail;
    window.location.href =
        `chrome://settings?search=${encodeURIComponent(query)}`;
  },

  /** @private */
  onTapBack_() {
    if (history.length > 1) {
      history.back();
    } else {
      window.location.href = 'chrome://settings/help';
    }
  },

  /** @private */
  updateManagedFields_() {
    this.browserProxy_.getContextualManagedData().then(data => {
      this.managed_ = data.managed;
      this.extensionReportingSubtitle_ = data.extensionReportingTitle;
      this.subtitle_ = data.pageSubtitle;
      // <if expr="chromeos">
      this.customerLogo_ = data.customerLogo;
      this.managementOverview_ = data.overview;
      // </if>
      // <if expr="not chromeos">
      this.managementNoticeHtml_ = data.browserManagementNotice;
      // </if>
    });
  },
});
