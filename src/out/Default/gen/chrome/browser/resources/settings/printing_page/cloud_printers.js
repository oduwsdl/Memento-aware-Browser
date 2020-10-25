// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview 'settings-cloud-printers' is a component for showing Google
 * Cloud Printer settings subpage (chrome://settings/cloudPrinters).
 */
// TODO(xdai): Rename it to 'settings-cloud-printers-page'.
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import '../controls/settings_toggle_button.m.js';
import '../settings_shared_css.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'settings-cloud-printers',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared iron-flex">
      #cloud-print-warning {
        --google-orange-900: rgb(176, 96, 0);  /* b06000 */
        --warning-extra-spacing: 12px;
        align-items: center;
        background-color: var(--google-yellow-50);
        color: var(--google-orange-900);
        display: flex;
        margin: 0 var(--cr-section-padding) var(--warning-extra-spacing);
        min-height: var(--settings-row-min-height);
        padding: 0 var(--warning-extra-spacing);
      }
    </style>
    <div id="cloud-print-warning" hidden$="[[hideCloudPrintWarning]]">
      <div class="cr-padded-text">$i18nRaw{cloudPrintFullWarning}</div>
    </div>
    <settings-toggle-button
        pref="{{prefs.local_discovery.notifications_enabled}}"
        label="$i18n{printingNotificationsLabel}">
    </settings-toggle-button>
    <a class="cr-row inherit-color no-outline" tabindex="-1"
        target="_blank" href="$i18n{cloudPrintersUrl}">
      <div class="flex">
        $i18n{printingManageCloudPrintDevices}
      </div>
      <cr-icon-button class="icon-external"
          aria-label="$i18n{printingManageCloudPrintDevices}"></cr-icon-button>
    </a>
<!--_html_template_end_-->`,

  properties: {
    hideCloudPrintWarning: Boolean,

    prefs: {
      type: Object,
      notify: true,
    },
  },
});
