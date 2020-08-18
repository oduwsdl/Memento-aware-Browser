// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_input/cr_input.m.js';
import './print_preview_shared_css.js';

import {CrSearchFieldBehavior} from 'chrome://resources/cr_elements/cr_search_field/cr_search_field_behavior.m.js';
import {stripDiacritics} from 'chrome://resources/js/search_highlight_utils.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

/** @type {!RegExp} */
const SANITIZE_REGEX = /[-[\]{}()*+?.,\\^$|#\s]/g;

Polymer({
  is: 'print-preview-search-box',

  _template: html`<!--_html_template_start_-->
<style include="print-preview-shared cr-input-style">
  :host {
    display: flex;
    --cr-input-error-display: none;
  }

  cr-input::part(row-container) {
    min-height: 32px;
  }

  #icon,
  #clearSearch {
    margin-inline-end: 0;
    margin-inline-start: 0;
  }

  #icon {
    height: 30px;
    width: 30px;
  }

  #clearSearch {
    --clear-icon-size: 28px;
    --cr-icon-button-size: var(--clear-icon-size);
    --cr-icon-button-icon-size: 20px;
    height: var(--clear-icon-size);
    position: absolute;
    right: 0;
    width: var(--clear-icon-size);
  }

  :host-context([dir=rtl]) #clearSearch {
    left: 0;
    right: auto;
  }

  :host([has-search-text]) cr-input {
    --cr-input-padding-end: 24px;
  }

  .search-box-input {
    width: 100%;
  }

  .search-box-input::-webkit-search-cancel-button {
    -webkit-appearance: none;
  }
</style>
<cr-input type="search" id="searchInput" class="search-box-input"
    on-search="onSearchTermSearch" on-input="onSearchTermInput"
    aria-label$="[[label]]" placeholder="[[label]]"
    autofocus="[[autofocus]]" spellcheck="false">
  <div slot="inline-prefix" id="icon" class="cr-icon icon-search" alt=""></div>
  <cr-icon-button id="clearSearch" class="icon-cancel"
      hidden$="[[!hasSearchText]]" slot="suffix" on-click="onClearClick_"
      title="[[clearLabel]]">
  </cr-icon-button>
</cr-input>
<!--_html_template_end_-->`,

  behaviors: [CrSearchFieldBehavior],

  properties: {
    autofocus: Boolean,

    /** @type {?RegExp} */
    searchQuery: {
      type: Object,
      notify: true,
    },
  },

  listeners: {
    'search-changed': 'onSearchChanged_',
  },

  /**
   * The last search query.
   * @private {string}
   */
  lastQuery_: '',

  /** @return {!CrInputElement} */
  getSearchInput() {
    return /** @type {!CrInputElement} */ (this.$.searchInput);
  },

  focus() {
    this.$.searchInput.focus();
  },

  /**
   * @param {!CustomEvent<string>} e Event containing the new search.
   * @private
   */
  onSearchChanged_(e) {
    const strippedQuery = stripDiacritics(e.detail.trim());
    const safeQuery = strippedQuery.replace(SANITIZE_REGEX, '\\$&');
    if (safeQuery === this.lastQuery_) {
      return;
    }

    this.lastQuery_ = safeQuery;
    this.searchQuery =
        safeQuery.length > 0 ? new RegExp(`(${safeQuery})`, 'ig') : null;
  },

  /** @private */
  onClearClick_() {
    this.setValue('');
    this.$.searchInput.focus();
  },
});
