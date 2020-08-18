// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/cr_input/cr_input.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import './pack_dialog_alert.js';
import './strings.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

/** @interface */
export class PackDialogDelegate {
  /**
   * Opens a file browser for the user to select the root directory.
   * @return {Promise<string>} A promise that is resolved with the path the
   *     user selected.
   */
  choosePackRootDirectory() {}

  /**
   * Opens a file browser for the user to select the private key file.
   * @return {Promise<string>} A promise that is resolved with the path the
   *     user selected.
   */
  choosePrivateKeyPath() {}

  /**
   * Packs the extension into a .crx.
   * @param {string} rootPath
   * @param {string} keyPath
   * @param {number=} flag
   * @param {function(chrome.developerPrivate.PackDirectoryResponse)=}
   *     callback
   */
  packExtension(rootPath, keyPath, flag, callback) {}
}

Polymer({
  is: 'extensions-pack-dialog',

  _template: html`<!--_html_template_start_-->
<style include="cr-shared-style">
  cr-input {
    margin-top: var(--cr-form-field-bottom-spacing);
    --cr-input-error-display: none;
  }

  cr-button[slot='suffix'] {
    margin-inline-start: 10px;
  }

  /* Prevent focus-outline from being chopped by bottom of dialog body. */
  cr-input {
    margin-bottom: 2px;
  }
</style>
<cr-dialog id="dialog" close-text="$i18n{close}">
  <div slot="title">$i18n{packDialogTitle}</div>
  <div slot="body">
    <div>$i18n{packDialogContent}</div>
    <cr-input id="root-dir" label="$i18n{packDialogExtensionRoot}"
        value="{{packDirectory_}}">
      <cr-button id="root-dir-browse" on-click="onRootBrowse_"
          slot="suffix">
        $i18n{packDialogBrowse}
      </cr-button>
    </cr-input>
    <cr-input id="key-file" label="$i18n{packDialogKeyFile}"
        value="{{keyFile_}}">
      <cr-button id="key-file-browse" on-click="onKeyBrowse_"
          slot="suffix">
        $i18n{packDialogBrowse}
      </cr-button>
    </cr-input>
  </div>
  <div slot="button-container">
    <cr-button class="cancel-button" on-click="onCancelTap_">
      $i18n{cancel}
    </cr-button>
    <cr-button class="action-button" on-click="onConfirmTap_"
        disabled="[[!packDirectory_]]">
      $i18n{packDialogConfirm}
    </cr-button>
  </div>
</cr-dialog>
<template is="dom-if" if="[[lastResponse_]]" restamp>
  <extensions-pack-dialog-alert model="[[lastResponse_]]"
      on-close="onAlertClose_">
  </extensions-pack-dialog-alert>
</template>
<!--_html_template_end_-->`,

  properties: {
    /** @type {PackDialogDelegate} */
    delegate: Object,

    /** @private */
    packDirectory_: {
      type: String,
      value: '',  // Initialized to trigger binding when attached.
    },

    /** @private */
    keyFile_: String,

    /** @private {?chrome.developerPrivate.PackDirectoryResponse} */
    lastResponse_: Object,
  },

  /** @override */
  attached() {
    this.$.dialog.showModal();
  },

  /** @private */
  onRootBrowse_() {
    this.delegate.choosePackRootDirectory().then(path => {
      if (path) {
        this.set('packDirectory_', path);
      }
    });
  },

  /** @private */
  onKeyBrowse_() {
    this.delegate.choosePrivateKeyPath().then(path => {
      if (path) {
        this.set('keyFile_', path);
      }
    });
  },

  /** @private */
  onCancelTap_() {
    this.$.dialog.cancel();
  },

  /** @private */
  onConfirmTap_() {
    this.delegate.packExtension(
        this.packDirectory_, this.keyFile_, 0, this.onPackResponse_.bind(this));
  },

  /**
   * @param {chrome.developerPrivate.PackDirectoryResponse} response the
   *    response from request to pack an extension.
   * @private
   */
  onPackResponse_(response) {
    this.lastResponse_ = response;
  },

  /**
   * In the case that the alert dialog was a success message, the entire
   * pack-dialog should close. Otherwise, we detach the alert by setting
   * lastResponse_ null. Additionally, if the user selected "proceed anyway"
   * in the dialog, we pack the extension again with override flags.
   * @param {!Event} e
   * @private
   */
  onAlertClose_(e) {
    e.stopPropagation();

    if (this.lastResponse_.status ===
        chrome.developerPrivate.PackStatus.SUCCESS) {
      this.$.dialog.close();
      return;
    }

    // This is only possible for a warning dialog.
    if (this.$$('extensions-pack-dialog-alert').returnValue === 'success') {
      this.delegate.packExtension(
          this.lastResponse_.item_path, this.lastResponse_.pem_path,
          this.lastResponse_.override_flags, this.onPackResponse_.bind(this));
    }

    this.lastResponse_ = null;
  },
});
