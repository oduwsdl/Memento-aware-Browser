// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

const styleElement = document.createElement('dom-module');
styleElement.innerHTML = `<!--_html_template_start_-->
<template>
  <style>
    @keyframes fade-in {
      0% { opacity: 0; }
      100% { opacity: 1; }
    }

    @keyframes slide-in {
      0% { transform: translateX(var(--slide-in-length, 40px)); }
      100% { transform: translateX(0); }
    }

    .fade-in {
      animation-delay: var(--animation-delay, 0);
      animation-duration: 200ms;
      animation-fill-mode: forwards;
      animation-name: fade-in;
      animation-timing-function: ease-in;
      opacity: 0;
    }

    .slide-in {
      animation-delay: var(--animation-delay, 0);
      animation-duration: 200ms;
      animation-fill-mode: forwards;
      animation-name: slide-in;
      animation-timing-function: ease;
      transform: translateX(30px);
    }

    :host-context(html[dir='rtl']) .slide-in {
      --slide-in-length: -40px;
    }
  </style>
</template>
<!--_html_template_end_-->`;
styleElement.register('animations');
