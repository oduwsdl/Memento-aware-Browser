// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {CrRadioButtonBehavior} from '//resources/cr_elements/cr_radio_button/cr_radio_button_behavior.m.js';
import '//resources/cr_elements/cr_radio_button/cr_radio_button_style_css.m.js';
import '//resources/cr_elements/policy/cr_policy_pref_indicator.m.js';
import {assert} from '//resources/js/assert.m.js';
import '//resources/polymer/v3_0/iron-a11y-keys-behavior/iron-a11y-keys-behavior.js';
import {PrefControlBehavior} from './pref_control_behavior.m.js';
import {prefToString} from '../prefs/pref_util.m.js';
import '../settings_shared_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="settings-shared cr-radio-button-style">
      :host([disabled]) {
        opacity: 1;
      }

      /* Disc and label should be transluscent, but not the policy indicator. */
      :host([disabled]) .disc-wrapper,
      :host([disabled]) #labelWrapper {
        opacity: var(--cr-disabled-opacity);
      }

      cr-policy-pref-indicator {
        margin-inline-start: var(--settings-controlled-by-spacing);
        /* Enable pointer events for the indicator so :hover works. Disable
         * clicks/taps via onIndicatorTap_ so outer on-tap doesn't trigger. */
        pointer-events: all;
      }
    </style>

    <div
        aria-checked$="[[getAriaChecked_(checked)]]"
        aria-describedby="slotted-content"
        aria-disabled$="[[getAriaDisabled_(disabled)]]"
        aria-labelledby="label"
        class="disc-wrapper"
        id="button"
        role="radio"
        tabindex$="[[buttonTabIndex_]]"
        on-keydown="onInputKeydown_">
      <div class="disc-border"></div>
      <div class="disc"></div>
    </div>

    <div id="labelWrapper">
      <span id="label" hidden$="[[!label]]">[[label]]</span>
      <span id="slotted-content">
        <slot></slot>
      </span>
    </div>

    <template is="dom-if" if="[[showIndicator_(disabled, name, pref.*)]]">
      <cr-policy-pref-indicator pref="[[pref]]" on-click="onIndicatorTap_"
          icon-aria-label="[[label]]">
      </cr-policy-pref-indicator>
    </template>

<!--_html_template_end_-->`,
  is: 'controlled-radio-button',

  behaviors: [
    PrefControlBehavior,
    CrRadioButtonBehavior,
  ],

  observers: [
    'updateDisabled_(pref.enforcement)',
  ],

  /** @private */
  updateDisabled_() {
    this.disabled =
        this.pref.enforcement === chrome.settingsPrivate.Enforcement.ENFORCED;
  },

  /**
   * @return {boolean}
   * @private
   */
  showIndicator_() {
    return this.disabled &&
        this.name === prefToString(assert(this.pref));
  },

  /**
   * @param {!Event} e
   * @private
   */
  onIndicatorTap_(e) {
    // Disallow <controlled-radio-button on-click="..."> when disabled.
    e.preventDefault();
    e.stopPropagation();
  },
});
