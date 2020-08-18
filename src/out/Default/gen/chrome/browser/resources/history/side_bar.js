// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';
import 'chrome://resources/cr_components/managed_footnote/managed_footnote.m.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {IronA11yKeysBehavior} from 'chrome://resources/polymer/v3_0/iron-a11y-keys-behavior/iron-a11y-keys-behavior.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import 'chrome://resources/polymer/v3_0/iron-selector/iron-selector.js';
import 'chrome://resources/polymer/v3_0/paper-ripple/paper-ripple.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import 'chrome://resources/polymer/v3_0/paper-styles/typography.js';
import {BrowserService} from './browser_service.js';
import './shared_style.js';
import './strings.js';

/**
 * @typedef {{
 *   managed: boolean,
 *   otherFormsOfHistory: boolean,
 * }}
 */
export let FooterInfo;

Polymer({
  is: 'history-side-bar',

  _template: html`<!--_html_template_start_-->
    <style include="shared-style cr-icons">
      :host {
        display: flex;
        height: 100%;
        overflow-x: hidden;
        overflow-y: auto;
        width: var(--side-bar-width);
      }

      div.separator {
        background-color: var(--separator-color);
        flex-shrink: 0;
        height: 1px;
        margin: 8px 0;
      }

      #clear-browsing-data {
        justify-content: space-between;
      }

      #clear-browsing-data .cr-icon {
        margin-inline-end: 20px;
      }

      iron-selector {
        background-color: transparent;
        color: var(--sidebar-unselected-color);
        display: flex;
        flex: 1;
        flex-direction: column;
        padding-top: 8px;
        user-select: none;
      }

      iron-selector > a {
        /* Ensure the focus outline appears correctly (crbug.com/655503). */
        align-items: center;
        box-sizing: border-box;
        color: inherit;
        cursor: pointer;
        display: flex;
        font-weight: 500;
        margin: 0 4px;
        min-height: 40px;
        padding-inline-start: 24px;
        position: relative;
        text-decoration: none;
      }

      iron-selector > a.iron-selected {
        color: var(--cr-link-color);
      }

      iron-selector > a[disabled] {
        opacity: 0.65;
        pointer-events: none;
      }

      #spacer {
        flex: 1;
      }

      #footer {
        color: var(--sidebar-footer-text-color);
        width: var(--side-bar-width);
      }

      managed-footnote {
        --managed-footnote-icon-padding: 12px;
        border: none;
        margin: 24px 0;
        padding-inline-end: 16px;
        padding-inline-start: 24px;
      }

      #google-account-footer {
        display: flex;
        margin: 24px 0;
        padding-inline-end: 16px;
        padding-inline-start: 24px;
      }

      #google-account-footer iron-icon {
        align-self: flex-start;
        flex-shrink: 0;
        height: 20px;
        padding-inline-end: 12px;
        width: 20px;
      }

      #google-account-footer > div {
        /* At large font sizes, prevents the text from wrapping weirdly. */
        overflow-x: hidden;
      }
    </style>

    <iron-selector id="menu" selected="{{selectedPage}}"
        selectable=".page-item" attr-for-selected="path"
        on-iron-activate="onSelectorActivate_">
      <a href="/" class="page-item" path="history" on-click="onItemClick_">
        $i18n{historyMenuItem}
        <paper-ripple></paper-ripple>
      </a>
      <a href="/syncedTabs" class="page-item" path="syncedTabs"
          on-click="onItemClick_">
        $i18n{openTabsMenuItem}
        <paper-ripple></paper-ripple>
      </a>
      <div class="separator"></div>
      <a id="clear-browsing-data"
          href="chrome://settings/clearBrowserData"
          on-click="onClearBrowsingDataTap_"
          disabled$="[[guestSession_]]"
          tabindex$="[[computeClearBrowsingDataTabIndex_(guestSession_)]]">
        $i18n{clearBrowsingData}
        <div class="cr-icon icon-external"></div>
        <paper-ripple id="cbd-ripple"></paper-ripple>
      </a>
      <div id="spacer"></div>
      <div id="footer" hidden="[[!showFooter_]]">
        <div class="separator"></div>
        <managed-footnote></managed-footnote>
        <div id="google-account-footer"
             hidden="[[!footerInfo.otherFormsOfHistory]]">
          <iron-icon icon="cr:info-outline"></iron-icon>
          <div>$i18nRaw{sidebarFooter}</div>
        </div>
      </div>
    </iron-selector>
<!--_html_template_end_-->`,

  behaviors: [IronA11yKeysBehavior],

  properties: {
    selectedPage: {
      type: String,
      notify: true,
    },

    /** @private */
    guestSession_: {
      type: Boolean,
      value: loadTimeData.getBoolean('isGuestSession'),
    },

    /** @type {FooterInfo} */
    footerInfo: Object,

    /**
     * Used to display notices for profile sign-in status and managed status.
     * @private
     */
    showFooter_: {
      type: Boolean,
      computed: 'computeShowFooter_(' +
          'footerInfo.otherFormsOfHistory, footerInfo.managed)',
    },
  },

  keyBindings: {
    'space:keydown': 'onSpacePressed_',
  },

  /**
   * @param {!CustomEvent<{keyboardEvent: !KeyboardEvent}>} e
   * @private
   */
  onSpacePressed_(e) {
    e.detail.keyboardEvent.path[0].click();
  },

  /**
   * @private
   */
  onSelectorActivate_() {
    this.fire('history-close-drawer');
  },

  /**
   * Relocates the user to the clear browsing data section of the settings page.
   * @param {Event} e
   * @private
   */
  onClearBrowsingDataTap_(e) {
    const browserService = BrowserService.getInstance();
    browserService.recordAction('InitClearBrowsingData');
    browserService.openClearBrowsingData();
    /** @type {PaperRippleElement} */ (this.$['cbd-ripple']).upAction();
    e.preventDefault();
  },

  /**
   * @return {string}
   * @private
   */
  computeClearBrowsingDataTabIndex_() {
    return this.guestSession_ ? '-1' : '';
  },

  /**
   * Prevent clicks on sidebar items from navigating. These are only links for
   * accessibility purposes, taps are handled separately by <iron-selector>.
   * @private
   */
  onItemClick_(e) {
    e.preventDefault();
  },

  /**
   * @return {boolean}
   * @private
   */
  computeShowFooter_(includeOtherFormsOfBrowsingHistory, managed) {
    return includeOtherFormsOfBrowsingHistory || managed;
  },
});
