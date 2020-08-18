// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import './print_preview_vars_css.js';
import './throbber_css.js';

import {isWindows} from 'chrome://resources/js/cr.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {Destination, DestinationOrigin} from '../data/destination.js';

Polymer({
  is: 'print-preview-link-container',

  _template: html`<!--_html_template_start_-->
<style include="cr-shared-style throbber cr-hidden-style">
  :host {
    display: block;
  }

  <if expr="not is_macosx">
    :host(:not([should-show-system-dialog-link_])) {
      display: none;
    }
  </if>

  :host cr-icon-button {
    --cr-icon-button-icon-size: 16px;
    --cr-icon-button-margin-end: -2px;
    --cr-icon-button-margin-start: 0;
    --cr-icon-button-size: 28px;
  }

  .link:not([actionable]) {
    pointer-events: none;
  }

  .throbber {
    margin: 8px;
    min-height: 16px;
    min-width: 16px;
  }

  .link {
    align-items: center;
    display: flex;
    min-height: 46px;
    padding: 0 var(--print-preview-sidebar-margin);
  }

  #systemDialogLink {
    padding-top: 0.5em;
  }

  .label {
    flex: 1;
  }

  .link:not([actionable]) .label {
    opacity: var(--cr-disabled-opacity);
  }
</style>
<div class="link" id="systemDialogLink"
     actionable$="[[!systemDialogLinkDisabled_]]"
     hidden$="[[!shouldShowSystemDialogLink_]]"
     on-click="onSystemDialogClick_">
  <div class="label">$i18n{systemDialogOption}</div>
  <cr-icon-button class="icon-external"
      hidden$="[[openingSystemDialog_]]"
      disabled="[[systemDialogLinkDisabled_]]"
      aria-label="$i18n{systemDialogOption}"></cr-icon-button>
  <div id="systemDialogThrobber" hidden$="[[!openingSystemDialog_]]"
      class="throbber"></div>
</div>
<if expr="is_macosx">
<div class="link" id="openPdfInPreviewLink" actionable$="[[!disabled]]"
    on-click="onOpenInPreviewClick_">
  <div class="label">$i18n{openPdfInPreviewOption}</div>
  <cr-icon-button class="icon-external"
      hidden$="[[openingInPreview_]]" disabled="[[disabled]]"
      aria-label="$i18n{openPdfInPreviewOption}"></cr-icon-button>
  <div id="openPdfInPreviewThrobber" hidden$="[[!openingInPreview_]]"
      class="throbber"></div>
</div>
</if>
<!--_html_template_end_-->`,

  properties: {
    appKioskMode: Boolean,

    /** @type {?Destination} */
    destination: Object,

    disabled: Boolean,

    /** @private {boolean} */
    shouldShowSystemDialogLink_: {
      type: Boolean,
      computed: 'computeShouldShowSystemDialogLink_(appKioskMode, destination)',
      reflectToAttribute: true,
    },

    /** @private {boolean} */
    systemDialogLinkDisabled_: {
      type: Boolean,
      computed: 'computeSystemDialogLinkDisabled_(disabled)',
    },

    /** @private {boolean} */
    openingSystemDialog_: {
      type: Boolean,
      value: false,
    },

    /** @private {boolean} */
    openingInPreview_: {
      type: Boolean,
      value: false,
    },
  },

  /**
   * @return {boolean} Whether the system dialog link should be visible.
   * @private
   */
  computeShouldShowSystemDialogLink_() {
    if (this.appKioskMode) {
      return false;
    }
    if (!isWindows) {
      return true;
    }
    return !!this.destination &&
        this.destination.origin === DestinationOrigin.LOCAL &&
        this.destination.id !== Destination.GooglePromotedId.SAVE_AS_PDF;
  },

  /**
   * @return {boolean} Whether the system dialog link should be disabled
   * @private
   */
  computeSystemDialogLinkDisabled_() {
    return isWindows && this.disabled;
  },

  /** @private */
  onSystemDialogClick_() {
    if (!this.shouldShowSystemDialogLink_) {
      return;
    }

    // <if expr="not is_win">
    this.openingSystemDialog_ = true;
    // </if>
    this.fire('print-with-system-dialog');
  },

  // <if expr="is_macosx">
  /** @private */
  onOpenInPreviewClick_() {
    this.openingInPreview_ = true;
    this.fire('open-pdf-in-preview');
  },
  // </if>

  /** @return {boolean} Whether the system dialog link is available. */
  systemDialogLinkAvailable() {
    return this.shouldShowSystemDialogLink_ && !this.systemDialogLinkDisabled_;
  },
});
