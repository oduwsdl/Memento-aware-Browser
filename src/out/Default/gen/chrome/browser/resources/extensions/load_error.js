// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/polymer/v3_0/paper-spinner/paper-spinner-lite.js';
import './code_section.js';
import './strings.m.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

/** @interface */
export class LoadErrorDelegate {
  /**
   * Attempts to load the previously-attempted unpacked extension.
   * @param {string} retryId
   * @return {!Promise}
   */
  retryLoadUnpacked(retryId) {}
}

Polymer({
  is: 'extensions-load-error',

  _template: html`<!--_html_template_start_-->
<style include="cr-shared-style">
  .description-row {
    display: flex;
  }

  .row-label {
    display: block;
    width: 104px;  /* Magic number from the specs. */
  }

  paper-spinner-lite {
    margin-inline-end: 8px;
  }
</style>
<cr-dialog id="dialog" close-text="$i18n{close}">
  <div slot="title">$i18n{loadErrorHeading}</div>
  <div slot="body">
    <div id="info">
      <div id="file" class="description-row">
        <span class="row-label">$i18n{loadErrorFileLabel}</span>
        <span class="row-value">[[loadError.path]]</span>
      </div>
      <div id="error" class="description-row">
        <span class="row-label">$i18n{loadErrorErrorLabel}</span>
        <span class="row-value">[[loadError.error]]</span>
      </div>
    </div>
    <extensions-code-section id="code"
        could-not-display-code="$i18n{loadErrorCouldNotLoadManifest}">
    </extensions-code-section>
  </div>
  <div slot="button-container">
    <paper-spinner-lite active="[[retrying_]]"></paper-spinner-lite>
    <cr-button class="cancel-button" on-click="close">
      $i18n{cancel}
    </cr-button>
    <cr-button class="action-button" disabled="[[retrying_]]"
        on-click="onRetryTap_">
      $i18n{loadErrorRetry}
    </cr-button>
  </div>
</cr-dialog>
<!--_html_template_end_-->`,

  properties: {
    /** @type {LoadErrorDelegate} */
    delegate: Object,

    /** @type {chrome.developerPrivate.LoadError} */
    loadError: Object,

    /** @private */
    retrying_: Boolean,
  },

  observers: [
    'observeLoadErrorChanges_(loadError)',
  ],

  show() {
    /** @type {!CrDialogElement} */ (this.$.dialog).showModal();
  },

  close() {
    /** @type {!CrDialogElement} */ (this.$.dialog).close();
  },

  /** @private */
  onRetryTap_() {
    this.retrying_ = true;
    this.delegate.retryLoadUnpacked(this.loadError.retryGuid)
        .then(
            () => {
              this.close();
            },
            loadError => {
              this.loadError =
                  /** @type {chrome.developerPrivate.LoadError} */ (loadError);
              this.retrying_ = false;
            });
  },

  /** @private */
  observeLoadErrorChanges_() {
    assert(this.loadError);
    const source = this.loadError.source;
    // CodeSection expects a RequestFileSourceResponse, rather than an
    // ErrorFileSource. Massage into place.
    // TODO(devlin): Make RequestFileSourceResponse use ErrorFileSource.
    /** @type {!chrome.developerPrivate.RequestFileSourceResponse} */
    const codeSectionProperties = {
      beforeHighlight: source ? source.beforeHighlight : '',
      highlight: source ? source.highlight : '',
      afterHighlight: source ? source.afterHighlight : '',
      title: '',
      message: this.loadError.error,
    };

    this.$.code.code = codeSectionProperties;
  },
});
