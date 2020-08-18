// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_expand_button/cr_expand_button.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import '../shared_style.js';
import '../shared_vars.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

/**
 * @typedef {{
 *   activityIds: !Set<string>,
 *   key: string,
 *   count: number,
 *   activityType: !chrome.activityLogPrivate.ExtensionActivityFilter,
 *   countsByUrl: !Map<string, number>,
 *   expanded: boolean
 * }}
 */
export let ActivityGroup;

/**
 * A struct used to describe each url and its associated counts. The id is
 * unique for each item in the list of URLs and is used for the tooltip.
 * @typedef {{
 *   page: string,
 *   count: number
 * }}
 */
let PageUrlItem;

Polymer({
  is: 'activity-log-history-item',

  _template: html`<!--_html_template_start_-->
<style include="cr-icons cr-shared-style shared-style">
  :host {
    border-top: var(--cr-separator-line);
    display: block;
    /* Unequal padding on left/right side as the cr-icon-button's width is
     * greater than the delete icon's width. */
    padding-bottom: 8px;
    padding-inline-end: 8px;
    padding-inline-start: var(--cr-section-padding);
    padding-top: 8px;
  }

  #activity-item-main-row {
    align-items: center;
    display: flex;
    flex-direction: row;
    /* Match separator height. */
    min-height: calc(var(--cr-section-min-height) - var(--separator-gap));
  }

  #activity-item-main-row .separator {
    margin: 0 calc(
        var(--cr-section-padding) + var(--cr-icon-ripple-margin));
  }

  #activity-item-main-row cr-expand-button {
    margin-inline-end: 6px;
  }

  #activity-call-and-count {
    display: flex;
    flex: 1;
    flex-direction: row;
    margin-inline-end: auto;
    max-width: var(--activity-log-call-and-count-width);
  }

  #activity-delete {
    margin: 0;
  }

  #activity-type {
    flex: 0 var(--activity-type-width);
  }

  #activity-key {
    flex: 1;
    margin-inline-start: 10px;
    overflow: hidden;
    text-overflow: ellipsis;
    white-space: nowrap;
  }

  #activity-count {
    flex: 0 var(--activity-count-width);
    text-align: end;
  }

  .page-url {
    display: flex;
    flex-direction: row;
    margin-bottom: 10px;
    max-width: var(--activity-log-call-and-count-width);
  }

  .page-url-link {
    flex-grow: 1;
    margin-inline-end: 20px;
    margin-inline-start: 16px;
    overflow: hidden;
    text-overflow: ellipsis;
    white-space: nowrap;
  }
</style>
<div actionable$="[[isExpandable_]]"
    id="activity-item-main-row"
    on-click="onExpandTap_">
  <div id="activity-call-and-count">
    <span id="activity-type">[[data.activityType]]</span>
    <span id="activity-key" title="[[data.key]]">[[data.key]]</span>
    <span id="activity-count">[[data.count]]</span>
  </div>
  <cr-expand-button expanded="{{data.expanded}}"
      hidden$="[[!isExpandable_]]">
  </cr-expand-button>
  <div class="separator" hidden$="[[!isExpandable_]]"></div>
  <cr-icon-button id="activity-delete" class="icon-delete-gray"
      aria-describedby="api-call" aria-label="$i18n{clearEntry}"
      on-click="onDeleteTap_"></cr-icon-button>
</div>
<div id="page-url-list" hidden$="[[!data.expanded]]">
  <template is="dom-repeat" items="[[getPageUrls_(data)]]">
    <div class="page-url">
      <a class="page-url-link" href="[[item.page]]" target="_blank"
          title="[[item.page]]">[[item.page]]</a>
      <span class="page-url-count"
          hidden$="[[!shouldShowPageUrlCount_(data)]]">
        [[item.count]]
      </span>
    </div>
  </template>
</div>
<!--_html_template_end_-->`,

  properties: {
    /**
     * The underlying ActivityGroup that provides data for the
     * ActivityLogItem displayed.
     * @type {!ActivityGroup}
     */
    data: Object,

    /** @private */
    isExpandable_: {
      type: Boolean,
      computed: 'computeIsExpandable_(data.countsByUrl)',
    },
  },

  /**
   * @private
   * @return {boolean}
   */
  computeIsExpandable_() {
    return this.data.countsByUrl.size > 0;
  },

  /**
   * Sort the page URLs by the number of times it was associated with the key
   * for this ActivityGroup (API call or content script invocation.) Resolve
   * ties by the alphabetical order of the page URL.
   * @private
   * @return {!Array<PageUrlItem>}
   */
  getPageUrls_() {
    return Array.from(this.data.countsByUrl.entries())
        .map(e => ({page: e[0], count: e[1]}))
        .sort(function(a, b) {
          if (a.count !== b.count) {
            return b.count - a.count;
          }
          return a.page < b.page ? -1 : (a.page > b.page ? 1 : 0);
        });
  },

  /** @private */
  onDeleteTap_(e) {
    e.stopPropagation();
    this.fire(
        'delete-activity-log-item', Array.from(this.data.activityIds.values()));
  },

  /** @private */
  onExpandTap_() {
    if (this.isExpandable_) {
      this.set('data.expanded', !this.data.expanded);
    }
  },

  /**
   * Show the call count for a particular page URL if more than one page
   * URL is associated with the key for this ActivityGroup.
   * @private
   * @return {boolean}
   */
  shouldShowPageUrlCount_() {
    return this.data.countsByUrl.size > 1;
  },
});
