// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import './strings.m.js';
import './signin_shared_css.js';

import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {SigninReauthBrowserProxy, SigninReauthBrowserProxyImpl} from './signin_reauth_browser_proxy.js';

Polymer({
  is: 'signin-reauth-app',

  _template: html`<!--_html_template_start_-->
<style include="signin-dialog-shared">
  :host {
    color: var(--cr-primary-text-color);
    display: flex;
    flex-direction: column;
    height: 100%;
  }

  #illustrationContainer {
    height: 170px;
    position: relative;
    width: 100%;
  }

  #illustration {
    background: url(./images/signin_reauth_illustration.svg);
    background-size: 100% 100%;
    height: 100%;
    position: absolute;
    top: 0;
    width: 100%;
  }

  @media (prefers-color-scheme: dark) {
    #illustration {
      background: url(./images/signin_reauth_illustration_dark.svg);
    }
  }

  #illustrationContainer > img {
    border-radius: 50%;
    height: 58px;
    left: 0;
    margin: auto;
    position: absolute;
    right: 0;
    top: 92px;
    width: 58px;
  }

  #contentContainer {
    flex-grow: 1;
    width: 100%;
  }

  h1 {
    font-weight: normal;
    margin-bottom: 32px;
    padding: 0 40px;
    text-align: center;
  }

  .message-container {
    line-height: 20px;
    margin-bottom: 16px;
    padding: 0 40px;
  }

  cr-button {
    padding-inline-end: 16px;
    padding-inline-start: 16px;
  }
</style>
<div id="illustrationContainer">
  <div id="illustration"></div>
  <img src="[[accountImageSrc_]]">
</div>
<div id="contentContainer">
  <h1 id="signinReauthTitle">
    $i18n{signinReauthTitle}
  </h1>
  <div class="message-container">
    <div>$i18n{signinReauthDesc}</div>
  </div>
</div>
<div class="action-container">
  <cr-button id="confirmButton" class="action-button" on-click="onConfirm_"
      autofocus>
    $i18n{signinReauthConfirmLabel}
  </cr-button>
  <cr-button id="cancelButton" on-click="onCancel_">
    $i18n{signinReauthCloseLabel}
  </cr-button>
</div>
<!--_html_template_end_-->`,

  properties: {
    /** @private */
    accountImageSrc_: {
      type: String,
      value() {
        return loadTimeData.getString('accountImageUrl');
      },
    },
  },

  /** @private {SigninReauthBrowserProxy} */
  signinReauthBrowserProxy_: null,

  /** @override */
  attached() {
    this.signinReauthBrowserProxy_ = SigninReauthBrowserProxyImpl.getInstance();
  },

  /** @private */
  onConfirm_() {
    this.signinReauthBrowserProxy_.confirm();
  },

  /** @private */
  onCancel_() {
    this.signinReauthBrowserProxy_.cancel();
  },
});
