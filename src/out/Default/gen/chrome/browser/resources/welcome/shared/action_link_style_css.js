// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {FocusOutlineManager} from 'chrome://resources/js/cr/ui/focus_outline_manager.m.js';

const styleElement = document.createElement('dom-module');
styleElement.innerHTML = `<!--_html_template_start_-->
<template>
  <style>
    button.action-link {
      -webkit-appearance: none;
      background: none;
      border: none;
      color: var(--cr-link-color);
      cursor: pointer;
      display: inline-block;
      font-family: inherit;
      text-decoration: none;
    }

    button.action-link[disabled] {
      color: var(--paper-grey-600);
      cursor: default;
      opacity: 0.65;
    }

    :host-context(html:not(.focus-outline-visible)) button.action-link {
      outline: none;
    }
  </style>
</template>
<!--_html_template_end_-->`;
styleElement.register('action-link-style');

// Initiate focus-outline-manager for this document so that action-link style
// can take advantage of it.
FocusOutlineManager.forDocument(document);
