/* Copyright 2017 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file. */

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import './strings.m.js';
import './signin_shared_css.js';

import {assert, assertNotReached} from 'chrome://resources/js/assert.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {SyncConfirmationBrowserProxy, SyncConfirmationBrowserProxyImpl} from './sync_confirmation_browser_proxy.js';

Polymer({
  is: 'sync-confirmation-app',

  _template: html`<!--_html_template_start_-->
<style include="signin-dialog-shared">
  :host {
    color: var(--cr-primary-text-color);
    display: block;
  }

  cr-button {
    padding-inline-end: 16px;
    padding-inline-start: 16px;
  }

  .action-container {
    bottom: 0;
    box-sizing: border-box;
    position: absolute;
    width: 100%;
  }

  #illustration-container {
    height: 168px;
    margin-bottom: 32px;
    position: relative;
    width: 100%;
  }

  #illustration {
    background: url(./images/sync_confirmation_illustration.svg);
    background-size: 100% 100%;
    height: 100%;
    position: absolute;
    top: 0;
    width: 100%;
  }

  @media (prefers-color-scheme: dark) {
    #illustration {
      background-image:
          url(./images/sync_confirmation_illustration_dark.svg);
    }
  }

  #illustration-container > img {
    border-radius: 50%;
    height: 68px;
    left: 0;
    margin: auto;
    position: absolute;
    right: 0;
    top: 96px;
    width: 68px;
  }

  .heading {
    font-weight: normal;
    margin-bottom: 32px;
    padding: 0 24px;
    text-align: center;
  }

  #content-container {
    /* Saves space for button row. */
    padding-bottom: 96px;
    position: relative;
    width: 100%;
  }

  .message-container {
    line-height: 20px;
    margin-bottom: 16px;
    padding: 0 24px;
  }

  .secondary {
    color: var(--cr-secondary-text-color);
  }

  @media (prefers-color-scheme: light) {
    #grey-banner {
      background: var(--paper-grey-50);
      height: 128px;
      top: 0;
      width: 100%;
    }
  }

  #footer {
    margin-bottom: 0;
    padding-top: 12px;
  }

  #settingsButton {
    left: 16px;
    position: absolute;
  }

  :host-context([dir='rtl']) #settingsButton {
    left: auto;
    right: 16px;
  }
</style>

<!--
  Use the 'consent-description' attribute to annotate all the UI elements
  that are part of the text the user reads before consenting to the Sync
  data collection . Similarly, use 'consent-confirmation' on UI elements on
  which user clicks to indicate consent.
-->

<div id="illustration-container">
  <div id="grey-banner"></div>
  <div id="illustration"></div>
  <img src="[[accountImageSrc_]]">
</div>
<div id="content-container">
  <h1 id="syncConfirmationHeading" class="heading" consent-description>
    $i18n{syncConfirmationTitle}
  </h1>
  <div class="message-container">
    <div consent-description>$i18n{syncConfirmationSyncInfoTitle}</div>
    <div class="secondary" consent-description>
      $i18n{syncConfirmationSyncInfoDesc}
    </div>
  </div>
  <div id="footer" class="message-container secondary">
    $i18n{syncConfirmationSettingsInfo}
  </div>
  <div class="action-container">
    <cr-button class="action-button" id="confirmButton"
        on-click="onConfirm_" consent-confirmation autofocus>
      $i18n{syncConfirmationConfirmLabel}
    </cr-button>
    <cr-button id="cancelButton" on-click="onUndo_">
      $i18n{syncConfirmationUndoLabel}
    </cr-button>
    <cr-button id="settingsButton" on-click="onGoToSettings_"
        consent-confirmation>
      $i18n{syncConfirmationSettingsLabel}
    </cr-button>
  </div>
</div>
<!--_html_template_end_-->`,

  behaviors: [
    WebUIListenerBehavior,
  ],

  properties: {
    /** @private */
    accountImageSrc_: {
      type: String,
      value() {
        return loadTimeData.getString('accountPictureUrl');
      },
    },
  },

  /** @private {?SyncConfirmationBrowserProxy} */
  syncConfirmationBrowserProxy_: null,

  /** @override */
  attached() {
    this.syncConfirmationBrowserProxy_ =
        SyncConfirmationBrowserProxyImpl.getInstance();
    this.addWebUIListener(
        'account-image-changed', this.handleAccountImageChanged_.bind(this));
    this.syncConfirmationBrowserProxy_.requestAccountImage();
  },

  /** @private */
  onConfirm_(e) {
    this.syncConfirmationBrowserProxy_.confirm(
        this.getConsentDescription_(), this.getConsentConfirmation_(e.path));
  },

  /** @private */
  onUndo_() {
    this.syncConfirmationBrowserProxy_.undo();
  },

  /** @private */
  onGoToSettings_(e) {
    this.syncConfirmationBrowserProxy_.goToSettings(
        this.getConsentDescription_(), this.getConsentConfirmation_(e.path));
  },

  /**
   * @param {!Array<!HTMLElement>} path Path of the click event. Must contain
   *     a consent confirmation element.
   * @return {string} The text of the consent confirmation element.
   * @private
   */
  getConsentConfirmation_(path) {
    for (const element of path) {
      if (element.nodeType !== Node.DOCUMENT_FRAGMENT_NODE &&
          element.hasAttribute('consent-confirmation')) {
        return element.innerHTML.trim();
      }
    }
    assertNotReached('No consent confirmation element found.');
    return '';
  },

  /** @return {!Array<string>} Text of the consent description elements. */
  getConsentDescription_() {
    const consentDescription =
        Array.from(this.shadowRoot.querySelectorAll('[consent-description]'))
            .filter(element => element.clientWidth * element.clientHeight > 0)
            .map(element => element.innerHTML.trim());
    assert(consentDescription);
    return consentDescription;
  },

  /**
   * Called when the account image changes.
   * @param {string} imageSrc
   * @private
   */
  handleAccountImageChanged_(imageSrc) {
    this.accountImageSrc_ = imageSrc;
  },

});
