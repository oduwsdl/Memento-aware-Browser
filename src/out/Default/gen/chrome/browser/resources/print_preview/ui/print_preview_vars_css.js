// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_vars_css.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

const $_documentContainer = document.createElement('template');
$_documentContainer.innerHTML = `<!--_html_template_start_-->
<custom-style>
<style>
  html {
    --print-preview-row-height: 38px;
    --print-preview-sidebar-width: 384px;
    --print-preview-title-width: 120px;
    --print-preview-sidebar-margin: 24px;

    --print-preview-settings-border: 1px solid var(--google-grey-200);
    --print-preview-dialog-margin: 34px;
    --cr-form-field-label-height: initial;
    --cr-form-field-label-line-height: .75rem;
    --destination-item-height: 32px;
    --preview-area-background-color: var(--google-grey-refresh-300);
    --iron-icon-fill-color: var(--google-grey-refresh-700);
    --iron-icon-height: var(--cr-icon-size);
    --iron-icon-width: var(--cr-icon-size);
  }

  @media (prefers-color-scheme: dark) {
    html {
      --preview-area-background-color: var(--google-grey-refresh-700);
      --print-preview-disabled-label: {
        opacity: var(--cr-disabled-opacity);
      }
      --print-preview-settings-border: var(--cr-separator-line);
      --iron-icon-fill-color: var(--google-grey-refresh-500);
    }
  }
</style>
</custom-style>
<!--_html_template_end_-->`;
document.head.appendChild($_documentContainer.content);
