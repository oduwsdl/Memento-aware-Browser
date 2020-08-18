// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import './icons.js';
import './print_preview_vars_css.js';
import '../strings.m.js';

import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {PluralStringProxyImpl} from 'chrome://resources/js/plural_string_proxy.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {Destination} from '../data/destination.js';
import {Error, State} from '../data/state.js';
import {SettingsBehavior} from './settings_behavior.js';

Polymer({
  is: 'print-preview-header',

  _template: html`<!--_html_template_start_-->
<style>
  :host {
    align-items: center;
    display: flex;
    justify-content: space-between;
    padding: 20px var(--print-preview-sidebar-margin) 12px;
  }

  @media (prefers-color-scheme: light) {
    :host {
      background-color: white;
    }
  }

  #headerContainer {
    align-items: center;
    display: flex;
  }

  .summary,
  .title {
    color: var(--cr-primary-text-color);
    line-height: calc(20/13 * 1em);
    margin: 0;
  }

  .title {
    font-size: calc(16/13 * 1em);
    font-weight: 400;
  }

  .summary {
    font-weight: 500;
  }

  iron-icon {
    align-self: center;
    fill: var(--cr-secondary-text-color);
    height: 16px;
    margin-inline-start: 8px;
    width: 16px;
  }
</style>
<div id="headerContainer">
  <h1 class="title">$i18n{title}</h1>
  <iron-icon hidden$="[[!managed]]" icon="print-preview:business"
       alt="" title="$i18n{managedSettings}">
  </iron-icon>
</div>
<span class="summary">[[summary_]]</span>
<!--_html_template_end_-->`,

  behaviors: [SettingsBehavior],

  properties: {
    cloudPrintErrorMessage: String,

    /** @type {!Destination} */
    destination: Object,

    /** @type {!Error} */
    error: Number,

    /** @type {!State} */
    state: Number,

    managed: Boolean,

    /** @private {number} */
    sheetCount: Number,

    /** @private {?string} */
    summary_: String,
  },

  observers: [
    'updateSummary_(sheetCount, state, destination.id)',
  ],

  /**
   * @return {boolean}
   * @private
   */
  isPdfOrDrive_() {
    return this.destination &&
        (this.destination.id === Destination.GooglePromotedId.SAVE_AS_PDF ||
         this.destination.id === Destination.GooglePromotedId.DOCS);
  },

  /** @private */
  updateSummary_() {
    switch (this.state) {
      case (State.PRINTING):
        this.summary_ = loadTimeData.getString(
            this.isPdfOrDrive_() ? 'saving' : 'printing');
        break;
      case (State.READY):
        this.updateSheetsSummary_();
        break;
      case (State.FATAL_ERROR):
        this.summary_ = this.getErrorMessage_();
        break;
      default:
        this.summary_ = null;
        break;
    }
  },

  /**
   * @return {string} The error message to display.
   * @private
   */
  getErrorMessage_() {
    switch (this.error) {
      case Error.PRINT_FAILED:
        return loadTimeData.getString('couldNotPrint');
      case Error.CLOUD_PRINT_ERROR:
        return this.cloudPrintErrorMessage;
      default:
        return '';
    }
  },

  /** @private */
  updateSheetsSummary_() {
    if (this.sheetCount === 0) {
      this.summary_ = '';
      return;
    }

    const pageOrSheet = this.isPdfOrDrive_() ? 'Page' : 'Sheet';
    PluralStringProxyImpl.getInstance()
        .getPluralString(
            `printPreview${pageOrSheet}SummaryLabel`, this.sheetCount)
        .then(label => {
          this.summary_ = label;
        });
  },
});
