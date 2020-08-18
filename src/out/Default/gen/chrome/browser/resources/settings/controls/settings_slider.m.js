// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * settings-slider wraps a cr-slider. It maps the slider's values from a
 * linear UI range to a range of real values.  When |value| does not map exactly
 * to a tick mark, it interpolates to the nearest tick.
 */
import {Polymer, html} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {CrPolicyPrefBehavior} from '//resources/cr_elements/policy/cr_policy_pref_behavior.m.js';
import {assert} from '//resources/js/assert.m.js';
import {SliderTick} from '//resources/cr_elements/cr_slider/cr_slider.m.js';
import '../settings_vars_css.m.js';
import {loadTimeData} from '../i18n_setup.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style>
      :host {
        display: inline-flex;
      }

      cr-policy-pref-indicator {
        align-self: center;
        margin-inline-start: var(--settings-controlled-by-spacing);
      }

      #labels[disabled] {
        color: var(--paper-grey-400);
      }

      @media (prefers-color-scheme: dark) {
        #labels[disabled] {
          color: var(--google-grey-refresh-500);
        }
      }

      div.outer {
        align-items: stretch;
        display: flex;
        flex-direction: column;
        margin: 8px 0;
        min-width: 200px;
      }

      #labels {
        display: flex;
        flex-direction: row;
        justify-content: space-between;
        margin: -4px 16px 0 16px;
      }

      #labels > div {
        font-size: 12px;
      }

      #label-begin {
        margin-inline-end: 4px;
      }

      #label-end {
        margin-inline-start: 4px;
      }
    </style>
    <template is="dom-if" if="[[pref.controlledBy]]" restamp>
      <cr-policy-pref-indicator pref="[[pref]]"></cr-policy-pref-indicator>
    </template>
    <div class="outer">
      <cr-slider id="slider" disabled$="[[disableSlider_]]" ticks="[[ticks]]"
          on-cr-slider-value-changed="onSliderChanged_" max="[[max]]"
          min="[[min]]" on-dragging-changed="onSliderChanged_"
          on-updating-from-key="onSliderChanged_"
          aria-roledescription$="[[getRoleDescription_()]]"
          aria-label$="[[labelAria]]">
      </cr-slider>
      <!-- aria-hidden because role description on #slider contains min/max. -->
      <div id="labels" disabled$="[[disableSlider_]]" aria-hidden="true">
        <div id="label-begin">[[labelMin]]</div>
        <div id="label-end">[[labelMax]]</div>
      </div>
    </div>
<!--_html_template_end_-->`,
  is: 'settings-slider',

  behaviors: [CrPolicyPrefBehavior],

  properties: {
    /** @type {!chrome.settingsPrivate.PrefObject} */
    pref: Object,

    /**
     * Values corresponding to each tick.
     * @type {!Array<SliderTick>|!Array<number>}
     */
    ticks: {
      type: Array,
      value: () => [],
    },

    /**
     * A scale factor used to support fractional pref values. This is not
     * compatible with |ticks|, i.e. if |scale| is not 1 then |ticks| must be
     * empty.
     */
    scale: {
      type: Number,
      value: 1,
    },

    min: Number,

    max: Number,

    labelAria: String,

    labelMin: String,

    labelMax: String,

    disabled: Boolean,

    showMarkers: Boolean,

    /** @private */
    disableSlider_: {
      computed: 'computeDisableSlider_(pref.*, disabled, ticks.*)',
      type: Boolean,
    },

    updateValueInstantly: {
      type: Boolean,
      value: true,
      observer: 'onSliderChanged_',
    },

    loaded_: Boolean,
  },

  observers: [
    'valueChanged_(pref.*, ticks.*, loaded_)',
  ],

  attached() {
    this.loaded_ = true;
  },

  /**
   * @param {number|SliderTick} tick
   * @return {number|undefined}
   */
  getTickValue_(tick) {
    return typeof tick === 'object' ? tick.value : tick;
  },

  /**
   * @param {number} index
   * @return {number|undefined}
   * @private
   */
  getTickValueAtIndex_(index) {
    return this.getTickValue_(this.ticks[index]);
  },

  /**
   * Sets the |pref.value| property to the value corresponding to the knob
   * position after a user action.
   * @private
   */
  onSliderChanged_() {
    if (!this.loaded_) {
      return;
    }

    if (this.$.slider.dragging && !this.updateValueInstantly) {
      return;
    }

    const sliderValue = this.$.slider.value;

    let newValue;
    if (this.ticks && this.ticks.length > 0) {
      newValue = this.getTickValueAtIndex_(sliderValue);
    } else {
      newValue = sliderValue / this.scale;
    }

    this.set('pref.value', newValue);
  },

  /** @private */
  computeDisableSlider_() {
    return this.disabled || this.isPrefEnforced();
  },

  /**
   * Updates the knob position when |pref.value| changes. If the knob is still
   * being dragged, this instead forces |pref.value| back to the current
   * position.
   * @private
   */
  valueChanged_() {
    if (this.pref === undefined || !this.loaded_ || this.$.slider.dragging ||
        this.$.slider.updatingFromKey) {
      return;
    }

    // First update the slider settings if |ticks| was set.
    const numTicks = this.ticks.length;
    if (numTicks === 1) {
      this.$.slider.disabled = true;
      return;
    }

    const prefValue = /** @type {number} */ (this.pref.value);

    // The preference and slider values are continuous when |ticks| is empty.
    if (numTicks === 0) {
      this.$.slider.value = prefValue * this.scale;
      return;
    }

    assert(this.scale === 1);
    // Limit the number of ticks to 10 to keep the slider from looking too busy.
    const MAX_TICKS = 10;
    this.$.slider.markerCount =
        (this.showMarkers || numTicks <= MAX_TICKS) ? numTicks : 0;

    // Convert from the public |value| to the slider index (where the knob
    // should be positioned on the slider).
    const index =
        this.ticks.map(tick => Math.abs(this.getTickValue_(tick) - prefValue))
            .reduce(
                (acc, diff, index) => diff < acc.diff ? {index, diff} : acc,
                {index: -1, diff: Number.MAX_VALUE})
            .index;
    assert(index !== -1);
    if (this.$.slider.value !== index) {
      this.$.slider.value = index;
    }
    const tickValue = this.getTickValueAtIndex_(index);
    if (this.pref.value !== tickValue) {
      this.set('pref.value', tickValue);
    }
  },

  /**
   * @return {string}
   * @private
   */
  getRoleDescription_() {
    return loadTimeData.getStringF(
        'settingsSliderRoleDescription', this.labelMin, this.labelMax);
  },
});
