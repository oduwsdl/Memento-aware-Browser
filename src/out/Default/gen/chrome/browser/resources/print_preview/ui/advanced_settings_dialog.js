// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import './advanced_settings_item.js';
import './print_preview_search_box.js';
import './print_preview_shared_css.js';
import './print_preview_vars_css.js';
import '../strings.m.js';

import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {removeHighlights} from 'chrome://resources/js/search_highlight_utils.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {Destination} from '../data/destination.js';
import {Metrics, MetricsContext} from '../metrics.js';

import {SettingsBehavior} from './settings_behavior.js';

Polymer({
  is: 'print-preview-advanced-settings-dialog',

  _template: html`<!--_html_template_start_-->
<style include="print-preview-shared cr-hidden-style">
  #dialog::part(dialog) {
    height: -webkit-fit-content;
    max-height: calc(100vh - 2 * var(--print-preview-dialog-margin));
    max-width:  calc(100vw - 2 * var(--print-preview-dialog-margin));
  }

  #dialog::part(wrapper) {
    height: calc(100vh - 2 * var(--print-preview-dialog-margin));
  }

  #dialog::part(body-container) {
    flex: 1;
  }

  print-preview-search-box {
    margin-bottom: 8px;
    margin-top: 16px;
  }

  cr-dialog [slot=body] {
    display: flex;
    flex-direction: column;
    height: 100%;
  }

  #itemList {
    flex: 1;
    overflow-x: hidden;
    overflow-y: overlay;
  }

  #itemList.searching {
    padding-bottom: 20px;
    padding-top: 20px;
  }
</style>
<cr-dialog id="dialog" on-close="onCloseOrCancel_">
  <div slot="title">
    [[i18n('advancedSettingsDialogTitle', destination.displayName)]]
  </div>
  <div slot="body">
    <print-preview-search-box id="searchBox"
        hidden$="[[!hasMultipleItems_(
            destination.capabilities.printer.vendor_capability)]]"
        label="$i18n{advancedSettingsSearchBoxPlaceholder}"
        search-query="{{searchQuery_}}" autofocus>
    </print-preview-search-box>
    <div id="itemList" class$="[[isSearching_(searchQuery_)]]">
      <template is="dom-repeat"
          items="[[destination.capabilities.printer.vendor_capability]]">
        <print-preview-advanced-settings-item capability="[[item]]"
            settings="[[settings]]">
        </print-preview-advanced-settings-item>
      </template>
    </div>
    <div class="no-settings-match-hint"
        hidden$="[[!shouldShowHint_(hasMatching_)]]">
      $i18n{noAdvancedSettingsMatchSearchHint}
    </div>
  </div>
  <div slot="button-container">
    <cr-button class="cancel-button" on-click="onCancelButtonClick_">
      $i18n{cancel}
    </cr-button>
    <cr-button class="action-button" on-click="onApplyButtonClick_">
      $i18n{advancedSettingsDialogConfirm}
    </cr-button>
  </div>
</cr-dialog>
<!--_html_template_end_-->`,

  behaviors: [SettingsBehavior, I18nBehavior],

  properties: {
    /** @type {!Destination} */
    destination: Object,

    /** @private {?RegExp} */
    searchQuery_: {
      type: Object,
      value: null,
    },

    /** @private {boolean} */
    hasMatching_: {
      type: Boolean,
      notify: true,
      computed: 'computeHasMatching_(searchQuery_)',
    },
  },

  listeners: {
    'keydown': 'onKeydown_',
  },

  /** @private {!Array<!Node>} */
  highlights_: [],

  /** @private {!Map<!Node, number>} */
  bubbles_: new Map,

  /** @private {!MetricsContext} */
  metrics_: MetricsContext.printSettingsUi(),

  /** @override */
  attached() {
    this.metrics_.record(
        Metrics.PrintSettingsUiBucket.ADVANCED_SETTINGS_DIALOG_SHOWN);
    this.$.dialog.showModal();
  },

  /**
   * @param {!KeyboardEvent} e Event containing the key
   * @private
   */
  onKeydown_(e) {
    e.stopPropagation();
    const searchInput = this.$.searchBox.getSearchInput();
    const eventInSearchBox = e.composedPath().includes(searchInput);
    if (e.key === 'Escape' &&
        (!eventInSearchBox || !searchInput.value.trim())) {
      this.$.dialog.cancel();
      e.preventDefault();
      return;
    }

    if (e.key === 'Enter' && !eventInSearchBox) {
      const activeElementTag = e.composedPath()[0].tagName;
      if (['CR-BUTTON', 'SELECT'].includes(activeElementTag)) {
        return;
      }
      this.onApplyButtonClick_();
      e.preventDefault();
      return;
    }
  },

  /**
   * @return {boolean} Whether there is more than one vendor item to display.
   * @private
   */
  hasMultipleItems_() {
    return this.destination.capabilities.printer.vendor_capability.length > 1;
  },

  /**
   * @return {boolean} Whether there is a setting matching the query.
   * @private
   */
  computeHasMatching_() {
    if (!this.shadowRoot) {
      return true;
    }

    removeHighlights(this.highlights_);
    this.bubbles_.forEach((number, bubble) => bubble.remove());
    this.highlights_ = [];
    this.bubbles_.clear();

    const listItems = this.shadowRoot.querySelectorAll(
        'print-preview-advanced-settings-item');
    let hasMatch = false;
    listItems.forEach(item => {
      const matches = item.hasMatch(this.searchQuery_);
      item.hidden = !matches;
      hasMatch = hasMatch || matches;
      this.highlights_.push(
          ...item.updateHighlighting(this.searchQuery_, this.bubbles_));
    });
    return hasMatch;
  },

  /**
   * @return {boolean} Whether the no matching settings hint should be shown.
   * @private
   */
  shouldShowHint_() {
    return !!this.searchQuery_ && !this.hasMatching_;
  },

  /** @private */
  onCloseOrCancel_() {
    if (this.searchQuery_) {
      this.$.searchBox.setValue('');
    }
    if (this.$.dialog.getNative().returnValue === 'success') {
      this.metrics_.record(
          Metrics.PrintSettingsUiBucket.ADVANCED_SETTINGS_DIALOG_CANCELED);
    }
  },

  /** @private */
  onCancelButtonClick_() {
    this.$.dialog.cancel();
  },

  /** @private */
  onApplyButtonClick_() {
    const settingsValues = {};
    this.shadowRoot.querySelectorAll('print-preview-advanced-settings-item')
        .forEach(item => {
          settingsValues[item.capability.id] = item.getCurrentValue();
        });
    this.setSetting('vendorItems', settingsValues);
    this.$.dialog.close();
  },

  close() {
    this.$.dialog.close();
  },

  /**
   * @return {string}
   * @private
   */
  isSearching_() {
    return this.searchQuery_ ? 'searching' : '';
  },
});
