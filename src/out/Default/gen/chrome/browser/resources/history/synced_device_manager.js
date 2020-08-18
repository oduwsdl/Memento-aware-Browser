// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';
import {FocusGrid} from 'chrome://resources/js/cr/ui/focus_grid.m.js';
import 'chrome://resources/polymer/v3_0/iron-list/iron-list.js';
import 'chrome://resources/cr_elements/cr_action_menu/cr_action_menu.m.js';
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_lazy_render/cr_lazy_render.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import {assert} from 'chrome://resources/js/assert.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import './shared_style.js';
import './synced_device_card.js';
import './strings.js';
import {BrowserService} from './browser_service.js';
import {ForeignSession, ForeignSessionTab} from './externs.js';
import {SyncedTabsHistogram, SYNCED_TABS_HISTOGRAM_NAME} from './constants.js';

/**
 * @typedef {{device: string,
 *           lastUpdateTime: string,
 *           opened: boolean,
 *           separatorIndexes: !Array<number>,
 *           timestamp: number,
 *           tabs: !Array<!ForeignSessionTab>,
 *           tag: string}}
 */
let ForeignDeviceInternal;

Polymer({
  is: 'history-synced-device-manager',

  _template: html`<!--_html_template_start_-->
    <style include="shared-style cr-shared-style">
      :host {
        display: block;
        overflow: auto;
      }

      #illustration {
        background: url(images/sign_in_promo.svg) no-repeat center center;
        background-size: contain;
        height: 222px;
        margin-top: 100px;
        width: 594.5px;
      }

      @media (prefers-color-scheme: dark) {
        #illustration {
          background-image: url(images/sign_in_promo_dark.svg);
        }
      }

      #no-synced-tabs {
        height: 100%;
      }

      #sign-in-guide {
        align-items: center;
        display: flex;
        flex-direction: column;
        justify-content: center;
        overflow-x: hidden;
        text-align: center;
      }

      #sign-in-promo {
        font-size: 215%;
        margin-top: 40px;
      }

      #sign-in-promo-desc {
        color: var(--cr-secondary-text-color);
        font-size: 123%;
        margin-top: 10px;
      }

      #sign-in-button {
        margin: 24px 0;
      }

      #synced-device-list {
        padding-top: var(--first-card-padding-top);
      }

      history-synced-device-card {
        margin-block-end: var(--card-padding-between);
      }
    </style>
    <div id="synced-device-list" class="history-cards"
        hidden="[[!syncedDevices_.length]]">
      <template is="dom-repeat" items="[[syncedDevices_]]" as="syncedDevice">
        <history-synced-device-card
            device="[[syncedDevice.device]]"
            last-update-time="[[syncedDevice.lastUpdateTime]]"
            tabs="[[syncedDevice.tabs]]"
            separator-indexes="[[syncedDevice.separatorIndexes]]"
            search-term="[[searchTerm]]"
            session-tag="[[syncedDevice.tag]]"
            opened="{{syncedDevice.opened}}">
        </history-synced-device-card>
      </template>
    </div>
    <div id="no-synced-tabs" class="centered-message"
        hidden="[[!showNoSyncedMessage(signInState, syncedDevices_.length,
                                       guestSession_)]]">
      [[noSyncedTabsMessage(fetchingSyncedTabs_, searchTerm)]]
    </div>
    <div id="sign-in-guide"
        hidden="[[!showSignInGuide(signInState, guestSession_)]]">
      <div id="illustration"></div>
      <div id="sign-in-promo">$i18n{signInPromo}</div>
      <div id="sign-in-promo-desc">$i18n{signInPromoDesc}</div>
      <cr-button id="sign-in-button" class="action-button"
          on-click="onSignInTap_">
        $i18n{signInButton}
      </cr-button>
    </div>

    <cr-lazy-render id="menu">
      <template>
        <cr-action-menu role-description="$i18n{menu}">
          <button id="menuOpenButton" class="dropdown-item"
              on-click="onOpenAllTap_">
            $i18n{openAll}
          </button>
          <button id="menuDeleteButton" class="dropdown-item"
              on-click="onDeleteSessionTap_">
            $i18n{deleteSession}
          </button>
        </cr-action-menu>
      </template>
    </cr-lazy-render>
<!--_html_template_end_-->`,

  properties: {
    /**
     * @type {?Array<!ForeignSession>}
     */
    sessionList: {
      type: Array,
      observer: 'updateSyncedDevices',
    },

    searchTerm: {
      type: String,
      observer: 'searchTermChanged',
    },

    /**
     * An array of synced devices with synced tab data.
     * @type {!Array<!ForeignDeviceInternal>}
     */
    syncedDevices_: {
      type: Array,
      value() {
        return [];
      },
    },

    /** @private */
    signInState: {
      type: Boolean,
      observer: 'signInStateChanged_',
    },

    /** @private */
    guestSession_: {
      type: Boolean,
      value: loadTimeData.getBoolean('isGuestSession'),
    },

    /** @private */
    fetchingSyncedTabs_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    hasSeenForeignData_: Boolean,

    /**
     * The session ID referring to the currently active action menu.
     * @private {?string}
     */
    actionMenuModel_: String,
  },

  listeners: {
    'open-menu': 'onOpenMenu_',
    'update-focus-grid': 'updateFocusGrid_',
  },

  /** @type {?FocusGrid} */
  focusGrid_: null,

  /** @override */
  attached() {
    this.focusGrid_ = new FocusGrid();

    // Update the sign in state.
    BrowserService.getInstance().otherDevicesInitialized();
    BrowserService.getInstance().recordHistogram(
        SYNCED_TABS_HISTOGRAM_NAME, SyncedTabsHistogram.INITIALIZED,
        SyncedTabsHistogram.LIMIT);
  },

  /** @override */
  detached() {
    this.focusGrid_.destroy();
  },

  /** @return {HTMLElement} */
  getContentScrollTarget() {
    return this;
  },

  /**
   * @param {!ForeignSession} session
   * @return {!ForeignDeviceInternal}
   * @private
   */
  createInternalDevice_(session) {
    let tabs = [];
    const separatorIndexes = [];
    for (let i = 0; i < session.windows.length; i++) {
      const windowId = session.windows[i].sessionId;
      const newTabs = session.windows[i].tabs;
      if (newTabs.length === 0) {
        continue;
      }

      newTabs.forEach(function(tab) {
        tab.windowId = windowId;
      });

      let windowAdded = false;
      if (!this.searchTerm) {
        // Add all the tabs if there is no search term.
        tabs = tabs.concat(newTabs);
        windowAdded = true;
      } else {
        const searchText = this.searchTerm.toLowerCase();
        for (let j = 0; j < newTabs.length; j++) {
          const tab = newTabs[j];
          if (tab.title.toLowerCase().indexOf(searchText) !== -1) {
            tabs.push(tab);
            windowAdded = true;
          }
        }
      }
      if (windowAdded && i !== session.windows.length - 1) {
        separatorIndexes.push(tabs.length - 1);
      }
    }
    return {
      device: session.name,
      lastUpdateTime: '– ' + session.modifiedTime,
      opened: true,
      separatorIndexes: separatorIndexes,
      timestamp: session.timestamp,
      tabs: tabs,
      tag: session.tag,
    };
  },

  /** @private */
  onSignInTap_() {
    BrowserService.getInstance().startSignInFlow();
  },

  /** @private */
  onOpenMenu_(e) {
    const menu = /** @type {CrActionMenuElement} */ (this.$.menu.get());
    this.actionMenuModel_ = e.detail.tag;
    menu.showAt(e.detail.target);
    BrowserService.getInstance().recordHistogram(
        SYNCED_TABS_HISTOGRAM_NAME, SyncedTabsHistogram.SHOW_SESSION_MENU,
        SyncedTabsHistogram.LIMIT);
  },

  /** @private */
  onOpenAllTap_() {
    const menu = assert(this.$.menu.getIfExists());
    const browserService = BrowserService.getInstance();
    browserService.recordHistogram(
        SYNCED_TABS_HISTOGRAM_NAME, SyncedTabsHistogram.OPEN_ALL,
        SyncedTabsHistogram.LIMIT);
    browserService.openForeignSessionAllTabs(assert(this.actionMenuModel_));
    this.actionMenuModel_ = null;
    menu.close();
  },

  /** @private */
  updateFocusGrid_() {
    if (!this.focusGrid_) {
      return;
    }

    this.focusGrid_.destroy();

    this.debounce('updateFocusGrid', () => {
      Array.from(this.shadowRoot.querySelectorAll('history-synced-device-card'))
          .reduce((prev, cur) => prev.concat(cur.createFocusRows()), [])
          .forEach((row) => {
            this.focusGrid_.addRow(row);
          });
      this.focusGrid_.ensureRowActive(1);
    });
  },

  /** @private */
  onDeleteSessionTap_() {
    const menu = assert(this.$.menu.getIfExists());
    const browserService = BrowserService.getInstance();
    browserService.recordHistogram(
        SYNCED_TABS_HISTOGRAM_NAME, SyncedTabsHistogram.HIDE_FOR_NOW,
        SyncedTabsHistogram.LIMIT);
    browserService.deleteForeignSession(assert(this.actionMenuModel_));
    this.actionMenuModel_ = null;
    menu.close();
  },

  /** @private */
  clearDisplayedSyncedDevices_() {
    this.syncedDevices_ = [];
  },

  /**
   * Decide whether or not should display no synced tabs message.
   * @param {boolean} signInState
   * @param {number} syncedDevicesLength
   * @param {boolean} guestSession
   * @return {boolean}
   */
  showNoSyncedMessage(
      signInState, syncedDevicesLength, guestSession) {
    if (guestSession) {
      return true;
    }

    return signInState && syncedDevicesLength === 0;
  },

  /**
   * Shows the signin guide when the user is not signed in and not in a guest
   * session.
   * @param {boolean} signInState
   * @param {boolean} guestSession
   * @return {boolean}
   */
  showSignInGuide(signInState, guestSession) {
    const show = !signInState && !guestSession;
    if (show) {
      BrowserService.getInstance().recordAction(
          'Signin_Impression_FromRecentTabs');
    }

    return show;
  },

  /**
   * Decide what message should be displayed when user is logged in and there
   * are no synced tabs.
   * @return {string}
   */
  noSyncedTabsMessage() {
    let stringName = this.fetchingSyncedTabs_ ? 'loading' : 'noSyncedResults';
    if (this.searchTerm !== '') {
      stringName = 'noSearchResults';
    }
    return loadTimeData.getString(stringName);
  },

  /**
   * Replaces the currently displayed synced tabs with |sessionList|. It is
   * common for only a single session within the list to have changed, We try to
   * avoid doing extra work in this case. The logic could be more intelligent
   * about updating individual tabs rather than replacing whole sessions, but
   * this approach seems to have acceptable performance.
   * @param {?Array<!ForeignSession>} sessionList
   */
  updateSyncedDevices(sessionList) {
    this.fetchingSyncedTabs_ = false;

    if (!sessionList) {
      return;
    }

    if (sessionList.length > 0 && !this.hasSeenForeignData_) {
      this.hasSeenForeignData_ = true;
      BrowserService.getInstance().recordHistogram(
          SYNCED_TABS_HISTOGRAM_NAME, SyncedTabsHistogram.HAS_FOREIGN_DATA,
          SyncedTabsHistogram.LIMIT);
    }

    const devices = [];
    sessionList.forEach((session) => {
      const device = this.createInternalDevice_(session);
      if (device.tabs.length !== 0) {
        devices.push(device);
      }
    });

    this.syncedDevices_ = devices;
  },

  /**
   * Get called when user's sign in state changes, this will affect UI of synced
   * tabs page. Sign in promo gets displayed when user is signed out, and
   * different messages are shown when there are no synced tabs.
   * @param {?boolean} current
   * @param {?boolean} previous
   */
  signInStateChanged_(current, previous) {
    if (previous === undefined) {
      return;
    }

    this.fire('history-view-changed');

    // User signed out, clear synced device list and show the sign in promo.
    if (!this.signInState) {
      this.clearDisplayedSyncedDevices_();
      return;
    }
    // User signed in, show the loading message when querying for synced
    // devices.
    this.fetchingSyncedTabs_ = true;
  },

  searchTermChanged(searchTerm) {
    this.clearDisplayedSyncedDevices_();
    this.updateSyncedDevices(this.sessionList);
  }
});
