// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import './print_preview_shared_css.js';
import './print_preview_vars_css.js';
import '../strings.m.js';
import './throbber_css.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {PromiseResolver} from 'chrome://resources/js/promise_resolver.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {Destination} from '../data/destination.js';
import {DestinationStore} from '../data/destination_store.js';

/**
 * @fileoverview PrintPreviewProvisionalDestinationResolver
 * This class is a dialog for resolving provisional destinations. Provisional
 * destinations are extension controlled destinations that need access to a USB
 * device and have not yet been granted access by the user. Destinations are
 * resolved when the user confirms they wish to grant access and the handler
 * has successfully granted access.
 */

/**
 * States that the provisional destination resolver can be in.
 * @enum {string}
 */
const ResolverState = {
  INITIAL: 'INITIAL',
  ACTIVE: 'ACTIVE',
  GRANTING_PERMISSION: 'GRANTING_PERMISSION',
  ERROR: 'ERROR',
  DONE: 'DONE'
};

Polymer({
  is: 'print-preview-provisional-destination-resolver',

  _template: html`<!--_html_template_start_-->
<style include="print-preview-shared cr-hidden-style throbber">
  #dialog::part(dialog) {
    height: -webkit-fit-content;
    max-height: calc(100vh - 4 * var(--print-preview-dialog-margin));
    max-width:  calc(100vw - 4 * var(--print-preview-dialog-margin));
  }

  .throbber-placeholder {
    height: 16px;
    margin: 4px;
    width: 16px;
  }

  .message {
    line-height: calc(20/13 * 1em);
    margin: 0;
    padding-bottom: 12px;
    padding-top: 8px;
  }

  .extension-desc {
    display: flex;
  }

  .extension-icon {
    background-position: center;
    background-repeat: none;
    height: 24px;
    width: 24px;
  }

  .extension-name {
    color: var(--cr-primary-text-color);
    display: flex;
    flex: 1;
    flex-direction: column;
    justify-content: center;
    line-height: 20px;
    margin-inline-start: 1em;
    overflow-wrap: break-word;
  }

  /* override print preview shared style */
  #dialog #buttons {
    box-shadow: none;
  }
</style>
<cr-dialog id="dialog" on-close="onCancel_">
  <div slot="title">$i18n{resolveExtensionUSBDialogTitle}</div>
  <div slot="body">
    <p class="message">
      [[getPermissionMessage_(state_, destination_.extensionName)]]
    </p>
    <div class="extension-desc" hidden="[[isInErrorState_(state_)]]">
      <div class$="throbber-placeholder [[getThrobberClass_(state_)]]"
          role="img" alt=""></div>
      <div class="extension-icon" role="img" alt=""></div>
      <div class="extension-name">
        [[destination_.extensionName]]
      </div>
    </div>
  </div>
  <div slot="button-container" id="buttons">
    <cr-button class="cancel-button" on-click="onCancelClick_">
      $i18n{goBackButton}
    </cr-button>
    <cr-button class="action-button"
        hidden="[[isInErrorState_(state_)]]"
        disabled="[[!isInActiveState_(state_)]]"
        on-click="startResolveDestination_">
      $i18n{selectButton}
    </cr-button>
  </div>
</cr-dialog>
<!--_html_template_end_-->`,

  behaviors: [I18nBehavior],

  properties: {
    /** @type {?DestinationStore} */
    destinationStore: Object,

    /** @private {?Destination} */
    destination_: {
      type: Object,
      value: null,
    },

    /** @private {!ResolverState} */
    state_: {
      type: String,
      value: ResolverState.INITIAL,
    },
  },

  listeners: {
    'keydown': 'onKeydown_',
  },

  /**
   * Promise resolver for promise returned by {@code this.resolveDestination}.
   * @private {?PromiseResolver<!Destination>}
   */
  promiseResolver_: null,

  /**
   * @param {!Destination} destination The destination this
   *     dialog is needed to resolve.
   * @return {!Promise} Promise that is resolved when the destination has been
   *     resolved.
   */
  resolveDestination(destination) {
    this.state_ = ResolverState.ACTIVE;
    this.destination_ = destination;
    this.$.dialog.showModal();
    const icon = this.$$('.extension-icon');
    icon.style.backgroundImage = '-webkit-image-set(' +
        'url(chrome://extension-icon/' + this.destination_.extensionId +
        '/24/1) 1x,' +
        'url(chrome://extension-icon/' + this.destination_.extensionId +
        '/48/1) 2x)';
    this.promiseResolver_ = new PromiseResolver();
    return this.promiseResolver_.promise;
  },

  /**
   * Handler for click on OK button. It attempts to resolve the destination.
   * If successful, promiseResolver_.promise is resolved with the
   * resolved destination and the dialog closes.
   * @private
   */
  startResolveDestination_() {
    assert(
        this.state_ === ResolverState.ACTIVE,
        'Invalid state in request grant permission');

    this.state_ = ResolverState.GRANTING_PERMISSION;
    const destination =
        /** @type {!Destination} */ (this.destination_);
    this.destinationStore.resolveProvisionalDestination(destination)
        .then(
            /** @param {?Destination} resolvedDestination */
            (resolvedDestination) => {
              if (this.state_ !== ResolverState.GRANTING_PERMISSION) {
                return;
              }

              if (destination.id !== this.destination_.id) {
                return;
              }

              if (resolvedDestination) {
                this.state_ = ResolverState.DONE;
                this.promiseResolver_.resolve(resolvedDestination);
                this.promiseResolver_ = null;
                this.$.dialog.close();
              } else {
                this.state_ = ResolverState.ERROR;
              }
            });
  },

  /**
   * @param {!KeyboardEvent} e Event containing the key
   * @private
   */
  onKeydown_(e) {
    e.stopPropagation();
    if (e.key === 'Escape') {
      this.$.dialog.cancel();
      e.preventDefault();
    }
  },

  /** @private */
  onCancelClick_() {
    this.$.dialog.cancel();
  },

  /** @private */
  onCancel_() {
    this.promiseResolver_.reject();
    this.state_ = ResolverState.INITIAL;
  },

  /**
   * @return {string} The USB permission message to display.
   * @private
   */
  getPermissionMessage_() {
    return this.state_ === ResolverState.ERROR ?
        this.i18n(
            'resolveExtensionUSBErrorMessage',
            this.destination_.extensionName) :
        this.i18n('resolveExtensionUSBPermissionMessage');
  },

  /**
   * @return {boolean} Whether the resolver is in the ERROR state.
   * @private
   */
  isInErrorState_() {
    return this.state_ === ResolverState.ERROR;
  },

  /**
   * @return {boolean} Whether the resolver is in the ACTIVE state.
   * @private
   */
  isInActiveState_() {
    return this.state_ === ResolverState.ACTIVE;
  },

  /**
   * @return {string} 'throbber' if the resolver is in the GRANTING_PERMISSION
   *     state, empty otherwise.
   */
  getThrobberClass_() {
    return this.state_ === ResolverState.GRANTING_PERMISSION ? 'throbber' : '';
  },
});
