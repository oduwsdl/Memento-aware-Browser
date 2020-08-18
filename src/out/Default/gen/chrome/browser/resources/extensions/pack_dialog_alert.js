// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import {assert, assertNotReached} from 'chrome://resources/js/assert.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'extensions-pack-dialog-alert',

  _template: html`<!--_html_template_start_-->
<style include="cr-shared-style">
  .body {
    white-space: pre-wrap;
    word-break: break-word;
  }
</style>

<cr-dialog id="dialog" close-text="$i18n{close}">
  <div class="title" slot="title">[[title_]]</div>
  <!-- No whitespace or new-lines allowed within the div.body tag. -->
  <div class="body" slot="body">[[model.message]]</div>
  <div class="button-container" slot="button-container">
    <cr-button class$="[[getCancelButtonClass_(confirmLabel_)]]"
        on-click="onCancelTap_" hidden="[[!cancelLabel_]]">
      [[cancelLabel_]]
    </cr-button>
    <cr-button class="action-button" on-click="onConfirmTap_"
        hidden="[[!confirmLabel_]]">
      [[confirmLabel_]]
    </cr-button>
  </div>
</cr-dialog>
<!--_html_template_end_-->`,

  properties: {
    /** @private {chrome.developerPrivate.PackDirectoryResponse} */
    model: Object,

    /** @private */
    title_: String,

    /** @private */
    message_: String,

    /** @private {?string} */
    cancelLabel_: String,

    /**
     * This needs to be initialized to trigger data-binding.
     * @private {?string}
     */
    confirmLabel_: {
      type: String,
      value: '',
    }
  },

  /** @return {string} */
  get returnValue() {
    return /** @type {!CrDialogElement} */ (this.$.dialog)
        .getNative()
        .returnValue;
  },

  /** @override */
  ready() {
    // Initialize button label values for initial html binding.
    this.cancelLabel_ = null;
    this.confirmLabel_ = null;

    switch (this.model.status) {
      case chrome.developerPrivate.PackStatus.WARNING:
        this.title_ = loadTimeData.getString('packDialogWarningTitle');
        this.cancelLabel_ = loadTimeData.getString('cancel');
        this.confirmLabel_ = loadTimeData.getString('packDialogProceedAnyway');
        break;
      case chrome.developerPrivate.PackStatus.ERROR:
        this.title_ = loadTimeData.getString('packDialogErrorTitle');
        this.cancelLabel_ = loadTimeData.getString('ok');
        break;
      case chrome.developerPrivate.PackStatus.SUCCESS:
        this.title_ = loadTimeData.getString('packDialogTitle');
        this.cancelLabel_ = loadTimeData.getString('ok');
        break;
      default:
        assertNotReached();
        return;
    }
  },

  /** @override */
  attached() {
    this.$.dialog.showModal();
  },

  /**
   * @return {string}
   * @private
   */
  getCancelButtonClass_() {
    return this.confirmLabel_ ? 'cancel-button' : 'action-button';
  },

  /** @private */
  onCancelTap_() {
    this.$.dialog.cancel();
  },

  /** @private */
  onConfirmTap_() {
    // The confirm button should only be available in WARNING state.
    assert(this.model.status === chrome.developerPrivate.PackStatus.WARNING);
    this.$.dialog.close();
  }
});
