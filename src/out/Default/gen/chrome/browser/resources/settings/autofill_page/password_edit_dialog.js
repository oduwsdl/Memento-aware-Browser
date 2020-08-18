// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'password-edit-dialog' is the dialog that allows showing a
 *     saved password.
 */

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_input/cr_input.m.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import '../icons.m.js';
import '../settings_shared_css.m.js';
import '../settings_vars_css.m.js';
import './passwords_shared_css.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {ShowPasswordBehavior} from './show_password_behavior.js';


Polymer({
  is: 'password-edit-dialog',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared passwords-shared">
      cr-input {
        --cr-input-error-display: none;
      }

      cr-input:not(:last-of-type) {
        margin-bottom: var(--cr-form-field-bottom-spacing);
      }

      #websiteInput,
      #usernameInput {
        width: var(--settings-input-max-width);
      }

      #passwordInput {
        --cr-input-width: var(--settings-input-max-width);
      }

      #passwordInput::part(row-container) {
        justify-content: initial;
      }

      #storageDetails {
        margin-inline-start: 2px;
        margin-bottom: 16px;
      }

      cr-icon-button {
        --cr-icon-button-icon-size: 24px;
        margin-inline-start: 2px;
      }
    </style>
    <cr-dialog id="dialog" close-text="$i18n{close}">
      <div slot="title">$i18n{passwordDetailsTitle}</div>
      <div slot="body">
        <div hidden="[[!shouldShowStorageDetails]]" id="storageDetails">
          [[getStorageDetailsMessage_()]]
        </div>
        <cr-input id="websiteInput" label="$i18n{editPasswordWebsiteLabel}"
            value="[[entry.urls.link]]" on-blur="onInputBlur_" readonly>
        </cr-input>
        <cr-input id="usernameInput" label="$i18n{editPasswordUsernameLabel}"
            value="[[entry.username]]" on-blur="onInputBlur_" readonly>
        </cr-input>
        <cr-input id="passwordInput" label="$i18n{editPasswordPasswordLabel}"
            type="[[getPasswordInputType_(password)]]"
            value="[[getPassword_(password)]]" on-blur="onInputBlur_"
            class="password-input" readonly>
          <cr-icon-button id="showPasswordButton"
              class$="[[getIconClass_(password)]]" slot="suffix"
              hidden$="[[entry.federationText]]"
              on-click="onShowPasswordButtonTap_"
              title="[[showPasswordTitle_(password,
                  '$i18nPolymer{hidePassword}',
                  '$i18nPolymer{showPassword}')]]">
          </cr-icon-button>
        </cr-input>
      </div>
      <div slot="button-container">
        <cr-button class="action-button" on-click="onActionButtonTap_">
          $i18n{done}
        </cr-button>
      </div>
    </cr-dialog>
<!--_html_template_end_-->`,

  behaviors: [ShowPasswordBehavior, I18nBehavior],

  properties: {
    shouldShowStorageDetails: {type: Boolean, value: false},
  },

  /** @override */
  attached() {
    this.$.dialog.showModal();
  },

  /** Closes the dialog. */
  close() {
    this.$.dialog.close();
  },

  /**
   * Handler for tapping the 'done' button. Should just dismiss the dialog.
   * @private
   */
  onActionButtonTap_() {
    this.close();
  },

  /** Manually de-select texts for readonly inputs. */
  onInputBlur_() {
    this.shadowRoot.getSelection().removeAllRanges();
  },

  /**
   * Gets the HTML-formatted message to indicate in which locations the password
   * is stored.
   */
  getStorageDetailsMessage_() {
    if (this.entry.isPresentInAccount() && this.entry.isPresentOnDevice()) {
      return this.i18n('passwordStoredInAccountAndOnDevice');
    }
    return this.entry.isPresentInAccount() ?
        this.i18n('passwordStoredInAccount') :
        this.i18n('passwordStoredOnDevice');
  }
});
