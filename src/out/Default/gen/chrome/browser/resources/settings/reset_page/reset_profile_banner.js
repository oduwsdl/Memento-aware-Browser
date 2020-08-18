// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'settings-reset-profile-banner' is the banner shown for prompting the user to
 * clear profile settings.
 */
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {routes} from '../route.js';
import {Router} from '../router.m.js';

import {ResetBrowserProxyImpl} from './reset_browser_proxy.js';

Polymer({
  // TODO(dpapad): Rename to settings-reset-warning-dialog.
  is: 'settings-reset-profile-banner',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared"></style>
    <cr-dialog id="dialog" close-text="$i18n{close}" ignore-popstate>
      <div slot="title">$i18n{resetAutomatedDialogTitle}</div>
      <div slot="body">
        <span id="description">
          $i18n{resetProfileBannerDescription}
          <a id="learnMore"
             href="$i18nRaw{resetProfileBannerLearnMoreUrl}"
             target="_blank">$i18n{learnMore}</a>
        </span>
      </div>
      <div slot="button-container">
        <cr-button class="cancel-button" on-click="onOkTap_" id="ok">
          $i18n{ok}
        </cr-button>
        <cr-button class="action-button" on-click="onResetTap_" id="reset">
          $i18n{resetProfileBannerButton}
        </cr-button>
      </div>
    </cr-dialog>
<!--_html_template_end_-->`,

  listeners: {
    'cancel': 'onCancel_',
  },

  /** @override */
  attached() {
    /** @type {!CrDialogElement} */ (this.$.dialog).showModal();
  },

  /** @private */
  onOkTap_() {
    /** @type {!CrDialogElement} */ (this.$.dialog).cancel();
  },

  /** @private */
  onCancel_() {
    ResetBrowserProxyImpl.getInstance().onHideResetProfileBanner();
  },

  /** @private */
  onResetTap_() {
    this.$.dialog.close();
    Router.getInstance().navigateTo(routes.RESET_DIALOG);
  },
});
