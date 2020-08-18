// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_radio_button/cr_radio_button.m.js';
import 'chrome://resources/cr_elements/cr_radio_group/cr_radio_group.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import './signin_shared_css.js';
import './strings.m.js';

import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'signin-email-confirmation-app',

  _template: html`<!--_html_template_start_-->
    <style include="signin-dialog-shared">
      .container {
        /* The sign-in confirmation dialog uses a width that is larger than
         * the other sign-in dialogs to fit cases when the user has an email
         * name that is very large. */
        width: 512px;
      }

      .details {
        line-height: 20px;
        margin-inline-start: -8px;
        padding: 8px 24px 0;
      }

      .radio-button-title-container {
        font-weight: 500;
        line-height: 20px;
      }

      .radio-button-subtitle-container {
        line-height: 20px;
      }

      .top-title-bar {
        color: #333;
        height: auto;

        /* The signin email confirmation dialog needs to support cases when the
         * title extends multiple lines. In that case, the height of the title
         * bar is equal to padding + height of the text (which is equal to
         * 2*16px + nb_lines * 22px). */
        line-height: 22px;
        padding: 16px 24px;
      }
      @media (prefers-color-scheme: dark) {
        .top-title-bar {
          color: var(--cr-primary-text-color);
        }
      }
    </style>
    <div class="container">
      <div class="top-title-bar" id='dialogTitle'>
      </div>
      <div class="details">
        <cr-radio-group selected="createNewUser">
          <cr-radio-button id="createNewUserRadioButton"
              name="createNewUser">
            <div class="radio-button-title-container">
              $i18n{signinEmailConfirmationCreateProfileButtonTitle}
            </div>
            <div class="radio-button-subtitle-container"
                id="createNewUserRadioButtonSubtitle">
            </div>
          </cr-radio-button>
          <cr-radio-button id="startSyncRadioButton" name="startSync">
            <div class="radio-button-title-container">
              $i18n{signinEmailConfirmationStartSyncButtonTitle}
            </div>
            <div class="radio-button-subtitle-container"
                id="startSyncRadioButtonSubtitle">
            </div>
          </cr-radio-button>
        </cr-radio-group>
      </div>
      <div class="action-container">
        <cr-button class="action-button" id="confirmButton"
            on-click="onConfirm_" autofocus>
          $i18n{signinEmailConfirmationConfirmLabel}
        </cr-button>
        <cr-button id="closeButton" on-click="onCancel_">
          $i18n{signinEmailConfirmationCloseLabel}
        </cr-button>
      </div>
    </div>
<!--_html_template_end_-->`,

  /** @override */
  ready() {
    const args = /** @type {{lastEmail: string, newEmail: string}} */
        (JSON.parse(chrome.getVariableValue('dialogArguments')));
    const {lastEmail, newEmail} = args;
    this.$.dialogTitle.textContent =
        loadTimeData.getStringF('signinEmailConfirmationTitle', lastEmail);
    this.$.createNewUserRadioButtonSubtitle.textContent =
        loadTimeData.getStringF(
            'signinEmailConfirmationCreateProfileButtonSubtitle', newEmail);
    this.$.startSyncRadioButtonSubtitle.textContent = loadTimeData.getStringF(
        'signinEmailConfirmationStartSyncButtonSubtitle', newEmail);
  },

  /** @private */
  onConfirm_() {
    const action = this.$$('cr-radio-group').selected;
    chrome.send('dialogClose', [JSON.stringify({'action': action})]);
  },

  /** @private */
  onCancel_() {
    chrome.send('dialogClose', [JSON.stringify({'action': 'cancel'})]);
  },
});
