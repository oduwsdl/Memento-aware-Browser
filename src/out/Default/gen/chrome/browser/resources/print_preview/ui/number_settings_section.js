// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_input/cr_input.m.js';
import './print_preview_shared_css.js';
import './print_preview_vars_css.js';
import './settings_section.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {InputBehavior} from './input_behavior.js';

Polymer({
  is: 'print-preview-number-settings-section',

  _template: html`<!--_html_template_start_-->
<style include="print-preview-shared">
  :host {
    /* Width = 3 digits + space + cr-input-padding-end/start */
    --cr-input-width: calc(4em + 16px);
  }

  #sectionTitle {
    align-self: baseline;
  }

  cr-input {
    margin-inline-end: 16px;
    min-height: var(--print-preview-row-height);
    overflow: hidden;
  }

  .input-wrapper {
    align-items: center;
    display: flex;
  }

  :host([input-valid]) cr-input {
    --cr-input-error-display: none;
  }

  span[slot=suffix] {
    max-width: calc(100% - 5em);
    min-height: var(--print-preview-row-height);
    overflow: hidden;
    word-wrap: break-word;
  }
</style>
<print-preview-settings-section>
  <span slot="title" id="sectionTitle">[[inputLabel]]</span>
  <div slot="controls" id="controls">
    <span class="input-wrapper">
      <cr-input id="userValue" type="number"
          max="[[maxValue]]" min="[[minValue]]" data-timeout-delay="250"
          disabled$="[[getDisabled_(disabled)]]" on-keydown="onKeydown_"
          on-blur="onBlur_" aria-label="[[inputAriaLabel]]"
          error-message="[[errorMessage_]]" auto-validate>
        <span slot="suffix">
          <slot name="opt-inside-content"></slot>
        </span>
      </cr-input>
    </span>
  </div>
</print-preview-settings-section>
<!--_html_template_end_-->`,

  behaviors: [InputBehavior],

  properties: {
    /** @private {string} */
    inputString_: {
      type: String,
      notify: true,
      observer: 'onInputChanged_',
    },

    /** @type {boolean} */
    inputValid: {
      type: Boolean,
      notify: true,
      reflectToAttribute: true,
      value: true,
    },

    /** @type {string} */
    currentValue: {
      type: String,
      notify: true,
      observer: 'onCurrentValueChanged_',
    },

    defaultValue: String,

    maxValue: Number,

    minValue: Number,

    inputLabel: String,

    inputAriaLabel: String,

    hintMessage: String,

    disabled: Boolean,

    /** @private */
    errorMessage_: {
      type: String,
      computed: 'computeErrorMessage_(hintMessage, inputValid)',
    },
  },

  listeners: {
    'input-change': 'onInputChange_',
  },

  /** @return {!CrInputElement} The cr-input field element for InputBehavior. */
  getInput() {
    return /** @type {!CrInputElement} */ (this.$.userValue);
  },

  /**
   * @param {!CustomEvent<string>} e Contains the new input value.
   * @private
   */
  onInputChange_(e) {
    this.inputString_ = e.detail;
  },

  /**
   * @return {boolean} Whether the input should be disabled.
   * @private
   */
  getDisabled_() {
    return this.disabled && this.inputValid;
  },

  /**
   * @param {!KeyboardEvent} e The keyboard event
   */
  onKeydown_(e) {
    if (['.', 'e', 'E', '-', '+'].includes(e.key)) {
      e.preventDefault();
      return;
    }

    if (e.key === 'Enter') {
      this.onBlur_();
    }
  },

  /** @private */
  onBlur_() {
    if (this.inputString_ === '') {
      this.set('inputString_', this.defaultValue);
    }
    if (this.$.userValue.value === '') {
      this.$.userValue.value = this.defaultValue;
    }
  },

  /** @private */
  onInputChanged_() {
    this.inputValid = this.computeValid_();
    this.currentValue = this.inputString_;
  },

  /** @private */
  onCurrentValueChanged_() {
    this.inputString_ = this.currentValue;
    this.resetString();
  },

  /**
   * @return {boolean} Whether input value represented by inputString_ is
   *     valid and non-empty, so that it can be used to update the setting.
   * @private
   */
  computeValid_() {
    // Make sure value updates first, in case inputString_ was updated by JS.
    this.$.userValue.value = this.inputString_;
    return !this.$.userValue.invalid;
  },

  /**
   * @return {string}
   * @private
   */
  computeErrorMessage_() {
    return this.inputValid ? '' : this.hintMessage;
  },
});
