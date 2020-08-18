// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import './code_section.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'extensions-install-warnings-dialog',

  _template: html`<!--_html_template_start_-->
<style include="cr-shared-style">
  div[slot='body'] ul {
    background-color: var(--paper-red-50);
    margin: 0;
    padding-bottom: 10px;
    padding-inline-end: 10px;
    padding-top: 10px;
  }

  @media (prefers-color-scheme: dark) {
    div[slot='body'] ul {
      /* TODO(dbeam): merge with --cr-input-background-color? */
      background-color: rgba(0, 0, 0, .3);
      color: var(--error-color);
    }
  }
</style>
<cr-dialog id="dialog" close-text="$i18n{close}">
  <div slot="title">$i18n{installWarnings}</div>
  <div slot="body">
    <ul>
      <template is="dom-repeat" items="[[installWarnings]]">
        <li>[[item]]</li>
      </template>
    </ul>
  </div>
  <div slot="button-container">
    <cr-button class="action-button" on-click="onOkTap_">
      $i18n{ok}
    </cr-button>
  </div>
</cr-dialog>
<!--_html_template_end_-->`,

  properties: {
    /** @type {!Array<string>} */
    installWarnings: Array,
  },

  /** @override */
  attached() {
    this.$.dialog.showModal();
  },

  /** @private */
  onOkTap_() {
    this.$.dialog.close();
  },
});
