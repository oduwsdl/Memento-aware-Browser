// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_checkbox/cr_checkbox.m.js';
import './number_settings_section.js';
import './print_preview_shared_css.js';

import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {SettingsBehavior} from './settings_behavior.js';

/**
 * Maximum number of copies supported by the printer if not explicitly
 * specified.
 * @type {number}
 */
export const DEFAULT_MAX_COPIES = 999;

Polymer({
  is: 'print-preview-copies-settings',

  _template: html`<!--_html_template_start_-->
<style include="print-preview-shared">
   #collate {
     margin-inline-start: 16px;
   }
</style>
<print-preview-number-settings-section max-value="[[copiesMax_]]" min-value="1"
    default-value="1" input-label="$i18n{copiesLabel}"
    input-aria-label="$i18n{copiesLabel}"
    disabled="[[disabled]]" current-value="{{currentValue_}}"
    input-valid="{{inputValid_}}"
    hint-message="[[getHintMessage_(copiesMax_)]]">
  <div slot="opt-inside-content" class="checkbox" aria-live="polite"
      hidden$="[[collateHidden_(
        currentValue_, settings.collate.available, inputValid_)]]">
    <cr-checkbox id="collate" on-change="onCollateChange_"
        disabled="[[disabled]]" aria-labelledby="copies-collate-label">
      <span id="copies-collate-label">$i18n{optionCollate}</span>
    </cr-checkbox>
  </div>
</print-preview-number-settings-section>
<!--_html_template_end_-->`,

  behaviors: [SettingsBehavior],

  properties: {
    capability: Object,

    /** @private {number} */
    copiesMax_: {
      type: Number,
      computed: 'computeCopiesMax_(capability)',
    },

    /** @private {string} */
    currentValue_: {
      type: String,
      observer: 'onInputChanged_',
    },

    /** @private {boolean} */
    inputValid_: Boolean,

    disabled: Boolean,
  },

  observers: ['onSettingsChanged_(settings.copies.value, settings.collate.*)'],

  /**
   * @return {number} The maximum number of copies this printer supports.
   * @private
   */
  computeCopiesMax_() {
    return (this.capability && this.capability.max) ? this.capability.max :
                                                      DEFAULT_MAX_COPIES;
  },

  /**
   * @return {string} The message to show as hint.
   * @private
   */
  getHintMessage_() {
    return loadTimeData.getStringF('copiesInstruction', this.copiesMax_);
  },

  /**
   * Updates the input string when the setting has been initialized.
   * @private
   */
  onSettingsChanged_() {
    const copies = this.getSetting('copies');
    if (this.inputValid_) {
      this.currentValue_ = /** @type {string} */ (copies.value.toString());
    }
    const collate = this.getSetting('collate');
    this.$.collate.checked = /** @type {boolean} */ (collate.value);
  },

  /**
   * Updates model.copies and model.copiesInvalid based on the validity
   * and current value of the copies input.
   * @private
   */
  onInputChanged_() {
    if (this.currentValue_ !== '' &&
        this.currentValue_ !== this.getSettingValue('copies').toString()) {
      this.setSetting(
          'copies', this.inputValid_ ? parseInt(this.currentValue_, 10) : 1);
    }
    this.setSettingValid('copies', this.inputValid_);
  },

  /**
   * @return {boolean} Whether collate checkbox should be hidden.
   * @private
   */
  collateHidden_() {
    return !this.getSetting('collate').available || !this.inputValid_ ||
        this.currentValue_ === '' || parseInt(this.currentValue_, 10) === 1;
  },

  /** @private */
  onCollateChange_() {
    this.setSetting('collate', this.$.collate.checked);
  },
});
