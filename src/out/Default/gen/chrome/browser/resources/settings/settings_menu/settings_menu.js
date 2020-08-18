// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'settings-menu' shows a menu with a hardcoded set of pages and subpages.
 */
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/polymer/v3_0/iron-collapse/iron-collapse.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import 'chrome://resources/polymer/v3_0/iron-selector/iron-selector.js';
import '../i18n_setup.js';
import '../icons.m.js';
import '../settings_shared_css.m.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {PageVisibility} from '../page_visibility.js';
import {Route, RouteObserverBehavior, Router} from '../router.m.js';

Polymer({
  is: 'settings-menu',

  _template: html`<!--_html_template_start_-->
    <style include="settings-shared cr-icons">
      :host {
        box-sizing: border-box;
        display: block;
        padding-bottom: 5px; /* Prevents focus outlines from being cropped. */
        padding-top: 8px;
      }

      :host * {
        -webkit-tap-highlight-color: transparent;
      }

      #topMenu {
        display: flex;
        flex-direction: column;
        min-width: fit-content;
      }

      a[href],
      #advancedButton {
        align-items: center;
        color: var(--settings-nav-item-color);
        display: flex;
        font-weight: 500;
        margin-inline-end: 2px;  /* Margin so selected outline is visible. */
        margin-inline-start: 1px;
        min-height: 20px;
        padding-bottom: 10px;
        padding-inline-start: 23px;  /* 24px - 1px from margin for outline. */
        padding-top: 10px;
      }

      a[href].iron-selected {
        color: var(--cr-link-color);
      }

      a[href]:focus {
        background: transparent;
        outline: auto 5px -webkit-focus-ring-color;
      }

      iron-icon {
        --iron-icon-fill-color: var(--settings-nav-icon-color);
        margin-inline-end: 24px;
        pointer-events: none;
        vertical-align: top;
      }

      .iron-selected > iron-icon {
        fill: var(--cr-link-color);
      }

      #advancedButton {
        --ink-color: var(--settings-nav-item-color);
        background: none;
        border: none;
        border-radius: initial;
        box-shadow: none;
        height: unset;
        margin-top: 8px;
        padding-inline-end: 0;
        text-transform: none;
      }

      #advancedButton:focus {
        outline: none;
      }

      :host-context(.focus-outline-visible) #advancedButton:focus {
        outline: auto 5px -webkit-focus-ring-color;
      }

      #advancedButton > span,
      #extensionsLink > span {
        flex: 1;
      }

      #advancedButton > iron-icon,
      #extensionsLink > .cr-icon {
        height: var(--cr-icon-size);
        margin-inline-end: 14px;  /* 16px - 2px from margin for outline. */
        width: var(--cr-icon-size);
      }

      #menuSeparator {
        /* Per bettes@, this is different from the other separator lines. */
        border-bottom: 1px solid rgba(0, 0, 0, 0.08);
        margin-bottom: 8px;
        margin-top: 8px;
      }

      @media (prefers-color-scheme: dark) {
        #menuSeparator {
          border-bottom: var(--cr-separator-line);  /* override */
        }
      }
    </style>
    <iron-selector id="topMenu" selectable="a:not(#extensionsLink)"
        attr-for-selected="href" on-iron-activate="onSelectorActivate_"
        role="navigation" on-click="onLinkClick_">
      <a id="people" href="/people" hidden="[[!pageVisibility.people]]">
        <iron-icon icon="cr:person"></iron-icon>
        $i18n{peoplePageTitle}
      </a>
      <a id="autofill" href="/autofill"
          hidden="[[!pageVisibility.autofill]]">
        <iron-icon icon="settings:assignment"></iron-icon>
        $i18n{autofillPageTitle}
      </a>
      <template is="dom-if" if="[[privacySettingsRedesignEnabled_]]" restamp>
        <a href="/safetyCheck" hidden="[[!pageVisibility.safetyCheck]]"
            id="safetyCheck">
          <iron-icon icon="settings20:safety-check"></iron-icon>
          $i18n{safetyCheckSectionTitle}
        </a>
      </template>
      <a href="/privacy" hidden="[[!pageVisibility.privacy]]">
        <iron-icon icon="cr:security"></iron-icon>
        $i18n{privacyPageTitle}
      </a>
      <a id="appearance" href="/appearance"
        hidden="[[!pageVisibility.appearance]]">
        <iron-icon icon="settings:palette"></iron-icon>
        $i18n{appearancePageTitle}
      </a>
      <a href="/search">
        <iron-icon icon="cr:search"></iron-icon>
        $i18n{searchPageTitle}
      </a>
<if expr="not chromeos">
      <a id="defaultBrowser" href="/defaultBrowser"
        hidden="[[!pageVisibility.defaultBrowser]]">
        <iron-icon icon="settings:web"></iron-icon>
        $i18n{defaultBrowser}
      </a>
</if>
      <a id="onStartup" href="/onStartup"
        hidden="[[!pageVisibility.onStartup]]">
        <iron-icon icon="settings:power-settings-new"></iron-icon>
        $i18n{onStartup}
      </a>
      <cr-button id="advancedButton"
          aria-expanded$="[[boolToString_(advancedOpened)]]"
          on-click="onAdvancedButtonToggle_"
          hidden="[[!pageVisibility.advancedSettings]]">
        <span>$i18n{advancedPageTitle}</span>
        <iron-icon icon="[[arrowState_(advancedOpened)]]">
        </iron-icon></cr-button>
      <iron-collapse id="advancedSubmenu" opened="[[advancedOpened]]"
          hidden="[[!pageVisibility.advancedSettings]]">
        <iron-selector id="subMenu" selectable="a" attr-for-selected="href"
            role="navigation" on-click="onLinkClick_">
          <a href="/languages">
            <iron-icon icon="settings:language"></iron-icon>
            $i18n{languagesPageTitle}
          </a>
          <a href="/downloads">
            <iron-icon icon="cr:file-download"></iron-icon>
            $i18n{downloadsPageTitle}
          </a>
          <a href="/printing" hidden="[[!pageVisibility.printing]]">
            <iron-icon icon="cr:print"></iron-icon>
            $i18n{printingPageTitle}
          </a>
          <a href="/accessibility">
            <iron-icon icon="settings:accessibility"></iron-icon>
            $i18n{a11yPageTitle}
          </a>
<if expr="not chromeos">
          <a href="/system">
            <iron-icon icon="settings:build"></iron-icon>
            $i18n{systemPageTitle}
          </a>
</if>
          <a id="reset" href="/reset" hidden="[[!pageVisibility.reset]]">
            <iron-icon icon="settings:restore"></iron-icon>
            $i18n{resetPageTitle}
          </a>
        </iron-selector>
      </iron-collapse>
      <div id="menuSeparator"></div>
      <a id="extensionsLink" href="chrome://extensions" target="_blank"
          hidden="[[!pageVisibility.extensions]]"
          on-click="onExtensionsLinkClick_"
          title="$i18n{extensionsLinkTooltip}">
        <span>$i18n{extensionsPageTitle}</span>
        <div class="cr-icon icon-external"></div>
      </a>
      <a id="about-menu" href="/help">$i18n{aboutPageTitle}</a>
    </iron-selector>
<!--_html_template_end_-->`,

  behaviors: [RouteObserverBehavior],

  properties: {
    advancedOpened: {
      type: Boolean,
      value: false,
      notify: true,
    },

    /** @private */
    privacySettingsRedesignEnabled_: {
      type: Boolean,
      value: function() {
        return loadTimeData.getBoolean('privacySettingsRedesignEnabled');
      },
    },

    /**
     * Dictionary defining page visibility.
     * @type {!PageVisibility}
     */
    pageVisibility: Object,
  },

  /** @param {!Route} newRoute */
  currentRouteChanged(newRoute) {
    // Focus the initially selected path.
    const anchors = this.root.querySelectorAll('a');
    for (let i = 0; i < anchors.length; ++i) {
      const anchorRoute =
          Router.getInstance().getRouteForPath(anchors[i].getAttribute('href'));
      if (anchorRoute && anchorRoute.contains(newRoute)) {
        this.setSelectedUrl_(anchors[i].href);
        return;
      }
    }

    this.setSelectedUrl_('');  // Nothing is selected.
  },

  /** @private */
  onAdvancedButtonToggle_() {
    this.advancedOpened = !this.advancedOpened;
  },

  /**
   * Prevent clicks on sidebar items from navigating. These are only links for
   * accessibility purposes, taps are handled separately by <iron-selector>.
   * @param {!Event} event
   * @private
   */
  onLinkClick_(event) {
    if (event.target.matches('a:not(#extensionsLink)')) {
      event.preventDefault();
    }
  },

  /**
   * Keeps both menus in sync. |url| needs to come from |element.href| because
   * |iron-list| uses the entire url. Using |getAttribute| will not work.
   * @param {string} url
   */
  setSelectedUrl_(url) {
    this.$.topMenu.selected = this.$.subMenu.selected = url;
  },

  /**
   * @param {!Event} event
   * @private
   */
  onSelectorActivate_(event) {
    this.setSelectedUrl_(event.detail.selected);

    const path = new URL(event.detail.selected).pathname;
    const route = Router.getInstance().getRouteForPath(path);
    assert(route, 'settings-menu has an entry with an invalid route.');
    Router.getInstance().navigateTo(
        route, /* dynamicParams */ null, /* removeSearch */ true);
  },

  /**
   * @param {boolean} opened Whether the menu is expanded.
   * @return {string} Which icon to use.
   * @private
   * */
  arrowState_(opened) {
    return opened ? 'cr:arrow-drop-up' : 'cr:arrow-drop-down';
  },

  /** @private */
  onExtensionsLinkClick_() {
    chrome.metricsPrivate.recordUserAction(
        'SettingsMenu_ExtensionsLinkClicked');
  },

  /**
   * @param {boolean} bool
   * @return {string}
   * @private
   */
  boolToString_(bool) {
    return bool.toString();
  },
});
