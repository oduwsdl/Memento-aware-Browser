// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'settings-search-page' is the settings page containing search settings.
 */
import 'chrome://resources/cr_elements/policy/cr_policy_pref_indicator.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/cr_elements/md_select_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import '../controls/extension_controlled_indicator.m.js';
import '../i18n_setup.js';
import '../settings_page/settings_animated_pages.m.js';
import '../settings_page/settings_subpage.m.js';
import '../settings_shared_css.m.js';
import '../settings_vars_css.m.js';

import {addWebUIListener} from 'chrome://resources/js/cr.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {routes} from '../route.js';
import {Router} from '../router.m.js';
import {SearchEngine, SearchEnginesBrowserProxy, SearchEnginesBrowserProxyImpl} from '../search_engines_page/search_engines_browser_proxy.m.js';

Polymer({
  is: 'settings-search-page',

  _template: html`<!--_html_template_start_-->
<style include="cr-shared-style iron-flex settings-shared md-select">
  #search-wrapper {
    align-items: center;
    display: flex;
    min-height: var(--settings-row-min-height);
  }
</style>
<settings-animated-pages id="pages" section="search"
    focus-config="[[focusConfig_]]">
  <div route-path="default">
    <!-- Omnibox search engine -->
    <div class="cr-row first">
      <div id="searchExplanation" class="flex cr-padded-text">
        $i18nRaw{searchExplanation}
      </div>
      <template is="dom-if" if="[[isDefaultSearchControlledByPolicy_(
          prefs.default_search_provider_data.template_url_data)]]">
        <cr-policy-pref-indicator pref="[[
            prefs.default_search_provider_data.template_url_data]]">
        </cr-policy-pref-indicator>
      </template>
      <select class="md-select" on-change="onChange_"
          aria-labelledby="searchExplanation"
          disabled$="[[isDefaultSearchEngineEnforced_(
              prefs.default_search_provider_data.template_url_data)]]">
        <template is="dom-repeat" items="[[searchEngines_]]">
          <option selected="[[item.default]]">[[item.name]]</option>
        </template>
      </select>
    </div>
    <template is="dom-if"
        if="[[prefs.default_search_provider_data.template_url_data.extensionId]]">
      <div class="cr-row continuation">
        <extension-controlled-indicator
            class="flex"
            extension-id="[[
                prefs.default_search_provider_data.template_url_data.extensionId]]"
            extension-name="[[
                prefs.default_search_provider_data.template_url_data.controlledByName]]"
            extension-can-be-disabled="[[
                prefs.default_search_provider_data.template_url_data.extensionCanBeDisabled]]"
            on-disable-extension="onDisableExtension_">
        </extension-controlled-indicator>
      </div>
    </template>

    <!-- Manage search engines -->
    <cr-link-row class="hr" id="enginesSubpageTrigger"
        label="$i18n{searchEnginesManage}"
        on-click="onManageSearchEnginesTap_"
        role-description="$i18n{subpageArrowRoleDescription}"></cr-link-row>
  </div>
  <template is="dom-if" route-path="/searchEngines">
    <settings-subpage
        associated-control="[[$$('#enginesSubpageTrigger')]]"
        page-title="$i18n{searchEnginesManage}"
        search-label="$i18n{searchEnginesSearch}"
        search-term="{{searchEnginesFilter_}}">
      <settings-search-engines-page filter="[[searchEnginesFilter_]]">
    </settings-subpage>
  </template>
</settings-animated-pages>
<!--_html_template_end_-->`,

  properties: {
    prefs: Object,

    /**
     * List of default search engines available.
     * @private {!Array<!SearchEngine>}
     */
    searchEngines_: {
      type: Array,
      value() {
        return [];
      }
    },

    /** @private Filter applied to search engines. */
    searchEnginesFilter_: String,

    /** @type {?Map<string, string>} */
    focusConfig_: Object,
  },

  /** @private {?SearchEnginesBrowserProxy} */
  browserProxy_: null,

  /** @override */
  created() {
    this.browserProxy_ = SearchEnginesBrowserProxyImpl.getInstance();
  },

  /** @override */
  ready() {
    // Omnibox search engine
    const updateSearchEngines = searchEngines => {
      this.set('searchEngines_', searchEngines.defaults);
    };
    this.browserProxy_.getSearchEnginesList().then(updateSearchEngines);
    addWebUIListener('search-engines-changed', updateSearchEngines);

    this.focusConfig_ = new Map();
    if (routes.SEARCH_ENGINES) {
      this.focusConfig_.set(
          routes.SEARCH_ENGINES.path, '#enginesSubpageTrigger');
    }
  },

  /** @private */
  onChange_() {
    const select = /** @type {!HTMLSelectElement} */ (this.$$('select'));
    const searchEngine = this.searchEngines_[select.selectedIndex];
    this.browserProxy_.setDefaultSearchEngine(searchEngine.modelIndex);
  },

  /** @private */
  onDisableExtension_() {
    this.fire('refresh-pref', 'default_search_provider.enabled');
  },

  /** @private */
  onManageSearchEnginesTap_() {
    Router.getInstance().navigateTo(routes.SEARCH_ENGINES);
  },

  /**
   * @param {!chrome.settingsPrivate.PrefObject} pref
   * @return {boolean}
   * @private
   */
  isDefaultSearchControlledByPolicy_(pref) {
    return pref.controlledBy ===
        chrome.settingsPrivate.ControlledBy.USER_POLICY;
  },

  /**
   * @param {!chrome.settingsPrivate.PrefObject} pref
   * @return {boolean}
   * @private
   */
  isDefaultSearchEngineEnforced_(pref) {
    return pref.enforcement === chrome.settingsPrivate.Enforcement.ENFORCED;
  },
});
