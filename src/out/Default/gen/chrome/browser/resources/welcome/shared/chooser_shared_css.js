// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/cr_elements/md_select_css.m.js';
import './navi_colors_css.js';

import 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

const styleElement = document.createElement('dom-module');
styleElement.innerHTML = `<!--_html_template_start_-->
<template>
  <style include="navi-colors-css">
    .option {
      background: var(--cr-card-background-color);
      border: 1px solid var(--navi-border-color);
      color: var(--cr-primary-text-color);
      cursor: pointer;
      flex-direction: column;
    }

    .option:hover {
      box-shadow: var(--navi-option-box-shadow);
    }

    .option-name {
      font-size: .875rem;
    }

    .button-bar {
      display: flex;
      justify-content: space-between;
    }

    :host-context([dir=rtl]) iron-icon[icon='cr:chevron-right'] {
      transform: scaleX(-1);
    }

    iron-icon[icon='cr:chevron-right'] {
      height: 1.25rem;
      margin-inline-end: -.625rem;
      margin-inline-start: .375rem;
      width: 1.25rem;
    }
  </style>
</template>
<!--_html_template_end_-->`;
styleElement.register('chooser-shared-css');
