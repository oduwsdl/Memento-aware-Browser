// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_dialog/cr_dialog.m.js';
import 'chrome://resources/cr_elements/cr_toggle/cr_toggle.m.js';
import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-pages/iron-pages.js';
import 'chrome://resources/polymer/v3_0/iron-selector/iron-selector.js';
import './customize_backgrounds.js';
import './customize_shortcuts.js';
import './customize_themes.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {BrowserProxy} from './browser_proxy.js';
import {createScrollBorders} from './utils.js';

/** @enum {number} */
export const BackgroundSelectionType = {
  NO_SELECTION: 0,
  NO_BACKGROUND: 1,
  IMAGE: 2,
  DAILY_REFRESH: 3,
};

/**
 * A user can make three types of background selections: no background, image
 * or daily refresh for a selected collection. The selection is tracked an
 * object of this type.
 * @typedef {{
 *   type: !BackgroundSelectionType,
 *   image: (!newTabPage.mojom.CollectionImage|undefined),
 *   dailyRefreshCollectionId: (string|undefined),
 * }}
 */
export let BackgroundSelection;

/**
 * Dialog that lets the user customize the NTP such as the background color or
 * image.
 */
class CustomizeDialogElement extends PolymerElement {
  static get is() {
    return 'ntp-customize-dialog';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style include="cr-hidden-style cr-icons">
  cr-dialog::part(dialog) {
    height: 100%;
    max-height: 520px;
    min-width: 800px;
  }

  cr-dialog::part(wrapper) {
    height: 100%;
  }

  cr-dialog::part(body-container) {
    flex-grow: 1;
  }

  div[slot=title] {
    align-items: center;
    color: var(--ntp-primary-text-color);
    display: flex;
    flex-direction: row;
    height: 58px;
    padding: 0;
  }

  div[slot=body] {
    color: var(--cr-primary-text-color);
    display: flex;
    flex-direction: column;
    overflow: hidden;
    padding: 0;
  }

  #bodyContainer {
    display: flex;
    flex-direction: row;
    overflow: hidden;
  }

  div[slot=button-container] {
    padding-top: 16px;
  }

  #menuContainer,
  #pagesContainer {
    overflow: hidden;
  }

  #leftTitleSpacer,
  #menuContainer {
    flex-basis: 232px;
  }

  #title {
    line-height: 1.5;
    margin-bottom: -2px;
    padding-inline-end: 24px;
    user-select: none;
  }

  #title,
  #pagesContainer {
    flex-grow: 1;
  }

  #menu,
  #pages {
    height: 100%;
    overflow: auto;
  }

  #pages > iron-pages {
    /* Margin is for focus outline. */
    margin: 2px;
  }

  div[scroll-border] {
    border-bottom: 1px solid transparent;
  }

  div[scroll-border][show-1],
  div[scroll-border][show-2] {
    border-bottom-color: var(--ntp-border-color);
  }

  #menu {
    display: flex;
    flex-direction: column;
  }

  .menu-item {
    align-items: center;
    border-radius: 0 16px 16px 0;
    color: var(--ntp-primary-text-color);
    cursor: pointer;
    display: flex;
    flex-direction: row;
    flex-shrink: 0;
    font-size: 14px;
    height: 32px;
    outline: none;
    width: 192px;
  }

  .menu-item + .menu-item {
    margin-top: 16px;
  }

  :host-context([dir=rtl]) .menu-item {
    border-radius: 16px 0 0 16px;
  }

  .menu-item:hover,
  .menu-item:focus {
    background-color: var(--ntp-hover-background-color);
  }

  .menu-item:active {
    background-color: var(--ntp-active-background-color);
  }

  .menu-item[selected] {
    background-color: var(--ntp-selected-background-color);
    color: var(--ntp-selected-primary-text-color);
  }

  .menu-item-icon {
    -webkit-mask-repeat: no-repeat;
    -webkit-mask-size: 100%;
    background-color: var(--ntp-primary-text-color);
    height: 20px;
    margin-inline-end: 16px;
    margin-inline-start: 24px;
    width: 20px;
  }

  .menu-item[selected] .menu-item-icon {
    background-color: var(--ntp-selected-primary-text-color);
  }

  #backgroundsIcon {
    -webkit-mask-image: url(icons/backgrounds.svg);
  }

  #shortcutsIcon {
    -webkit-mask-image: url(icons/link.svg);
  }

  #themesIcon {
    -webkit-mask-image: url(icons/colors.svg);
  }

  #backButton {
    --cr-icon-button-fill-color: var(--ntp-primary-text-color);
    margin-inline-end: 4px;
    /* So that the arrow aligns with the grid. */
    margin-inline-start: -12px;
  }

  #titleNavigation {
    align-items: center;
    display: flex;
    flex-direction: row;
  }

  cr-toggle {
    margin-inline-end: 12px;
  }

  #collectionTitle {
    flex-grow: 1;
  }
