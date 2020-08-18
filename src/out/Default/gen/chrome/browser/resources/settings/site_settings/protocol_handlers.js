// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'protocol-handlers' is the polymer element for showing the
 * protocol handlers category under Site Settings.
 */

import 'chrome://resources/cr_elements/cr_action_menu/cr_action_menu.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_link_row/cr_link_row.m.js';
import 'chrome://resources/cr_elements/cr_toggle/cr_toggle.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import '../settings_shared_css.m.js';
import '../site_favicon.js';

import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';

// <if expr="chromeos">
import {AndroidAppsInfo, AndroidInfoBrowserProxyImpl} from './android_info_browser_proxy.js';
// </if>
import {SiteSettingsBehavior} from './site_settings_behavior.js';

/**
 * All possible actions in the menu.
 * @enum {string}
 */
const MenuActions = {
  SET_DEFAULT: 'SetDefault',
  REMOVE: 'Remove',
};

/**
 * @typedef {{host: string,
 *            is_default: boolean,
 *            protocol: string,
 *            protocol_display_name: string,
 *            spec: string}}
 */
export let HandlerEntry;

/**
 * @typedef {{handlers: !Array<!HandlerEntry>,
 *            protocol: string,
 *            protocol_display_name: string}}
 */
export let ProtocolEntry;

