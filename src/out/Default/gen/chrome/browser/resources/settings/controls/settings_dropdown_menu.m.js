// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * The |name| is shown in the gui.  The |value| us use to set or compare with
 * the preference value.
 * @typedef {{
 *   name: string,
 *   value: (number|string)
 * }}
 */
let DropdownMenuOption;

/**
 * @typedef {!Array<!DropdownMenuOption>}
 */
export let DropdownMenuOptionList;

/**
 * 'settings-dropdown-menu' is a control for displaying options
 * in the settings.
 *
 * Example:
 *
 *   <settings-dropdown-menu pref="{{prefs.foo}}">
 *   </settings-dropdown-menu>
 */
import {Polymer, html} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '//resources/cr_elements/md_select_css.m.js';
import {CrPolicyPrefBehavior} from '//resources/cr_elements/policy/cr_policy_pref_behavior.m.js';
import '//resources/cr_elements/policy/cr_policy_pref_indicator.m.js';
import {assert} from '//resources/js/assert.m.js';
import {PrefControlBehavior} from './pref_control_behavior.m.js';
import {loadTimeData} from '../i18n_setup.js';
import {stringToPrefValue,  prefToString} from '../prefs/pref_util.m.js';
import '../settings_shared_css.m.js';
import '../settings_vars_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="settings-shared md-select">
      :host {
        align-items: center;
        display: inline-flex;
      }

      /* When settings-dropdown-menu is start-aligned, we probably want policy
       * indicator to be be displayed after the dropdown.
       * Setting --settings-dropdown-menu-policy-order to 1 will do the job.
       */
      cr-policy-pref-indicator {
        height: var(--iron-icon-width, 24px);
        margin: 0 var(--settings-controlled-by-spacing);
        order: var(--settings-dropdown-menu-policy-order, 0);
        width: var(--iron-icon-width, 24px);
      }

      /* Hide "Custom" value when unselectable. */
      option:disabled {
        display: none;
      }
    </style>
    <template is="dom-if" if="[[pref.controlledBy]]" restamp>
      <cr-policy-pref-indicator pref="[[pref]]"></cr-policy-pref-indicator>
    </template>
    <select class="md-select" id="dropdownMenu" on-change="onChange_"
        aria-label$="[[label]]"
        disabled="[[shouldDisableMenu_(disabled, menuOptions.*, pref.*)]]">
      <template is="dom-repeat" items="[[menuOptions]]">
        <option value="[[item.value]]">[[item.name]]</option>
      </template>
      <option value="[[notFoundValue_]]"
          disabled="[[!showNotFoundValue_(menuOptions, pref.value)]]">
        $i18n{custom}
      </option>
    </select>
<!--_html_template_end_-->`,
  is: 'settings-dropdown-menu',

  behaviors: [CrPolicyPrefBehavior, PrefControlBehavior],

  properties: {
    /**
     * List of options for the drop-down menu.
     * @type {!DropdownMenuOptionList}
     */
    menuOptions: Array,

    /** Whether the dropdown menu should be disabled. */
    disabled: {
      type: Boolean,
      reflectToAttribute: true,
      value: false,
    },

    /**
       If this is a dictionary pref, this is the key for the item
        we are interested in.
     */
    prefKey: {
      type: String,
      value: null,
    },

    /**
     * The value of the "custom" item.
     * @private
     */
    notFoundValue_: {
      type: String,
      value: 'SETTINGS_DROPDOWN_NOT_FOUND_ITEM',
      readOnly: true,
    },

    /** Label for a11y purposes */
    label: String,
  },

  observers: [
    'updateSelected_(menuOptions, pref.value.*, prefKey)',
  ],

  /** @override */
  focus() {
    this.$.dropdownMenu.focus();
  },

  /**
   * Pass the selection change to the pref value.
   * @private
   */
  onChange_() {
    const selected = this.$.dropdownMenu.value;

    if (selected === this.notFoundValue_) {
      return;
    }

    if (this.prefKey) {
      assert(this.pref);
      this.set(`pref.value.${this.prefKey}`, selected);
    } else {
      const prefValue =
          stringToPrefValue(selected, assert(this.pref));
      if (prefValue !== undefined) {
        this.set('pref.value', prefValue);
      }
    }

    // settings-control-change only fires when the selection is changed to
    // a valid property.
    this.fire('settings-control-change');
  },

  /**
   * Updates the selected item when the pref or menuOptions change.
   * @private
   */
  updateSelected_() {
    if (this.menuOptions === undefined || this.pref === undefined ||
        this.prefKey === undefined) {
      return;
    }

    if (!this.menuOptions.length) {
      return;
    }

    const prefValue = this.prefStringValue_();
    const option = this.menuOptions.find(function(menuItem) {
      return menuItem.value.toString() === prefValue;
    });

    // Wait for the dom-repeat to populate the <select> before setting
    // <select>#value so the correct option gets selected.
    this.async(() => {
      this.$.dropdownMenu.value =
          option === undefined ? this.notFoundValue_ : prefValue;
    });
  },

  /**
   * Gets the current value of the preference as a string.
   * @return {string}
   * @private
   */
  prefStringValue_() {
    if (this.prefKey) {
      // Dictionary pref, values are always strings.
      return this.pref.value[this.prefKey];
    } else {
      return prefToString(assert(this.pref));
    }
  },

  /**
   * @param {?DropdownMenuOptionList} menuOptions
   * @param {string} prefValue
   * @return {boolean}
   * @private
   */
  showNotFoundValue_(menuOptions, prefValue) {
    if (menuOptions === undefined || prefValue === undefined) {
      return false;
    }

    // Don't show "Custom" before the options load.
    if (menuOptions === null || menuOptions.length === 0) {
      return false;
    }

    const option = menuOptions.find((menuItem) => {
      return menuItem.value.toString() === this.prefStringValue_();
    });
    return !option;
  },

  /**
   * @return {boolean}
   * @private
   */
  shouldDisableMenu_() {
    return this.disabled || this.isPrefEnforced() ||
        this.menuOptions === undefined || this.menuOptions.length === 0;
  },
});
