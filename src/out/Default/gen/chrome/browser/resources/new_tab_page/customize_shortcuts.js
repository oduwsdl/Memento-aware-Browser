// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import './mini_page.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/cr_elements/cr_toggle/cr_toggle.m.js';
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {FocusOutlineManager} from 'chrome://resources/js/cr/ui/focus_outline_manager.m.js';
import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {BrowserProxy} from './browser_proxy.js';

/** Element that lets the user configure shortcut settings. */
class CustomizeShortcutsElement extends PolymerElement {
  static get is() {
    return 'ntp-customize-shortcuts';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style include="cr-icons">
  :host {
    line-height: 20px;
  }

  #options {
    display: flex;
  }

  .option {
    margin-inline-end: 9px;
    width: 268px;
  }

  .option-image {
    border: 1px solid var(--ntp-border-color);
    border-radius: 4px;
    box-sizing: border-box;
    cursor: pointer;
    height: 176px;
    position: relative;
    width: 268px;
  }

  :host-context(.focus-outline-visible) .option-image:focus {
    box-shadow: var(--ntp-focus-shadow);
  }

  .selected .option-image {
    background-color: var(--ntp-selected-background-color);
    border-color: var(--ntp-selected-border-color);
  }

  .option-mini {
    background-color: var(--ntp-background-override-color);
    border: 1px solid var(--ntp-border-color);
    border-radius: 4px;
    box-sizing: border-box;
    height: 144px;
    position: absolute;
    right: 40px;
    top: 16px;
    width: 144px;
  }

  html[dir=rtl] .option-mini {
    left: 40px;
    right: unset;
  }

  .selected .option-mini {
    border-color: transparent;
    box-shadow: 0 1px 3px 0 rgba(var(--google-grey-800-rgb), .3),
        0 4px 8px 3px rgba(var(--google-grey-800-rgb), .15);
  }

  @media (prefers-color-scheme: dark) {
    .selected .option-mini {
      box-shadow: 0 1px 3px 0 rgba(0, 0, 0, .3),
          0 4px 8px 3px rgba(0, 0, 0, .15);
    }
  }

  ntp-mini-page {
    --ntp-mini-page-shortcut-color: var(--google-grey-refresh-500);
  }

  .selected ntp-mini-page {
    --ntp-mini-page-shortcut-color: var(--ntp-selected-border-color);
  }

  .option-icon {
    -webkit-mask-repeat: no-repeat;
    -webkit-mask-size: 100%;
    background: 96px 96px var(--ntp-border-color);
    height: 96px;
    left: 16px;
    position: absolute;
    top: 48px;
    width: 96px;
  }

  #optionCustomLinks .option-icon {
    -webkit-mask-image: url(icons/account_circle.svg);
  }

  #optionMostVisited .option-icon {
    -webkit-mask-image: url(icons/generic_globe.svg);
  }

  html[dir=rtl] .option-icon {
    right: 16px;
  }

  .selected .option-icon {
    background-color: var(--ntp-selected-light-background-color);
  }

  @media (prefers-color-scheme: dark) {
    .selected .option-icon {
      background-color: var(--ntp-selected-border-color);
    }
  }

  .option-image .selected-circle {
    box-shadow: 0 3px 6px 1px rgba(0, 0, 0, .16),
        0 1px 2px 1px rgba(0, 0, 0, .23);
    height: 22px;
    left: 209px;
    top: 9px;
    width: 22px;
  }

  html[dir=rtl] .option-image .selected-circle {
    left: 0;
    right: 209px;
  }

  .option-image .selected-check {
    left: initial;
    right: 32px;
    top: 6px;
  }

  html[dir=rtl] .option-image .selected-check {
    left: 32px;
    right: initial;
  }

  .option-title {
    font-weight: bold;
    margin: 8px 0;
  }

  #hide {
    align-items: center;
    border: 1px solid var(--ntp-border-color);
    border-radius: 4px;
    box-sizing: border-box;
    display: flex;
    height: 64px;
    margin-top: 24px;
    max-width: 544px;
    width: 100%;
  }

  #hide.selected {
    background-color: var(--ntp-selected-background-color);
    border-color: var(--ntp-selected-border-color);
    color: var(--ntp-selected-border-color);
  }

  #hideIcon {
    margin-inline-end: 20px;
    margin-inline-start: 24px;
  }

  .selected #hideIcon {
    background-color: var(--ntp-selected-border-color);
  }

  #hideTitleContainer {
    flex-grow: 1;
  }

  #hideTitle {
    font-weight: bold;
  }

  cr-toggle {
    margin-inline-end: 20px;
  }

  .selected-circle {
    background: var(--ntp-background-override-color) no-repeat center;
    border-radius: 50%;
    display: none;
    height: 22px;
    left: 66px;
    position: absolute;
    top: 46px;
    width: 22px;
  }

  html[dir=rtl] .selected-circle {
    left: auto;
    right: 66px;
  }

  .selected-check {
    background: url(icons/check_circle.svg) no-repeat center;
    background-size: 28px 28px;
    display: none;
    height: 28px;
    left: 63px;
    position: absolute;
    top: 43px;
    width: 28px;
  }

  .selected :-webkit-any(.selected-circle, .selected-check) {
    display: block;
  }

  html[dir=rtl] .selected-check {
    left: auto;
    right: 63px;
  }

  @media (prefers-color-scheme: dark) {
    .selected-check {
      background: transparent;
    }
  }

  /* We use ::after without content to provide the masked check element. */
  @media (prefers-color-scheme: dark) {
    .selected-check::after {
      -webkit-mask-image: url(icons/check_circle.svg);
      -webkit-mask-repeat: no-repeat;
      -webkit-mask-size: 28px;
      background-color: var(--google-blue-refresh-300);
      content: '';
      display: block;
      height: 28px;
      left: 0;
      position: absolute;
      top: 0;
      width: 28px;
    }
  }
