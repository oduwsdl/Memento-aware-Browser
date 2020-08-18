// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_input/cr_input.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'viewer-page-selector',

  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        color: #fff;
        display: flex;
        font-size: 0.81rem;

        --page-selector-spacing: 4px;
      }

      :host ::selection {
        background: rgba(255, 255, 255, 0.3);
      }

      #pageselector::part(input),
      #pagelength {
        /* --page-length-digits is set through JavaScript. 1px is added because
         * the unit 'ch' does not provide exact whole number pixels, and
         * therefore seems to have 1px-off bugginess. */
        width: calc(max(2, var(--page-length-digits)) * 1ch + 1px);
      }

      #pageselector {
        --cr-input-background-color: transparent;
        --cr-input-border-radius: 0;
        --cr-input-color: white;
        --cr-input-error-display: none;
        --cr-input-focus-color: transparent;
      }

      #pageselector::part(input) {
        background: rgba(0, 0, 0, 0.5);
        box-sizing: content-box;
        caret-color: var(--cr-input-color);
        padding: 0 var(--page-selector-spacing);
      }

      #divider {
        margin: 0 var(--page-selector-spacing);
      }
    </style>
    <cr-input id="pageselector" value="[[pageNo]]" on-mouseup="select"
        on-value-changed="onInputValueChange_" on-change="pageNoCommitted"
        aria-label$="$i18n{labelPageNumber}">
    </cr-input>
    <span id="divider">/</span>
    <span id="pagelength">[[docLength]]</span>
<!--_html_template_end_-->`,

  properties: {
    /**
     * The number of pages the document contains.
     */
    docLength: {type: Number, value: 1, observer: 'docLengthChanged_'},

    /**
     * The current page being viewed (1-based). A change to pageNo is mirrored
     * immediately to the input field. A change to the input field is not
     * mirrored back until pageNoCommitted() is called and change-page is fired.
     */
    pageNo: {
      type: Number,
      value: 1,
    },
  },

  /** @return {!CrInputElement} */
  get pageSelector() {
    return /** @type {!CrInputElement} */ (this.$.pageselector);
  },

  pageNoCommitted() {
    const page = parseInt(this.pageSelector.value, 10);

    if (!isNaN(page) && page <= this.docLength && page > 0) {
      this.fire('change-page', {page: page - 1, origin: 'pageselector'});
    } else {
      this.pageSelector.value = this.pageNo.toString();
    }
    this.pageSelector.blur();
  },

  /** @private */
  docLengthChanged_() {
    const numDigits = this.docLength.toString().length;
    this.style.setProperty('--page-length-digits', `${numDigits}`);
  },

  select() {
    this.pageSelector.select();
  },

  /**
   * @return {boolean} True if the selector input field is currently focused.
   */
  isActive() {
    return this.shadowRoot.activeElement === this.pageSelector;
  },

  /**
   * Immediately remove any non-digit characters.
   * @private
   */
  onInputValueChange_() {
    this.pageSelector.value = this.pageSelector.value.replace(/[^\d]/, '');
  },
});
