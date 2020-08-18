// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/paper-ripple/paper-ripple.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';

import {IronA11yKeysBehavior} from 'chrome://resources/polymer/v3_0/iron-a11y-keys-behavior/iron-a11y-keys-behavior.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {Bookmark} from '../bookmark_type.js';

/** Amount that each level of bookmarks is indented by (px). */
const BOOKMARK_INDENT = 20;

Polymer({
  is: 'viewer-bookmark',

  _template: html`<!--_html_template_start_-->
    <style>
      #item {
        align-items: center;
        cursor: pointer;
        display: flex;
        height: 30px;
        position: relative;
      }

      #item:hover {
        background-color: var(--cr-menu-background-focus-color);
      }

      paper-ripple {
        /* Allowing the ripple to capture pointer events prevents a focus
         * rectangle for showing up for clicks, while still allowing it with
         * tab-navigation. This undoes a paper-ripple bug fix aimed at
         * non-Chrome browsers. TODO(tsergeant): Improve focus in
         * viewer-bookmark so this can be removed (https://crbug.com/5448190).
         */
        pointer-events: auto;
      }

      #title {
        overflow: hidden;
        text-overflow: ellipsis;
        white-space: nowrap;
      }

      #expand {
        --cr-icon-button-fill-color: var(--primary-text-color);
        --cr-icon-button-icon-size: 16px;
        --cr-icon-button-size: 28px;
        margin: 0;
        transition: transform 150ms;
      }

      :host-context([dir=rtl]) #expand {
        transform: rotate(180deg);
      }

      :host([children-shown_]) #expand {
        transform: rotate(90deg);
      }
    </style>
    <div id="item" on-click="onClick_">
      <paper-ripple></paper-ripple>
      <cr-icon-button id="expand" iron-icon="cr:chevron-right"
          on-click="toggleChildren_"></cr-icon-button>
      <span id="title" tabindex="0">[[bookmark.title]]</span>
    </div>
    <!-- dom-if will stamp the complex bookmark tree lazily as individual nodes
      are opened. -->
    <template is="dom-if" if="[[childrenShown_]]">
      <template is="dom-repeat" items="[[bookmark.children]]">
        <viewer-bookmark bookmark="[[item]]" depth="[[childDepth_]]">
        </viewer-bookmark>
      </template>
    </template>
<!--_html_template_end_-->`,

  properties: {
    /** @type {Bookmark} */
    bookmark: {
      type: Object,
      observer: 'bookmarkChanged_',
    },

    depth: {
      type: Number,
      observer: 'depthChanged_'
    },

    /** @private */
    childDepth_: Number,

    /** @private */
    childrenShown_: {
      type: Boolean,
      reflectToAttribute: true,
      value: false,
    },

    /** @type {?EventTarget} The target for the key bindings below. */
    keyEventTarget: Object,
  },

  behaviors: [IronA11yKeysBehavior],

  keyBindings: {'enter': 'onEnter_', 'space': 'onSpace_'},

  /** @override */
  attached() {
    this.keyEventTarget = this.$.item;
  },

  /** @private */
  bookmarkChanged_() {
    this.$.expand.style.visibility =
        this.bookmark.children.length > 0 ? 'visible' : 'hidden';
  },

  /** @private */
  depthChanged_() {
    this.childDepth_ = this.depth + 1;
    this.$.item.style.paddingInlineStart =
        (this.depth * BOOKMARK_INDENT) + 'px';
  },

  /** @private */
  onClick_() {
    if (this.bookmark.page != null) {
      if (this.bookmark.zoom != null) {
        this.fire('change-zoom', {zoom: this.bookmark.zoom});
      }
      if (this.bookmark.x != null &&
          this.bookmark.y != null) {
        this.fire('change-page-and-xy', {
          page: this.bookmark.page,
          x: this.bookmark.x,
          y: this.bookmark.y,
          origin: 'bookmark'
        });
      } else {
        this.fire(
            'change-page', {page: this.bookmark.page, origin: 'bookmark'});
      }
    } else if (this.bookmark.uri != null) {
      this.fire('navigate', {uri: this.bookmark.uri, newtab: true});
    }
  },

  /**
   * @param {!KeyboardEvent} e
   * @private
   */
  onEnter_(e) {
    // Don't allow events which have propagated up from the expand button to
    // trigger a click.
    if (e.detail.keyboardEvent.target !== this.$.expand) {
      this.onClick_();
    }
  },

  /**
   * @param {!KeyboardEvent} e
   * @private
   */
  onSpace_(e) {
    // cr-icon-button stops propagation of space events, so there's no need
    // to check the event source here.
    this.onClick_();
    // Prevent default space scroll behavior.
    e.detail.keyboardEvent.preventDefault();
  },

  /**
   * @param {!Event} e
   * @private
   */
  toggleChildren_(e) {
    this.childrenShown_ = !this.childrenShown_;
    e.stopPropagation();  // Prevent the above onClick_ handler from firing.
  }
});
