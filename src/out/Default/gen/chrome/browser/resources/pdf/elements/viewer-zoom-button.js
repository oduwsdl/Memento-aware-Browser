// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/polymer/v3_0/paper-styles/shadow.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'viewer-zoom-button',

  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        --translate-x-distance: 132px;
      }

      :host-context([is-print-preview]) {
        --translate-x-distance: 96px;
      }

      #wrapper {
        transition: transform 250ms;
        transition-timing-function: cubic-bezier(0, 0, 0.2, 1);
      }

      :host([closed_]) #wrapper {
        /* 132px roughly flips the location of the button across the right edge
         * of the page. */
        transform: translateX(var(--translate-x-distance));
        transition-timing-function: cubic-bezier(0.4, 0, 1, 1);
      }

      :host-context([is-print-preview][dir='ltr']):host([closed_]) #wrapper {
        transform: translateX(calc(-1 * var(--translate-x-distance)));
      }

      :host-context([dir='rtl']):host([closed_]) #wrapper {
        transform: translateX(calc(-1 * var(--translate-x-distance)));
      }

      :host-context([is-print-preview][dir='rtl']):host([closed_]) #wrapper {
        transform: translateX(var(--translate-x-distance));
      }

      cr-icon-button {
        --cr-icon-button-fill-color: var(--paper-grey-700);
        --cr-icon-button-icon-size: 20px;
        --cr-icon-button-size: 36px;
        background-color: rgb(242, 242, 242);
        border-radius: 50%;
        box-shadow: var(--cr-elevation-1);
        overflow: visible;
      }

      cr-icon-button([disabled]) {
        box-shadow: none;
      }

      :host-context([is-print-preview]) cr-icon-button {
        --cr-icon-button-fill-color: white;
        --cr-icon-button-size: 32px;
        background-color: var(--google-grey-600);
      }

      @media (prefers-color-scheme: light) {
        :host-context([is-print-preview]) cr-icon-button {
          --cr-icon-button-ripple-opacity: .5;
        }
      }

      @media (prefers-color-scheme: dark) {
        :host-context([is-print-preview]) cr-icon-button {
          --cr-icon-button-fill-color: var(--google-grey-200);
          background-color: var(--google-grey-900);
        }
      }

      :host([keyboard-navigation-active]) cr-icon-button:focus {
        box-shadow: var(--cr-elevation-4);
      }

      cr-icon-button:active {
        box-shadow: var(--cr-elevation-5);
      }
    </style>
    <div id="wrapper">
      <cr-icon-button iron-icon="[[visibleIcon_]]" on-click="fireClick_"
          aria-label$="[[visibleTooltip_]]" title="[[visibleTooltip_]]"
          disabled="[[disabled]]">
      </cr-icon-button>
    </div>
<!--_html_template_end_-->`,

  properties: {
    /** Index of the icon currently being displayed. */
    activeIndex: {
      type: Number,
      value: 0,
    },

    delay: {
      type: Number,
      observer: 'delayChanged_',
    },

    disabled: {
      type: Boolean,
      value: false,
    },

    /**
     * Icons to be displayed on the FAB. Multiple icons should be separated with
     * spaces, and will be cycled through every time the FAB is clicked.
     */
    icons: String,

    /**
     * Used to show the appropriate drop shadow when buttons are focused with
     * the keyboard.
     */
    keyboardNavigationActive: {
      type: Boolean,
      reflectToAttribute: true,
    },

    /** @type {?Array<string>} */
    tooltips: Array,

    /** @private */
    closed_: {
      type: Boolean,
      reflectToAttribute: true,
      value: false,
    },

    /**
     * Array version of the list of icons. Polymer does not allow array
     * properties to be set from HTML, so we must use a string property and
     * perform the conversion manually.
     * @private {!Array<string>}
     */
    icons_: {
      type: Array,
      value: [''],
      computed: 'computeIconsArray_(icons)',
    },

    /**
     * Icon currently being displayed on the FAB.
     * @private
     */
    visibleIcon_: {
      type: String,
      computed: 'computeVisibleIcon_(icons_, activeIndex)',
    },

    /** @private */
    visibleTooltip_: {
      type: String,
      computed: 'computeVisibleTooltip_(tooltips, activeIndex)',
    }
  },

  /**
   * @param {string} icons Icon names in a string, delimited by spaces
   * @return {!Array<string>} Array of icon name strings
   * @private
   */
  computeIconsArray_(icons) {
    return icons.split(' ');
  },

  /**
   * @param {!Array<string>} icons Array of icon name strings.
   * @param {number} activeIndex Index of the currently active icon.
   * @return {string} Icon name for the currently visible icon.
   * @private
   */
  computeVisibleIcon_(icons, activeIndex) {
    return icons[activeIndex];
  },

  /**
   * @param {?Array<string>} tooltips Array of tooltip strings.
   * @param {number} activeIndex Index of the currently active icon.
   * @return {string} Tooltip for the currently visible icon.
   * @private
   */
  computeVisibleTooltip_(tooltips, activeIndex) {
    return tooltips === undefined ? '' : tooltips[activeIndex];
  },

  /** @private */
  delayChanged_() {
    this.$.wrapper.style.transitionDelay = this.delay + 'ms';
  },

  show() {
    this.closed_ = false;
  },

  hide() {
    this.closed_ = true;
  },

  /** @private */
  fireClick_() {
    // We cannot attach an on-click to the entire viewer-zoom-button, as this
    // will include clicks on the margins. Instead, proxy clicks on the FAB
    // through.
    this.fire('fabclick');

    this.activeIndex = (this.activeIndex + 1) % this.icons_.length;
  }
});
