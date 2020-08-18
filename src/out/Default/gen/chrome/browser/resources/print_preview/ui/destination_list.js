// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-list/iron-list.js';
import './destination_list_item.js';
import './print_preview_vars_css.js';
import '../strings.m.js';
import './throbber_css.js';

import {ListPropertyUpdateBehavior} from 'chrome://resources/js/list_property_update_behavior.m.js';
import {afterNextRender, html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {Destination} from '../data/destination.js';

const DESTINATION_ITEM_HEIGHT = 32;

Polymer({
  is: 'print-preview-destination-list',

  _template: html`<!--_html_template_start_-->
<style include="cr-hidden-style throbber">
  :host {
    display: flex;
    flex-direction: column;
    height: 100%;
    overflow: hidden;
    user-select: none;
  }

  #list {
    min-height: var(--destination-item-height);
  }

  .throbber-container {
    display: flex;
    margin-inline-start: 14px;
    min-height: var(--destination-item-height);
    padding-inline-end: 16px;
    padding-inline-start: calc(10/13 * 1em);
  }

  .throbber {
    align-self: center;
  }

  .no-destinations-message {
    padding-bottom: 8px;
    padding-inline-start: 18px;
    padding-top: 8px;
  }

  :not(.moving).list-item {
    transition: background-color 150ms;
  }

  .list-item:hover,
  .list-item:focus {
    background-color: rgb(228, 236, 247);
  }

  @media (prefers-color-scheme: dark) {
    .list-item:-webkit-any(:hover, :focus) {
      background-color: var(--cr-menu-background-focus-color);
    }
  }

  .list-item:focus {
    outline: none;
  }
</style>
<div class="no-destinations-message" hidden$="[[hasDestinations_]]">
  $i18n{noDestinationsMessage}
</div>
<iron-list id="list" items="[[matchingDestinations_]]" role="grid"
    aria-rowcount$="[[matchingDestinations_.length]]"
    aria-label="$i18n{printDestinationsTitle}" hidden$="[[hideList_]]">
  <template>
    <div role="row" id$="destination_[[index]]"
        aria-rowindex$="[[getAriaRowindex_(index)]]">
      <print-preview-destination-list-item class="list-item"
          search-query="[[searchQuery]]" destination="[[item]]"
          on-click="onDestinationSelected_" on-keydown="onKeydown_"
          role="gridcell" tabindex$="[[tabIndex]]"
          iron-list-tab-index="[[tabIndex]]">
      </print-preview-destination-list-item>
    </div>
  </template>
</iron-list>
<div class="throbber-container" hidden$="[[throbberHidden_]]">
  <div class="throbber"></div>
</div>
<!--_html_template_end_-->`,

  behaviors: [ListPropertyUpdateBehavior],

  properties: {
    /** @type {Array<!Destination>} */
    destinations: Array,

    /** @type {?RegExp} */
    searchQuery: Object,

    /** @type {boolean} */
    loadingDestinations: {
      type: Boolean,
      value: false,
    },

    /** @private {!Array<!Destination>} */
    matchingDestinations_: {
      type: Array,
      value: () => [],
    },

    /** @private {boolean} */
    hasDestinations_: {
      type: Boolean,
      value: true,
    },

    /** @private {boolean} */
    throbberHidden_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    hideList_: {
      type: Boolean,
      value: false,
    },
  },

  observers: [
    'updateMatchingDestinations_(' +
        'destinations.*, searchQuery, loadingDestinations)',
  ],

  /** @private {?function(Event)} */
  boundUpdateHeight_: null,

  /** @override */
  attached() {
    this.boundUpdateHeight_ = () => this.updateHeight_();
    window.addEventListener('resize', this.boundUpdateHeight_);
  },

  /** @override */
  detached() {
    window.removeEventListener('resize', this.boundUpdateHeight_);
    this.boundUpdateHeight_ = null;
  },

  /**
   * This is a workaround to ensure that the iron-list correctly updates the
   * displayed destination information when the elements in the
   * |matchingDestinations_| array change, instead of using stale information
   * (a known iron-list issue). The event needs to be fired while the list is
   * visible, so firing it immediately when the change occurs does not always
   * work.
   * @private
   */
  forceIronResize_() {
    this.$.list.fire('iron-resize');
  },

  /**
   * @param {number=} numDestinations
   * @private
   */
  updateHeight_(numDestinations) {
    const count = numDestinations === undefined ?
        this.matchingDestinations_.length :
        numDestinations;

    const maxDisplayedItems = this.offsetHeight / DESTINATION_ITEM_HEIGHT;
    const isListFullHeight = maxDisplayedItems <= count;

    // Update the throbber and "No destinations" message.
    this.hasDestinations_ = count > 0 || this.loadingDestinations;
    this.throbberHidden_ =
        !this.loadingDestinations || isListFullHeight || !this.hasDestinations_;

    this.hideList_ = count === 0;
    if (this.hideList_) {
      return;
    }

    const listHeight =
        isListFullHeight ? this.offsetHeight : count * DESTINATION_ITEM_HEIGHT;
    this.$.list.style.height = listHeight > DESTINATION_ITEM_HEIGHT ?
        `${listHeight}px` :
        `${DESTINATION_ITEM_HEIGHT}px`;
  },

  /** @private */
  updateMatchingDestinations_() {
    if (this.destinations === undefined) {
      return;
    }

    const matchingDestinations = this.searchQuery ?
        this.destinations.filter(
            d => d.matches(/** @type {!RegExp} */ (this.searchQuery))) :
        this.destinations.slice();

    // Update the height before updating the list.
    this.updateHeight_(matchingDestinations.length);
    this.updateList(
        'matchingDestinations_', destination => destination.key,
        matchingDestinations);

    this.forceIronResize_();
  },

  /**
   * @param {!KeyboardEvent} e Event containing the destination and key.
   * @private
   */
  onKeydown_(e) {
    if (e.key === 'Enter') {
      this.onDestinationSelected_(e);
      e.stopPropagation();
    }
  },

  /**
   * @param {!Event} e Event containing the destination that was selected.
   * @private
   */
  onDestinationSelected_(e) {
    if (e.composedPath()[0].tagName === 'A') {
      return;
    }

    this.fire('destination-selected', e.target);
  },

  /**
   * Returns a 1-based index for aria-rowindex.
   * @param {number} index
   * @return {number}
   * @private
   */
  getAriaRowindex_(index) {
    return index + 1;
  },
});
