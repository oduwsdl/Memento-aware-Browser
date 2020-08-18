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
  is: 'print-preview-layout-settings',

  _template: html`<!--_html_template_start_-->
<style include="print-preview-shared md-select"></style>
<print-preview-settings-section>
  <span id="layout-label" slot="title">$i18n{layoutLabel}</span>
  <div slot="controls">
    <select class="md-select" aria-labelledby="layout-label"
        disabled$="[[disabled]]" value="{{selectedValue::change}}">
      <option value="portrait" selected>$i18n{optionPortrait}</option>
      <option value="landscape">$i18n{optionLandscape}</option>
    </select>
  </div>
</print-preview-settings-section>
<!--_html_template_end_-->`,

  behaviors: [SettingsBehavior, SelectBehavior],

  properties: {
    disabled: Boolean,
  },

  observers: ['onLayoutSettingChange_(settings.layout.value)'],

  /**
   * @param {*} newValue The new value of the layout setting.
   * @private
   */
  onLayoutSettingChange_(newValue) {
    this.selectedValue =
        /** @type {boolean} */ (newValue) ? 'landscape' : 'portrait';
  },

  /** @param {string} value The new select value. */
  onProcessSelectChange(value) {
    this.setSetting('layout', value === 'landscape');
  },
});
