// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import './icons.js';
import './print_preview_vars_css.js';
import '../strings.m.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {removeHighlights} from 'chrome://resources/js/search_highlight_utils.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {Destination, DestinationOrigin} from '../data/destination.js';

import {updateHighlights} from './highlight_utils.js';


// <if expr="chromeos">
/** @enum {number} */
const DestinationConfigStatus = {
  IDLE: 0,
  IN_PROGRESS: 1,
  FAILED: 2,
};
// </if>

Polymer({
  is: 'print-preview-destination-list-item',

  _template: html`<!--_html_template_start_-->

    <style include="cr-hidden-style">
      :host {
        align-items: center;
        cursor: default;
        display: flex;
        font-size: calc(12/13 * 1em);
        min-height: var(--destination-item-height);
        opacity: .87;
        padding-inline-end: 2px;
        padding-inline-start: 14px;
        vertical-align: middle;
      }

      :host > * {
        align-items: center;
        color: var(--cr-secondary-text-color);
        font-size: calc(10/12 * 1em);
        margin-inline-start: 1em;
        overflow: hidden;
        text-overflow: ellipsis;
        vertical-align: middle;
        white-space: nowrap;
      }

      iron-icon {
        fill: var(--google-grey-600);
        flex: 0;
        height: 20px;
        margin-inline-end: 12px;
        min-width: 20px;
        transition: opacity 150ms;
      }

      @media (prefers-color-scheme: dark) {
        iron-icon {
          fill: var(--google-grey-refresh-500);
        }
      }

      .name {
        color: var(--cr-primary-text-color);
        font-size: 1em;
        margin-inline-start: 0;
      }

      .extension-controlled-indicator {
        display: flex;
        flex: 1;
        justify-content: flex-end;
        min-width: 150px;
      }

      .extension-icon {
        height: 24px;
        margin-inline-start: 1em;
        width: 24px;
      }

      .configuring-failed-text {
        color: var(--google-red-600);
        font-style: italic;
      }

      :host([stale_]) :-webkit-any(iron-icon, .name, .connection-status) {
        opacity: 0.4;
      }
    </style>
    <iron-icon icon$="[[destination.icon]]"></iron-icon>
    <span class="name searchable">[[destination.displayName]]</span>
    <span class="search-hint searchable">[[searchHint_]]</span>
    <span class="connection-status"
        hidden$="[[!destination.isOfflineOrInvalid]]">
      [[destination.connectionStatusText]]
    </span>
    <a href="$i18n{gcpCertificateErrorLearnMoreURL}"
        target="_blank" class="learn-more-link"
        hidden$="[[!destination.shouldShowInvalidCertificateError]]">
      $i18n{learnMore}
    </a>
    <span class="extension-controlled-indicator"
        hidden$="[[!destination.isExtension]]">
      <span class="extension-name searchable">
        [[destination.extensionName]]
      </span>
      <span class="extension-icon" role="button" tabindex="0"
          title="[[getExtensionPrinterTooltip_(destination)]]"></span>
    </span>
<if expr="chromeos">
    <span class="configuring-in-progress-text"
      hidden$="[[!checkConfigurationStatus_(statusEnum_.IN_PROGRESS,
                                            configurationStatus_)]]">
      $i18n{configuringInProgressText}
      <span class="configuring-text-jumping-dots">
        <span>.</span><span>.</span><span>.</span>
      </span>
    </span>
    <span class="configuring-failed-text"
      hidden$="[[!checkConfigurationStatus_(statusEnum_.FAILED,
                                            configurationStatus_)]]">
      $i18n{configuringFailedText}
    </span>
</if>
<!--_html_template_end_-->`,

  properties: {
    /** @type {!Destination} */
    destination: Object,

    /** @type {?RegExp} */
    searchQuery: Object,

    /** @private */
    stale_: {
      type: Boolean,
      reflectToAttribute: true,
    },

    /** @private {string} */
    searchHint_: String,

    // <if expr="chromeos">
    /** @private {!DestinationConfigStatus} */
    configurationStatus_: {
      type: Number,
      value: DestinationConfigStatus.IDLE,
    },

    /**
     * Mirroring the enum so that it can be used from HTML bindings.
     * @private
     */
    statusEnum_: {
      type: Object,
      value: DestinationConfigStatus,
    },
    // </if>
  },

  observers: [
    'onDestinationPropertiesChange_(' +
        'destination.displayName, destination.isOfflineOrInvalid, ' +
        'destination.isExtension)',
    'updateHighlightsAndHint_(destination, searchQuery)',
  ],

  /** @private {!Array<!Node>} */
  highlights_: [],

  /** @private */
  onDestinationPropertiesChange_() {
    this.title = this.destination.displayName;
    this.stale_ = this.destination.isOfflineOrInvalid;
    if (this.destination.isExtension) {
      const icon = this.$$('.extension-icon');
      icon.style.backgroundImage = '-webkit-image-set(' +
          'url(chrome://extension-icon/' + this.destination.extensionId +
          '/24/1) 1x,' +
          'url(chrome://extension-icon/' + this.destination.extensionId +
          '/48/1) 2x)';
    }
  },

  // <if expr="chromeos">
  /**
   * Called if the printer configuration request is accepted. Show the waiting
   * message to the user as the configuration might take longer than expected.
   */
  onConfigureRequestAccepted() {
    // It must be a Chrome OS CUPS printer which hasn't been set up before.
    assert(
        this.destination.origin === DestinationOrigin.CROS &&
        !this.destination.capabilities);
    this.configurationStatus_ = DestinationConfigStatus.IN_PROGRESS;
  },

  /**
   * Called when the printer configuration request completes.
   * @param {boolean} success Whether configuration was successful.
   */
  onConfigureComplete(success) {
    this.configurationStatus_ =
        success ? DestinationConfigStatus.IDLE : DestinationConfigStatus.FAILED;
  },

  /**
   * @param {!DestinationConfigStatus} status
   * @return {boolean} Whether the current configuration status is |status|.
   * @private
   */
  checkConfigurationStatus_(status) {
    return this.configurationStatus_ === status;
  },
  // </if>

  /** @private */
  updateHighlightsAndHint_() {
    this.updateSearchHint_();
    removeHighlights(this.highlights_);
    this.highlights_ = updateHighlights(this, this.searchQuery, new Map);
  },

  /** @private */
  updateSearchHint_() {
    const matches = !this.searchQuery ?
        [] :
        this.destination.extraPropertiesToMatch.filter(
            p => p.match(this.searchQuery));
    this.searchHint_ = matches.length === 0 ?
        (this.destination.extraPropertiesToMatch.find(p => !!p) || '') :
        matches.join(' ');
  },

  /**
   * @return {string} A tooltip for the extension printer icon.
   * @private
   */
  getExtensionPrinterTooltip_() {
    if (!this.destination.isExtension) {
      return '';
    }
    return loadTimeData.getStringF(
        'extensionDestinationIconTooltip', this.destination.extensionName);
  },
});
