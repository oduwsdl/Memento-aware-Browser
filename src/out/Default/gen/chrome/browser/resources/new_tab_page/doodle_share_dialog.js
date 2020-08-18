// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/cr_input/cr_input.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';

import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';
import {BrowserProxy} from './browser_proxy.js';

/**
 * The ID of the doodle app for Facebook. Used to share doodles to Facebook.
 * @type {number}
 */
const FACEBOOK_APP_ID = 738026486351791;

// Dialog that lets the user share the doodle.
class DoodleShareDialogElement extends PolymerElement {
  static get is() {
    return 'ntp-doodle-share-dialog';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style>
  #dialog::part(dialog) {
    max-width: 300px;
  }

  #buttons {
    display: flex;
    flex-direction: row;
    justify-content: center;
    margin-bottom: 28px;
    margin-top: 20px;
  }

  #buttons cr-button {
    background-position: center;
    background-repeat: no-repeat;
    background-size: cover;
    border: none;
    height: 48px;
    min-width: 48px;
    width: 48px;
  }

  #buttons cr-button:hover {
    opacity: 0.8;
  }

  #buttons > :not(:last-child) {
    margin-inline-end: 12px;
  }

  #facebookButton {
    background-image: url(icons/facebook.svg);
  }

  #twitterButton {
    background-image: url(icons/twitter.svg);
  }

  #emailButton {
    background-image: url(icons/mail.svg);
  }

  #url {
    --cr-input-error-display: none;
  }

  #copyButton {
    --cr-icon-image: url(icons/copy.svg);
    margin-inline-start: 2px;
  }
</style>
<cr-dialog id="dialog" show-on-attach>
  <div id="title" slot="title">
    [[title]]
  </div>
  <div slot="body">
    <div id="buttons">
      <cr-button id="facebookButton" title="$i18n{facebook}"
          on-click="onFacebookClick_">
      </cr-button>
      <cr-button id="twitterButton" title="$i18n{twitter}"
          on-click="onTwitterClick_">
      </cr-button>
      <cr-button id="emailButton" title="$i18n{email}"
          on-click="onEmailClick_">
      </cr-button>
    </div>
    <cr-input readonly label="$i18n{doodleLink}" id="url"
        value="[[url.url]]">
      <cr-icon-button id="copyButton" slot="suffix" title="$i18n{copyLink}"
          on-click="onCopyClick_">
      </cr-icon-button>
    </cr-input>
  </div>
  <div slot="button-container">
    <cr-button id="doneButton" class="action-button" on-click="onCloseClick_">
      $i18n{doneButton}
    </cr-button>
  </div>
</cr-dialog>
<!--_html_template_end_-->`;
  }

  static get properties() {
    return {
      /**
       * Title shown on the dialog.
       * @type {string}
       */
      title: String,

      /**
       * Share URL provided to the user.
       * @type {url.mojom.Url}
       */
      url: Object,
    };
  }

  /** @private */
  onFacebookClick_() {
    const url = 'https://www.facebook.com/dialog/share' +
        `?app_id=${FACEBOOK_APP_ID}` +
        `&href=${encodeURIComponent(this.url.url)}` +
        `&hashtag=${encodeURIComponent('#GoogleDoodle')}`;
    BrowserProxy.getInstance().open(url);
    this.notifyShare_(newTabPage.mojom.DoodleShareChannel.FACEBOOK);
  }

  /** @private */
  onTwitterClick_() {
    const url = 'https://twitter.com/intent/tweet' +
        `?text=${encodeURIComponent(`${this.title}\n${this.url.url}`)}`;
    BrowserProxy.getInstance().open(url);
    this.notifyShare_(newTabPage.mojom.DoodleShareChannel.TWITTER);
  }

  /** @private */
  onEmailClick_() {
    const url = `mailto:?subject=${encodeURIComponent(this.title)}` +
        `&body=${encodeURIComponent(this.url.url)}`;
    BrowserProxy.getInstance().navigate(url);
    this.notifyShare_(newTabPage.mojom.DoodleShareChannel.EMAIL);
  }

  /** @private */
  onCopyClick_() {
    this.$.url.select();
    navigator.clipboard.writeText(this.url.url);
    this.notifyShare_(newTabPage.mojom.DoodleShareChannel.LINK_COPY);
  }

  /** @private */
  onCloseClick_() {
    this.$.dialog.close();
  }

  /**
   * @param {newTabPage.mojom.DoodleShareChannel} channel
   * @private
   */
  notifyShare_(channel) {
    this.dispatchEvent(new CustomEvent('share', {detail: channel}));
  }
}

customElements.define(DoodleShareDialogElement.is, DoodleShareDialogElement);
