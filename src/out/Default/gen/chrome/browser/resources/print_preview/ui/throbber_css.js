// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

const template = document.createElement('template');
template.innerHTML = `
<dom-module id="throbber"><!--_html_template_start_-->
<template>
  <style>
    .throbber {
      background: url(chrome://resources/images/throbber_small.svg) no-repeat;
      display: inline-block;
      height: 16px;
      width: 16px;
    }
  </style>
</template>
<!--_html_template_end_--></dom-module>
`;
document.body.appendChild(template.content.cloneNode(true));
