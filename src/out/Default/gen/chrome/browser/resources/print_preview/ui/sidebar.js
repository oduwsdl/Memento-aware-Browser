// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-collapse/iron-collapse.js';
import './advanced_options_settings.js';
import './button_strip.js';
import './color_settings.js';
import './copies_settings.js';
import './dpi_settings.js';
import './duplex_settings.js';
import './header.js';
import './layout_settings.js';
import './media_size_settings.js';
import './margins_settings.js';
import './more_settings.js';
import './other_options_settings.js';
import './pages_per_sheet_settings.js';
import './pages_settings.js';
// <if expr="chromeos">
import './pin_settings.js';
// </if>
import './print_preview_vars_css.js';
import './scaling_settings.js';
import '../strings.m.js';
// <if expr="not chromeos">
import './link_container.js';
// </if>

import {CrContainerShadowBehavior} from 'chrome://resources/cr_elements/cr_container_shadow_behavior.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {DarkModeBehavior} from '../dark_mode_behavior.js';
import {Destination} from '../data/destination.js';
import {Error, State} from '../data/state.js';
import {Metrics, MetricsContext} from '../metrics.js';

import {DestinationState} from './destination_settings.js';
import {SettingsBehavior} from './settings_behavior.js';

/**
 * Number of settings sections to show when "More settings" is collapsed.
 * @type {number}
 */
const MAX_SECTIONS_TO_SHOW = 6;

