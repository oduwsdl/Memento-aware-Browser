// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import './toggle_row.js';
import './shared_style.js';
import './strings.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {ItemDelegate} from './item.js';

Polymer({
  is: 'extensions-host-permissions-toggle-list',

  _template: html`<!--_html_template_start_-->
<style include="cr-shared-style shared-style">
  iron-icon {
    --iron-icon-height: var(--cr-icon-size);
    --iron-icon-width: var(--cr-icon-size);
  }

  #section-heading {
    align-items: center;
    color: var(--cr-primary-text-color);
    display: flex;
    justify-content: space-between;
    margin-top: 12px;
  }

  .toggle-section {
    display: flex;
    flex-direction: column;
    justify-content: center;
    min-height: var(--cr-section-min-height);
  }

  .site-toggle {
    border-top: var(--cr-separator-line);
    margin-inline-start: var(--cr-section-indent-width);
  }
</style>
<div id="section-heading">
  <span>$i18n{hostPermissionsDescription}</span>
  <a id="link-icon-button" aria-label="$i18n{learnMore}"
      href="$i18n{hostPermissionsLearnMoreLink}" target="_blank">
    <iron-icon icon="cr:help-outline"></iron-icon>
  </a>
</div>
<div class="toggle-section">
  <extensions-toggle-row checked="[[allowedOnAllHosts_(permissions.*)]]"
      id="allHostsToggle"
      on-change="onAllHostsToggleChanged_">
    <span>$i18n{itemAllowOnFollowingSites}</span>
  </extensions-toggle-row>
</div>
<template is="dom-repeat" items="[[getSortedHosts_(permissions.*)]]">
  <div class="toggle-section site-toggle">
    <extensions-toggle-row checked="[[item.granted]]"
        class="host-toggle no-end-padding"
        disabled="[[allowedOnAllHosts_(permissions.*)]]"
        host="[[item.host]]"
        on-change="onHostAccessChanged_">
      <span>[[item.host]]</span>
    </extensions-toggle-row>
  </div>
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
  },

  /**
   * @return {boolean} Whether the item is allowed to execute on all of its
   *     requested sites.
   * @private
   */
  allowedOnAllHosts_() {
    return this.permissions.hostAccess ===
        chrome.developerPrivate.HostAccess.ON_ALL_SITES;
  },

  /**
   * Returns a lexicographically-sorted list of the hosts associated with this
   * item.
   * @return {!Array<!chrome.developerPrivate.SiteControl>}
   * @private
   */
  getSortedHosts_() {
    return this.permissions.hosts.sort((a, b) => {
      if (a.host < b.host) {
        return -1;
      }
      if (a.host > b.host) {
        return 1;
      }
      return 0;
    });
  },

  /** @private */
  onAllHostsToggleChanged_() {
    // TODO(devlin): In the case of going from all sites to specific sites,
    // we'll withhold all sites (i.e., all specific site toggles will move to
    // unchecked, and the user can check them individually). This is slightly
    // different than the sync page, where disabling the "sync everything"
    // switch leaves everything synced, and user can uncheck them
    // individually. It could be nice to align on behavior, but probably not
    // super high priority.
    this.delegate.setItemHostAccess(
        this.itemId,
        this.$.allHostsToggle.checked ?
            chrome.developerPrivate.HostAccess.ON_ALL_SITES :
            chrome.developerPrivate.HostAccess.ON_SPECIFIC_SITES);
  },

  /** @private */
  onHostAccessChanged_(e) {
    const host = e.target.host;
    const checked = e.target.checked;

    if (checked) {
      this.delegate.addRuntimeHostPermission(this.itemId, host);
    } else {
      this.delegate.removeRuntimeHostPermission(this.itemId, host);
    }
  },
});