Polymer({
  is: 'protocol-handlers',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared iron-flex">
      :host {
        display: block;
      }

      .column-header {
        margin-bottom: 15px;
        margin-inline-start: 20px;
        margin-top: 15px;
      }
    </style>
    <div class="cr-row first two-line">
      <div id="categoryLabel" class="flex" on-click="categoryLabelClicked_"
          actionable>
        [[computeHandlersDescription_(categoryEnabled)]]
      </div>
      <cr-toggle id="toggle" checked="{{categoryEnabled}}"
          on-change="onToggleChange_" aria-labelledby="categoryLabel">
      </cr-toggle>
    </div>

    <template is="dom-repeat" items="[[protocols]]" as="protocol">
      <div class="column-header">[[protocol.protocol_display_name]]</div>

      <div class="list-frame menu-content vertical-list">
        <template is="dom-repeat" items="[[protocol.handlers]]">

          <div class="list-item">
            <site-favicon url="[[item.host]]"></site-favicon>
            <div class="middle" >
              <div class="protocol-host">
                <span class="url-directionality">[[item.host]]</span>
              </div>
              <div class="secondary protocol-default"
                  hidden$="[[!item.is_default]]">
                $i18n{handlerIsDefault}
              </div>
            </div>

            <cr-icon-button class="icon-more-vert" on-click="showMenu_"
                title="$i18n{moreActions}"></cr-icon-button>
          </div>
        </template>
      </div>
    </template>

    <cr-action-menu role-description="$i18n{menu}">
      <button class="dropdown-item" on-click="onDefaultClick_"
          id="defaultButton" hidden$="[[actionMenuModel_.is_default]]">
        $i18n{handlerSetDefault}
      </button>
      <button class="dropdown-item" on-click="onRemoveClick_"
          id="removeButton">
        $i18n{handlerRemove}
      </button>
    </cr-action-menu>

    <template is="dom-if" if="[[ignoredProtocols.length]]">
      <div class="column-header">$i18n{siteSettingsBlocked}</div>
      <div class="list-frame menu-content vertical-list">
        <template is="dom-repeat" items="[[ignoredProtocols]]">
          <div class="list-item">
            <site-favicon url="[[item.host]]"></site-favicon>
            <div class="middle" >
              <div class="protocol-host">
                <span class="url-directionality">[[item.host]]</span></div>
              <div class="secondary protocol-protocol">
                [[item.protocol_display_name]]
              </div>
            </div>
            <cr-icon-button class="icon-clear" id="removeIgnoredButton"
                on-click="onRemoveIgnored_" title="$i18n{handlerRemove}">
            </cr-icon-button>
          </div>
        </template>
      </div>
    </template>

<if expr="chromeos">
  <template is="dom-if" if="[[settingsAppAvailable_]]">
    <cr-link-row on-click="onManageAndroidAppsClick_"
        label="$i18n{androidAppsManageAppLinks}" external></cr-link-row>
  </template>
</if>
<!--_html_template_end_-->`,

  behaviors: [SiteSettingsBehavior, WebUIListenerBehavior],

  properties: {
    /**
     * Represents the state of the main toggle shown for the category.
     */
    categoryEnabled: Boolean,

    /**
     * Array of protocols and their handlers.
     * @type {!Array<!ProtocolEntry>}
     */
    protocols: Array,

    /**
     * The targetted object for menu operations.
     * @private {?HandlerEntry}
     */
    actionMenuModel_: Object,

    /* Labels for the toggle on/off positions. */
    toggleOffLabel: String,
    toggleOnLabel: String,

    /**
     * Array of ignored (blocked) protocols.
     * @type {!Array<!HandlerEntry>}
     */
    ignoredProtocols: Array,

    // <if expr="chromeos">
    /** @private */
    settingsAppAvailable_: {
      type: Boolean,
      value: false,
    },
    // </if>
  },

  /** @override */
  ready() {
    this.addWebUIListener(
        'setHandlersEnabled', this.setHandlersEnabled_.bind(this));
    this.addWebUIListener(
        'setProtocolHandlers', this.setProtocolHandlers_.bind(this));
    this.addWebUIListener(
        'setIgnoredProtocolHandlers',
        this.setIgnoredProtocolHandlers_.bind(this));
    this.browserProxy.observeProtocolHandlers();
  },

  // <if expr="chromeos">
  /** @override */
  attached() {
    this.addWebUIListener(
        'android-apps-info-update', this.androidAppsInfoUpdate_.bind(this));
    AndroidInfoBrowserProxyImpl.getInstance().requestAndroidAppsInfo();
  },
  // </if>

  // <if expr="chromeos">
  /**
   * Receives updates on whether or not ARC settings app is available.
   * @param {AndroidAppsInfo} info
   * @private
   */
  androidAppsInfoUpdate_(info) {
    this.settingsAppAvailable_ = info.settingsAppAvailable;
  },
  // </if>

  /** @private */
  categoryLabelClicked_() {
    this.$.toggle.click();
  },

  /**
   * Obtains the description for the main toggle.
   * @return {string} The description to use.
   * @private
   */
  computeHandlersDescription_() {
    return this.categoryEnabled ? this.toggleOnLabel : this.toggleOffLabel;
  },

  /**
   * Updates the main toggle to set it enabled/disabled.
   * @param {boolean} enabled The state to set.
   * @private
   */
  setHandlersEnabled_(enabled) {
    this.categoryEnabled = enabled;
  },

  /**
   * Updates the list of protocol handlers.
   * @param {!Array<!ProtocolEntry>} protocols The new protocol handler list.
   * @private
   */
  setProtocolHandlers_(protocols) {
    this.protocols = protocols;
  },

  /**
   * Updates the list of ignored protocol handlers.
   * @param {!Array<!HandlerEntry>} ignoredProtocols The new (ignored) protocol
   *     handler list.
   * @private
   */
  setIgnoredProtocolHandlers_(ignoredProtocols) {
    this.ignoredProtocols = ignoredProtocols;
  },

  /**
   * Closes action menu and resets action menu model
   * @private
   */
  closeActionMenu_() {
    this.$$('cr-action-menu').close();
    this.actionMenuModel_ = null;
  },

  /**
   * A handler when the toggle is flipped.
   * @private
   */
  onToggleChange_(event) {
    this.browserProxy.setProtocolHandlerDefault(this.categoryEnabled);
  },

  /**
   * The handler for when "Set Default" is selected in the action menu.
   * @private
   */
  onDefaultClick_() {
    const item = this.actionMenuModel_;
    this.browserProxy.setProtocolDefault(item.protocol, item.spec);
    this.closeActionMenu_();
  },

  /**
   * The handler for when "Remove" is selected in the action menu.
   * @private
   */
  onRemoveClick_() {
    const item = this.actionMenuModel_;
    this.browserProxy.removeProtocolHandler(item.protocol, item.spec);
    this.closeActionMenu_();
  },

  /**
   * Handler for removing handlers that were blocked
   * @private
   */
  onRemoveIgnored_(event) {
    const item = event.model.item;
    this.browserProxy.removeProtocolHandler(item.protocol, item.spec);
  },

  /**
   * A handler to show the action menu next to the clicked menu button.
   * @param {!{model: !{item: HandlerEntry}}} event
   * @private
   */
  showMenu_(event) {
    this.actionMenuModel_ = event.model.item;
    /** @type {!CrActionMenuElement} */ (this.$$('cr-action-menu'))
        .showAt(
            /** @type {!Element} */ (/** @type {!Event} */ (event).target));
  },

  // <if expr="chromeos">
  /**
   * Opens an activity to handle App links (preferred apps).
   * @private
   */
  onManageAndroidAppsClick_() {
    this.browserProxy.showAndroidManageAppLinks();
  },
  // </if>
});
