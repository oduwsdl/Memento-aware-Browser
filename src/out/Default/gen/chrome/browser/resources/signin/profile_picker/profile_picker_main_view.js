// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import './icons.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'profile-picker-main-view',

  _template: html`<!--_html_template_start_-->
<style>
 .profiles-container {
    --grid-gutter: 12px;
    --max-columns: 4;
    --profile-item-height:178px;
    --profile-item-width: 162px;
    align-items: center;
    display: grid;
    height: 80%;
    grid-column-gap: var(--grid-gutter);
    grid-row-gap: var(--grid-gutter);
    grid-template-columns: repeat(auto-fit, var(--profile-item-width));
    justify-content: center;
    margin: auto;
    max-width: calc(var(--profile-item-width) * var(--max-columns) +
        var(--grid-gutter) * var(--max-columns));
 }

.profile-item {
    align-items: center;
    display: flex;
    flex-direction: column;
    height: var(--profile-item-height);
    justify-content: center;
    width: var(--profile-item-width);
 }

 #addProfile {
  border: 1px dashed;
  border-color:  var(--google-grey-400);
  border-radius: 12px;
 }

 cr-icon-button[iron-icon='profiles:add'] {
  --cr-icon-button-icon-size: 74px;
  --cr-icon-button-size: 84px;
  --cr-icon-button-fill-color: var(--google-grey-refresh-100);
  --cr-icon-button-margin-end: 0px;
  --cr-icon-button-margin-start: 0px;
  --cr-icon-button-stroke-color: var(--google-grey-refresh-700);
 }

@media (prefers-color-scheme: dark) {
  /* TODO(msalama): Dark mode mocks not ready yet.*/
}
</style>
<div class="profiles-container">
  <div id="addProfile" class="profile-item">
    <!-- TODO(msalama): Add title, aria-label once strings are ready-->
    <cr-icon-button iron-icon="profiles:add"
        on-click="onAddProfileClick_">
    </cr-icon-button>
  </div>
</div>
<!--_html_template_end_-->`,

  /** @private */
  onAddProfileClick_() {
    // TODO(msalama): do something.
  },
});
