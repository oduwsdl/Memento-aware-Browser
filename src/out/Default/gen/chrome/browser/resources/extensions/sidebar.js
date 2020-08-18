// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-selector/iron-selector.js';
import 'chrome://resources/polymer/v3_0/paper-ripple/paper-ripple.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {navigation, Page} from './navigation_helper.js';

Polymer({
  is: 'extensions-sidebar',

  _template: html`<!--_html_template_start_-->
<style include="cr-icons">
  :host {
    --sidebar-inactive-color: #5a5a5a;
    color: var(--sidebar-inactive-color);
    display: flex;
    flex-direction: column;
    height: 100%;
    justify-content: space-between;
    overflow-x: hidden;
    overflow-y: auto;
    width: 256px;
  }

  @media (prefers-color-scheme: dark) {
    :host {
      --sidebar-inactive-color: var(--cr-primary-text-color);
    }
  }

  iron-selector .iron-selected {
    color: var(--cr-link-color);
  }

  #sectionMenu {
    padding-top: 8px;
    user-select: none;
  }

  .section-item {
    align-items: center;
    color: inherit;
    display: flex;
    font-weight: 500;
    /* Ensure the focus outline appears correctly (crbug.com/655503). */
    margin-inline-end: 4px;
    min-height: 40px;
    padding-inline-start: 24px;
    position: relative;
    text-decoration: none;
  }

  .separator {
    border-top: var(--cr-separator-line);
    margin: 8px 0;
  }

  #more-extensions {
    align-items: center;
    display: flex;
    justify-content: space-between;
    margin-bottom: 8px;
  }

  .cr-icon {
    margin-inline-end: calc(
        var(--cr-section-padding) - var(--cr-icon-ripple-padding));
  }
</style>
<iron-selector id="sectionMenu">
  <!-- Values for "data-path" attribute must match the "Page" enum. -->
  <a class="section-item" id="sections-extensions" href="/"
      on-click="onLinkTap_" data-path="items-list">
    $i18n{sidebarExtensions}
    <paper-ripple></paper-ripple>
  </a>
  <a class="section-item" id="sections-shortcuts" href="/shortcuts"
      on-click="onLinkTap_" data-path="keyboard-shortcuts">
    $i18n{keyboardShortcuts}
    <paper-ripple></paper-ripple>
  </a>
</iron-selector>
<div>
  <div class="separator"></div>
  <a class="section-item" id="more-extensions" target="_blank"
      href="$i18n{getMoreExtensionsUrl}" on-click="onMoreExtensionsTap_">
    <span>$i18n{openChromeWebStore}</span>
    <div class="cr-icon icon-external"></div>
    <paper-ripple></paper-ripple>
  </a>
</div>
<!--_html_template_end_-->`,

  hostAttributes: {
    role: 'navigation',
  },

  /** @override */
  attached() {
    this.$.sectionMenu.select(
        navigation.getCurrentPage().page === Page.SHORTCUTS ? 1 : 0);
  },

  /**
   * @param {!Event} e
   * @private
   */
  onLinkTap_(e) {
    e.preventDefault();
    navigation.navigateTo({page: e.target.dataset.path});
    this.fire('close-drawer');
  },

  /** @private */
  onMoreExtensionsTap_() {
    chrome.metricsPrivate.recordUserAction('Options_GetMoreExtensions');
  },
});
