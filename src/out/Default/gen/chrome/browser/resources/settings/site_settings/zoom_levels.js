// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'zoom-levels' is the polymer element for showing the sites that are zoomed in
 * or out.
 */

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import '../settings_shared_css.m.js';
import '../site_favicon.js';

import {ListPropertyUpdateBehavior} from 'chrome://resources/js/list_property_update_behavior.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {loadTimeData} from '../i18n_setup.js';

import {SiteSettingsBehavior} from './site_settings_behavior.js';
import {ZoomLevelEntry} from './site_settings_prefs_browser_proxy.js';

Polymer({
  is: 'zoom-levels',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared">
      :host {
        display: block;
      }

      .zoom-label {
        color: var(--cr-secondary-text-color);
        margin-inline-end: 16px;
      }

      #empty {
        margin-top: 15px;
      }

      .list-item site-favicon {
        flex-shrink: 0;
      }

      .list-item .middle {
        overflow-x: hidden;
        text-overflow: ellipsis;
      }
    </style>
    <div class="list-frame vertical-list" id="listContainer">
      <iron-list id="list" preserve-focus items="[[sites_]]"
          class="cr-separators" risk-selection>
        <template>
          <div class="list-item" first$="[[!index]]">
            <site-favicon url="[[item.originForFavicon]]"></site-favicon>
            <div class="middle">
              <span class="url-directionality">[[item.displayName]]</span>
            </div>
            <div class="zoom-label">[[item.zoom]]</div>
            <cr-icon-button class="icon-clear" on-click="removeZoomLevel_"
                title="$i18n{siteSettingsRemoveZoomLevel}"
                tabindex$="[[tabIndex]]"></cr-icon-button>
          </div>
        </template>
      </iron-list>
      <div id="empty" hidden$="[[!showNoSites_]]">
        $i18n{siteSettingsNoZoomedSites}
      </div>
    </div>
<!--_html_template_end_-->`,

  behaviors: [
    ListPropertyUpdateBehavior,
    SiteSettingsBehavior,
    WebUIListenerBehavior,
  ],

  properties: {
    /**
     * Array of sites that are zoomed in or out.
     * @type {!Array<ZoomLevelEntry>}
     */
    sites_: {
      type: Array,
      value: () => [],
    },

    /** @private */
    showNoSites_: {
      type: Boolean,
      value: false,
    },
  },

  /** @override */
  ready() {
    this.addWebUIListener(
        'onZoomLevelsChanged', this.onZoomLevelsChanged_.bind(this));
    this.browserProxy.fetchZoomLevels();
  },

  /**
   * A handler for when zoom levels change.
   * @param {!Array<ZoomLevelEntry>} sites The up to date list of sites and
   *     their zoom levels.
   */
  onZoomLevelsChanged_(sites) {
    this.updateList('sites_', item => item.origin, sites);
    this.showNoSites_ = this.sites_.length === 0;
  },

  /**
   * A handler for when a zoom level for a site is deleted.
   * @param {!{model: !{index: number}}} event
   * @private
   */
  removeZoomLevel_(event) {
    const site = this.sites_[event.model.index];
    this.browserProxy.removeZoomLevel(site.origin);
  },
});
