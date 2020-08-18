// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import './cloud_printers.js';
import '../settings_page/settings_animated_pages.m.js';
import '../settings_page/settings_subpage.m.js';
import '../settings_shared_css.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {routes} from '../route.js';
import {Router} from '../router.m.js';

// <if expr="not chromeos">
import {PrintingBrowserProxyImpl} from './printing_browser_proxy.js';
// </if>

Polymer({
  is: 'settings-printing-page',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared"></style>
    <settings-animated-pages id="pages" section="printing"
        focus-config="[[focusConfig_]]">
      <div route-path="default">
<if expr="not chromeos">
        <cr-link-row label="$i18n{localPrintersTitle}"
            on-click="onTapLocalPrinters_" external></cr-link-row>
</if>
        <cr-link-row class="hr" id="cloudPrinters"
            label="$i18n{cloudPrintersTitle}" on-click="onTapCloudPrinters_"
            role-description="$i18n{subpageArrowRoleDescription}">
        </cr-link-row>
      </div>
      <template is="dom-if" route-path="/cloudPrinters">
        <settings-subpage
            associated-control="[[$$('#cloudPrinters')]]"
            page-title="$i18n{cloudPrintersTitle}">
          <settings-cloud-printers prefs="{{prefs}}">
          </settings-cloud-printers>
        </settings-subpage>
      </template>
    </settings-animated-pages>
<!--_html_template_end_-->`,

  properties: {
    /** Preferences state. */
    prefs: {
      type: Object,
      notify: true,
    },

    searchTerm: {
      type: String,
    },

    /** @private {!Map<string, string>} */
    focusConfig_: {
      type: Object,
      value() {
        const map = new Map();
        if (routes.CLOUD_PRINTERS) {
          map.set(routes.CLOUD_PRINTERS.path, '#cloudPrinters');
        }
        return map;
      },
    },
  },

  // <if expr="not chromeos">
  onTapLocalPrinters_() {
    PrintingBrowserProxyImpl.getInstance().openSystemPrintDialog();
  },
  // </if>

  /** @private */
  onTapCloudPrinters_() {
    Router.getInstance().navigateTo(routes.CLOUD_PRINTERS);
  },
});
