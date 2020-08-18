// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'credit-card-list-entry' is a credit card row to be shown in
 * the settings page.
 */

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import '../i18n_setup.js';
import '../settings_shared_css.m.js';
import './passwords_shared_css.js';

import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'settings-credit-card-list-entry',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared passwords-shared">
      .expiration-column {
        align-items: center;
        display: flex;
        flex: 1;
      }

      #creditCardExpiration {
        flex: 1;
      }

      .payments-label {
        color: var(--cr-secondary-text-color);
        margin-inline-start: 16px;
      }
    </style>
    <div class="list-item">
      <div class="type-column">
        <span id="creditCardLabel">[[creditCard.metadata.summaryLabel]]</span>
        <span class="payments-label"
            hidden$="[[creditCard.metadata.isLocal]]">
          <span hidden$="[[creditCard.metadata.isCached]]">
            $i18n{googlePayments}
          </span>
          <span hidden$="[[!creditCard.metadata.isCached]]">
            $i18n{googlePaymentsCached}
          </span>
        </span>
      </div>
      <div class="expiration-column">
        <div id="creditCardExpiration">
            [[creditCard.expirationMonth]]/[[creditCard.expirationYear]]
        </div>
        <template is="dom-if" if="[[showDots_(creditCard.metadata)]]">
          <cr-icon-button class="icon-more-vert" id="creditCardMenu"
              title="$i18n{moreActions}" on-click="onDotsMenuClick_">
          </cr-icon-button>
        </template>
        <template is="dom-if" if="[[!showDots_(creditCard.metadata)]]">
          <cr-icon-button class="icon-external" id="remoteCreditCardLink"
              on-click="onRemoteEditClick_"></cr-icon-button>
        </template>
      </div>
    </div>
<!--_html_template_end_-->`,

  behaviors: [
    I18nBehavior,
  ],

  properties: {
    /**
     * A saved credit card.
     * @type {!chrome.autofillPrivate.CreditCardEntry}
     */
    creditCard: Object,
  },

  /**
   * Opens the credit card action menu.
   * @private
   */
  onDotsMenuClick_() {
    this.fire('dots-card-menu-click', {
      creditCard: this.creditCard,
      anchorElement: this.$$('#creditCardMenu'),
    });
  },

  /** @private */
  onRemoteEditClick_() {
    this.fire('remote-card-menu-click');
  },

  /**
   * The 3-dot menu should not be shown if the card is entirely remote.
   * @return {boolean}
   * @private
   */
  showDots_() {
    return !!(
        this.creditCard.metadata.isLocal || this.creditCard.metadata.isCached);
  },
});
