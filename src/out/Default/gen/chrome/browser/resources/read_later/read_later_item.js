// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/mwb_shared_vars.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';

import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {ReadLaterApiProxy, ReadLaterApiProxyImpl} from './read_later_api_proxy.js';

export class ReadLaterItemElement extends PolymerElement {
  static get is() {
    return 'read-later-item';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style>
  .button-container {
    display: flex;
    margin-inline-start: calc(var(--mwb-icon-size) / 2);
    overflow: hidden;
    width: 0;
  }

  :host(:hover) .button-container {
    overflow: visible;
    width: auto;
  }

  .text-container {
    flex-grow: 1;
    overflow: hidden;
  }

  .primary-text,
  .secondary-text {
    overflow: hidden;
    text-overflow: ellipsis;
    user-select: none;
    white-space: nowrap;
  }

  .primary-text {
    color: var(--cr-primary-text-color);
    font-size: var(--mwb-primary-text-font-size);
    margin-bottom: 3px;
  }

  .secondary-text {
    color: var(--cr-secondary-text-color);
    font-size: var(--mwb-secondary-text-font-size);
  }

  cr-icon-button {
    border-radius: 50%;
    --cr-icon-button-fill-color: transparent;
    --cr-icon-button-icon-size: var(--mwb-icon-size);
    --cr-icon-button-size: 24px;
    --cr-icon-button-margin-start: 0;
    --cr-icon-button-margin-end: 0;
  }

  :host(:hover) cr-icon-button {
    --cr-icon-button-fill-color: var(--google-grey-refresh-700);
  }

  cr-icon-button:hover {
    background-color: rgba(var(--google-grey-900-rgb), .1);
  }

  #deleteButton {
    margin-inline-start: calc(var(--cr-icon-button-size) / 2);
  }
</style>

<div class="text-container">
  <div class="primary-text">[[data.title]]</div>
  <div class="secondary-text">
    [[data.displayUrl]] - [[data.displayTimeSinceUpdate]]
  </div>
</div>
<div class="button-container">
  <cr-icon-button id="updateStatusButton"
      aria-label="[[getUpdateStatusButtonTooltip_('$i18n{tooltipMarkAsUnread}',
      '$i18n{tooltipMarkAsRead}', data.read)]]" disable-ripple
      iron-icon="cr:check" title="[[getUpdateStatusButtonTooltip_(
      '$i18n{tooltipMarkAsUnread}', '$i18n{tooltipMarkAsRead}', data.read)]]"
      on-click="onUpdateStatusClick_">
  </cr-icon-button>
  <cr-icon-button id="deleteButton" aria-label="$i18n{tooltipDelete}"
      disable-ripple iron-icon="cr:close" title="$i18n{tooltipDelete}"
      on-click="onItemDeleteClick_">
  </cr-icon-button>
</div>
<!--_html_template_end_-->`;
  }

  static get properties() {
    return {
      /** @type {!readLater.mojom.ReadLaterEntry} */
      data: Object,
    };
  }

  constructor() {
    super();
    /** @private {!ReadLaterApiProxy} */
    this.apiProxy_ = ReadLaterApiProxyImpl.getInstance();
  }

  /** @override */
  ready() {
    super.ready();
    this.addEventListener('click', this.onClick_);
  }

  /** @private */
  onClick_() {
    this.apiProxy_.openSavedEntry(this.data.url);
  }

  /**
   * @param {!Event} e
   * @private
   */
  onUpdateStatusClick_(e) {
    e.stopPropagation();
    this.apiProxy_.updateReadStatus(this.data.url, !this.data.read);
  }

  /**
   * @param {!Event} e
   * @private
   */
  onItemDeleteClick_(e) {
    e.stopPropagation();
    this.apiProxy_.removeEntry(this.data.url);
  }

  /**
   * @param {string} markAsUnreadTooltip
   * @param {string} markAsReadTooltip
   * @return {string} The appropriate tooltip for the current state
   * @private
   */
  getUpdateStatusButtonTooltip_(markAsUnreadTooltip, markAsReadTooltip) {
    return this.data.read ? markAsUnreadTooltip : markAsReadTooltip;
  }
}

customElements.define(ReadLaterItemElement.is, ReadLaterItemElement);
