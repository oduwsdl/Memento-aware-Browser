// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {assert} from 'chrome://resources/js/assert.m.js';
import {isRTL} from 'chrome://resources/js/util.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'viewer-page-indicator',

  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        display: flex;
        pointer-events: none;
        position: fixed;
        right: 0;
        transition: opacity 400ms ease-in-out;
      }

      :host-context([dir=rtl]) {
        left: 0;
        right: auto;
      }

      #text {
        background-color: rgba(0, 0, 0, 0.5);
        border-radius: 5px;
        color: white;
        font-family: sans-serif;
        font-size: 12px;
        font-weight: bold;
        line-height: 48px;
        text-align: center;
        text-shadow: 1px 1px 1px rgba(0, 0, 0, 0.8);
        width: 62px;
      }

      #triangle-end {
        border-bottom: 6px solid transparent;
        border-inline-start: 8px solid rgba(0, 0, 0, 0.5);
        border-top: 6px solid transparent;
        height: 0;
        margin-top: 18px;
        width: 0;
      }
    </style>
    <div id="text">[[label]]</div>
    <div id="triangle-end"></div>
<!--_html_template_end_-->`,

  properties: {
    label: {type: String, value: '1'},

    index: {type: Number, observer: 'indexChanged'},

    pageLabels: {type: Array, value: null, observer: 'pageLabelsChanged'}
  },

  /** @type {number|undefined} */
  timerId: undefined,

  /** @override */
  ready() {
    const callback = this.fadeIn_.bind(this);
    window.addEventListener('scroll', function() {
      requestAnimationFrame(callback);
    });
  },

  /** @private */
  fadeIn_() {
    const percent = window.scrollY /
        (document.scrollingElement.scrollHeight -
         document.documentElement.clientHeight);
    this.style.top =
        percent * (document.documentElement.clientHeight - this.offsetHeight) +
        'px';
    // <if expr="is_macosx">
    // If overlay scrollbars are enabled, prevent them from overlapping the
    // triangle. TODO(dbeam): various platforms can enable overlay scrolling,
    // not just Mac. The scrollbars seem to have different widths/appearances on
    // those platforms, though.
    assert(document.documentElement.dir);
    const endEdge = isRTL() ? 'left' : 'right';
    if (window.innerWidth === document.scrollingElement.scrollWidth) {
      this.style[endEdge] = '16px';
    } else {
      this.style[endEdge] = '0px';
    }
    // </if>
    this.style.opacity = 1;
    clearTimeout(this.timerId);

    this.timerId = setTimeout(() => {
      this.style.opacity = 0;
      this.timerId = undefined;
    }, 2000);
  },

  pageLabelsChanged() {
    this.indexChanged();
  },

  indexChanged() {
    if (this.pageLabels) {
      this.label = this.pageLabels[this.index];
    } else {
      this.label = String(this.index + 1);
    }
  }
});
