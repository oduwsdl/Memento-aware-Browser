// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html, afterNextRender} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';
import {BrowserService} from './browser_service.js';
import {UMA_MAX_BUCKET_VALUE, UMA_MAX_SUBSET_BUCKET_VALUE} from './constants.js';
import './searched_label.js';
import './shared_style.js';
import './strings.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import {getFaviconForPageURL} from 'chrome://resources/js/icon.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import {FocusRowBehavior} from 'chrome://resources/js/cr/ui/focus_row_behavior.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import 'chrome://resources/js/icon.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';

Polymer({
  is: 'history-item',

  _template: html`<!--_html_template_start_-->
    <style include="shared-style cr-icons">
      :host {
        display: block;
        outline: none;
        pointer-events: none;
      }

      #main-container {
        position: relative;
      }

      :host([is-card-end]) #main-container {
        margin-bottom: var(--card-padding-between);
      }

      :host([is-card-start][is-card-end]) #main-container {
        border-radius: var(--cr-card-border-radius);
      }

      #date-accessed {
        display: none;
      }

      :host([is-card-start]) #date-accessed {
        display: block;
        font-size: 123%;
        font-weight: 400;
        letter-spacing: .25px;
        padding-bottom: 4px;
        padding-top: 8px;
      }

      #item-container {
        align-items: center;
        display: flex;
        min-height: var(--item-height);
        padding-inline-start: 10px;
        pointer-events: auto;
      }

      :host([is-card-start]) #item-container {
        padding-top: var(--card-first-last-item-padding);
      }

      :host([is-card-end]) #item-container {
        padding-bottom: var(--card-first-last-item-padding);
      }

      #title-and-domain {
        align-items: center;
        display: flex;
        flex: 1;
        height: var(--item-height);
        overflow: hidden;
        /* Allows the link's focus outline to be shown completely. */
        padding-inline-start: 5px;
      }

      #checkbox {
        margin: 12px;
      }

      /* #checkbox[unresolved] styling is necessary since cr-checkbox is being
         lazy-loaded. */
      #checkbox[unresolved] {
        border: 2px solid var(--cr-secondary-text-color);
        border-radius: 2px;
        content: '';
        display: block;
        height: 12px;
        width: 12px;
      }

      #time-accessed {
        color: var(--history-item-time-color);
        margin-inline-start: 6px;
        min-width: 96px;
      }

      #domain {
        color: var(--cr-secondary-text-color);
        flex-shrink: 0;
        margin-inline-start: 16px;
      }

      #menu-button {
        --cr-icon-button-margin-end: 12px;
        --cr-icon-button-margin-start: 12px;
      }

      #bookmark-star {
        --cr-icon-button-fill-color: var(--interactive-color);
        --cr-icon-button-icon-size: 16px;
        --cr-icon-button-margin-start: 12px;
        --cr-icon-button-size: 32px;
      }

      #time-gap-separator {
        border-inline-start: 1px solid #888;
        height: 15px;
        margin-inline-start: 77px;
      }

      @media (prefers-color-scheme: dark) {
        #time-gap-separator {
          border-color: var(--google-grey-refresh-500);
        }
      }

      #background-clip {
        /* Prevent artifacts when zoomed by overlapping the next item. */
        bottom: -0.4px;
        clip: rect(auto 999px auto -5px); /* Clip the top and bottom edges. */
        left: 0;
        position: absolute;
        right: 0;
        top: 0;
        z-index: -1;
      }

      :host([is-card-end]) #background-clip {
        bottom: 0;
        clip: rect(auto 999px 500px -5px); /* Clip the top edge. */
      }

      #background {
        background-color: var(--cr-card-background-color);
        bottom: 0;
        box-shadow: var(--cr-card-shadow);
        left: 0;
        position: absolute;
        right: 0;
        top: 0;
      }

      :host(:not([is-card-start])) #background {
        top: -5px; /* Draw the box shadow up the full edge of the background. */
      }

      :host([is-card-start]) #background {
        border-radius: var(--cr-card-border-radius) var(--cr-card-border-radius) 0 0;
      }

      :host([is-card-end]) #background {
        border-radius: 0 0 var(--cr-card-border-radius) var(--cr-card-border-radius);
      }

      :host([is-card-start][is-card-end]) #background {
        border-radius: var(--cr-card-border-radius);
      }
    </style>

    <div id="main-container">
      <div id="background-clip" aria-hidden="true">
        <div id="background"></div>
      </div>
      <div id="date-accessed" class="card-title" role="heading" aria-level="2">
        [[cardTitle_(numberOfItems, item.dateRelativeDay, searchTerm)]]
      </div>
      <div id="item-container" focus-row-container
          on-mousedown="onItemMousedown_"
          on-click="onItemClick_">
        <div role="gridcell">
          <cr-checkbox id="checkbox" checked="[[selected]]" unresolved
              focus-row-control focus-type="cr-checkbox"
              on-mousedown="onCheckboxClick_" on-keydown="onCheckboxClick_"
              on-change="onCheckboxChange_" class="no-label"
              hidden="[[selectionNotAllowed_]]"
              disabled="[[selectionNotAllowed_]]"
              aria-label$="[[getEntrySummary_(item)]]"></cr-checkbox>
        </div>
        <!-- ARIA hidden to avoid redundancy since timestamp is already part of
             |getEntrySummary_|. -->
        <span id="time-accessed" aria-hidden="true">
          [[item.readableTimestamp]]
        </span>
        <div id="title-and-domain" role="gridcell">
          <a href="[[item.url]]" id="link" class="website-link"
              focus-row-control focus-type="link"
              title="[[item.title]]" on-click="onLinkClick_"
              on-contextmenu="onLinkRightClick_">
            <div class="website-icon" id="icon"></div>
            <history-searched-label class="website-title" title="[[item.title]]"
                search-term="[[searchTerm]]"></history-searched-label>
          </a>
          <span id="domain">[[item.domain]]</span>
        </div>
        <div id="star-container">
          <template is="dom-if" if="[[item.starred]]">
            <div role="gridcell">
              <cr-icon-button id="bookmark-star" iron-icon="cr:star"
                  focus-row-control focus-type="star"
                  title="$i18n{removeBookmark}"
                  on-click="onRemoveBookmarkTap_">
              </cr-icon-button>
            </div>
          </template>
        </div>
        <div role="gridcell">
          <cr-icon-button id="menu-button" iron-icon="cr:more-vert"
              focus-row-control focus-type="cr-menu-button"
              title="$i18n{actionMenuDescription}" on-click="onMenuButtonTap_"
              aria-haspopup="menu"></cr-icon-button>
        </div>
      </div>
      <div id="time-gap-separator" hidden="[[!hasTimeGap]]"></div>
    </div>
<!--_html_template_end_-->`,

  behaviors: [FocusRowBehavior],

  properties: {
    // Underlying HistoryEntry data for this item. Contains read-only fields
    // from the history backend, as well as fields computed by history-list.
    item: {
      type: Object,
      observer: 'itemChanged_',
    },

    selected: {
      type: Boolean,
      reflectToAttribute: true,
    },

    isCardStart: {
      type: Boolean,
      reflectToAttribute: true,
    },

    isCardEnd: {
      type: Boolean,
      reflectToAttribute: true,
    },

    /** @type {Element} */
    lastFocused: {
      type: Object,
      notify: true,
    },

    listBlurred: {
      type: Boolean,
      notify: true,
    },

    ironListTabIndex: {
      type: Number,
      observer: 'ironListTabIndexChanged_',
    },

    selectionNotAllowed_: {
      type: Boolean,
      value: !loadTimeData.getBoolean('allowDeletingHistory'),
    },

    hasTimeGap: Boolean,

    index: Number,

    numberOfItems: Number,

    // Search term used to obtain this history-item.
    searchTerm: String,

    overrideCustomEquivalent: {
      type: Boolean,
      value: true,
    },
  },

  hostAttributes: {'role': 'row'},

  /** @private {boolean} */
  mouseDown_: false,

  /** @private {boolean} */
  isShiftKeyDown_: false,

  /** @override */
  attached() {
    afterNextRender(this, function() {
      // Adding listeners asynchronously to reduce blocking time, since these
      // history items are items in a potentially long list.
      this.listen(this.$.checkbox, 'keydown', 'onCheckboxKeydown_');
    });
  },

  /** @override */
  detached() {
    this.unlisten(this.$.checkbox, 'keydown', 'onCheckboxKeydown_');
  },

  focusOnMenuButton() {
    focusWithoutInk(this.$['menu-button']);
  },

  /** @param {!KeyboardEvent} e */
  onCheckboxKeydown_(e) {
    if (e.shiftKey && e.key === 'Tab') {
      this.focus();
    }
  },

  /**
   * Toggle item selection whenever the checkbox or any non-interactive part
   * of the item is clicked.
   * @param {MouseEvent} e
   * @private
   */
  onItemClick_(e) {
    for (let i = 0; i < e.path.length; i++) {
      const elem = e.path[i];
      if (elem.id !== 'checkbox' &&
          (elem.nodeName === 'A' || elem.nodeName === 'CR-ICON-BUTTON')) {
        return;
      }
    }

    if (this.selectionNotAllowed_) {
      return;
    }

    this.$.checkbox.focus();
    this.fire('history-checkbox-select', {
      index: this.index,
      shiftKey: e.shiftKey,
    });
  },

  /**
   * This is bound to mouse/keydown instead of click/press because this
   * has to fire before onCheckboxChange_. If we bind it to click/press,
   * it might trigger out of desired order.
   *
   * @param {!Event} e
   * @private
   */
  onCheckboxClick_(e) {
    this.isShiftKeyDown_ = e.shiftKey;
  },

  /**
   * @param {!Event} e
   * @private
   */
  onCheckboxChange_(e) {
    this.fire('history-checkbox-select', {
      index: this.index,
      // If the user clicks or press enter/space key, oncheckboxClick_ will
      // trigger before this function, so a shift-key might be recorded.
      shiftKey: this.isShiftKeyDown_,
    });

    this.isShiftKeyDown_ = false;
  },

  /**
   * @param {MouseEvent} e
   * @private
   */
  onItemMousedown_(e) {
    // Prevent shift clicking a checkbox from selecting text.
    if (e.shiftKey) {
      e.preventDefault();
    }
  },

  /**
   * @private
   * @return {string}
   */
  getEntrySummary_() {
    const item = this.item;
    return loadTimeData.getStringF(
        'entrySummary', item.dateTimeOfDay,
        item.starred ? loadTimeData.getString('bookmarked') : '', item.title,
        item.domain);
  },

  /**
   * @param {boolean} selected
   * @return {string}
   * @private
   */
  getAriaChecked_(selected) {
    return selected ? 'true' : 'false';
  },

  /**
   * Remove bookmark of current item when bookmark-star is clicked.
   * @private
   */
  onRemoveBookmarkTap_() {
    if (!this.item.starred) {
      return;
    }

    if (this.$$('#bookmark-star') === this.root.activeElement) {
      focusWithoutInk(this.$['menu-button']);
    }

    const browserService = BrowserService.getInstance();
    browserService.removeBookmark(this.item.url);
    browserService.recordAction('BookmarkStarClicked');

    this.fire('remove-bookmark-stars', this.item.url);
  },

  /**
   * Fires a custom event when the menu button is clicked. Sends the details
   * of the history item and where the menu should appear.
   */
  onMenuButtonTap_(e) {
    this.fire('open-menu', {
      target: e.target,
      index: this.index,
      item: this.item,
    });

    // Stops the 'click' event from closing the menu when it opens.
    e.stopPropagation();
  },

  /**
   * Record metrics when a result is clicked.
   * @private
   */
  onLinkClick_() {
    const browserService = BrowserService.getInstance();
    browserService.recordAction('EntryLinkClick');

    if (this.searchTerm) {
      browserService.recordAction('SearchResultClick');
    }

    if (this.index === undefined) {
      return;
    }

    const ageInDays = Math.ceil(
        (new Date() - new Date(this.item.time)) / 1000 /* s/ms */ /
        60 /* m/s */ / 60 /* h/m */ / 24 /* d/h */);

    browserService.recordHistogram(
        'HistoryPage.ClickPosition', Math.min(this.index, UMA_MAX_BUCKET_VALUE),
        UMA_MAX_BUCKET_VALUE);

    browserService.recordHistogram(
        'HistoryPage.ClickAgeInDays', Math.min(ageInDays, UMA_MAX_BUCKET_VALUE),
        UMA_MAX_BUCKET_VALUE);

    if (this.index <= UMA_MAX_SUBSET_BUCKET_VALUE) {
      browserService.recordHistogram(
          'HistoryPage.ClickPositionSubset', this.index,
          UMA_MAX_SUBSET_BUCKET_VALUE);
    }

    if (ageInDays <= UMA_MAX_SUBSET_BUCKET_VALUE) {
      browserService.recordHistogram(
          'HistoryPage.ClickAgeInDaysSubset', ageInDays,
          UMA_MAX_SUBSET_BUCKET_VALUE);
    }
  },

  onLinkRightClick_() {
    BrowserService.getInstance().recordAction('EntryLinkRightClick');
  },

  /**
   * Set the favicon image, based on the URL of the history item.
   * @private
   */
  itemChanged_() {
    this.$.icon.style.backgroundImage = getFaviconForPageURL(
        this.item.url, this.item.isUrlInRemoteUserData,
        this.item.remoteIconUrlForUma);
    this.listen(this.$['time-accessed'], 'mouseover', 'addTimeTitle_');
  },

  /**
   * @param {number} numberOfItems The number of items in the card.
   * @param {string} historyDate Date of the current result.
   * @param {string} search The search term associated with these results.
   * @return {string} The title for this history card.
   * @private
   */
  cardTitle_(numberOfItems, historyDate, search) {
    if (this.item === undefined) {
      return '';
    }

    if (!search) {
      return this.item.dateRelativeDay;
    }
    return searchResultsTitle(numberOfItems, search);
  },

  /** @private */
  addTimeTitle_() {
    const el = this.$['time-accessed'];
    el.setAttribute('title', new Date(this.item.time).toString());
    this.unlisten(el, 'mouseover', 'addTimeTitle_');
  },

  /**
   * @param {!Element} sampleElement An element to find an equivalent for.
   * @return {?Element} An equivalent element to focus, or null to use the
   *     default element.
   */
  getCustomEquivalent(sampleElement) {
    return sampleElement.getAttribute('focus-type') === 'star' ? this.$.link :
                                                                 null;
  },
});

/**
 * @param {number} numberOfResults
 * @param {string} searchTerm
 * @return {string} The title for a page of search results.
 */
export function searchResultsTitle(numberOfResults, searchTerm) {
  const resultId = numberOfResults === 1 ? 'searchResult' : 'searchResults';
  return loadTimeData.getStringF(
      'foundSearchResults', numberOfResults, loadTimeData.getString(resultId),
      searchTerm);
}
