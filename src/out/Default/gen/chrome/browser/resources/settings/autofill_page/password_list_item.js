// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview PasswordListItem represents one row in the list of passwords.
 * It needs to be its own component because FocusRowBehavior provides good a11y.
 */

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import '../settings_shared_css.m.js';
import '../site_favicon.js';
import './passwords_shared_css.js';

import {FocusRowBehavior} from 'chrome://resources/js/cr/ui/focus_row_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';

import {MultiStorePasswordUiEntry} from './multi_store_password_ui_entry.js';
import {ShowPasswordBehavior} from './show_password_behavior.js';

Polymer({
  is: 'password-list-item',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared passwords-shared">
      #originUrl {
        /* The following non-flex directives allow eliding long originUrls from
         * the left. Forcing rtl should not cause an issue for right-to-left
         * languages in this case, since valid URL characters are restricted to
         * ASCII.
         */
         direction: rtl;
         display: flex;
      }

      #username,
      #password {
        color: inherit;
        font-size: inherit;
        line-height: inherit;
      }

      #username {
        font-family: inherit;
      }

      #username,
      #password:not([type='password']) {
        text-overflow: ellipsis;
      }
    </style>
    <div class="list-item" focus-row-container>
      <div class="website-column no-min-width">
        <site-favicon url="[[entry.urls.link]]"></site-favicon>
        <a id="originUrl" target="_blank" class="no-min-width"
            href="[[entry.urls.link]]"
            focus-row-control focus-type="originUrl">
          <span class="text-elide">
            <!-- This bdo tag is necessary to fix the display of domains
              starting with numbers. -->
            <bdo dir="ltr">[[entry.urls.shown]]</bdo>
          </span>
        </a>
      </div>
      <input id="username" class="username-column password-field"
          aria-label="$i18n{editPasswordUsernameLabel}"
          readonly value="[[entry.username]]"
          focus-row-control focus-type="username">
      <div class="password-column">
        <template is="dom-if" if="[[!entry.federationText]]">
          <input id="password" aria-label=$i18n{editPasswordPasswordLabel}
              type="[[getPasswordInputType_(password)]]"
              class="password-field password-input" readonly
              disabled$="[[!password]]" on-click="onReadonlyInputTap_"
              value="[[getPassword_(password)]]"
              focus-row-control focus-type="passwordField">
          <cr-icon-button id="showPasswordButton"
              class$="[[getIconClass_(password)]]"
              on-click="onShowPasswordButtonTap_"
              title="[[showPasswordTitle_(password,
                  '$i18nPolymer{hidePassword}',
                  '$i18nPolymer{showPassword}')]]"
              focus-row-control focus-type="showPassword"></cr-icon-button>
        </template>
        <span class="password-field text-elide" id="federated"
            hidden$="[[!entry.federationText]]">
          [[entry.federationText]]
        </span>
      </div>
      <cr-icon-button class="icon-more-vert" id="passwordMenu"
          on-click="onPasswordMenuTap_" title="$i18n{moreActions}"
          focus-row-control focus-type="passwordMenu"
          aria-label$="[[getMoreActionsLabel_(entry)]]"></cr-icon-button>
    </div>
<!--_html_template_end_-->`,

  behaviors: [
    FocusRowBehavior,
    ShowPasswordBehavior,
  ],

  /**
   * Selects the password on tap if revealed.
   * @private
   */
  onReadonlyInputTap_() {
    if (this.password) {
      this.$$('#password').select();
    }
  },

  /**
   * Opens the password action menu.
   * @private
   */
  onPasswordMenuTap_() {
    this.fire(
        'password-menu-tap', {target: this.$.passwordMenu, listItem: this});
  },

  /**
   * Get the aria label for the More Actions button on this row.
   * @private
   */
  getMoreActionsLabel_() {
    // Avoid using I18nBehavior.i18n, because it will filter sequences, which
    // are otherwise not illegal for usernames. Polymer still protects against
    // XSS injection.
    return loadTimeData.getStringF(
        (this.entry.federationText) ? 'passwordRowFederatedMoreActionsButton' :
                                      'passwordRowMoreActionsButton',
        this.entry.username, this.entry.urls.shown);
  },
});
