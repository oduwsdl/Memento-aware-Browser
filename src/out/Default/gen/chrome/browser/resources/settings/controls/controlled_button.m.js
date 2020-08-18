// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '//resources/cr_elements/cr_button/cr_button.m.js';
import {CrPolicyPrefBehavior} from '//resources/cr_elements/policy/cr_policy_pref_behavior.m.js';
import '//resources/cr_elements/policy/cr_policy_pref_indicator.m.js';
import '//resources/cr_elements/shared_vars_css.m.js';
import {PrefControlBehavior} from './pref_control_behavior.m.js';
import {loadTimeData} from '../i18n_setup.js';
import '../settings_shared_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="settings-shared">
      :host {
        --justify-margin: 8px;
        align-items: center;
        display: flex;
      }

      :host([enforced_]) {
        /* Disable pointer events for this whole element, as outer on-tap gets
         * triggered when clicking/tapping anywhere in :host. */
        pointer-events: none;
      }

      cr-policy-pref-indicator {
        /* Enable pointer events for the indicator so :hover works. Disable
         * clicks/taps via onIndicatorTap_ so outer on-tap doesn't trigger. */
        pointer-events: all;
      }

      :host(:not([end-justified])) cr-policy-pref-indicator {
        margin-inline-start: var(--cr-controlled-by-spacing);
      }

      :host([end-justified]) cr-policy-pref-indicator {
        margin-inline-end: var(--cr-controlled-by-spacing);
        margin-inline-start: calc(
            var(--cr-controlled-by-spacing) - var(--justify-margin));
        order: -1;
      }
    </style>

    <cr-button class$="[[actionClass_]]"
      disabled="[[!buttonEnabled_(enforced_, disabled)]]">
      [[label]]
    </cr-button>

    <template is="dom-if" if="[[hasPrefPolicyIndicator(pref.*)]]" restamp>
      <cr-policy-pref-indicator pref="[[pref]]" on-click="onIndicatorTap_"
          icon-aria-label="[[label]]">
      </cr-policy-pref-indicator>
    </template>

<!--_html_template_end_-->`,
  is: 'controlled-button',

  behaviors: [
    CrPolicyPrefBehavior,
    PrefControlBehavior,
  ],

  properties: {
    endJustified: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
    },

    label: String,

    disabled: {
      type: Boolean,
      value: false,
      reflectToAttribute: true,
    },

    /** @private */
    actionClass_: {type: String, value: ''},

    /** @private */
    enforced_: {
      type: Boolean,
      computed: 'isPrefEnforced(pref.*)',
      reflectToAttribute: true,
    },
  },

  /** @override */
  attached() {
    if (this.classList.contains('action-button')) {
      this.actionClass_ = 'action-button';
    }
  },

  /** Focus on the inner cr-button. */
  focus() {
    this.$$('cr-button').focus();
  },

  /**
   * @param {!Event} e
   * @private
   */
  onIndicatorTap_(e) {
    // Disallow <controlled-button on-click="..."> when controlled.
    e.preventDefault();
    e.stopPropagation();
  },

  /**
   * @param {!boolean} enforced
   * @param {!boolean} disabled
   * @return {boolean} True if the button should be enabled.
   * @private
   */
  buttonEnabled_(enforced, disabled) {
    return !enforced && !disabled;
  }
});
