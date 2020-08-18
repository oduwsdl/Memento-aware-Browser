// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import '../settings_shared_css.m.js';
import '../controls/settings_toggle_button.m.js';

import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {MetricsBrowserProxyImpl, PrivacyElementInteractions} from '../metrics_browser_proxy.js';

Polymer({
  is: 'settings-do-not-track-toggle',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared"></style>
    <settings-toggle-button id="toggle" class="hr" label="$i18n{doNotTrack}"
        pref="{{prefs.enable_do_not_track}}"
        on-settings-boolean-control-change="onToggleChange_"
        no-set-pref>
    </settings-toggle-button>
    <template is="dom-if" if="[[showDialog_]]"
        on-dom-change="onDomChange_" restamp>
      <cr-dialog id="confirmDialog"
          close-text="$i18n{close}" on-cancel="onDialogCancel_"
          on-close="onDialogClosed_">
        <div slot="title">$i18n{doNotTrackDialogTitle}</div>
        <div slot="body">$i18nRaw{doNotTrackDialogMessage}</div>
        <div slot="button-container">
          <cr-button class="cancel-button"
              on-click="onDialogCancel_">
            $i18n{cancel}
          </cr-button>
          <cr-button class="action-button"
              on-click="onDialogConfirm_">
            $i18n{confirm}
          </cr-button>
        </div>
      </cr-dialog>
    </template>
<!--_html_template_end_-->`,

  properties: {
    /**
     * Preferences state.
     */
    prefs: {
      type: Object,
      notify: true,
    },

    /** @private */
    showDialog_: {
      type: Boolean,
      value: false,
    },
  },

  /** @private */
  onDomChange_() {
    if (this.showDialog_) {
      this.$$('#confirmDialog').showModal();
    }
  },

  /**
   * Handles the change event for the do-not-track toggle. Shows a
   * confirmation dialog when enabling the setting.
   * @param {!Event} event
   * @private
   */
  onToggleChange_(event) {
    MetricsBrowserProxyImpl.getInstance().recordSettingsPageHistogram(
        PrivacyElementInteractions.DO_NOT_TRACK);
    const target = /** @type {!SettingsToggleButtonElement} */ (event.target);
    if (!target.checked) {
      // Always allow disabling the pref.
      target.sendPrefChange();
      return;
    }

    this.showDialog_ = true;
  },

  /** @private */
  closeDialog_() {
    this.$$('#confirmDialog').close();
    this.showDialog_ = false;
  },

  /** @private */
  onDialogClosed_() {
    focusWithoutInk(this.$.toggle);
  },

  /**
   * Handles the shared proxy confirmation dialog 'Confirm' button.
   * @private
   */
  onDialogConfirm_() {
    /** @type {!SettingsToggleButtonElement} */ (this.$.toggle)
        .sendPrefChange();
    this.closeDialog_();
  },

  /**
   * Handles the shared proxy confirmation dialog 'Cancel' button or a cancel
   * event.
   * @private
   */
  onDialogCancel_() {
    /** @type {!SettingsToggleButtonElement} */ (this.$.toggle)
        .resetToPrefValue();
    this.closeDialog_();
  },
});
