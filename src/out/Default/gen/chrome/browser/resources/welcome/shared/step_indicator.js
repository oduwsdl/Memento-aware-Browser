// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview This element contains a set of SVGs that together acts as an
 * animated and responsive background for any page that contains it.
 */
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import './navi_colors_css.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {stepIndicatorModel} from './nux_types.js';

Polymer({
  is: 'step-indicator',

  _template: html`<!--_html_template_start_-->
<style include="navi-colors-css">
  :host {
    align-items: center;
    display: flex;
  }

  span {
    background: var(--navi-step-indicator-color);
    border-radius: 50%;
    display: inline-block;
    height: 8px;
    margin: 0 4px;
    width: 8px;
  }

  span.active {
    background: var(--navi-step-indicator-active-color);
  }
</style>
<template is="dom-repeat" items="[[dots_]]">
  <span class$="[[getActiveClass_(index, model.active)]]"></span>
</template>
<!--_html_template_end_-->`,

  properties: {
    /** @type {stepIndicatorModel} */
    model: Object,

    /** @private */
    dots_: {
      type: Array,
      computed: 'computeDots_(model.total)',
    },
  },

  /**
   * @return {!Array<undefined>}
   * @private
   */
  computeDots_() {
    // If total is 1, show nothing.
    return new Array(this.model.total > 1 ? this.model.total : 0);
  },

  /**
   * @param {number} index
   * @return {string}
   * @private
   */
  getActiveClass_(index) {
    return index === this.model.active ? 'active' : '';
  },
});
