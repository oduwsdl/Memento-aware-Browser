// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'disable-safebrowsing-dialog' makes sure users want to disable safebrowsing.
 */
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'settings-disable-safebrowsing-dialog',

  _template: html`<!--_html_template_start_-->
    <cr-dialog id="dialog" close-text="$i18n{close}">
      <div slot="title">$i18n{safeBrowsingDisableDialog}</div>
      <div slot="body">$i18n{safeBrowsingDisableDialogDesc}</div>
      <div slot="button-container">
        <cr-button class="cancel-button" on-click="onDialogCancel_">
          $i18n{cancel}
        </cr-button>
        <cr-button class="action-button" on-click="onDialogConfirm_">
          $i18n{safeBrowsingDisableDialogConfirm}
        </cr-button>
      </div>
    </cr-dialog>
<!--_html_template_end_-->`,

  /** @override */
  attached() {
    this.$.dialog.showModal();
  },

  /** @return {boolean} Whether the user confirmed the dialog. */
  wasConfirmed() {
    return /** @type {!CrDialogElement} */ (this.$.dialog)
               .getNative()
               .returnValue === 'success';
  },

  /** @private */
  onDialogCancel_() {
    this.$.dialog.cancel();
  },

  /** @private */
  onDialogConfirm_() {
    this.$.dialog.close();
  },
});
