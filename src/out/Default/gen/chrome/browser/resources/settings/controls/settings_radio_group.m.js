// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * `settings-radio-group` wraps cr-radio-group and set of radio-buttons that
 * control a supplied preference.
 *
 * Example:
 *      <settings-radio-group pref="{{prefs.settings.foo}}"
 *          label="Foo Options." buttons="{{fooOptionsList}}">
 *      </settings-radio-group>
 */
import {Polymer, html} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '//resources/cr_elements/cr_radio_button/cr_radio_button.m.js';
import '//resources/cr_elements/cr_radio_group/cr_radio_group.m.js';
import {PrefControlBehavior} from './pref_control_behavior.m.js';
import {stringToPrefValue,  prefToString} from '../prefs/pref_util.m.js';
import '../settings_shared_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="settings-shared"></style>
    <cr-radio-group selected="[[selected]]"
        on-selected-changed="onSelectedChanged_"
        aria-label$="[[groupAriaLabel]]"
        selectable-elements="[[selectableElements]]">
      <slot></slot>
    </cr-radio-group>
<!--_html_template_end_-->`,
  is: 'settings-radio-group',

  behaviors: [PrefControlBehavior],

  properties: {
    groupAriaLabel: String,

    selected: String,

    selectableElements: {
      type: String,
      value: ['cr-radio-button', 'controlled-radio-button'].join(', '),
    },
  },

  hostAttributes: {
    role: 'none',
  },

  observers: [
    'prefChanged_(pref.*)',
  ],

  /** @private */
  prefChanged_() {
    const pref = /** @type {!chrome.settingsPrivate.PrefObject} */ (this.pref);
    this.selected = prefToString(pref);
  },

  /** @private */
  onSelectedChanged_() {
    if (!this.pref) {
      return;
    }
    this.selected = this.$$('cr-radio-group').selected;
    this.set(
        'pref.value',
        stringToPrefValue(this.selected, this.pref));
    this.fire('change');
  },
});
