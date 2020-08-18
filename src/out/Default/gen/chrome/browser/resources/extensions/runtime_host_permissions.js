// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_action_menu/cr_action_menu.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_radio_group/cr_radio_group.m.js';
import 'chrome://resources/cr_elements/cr_radio_button/cr_radio_button.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/js/action_link.js';
import 'chrome://resources/cr_elements/action_link_css.m.js';
import 'chrome://resources/cr_elements/md_select_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import './runtime_hosts_dialog.js';
import './shared_style.js';
import './strings.m.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {ItemDelegate} from './item.js';

Polymer({
  is: 'extensions-runtime-host-permissions',

  _template: html`<!--_html_template_start_-->
<style include="cr-shared-style action-link md-select shared-style">
  iron-icon {
    --iron-icon-height: var(--cr-icon-size);
    --iron-icon-width: var(--cr-icon-size);
  }

  #section-heading {
    align-items: center;
    display: flex;
    justify-content: space-between;
  }

  #host-access {
    margin-inline-start: 20px;
    width: 100%;
  }

  #hosts {
    margin-bottom: 0;
    padding: 0;
  }

  #hosts li {
    align-items: center;
    border-bottom: var(--cr-separator-line);
    display: flex;
    height: var(--cr-section-min-height);
    justify-content: space-between;
  }

  #hosts li:last-child {
    border-bottom: none;
  }

  #add-host {
    font-weight: 500;
    width: 100%;
  }

  #permissions-mode {
    color: var(--cr-primary-text-color);
    margin-top: 12px;
  }

  cr-radio-button.multi-row {
    align-items: normal;
  }

  cr-icon-button {
    margin: 0;
  }
</style>
<div id="permissions-mode">
  <div id="section-heading">
    <span>$i18n{hostPermissionsHeading}</span>
    <a class="link-icon-button" aria-label="$i18n{learnMore}"
        href="$i18n{hostPermissionsLearnMoreLink}" target="_blank">
      <iron-icon icon="cr:help-outline"></iron-icon>
    </a>
  </div>
  <cr-radio-group id="host-access" selected="[[permissions.hostAccess]]"
      on-selected-changed="onHostAccessChange_">
    <cr-radio-button name="[[HostAccess_.ON_CLICK]]">
      $i18n{hostAccessOnClick}
    </cr-radio-button>
    <cr-radio-button name="[[HostAccess_.ON_SPECIFIC_SITES]]"
        class="multi-row">
      <div>
        $i18n{hostAccessOnSpecificSites}
      </div>
      <template is="dom-if" if="[[showSpecificSites_(permissions.*)]]">
        <ul id="hosts">
          <template is="dom-repeat"
              items="[[getRuntimeHosts_(permissions.hosts)]]">
            <li>
              <div>[[item]]</div>
              <cr-icon-button class="icon-more-vert edit-host"
                  on-click="onEditHostClick_"
                  title="$i18n{hostPermissionsEdit}"></cr-icon-button>
            </li>
          </template>
          <li>
            <a id="add-host" is="action-link" on-click="onAddHostClick_">
              $i18n{itemSiteAccessAddHost}
            </a>
          </li>
        </ul>
      </template>
    </cr-radio-button>
    <cr-radio-button name="[[HostAccess_.ON_ALL_SITES]]">
      $i18n{hostAccessOnAllSites}
    </cr-radio-button>
  </cr-radio-group>
</div>
<cr-action-menu id="hostActionMenu"
    role-description="$i18n{menu}"
    on-close="onActionMenuClose_">
  <button class="dropdown-item" id="action-menu-edit"
      on-click="onActionMenuEditClick_">
    $i18n{hostPermissionsEdit}
  </button>
  <button class="dropdown-item" id="action-menu-remove"
      on-click="onActionMenuRemoveClick_">
    $i18n{remove}
  </button>
</cr-action-menu>
<template is="dom-if" if="[[showHostDialog_]]" restamp>
  <extensions-runtime-hosts-dialog
      delegate="[[delegate]]" item-id="[[itemId]]"
      current-site="[[hostDialogModel_]]"
      update-host-access="[[dialogShouldUpdateHostAccess_(oldHostAccess_)]]"
      on-close="onHostDialogClose_"
      on-cancel="onHostDialogCancel_">
  </extensions-runtime-hosts-dialog>
</template>
<!--_html_template_end_-->`,

  properties: {
    /**
     * The underlying permissions data.
     * @type {chrome.developerPrivate.RuntimeHostPermissions}
     */
    permissions: Object,

    /** @private */
    itemId: String,

    /** @type {!ItemDelegate} */
    delegate: Object,

    /**
     * Whether the dialog to add a new host permission is shown.
     * @private
     */
    showHostDialog_: Boolean,

    /**
     * The current site of the entry that the host dialog is editing, if the
     * dialog is open for editing.
     * @type {?string}
     * @private
     */
    hostDialogModel_: {
      type: String,
      value: null,
    },

    /**
     * The element to return focus to once the host dialog closes.
     * @type {?HTMLElement}
     * @private
     */
    hostDialogAnchorElement_: {
      type: Object,
      value: null,
    },

    /**
     * If the action menu is open, the site of the entry it is open for.
     * Otherwise null.
     * @type {?string}
     * @private
     */
    actionMenuModel_: {
      type: String,
      value: null,
    },

    /**
     * The element that triggered the action menu, so that the page will
     * return focus once the action menu (or dialog) closes.
     * @type {?HTMLElement}
     * @private
     */
    actionMenuAnchorElement_: {
      type: Object,
      value: null,
    },

    /**
     * The old host access setting; used when we don't immediately commit the
     * change to host access so that we can reset it if the user cancels.
     * @type {?string}
     * @private
     */
    oldHostAccess_: {
      type: String,
      value: null,
    },

    /**
     * Proxying the enum to be used easily by the html template.
     * @private
     */
    HostAccess_: {
      type: Object,
      value: chrome.developerPrivate.HostAccess,
    },
  },

  /**
   * @param {!Event} event
   * @private
   */
  onHostAccessChange_(event) {
    const group = /** @type {!HTMLElement} */ (this.$['host-access']);
    const access = group.selected;

    if (access === chrome.developerPrivate.HostAccess.ON_SPECIFIC_SITES &&
        this.permissions.hostAccess !==
            chrome.developerPrivate.HostAccess.ON_SPECIFIC_SITES) {
      // If the user is transitioning to the "on specific sites" option, show
      // the "add host" dialog. This serves two purposes:
      // - The user is prompted to add a host immediately, since otherwise
      //   "on specific sites" is meaningless, and
      // - The way the C++ code differentiates between "on click" and "on
      //   specific sites" is by checking if there are any specific sites.
      //   This ensures there will be at least one, so that the host access
      //   is properly calculated.
      this.oldHostAccess_ = this.permissions.hostAccess;
      this.doShowHostDialog_(group, null);
    } else {
      this.delegate.setItemHostAccess(this.itemId, access);
    }
  },

  /**
   * @return {boolean}
   * @private
   */
  showSpecificSites_() {
    return this.permissions.hostAccess ===
        chrome.developerPrivate.HostAccess.ON_SPECIFIC_SITES;
  },

  /**
   * Returns the granted host permissions as a sorted set of strings.
   * @return {!Array<string>}
   * @private
   */
  getRuntimeHosts_() {
    if (!this.permissions.hosts) {
      return [];
    }

    // Only show granted hosts in the list.
    // TODO(devlin): For extensions that request a finite set of hosts,
    // display them in a toggle list. https://crbug.com/891803.
    return this.permissions.hosts.filter(control => control.granted)
        .map(control => control.host)
        .sort();
  },

  /**
   * @param {Event} e
   * @private
   */
  onAddHostClick_(e) {
    const target = /** @type {!HTMLElement} */ (e.target);
    this.doShowHostDialog_(target, null);
  },

  /**
   * @param {!HTMLElement} anchorElement The element to return focus to once
   *     the dialog closes.
   * @param {?string} currentSite The site entry currently being
   *     edited, or null if this is to add a new entry.
   * @private
   */
  doShowHostDialog_(anchorElement, currentSite) {
    this.hostDialogAnchorElement_ = anchorElement;
    this.hostDialogModel_ = currentSite;
    this.showHostDialog_ = true;
  },

  /** @private */
  onHostDialogClose_() {
    this.hostDialogModel_ = null;
    this.showHostDialog_ = false;
    focusWithoutInk(assert(this.hostDialogAnchorElement_, 'Host Anchor'));
    this.hostDialogAnchorElement_ = null;
    this.oldHostAccess_ = null;
  },

  /** @private */
  onHostDialogCancel_() {
    // The user canceled the dialog. Set host-access back to the old value,
    // if the dialog was shown when just transitioning to a new state.
    if (this.oldHostAccess_) {
      assert(this.permissions.hostAccess === this.oldHostAccess_);
      this.$['host-access'].selected = this.oldHostAccess_;
      this.oldHostAccess_ = null;
    }
  },

  /**
   * @return {boolean}
   * @private
   */
  dialogShouldUpdateHostAccess_() {
    return !!this.oldHostAccess_;
  },

  /**
   * @param {!{
   *   model: !{item: string},
   *   target: !HTMLElement,
   * }} e
   * @private
   */
  onEditHostClick_(e) {
    this.actionMenuModel_ = e.model.item;
    this.actionMenuAnchorElement_ = e.target;
    const actionMenu =
        /** @type {CrActionMenuElement} */ (this.$.hostActionMenu);
    actionMenu.showAt(e.target);
  },

  /** @private */
  onActionMenuEditClick_() {
    // Cache the site before closing the action menu, since it's cleared.
    const site = this.actionMenuModel_;

    // Cache and reset actionMenuAnchorElement_ so focus is not returned
    // to the action menu's trigger (since the dialog will be shown next).
    // Instead, curry the element to the dialog, so once it closes, focus
    // will be returned.
    const anchorElement = assert(this.actionMenuAnchorElement_, 'Menu Anchor');
    this.actionMenuAnchorElement_ = null;
    this.closeActionMenu_();
    this.doShowHostDialog_(anchorElement, site);
  },

  /** @private */
  onActionMenuRemoveClick_() {
    this.delegate.removeRuntimeHostPermission(
        this.itemId, assert(this.actionMenuModel_, 'Action Menu Model'));
    this.closeActionMenu_();
  },

  /** @private */
  closeActionMenu_() {
    const menu = this.$.hostActionMenu;
    assert(menu.open);
    menu.close();
  },

  /** @private */
  onActionMenuClose_() {
    this.actionMenuModel_ = null;
    this.actionMenuAnchorElement_ = null;
  },
});