</style>
<cr-dialog id="dialog" on-cancel="onCancel_" show-on-attach>
  <div slot="title">
    <div id="leftTitleSpacer"></div>
    <div id="title">
      <div id="titleText" hidden="[[showTitleNavigation_]]">
        $i18n{customizeThisPage}
      </div>
      <div id="titleNavigation" hidden="[[!showTitleNavigation_]]">
        <cr-icon-button id="backButton" class="icon-arrow-back"
            on-click="onBackClick_" title="$i18n{backButton}">
        </cr-icon-button>
        <div id="collectionTitle">[[selectedCollection_.label]]</div>
        <cr-toggle id="refreshToggle" checked="[[isRefreshToggleChecked_]]"
            on-change="onBackgroundDailyRefreshToggleChange_">
        </cr-toggle>
        $i18n{refreshDaily}
      </div>
    </div>
  </div>
  <div slot="body">
    <div id="topPageScrollBorder" scroll-border></div>
    <div id="bodyContainer">
      <div id="menuContainer">
        <div id="menu">
          <iron-selector selected-attribute="selected"
              attr-for-selected="page-name" selected="{{selectedPage_}}"
              on-keydown="onMenuItemKeyDown_">
            <div class="menu-item" page-name="backgrounds" tabindex="0">
              <div id="backgroundsIcon" class="menu-item-icon"></div>
              $i18n{backgroundsMenuItem}
            </div>
            <div class="menu-item" page-name="shortcuts" tabindex="0">
              <div id="shortcutsIcon" class="menu-item-icon"></div>
              $i18n{shortcutsMenuItem}
            </div>
            <div class="menu-item" page-name="themes" tabindex="0">
              <div id="themesIcon" class="menu-item-icon"></div>
              $i18n{themesMenuItem}
            </div>
          </iron-selector>
        </div>
      </div>
      <div id="pagesContainer">
        <div id="pages">
          <iron-pages selected="[[selectedPage_]]"
              attr-for-selected="page-name">
            <ntp-customize-backgrounds id="backgrounds" page-name="backgrounds"
                selected-collection="{{selectedCollection_}}" theme="[[theme]]"
                background-selection="{{backgroundSelection}}">
            </ntp-customize-backgrounds>
            <ntp-customize-shortcuts page-name="shortcuts">
            </ntp-customize-shortcuts>
            <ntp-customize-themes page-name="themes" theme="[[theme]]">
            </ntp-customize-themes>
          </iron-pages>
        </div>
      </div>
    </div>
    <div id="bottomPageScrollBorder" scroll-border></div>
  </div>
  <div slot="button-container">
    <cr-button class="cancel-button" on-click="onCancelClick_">
      $i18n{cancelButton}
    </cr-button>
    <cr-button class="action-button" on-click="onDoneClick_">
      $i18n{doneButton}
    </cr-button>
  </div>
