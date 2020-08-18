// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'settings-security-keys-credential-management-dialog' is a
 * dialog for viewing and erasing credentials stored on a security key.
 */

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_checkbox/cr_checkbox.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/polymer/v3_0/iron-list/iron-list.js';
import 'chrome://resources/polymer/v3_0/iron-pages/iron-pages.js';
import 'chrome://resources/polymer/v3_0/paper-spinner/paper-spinner-lite.js';
import '../settings_shared_css.m.js';
import '../site_favicon.js';
import './security_keys_pin_field.js';

import {assert, assertNotReached} from 'chrome://resources/js/assert.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';

import {Credential, SecurityKeysCredentialBrowserProxy, SecurityKeysCredentialBrowserProxyImpl} from './security_keys_browser_proxy.js';

/** @enum {string} */
export const CredentialManagementDialogPage = {
  INITIAL: 'initial',
  PIN_PROMPT: 'pinPrompt',
  CREDENTIALS: 'credentials',
  ERROR: 'error',
};

Polymer({
  is: 'settings-security-keys-credential-management-dialog',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared">
      paper-spinner-lite {
        padding-bottom: 12px;
      }

      #header {
        display: flex;
      }

      .site {
        flex: 3;
      }

      .user {
        flex: 2;
      }

      .list-item .site {
        align-items: center;
        display: flex;
      }

      .list-item .site,
      .list-item .user {
        word-break: break-word;
      }

      site-favicon {
        margin-inline-end: 8px;
        min-width: 16px;
      }

      .checkbox-placeholder {
        width: var(--cr-icon-ripple-size);
      }
    </style>

    <cr-dialog id="dialog" close-text="$i18n{cancel}" ignore-popstate
        on-close="onDialogClosed_">
      <div slot="title">$i18n{securityKeysCredentialManagementDialogTitle}</div>

      <div slot="body">
        <iron-pages attr-for-selected="id" selected="[[dialogPage_]]"
            on-iron-select="onIronSelect_">
          <div id="initial">
            <p>$i18n{securityKeysTouchToContinue}</p>
            <paper-spinner-lite active></paper-spinner-lite>
          </div>

          <div id="pinPrompt">
            <settings-security-keys-pin-field id="pin">
            </settings-security-keys-pin-field>
          </div>

          <div id="credentials">
            <div id="header" class="list-item column-header">
              <div class="checkbox-placeholder"></div>
              <div class="site">$i18n{securityKeysCredentialWebsite}</div>
              <div class="user">$i18n{securityKeysCredentialUsername}</div>
            </div>

            <div id="container">
              <iron-list id="credentialList" items="[[credentials_]]"
                  class="cr-separators list-with-header">
                <template>
                  <div class="list-item">
                    <cr-checkbox on-change="checkedCredentialsChanged_"
                        data-id$="[[item.id]]"
                        checked="[[credentialIsChecked_(item.id)]]"
                        disabled="[[deleteInProgress_]]"></cr-checkbox>
                    <div class="site" aria-label="[[item.relyingPartyId]]">
                      <site-favicon url="[[item.relyingPartyId]]">
                      </site-favicon>
                      <div>[[item.relyingPartyId]]</div>
                    </div>
                    <div class="user">[[formatUser_(item)]]</div>
                  </div>
                </template>
              </iron-list>
            </div>
          </div>

          <div id="error">[[errorMsg_]]</div>
        </iron-pages>
      </div>

      <div slot="button-container">
        <cr-button id="cancelButton" class="cancel-button"
            on-click="close_" hidden="[[!cancelButtonVisible_]]">
          $i18n{cancel}
        </cr-button>
        <cr-button id="confirmButton" class="action-button"
            on-click="confirmButtonClick_"
            disabled="[[confirmButtonDisabled_]]"
            hidden="[[!confirmButtonVisible_]]">
          [[confirmButtonLabel_]]
        </cr-button>
        <cr-button id="closeButton" class="action-button"
            on-click="close_"
            hidden="[[!closeButtonVisible_]]">
          $i18n{close}
        </cr-button>
      </div>
    </cr-dialog>

<!--_html_template_end_-->`,

  behaviors: [
    I18nBehavior,
    WebUIListenerBehavior,
  ],

  properties: {
    /**
     * The ID of the element currently shown in the dialog.
     * @private {!CredentialManagementDialogPage}
     */
    dialogPage_: {
      type: String,
      value: CredentialManagementDialogPage.INITIAL,
      observer: 'dialogPageChanged_',
    },

    /**
     * The list of credentials displayed in the dialog.
     * @private {!Array<!Credential>}
     */
    credentials_: Array,

    /**
     * The message displayed on the "error" dialog page.
     * @private
     */
    errorMsg_: String,

    /** @private */
    cancelButtonVisible_: Boolean,

    /** @private */
    confirmButtonVisible_: Boolean,

    /** @private */
    confirmButtonDisabled_: Boolean,

    /** @private */
    confirmButtonLabel_: String,

    /** @private */
    closeButtonVisible_: Boolean,

    /** @private */
    deleteInProgress_: Boolean,
  },

  /** @private {?SecurityKeysCredentialBrowserProxy} */
  browserProxy_: null,

  /** @private {?Set<string>} */
  checkedCredentialIds_: null,

  /** @override */
  attached() {
    this.$.dialog.showModal();
    this.addWebUIListener(
        'security-keys-credential-management-finished',
        this.onError_.bind(this));
    this.checkedCredentialIds_ = new Set();
    this.browserProxy_ = SecurityKeysCredentialBrowserProxyImpl.getInstance();
    this.browserProxy_.startCredentialManagement().then(() => {
      this.dialogPage_ = CredentialManagementDialogPage.PIN_PROMPT;
    });
  },

  /**
   * @private
   * @param {string} error
   */
  onError_(error) {
    this.errorMsg_ = error;
    this.dialogPage_ = CredentialManagementDialogPage.ERROR;
  },

  /** @private */
  submitPIN_() {
    // Disable the confirm button to prevent concurrent submissions.
    this.confirmButtonDisabled_ = true;

    /** @type {!SettingsSecurityKeysPinFieldElement} */ (this.$.pin)
        .trySubmit(pin => this.browserProxy_.providePIN(pin))
        .then(
            () => {
              // Leave confirm button disabled while enumerating credentials.
              this.browserProxy_.enumerateCredentials().then(
                  this.onCredentials_.bind(this));
            },
            () => {
              // Wrong PIN.
              this.confirmButtonDisabled_ = false;
            });
  },

  /**
   * @private
   * @param {!Array<!Credential>} credentials
   */
  onCredentials_(credentials) {
    if (!credentials.length) {
      this.onError_(this.i18n('securityKeysCredentialManagementNoCredentials'));
      return;
    }
    this.credentials_ = credentials;
    this.$.credentialList.fire('iron-resize');
    this.dialogPage_ = CredentialManagementDialogPage.CREDENTIALS;
  },

  /** @private */
  dialogPageChanged_() {
    switch (this.dialogPage_) {
      case CredentialManagementDialogPage.INITIAL:
        this.cancelButtonVisible_ = true;
        this.confirmButtonVisible_ = false;
        this.closeButtonVisible_ = false;
        break;
      case CredentialManagementDialogPage.PIN_PROMPT:
        this.cancelButtonVisible_ = true;
        this.confirmButtonLabel_ = this.i18n('continue');
        this.confirmButtonDisabled_ = false;
        this.confirmButtonVisible_ = true;
        this.closeButtonVisible_ = false;
        this.$.pin.focus();
        break;
      case CredentialManagementDialogPage.CREDENTIALS:
        this.cancelButtonVisible_ = true;
        this.confirmButtonLabel_ = this.i18n('delete');
        this.confirmButtonDisabled_ = true;
        this.confirmButtonVisible_ = true;
        this.closeButtonVisible_ = false;
        break;
      case CredentialManagementDialogPage.ERROR:
        this.cancelButtonVisible_ = false;
        this.confirmButtonVisible_ = false;
        this.closeButtonVisible_ = true;
        break;
      default:
        assertNotReached();
    }
    this.fire('credential-management-dialog-ready-for-testing');
  },

  /** @private */
  confirmButtonClick_() {
    switch (this.dialogPage_) {
      case CredentialManagementDialogPage.PIN_PROMPT:
        this.submitPIN_();
        break;
      case CredentialManagementDialogPage.CREDENTIALS:
        this.deleteSelectedCredentials_();
        break;
      default:
        assertNotReached();
    }
  },

  /** @private */
  close_() {
    this.$.dialog.close();
  },

  /**
   * Stringifies the user entity of a Credential for display in the dialog.
   * @private
   * @param {!Credential} credential
   * @return {string}
   */
  formatUser_(credential) {
    if (this.isEmpty_(credential.userDisplayName)) {
      return credential.userName;
    }
    return `${credential.userDisplayName} (${credential.userName})`;
  },

  /** @private */
  onDialogClosed_() {
    this.browserProxy_.close();
  },

  /**
   * @private
   * @param {?string} str
   * @return {boolean} Whether this credential has been selected for removal.
   */
  isEmpty_(str) {
    return !str || str.length === 0;
  },

  /**
   * @param {!Event} e
   * @private
   */
  onIronSelect_(e) {
    // Prevent this event from bubbling since it is unnecessarily triggering
    // the listener within settings-animated-pages.
    e.stopPropagation();
  },

  /**
   * Handler for checking or unchecking a credential.
   * @param {!Event} e
   * @private
   */
  checkedCredentialsChanged_(e) {
    const credentialId = e.target.dataset.id;
    if (e.target.checked) {
      this.checkedCredentialIds_.add(credentialId);
    } else {
      this.checkedCredentialIds_.delete(credentialId);
    }
    this.confirmButtonDisabled_ = this.checkedCredentialIds_.size === 0;
  },

  /**
   * @private
   * @param {string} credentialId
   * @return {boolean} true if the checkbox for |credentialId| is checked
   */
  credentialIsChecked_(credentialId) {
    return this.checkedCredentialIds_.has(credentialId);
  },

  /** @private */
  deleteSelectedCredentials_() {
    assert(this.dialogPage_ === CredentialManagementDialogPage.CREDENTIALS);
    assert(this.credentials_ && this.credentials_.length > 0);
    assert(this.checkedCredentialIds_.size > 0);

    this.confirmButtonDisabled_ = true;
    this.deleteInProgress_ = true;
    this.browserProxy_.deleteCredentials(Array.from(this.checkedCredentialIds_))
        .then((err) => {
          this.confirmButtonDisabled_ = false;
          this.deleteInProgress_ = false;
          this.onError_(err);
        });
  },
});
