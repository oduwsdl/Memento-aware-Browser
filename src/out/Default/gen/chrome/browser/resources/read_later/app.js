// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/cr_elements/mwb_shared_style.js';
import 'chrome://resources/cr_elements/mwb_shared_vars.js';

import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {ReadLaterApiProxy, ReadLaterApiProxyImpl} from './read_later_api_proxy.js';
import {ReadLaterItemElement} from './read_later_item.js';

export class ReadLaterAppElement extends PolymerElement {
  static get is() {
    return 'read-later-app';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style include="mwb-shared-style">
  #header {
    align-items: center;
    display: flex;
    font-size: var(--mwb-primary-text-font-size);
    height: var(--mwb-item-height);
    margin: 0;
    padding-inline-start: var(--mwb-list-item-horizontal-margin);
  }

  #read-later-list {
    max-height: 444px;
    overflow-x: hidden;
    overflow-y: auto;
  }

  .sub-heading {
    align-items: center;
    border-bottom: 1px solid #dbdbdb;
    color: var(--cr-secondary-text-color);
    display: flex;
    font-size: 11px;
    height: 24px;
    margin-inline-start: var(--mwb-list-item-horizontal-margin);
    margin-top: 4px;
  }
</style>

<div id="header">$i18n{title}</div>
<div id="read-later-list">
  <div class="sub-heading">$i18n{unreadHeader}</div>
  <template id="ureadItemsList" is="dom-repeat" items="[[unreadItems_]]">
    <read-later-item data-url$="[[item.url]]" class="mwb-list-item"
        data="[[item]]"></read-later-item>
  </template>
  <div class="sub-heading">$i18n{readHeader}</div>
  <template id="readItemsList" is="dom-repeat" items="[[readItems_]]">
    <read-later-item data-url$="[[item.url]]" class="mwb-list-item"
        data="[[item]]"></read-later-item>
  </template>
</div>
<!--_html_template_end_-->`;
  }

  static get properties() {
    return {
      /** @private {?Array<!readLater.mojom.ReadLaterEntry>} */
      unreadItems_: Array,

      /** @private {?Array<!readLater.mojom.ReadLaterEntry>} */
      readItems_: Array,
    };
  }

  constructor() {
    super();
    /** @private {!ReadLaterApiProxy} */
    this.apiProxy_ = ReadLaterApiProxyImpl.getInstance();

    /** @private {?number} */
    this.listenerId_ = null;
  }

  /** @override */
  ready() {
    super.ready();
    this.updateItems_();
    // Push ShowUI() callback to the event queue to allow deferred rendering to
    // take place.
    // TODO(corising): Determine the ideal place to make this call.
    setTimeout(() => {
      this.apiProxy_.showUI();
    }, 0);
  }

  /** @override */
  connectedCallback() {
    super.connectedCallback();
    const callbackRouter = this.apiProxy_.getCallbackRouter();
    this.listenerId_ =
        callbackRouter.itemsChanged.addListener(() => this.updateItems_());
  }

  /** @override */
  disconnectedCallback() {
    super.disconnectedCallback();
    this.apiProxy_.getCallbackRouter().removeListener(
        /** @type {number} */ (this.listenerId_));
    this.listenerId_ = null;
  }

  /** @private */
  updateItems_() {
    this.apiProxy_.getReadLaterEntries().then(({entries}) => {
      this.unreadItems_ = entries.unreadEntries;
      this.readItems_ = entries.readEntries;
    });
  }
}

customElements.define(ReadLaterAppElement.is, ReadLaterAppElement);
