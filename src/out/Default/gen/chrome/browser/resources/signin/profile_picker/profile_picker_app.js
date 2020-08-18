// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_view_manager/cr_view_manager.m.js';
import './profile_picker_main_view.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'profile-picker-app',

  _template: html`<!--_html_template_start_-->
<style>
  cr-view-manager {
    display: flex;
    font-size: 100%;
    margin: 0;
    min-height: 100vh;
  }
</style>
<cr-view-manager>
  <profile-picker-main-view slot="view" class="active">
  </profile-picker-main-view>
</cr-view-manager>
<!--_html_template_end_-->`,
});
