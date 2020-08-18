/* Copyright 2019 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file. */
import 'chrome://resources/cr_elements/shared_vars_css.m.js';

import 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

const styleElement = document.createElement('dom-module');
styleElement.setAttribute('assetpath', 'chrome://resources/');
styleElement.innerHTML = `<!--_html_template_start_-->
<!-- Common styles for signin-related tab modal dialogs. -->
<template>
  <style>
    a {
      color: var(--cr-link-color);
      text-decoration: none;
    }

    .container {
      color: var(--cr-primary-text-color);
      width: 448px;
    }

    .top-title-bar {
      align-items: center;
      border-bottom: var(--cr-separator-line);
      display: flex;
      font-size: 16px;
      height: 52px;
      padding: 0 24px;
    }

    .action-container {
      display: flex;
      justify-content: flex-end;
      padding: 16px;
    }

    cr-button + cr-button {
      margin-inline-start: 8px;
    }

<if expr="is_macosx or is_linux">
    .action-container {
      flex-flow: row-reverse;
      justify-content: flex-start;
    }

    cr-button + cr-button {
      margin-inline-end: 8px;
      margin-inline-start: 0;
    }
</if>
  </style>
</template>
<!--_html_template_end_-->`;
styleElement.register('signin-dialog-shared');
