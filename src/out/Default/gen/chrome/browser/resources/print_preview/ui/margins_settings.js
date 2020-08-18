// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/md_select_css.m.js';
import './print_preview_shared_css.js';
import './settings_section.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {MarginsType} from '../data/margins.js';
import {State} from '../data/state.js';

import {SelectBehavior} from './select_behavior.js';
import {SettingsBehavior} from './settings_behavior.js';

Polymer({
  is: 'print-preview-margins-settings',

  _template: html`<!--_html_template_start_-->
<style include="print-preview-shared md-select">
</style>
<print-preview-settings-section>
  <span id="margins-label" slot="title">$i18n{marginsLabel}</span>
  <div slot="controls">
    <select class="md-select" aria-labelledby="margins-label"
        disabled$="[[marginsDisabled_]]"
        value="{{selectedValue::change}}">
      <!-- The order of these options must match the natural order of their
      values, which come from MarginsType. -->
      <option value="[[MarginsTypeEnum.DEFAULT]]" selected>
        $i18n{defaultMargins}
      </option>
      <option value="[[MarginsTypeEnum.NO_MARGINS]]">
        $i18n{noMargins}
      </option>
      <option value="[[MarginsTypeEnum.MINIMUM]]">
        $i18n{minimumMargins}
      </option>
      <option value="[[MarginsTypeEnum.CUSTOM]]">
        $i18n{customMargins}
      </option>
    </select>
  </div>
</print-preview-settings-section>
<!--_html_template_end_-->`,

  behaviors: [SettingsBehavior, SelectBehavior],

  properties: {
    disabled: {
      type: Boolean,
      observer: 'updateMarginsDisabled_',
    },

    /** @type {!State} */
    state: {
      type: Number,
      observer: 'onStateChange_',
    },

    /** @private */
    marginsDisabled_: Boolean,

    /** Mirroring the enum so that it can be used from HTML bindings. */
    MarginsTypeEnum: Object,
  },

  observers: [
    'onMarginsSettingChange_(settings.margins.value)',
    'onMediaSizeOrLayoutChange_(' +
        'settings.mediaSize.value, settings.layout.value)',
    'onPagesPerSheetSettingChange_(settings.pagesPerSheet.value)'
  ],

  /** @private {boolean} */
  loaded_: false,

  /** @override */
  ready() {
    this.MarginsTypeEnum = MarginsType;
  },

  /** @private */
  onStateChange_() {
    if (this.state === State.READY) {
      this.loaded_ = true;
    }
  },

  /** @private */
  onMediaSizeOrLayoutChange_() {
    if (this.loaded_ &&
        this.getSetting('margins').value === MarginsType.CUSTOM) {
      this.setSetting('margins', MarginsType.DEFAULT);
    }
  },

  /**
   * @param {number} newValue The new value of the pages per sheet setting.
   * @private
   */
  onPagesPerSheetSettingChange_(newValue) {
    if (newValue > 1) {
      this.setSetting('margins', MarginsType.DEFAULT);
    }
    this.updateMarginsDisabled_();
  },

  /** @param {*} newValue The new value of the margins setting. */
  onMarginsSettingChange_(newValue) {
    this.selectedValue =
        /** @type {!MarginsType} */ (newValue).toString();
  },

  /** @param {string} value The new select value. */
  onProcessSelectChange(value) {
    this.setSetting('margins', parseInt(value, 10));
  },

  /** @private */
  updateMarginsDisabled_() {
    this.marginsDisabled_ =
        /** @type {number} */ (this.getSettingValue('pagesPerSheet')) > 1 ||
        this.disabled;
  },
});
