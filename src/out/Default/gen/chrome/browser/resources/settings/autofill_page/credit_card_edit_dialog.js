// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'settings-credit-card-edit-dialog' is the dialog that allows
 * editing or creating a credit card entry.
 */

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/cr_input/cr_input.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/cr_elements/md_select_css.m.js';
import '../settings_shared_css.m.js';
import '../settings_vars_css.m.js';

import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';

/**
 * Regular expression for invalid nickname. Nickname containing any digits will
 * be treated as invalid.
 * @type {!RegExp}
 */
const NICKNAME_INVALID_REGEX = new RegExp('.*\\d+.*');

Polymer({
  is: 'settings-credit-card-edit-dialog',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared md-select">
      cr-input {
        --cr-input-error-display: none;
        margin-bottom: var(--cr-form-field-bottom-spacing);
        width: var(--settings-input-max-width);
      }

      /* Larger cr-input margin (by reserving space for error display) when
      nickname management is enabled. */
      :host([nickname-management-enabled_]) cr-input {
        --cr-input-error-display: block;
        margin-bottom: 0;
      }

      /* Override the padding-top (the space is set by save-to-this-device) when
      nickname management is enabled. */
      :host([nickname-management-enabled_]) div[slot='button-container'] {
        padding-top: 0;
      }

      .md-select + .md-select {
        margin-inline-start: 8px;
      }

      #expired {
        align-items: center;
        background-color: var(--paper-red-50);
        color: var(--settings-error-color);
        display: flex;
        height: 40px;
        margin-top: 12px;
        padding: 0 0 0 8px;
      }

      @media (prefers-color-scheme: dark) {
        #expired {
          background-color: unset;
          font-weight: bold;
          padding: 0;
        }
      }

      #month {
        width: 70px;
      }

      #saved-to-this-device-only-label {
        margin-top: var(--cr-form-field-bottom-spacing);
      }

      :host([nickname-management-enabled_]) #saved-to-this-device-only-label {
        /* Overall space between input fields, including space between
           nicknameInput and saved-to-this-device text, between
           saved-to-this-device text and button. */
        margin-bottom: 26px;
        margin-top: 0;
      }

      #year {
        width: 100px;
      }

      /* For nickname input, cr-input-width is the same as other input fields */
      #nicknameInput {
        --cr-input-width: var(--settings-input-max-width);
        width: fit-content;
      }

      #charCount {
        font-size: var(--cr-form-field-label-font-size);
        line-height: var(--cr-form-field-label-line-height);
        padding-inline-start: 8px;
      }

      #nicknameInput:not(:focus-within) #charCount {
        display: none;
      }

      /* Same style as cr-input error except margin-top. */
      #expired-error {
        display: block;
        font-size: var(--cr-form-field-label-font-size);
        height: var(--cr-form-field-label-height);
        line-height: var(--cr-form-field-label-line-height);
        margin: 8px 0;
        visibility: hidden;
      }

      :host([expired_]) #expired-error {
        visibility: visible;
      }

      #expired-error,
      :host([nickname-management-enabled_][expired_]) #expiration {
        color: var(--google-red-600);
      }

      @media (prefers-color-scheme: dark) {
        #expired-error,
        :host([nickname-management-enabled_][expired_]) #expiration {
          color: var(--google-red-refresh-300);
        }
      }
    </style>
    <cr-dialog id="dialog" close-text="$i18n{close}">
      <div slot="title">[[title_]]</div>
      <div slot="body">
        <!-- Place and autofocus the cardholder name as the first field when
          nickname management is not enabled. -->
        <cr-input id="legacyNameInput" label="$i18n{creditCardName}"
            value="{{creditCard.name}}" spellcheck="false"
            hidden$="[[nicknameManagementEnabled_]]" autofocus>
        </cr-input>
        <cr-input id="numberInput" label="$i18n{creditCardNumber}"
            value="{{creditCard.cardNumber}}" autofocus>
        </cr-input>
        <!-- aria-hidden for creditCardExpiration label since
          creditCardExpirationMonth and creditCardExpirationYear provide
          sufficient labeling. -->
        <label id='expiration' class="cr-form-field-label" aria-hidden="true">
          $i18n{creditCardExpiration}
        </label>
        <select class="md-select" id="month" value="[[expirationMonth_]]"
            on-change="onMonthChange_"
            aria-label="$i18n{creditCardExpirationMonth}">
          <template is="dom-repeat" items="[[monthList_]]">
            <option>[[item]]</option>
          </template>
        </select>
        <select class="md-select" id="year" value="[[expirationYear_]]"
            on-change="onYearChange_"
            aria-label="$i18n{creditCardExpirationYear}">
          <template is="dom-repeat" items="[[yearList_]]">
            <option>[[item]]</option>
          </template>
        </select>
        <!-- Use new error message text under the drop down when nickname
          management is enabled.-->
        <div id="expired-error" aria-hidden$="[[getAriaHidden_(expired_)]]"
            hidden="[[!nicknameManagementEnabled_]]">
          $i18n{creditCardExpired}
        </div>
        <!-- Reuse current error message span when nickname management is
          disabled.-->
        <span id="expired" hidden="[[!showLegacyExpiredError_(expired_,
            nicknameManagementEnabled_)]]">
          $i18n{creditCardExpired}
        </span>
        <!-- Place cardholder name field and nickname field after expiration
          when nickname management is enabled.-->
        <template is="dom-if" if="[[nicknameManagementEnabled_]]">
          <cr-input id="nameInput" label="$i18n{creditCardName}"
              value="{{creditCard.name}}" spellcheck="false">
          </cr-input>
          <cr-input id="nicknameInput" label="$i18n{creditCardNickname}"
              value="{{creditCard.nickname}}" spellcheck="false" maxlength="25"
              on-input="validateNickname_"
              invalid="[[nicknameInvalid_]]"
              error-message="$i18n{creditCardNicknameInvalid}">
              <div id="charCount" slot="suffix">
                [[computeNicknameCharCount_(creditCard.nickname)]]/25
              </div>
          </cr-input>
        </template>
        <div id="saved-to-this-device-only-label">
          $i18n{savedToThisDeviceOnly}
        </div>
      </div>
      <div slot="button-container">
        <cr-button id="cancelButton" class="cancel-button"
            on-click="onCancelButtonTap_">$i18n{cancel}</cr-button>
        <cr-button id="saveButton" class="action-button"
            on-click="onSaveButtonTap_"
            disabled="[[!saveEnabled_(nicknameInvalid_, creditCard.*,
                expired_)]]">
          $i18n{save}
        </cr-button>
      </div>
    </cr-dialog>