</cr-dialog>
<!--_html_template_end_-->`;
  }

  static get properties() {
    return {
      /**
       * This is the background selection which is two-way bound to ntp-app for
       * previewing the background and ntp-customize-background which makes the
       * image and no background selections.
       * @type {!BackgroundSelection}
       */
      backgroundSelection: {
        type: Object,
        notify: true,
      },

      /** @type {!newTabPage.mojom.Theme} */
      theme: Object,

      /** @private */
      selectedPage_: {
        type: String,
        value: 'backgrounds',
        observer: 'onSelectedPageChange_',
      },

      /** @private {newTabPage.mojom.BackgroundCollection} */
      selectedCollection_: Object,

      /** @private */
      showTitleNavigation_: {
        type: Boolean,
        computed:
            'computeShowTitleNavigation_(selectedPage_, selectedCollection_)',
        value: false,
      },

      /** @private */
      isRefreshToggleChecked_: {
        type: Boolean,
        computed: `computeIsRefreshToggleChecked_(theme, selectedCollection_,
            backgroundSelection)`,
      },
    };
  }

  constructor() {
    super();
    /** @private {newTabPage.mojom.PageHandlerRemote} */
    this.pageHandler_ = BrowserProxy.getInstance().handler;
    /** @private {!Array<!IntersectionObserver>} */
    this.intersectionObservers_ = [];
    this.backgroundSelection = {type: BackgroundSelectionType.NO_SELECTION};
  }

  /** @override */
  disconnectedCallback() {
    super.disconnectedCallback();
    this.intersectionObservers_.forEach(observer => {
      observer.disconnect();
    });
    this.intersectionObservers_ = [];
  }

  /** @override */
  ready() {
    super.ready();
    this.intersectionObservers_ = [
      createScrollBorders(
          this.$.menu, this.$.topPageScrollBorder,
          this.$.bottomPageScrollBorder, 'show-1'),
      createScrollBorders(
          this.$.pages, this.$.topPageScrollBorder,
          this.$.bottomPageScrollBorder, 'show-2'),
    ];
    this.pageHandler_.onCustomizeDialogAction(
        newTabPage.mojom.CustomizeDialogAction.OPEN_CLICKED);
  }

  /** @private */
  onCancel_() {
    this.pageHandler_.revertThemeChanges();
    this.backgroundSelection = {type: BackgroundSelectionType.NO_SELECTION};
  }

  /** @private */
  onCancelClick_() {
    this.pageHandler_.onCustomizeDialogAction(
        newTabPage.mojom.CustomizeDialogAction.CANCEL_CLICKED);
    this.$.dialog.cancel();
  }

  /**
   * The |backgroundSelection| is used in ntp-app to preview the image and has
   * precedence over the theme background setting. |backgroundSelection| is not
   * reset because it takes time for the theme to update, and after the update
   * the theme and |backgroundSelection| are the same. By not resetting the
   * value here, ntp-app can reset it if needed (other theme update). This
   * prevents a flicker between |backgroundSelection| and the previous theme
   * background setting.
   * @private
   */
  onDoneClick_() {
    this.pageHandler_.confirmThemeChanges();
    this.shadowRoot.querySelector('ntp-customize-shortcuts').apply();
    switch (this.backgroundSelection.type) {
      case BackgroundSelectionType.NO_BACKGROUND:
        this.pageHandler_.setNoBackgroundImage();
        break;
      case BackgroundSelectionType.IMAGE:
        const {attribution1, attribution2, attributionUrl, imageUrl} =
            assert(this.backgroundSelection.image);
        this.pageHandler_.setBackgroundImage(
            attribution1, attribution2, attributionUrl, imageUrl);
        break;
      case BackgroundSelectionType.DAILY_REFRESH:
        this.pageHandler_.setDailyRefreshCollectionId(
            assert(this.backgroundSelection.dailyRefreshCollectionId));
    }
    this.pageHandler_.onCustomizeDialogAction(
        newTabPage.mojom.CustomizeDialogAction.DONE_CLICKED);
    this.$.dialog.close();
  }

  /**
   * @param {!Event} e
   * @private
   */
  onMenuItemKeyDown_(e) {
    if (!['Enter', ' '].includes(e.key)) {
      return;
    }
    e.preventDefault();
    e.stopPropagation();
    this.selectedPage_ = e.target.getAttribute('page-name');
  }

  /** @private */
  onSelectedPageChange_() {
    this.$.pages.scrollTop = 0;
  }

  /**
   * @return {boolean}
   * @private
   */
  computeIsRefreshToggleChecked_() {
    if (!this.selectedCollection_) {
      return false;
    }
    switch (this.backgroundSelection.type) {
      case BackgroundSelectionType.NO_SELECTION:
        return !!this.theme &&
            this.selectedCollection_.id === this.theme.dailyRefreshCollectionId;
      case BackgroundSelectionType.DAILY_REFRESH:
        return this.selectedCollection_.id ===
            this.backgroundSelection.dailyRefreshCollectionId;
    }
    return false;
  }

  /**
   * @return {boolean}
   * @private
   */
  computeShowTitleNavigation_() {
    return this.selectedPage_ === 'backgrounds' && !!this.selectedCollection_;
  }

  /** @private */
  onBackClick_() {
    this.selectedCollection_ = null;
    this.pageHandler_.onCustomizeDialogAction(
        newTabPage.mojom.CustomizeDialogAction.BACKGROUNDS_BACK_CLICKED);
  }

  /** @private */
  onBackgroundDailyRefreshToggleChange_() {
    if (this.$.refreshToggle.checked) {
      this.backgroundSelection = {
        type: BackgroundSelectionType.DAILY_REFRESH,
        dailyRefreshCollectionId: this.selectedCollection_.id,
      };
    } else {
      this.backgroundSelection = {type: BackgroundSelectionType.NO_BACKGROUND};
    }
    this.pageHandler_.onCustomizeDialogAction(
        newTabPage.mojom.CustomizeDialogAction
            .BACKGROUNDS_REFRESH_TOGGLE_CLICKED);
  }
}

customElements.define(CustomizeDialogElement.is, CustomizeDialogElement);
