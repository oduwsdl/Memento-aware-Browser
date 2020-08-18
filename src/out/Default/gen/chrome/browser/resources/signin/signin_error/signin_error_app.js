// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import './strings.m.js';
import './signin_shared_css.js';

import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'signin-error-app',

  _template: html`<!--_html_template_start_-->
    <style include="signin-dialog-shared">
      .details {
        line-height: 20px;
        margin-bottom: 8px;
        margin-top: 16px;
        padding: 0 24px;
      }

      #normal-error-message > p {
        margin-bottom: 0;
      }

      #profile-blocking-error-message {
        margin-top: 30px;
      }

      #profile-blocking-error-message > div {
        align-items: center;
        display: flex;
        margin-top: 1em;
      }

      iron-icon {
        color: var(--cr-secondary-text-color);
        flex-shrink: 0;
        height: var(--cr-icon-size);
        margin-inline-end: 16px;
        width: var(--cr-icon-size);
      }
    </style>
    <div class="container">
      <div class="top-title-bar">$i18n{signinErrorTitle}</div>
      <div id="normal-error-message" class="details"
          hidden="[[hideNormalError_]]">
        <p>$i18nRaw{signinErrorMessage}</p>
        <a id="learnMoreLink" href="#" on-click="onLearnMore_"
               hidden="[[isSystemProfile_]]">
          $i18nRaw{signinErrorLearnMore}
        </a>
      </div>
      <div id="profile-blocking-error-message" class="details"
          hidden="[[hideProfileBlockingErrors_.0]]">
        <div hidden="[[hideProfileBlockingErrors_.1]]">
          <iron-icon icon="cr:domain"></iron-icon>
          <span>$i18n{profileBlockedMessage}</span>
        </div>
        <div hidden="[[hideProfileBlockingErrors_.2]]">
          <iron-icon icon="cr:info"></iron-icon>
          <span>$i18n{profileBlockedAddPersonSuggestion}</span>
        </div>
        <div hidden="[[hideProfileBlockingErrors_.3]]">
          <iron-icon icon="cr:info"></iron-icon>
          <span>$i18n{profileBlockedRemoveProfileSuggestion}</span>
        </div>
      </div>
      <div class="action-container">
        <cr-button class="action-button" id="switchButton"
            hidden="[[switchButtonUnavailable_]]"
            on-click="onSwitchToExistingProfile_">
          $i18n{signinErrorSwitchLabel}
        </cr-button>
        <cr-button id="closeButton" hidden="[[switchButtonUnavailable_]]"
            on-click="onConfirm_" autofocus>
          $i18n{signinErrorCloseLabel}
        </cr-button>
        <cr-button id="confirmButton" hidden="[[!switchButtonUnavailable_]]"
            on-click="onConfirm_">
          $i18n{signinErrorOkLabel}
        </cr-button>
      </div>
    </div>
<!--_html_template_end_-->`,

  behaviors: [
    WebUIListenerBehavior,
  ],

  properties: {
    /** @private {boolean} */
    isSystemProfile_: {
      type: Boolean,
      value: () => loadTimeData.getBoolean('isSystemProfile'),
    },

    /** @private {boolean} */
    switchButtonUnavailable_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    hideNormalError_: {
      type: Boolean,
      value: () => loadTimeData.getString('signinErrorMessage').length === 0,
    },

    /**
     * An array of booleans indicating whether profile blocking messages should
     * be hidden. Position 0 corresponds to the #profile-blocking-error-message
     * container, and subsequent positions correspond to each of the 3 related
     * messages respectively.
     * @private {!Array<boolean>}
     */
    hideProfileBlockingErrors_: {
      type: Array,
      value: function() {
        const hide = [
          'profileBlockedMessage',
          'profileBlockedAddPersonSuggestion',
          'profileBlockedRemoveProfileSuggestion',
        ].map(id => loadTimeData.getString(id).length === 0);

        // Hide the container itself if all of each children are also hidden.
        hide.unshift(hide.every(hideEntry => hideEntry));

        return hide;
      },
    },
  },

  /** @override */
  attached() {
    this.addWebUIListener('switch-button-unavailable', () => {
      this.switchButtonUnavailable_ = true;
      // Move focus to the only displayed button in this case.
      this.$$('#confirmButton').focus();
    });
  },

  /** @private */
  onConfirm_() {
    chrome.send('confirm');
  },

  /** @private */
  onSwitchToExistingProfile_() {
    chrome.send('switchToExistingProfile');
  },

  /** @private */
  onLearnMore_() {
    chrome.send('learnMore');
  },
});
