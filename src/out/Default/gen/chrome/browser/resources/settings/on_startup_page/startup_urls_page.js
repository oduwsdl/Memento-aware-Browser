// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'settings-startup-urls-page' is the settings page
 * containing the urls that will be opened when chrome is started.
 */

import 'chrome://resources/js/action_link.js';
import 'chrome://resources/cr_elements/action_link_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import 'chrome://resources/polymer/v3_0/iron-list/iron-list.js';
import '../controls/extension_controlled_indicator.m.js';
import '../settings_shared_css.m.js';
import './startup_url_dialog.js';

import {CrScrollableBehavior} from 'chrome://resources/cr_elements/cr_scrollable_behavior.m.js';
import {assert} from 'chrome://resources/js/assert.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {EDIT_STARTUP_URL_EVENT} from './startup_url_entry.js';
import {StartupPageInfo, StartupUrlsPageBrowserProxy, StartupUrlsPageBrowserProxyImpl} from './startup_urls_page_browser_proxy.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="settings-shared action-link iron-flex">
      #editOptions > div {
        border-top: var(--cr-separator-line);
      }

      #outer {
        max-height: 355px;  /** Enough height to show six entries. */
      }

      #container settings-startup-url-entry {
        cursor: default;
      }
    </style>
    <div id="outer" class="layout vertical flex list-frame">
      <div id="container" class="scroll-container" scrollable>
        <iron-list items="[[startupPages_]]" scroll-target="container"
            preserve-focus risk-selection class="cr-separators">
          <template>
            <settings-startup-url-entry model="[[item]]" first$="[[!index]]"
                tabindex$="[[tabIndex]]" iron-list-tab-index="[[tabIndex]]"
                last-focused="{{lastFocused_}}" list-blurred="{{listBlurred_}}"
                focus-row-index="[[index]]" editable="[[shouldAllowUrlsEdit_(
                    prefs.session.startup_urls.enforcement)]]">
            </settings-startup-url-entry>
          </template>
        </iron-list>
      </div>
    </div>
    <div id="editOptions" class="list-frame">
      <template is="dom-if" if="[[shouldAllowUrlsEdit_(
          prefs.session.startup_urls.enforcement)]]" restamp>
        <div class="list-item" id="addPage">
          <a is="action-link" class="list-button" on-click="onAddPageTap_">
            $i18n{onStartupAddNewPage}
          </a>
        </div>
        <div class="list-item" id="useCurrentPages">
          <a is="action-link" class="list-button"
              on-click="onUseCurrentPagesTap_">
            $i18n{onStartupUseCurrent}
          </a>
        </div>
      </template>
      <template is="dom-if" if="[[prefs.session.startup_urls.extensionId]]"
          restamp>
        <extension-controlled-indicator
            extension-id="[[prefs.session.startup_urls.extensionId]]"
            extension-name="[[prefs.session.startup_urls.controlledByName]]"
            extension-can-be-disabled="[[
                prefs.session.startup_urls.extensionCanBeDisabled]]">
        </extension-controlled-indicator>
      </template>
    </div>
    <template is="dom-if" if="[[showStartupUrlDialog_]]" restamp>
      <settings-startup-url-dialog model="[[startupUrlDialogModel_]]"
          on-close="destroyUrlDialog_">
      </settings-startup-url-dialog>
    </template>
<!--_html_template_end_-->`,
  is: 'settings-startup-urls-page',

  behaviors: [CrScrollableBehavior, WebUIListenerBehavior],

  properties: {
    prefs: Object,

    /**
     * Pages to load upon browser startup.
     * @private {!Array<!StartupPageInfo>}
     */
    startupPages_: Array,

    /** @private */
    showStartupUrlDialog_: Boolean,

    /** @private {?StartupPageInfo} */
    startupUrlDialogModel_: Object,

    /** @private {Object}*/
    lastFocused_: Object,

    /** @private */
    listBlurred_: Boolean,
  },

  /** @private {?StartupUrlsPageBrowserProxy} */
  browserProxy_: null,

  /**
   * The element to return focus to, when the startup-url-dialog is closed.
   * @private {?HTMLElement}
   */
  startupUrlDialogAnchor_: null,

  /** @override */
  attached() {
    this.browserProxy_ = StartupUrlsPageBrowserProxyImpl.getInstance();
    this.addWebUIListener('update-startup-pages', startupPages => {
      // If an "edit" URL dialog was open, close it, because the underlying page
      // might have just been removed (and model indices have changed anyway).
      if (this.startupUrlDialogModel_) {
        this.destroyUrlDialog_();
      }
      this.startupPages_ = startupPages;
      this.updateScrollableContents();
    });
    this.browserProxy_.loadStartupPages();

    this.addEventListener(EDIT_STARTUP_URL_EVENT, event => {
      this.startupUrlDialogModel_ = event.detail.model;
      this.startupUrlDialogAnchor_ = event.detail.anchor;
      this.showStartupUrlDialog_ = true;
      event.stopPropagation();
    });
  },

  /**
   * @param {!Event} e
   * @private
   */
  onAddPageTap_(e) {
    e.preventDefault();
    this.showStartupUrlDialog_ = true;
    this.startupUrlDialogAnchor_ =
        /** @type {!HTMLElement} */ (this.$$('#addPage a[is=action-link]'));
  },

  /** @private */
  destroyUrlDialog_() {
    this.showStartupUrlDialog_ = false;
    this.startupUrlDialogModel_ = null;
    if (this.startupUrlDialogAnchor_) {
      focusWithoutInk(assert(this.startupUrlDialogAnchor_));
      this.startupUrlDialogAnchor_ = null;
    }
  },

  /** @private */
  onUseCurrentPagesTap_() {
    this.browserProxy_.useCurrentPages();
  },

  /**
   * @return {boolean} Whether "Add new page" and "Use current pages" are
   *     allowed.
   * @private
   */
  shouldAllowUrlsEdit_() {
    return this.get('prefs.session.startup_urls.enforcement') !=
        chrome.settingsPrivate.Enforcement.ENFORCED;
  },
});
