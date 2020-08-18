// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * `settings-toggle-button` is a toggle that controls a supplied preference.
 */
import {Polymer, html} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '//resources/cr_elements/shared_vars_css.m.js';
import '//resources/cr_elements/cr_toggle/cr_toggle.m.js';
import '//resources/cr_elements/policy/cr_policy_pref_indicator.m.js';
import '//resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import {SettingsBooleanControlBehavior} from './settings_boolean_control_behavior.m.js';
import '../settings_shared_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="settings-shared iron-flex">
      :host {
        align-items: center;
        display: flex;
        padding: 0 var(--cr-section-padding);
      }

      :host([elide-label]),
      :host([elide-label]) #outerRow,
      :host([elide-label]) #outerRow > div.flex {
        min-width: 0;
      }

      :host([elide-label]) .label {
        overflow: hidden;
        text-overflow: ellipsis;
        white-space: nowrap;
      }

      #outerRow {
        align-items: center;
        display: flex;
        min-height: var(--settings-row-two-line-min-height);
        width: 100%;
      }

      #outerRow[noSubLabel] {
        min-height: var(--settings-row-min-height);
      }

      #labelWrapper {
        padding: var(--cr-section-vertical-padding) 0;
      }

      #labelWrapper,
      ::slotted([slot='more-actions']) {
        margin-inline-end: var(--settings-control-label-spacing) !important;
      }

      cr-policy-pref-indicator {
        margin-inline-end: var(--settings-controlled-by-spacing);
      }
    </style>
    <div id="outerRow" noSubLabel$="[[!subLabel]]">
      <div class="flex" id="labelWrapper" hidden$="[[!label]]">
        <div class="label" aria-hidden="true">[[label]]</div>
        <div class="secondary label" id="sub-label">
          <span id="sub-label-text" aria-hidden="true">
            [[subLabel]]
          </span>
          <template is="dom-if" if="[[learnMoreUrl]]">
            <a id="learn-more" href="[[learnMoreUrl]]" target="_blank"
                aria-labeledby="sub-label-text learn-more"
                on-click="onLearnMoreClicked_">
              $i18n{learnMore}
            </a>
          </template>
        </div>
      </div>
      <slot name="more-actions"></slot>
      <template is="dom-if" if="[[hasPrefPolicyIndicator(pref.*)]]">
        <cr-policy-pref-indicator pref="[[pref]]" icon-aria-label="[[label]]">
        </cr-policy-pref-indicator>
      </template>
      <cr-toggle id="control" checked="{{checked}}"
          on-change="onChange_"
          aria-label$="[[getAriaLabel_(label, ariaLabel)]]"
          aria-describedby="sub-label-text"
          disabled="[[controlDisabled(disabled, pref)]]">
      </cr-toggle>
    </div>
<!--_html_template_end_-->`,
  is: 'settings-toggle-button',

  behaviors: [SettingsBooleanControlBehavior],

  properties: {
    ariaLabel: {
      type: String,
      reflectToAttribute: false,  // Handled by #control.
      observer: 'onAriaLabelSet_',
      value: '',
    },

    elideLabel: {
      type: Boolean,
      reflectToAttribute: true,
    },

    learnMoreUrl: {
      type: String,
      reflectToAttribute: true,
    },
  },

  listeners: {
    'click': 'onHostTap_',
  },

  observers: [
    'onDisableOrPrefChange_(disabled, pref.*)',
  ],

  /** @override */
  focus() {
    this.$.control.focus();
  },

  /**
   * Removes the aria-label attribute if it's added by $i18n{...}.
   * @private
   */
  onAriaLabelSet_() {
    if (this.hasAttribute('aria-label')) {
      const ariaLabel = this.ariaLabel;
      this.removeAttribute('aria-label');
      this.ariaLabel = ariaLabel;
    }
  },

  /**
   * @return {string}
   * @private
   */
  getAriaLabel_() {
    return this.label || this.ariaLabel;
  },

  /** @private */
  onDisableOrPrefChange_() {
    if (this.controlDisabled()) {
      this.removeAttribute('actionable');
    } else {
      this.setAttribute('actionable', '');
    }
  },

  /**
   * Handles non cr-toggle button clicks (cr-toggle handles its own click events
   * which don't bubble).
   * @param {!Event} e
   * @private
   */
  onHostTap_(e) {
    e.stopPropagation();
    if (this.controlDisabled()) {
      return;
    }

    this.checked = !this.checked;
    this.notifyChangedByUserInteraction();
    this.fire('change');
  },

  /**
   * @param {!CustomEvent<boolean>} e
   * @private
   */
  onLearnMoreClicked_(e) {
    e.stopPropagation();
    this.fire('learn-more-clicked');
  },

  /**
   * @param {!CustomEvent<boolean>} e
   * @private
   */
  onChange_(e) {
    this.checked = e.detail;
    this.notifyChangedByUserInteraction();
  },
});