Polymer({
  is: 'print-preview-sidebar',

  _template: html`<!--_html_template_start_-->
<style include="cr-hidden-style cr-shared-style">
  :host {
    background-color: white;
    border-inline-start: var(--print-preview-settings-border);
    display: flex;
    flex-direction: column;
  }

  @media (prefers-color-scheme: dark) {
    :host {
      background-color: rgba(255, 255, 255, .04);
    }
  }

  #container {
    color: var(--cr-primary-text-color);
    flex: 1;
    overflow: overlay;
  }

  :host #destinationSettings {
    margin-top: 12px;
  }

  /* Print Preview uses lighter box-shadows compared to the default
   * styling. */
  :host #cr-container-shadow-top,
  :host #cr-container-shadow-bottom {
    box-shadow: inset 0 5px 3px -3px rgba(0, 0, 0, .2);
  }

  .settings-section {
    display: block;
    margin-bottom: 16px;
    margin-top: 16px;
  }
</style>
<print-preview-header id="header" destination="[[destination]]"
    cloud-print-error-message="[[cloudPrintErrorMessage]]"
    error="[[error]]" sheet-count="[[sheetCount_]]" state="[[state]]"
    settings="[[settings]]" managed="[[controlsManaged]]">
</print-preview-header>
<div id="container" show-bottom-shadow>
  <print-preview-destination-settings id="destinationSettings"
      dark="[[inDarkMode]]" destination="{{destination}}"
      destination-state="{{destinationState}}"
      error="{{error}}" first-load="[[firstLoad_]]" settings="[[settings]]"
      state="[[state]]" app-kiosk-mode="[[isInAppKioskMode_]]"
      disabled="[[controlsDisabled_]]"
      available class="settings-section">
  </print-preview-destination-settings>
<if expr="chromeos">
  <print-preview-pin-settings state="[[state]]" settings="[[settings]]"
      disabled="[[controlsDisabled_]]"
      hidden$="[[!settings.pin.available]]" class="settings-section">
  </print-preview-pin-settings>
</if>
  <print-preview-pages-settings settings="[[settings]]"
      page-count="[[pageCount]]" disabled="[[controlsDisabled_]]"
      hidden$="[[!settings.pages.available]]" class="settings-section">
  </print-preview-pages-settings>
  <print-preview-copies-settings settings="[[settings]]"
      capability="[[destination.capabilities.printer.copies]]"
      disabled="[[controlsDisabled_]]"
      hidden$="[[!settings.copies.available]]" class="settings-section">
  </print-preview-copies-settings>
  <print-preview-layout-settings settings="[[settings]]"
      disabled="[[controlsDisabled_]]"
      hidden$="[[!settings.layout.available]]" class="settings-section">
  </print-preview-layout-settings>
  <print-preview-color-settings settings="[[settings]]"
      disabled="[[controlsDisabled_]]"
      hidden$="[[!settings.color.available]]" class="settings-section">
  </print-preview-color-settings>
  <print-preview-more-settings
      settings-expanded-by-user="{{settingsExpandedByUser_}}"
      disabled="[[controlsDisabled_]]"
      hidden$="[[!shouldShowMoreSettings_]]">
  </print-preview-more-settings>
  <iron-collapse id="moreSettings"
      opened="[[shouldExpandSettings_(
          settingsExpandedByUser_, shouldShowMoreSettings_)]]">
    <print-preview-media-size-settings settings="[[settings]]"
        capability="[[destination.capabilities.printer.media_size]]"
        disabled="[[controlsDisabled_]]"
        hidden$="[[!settings.mediaSize.available]]"
        class="settings-section">
    </print-preview-media-size-settings>
    <print-preview-pages-per-sheet-settings settings="[[settings]]"
        disabled="[[controlsDisabled_]]"
        hidden$="[[!settings.pagesPerSheet.available]]"
        class="settings-section">
    </print-preview-pages-per-sheet-settings>
    <print-preview-margins-settings settings="[[settings]]" state="[[state]]"
        disabled="[[controlsDisabled_]]"
        hidden$="[[!settings.margins.available]]"
        class="settings-section">
    </print-preview-margins-settings>
    <print-preview-dpi-settings settings="[[settings]]"
        capability="[[destination.capabilities.printer.dpi]]"
        disabled="[[controlsDisabled_]]"
        hidden$="[[!settings.dpi.available]]" class="settings-section">
    </print-preview-dpi-settings>
    <print-preview-scaling-settings settings="[[settings]]"
        disabled="[[controlsDisabled_]]" is-pdf="[[isPdf]]"
        hidden$="[[!settings.scaling.available]]"
        class="settings-section">
    </print-preview-scaling-settings>
    <print-preview-duplex-settings settings="[[settings]]"
        disabled="[[controlsDisabled_]]" dark="[[inDarkMode]]"
        hidden$="[[!settings.duplex.available]]"
        class="settings-section">
    </print-preview-duplex-settings>
    <print-preview-other-options-settings settings="[[settings]]"
        disabled="[[controlsDisabled_]]"
        hidden$="[[!settings.otherOptions.available]]"
        class="settings-section">
    </print-preview-other-options-settings>
    <print-preview-advanced-options-settings
        settings="[[settings]]" destination="[[destination]]"
        disabled="[[controlsDisabled_]]"
        hidden$="[[!settings.vendorItems.available]]"
        class="settings-section">
    </print-preview-advanced-options-settings>
<if expr="not chromeos">
    <print-preview-link-container destination="[[destination]]"
        app-kiosk-mode="[[isInAppKioskMode_]]"
        disabled="[[controlsDisabled_]]">
    </print-preview-link-container>
</if>
  </iron-collapse>
</div>
<print-preview-button-strip destination="[[destination]]"
    state="[[state]]" first-load="[[firstLoad_]]"
    sheet-count="[[sheetCount_]]" max-sheets="[[maxSheets]]"
    on-print-button-focused="onPrintButtonFocused_">
</print-preview-button-strip>
<!--_html_template_end_-->`,

  behaviors: [
    SettingsBehavior,
    CrContainerShadowBehavior,
    WebUIListenerBehavior,
    DarkModeBehavior,
  ],

  properties: {
    cloudPrintErrorMessage: String,

    controlsManaged: Boolean,

    /** @type {Destination} */
    destination: {
      type: Object,
      notify: true,
    },

    /** @private {!DestinationState} */
    destinationState: {
      type: Number,
      notify: true,
    },

    /** @type {!Error} */
    error: {
      type: Number,
      notify: true,
    },

    isPdf: Boolean,

    pageCount: Number,

    /** @type {!State} */
    state: {
      type: Number,
      observer: 'onStateChanged_',
    },

    /** @private {boolean} */
    controlsDisabled_: {
      type: Boolean,
      computed: 'computeControlsDisabled_(state)',
    },

    maxSheets: Number,

    /** @private {number} */
    sheetCount_: {
      type: Number,
      computed: 'computeSheetCount_(' +
          'settings.pages.*, settings.duplex.*, settings.copies.*)',
    },

    /** @private {boolean} */
    firstLoad_: {
      type: Boolean,
      value: true,
    },

    /** @private {boolean} */
    isInAppKioskMode_: {
      type: Boolean,
      value: false,
    },

    /** @private {boolean} */
    settingsExpandedByUser_: {
      type: Boolean,
      value: false,
    },

    /** @private {boolean} */
    shouldShowMoreSettings_: {
      type: Boolean,
      computed: 'computeShouldShowMoreSettings_(settings.pages.available, ' +
          'settings.copies.available, settings.layout.available, ' +
          'settings.color.available, settings.mediaSize.available, ' +
          'settings.dpi.available, settings.margins.available, ' +
          'settings.pagesPerSheet.available, settings.scaling.available, ' +
          'settings.duplex.available, settings.otherOptions.available, ' +
          'settings.vendorItems.available)',
    },
  },

  /**
   * @param {boolean} appKioskMode
   * @param {string} defaultPrinter The system default printer ID.
   * @param {string} serializedDestinationSelectionRulesStr String with rules
   *     for selecting the default destination.
   * @param {?Array<string>} userAccounts The signed in user accounts.
   * @param {boolean} syncAvailable
   * @param {boolean} pdfPrinterDisabled Whether the PDF printer is disabled.
   */
  init(
      appKioskMode, defaultPrinter, serializedDestinationSelectionRulesStr,
      userAccounts, syncAvailable, pdfPrinterDisabled) {
    this.isInAppKioskMode_ = appKioskMode;
    const saveAsPdfDisabled = this.isInAppKioskMode_ || pdfPrinterDisabled;
    this.$.destinationSettings.init(
        defaultPrinter, saveAsPdfDisabled,
        serializedDestinationSelectionRulesStr, userAccounts, syncAvailable);
  },

  /**
   * @return {boolean} Whether the controls should be disabled.
   * @private
   */
  computeControlsDisabled_() {
    return this.state !== State.READY;
  },

  /**
   * @return {number} The number of sheets that will be printed.
   * @private
   */
  computeSheetCount_() {
    let sheets = this.getSettingValue('pages').length;
    if (this.getSettingValue('duplex')) {
      sheets = Math.ceil(sheets / 2);
    }
    return sheets * /** @type {number} */ (this.getSettingValue('copies'));
  },

  /**
   * @return {boolean} Whether to show the "More settings" link.
   * @private
   */
  computeShouldShowMoreSettings_() {
    // Destination settings is always available. See if the total number of
    // available sections exceeds the maximum number to show.
    return [
      'pages', 'copies', 'layout', 'color', 'mediaSize', 'margins', 'color',
      'pagesPerSheet', 'scaling', 'dpi', 'duplex', 'otherOptions', 'vendorItems'
    ].reduce((count, setting) => {
      return this.getSetting(setting).available ? count + 1 : count;
    }, 1) > MAX_SECTIONS_TO_SHOW;
  },

  /**
   * @return {boolean} Whether the "more settings" collapse should be expanded.
   * @private
   */
  shouldExpandSettings_() {
    if (this.settingsExpandedByUser_ === undefined ||
        this.shouldShowMoreSettings_ === undefined) {
      return false;
    }

    // Expand the settings if the user has requested them expanded or if more
    // settings is not displayed (i.e. less than 6 total settings available).
    return this.settingsExpandedByUser_ || !this.shouldShowMoreSettings_;
  },

  /** @private */
  onPrintButtonFocused_() {
    this.firstLoad_ = false;
  },

  onStateChanged_() {
    if (this.state !== State.PRINTING) {
      return;
    }

    if (this.shouldShowMoreSettings_) {
      MetricsContext.printSettingsUi().record(
          this.settingsExpandedByUser_ ?
              Metrics.PrintSettingsUiBucket.PRINT_WITH_SETTINGS_EXPANDED :
              Metrics.PrintSettingsUiBucket.PRINT_WITH_SETTINGS_COLLAPSED);
    }
  },

  /** @return {boolean} Whether the system dialog link is available. */
  systemDialogLinkAvailable() {
    const linkContainer = this.$$('print-preview-link-container');
    return !!linkContainer && linkContainer.systemDialogLinkAvailable();
  },
});
