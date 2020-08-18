// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import './advanced_settings_dialog.js';
import './print_preview_shared_css.js';
import './settings_section.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {Destination} from '../data/destination.js';
import {Settings} from '../data/model.js';

Polymer({
  is: 'print-preview-advanced-options-settings',

  _template: html`<!--_html_template_start_-->
<style include="print-preview-shared">
  cr-button {
    height: fit-content;
    min-height: 32px;
    text-align: center;
    width: calc(100% - 2 * var(--print-preview-sidebar-margin));
  }
</style>
<print-preview-settings-section>
  <span slot="title"></span>
  <div slot="controls">
    <cr-button id="button" disabled$="[[disabled]]"
        on-click="onButtonClick_">
      $i18n{newShowAdvancedOptions}
    </cr-button>
  </div>
</print-preview-settings-section>
<template is="dom-if" if="[[showAdvancedDialog_]]" restamp>
  <print-preview-advanced-settings-dialog
      settings="[[settings]]" destination="[[destination]]"
      on-close="onDialogClose_">
  </print-preview-advanced-settings-dialog>
</template>
<!--_html_template_end_-->`,

  properties: {
    disabled: Boolean,

    /** @type {!Destination} */
    destination: Object,

    /** @type {!Settings} */
    settings: Object,

    /** @private {boolean} */
    showAdvancedDialog_: {
      type: Boolean,
      value: false,
    },
  },

  /** @private */
  onButtonClick_() {
    this.showAdvancedDialog_ = true;
  },

  /** @private */
  onDialogClose_() {
    this.showAdvancedDialog_ = false;
    this.$.button.focus();
  },
});
