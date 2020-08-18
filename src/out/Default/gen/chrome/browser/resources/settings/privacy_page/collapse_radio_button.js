// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_expand_button/cr_expand_button.m.js';
import 'chrome://resources/cr_elements/cr_radio_button/cr_radio_button_style_css.m.js';
import 'chrome://resources/cr_elements/policy/cr_policy_indicator.m.js';
import 'chrome://resources/polymer/v3_0/iron-collapse/iron-collapse.js';
import '../settings_shared_css.m.js';

import {CrRadioButtonBehavior} from 'chrome://resources/cr_elements/cr_radio_button/cr_radio_button_behavior.m.js';
import {CrPolicyIndicatorType} from 'chrome://resources/cr_elements/policy/cr_policy_indicator_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'settings-collapse-radio-button',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared cr-radio-button-style">
      :host {
        display: block;
      }

      :host([disabled]) {
        opacity: 1;
      }

      cr-policy-indicator,
      cr-policy-pref-indicator,
      :host([disabled]) cr-expand-button {
        pointer-events: auto;
      }

      :host([disabled]) .disc-wrapper {
        opacity: var(--cr-disabled-opacity);
      }

      iron-collapse {
        margin-inline-end: 0;
        margin-inline-start: calc(var(--cr-radio-button-label-spacing, 20px)
            + var(--cr-radio-button-size));
      }

      .disc-wrapper {
        margin-inline-end: var(--cr-radio-button-label-spacing, 20px);
      }

      .separator {
        margin-inline-end: 0;
        min-height: calc(var(--settings-collapse-toggle-min-height, 48px) / 2);
      }

      #borderWrapper {
        align-items: center;
        border-top: var(--settings-collapse-separator-line);
        display: flex;
        min-height: var(--settings-collapse-toggle-min-height);
        width: 100%;
      }

      #labelWrapper {
        --cr-radio-button-label-spacing: 0;
        padding-bottom: 6px;
        padding-top: 6px;
      }

      #radioCollapse {
        align-items: center;
        display: flex;
      }

      slot[name='noSelectionCollapse'] {
       cursor: auto;
      }
    </style>
    <div id="radioCollapse">
      <div aria-checked$="[[getAriaChecked_(checked)]]"
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
      <div id="borderWrapper">
        <div id="labelWrapper">
          <div id="label" aria-hidden="true">
            [[label]]
            <slot name="label"></slot>
          </div>
          <div hidden$="[[!subLabel]]" class="secondary">
            [[subLabel]]
            <slot name="sub-label"></slot>
          </div>
        </div>
        <template is="dom-if" if="[[pref]]">
          <cr-policy-pref-indicator pref="[[pref]]" icon-aria-label="[[label]]"
            associated-value="[[name]]">
          </cr-policy-pref-indicator>
        </template>
        <template is="dom-if"
            if="[[shouldShowPolicyIndicator_(pref, policyIndicatorType)]]">
          <cr-policy-indicator id="policyIndicator"
              on-click="onIndicatorClick_"
              on-aria-label="[[label]]"
              indicator-type="[[policyIndicatorType]]">
          </cr-policy-indicator>
        </template>
        <div hidden$="[[noCollapse]]" class="separator"></div>
        <cr-expand-button hidden$="[[noCollapse]]" expanded="{{expanded}}">
        </cr-expand-button>
      </div>
    </div>

    <iron-collapse opened="[[expanded]]">
      <slot name="collapse"></slot>
      <slot name="noSelectionCollapse"></slot>
    </iron-collapse>

<!--_html_template_end_-->`,

  behaviors: [
    CrRadioButtonBehavior,
  ],

  properties: {
    expanded: {
      type: Boolean,
      notify: true,
      value: false,
    },

    /**
     * Which indicator type to show (or NONE).
     * @type {CrPolicyIndicatorType}
     */
    policyIndicatorType: {
      type: String,
      value: CrPolicyIndicatorType.NONE,
    },

    noCollapse: Boolean,

    label: String,

    /*
     * The Preference associated with the radio group.
     * @type {!chrome.settingsPrivate.PrefObject|undefined}
     */
    pref: Object,

    disabled: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
    },

    subLabel: {
      type: String,
      value: '',  // Allows the $hidden= binding to run without being set.
    },
  },

  observers: [
    'onCheckedChanged_(checked)',
    'onPrefChanged_(pref.*)',
  ],

  /** @private */
  onCheckedChanged_() {
    this.expanded = this.checked;
  },

  /**
   * @param {!Event} e
   * @private
   */
  onIndicatorClick_(e) {
    // Prevent interacting with the indicator changing anything when disabled.
    e.preventDefault();
    e.stopPropagation();
  },

  /** @private */
  onPrefChanged_() {
    // If the preference has been set, and is managed, this control should be
    // disabled. Unless the value associated with this control is present in
    // |pref.userSelectableValues|. This will override the disabled set on the
    // element externally.
    this.disabled = !!this.pref &&
        this.pref.enforcement === chrome.settingsPrivate.Enforcement.ENFORCED &&
        !(!!this.pref.userSelectableValues &&
          this.pref.userSelectableValues.includes(this.name));
  },

  /** @private */
  shouldShowPolicyIndicator_() {
    return !this.pref;
  },
});
