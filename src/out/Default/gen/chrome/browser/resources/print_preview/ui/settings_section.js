// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import './print_preview_shared_css.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'print-preview-settings-section',

  _template: html`<!--_html_template_start_-->
<style include="print-preview-shared">
  :host {
    display: flex;
    padding-inline-start: var(--print-preview-sidebar-margin);
  }

  ::slotted([slot=controls]),
  ::slotted([slot=title]) {
    display: flex;
    flex-direction: column;
    justify-content: center;
    min-height: var(--print-preview-row-height);
    word-break: break-word;
  }

  ::slotted([slot=controls]) {
    flex: 1;
    overflow: hidden;
  }

  ::slotted([slot=title]) {
    color: var(--cr-primary-text-color);
    flex: none;
    font-size: 1em;
    line-height: calc(20/13 * 1em);
    width: var(--print-preview-title-width);
  }
</style>
<slot name="title"></slot>
<slot name="controls"></slot>
<!--_html_template_end_-->`,
});
