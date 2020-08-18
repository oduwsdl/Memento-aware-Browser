// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/cr_elements/cr_expand_button/cr_expand_button.m.js';
import '../strings.m.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {Metrics, MetricsContext} from '../metrics.js';

Polymer({
  is: 'print-preview-more-settings',

  _template: html`<!--_html_template_start_-->
<style include="cr-hidden-style print-preview-shared">
  :host {
    border-top: var(--print-preview-settings-border);
    display: block;
  }

  :host([disabled]) {
    pointer-events: none;
  }

  div {
    align-items: center;
    display: flex;
    font: inherit;
    margin: 0;
    min-height: 48px;
  }

  :host cr-expand-button {
    margin-inline-end: calc(var(--print-preview-sidebar-margin) + 6px);
    --cr-expand-button-size: 28px;
  }

  :host([hidden]) {
    display: none;
  }

  #label {
    color: var(--cr-primary-text-color);
    flex: 1;
    margin-inline-start: var(--print-preview-sidebar-margin);
    text-align: start;
  }

  :host([disabled]) #label {
    opacity: var(--cr-disabled-opacity);
  }
</style>
<div on-click="toggleExpandButton_" actionable>
  <span id="label">$i18n{moreOptionsLabel}</span>
  <cr-expand-button alt="$i18n{moreOptionsLabel}"
      expanded="{{settingsExpandedByUser}}" disabled="[[disabled]]">
  </cr-expand-button>
</div>
<!--_html_template_end_-->`,

  behaviors: [I18nBehavior],

  properties: {
    settingsExpandedByUser: {
      type: Boolean,
      notify: true,
    },

    disabled: {
      type: Boolean,
      reflectToAttribute: true,
    },
  },

  /** @private {!MetricsContext} */
  metrics_: MetricsContext.printSettingsUi(),

  /**
   * Toggles the expand button within the element being listened to.
   * @param {!Event} e
   * @private
   */
  toggleExpandButton_(e) {
    // The expand button handles toggling itself.
    const expandButtonTag = 'CR-EXPAND-BUTTON';
    if (e.target.tagName === expandButtonTag) {
      return;
    }

    if (!e.currentTarget.hasAttribute('actionable')) {
      return;
    }

    /** @type {!CrExpandButtonElement} */
    const expandButton = e.currentTarget.querySelector(expandButtonTag);
    assert(expandButton);
    expandButton.expanded = !expandButton.expanded;
    this.metrics_.record(
        this.settingsExpandedByUser ?
            Metrics.PrintSettingsUiBucket.MORE_SETTINGS_CLICKED :
            Metrics.PrintSettingsUiBucket.LESS_SETTINGS_CLICKED);
  },
});
