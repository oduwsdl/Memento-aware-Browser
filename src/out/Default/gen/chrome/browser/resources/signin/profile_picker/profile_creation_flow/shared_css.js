// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';

import 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';
import '../profile_picker_shared_css.js';

const template = document.createElement('template');
template.innerHTML = `
<dom-module id="profile-creation-shared"><!--_html_template_start_-->
<template>
  <style include="cr-icons profile-picker-shared">
    :host {
      --avatar-size: 100px;
      --banner-height: 244px;
    }

    #headerContainer {
      background-color: var(--theme-frame-color);
      height: var(--banner-height);
      position: relative;
      width: 100%;
    }

    .banner {
      background-size: 100% 100%;
      height: 100%;
      position: absolute;
      top: 0;
      width: 100%;
    }

    #backButton {
      --cr-icon-button-fill-color: var(--theme-text-color);
      --cr-icon-button-icon-size: 20px;
      --cr-icon-button-margin-start: 4px;
      --cr-icon-button-size: 36px;
      margin-top: 4px;
    }

    .avatar {
      border: 2px solid var(--md-background-color);
      border-radius: 50%;
      bottom: calc(var(--avatar-size)/-2);
      height: var(--avatar-size);
      left: 0;
      margin: auto;
      position: absolute;
      right: 0;
      width: var(--avatar-size);
    }
  </style>
</template>
<!--_html_template_end_--></dom-module>
`;
document.body.appendChild(template.content.cloneNode(true));
