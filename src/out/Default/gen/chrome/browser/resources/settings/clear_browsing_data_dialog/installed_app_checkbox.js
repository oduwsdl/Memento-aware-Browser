// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
/**
 * @fileoverview
 * `installed-app-checkbox` is a checkbox that displays an installed app.
 * An installed app could be a domain with data that the user might want
 * to protect from being deleted.
 */
import 'chrome://resources/cr_elements/cr_checkbox/cr_checkbox.m.js';
import 'chrome://resources/cr_elements/policy/cr_policy_pref_indicator.m.js';
import '../settings_shared_css.m.js';
import '../site_favicon.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {InstalledApp} from './clear_browsing_data_browser_proxy.js';

Polymer({
  is: 'installed-app-checkbox',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared">
      site-favicon {
        --site-favicon-height: 20px;
        --site-favicon-width: 20px;
      }

      #outerRow {
        align-items: center;
        display: flex;
        min-height: var(--settings-row-two-line-min-height);
        width: 100%;
      }

      #innerRow {
        display: flex;
        flex-direction: row;
      }

      cr-checkbox {
        width: 100%;
      }

      site-favicon {
        padding-inline-end: 10px;
      }
      #innerRow secondary {
        padding-inline-start: 4px;
      }
    </style>

    <div id="outerRow">
      <cr-checkbox id="checkbox" checked="{{installed_app.isChecked}}"
          disabled="[[disabled]]">
        <div id="innerRow">
          <site-favicon url="[[installed_app.registerableDomain]]">
          </site-favicon>
          <div class="label">[[installed_app.appName]]</div>
          <div class="secondary label">
            &nbsp([[installed_app.registerableDomain]])
          </div>
        </div>
      </cr-checkbox>
    </div>
<!--_html_template_end_-->`,

  properties: {
    /** @type {InstalledApp} */
    installed_app: Object,
    disabled: {
      type: Boolean,
      value: false,
    },
  },
});
