// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/cr_input/cr_input.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';

import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'viewer-password-screen',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style">
      #password {
        margin-top: var(--cr-form-field-bottom-spacing);
      }
    </style>
    <cr-dialog id="dialog" no-cancel>
      <div slot="title">$i18n{passwordDialogTitle}</div>
      <div slot="body">
        <div id="message">$i18n{passwordPrompt}</div>
        <cr-input id="password"
            type="password"
            error-message="[[getErrorMessage_(invalid)]]"
            invalid="[[invalid]]"
            autofocus>
        </cr-input>
      </div>
      <div slot="button-container">
        <cr-button id="submit" class="action-button" on-click="submit">
          $i18n{passwordSubmit}
        </cr-button>
      </div>
    </cr-dialog>
<!--_html_template_end_-->`,

  properties: {
    invalid: Boolean,
  },

  get active() {
    return this.$.dialog.open;
  },

  show() {
    this.$.dialog.showModal();
  },

  close() {
    if (this.active) {
      this.$.dialog.close();
    }
  },

  deny() {
    const password = /** @type {!CrInputElement} */ (this.$.password);
    password.disabled = false;
    this.$.submit.disabled = false;
    this.invalid = true;
    password.select();
  },

  submit() {
    const password = /** @type {!CrInputElement} */ (this.$.password);
    if (password.value.length === 0) {
      return;
    }
    password.disabled = true;
    this.$.submit.disabled = true;
    this.fire('password-submitted', {password: password.value});
  },

  /**
   * Returns |message| if input is invalid, otherwise empty string.
   * This avoids setting the error message (which announces to screen readers)
   * when there is no error.
   * @return {string}
   */
  getErrorMessage_() {
    return this.invalid ? loadTimeData.getString('passwordInvalid') : '';
  }
});
