// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/hidden_style_css.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'viewer-error-screen',

  _template: html`<!--_html_template_start_-->
    <style include="cr-hidden-style"></style>
    <cr-dialog id="dialog" no-cancel>
      <div slot="title">$i18n{errorDialogTitle}</div>
      <div slot="body">$i18n{pageLoadFailed}</div>
      <div slot="button-container" hidden$="[[!reloadFn]]">
        <cr-button class="action-button" on-click="reload">
          $i18n{pageReload}
        </cr-button>
      </div>
    </cr-dialog>
<!--_html_template_end_-->`,

  properties: {
    reloadFn: Function,
  },

  show() {
    /** @type {!CrDialogElement} */ (this.$.dialog).showModal();
  },

  reload() {
    if (this.reloadFn) {
      this.reloadFn();
    }
  }
});
