// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'chooser-exception-list-entry' shows a single chooser exception for a given
 * chooser type.
 */
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import 'chrome://resources/polymer/v3_0/iron-list/iron-list.js';
import '../settings_shared_css.m.js';
import './site_list_entry.js';

import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {SiteSettingsBehavior} from './site_settings_behavior.js';
import {ChooserException} from './site_settings_prefs_browser_proxy.js';

Polymer({
  is: 'chooser-exception-list-entry',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared iron-flex"></style>

    <div class="cr-row first">
      <h2 class="flex">[[exception.displayName]]</h2>
    </div>

    <div class="list-frame menu-content vertical-list" id="listContainer">
      <iron-list items="[[exception.sites]]" preserve-focus risk-selection>
        <template>
          <site-list-entry model="[[item]]"
              tabindex$="[[tabIndex]]"
              first$="[[!index]]"
              focus-row-index="[[index]]"
              iron-list-tab-index="[[tabIndex]]"
              last-focused="{{lastFocused_}}"
              chooser-type="[[exception.chooserType]]"
              chooser-object="[[exception.object]]"
              read-only-list>
          </site-list-entry>
        </template>
      </iron-list>
    </div>
<!--_html_template_end_-->`,

  behaviors: [SiteSettingsBehavior],

  properties: {
    /**
     * Chooser exception object to display in the widget.
     * @type {!ChooserException}
     */
    exception: Object,

    /** @private */
    lastFocused_: Object,
  },
});
