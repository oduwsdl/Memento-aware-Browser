// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import './strings.m.js';
import './realbox_button.js';
import './realbox_match.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {BrowserProxy} from './browser_proxy.js';
import {decodeString16, skColorToRgba} from './utils.js';

/**
 * Indicates a missing suggestion group Id. Based on
 * SearchSuggestionParser::kNoSuggestionGroupId.
 * @type {string}
 */
export const NO_SUGGESTION_GROUP_ID = '-1';

// A dropdown element that contains autocomplete matches. Provides an API for
// the embedder (i.e., <ntp-realbox>) to change the selection.
class RealboxDropdownElement extends PolymerElement {
  static get is() {
    return 'ntp-realbox-dropdown';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style>
  :host {
    background-color: var(--search-box-results-bg, white);
    overflow: hidden;
  }

  @media (min-width: 560px) {
    :host {
      width: 449px;
    }
  }

  @media (min-width: 672px) {
    :host {
      width: 561px;
    }
  }

  ntp-realbox-match {
    color: var(--search-box-results-text);
  }

  .header {
    align-items: center;
    display: flex;
    justify-content: space-between;
    margin-top: 8px;
    outline: none;
    padding-bottom: 4px;
    padding-inline-end: 16px;
    padding-inline-start: 12px;
    padding-top: 4px;
  }

  .header .text {
    color: var(--google-grey-refresh-700);
    cursor: default;
    font-size: 13px;
    font-weight: 500;
    line-height: 16px;
    overflow: hidden;
    padding-inline-end: 8px;
    text-overflow: ellipsis;
    text-transform: uppercase;
    user-select: none;
    white-space: nowrap;
  }

  ntp-realbox-match:hover,
  .header:hover {
    background-color: var(--search-box-results-bg-hovered, rgba(var(--google-grey-900-rgb), .1));
  }

  ntp-realbox-match:-webkit-any(:focus-within, .selected),
  .header:focus-within:not(:focus) {
    background-color: var(--search-box-results-bg-selected, rgba(var(--google-grey-900-rgb), .16));
    color: var(--search-box-results-text-selected, var(--google-grey-900));
  }
</style>
<iron-selector id="selector" selectable="ntp-realbox-match"
    items="{{selectableMatchElements_}}" selected="{{selectedMatchIndex}}"
    selected-class="selected">
  <template is="dom-repeat" items="[[groupIds_]]" as="groupId">
    <template is="dom-if" if="[[groupHasHeader_(groupId)]]">
      <!-- Header cannot be tabbed into but gets focus when clicked. This stops
           the dropdown from losing focus and closing as a result. -->
      <div class="header" tabindex="-1" on-focusin="onHeaderFocusin_"
          aria-hidden="true"
          group-is-hidden$="[[groupIsHidden_(groupId, hiddenGroupIds_.*)]]">
        <span class="text">[[headerForGroup_(groupId)]]</span>
        <ntp-realbox-button data-id$="[[groupId]]" tabindex="0" role="button"
            title="[[toggleButtonTitleForGroup_(groupId, hiddenGroupIds_.*)]]"
            aria-label$="[[toggleButtonA11yLabelForGroup_(groupId, hiddenGroupIds_.*)]]"
            on-click="onToggleButtonClick_" on-keydown="onToggleButtonKeydown_">
        </ntp-realbox-button>
      </div>
    </template>
    <template is="dom-if" if="[[!groupIsHidden_(groupId, hiddenGroupIds_.*)]]"
        restamp>
      <template is="dom-repeat" items="[[result.matches]]"
          filter="[[computeMatchBelongsToGroup_(groupId)]]"
          on-dom-change="onResultRepaint_">
        <ntp-realbox-match tabindex="0" role="option" match="[[item]]"
            match-index="[[matchIndex_(item)]]">
        </ntp-realbox-match>
      </template>
    </template>
  <template>
</iron-selector>
<!--_html_template_end_-->`;
  }

  static get properties() {
    return {
      //========================================================================
      // Public properties
      //========================================================================

      /**
       * @type {!search.mojom.AutocompleteResult}
       */
      result: {
        type: Object,
      },

      /**
       * Index of the selected match.
       * @type {number}
       */
      selectedMatchIndex: {
        type: Number,
        value: -1,
        notify: true,
      },

      /**
       * @type {!newTabPage.mojom.SearchBoxTheme}
       */
      theme: {
        type: Object,
        observer: 'onThemeChange_',
      },

      //========================================================================
      // Private properties
      //========================================================================

      /**
       * The list of suggestion group IDs matches belong to.
       * @type {!Array<string>}
       * @private
       */
      groupIds_: {
        type: Array,
        computed: `computeGroupIds_(result)`,
      },

      /**
       * The list of suggestion group IDs whose matches should be hidden.
       * @type {!Array<string>}
       * @private
       */
      hiddenGroupIds_: {
        type: Array,
        computed: `computeHiddenGroupIds_(result)`,
      },

      /**
       * The list of selectable match elements.
       * @type {!Array<!Element>}
       * @private
       */
      selectableMatchElements_: {
        type: Array,
        value: () => [],
      },
    };
  }

  constructor() {
    super();
    /** @private {!newTabPage.mojom.PageCallbackRouter} */
    this.callbackRouter_ = BrowserProxy.getInstance().callbackRouter;
    /** @private {newTabPage.mojom.PageHandlerRemote} */
    this.pageHandler_ = BrowserProxy.getInstance().handler;
    /** @private {?number} */
    this.autocompleteMatchImageAvailableListenerId_ = null;
  }

  /** @override */
  connectedCallback() {
    super.connectedCallback();
    this.autocompleteMatchImageAvailableListenerId_ =
        this.callbackRouter_.autocompleteMatchImageAvailable.addListener(
            this.onAutocompleteMatchImageAvailable_.bind(this));
  }

  /** @override */
  disconnectedCallback() {
    super.disconnectedCallback();
    this.callbackRouter_.removeListener(
        assert(this.autocompleteMatchImageAvailableListenerId_));
  }

  //============================================================================
  // Public methods
  //============================================================================

  /**
   * Unselects the currently selected match, if any.
   */
  unselect() {
    this.selectedMatchIndex = -1;
  }

  /**
   * Focuses the selected match, if any.
   */
  focusSelected() {
    if (this.$.selector.selectedItem) {
      this.$.selector.selectedItem.focus();
    }
  }

  /**
   * Selects the first match.
   */
  selectFirst() {
    this.selectedMatchIndex = 0;
  }

  /**
   * Selects the match at the given index.
   * @param {number} index
   */
  selectIndex(index) {
    this.selectedMatchIndex = index;
  }

  /**
   * Selects the previous match with respect to the currently selected one.
   * Selects the last match if the first one is currently selected.
   */
  selectPrevious() {
    this.selectedMatchIndex = this.selectedMatchIndex - 1 >= 0 ?
        this.selectedMatchIndex - 1 :
        this.selectableMatchElements_.length - 1;
  }

  /**
   * Selects the last match.
   */
  selectLast() {
    this.selectedMatchIndex = this.selectableMatchElements_.length - 1;
  }

  /**
   * Selects the next match with respect to the currently selected one.
   * Selects the first match if the last one is currently selected.
   */
  selectNext() {
    this.selectedMatchIndex =
        this.selectedMatchIndex + 1 < this.selectableMatchElements_.length ?
        this.selectedMatchIndex + 1 :
        0;
  }

  //============================================================================
  // Callbacks
  //============================================================================

  /**
   * @param {number} matchIndex match index
   * @param {!url.mojom.Url} url match imageUrl or destinationUrl.
   * @param {string} dataUrl match image or favicon content in in base64 encoded
   *     Data URL format.
   * @private
   */
  onAutocompleteMatchImageAvailable_(matchIndex, url, dataUrl) {
    if (!this.result || !this.result.matches) {
      return;
    }

    const match = this.result.matches[matchIndex];
    if (!match) {
      return;
    }

    // Set image or favicon content of the match, if applicable.
    if (match.destinationUrl.url === url.url) {
      this.set(`result.matches.${matchIndex}.faviconDataUrl`, dataUrl);
    } else if (match.imageUrl === url.url) {
      this.set(`result.matches.${matchIndex}.imageDataUrl`, dataUrl);
    }
  }

  /**
   * @private
   */
  onResultRepaint_() {
    this.dispatchEvent(new CustomEvent('result-repaint', {
      bubbles: true,
      composed: true,
      detail: window.performance.now(),
    }));
  }

  /**
   * @private
   */
  onThemeChange_() {
    if (!loadTimeData.getBoolean('realboxMatchOmniboxTheme')) {
      return;
    }

    const icon = assert(this.theme.icon);
    // Icon's background color in a hovered context (0x29 == .16).
    // TODO(crbug.com/1041129): Share this with the Omnibox.
    const iconBgHovered = {value: icon.value & 0x29ffffff};

    const iconSelected = assert(this.theme.iconSelected);
    // Icon's background color in a focused context (0x52 == .32).
    // TODO(crbug.com/1041129): Share this with the Omnibox.
    const iconBgFocused = {value: iconSelected.value & 0x52ffffff};

    this.updateStyles({
      '--search-box-icon-bg-focused': skColorToRgba(iconBgFocused),
      '--search-box-icon-bg-hovered': skColorToRgba(iconBgHovered),
      '--search-box-icon-selected': skColorToRgba(iconSelected),
      '--search-box-icon': skColorToRgba(icon),
      '--search-box-results-bg-hovered':
          skColorToRgba(assert(this.theme.resultsBgHovered)),
      '--search-box-results-bg-selected':
          skColorToRgba(assert(this.theme.resultsBgSelected)),
      '--search-box-results-bg': skColorToRgba(assert(this.theme.resultsBg)),
      '--search-box-results-dim-selected':
          skColorToRgba(assert(this.theme.resultsDimSelected)),
      '--search-box-results-dim': skColorToRgba(assert(this.theme.resultsDim)),
      '--search-box-results-text-selected':
          skColorToRgba(assert(this.theme.resultsTextSelected)),
      '--search-box-results-text':
          skColorToRgba(assert(this.theme.resultsText)),
      '--search-box-results-url-selected':
          skColorToRgba(assert(this.theme.resultsUrlSelected)),
      '--search-box-results-url': skColorToRgba(assert(this.theme.resultsUrl)),
    });
  }

  //============================================================================
  // Event handlers
  //============================================================================

  /**
   * @private
   */
  onHeaderFocusin_() {
    // The header got focus. Unselect the selected match, if any.
    this.unselect();
  }

  /**
   * @param {!Event} e
   * @private
   */
  onToggleButtonClick_(e) {
    const groupId = e.target.dataset.id;

    // Tell the backend to toggle visibility of the given suggestion group ID.
    this.pageHandler_.toggleSuggestionGroupIdVisibility(groupId);

    // Hide/Show matches with the given suggestion group ID.
    const index = this.hiddenGroupIds_.indexOf(groupId);
    if (index === -1) {
      this.push('hiddenGroupIds_', groupId);
    } else {
      this.splice('hiddenGroupIds_', index, 1);
    }
  }

  /**
   * @param {!Event} e
   * @private
   */
  onToggleButtonKeydown_(e) {
    if (e.key !== 'Enter' && e.key !== ' ') {
      return;
    }

    // Simulate a click so that it gets handled by |onToggleButtonClick_|.
    e.target.click();
    e.preventDefault();  // Prevents default browser action.
  }

  //============================================================================
  // Helpers
  //============================================================================

  /**
   * @returns {number} Index of the match in the autocomplete result. Passed to
   *     the match so it knows abut its position in the list of matches.
   * @private
   */
  matchIndex_(match) {
    if (!this.result || !this.result.matches) {
      return -1;
    }

    return this.result.matches.indexOf(match);
  }

  /**
   * @returns {!Array<string>}
   * @private
   */
  computeGroupIds_() {
    if (!this.result) {
      return [];
    }

    // Add |NO_SUGGESTION_GROUP_ID| to the list of suggestion group IDs.
    return [NO_SUGGESTION_GROUP_ID].concat(
        Object.keys(this.result.suggestionGroupsMap));
  }

  /**
   * @returns {!Array<string>}
   * @private
   */
  computeHiddenGroupIds_() {
    if (!this.result) {
      return [];
    }

    return Object.keys(this.result.suggestionGroupsMap)
        .filter((groupId => {
                  return this.result.suggestionGroupsMap[groupId].hidden;
                }).bind(this));
  }

  /**
   * @param {string} groupId
   * @returns {!function(!search.mojom.AutocompleteMatch):boolean} The filter
   *     function to filter matches that belong to the given suggestion group
   *     ID.
   * @private
   */
  computeMatchBelongsToGroup_(groupId) {
    return (match) => {
      return match.suggestionGroupId === Number(groupId);
    };
  }

  /**
   * @param {string} groupId
   * @returns {boolean} Whether the given suggestion group ID has a header.
   * @private
   */
  groupHasHeader_(groupId) {
    return groupId !== NO_SUGGESTION_GROUP_ID;
  }

  /**
   * @param {string} groupId
   * @returns {boolean} Whether matches with the given suggestion group ID
   *     should be hidden.
   * @private
   */
  groupIsHidden_(groupId) {
    return this.hiddenGroupIds_.indexOf(groupId) !== -1;
  }

  /**
   * @param {string} groupId
   * @returns {string} The header for the given suggestion group ID.
   * @private
   * @suppress {checkTypes}
   */
  headerForGroup_(groupId) {
    if (!this.groupHasHeader_(groupId)) {
      return '';
    }
    return (this.result && this.result.suggestionGroupsMap &&
            this.result.suggestionGroupsMap[groupId]) ?
        decodeString16(this.result.suggestionGroupsMap[groupId].header) :
        '';
  }

  /**
   * @param {string} groupId
   * @returns {string} Tooltip for suggestion group show/hide toggle button.
   * @private
   */
  toggleButtonTitleForGroup_(groupId) {
    if (!this.groupHasHeader_(groupId)) {
      return '';
    }
    return loadTimeData.getString(
        this.groupIsHidden_(groupId) ? 'showSuggestions' : 'hideSuggestions');
  }

  /**
   * @param {string} groupId
   * @returns {string} A11y label for suggestion group show/hide toggle button.
   * @private
   */
  toggleButtonA11yLabelForGroup_(groupId) {
    if (!this.groupHasHeader_(groupId)) {
      return '';
    }
    return loadTimeData.substituteString(
        loadTimeData.getString(
            this.groupIsHidden_(groupId) ? 'showSection' : 'hideSection'),
        this.headerForGroup_(groupId));
  }
}

customElements.define(RealboxDropdownElement.is, RealboxDropdownElement);
