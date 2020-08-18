// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import '../controls/settings_slider.m.js';
import '../settings_shared_css.m.js';

import {SliderTick} from 'chrome://resources/cr_elements/cr_slider/cr_slider.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {WebUIListenerBehavior} from 'chrome://resources/js/web_ui_listener_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {DropdownMenuOptionList} from '../controls/settings_dropdown_menu.m.js';
import {loadTimeData} from '../i18n_setup.js';

import {FontsBrowserProxy, FontsBrowserProxyImpl, FontsData} from './fonts_browser_proxy.m.js';


/** @type {!Array<number>} */
const FONT_SIZE_RANGE = [
  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 22, 24,
  26, 28, 30, 32, 34, 36, 40, 44, 48, 56, 64, 72,
];

/** @type {!Array<number>} */
const MINIMUM_FONT_SIZE_RANGE =
    [0, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 22, 24];

/**
 * @param {!Array<number>} ticks
 * @return {!Array<!SliderTick>}
 */
function ticksWithLabels(ticks) {
  return ticks.map(x => ({label: `${x}`, value: x}));
}

/**
 * 'settings-appearance-fonts-page' is the settings page containing appearance
 * settings.
 */
Polymer({
  is: 'settings-appearance-fonts-page',

  _template: html`<!--_html_template_start_-->
    <style include="cr-shared-style settings-shared iron-flex">
      #minimumSize {
        align-items: flex-end;
        display: flex;
        flex-direction: column;
      }

      #minimumSizeSample {
        text-align: end;
      }
    </style>
    <div class="cr-row first">
      <div class="flex cr-padded-text" aria-hidden="true">
        $i18n{fontSize}
      </div>
      <settings-slider id="sizeSlider"
          pref="{{prefs.webkit.webprefs.default_font_size}}"
          ticks="[[fontSizeRange_]]" label-aria="$i18n{fontSize}"
          label-min="$i18n{tiny}" label-max="$i18n{huge}">
      </settings-slider>
    </div>
    <div class="cr-row">
      <div class="flex cr-padded-text" aria-hidden="true">
        $i18n{minimumFont}
      </div>
      <div id="minimumSize">
        <settings-slider  pref="{{prefs.webkit.webprefs.minimum_font_size}}"
            ticks="[[minimumFontSizeRange_]]" label-aria="$i18n{minimumFont}"
            label-min="$i18n{tiny}" label-max="$i18n{huge}">
        </settings-slider>
        <div id="minimumSizeSample"
            style="
                font-size:[[computeMinimumFontSize_(
                    prefs.webkit.webprefs.minimum_font_size.value)]]px;
                font-family:
                    '[[prefs.webkit.webprefs.fonts.standard.Zyyy.value]]';"
            hidden>
          [[computeMinimumFontSize_(
                  prefs.webkit.webprefs.minimum_font_size.value)]]:
          $i18n{quickBrownFox}
        </div>
      </div>
    </div>
    <div class="cr-row" aria-hidden="true">
      <h2>$i18n{standardFont}</h2>
    </div>
    <div class="list-frame">
      <div class="list-item">
        <settings-dropdown-menu class="start" label="$i18n{standardFont}"
            pref="{{prefs.webkit.webprefs.fonts.standard.Zyyy}}"
            menu-options="[[fontOptions_]]">
        </settings-dropdown-menu>
      </div>
      <div class="list-item cr-padded-text"
          style="
              font-size:[[prefs.webkit.webprefs.default_font_size.value]]px;
              font-family:
                  '[[prefs.webkit.webprefs.fonts.standard.Zyyy.value]]';">
        <span>
          [[prefs.webkit.webprefs.default_font_size.value]]:
          $i18n{quickBrownFox}
        </span>
      </div>
    </div>
    <div class="cr-row" aria-hidden="true">
      <h2>$i18n{serifFont}</h2>
    </div>
    <div class="list-frame">
      <div class="list-item">
        <settings-dropdown-menu class="start" label="$i18n{serifFont}"
            pref="{{prefs.webkit.webprefs.fonts.serif.Zyyy}}"
            menu-options="[[fontOptions_]]">
        </settings-dropdown-menu>
      </div>
      <div class="list-item cr-padded-text"
          style="
              font-size:[[prefs.webkit.webprefs.default_font_size.value]]px;
              font-family:
                  '[[prefs.webkit.webprefs.fonts.serif.Zyyy.value]]';">
        <span>
          [[prefs.webkit.webprefs.default_font_size.value]]:
          $i18n{quickBrownFox}
        </span>
      </div>
    </div>
    <div class="cr-row" aria-hidden="true">
      <h2>$i18n{sansSerifFont}</h2>
    </div>
    <div class="list-frame">
      <div class="list-item">
        <settings-dropdown-menu class="start" label="$i18n{sansSerifFont}"
            pref="{{prefs.webkit.webprefs.fonts.sansserif.Zyyy}}"
            menu-options="[[fontOptions_]]">
        </settings-dropdown-menu>
      </div>
      <div class="list-item cr-padded-text"
          style="
              font-size:[[prefs.webkit.webprefs.default_font_size.value]]px;
              font-family:
                  '[[prefs.webkit.webprefs.fonts.sansserif.Zyyy.value]]';">
        <span>
          [[prefs.webkit.webprefs.default_font_size.value]]:
          $i18n{quickBrownFox}
        </span>
      </div>
    </div>
    <div class="cr-row" aria-hidden="true">
      <h2>$i18n{fixedWidthFont}</h2>
    </div>
    <div class="list-frame">
      <div class="list-item">
        <settings-dropdown-menu class="start" label="$i18n{fixedWidthFont}"
            pref="{{prefs.webkit.webprefs.fonts.fixed.Zyyy}}"
            menu-options="[[fontOptions_]]">
        </settings-dropdown-menu>
      </div>
      <div class="list-item cr-padded-text"
          style="
              font-size:
                  [[prefs.webkit.webprefs.default_fixed_font_size.value]]px;
              font-family:
                  '[[prefs.webkit.webprefs.fonts.fixed.Zyyy.value]]';">
        [[prefs.webkit.webprefs.default_font_size.value]]:
        $i18n{quickBrownFox}
      </div>
    </div>
<!--_html_template_end_-->`,

  behaviors: [I18nBehavior, WebUIListenerBehavior],

  properties: {
    /** @private {!DropdownMenuOptionList} */
    fontOptions_: Object,

    /**
     * Common font sizes.
     * @private {!Array<!SliderTick>}
     */
    fontSizeRange_: {
      readOnly: true,
      type: Array,
      value: ticksWithLabels(FONT_SIZE_RANGE),
    },

    /**
     * Reasonable, minimum font sizes.
     * @private {!Array<!SliderTick>}
     */
    minimumFontSizeRange_: {
      readOnly: true,
      type: Array,
      value: ticksWithLabels(MINIMUM_FONT_SIZE_RANGE),
    },

    /**
     * Preferences state.
     */
    prefs: {
      type: Object,
      notify: true,
    },
  },

  observers: [
    'onMinimumSizeChange_(prefs.webkit.webprefs.minimum_font_size.value)',
  ],

  /** @private {?FontsBrowserProxy} */
  browserProxy_: null,

  /** @override */
  created() {
    this.browserProxy_ = FontsBrowserProxyImpl.getInstance();
  },

  /** @override */
  ready() {
    this.browserProxy_.fetchFontsData().then(this.setFontsData_.bind(this));
  },

  /**
   * @param {!FontsData} response A list of fonts.
   * @private
   */
  setFontsData_(response) {
    const fontMenuOptions = [];
    for (const fontData of response.fontList) {
      fontMenuOptions.push({value: fontData[0], name: fontData[1]});
    }
    this.fontOptions_ = fontMenuOptions;
  },

  /**
   * Get the minimum font size, accounting for unset prefs.
   * @return {number}
   * @private
   */
  computeMinimumFontSize_() {
    const prefValue = this.get('prefs.webkit.webprefs.minimum_font_size.value');
    return /** @type {number} */ (prefValue) || MINIMUM_FONT_SIZE_RANGE[0];
  },


  /** @private */
  onMinimumSizeChange_() {
    this.$.minimumSizeSample.hidden = this.computeMinimumFontSize_() <= 0;
  },
});