<!--_html_template_end_-->`,

  properties: {
    /**
     * The credit card being edited.
     * @type {!chrome.autofillPrivate.CreditCardEntry}
     */
    creditCard: Object,

    /**
     * The actual title that's used for this dialog. Will be context sensitive
     * based on if |creditCard| is being created or edited.
     * @private
     */
    title_: String,

    /**
     * The list of months to show in the dropdown.
     * @private {!Array<string>}
     */
    monthList_: {
      type: Array,
      value: [
        '01', '02', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12'
      ],
    },

    /**
     * The list of years to show in the dropdown.
     * @private {!Array<string>}
     */
    yearList_: Array,

    /** @private */
    expirationYear_: String,

    /** @private {string|undefined} */
    expirationMonth_: String,

    /**
     * True if nickname management is enabled.
     * @private
     */
    nicknameManagementEnabled_: {
      type: Boolean,
      reflectToAttribute: true,
      value() {
        return loadTimeData.getBoolean('nicknameManagementEnabled');
      }
    },

    /**
     * Whether the current nickname input is invalid.
     * @private
     */
    nicknameInvalid_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    expired_: {
      type: Boolean,
      computed: 'computeExpired_(expirationMonth_, expirationYear_)',
      reflectToAttribute: true,
    },
  },

  behaviors: [
    I18nBehavior,
  ],

  /**
   * @return {boolean} True iff the provided expiration date is passed.
   * @private
   */
  computeExpired_() {
    if (this.expirationYear_ === undefined ||
        this.expirationMonth_ === undefined) {
      return false;
    }
    const now = new Date();
    // Convert string (e.g. '06') to number (e.g. 6) for comparison.
    const expirationYear = parseInt(this.expirationYear_, 10);
    const expirationMonth = parseInt(this.expirationMonth_, 10);
    return (
        expirationYear < now.getFullYear() ||
        (expirationYear === now.getFullYear() &&
         expirationMonth <= now.getMonth()));
  },

  /** @override */
  attached() {
    this.title_ = this.i18n(
        this.creditCard.guid ? 'editCreditCardTitle' : 'addCreditCardTitle');

    // Add a leading '0' if a month is 1 char.
    if (this.creditCard.expirationMonth.length === 1) {
      this.creditCard.expirationMonth = '0' + this.creditCard.expirationMonth;
    }

    const date = new Date();
    let firstYear = date.getFullYear();
    let lastYear = firstYear + 19;  // Show next 19 years (20 total).
    let selectedYear = parseInt(this.creditCard.expirationYear, 10);

    // |selectedYear| must be valid and between first and last years.
    if (!selectedYear) {
      selectedYear = firstYear;
    } else if (selectedYear < firstYear) {
      firstYear = selectedYear;
    } else if (selectedYear > lastYear) {
      lastYear = selectedYear;
    }

    const yearList = [];
    for (let i = firstYear; i <= lastYear; ++i) {
      yearList.push(i.toString());
    }
    this.yearList_ = yearList;

    this.async(() => {
      this.expirationYear_ = selectedYear.toString();
      this.expirationMonth_ = this.creditCard.expirationMonth;
      this.$.dialog.showModal();
    });
  },

  /** Closes the dialog. */
  close() {
    this.$.dialog.close();
  },

  /**
   * Handler for tapping the 'cancel' button. Should just dismiss the dialog.
   * @private
   */
  onCancelButtonTap_() {
    this.$.dialog.cancel();
  },

  /**
   * Handler for tapping the save button.
   * @private
   */
  onSaveButtonTap_() {
    if (!this.saveEnabled_()) {
      return;
    }

    this.creditCard.expirationYear = this.expirationYear_;
    this.creditCard.expirationMonth = this.expirationMonth_;
    this.fire('save-credit-card', this.creditCard);
    this.close();
  },

  /** @private */
  onMonthChange_() {
    this.expirationMonth_ = this.monthList_[this.$.month.selectedIndex];
  },

  /** @private */
  onYearChange_() {
    this.expirationYear_ = this.yearList_[this.$.year.selectedIndex];
  },

  /** @private */
  saveEnabled_() {
    // The save button is enabled if:
    // There is and name or number for the card
    // and the expiration date is valid
    // and the nickname is valid if present.
    return ((this.creditCard.name && this.creditCard.name.trim()) ||
            (this.creditCard.cardNumber &&
             this.creditCard.cardNumber.trim())) &&
        !this.expired_ && !this.nicknameInvalid_;
  },

  /**
   * @return {boolean} True iff the card is expired and nickname management is
   *     disabled.
   * @private
   */
  // TODO(crbug.com/1082013): Remove legacy expired error message when nickname
  // management is fully enabled.
  showLegacyExpiredError_() {
    return !this.nicknameManagementEnabled_ && this.expired_;
  },

  /**
   * Validate no digits are used in nickname. Display error message and disable
   * the save button when invalid.
   * @private
   */
  validateNickname_() {
    this.nicknameInvalid_ =
        NICKNAME_INVALID_REGEX.test(this.creditCard.nickname);
  },

  /**
   * @param {string|undefined} nickname of the card, undefined when not set.
   * @return {number} nickname character length.
   * @private
   */
  computeNicknameCharCount_(nickname) {
    return (nickname || '').length;
  },

  /**
   * @return {string} 'true' or 'false', indicating whether the expired error
   *     message should be aria-hidden.
   * @private
   */
  getAriaHidden_() {
    return this.expired_ ? 'false' : 'true';
  },
});
