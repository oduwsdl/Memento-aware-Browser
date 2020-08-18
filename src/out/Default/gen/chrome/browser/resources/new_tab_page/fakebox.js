// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {assert} from 'chrome://resources/js/assert.m.js';
import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';
import {BrowserProxy} from './browser_proxy.js';

// A fake search box that moves focus and input to the omnibox when interacted
// with.
class FakeboxElement extends PolymerElement {
  static get is() {
    return 'ntp-fakebox';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style>
  :host {
    --ntp-fakebox-height: 44px;
    background-color: white;
    border-radius: calc(0.5 * var(--ntp-fakebox-height));
    box-shadow: 0 1px 6px 0 rgba(32, 33, 36, .28);
    height: var(--ntp-fakebox-height);
    position: relative;
    width: 337px;
  }

  @media (min-width: 560px) {
    :host {
      width: 449px;
    }
  }

  @media (min-width: 672px) {
    :host {
      width: 561px;
    }
  }

  :host([hidden_]) {
    visibility: hidden;
  }

  :host > * {
    bottom: 0;
    left: 0;
    position: absolute;
    right: 0;
    top: 0;
  }

  #controls {
    align-items: center;
    display: flex;
    flex-direction: row;
    left: 16px;
    pointer-events: none;
    right: 16px;
  }

  input {
    border: 0;
    opacity: 0;
    padding: 0;
    width: 100%;
  }

  #searchIcon {
    -webkit-mask-image: url(chrome://resources/images/icon_search.svg);
    -webkit-mask-repeat: no-repeat;
    -webkit-mask-size: 100%;
    background-color: var(--ntp-secondary-text-color);
    height: 21px;
    width: 21px;
  }

  @keyframes blink {
    0% {
      opacity: 1;
    }
    61.55% {
      opacity: 0;
    }
  }

  #fakeCursor {
    background-color: var(--ntp-secondary-text-color);
    height: 1rem;
    margin-inline-start: 11px;
    visibility: hidden;
    width: 1px;
  }

  :host([focused_]) #fakeCursor {
    animation: blink 1.3s step-end infinite;
    visibility: visible;
  }

  :host([dragged_]) #fakeCursor {
    visibility: visible;
  }

  #hint {
    color: var(--ntp-secondary-text-color);
    flex-grow: 1;
    font-size: 1rem;
    margin-inline-start: 3px;
  }

  :host([focused_]) #hint,
  :host([dragged_]) #hint {
    visibility: hidden;
  }

  #voiceSearchButton {
    background: url(icons/googlemic_clr_24px.svg) no-repeat center;
    background-size: 21px 21px;
    border: none;
    border-radius: 2px;
    cursor: pointer;
    height: 100%;
    outline: none;
    padding: 0;
    pointer-events: auto;
    width: 26px;
  }

  :host-context(.focus-outline-visible) #voiceSearchButton:focus {
    box-shadow: var(--ntp-focus-shadow);
  }
</style>
<input id="input" on-pointerdown="onPointerDown_" on-paste="onPaste_"
    on-dragenter="onDragenter_" on-dragleave="onDragleave_" on-drop="onDrop_"
    autocomplete="off" tabindex="-1" type="url" aria-hidden="true">
</input>
<div id="controls">
  <div id="searchIcon"></div>
  <div id="fakeCursor"></div>
  <div id="hint">$i18n{searchBoxHint}</div>
  <button id="voiceSearchButton" on-click="onVoiceSearchClick_"
      title="$i18n{voiceSearchButtonLabel}">
  </button>
</div>
<!--_html_template_end_-->`;
  }

  static get properties() {
    return {
      /** @private */
      focused_: {
        reflectToAttribute: true,
        type: Boolean,
      },

      /** @private */
      hidden_: {
        reflectToAttribute: true,
        type: Boolean,
      },

      /** @private */
      dragged_: {
        reflectToAttribute: true,
        type: Boolean,
      },
    };
  }

  constructor() {
    performance.mark('fakebox-creation-start');
    super();
    /** @private {newTabPage.mojom.PageHandlerRemote} */
    this.pageHandler_ = BrowserProxy.getInstance().handler;
    /** @private {!newTabPage.mojom.PageCallbackRouter} */
    this.callbackRouter_ = BrowserProxy.getInstance().callbackRouter;
    /** @private {?number} */
    this.setFakeboxFocusedListenerId_ = null;
    /** @private {?number} */
    this.setFakeboxVisibleListenerId_ = null;
  }

  /** @override */
  connectedCallback() {
    super.connectedCallback();
    this.setFakeboxFocusedListenerId_ =
        this.callbackRouter_.setFakeboxFocused.addListener(focused => {
          this.focused_ = focused;
          this.dragged_ = false;
        });
    this.setFakeboxVisibleListenerId_ =
        this.callbackRouter_.setFakeboxVisible.addListener(visible => {
          this.hidden_ = !visible;
        });
  }

  /** @override */
  disconnectedCallback() {
    super.disconnectedCallback();
    this.callbackRouter_.removeListener(
        assert(this.setFakeboxFocusedListenerId_));
    this.callbackRouter_.removeListener(
        assert(this.setFakeboxVisibleListenerId_));
  }

  /** @override */
  ready() {
    super.ready();
    performance.measure('fakebox-creation', 'fakebox-creation-start');
  }

  /** @private */
  onPointerDown_() {
    this.pageHandler_.focusOmnibox();
  }

  /**
   * @param {Event} e
   * @private
   */
  onPaste_(e) {
    e.preventDefault();
    const text = e.clipboardData.getData('text/plain');
    if (!text) {
      return;
    }
    this.pageHandler_.pasteIntoOmnibox(text);
  }

  /** @private */
  onDragenter_() {
    this.dragged_ = true;
  }

  /** @private */
  onDragleave_() {
    this.dragged_ = false;
  }

  /**
   * @param {Event} e
   * @private
   */
  onDrop_(e) {
    e.preventDefault();
    const text = e.dataTransfer.getData('text/plain');
    if (!text) {
      return;
    }
    this.pageHandler_.focusOmnibox();
    this.pageHandler_.pasteIntoOmnibox(text);
  }

  /** @private */
  onVoiceSearchClick_() {
    this.dispatchEvent(new Event('open-voice-search'));
  }
}

customElements.define(FakeboxElement.is, FakeboxElement);
