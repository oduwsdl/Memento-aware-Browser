// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'settings-signout-dialog' is a dialog that allows the
 * user to turn off sync and sign out of Chromium.
 */
import {Polymer, html} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '//resources/cr_elements/cr_button/cr_button.m.js';
import '//resources/cr_elements/cr_checkbox/cr_checkbox.m.js';
import '//resources/cr_elements/cr_dialog/cr_dialog.m.js';
import '//resources/cr_elements/cr_expand_button/cr_expand_button.m.js';
import '//resources/cr_elements/shared_style_css.m.js';
import '//resources/cr_elements/shared_vars_css.m.js';
import {WebUIListenerBehavior} from '//resources/js/web_ui_listener_behavior.m.js';
import '//resources/polymer/v3_0/iron-collapse/iron-collapse.js';
import '//resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import {ProfileInfoBrowserProxyImpl} from './profile_info_browser_proxy.m.js';
import {SyncBrowserProxyImpl, SyncStatus} from './sync_browser_proxy.m.js';
import {loadTimeData} from '../i18n_setup.js';
import '../settings_shared_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared iron-flex">
      .delete-profile-warning {
        padding-bottom: 10px;
        padding-inline-end: var(--cr-section-padding);
        /* In order to line up with the checkbox text. */
        padding-inline-start: var(--cr-section-indent-padding);
        padding-top: 10px;
      }

      #wideFooter {
        /* Override the cr-dialog footer padding. */
        padding: 16px 0;
      }

      #dialog-body {
        /* Add space for the link focus ring. See https://crbug.com/916939. */
        padding-bottom: 2px;
      }
    </style>

    <cr-dialog id="dialog" ignore-enter-key close-text="$i18n{close}">
      <div slot="title">$i18n{syncDisconnectTitle}</div>
      <div id="dialog-body" slot="body">
        <div inner-h-t-m-l="[[
            getDisconnectExplanationHtml_(syncStatus.domain)]]">
        </div>
      </div>
      <div slot="button-container">
        <cr-button id="disconnectCancel" class="cancel-button"
            on-click="onDisconnectCancel_" >
          $i18n{cancel}
        </cr-button>
        <cr-button id="disconnectConfirm" class="action-button"
            hidden="[[syncStatus.domain]]" on-click="onDisconnectConfirm_">
          $i18n{syncDisconnect}
        </cr-button>
        <cr-button id="disconnectManagedProfileConfirm"
            class="action-button" hidden="[[!syncStatus.domain]]"
            on-click="onDisconnectConfirm_">
          $i18n{syncDisconnectConfirm}
        </cr-button>
      </div>
<if expr="(not chromeos and is_posix) or is_win or is_macosx">
      <template is="dom-if" if="[[!syncStatus.domain]]">
        <div id="wideFooter" slot="footer">
          <div class="cr-row first">
            <cr-checkbox id="deleteProfile" class="flex"
                checked="{{deleteProfile_}}">
              $i18n{syncDisconnectDeleteProfile}
            </cr-checkbox>
            <cr-expand-button expanded="{{deleteProfileWarningVisible_}}"
                alt="$i18n{deleteProfileWarningExpandA11yLabel}">
            </cr-expand-button>
          </div>
          <iron-collapse opened="[[deleteProfileWarningVisible_]]">
            <div class="delete-profile-warning">
              [[deleteProfileWarning_]]
            </div>
          </iron-collapse>
        </div>
      </template>
</if>
    </cr-dialog>
<!--_html_template_end_-->`,
  is: 'settings-signout-dialog',

  behaviors: [WebUIListenerBehavior],

  properties: {
    /**
     * The current sync status, supplied by the parent.
     * @type {?SyncStatus}
     */
    syncStatus: {
      type: Object,
      observer: 'syncStatusChanged_',
    },

    /**
     * True if the checkbox to delete the profile has been checked.
     * @private
     */
    deleteProfile_: Boolean,

    /**
     * True if the profile deletion warning is visible.
     * @private
     */
    deleteProfileWarningVisible_: Boolean,

    /**
     * The profile deletion warning. The message indicates the number of
     * profile stats that will be deleted if a non-zero count for the profile
     * stats is returned from the browser.
     * @private
     */
    deleteProfileWarning_: String,
  },

  /** @override */
  attached() {
    this.addWebUIListener(
        'profile-stats-count-ready', this.handleProfileStatsCount_.bind(this));
    // <if expr="not chromeos">
    ProfileInfoBrowserProxyImpl.getInstance().getProfileStatsCount();
    // </if>
    this.async(() => {
      this.$.dialog.showModal();
    });
  },

  /**
   * Returns true when the user selected 'Confirm'.
   * @return {boolean}
   */
  wasConfirmed() {
    return /** @type {!CrDialogElement} */ (this.$.dialog)
               .getNative()
               .returnValue === 'success';
  },

  /**
   * Handler for when the profile stats count is pushed from the browser.
   * @param {number} count
   * @private
   */
  handleProfileStatsCount_(count) {
    const username = this.syncStatus.signedInUsername || '';
    if (count === 0) {
      this.deleteProfileWarning_ = loadTimeData.getStringF(
          'deleteProfileWarningWithoutCounts', username);
    } else if (count === 1) {
      this.deleteProfileWarning_ = loadTimeData.getStringF(
          'deleteProfileWarningWithCountsSingular', username);
    } else {
      this.deleteProfileWarning_ = loadTimeData.getStringF(
          'deleteProfileWarningWithCountsPlural', count, username);
    }
  },

  /**
   * Polymer observer for syncStatus.
   * @private
   */
  syncStatusChanged_() {
    if (!this.syncStatus.signedIn && this.$.dialog.open) {
      this.$.dialog.close();
    }
  },

  /**
   * @private
   * @param {string} domain
   * @return {string}
   */
  getDisconnectExplanationHtml_(domain) {
    // <if expr="not chromeos">
    if (domain) {
      return loadTimeData.getStringF(
          'syncDisconnectManagedProfileExplanation',
          '<span id="managed-by-domain-name">' + domain + '</span>');
    }
    // </if>
    return loadTimeData.getString('syncDisconnectExplanation');
  },

  /** @private */
  onDisconnectCancel_() {
    /** @type {!CrDialogElement} */ (this.$.dialog).cancel();
  },

  /** @private */
  onDisconnectConfirm_() {
    this.$.dialog.close();
    // <if expr="not chromeos">
    const deleteProfile = !!this.syncStatus.domain || this.deleteProfile_;
    SyncBrowserProxyImpl.getInstance().signOut(deleteProfile);
    // </if>
    // <if expr="chromeos">
    // Chrome OS users are always signed-in, so just turn off sync.
    SyncBrowserProxyImpl.getInstance().turnOffSync();
    // </if>
  },
});