</style>
<div id="options">
  <div id="optionCustomLinks"
      class$="option [[getCustomLinksSelected_(customLinksEnabled_, hide_)]]">
    <cr-button id="optionCustomLinksButton" class="option-image" tabindex="0"
        aria-pressed$="[[getCustomLinksAriaPressed_(customLinksEnabled_,
            hide_)]]"
        title="$i18n{myShortcuts}" on-click="onCustomLinksClick_" noink>
      <div class="option-icon"></div>
      <div class="option-mini">
        <ntp-mini-page single-colored-logo></ntp-mini-page>
      </div>
      <div class="selected-circle"></div>
      <div class="selected-check"></div>
    </cr-button>
    <div class="option-title">$i18n{myShortcuts}</div>
    $i18n{shortcutsCurated}
  </div>
  <div id="optionMostVisited"
      class$="option [[getMostVisitedSelected_(customLinksEnabled_, hide_)]]">
    <cr-button id="optionMostVisitedButton" class="option-image" tabindex="0"
        aria-pressed$="[[getMostVisitedAriaPressed_(customLinksEnabled_,
            hide_)]]"
        title="$i18n{mostVisited}" on-click="onMostVisitedClick_"
        on-keydown="onMostVistedKey" noink>
      <div class="option-icon"></div>
      <div class="option-mini">
        <ntp-mini-page single-colored-logo></ntp-mini-page>
      </div>
      <div class="selected-circle"></div>
      <div class="selected-check"></div>
    </cr-button>
    <div class="option-title">$i18n{mostVisited}</div>
    $i18n{shortcutsSuggested}
  </div>
</div>
<div id="hide" class$="[[getHideClass_(hide_)]]">
  <div id="hideIcon" class="cr-icon icon-visibility-off"></div>
  <div id="hideTitleContainer">
    <div id="hideTitle">$i18n{hideShortcuts}</div>
    $i18n{hideShortcutsDesc}
  </div>
  <cr-toggle id="hideToggle" title="$i18n{hideShortcuts}" checked="[[hide_]]"
      on-change="onHideChange_"></cr-toggle>
</div>
<!--_html_template_end_-->`;
  }

  static get properties() {
    return {
      /** @private */
      customLinksEnabled_: Boolean,

      /** @private */
      hide_: Boolean,
    };
  }

  constructor() {
    super();
    const {callbackRouter, handler} = BrowserProxy.getInstance();
    /** @private {!newTabPage.mojom.PageCallbackRouter} */
    this.callbackRouter_ = callbackRouter;
    /** @private {newTabPage.mojom.PageHandlerRemote} */
    this.pageHandler_ = handler;
    /** @private {?number} */
    this.setMostVisitedInfoListenerId_ = null;
  }

  /** @override */
  connectedCallback() {
    super.connectedCallback();
    this.setMostVisitedInfoListenerId_ =
        this.callbackRouter_.setMostVisitedInfo.addListener(info => {
          this.customLinksEnabled_ = info.customLinksEnabled;
          this.hide_ = !info.visible;
        });
    this.pageHandler_.updateMostVisitedInfo();
    FocusOutlineManager.forDocument(document);
  }

  /** @override */
  disconnectedCallback() {
    super.disconnectedCallback();
    this.callbackRouter_.removeListener(
        assert(this.setMostVisitedInfoListenerId_));
  }

  apply() {
    this.pageHandler_.setMostVisitedSettings(
        this.customLinksEnabled_, /* visible= */ !this.hide_);
  }

  /**
   * @return {string}
   * @private
   */
  getCustomLinksAriaPressed_() {
    return !this.hide_ && this.customLinksEnabled_ ? 'true' : 'false';
  }

  /**
   * @return {string}
   * @private
   */
  getCustomLinksSelected_() {
    return !this.hide_ && this.customLinksEnabled_ ? 'selected' : '';
  }

  /**
   * @return {string}
   * @private
   */
  getHideClass_() {
    return this.hide_ ? 'selected' : '';
  }

  /**
   * @return {string}
   * @private
   */
  getMostVisitedAriaPressed_() {
    return !this.hide_ && !this.customLinksEnabled_ ? 'true' : 'false';
  }

  /**
   * @return {string}
   * @private
   */
  getMostVisitedSelected_() {
    return !this.hide_ && !this.customLinksEnabled_ ? 'selected' : '';
  }

  /** @private */
  onCustomLinksClick_() {
    if (!this.customLinksEnabled_) {
      this.pageHandler_.onCustomizeDialogAction(
          newTabPage.mojom.CustomizeDialogAction
              .SHORTCUTS_CUSTOM_LINKS_CLICKED);
    }
    this.customLinksEnabled_ = true;
    this.hide_ = false;
  }

  /**
   * @param {!CustomEvent<boolean>} e
   * @private
   */
  onHideChange_(e) {
    this.pageHandler_.onCustomizeDialogAction(
        newTabPage.mojom.CustomizeDialogAction
            .SHORTCUTS_VISIBILITY_TOGGLE_CLICKED);
    this.hide_ = e.detail;
  }


  /** @private */
  onMostVisitedClick_() {
    if (this.customLinksEnabled_) {
      this.pageHandler_.onCustomizeDialogAction(
          newTabPage.mojom.CustomizeDialogAction
              .SHORTCUTS_MOST_VISITED_CLICKED);
    }
    this.customLinksEnabled_ = false;
    this.hide_ = false;
  }
}

customElements.define(CustomizeShortcutsElement.is, CustomizeShortcutsElement);
