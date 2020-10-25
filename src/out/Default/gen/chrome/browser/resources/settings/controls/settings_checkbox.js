// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * `settings-checkbox` is a checkbox that controls a supplied preference.
 */
import 'chrome://resources/cr_elements/cr_checkbox/cr_checkbox.m.js';
import 'chrome://resources/cr_elements/policy/cr_policy_pref_indicator.m.js';
import '../settings_shared_css.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {SettingsBooleanControlBehavior} from './settings_boolean_control_behavior.m.js';

Polymer({
  is: 'settings-checkbox',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared">
      #outerRow {
        align-items: center;
        display: flex;
        min-height: var(--settings-row-two-line-min-height);
        width: 100%;
      }

      #outerRow[noSubLabel] {
        min-height: var(--settings-row-min-height);
      }

      cr-checkbox {
        /* Additional margin in case subLabel needs more than one line. */
        margin-bottom: 4px;
        margin-top: var(--settings-checkbox-margin-top, 4px);
        width: 100%;
      }

      cr-policy-pref-indicator {
        margin-inline-start: var(--settings-controlled-by-spacing);
      }
    </style>
    <div id="outerRow" noSubLabel$="[[!hasSubLabel_(subLabel, subLabelHtml)]]">
      <cr-checkbox id="checkbox" checked="{{checked}}"
          on-change="notifyChangedByUserInteraction"
          disabled="[[controlDisabled(disabled, pref.*)]]"
          aria-label="[[label]]">
        <div id="label" class="label">[[label]] <slot></slot></div>
        <div id="subLabel" class="secondary label">
          <div inner-h-t-m-l="[[subLabelHtml]]"></div>
          [[subLabel]]
        </div>
      </cr-checkbox>
      <template is="dom-if" if="[[pref.controlledBy]]">
        <cr-policy-pref-indicator pref="[[pref]]" icon-aria-label="[[label]]">
        </cr-policy-pref-indicator>
      </template>
    </div>
<!--_html_template_end_-->`,

  behaviors: [SettingsBooleanControlBehavior],

  properties: {
    /**
     * Alternative source for the sub-label that can contain html markup.
     * Only use with trusted input.
     */
    subLabelHtml: {
      type: String,
      value: '',
      observer: 'onSubLabelHtmlChanged_',
    },
  },

  observers: [
    'onSubLabelChanged_(subLabel, subLabelHtml)',
  ],

  /** @private */
  onSubLabelChanged_() {
    this.$.checkbox.ariaDescription = this.$.subLabel.textContent;
  },

  /**
   * Don't let clicks on a link inside the secondary label reach the checkbox.
   * @private
   */
  onSubLabelHtmlChanged_() {
    const links = this.root.querySelectorAll('.secondary.label a');
    links.forEach((link) => {
      link.addEventListener('click', this.stopPropagation);
    });
  },

  /**
   * @param {!Event} event
   * @private
   */
  stopPropagation(event) {
    event.stopPropagation();
  },

  /**
   * @param {string} subLabel
   * @param {string} subLabelHtml
   * @return {boolean} Whether there is a subLabel
   * @private
   */
  hasSubLabel_(subLabel, subLabelHtml) {
    return !!subLabel || !!subLabelHtml;
  },

});
