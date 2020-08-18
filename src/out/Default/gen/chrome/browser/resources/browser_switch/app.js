// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import './strings.m.js';

import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {BrowserSwitchProxyImpl} from './browser_switch_proxy.js';

/** @type {number} */
const MS_PER_SECOND = 1000;

/** @enum {string} */
const LaunchError = {
  GENERIC_ERROR: 'genericError',
  PROTOCOL_ERROR: 'protocolError',
};

Polymer({
  is: 'browser-switch-app',

  _template: html`<!--_html_template_start_-->
<style>
  :host {
    background-color: var(--cr-card-background-color);
    border-radius: var(--cr-card-border-radius);
    box-shadow: var(--cr-card-shadow);
    color: var(--cr-primary-text-color);
    display: block;
    margin: 16px;
    max-width: 640px;
    min-width: 500px;
    padding: 16px;
  }

  h1 {
    font-size: 1rem;
    font-weight: 500;
    margin: 0;
    padding: 0 0 14px 0;
  }

  p {
    /* Should be 13px when html font-size is 16px */
    font-size: 0.8125rem;
    margin: 0;
    max-width: 450px;
  }

  iron-icon {
    height: 24px;
    margin-inline-end: 0.5rem;
    margin-top: -0.4rem;
    width: 24px;
  }
</style>

<h1>
  <iron-icon icon="cr:domain"></iron-icon>
  [[computeTitle_(error_, secondCounter_)]]
</h1>
<p inner-h-t-m-l="[[computeDescription_(url_, error_)]]"></p>
<!--_html_template_end_-->`,

  behaviors: [I18nBehavior],

  properties: {
    /**
     * URL to launch in the alternative browser.
     * @private
     */
    url_: {
      type: String,
      value() {
        return (new URLSearchParams(window.location.search)).get('url') || '';
      },
    },

    /**
     * Error message, or empty string if no error has occurred (yet).
     * @private
     */
    error_: {
      type: String,
      value: '',
    },

    /**
     * Countdown displayed to the user, number of seconds until launching. If 0
     * or less, doesn't get displayed at all.
     * @private
     */
    secondCounter_: {
      type: Number,
      value: 0,
    },
  },

  /** @override */
  attached() {
    // If '?done=...' is specified in the URL, this tab was-reopened, or the
    // entire browser was closed by LBS and re-opened. In that case, go to NTP
    // instead.
    const done = (new URLSearchParams(window.location.search)).has('done');
    if (done) {
      getProxy().gotoNewTabPage();
      return;
    }

    // Sanity check the URL to make sure nothing really funky is going on.
    const anchor = document.createElement('a');
    anchor.href = this.url_;
    if (!/^(file|http|https):$/.test(anchor.protocol)) {
      this.error_ = LaunchError.PROTOCOL_ERROR;
      return;
    }

    const milliseconds = loadTimeData.getInteger('launchDelay');
    setTimeout(this.launchAndCloseTab_.bind(this), milliseconds);
    this.startCountdown_(Math.floor(milliseconds / 1000));
  },

  /** @private */
  launchAndCloseTab_() {
    // Mark this page with '?done=...' so that restoring the tab doesn't
    // immediately re-trigger LBS.
    history.pushState({}, '', '/?done=true');

    getProxy().launchAlternativeBrowserAndCloseTab(this.url_).catch(() => {
      this.error_ = LaunchError.GENERIC_ERROR;
    });
  },

  /**
   * @param {number} seconds
   * @private
   */
  startCountdown_(seconds) {
    this.secondCounter_ = seconds;
    const intervalId = setInterval(() => {
      this.secondCounter_--;
      if (this.secondCounter_ <= 0) {
        clearInterval(intervalId);
      }
    }, 1 * MS_PER_SECOND);
  },

  /**
   * @return {string}
   * @private
   */
  computeTitle_() {
    if (this.error_) {
      return this.i18n('errorTitle', getBrowserName());
    }
    if (this.secondCounter_ > 0) {
      return this.i18n('countdownTitle', this.secondCounter_, getBrowserName());
    }
    return this.i18n('openingTitle', getBrowserName());
  },

  /**
   * @return {string}
   * @private
   */
  computeDescription_() {
    if (this.error_) {
      return this.i18n(
          this.error_, getUrlHostname(this.url_), getBrowserName());
    }
    return this.i18n(
        'description', getUrlHostname(this.url_), getBrowserName());
  },
});

function getBrowserName() {
  return loadTimeData.getString('browserName');
}

function getUrlHostname(url) {
  const anchor = document.createElement('a');
  anchor.href = url;
  // Return entire url if parsing failed (which means the URL is bogus).
  return anchor.hostname || url;
}

function getProxy() {
  return BrowserSwitchProxyImpl.getInstance();
}
