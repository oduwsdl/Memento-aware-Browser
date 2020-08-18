// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'upi-id-list-entry' is a UPI ID row to be shown in
 * the settings page. https://en.wikipedia.org/wiki/Unified_Payments_Interface
 */

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import '../i18n_setup.js';
import '../settings_shared_css.m.js';

import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'settings-upi-id-list-entry',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared passwords-shared">
      .expiration-column {
        align-items: center;
        display: flex;
        flex: 1;
      }

      #upiIdExpiration {
        flex: 1;
      }

      .payments-label {
        color: var(--cr-secondary-text-color);
        margin-inline-start: 16px;
      }
    </style>
    <div class="list-item">
      <div class="type-column">
        <span id="upiIdLabel">[[upiId]]</span>
        <span class="payments-label">$i18n{upiIdLabel}</span>
      </div>
      <div class="expiration-column">
        <div id="upiIdExpiration">
          $i18n{upiIdExpirationNever}
        </div>
        <!-- TODO(crbug.com/986289) Implement button for deleting a row. -->
      </div>
    </div>
<!--_html_template_end_-->`,

  behaviors: [
    I18nBehavior,
  ],

  properties: {
    /** A saved UPI ID. */
    upiId: String,
  },
});
