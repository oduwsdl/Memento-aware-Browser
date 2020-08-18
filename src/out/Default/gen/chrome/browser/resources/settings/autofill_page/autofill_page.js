// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'settings-autofill-page' is the settings page containing settings for
 * passwords, payment methods and addresses.
 */
import 'chrome://resources/cr_elements/cr_link_row/cr_link_row.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import '../prefs/prefs.m.js';
import '../settings_page/settings_animated_pages.m.js';
import '../settings_page/settings_subpage.m.js';
import '../settings_shared_css.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';
import {OpenWindowProxyImpl} from '../open_window_proxy.js';
import {PrefsBehavior} from '../prefs/prefs_behavior.m.js';
import {routes} from '../route.js';
import {Router} from '../router.m.js';

import {PasswordCheckBehavior} from './password_check_behavior.js';
import {PasswordManagerImpl} from './password_manager_proxy.js';

Polymer({
  is: 'settings-autofill-page',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared">
      cr-link-row {
        --cr-icon-button-margin-start: 20px;
      }

      cr-link-row:not([hidden]) + cr-link-row {
        border-top: var(--cr-separator-line);
      }
    </style>
    <settings-animated-pages id="pages" section="autofill"
        focus-config="[[focusConfig_]]">
      <div route-path="default">
        <cr-link-row id="passwordManagerButton" start-icon="settings20:vpn-key"
            label="$i18n{passwords}" on-click="onPasswordsClick_"
            role-description="$i18n{subpageArrowRoleDescription}">
          <span id="passwordManagerSubLabel" slot="sub-label">
              [[passwordManagerSubLabel_]]</span>
        </cr-link-row>
        <cr-link-row id="paymentManagerButton"
            start-icon="settings20:credit-card" label="$i18n{creditCards}"
            on-click="onPaymentsClick_"
            role-description="$i18n{subpageArrowRoleDescription}"></cr-link-row>
        <cr-link-row id="addressesManagerButton"
            start-icon="settings20:location-on" label="$i18n{addressesTitle}"
            on-click="onAddressesClick_"
            role-description="$i18n{subpageArrowRoleDescription}"></cr-link-row>
      </div>
      <template is="dom-if" route-path="/passwords">
        <settings-subpage
            associated-control="[[$$('#passwordManagerButton')]]"
            page-title="$i18n{passwords}"
            learn-more-url="$i18n{passwordManagerLearnMoreURL}"
            search-label="$i18n{searchPasswords}"
            search-term="{{passwordFilter_}}">
          <passwords-section id="passwordSection" filter="[[passwordFilter_]]"
              prefs="{{prefs}}">
          </passwords-section>
        </settings-subpage>
      </template>
      <!-- TODO(crbug.com/1049141): Add a learn-more-url, which will cause the
      (?) button to appear. -->
      <template is="dom-if" route-path="/passwords/device" no-search>
        <settings-subpage
            page-title="$i18n{passwordsDevice}"
            search-label="$i18n{searchPasswords}"
            search-term="{{passwordFilter_}}">
          <passwords-device-section id="passwordDeviceSection"
              filter="[[passwordFilter_]]">
          </passwords-device-section>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/passwords/check"
          no-search="[[!enablePasswordCheck_]]">
        <settings-subpage
            associated-control="[[$$('#passwordManagerButton')]]"
            page-title="$i18n{checkPasswords}"
            learn-more-url="$i18n{passwordCheckLearnMoreURL}">
          <settings-password-check prefs="{{prefs}}"></settings-password-check>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/payments">
        <settings-subpage
            associated-control="[[$$('#paymentManagerButton')]]"
            page-title="$i18n{creditCards}"
            learn-more-url="$i18n{paymentMethodsLearnMoreURL}">
          <settings-payments-section id="paymentsSection" prefs="{{prefs}}">
          </settings-payments-section>
        </settings-subpage>
      </template>
      <template is="dom-if" route-path="/addresses">
        <settings-subpage
            associated-control="[[$$('#addressesManagerButton')]]"
            page-title="$i18n{addressesTitle}">
          <settings-autofill-section id="autofillSection" prefs="{{prefs}}">
          </settings-autofill-section>
        </settings-subpage>
      </template>
    </settings-animated-pages>
<!--_html_template_end_-->`,

  behaviors: [
    PrefsBehavior,
    PasswordCheckBehavior,
  ],

  properties: {
    /** @private Filter applied to passwords and password exceptions. */
    passwordFilter_: String,

    /** @private {!Map<string, string>} */
    focusConfig_: {
      type: Object,
      value() {
        const map = new Map();
        if (routes.PASSWORDS) {
          map.set(routes.PASSWORDS.path, '#passwordManagerButton');
        }
        if (routes.PAYMENTS) {
          map.set(routes.PAYMENTS.path, '#paymentManagerButton');
        }
        if (routes.ADDRESSES) {
          map.set(routes.ADDRESSES.path, '#addressesManagerButton');
        }

        return map;
      },
    },

    /** @private */
    passwordManagerSubLabel_: {
      type: String,
      computed: 'computePasswordManagerSubLabel_(compromisedPasswordsCount)',
    },

    /** @private */
    enablePasswordCheck_: {
      type: Boolean,
      value: () => loadTimeData.getBoolean('enablePasswordCheck'),
    },
  },

  /**
   * Shows the manage addresses sub page.
   * @param {!Event} event
   * @private
   */
  onAddressesClick_(event) {
    Router.getInstance().navigateTo(routes.ADDRESSES);
  },

  /**
   * Shows the manage payment methods sub page.
   * @private
   */
  onPaymentsClick_() {
    Router.getInstance().navigateTo(routes.PAYMENTS);
  },

  /**
   * Shows a page to manage passwords. This is either the passwords sub page or
   * the Google Password Manager page.
   * @private
   */
  onPasswordsClick_() {
    PasswordManagerImpl.getInstance().recordPasswordsPageAccessInSettings();
    loadTimeData.getBoolean('navigateToGooglePasswordManager') ?
        OpenWindowProxyImpl.getInstance().openURL(
            loadTimeData.getString('googlePasswordManagerUrl')) :
        Router.getInstance().navigateTo(routes.PASSWORDS);
  },

  /**
   * @return {string} The sub-title message indicating the result of password
   *     check.
   * @private
   */
  computePasswordManagerSubLabel_() {
    if (!this.enablePasswordCheck_) {
      return '';
    }

    return this.leakedPasswords.length > 0 ? this.compromisedPasswordsCount :
                                             '';
  },
});
