// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/md_select_css.m.js';
import './print_preview_shared_css.js';
import './settings_section.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {MarginsType} from '../data/margins.js';

import {SelectBehavior} from './select_behavior.js';
import {SettingsBehavior} from './settings_behavior.js';

Polymer({
  is: 'print-preview-pages-per-sheet-settings',

  _template: html`<!--_html_template_start_-->
<style include="print-preview-shared md-select">
</style>
<print-preview-settings-section>
  <span id="pages-per-sheet-label" slot="title">$i18n{pagesPerSheetLabel}
  </span>
  <div slot="controls">
    <select class="md-select" aria-labelledby="pages-per-sheet-label"
        disabled$="[[disabled]]" value="{{selectedValue::change}}">
      <option value="1" selected>1</option>
      <option value="2">2</option>
      <option value="4">4</option>
      <option value="6">6</option>
      <option value="9">9</option>
      <option value="16">16</option>
    </select>
  </div>
</print-preview-settings-section>
<!--_html_template_end_-->`,

  behaviors: [SettingsBehavior, SelectBehavior],

  properties: {
    disabled: Boolean,
  },

  observers: ['onPagesPerSheetSettingChange_(settings.pagesPerSheet.value)'],

  /**
   * @param {*} newValue The new value of the pages per sheet setting.
   * @private
   */
  onPagesPerSheetSettingChange_(newValue) {
    this.selectedValue = /** @type {number} */ (newValue).toString();
  },

  /** @param {string} value The new select value. */
  onProcessSelectChange(value) {
    this.setSetting('pagesPerSheet', parseInt(value, 10));
  },
});
