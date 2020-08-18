// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'settings-history-deletion-dialog' is a dialog that is
 * optionally shown inside settings-clear-browsing-data-dialog after deleting
 * browsing history. It informs the user about the existence of other forms
 * of browsing history in their account.
 */
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import '../settings_shared_css.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'settings-history-deletion-dialog',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared"></style>

    <cr-dialog id="dialog" close-text="$i18n{close}">
      <div slot="title">$i18n{historyDeletionDialogTitle}</div>
      <div slot="body">$i18nRaw{historyDeletionDialogBody}</div>
      <div slot="button-container">
        <cr-button class="action-button" on-click="onOkTap_">
          $i18n{historyDeletionDialogOK}
        </cr-button>
      </div>
    </cr-dialog>
<!--_html_template_end_-->`,

  /** @override */
  attached() {
    this.$.dialog.showModal();
  },

  /**
   * Tap handler for the "OK" button.
   * @private
   */
  onOkTap_() {
    this.$.dialog.close();
  },
});
