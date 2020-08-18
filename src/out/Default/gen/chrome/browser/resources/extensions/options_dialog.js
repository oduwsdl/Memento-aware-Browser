// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {ItemBehavior} from './item_behavior.js';
import {navigation, Page} from './navigation_helper.js';

/**
 * @return {!Promise} A signal that the document is ready. Need to wait for
 *     this, otherwise the custom ExtensionOptions element might not have been
 *     registered yet.
 */
function whenDocumentReady() {
  if (document.readyState === 'complete') {
    return Promise.resolve();
  }

  return new Promise(function(resolve) {
    document.addEventListener('readystatechange', function f() {
      if (document.readyState === 'complete') {
        document.removeEventListener('readystatechange', f);
        resolve();
      }
    });
  });
}

// The minimum width in pixels for the options dialog.
export const OptionsDialogMinWidth = 400;

// The maximum height in pixels for the options dialog.
export const OptionsDialogMaxHeight = 640;

Polymer({
  is: 'extensions-options-dialog',

  _template: html`<!--_html_template_start_-->
<style>
  #icon {
    height: 32px;
    margin-inline-end: 10px;
    width: 32px;
  }

  #icon-and-name-wrapper {
    align-items: center;
    display: flex;
  }

  ExtensionOptions {
    display: block;
    height: 100%;
    overflow: hidden;
  }

  cr-dialog::part(dialog) {
    /* CSS variables are set by the JS. */
    height: var(--dialog-height);
    opacity: var(--dialog-opacity, 0);
    /* When loading, it's possible for an size update to follow after the
       initial size update. The debounce time on size updates is 50ms.
       A 100ms delay for the opacity transition will allow two updates to
       occur without showing the dialog resizing to the user. */
    transition: opacity 100ms ease 100ms;
    width: var(--dialog-width);
  }

  cr-dialog::part(wrapper) {
    height: 100%;
    max-height: initial;
    overflow: hidden;
  }

  cr-dialog #body {
    height: 100%;
    padding: 0;
  }

  cr-dialog {
    --cr-dialog-body-border-bottom: none;
    --cr-dialog-body-border-top: none;
    --scroll-border: none;
  }

  cr-dialog::part(body-container) {
    height: 100%;
    min-height: initial;
  }
</style>

<cr-dialog id="dialog" close-text="$i18n{close}"
    on-close="onClose_" show-close-button>
  <div slot="title">
    <div id="icon-and-name-wrapper">
      <img id="icon" src="[[data_.iconUrl]]"
          alt$="[[appOrExtension(
              data.type,
              '$i18nPolymer{appIcon}',
              '$i18nPolymer{extensionIcon}')]]">
      <span>[[data_.name]]</span>
    </div>
  </div>
  <div slot="body" id="body">
  </div>
</cr-dialog>
<!--_html_template_end_-->`,

  behaviors: [ItemBehavior],

  properties: {
    /** @private {Object} */
    extensionOptions_: Object,

    /** @private {chrome.developerPrivate.ExtensionInfo} */
    data_: Object,
  },

  /** @private {?Function} */
  boundUpdateDialogSize_: null,

  /** @private {?{height: number, width: number}} */
  preferredSize_: null,

  get open() {
    return this.$.dialog.open;
  },

  /**
   * Resizes the dialog to the width/height stored in |preferredSize_|, taking
   * into account the window width/height.
   * @private
   */
  updateDialogSize_() {
    const headerHeight = this.$.body.offsetTop;
    const maxHeight =
        Math.min(0.9 * window.innerHeight, OptionsDialogMaxHeight);
    const effectiveHeight =
        Math.min(maxHeight, headerHeight + this.preferredSize_.height);
    const effectiveWidth =
        Math.max(OptionsDialogMinWidth, this.preferredSize_.width);

    this.$.dialog.style.setProperty('--dialog-height', `${effectiveHeight}px`);
    this.$.dialog.style.setProperty('--dialog-width', `${effectiveWidth}px`);
    this.$.dialog.style.setProperty('--dialog-opacity', '1');
  },

  /** @param {chrome.developerPrivate.ExtensionInfo} data */
  show(data) {
    this.data_ = data;
    whenDocumentReady().then(() => {
      if (!this.extensionOptions_) {
        this.extensionOptions_ = document.createElement('ExtensionOptions');
      }
      this.extensionOptions_.extension = this.data_.id;
      this.extensionOptions_.onclose = () => this.$.dialog.close();

      const boundUpdateDialogSize = this.updateDialogSize_.bind(this);
      this.boundUpdateDialogSize_ = boundUpdateDialogSize;
      this.extensionOptions_.onpreferredsizechanged = e => {
        if (!this.$.dialog.open) {
          this.$.dialog.showModal();
        }
        this.preferredSize_ = e;
        this.debounce('updateDialogSize_', boundUpdateDialogSize, 50);
      };

      // Add a 'resize' such that the dialog is resized when window size
      // changes.
      window.addEventListener('resize', this.boundUpdateDialogSize_);
      this.$.body.appendChild(/** @type {Node} */ (this.extensionOptions_));
    });
  },

  /** @private */
  onClose_() {
    this.extensionOptions_.onpreferredsizechanged = null;

    if (this.boundUpdateDialogSize_) {
      window.removeEventListener('resize', this.boundUpdateDialogSize_);
      this.boundUpdateDialogSize_ = null;
    }

    const currentPage = navigation.getCurrentPage();
    // We update the page when the options dialog closes, but only if we're
    // still on the details page. We could be on a different page if the
    // user hit back while the options dialog was visible; in that case, the
    // new page is already correct.
    if (currentPage && currentPage.page === Page.DETAILS) {
      // This will update the currentPage_ and the NavigationHelper; since
      // the active page is already the details page, no main page
      // transition occurs.
      navigation.navigateTo(
          {page: Page.DETAILS, extensionId: currentPage.extensionId});
    }
  },
});
