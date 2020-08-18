// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

const $_documentContainer = document.createElement('template');
$_documentContainer.innerHTML = `<!--_html_template_start_-->
<custom-style>
<style>
  html {
    --card-max-width: 960px;
    --card-padding-side: 32px;
    --folder-icon-color: #757575;
    --folder-inactive-color: #5a5a5a;
    --highlight-color: var(--google-blue-50);
    --interactive-color: var(--google-blue-500);
    --iron-icon-height: 20px;
    --iron-icon-width: 20px;
    --min-sidebar-width: 256px;
    --splitter-width: 15px;
  }

  @media (prefers-color-scheme: dark) {
    html {
      --folder-icon-color: var(--google-grey-refresh-500);
      --folder-inactive-color: var(--google-grey-refresh-500);
      --highlight-color: var(--google-blue-refresh-300);
      --interactive-color: var(--google-blue-refresh-300);
    }
  }
</style>
</custom-style>
<!--_html_template_end_-->`;
document.head.appendChild($_documentContainer.content);
