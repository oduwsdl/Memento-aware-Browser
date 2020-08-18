// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/md_select_css.m.js';
import './print_preview_shared_css.js';
import './settings_section.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {SelectBehavior} from './select_behavior.js';
import {SettingsBehavior} from './settings_behavior.js';

Polymer({
  is: 'print-preview-color-settings',

  _template: html`<!--_html_template_start_-->
<style include="print-preview-shared md-select">
</style>
<print-preview-settings-section>
  <span id="color-label" slot="title">$i18n{optionColor}</span>
  <div slot="controls">
    <select class="md-select" aria-labelledby="color-label"
        disabled$="[[disabled_]]" value="{{selectedValue::change}}">
      <option value="bw" selected>$i18n{optionBw}</option>
      <option value="color">$i18n{optionColor}</option>
    </select>
  </div>
</print-preview-settings-section>
<!--_html_template_end_-->`,

  behaviors: [SettingsBehavior, SelectBehavior],

  properties: {
    disabled: Boolean,

    /** @private {boolean} */
    disabled_: {
      type: Boolean,
      computed: 'computeDisabled_(disabled, settings.color.setByPolicy)',
    },
  },

  observers: ['onColorSettingChange_(settings.color.value)'],

  /**
   * @param {*} newValue The new value of the color setting.
   * @private
   */
  onColorSettingChange_(newValue) {
    this.selectedValue = /** @type {boolean} */ (newValue) ? 'color' : 'bw';
  },

  /**
   * @param {boolean} disabled Whether color selection is disabled.
   * @param {boolean} managed Whether color selection is managed.
   * @return {boolean} Whether drop-down should be disabled.
   * @private
   */
  computeDisabled_(disabled, managed) {
    return !!(disabled || managed);
  },

  /** @param {string} value The new select value. */
  onProcessSelectChange(value) {
    this.setSetting('color', value === 'color');
  },
});
