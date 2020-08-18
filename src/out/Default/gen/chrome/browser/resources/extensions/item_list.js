// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_components/managed_footnote/managed_footnote.m.js';
import './shared_style.js';
import './checkup.js';

import {CrContainerShadowBehavior} from 'chrome://resources/cr_elements/cr_container_shadow_behavior.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {IronA11yAnnouncer} from 'chrome://resources/polymer/v3_0/iron-a11y-announcer/iron-a11y-announcer.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {ItemDelegate} from './item.js';

Polymer({
  is: 'extensions-item-list',

  _template: html`<!--_html_template_start_-->
<style include="shared-style">
  .items-container,
  #content-wrapper {
    --extensions-card-width: 400px;
  }

  #container {
    box-sizing: border-box;
    height: 100%;
    overflow: overlay;
  }

  #content-wrapper {
    min-width: var(--extensions-card-width);
    padding: 24px 60px 64px;
  }

  .empty-list-message {
    color: #6e6e6e;
    font-size: 123%;  /* Should be 16px when 100% is 13px. */
    font-weight: 500;
    margin-top: 80px;
    text-align: center;
  }

  @media (prefers-color-scheme: dark) {
    .empty-list-message {
      color: var(--cr-secondary-text-color);
    }
  }

  .items-container {
    --grid-gutter: 12px;
    display: grid;
    grid-column-gap: var(--grid-gutter);
    grid-row-gap: var(--grid-gutter);
    grid-template-columns: repeat(auto-fill, var(--extensions-card-width));
    justify-content: center;
    margin: auto;
    max-width: calc(var(--extensions-card-width) * var(--max-columns) +
        var(--grid-gutter) * var(--max-columns));
  }

  #checkup-container {
    grid-column: 1 / -1;
    /* The checkup card should be at least as tall as an extensions item card.*/
    min-height: var(--extensions-card-height);
  }

  extensions-item {
    grid-column-start: auto;
    grid-row-start: auto;
  }

  #app-title {
    color: var(--cr-primary-text-color);
    font-size: 123%;
    font-weight: 400;
    letter-spacing: .25px;
    margin-bottom: 12px;
    margin-top: 21px;
    padding-bottom: 4px;
    padding-top: 8px;
  }

  managed-footnote {
    border-top: none;
    /* #content-wrapper has a 24px margin-top. This overrides that
     * margin-top, so the only space left is this element's 12px
     * padding-bottom.
     */
    margin-bottom: -24px;
    padding-bottom: 12px;
     padding-top: 12px;
    /* The next element spills over this element. This ensures the link
     * is clickable. */
    z-index: 1;
  }
</style>
<div id="container">
  <managed-footnote hidden="[[filter]]"></managed-footnote>
  <div id="content-wrapper" style="--max-columns: [[maxColumns_]];">
    <div id="no-items" class="empty-list-message"
        hidden$="[[!shouldShowEmptyItemsMessage_(
            apps.length, extensions.length)]]">
      <span on-click="onNoExtensionsTap_">
        $i18nRaw{noExtensionsOrApps}
      </span>
    </div>
    <div id="no-search-results" class="empty-list-message"
        hidden$="[[!shouldShowEmptySearchMessage_(
            shownAppsCount_, shownExtensionsCount_, apps, extensions)]]">
      <span>$i18n{noSearchResults}</span>
    </div>
    <div class="items-container" hidden="[[!shownExtensionsCount_]]">
      <div id="checkup-container" hidden="[[!showCheckup_]]">
        <extensions-checkup id="checkup" slot="view">
        </extensions-checkup>
      </div>
      <!-- Render only a few items first, to improve initial render time,
        then render the remaining items on a different frame. Value of 3
        was chosen by experimentation, and it is a good trade-off between
        initial render time and total render time. -->
      <template is="dom-repeat" items="[[extensions]]" initial-count="3"
          filter="[[computedFilter_]]"
          rendered-item-count="{{shownExtensionsCount_::dom-change}}">
        <extensions-item id="[[item.id]]" data="[[item]]"
            delegate="[[delegate]]" in-dev-mode="[[inDevMode]]">
        </extensions-item>
      </template>
    </div>
    <div hidden="[[!shownAppsCount_]]">
      <!-- app-title needs to left-align with the grid content below, and
           the easiest way to achieve this is to make it a grid as well. -->
      <h2 id="app-title" class="items-container">$i18n{appsTitle}</h2>
      <div class="items-container">
        <template is="dom-repeat" items="[[apps]]" initial-count="3"
            filter="[[computedFilter_]]"
            rendered-item-count="{{shownAppsCount_::dom-change}}">
          <extensions-item id="[[item.id]]" data="[[item]]"
              delegate="[[delegate]]" in-dev-mode="[[inDevMode]]">
          </extensions-item>
        </template>
      </div>
    </div>
  </div>
</div>
<!--_html_template_end_-->`,

  behaviors: [CrContainerShadowBehavior, I18nBehavior],

  properties: {
    /** @type {!Array<!chrome.developerPrivate.ExtensionInfo>} */
    apps: Array,

    /** @type {!Array<!chrome.developerPrivate.ExtensionInfo>} */
    extensions: Array,

    /** @type {ItemDelegate} */
    delegate: Object,

    inDevMode: {
      type: Boolean,
      value: false,
    },

    filter: {
      type: String,
    },

    /** @private */
    computedFilter_: {
      type: String,
      computed: 'computeFilter_(filter)',
      observer: 'announceSearchResults_',
    },

    /** @private */
    maxColumns_: {
      type: Number,
      value: () => loadTimeData.getBoolean('showCheckup') ? 2 : 3,
    },

    /** @private */
    showCheckup_: {
      type: Boolean,
      value: () => loadTimeData.getBoolean('showCheckup'),
    },

    /** @private */
    shownAppsCount_: {
      type: Number,
      value: 0,
    },

    /** @private */
    shownExtensionsCount_: {
      type: Number,
      value: 0,
    },
  },

  /**
   * @param {string} id
   * @return {?Element}
   */
  getDetailsButton(id) {
    const item = this.$$(`#${id}`);
    return item && item.getDetailsButton();
  },

  /**
   * @param {string} id
   * @return {?Element}
   */
  getErrorsButton(id) {
    const item = this.$$(`#${id}`);
    return item && item.getErrorsButton();
  },

  /**
   * Computes the filter function to be used for determining which items
   * should be shown. A |null| value indicates that everything should be
   * shown.
   * return {?Function}
   * @private
   */
  computeFilter_() {
    const formattedFilter = this.filter.trim().toLowerCase();
    return formattedFilter ?
        i => i.name.toLowerCase().includes(formattedFilter) :
        null;
  },

  /** @private */
  shouldShowEmptyItemsMessage_() {
    if (!this.apps || !this.extensions) {
      return;
    }

    return this.apps.length === 0 && this.extensions.length === 0;
  },

  /** @private */
  shouldShowEmptySearchMessage_() {
    return !this.shouldShowEmptyItemsMessage_() && this.shownAppsCount_ === 0 &&
        this.shownExtensionsCount_ === 0;
  },

  /** @private */
  onNoExtensionsTap_(e) {
    if (e.target.tagName === 'A') {
      chrome.metricsPrivate.recordUserAction('Options_GetMoreExtensions');
    }
  },

  /** @private */
  announceSearchResults_() {
    if (this.computedFilter_) {
      IronA11yAnnouncer.requestAvailability();
      this.async(() => {  // Async to allow list to update.
        const total = this.shownAppsCount_ + this.shownExtensionsCount_;
        this.fire('iron-announce', {
          text: this.shouldShowEmptySearchMessage_() ?
              this.i18n('noSearchResults') :
              (total === 1 ?
                   this.i18n('searchResultsSingular', this.filter) :
                   this.i18n(
                       'searchResultsPlural', total.toString(), this.filter)),
        });
      });
    }
  },
});
