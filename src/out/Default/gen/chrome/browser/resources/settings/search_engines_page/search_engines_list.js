// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'settings-search-engines-list' is a component for showing a
 * list of search engines.
 */
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-list/iron-list.js';
import '../settings_shared_css.m.js';
import '../settings_vars_css.m.js';
import './search_engine_entry.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {SearchEngine} from './search_engines_browser_proxy.m.js';

Polymer({
  is: 'settings-search-engines-list',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared">
      #headers {
        display: flex;
        padding: 10px 0;
      }

      #headers .name,
      #headers .keyword {
        flex: 3;
      }

      #headers .url {
        flex: 4;
      }

      settings-search-engine-entry {
        border-top: var(--cr-separator-line);
      }

      :host([fixed-height]) #container {
        /* Max items we show before scrolling is 6. Adding a 7th item to the
         * list will add a scroll bar to the container. */
        max-height: calc((var(--settings-row-min-height) +
                          var(--cr-separator-height)) * 6);
      }

      .icon-placeholder {
        margin-inline-end: 0;
        margin-inline-start: var(--cr-icon-button-margin-start);
        width: var(--cr-icon-ripple-size);
      }
    </style>
    <div id="outer" class="list-frame">
      <div id="headers" class="column-header">
        <div class="name">$i18n{searchEnginesSearchEngine}</div>
        <div class="keyword">$i18n{searchEnginesKeyword}</div>
        <div class="url">$i18n{searchEnginesQueryURL}</div>
        <div class="icon-placeholder"></div>
      </div>
      <div id="container" class="scroll-container"
          scrollable$="[[fixedHeight]]">
        <iron-list items="[[engines]]" scroll-target="[[scrollTarget]]"
            scroll-offset="[[scrollOffset]]" preserve-focus risk-selection>
          <template>
            <settings-search-engine-entry engine="[[item]]"
                focus-row-index="[[index]]"
                tabindex$="[[tabIndex]]" iron-list-tab-index="[[tabIndex]]"
                last-focused="{{lastFocused_}}" list-blurred="{{listBlurred_}}">
            </settings-search-engine-entry>
          </template>
        </iron-list>
      </div>
    </div>
<!--_html_template_end_-->`,

  properties: {
    /** @type {!Array<!SearchEngine>} */
    engines: Array,

    /**
     * The scroll target that this list should use.
     * @type {?HTMLElement}
     */
    scrollTarget: Object,

    /** Used to fix scrolling glitch when list is not top most element. */
    scrollOffset: Number,

    /** @private {Object}*/
    lastFocused_: Object,

    /** @private */
    listBlurred_: Boolean,

    fixedHeight: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
    },
  },
});
