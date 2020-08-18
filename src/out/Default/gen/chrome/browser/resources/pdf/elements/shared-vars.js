// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/polymer/v3_0/paper-styles/color.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

const $_documentContainer = document.createElement('template');
$_documentContainer.innerHTML = `<!--_html_template_start_-->
<custom-style>
  <style>
    html {
      --iron-icon-height: 20px;
      --iron-icon-width: 20px;
      --viewer-icon-ink-color: rgb(189, 189, 189);
    }
  </style>
</custom-style>
<!--_html_template_end_-->`;
document.head.appendChild($_documentContainer.content);
