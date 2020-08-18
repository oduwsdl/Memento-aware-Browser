// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import './strings.m.js';

import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

// The RHS action button. Used on autocomplete matches as the remove button as
// well as on suggestion group headers as the toggle button.
class RealboxButtonElement extends PolymerElement {
  static get is() {
    return 'ntp-realbox-button';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style>
  :host {
    align-items: center;
    border-radius: 50%;
    display: flex;
    flex-shrink: 0;
    height: 24px;
    justify-content: center;
    outline: none;
    width: 24px;
  }

  :host([hidden]) {
    display: none;
  }

  :host(:hover) {
    background-color: var(--search-box-icon-bg-hovered, rgba(var(--google-grey-900-rgb), .16));
  }

  :host(:focus-within) {
    background-color: var(--search-box-icon-bg-focused, rgba(var(--google-grey-900-rgb), .32));
  }

  #icon {
    -webkit-mask-image: url(chrome://resources/images/icon_clear.svg);
    -webkit-mask-position: center;
    -webkit-mask-repeat: no-repeat;
    -webkit-mask-size: 16px;
    height: 100%;
    width: 100%;
  }

  :host-context(.header) #icon {
    -webkit-mask-image: url(icons/chevron.svg);
    -webkit-transform: rotate(180deg);
    background-color: var(--search-box-icon, var(--google-grey-900));
  }

  :host-context(.header[group-is-hidden]) #icon {
    -webkit-transform: none;
  }

  :host-context(ntp-realbox-match:hover) #icon {
    background-color: var(--search-box-icon, var(--google-grey-900));
  }

  :host-context(ntp-realbox-match:-webkit-any(:focus-within, .selected)) #icon,
  :host-context(.header:focus-within) #icon {
    background-color: var(--search-box-icon-selected, var(--google-grey-900));
  }
</style>
<div id="icon"></div>

<!--_html_template_end_-->`;
  }

  ready() {
    super.ready();

    this.addEventListener('mousedown', this.onMouseDown_.bind(this));
  }

  //============================================================================
  // Event handlers
  //============================================================================

  /**
   * @param {!Event} e
   */
  onMouseDown_(e) {
    e.preventDefault();  // Prevents default browser action (focus).
  }
}

customElements.define(RealboxButtonElement.is, RealboxButtonElement);
