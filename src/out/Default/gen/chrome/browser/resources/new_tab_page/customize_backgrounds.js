// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import './grid.js';
import './mini_page.js';
import './untrusted_iframe.js';

import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {BrowserProxy} from './browser_proxy.js';
import {BackgroundSelection, BackgroundSelectionType} from './customize_dialog.js';

/** Element that lets the user configure the background. */
class CustomizeBackgroundsElement extends PolymerElement {
  static get is() {
    return 'ntp-customize-backgrounds';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style include="cr-hidden-style">
  :host {
    display: flex;
  }

  #container {
    padding: 4px;
  }

  ntp-grid {
    --ntp-grid-gap: 8px;
  }

  .tile {
    cursor: pointer;
    outline-width: 0;
  }

  ntp-untrusted-iframe {
    pointer-events: none;
  }

  :host-context(.focus-outline-visible) .tile:focus {
    box-shadow: var(--ntp-focus-shadow);
  }

  .image {
    border-radius: 4px;
    display: block;
    height: 176px;
    width: 176px;
  }

  .label {
    color: var(--ntp-primary-text-color);
    margin-bottom: 4px;
    margin-top: 3px;
    min-height: 30px;
  }

  .selected {
    background-color: var(--ntp-selected-background-color);
    border-radius: 4px;
    position: relative;
  }

  .selected .image,
  .selected #uploadFromDevice {
    box-shadow: 0 1px 3px 0 rgba(var(--google-grey-800-rgb), .3),
        0 4px 8px 3px rgba(var(--google-grey-800-rgb), .15);
  }

  .selected .image {
    transform: scale(.8);
  }

  .selected-circle {
    background-color: var(--ntp-background-override-color);
    border-radius: 50%;
    box-shadow: 0 3px 6px 1px rgba(0, 0, 0, .16),
        0 1px 2px 1px rgba(0, 0, 0, .23);
    display: none;
    height: 22px;
    left: initial;
    position: absolute;
    right: 10px;
    top: 8px;
    width: 22px;
  }

  :host-context([dir=rtl]) .selected-circle {
    left: 10px;
    right: initial;
  }

  .selected-check {
    -webkit-mask-image: url(icons/check_circle.svg);
    -webkit-mask-repeat: no-repeat;
    -webkit-mask-size: 28px;
    background-color: var(--ntp-selected-border-color);
    display: none;
    height: 28px;
    left: initial;
    position: absolute;
    right: 7px;
    top: 5px;
    width: 28px;
  }

  :host-context([dir=rtl]) .selected-check {
    left: 7px;
    right: initial;
  }

  .selected :-webkit-any(.selected-circle, .selected-check) {
    display: block;
  }

  #noBackground .image,
  #uploadFromDevice .image {
    background: var(--ntp-background-override-color);
    border: 1px solid var(--ntp-border-color);
  }

  #uploadFromDevice {
    position: relative;
  }

  #uploadFromDeviceImage {
    position: absolute;
    top: 0;
    width: 100%;
  }

  #uploadFromDeviceImage .label {
    text-align: center;
  }

  #uploadIcon {
    -webkit-mask-image: url(icons/upload.svg);
    -webkit-mask-repeat: no-repeat;
    -webkit-mask-size: 100%;
    background-color: var(--google-grey-refresh-700);
    height: 32px;
    margin: 61px auto 8px;
    width: 32px;
  }

  #backgroundsDisabled {
    align-items: center;
    align-self: center;
    display: flex;
    flex-direction: column;
    width: 100%;
  }

  #backgroundsDisabledIcon {
    -webkit-mask-image: url(chrome://resources/images/business.svg);
    -webkit-mask-repeat: no-repeat;
    -webkit-mask-size: 100%;
    background-color: var(--ntp-primary-text-color);
    height: 48px;
    margin: auto;
    width: 48px;
  }

  #backgroundsDisabledTitle {
    margin-top: 10px;
    text-align: center;
    width: 50%;
  }

  @media (prefers-color-scheme: dark) {
    .selected .image,
    .selected #uploadFromDevice {
      box-shadow: 0 1px 3px 0 rgba(0, 0, 0, .3),
          0 4px 8px 3px rgba(0, 0, 0, .15);
    }

    #uploadIcon {
      background-color: var(--google-grey-refresh-500);
    }
  }
</style>
<div id="backgroundsDisabled" hidden$="[[!customBackgroundDisabledByPolicy_]]">
  <div id="backgroundsDisabledIcon"></div>
  <div id="backgroundsDisabledTitle">$i18n{customBackgroundDisabled}</div>
</div>
<ntp-grid id="collections" columns="3" hidden="[[!showBackgroundSelection_]]">
  <div id="uploadFromDevice" class="tile" role="button"
      on-click="onUploadFromDeviceClick_" tabindex="0">
    <div class$="[[getCustomBackgroundClass_(theme, backgroundSelection)]]">
      <div class="image">
      </div>
      <div id="uploadFromDeviceImage">
        <div id="uploadIcon"></div>
        <div class="label">$i18n{uploadFromDevice}</div>
      </div>
      <div class="selected-circle"></div>
      <div class="selected-check"></div>
    </div>
    <div class="label"></div>
  </div>
  <div id="noBackground" class="tile" role="button" on-click="onDefaultClick_"
       tabindex="0">
    <div class$="[[getNoBackgroundClass_(theme, backgroundSelection)]]">
      <div class="image">
        <ntp-mini-page></ntp-mini-page>
      </div>
      <div class="selected-circle"></div>
      <div class="selected-check"></div>
    </div>
    <div class="label">$i18n{noBackground}</div>
  </div>
  <dom-repeat id="collectionsRepeat" items="[[collections_]]">
    <template>
      <div class="tile" tabindex="0" title="[[item.label]]" role="button"
          on-click="onCollectionClick_">
        <ntp-untrusted-iframe class="image"
            path="background_image?[[item.previewImageUrl.url]]">
        </ntp-untrusted-iframe>
        <div class="label">[[item.label]]</div>
      </div>
    </template>
  </dom-repeat>
</ntp-grid>
<ntp-grid id="images" columns="3" hidden="[[!selectedCollection]]">
  <dom-repeat id="imagesRepeat" items="[[images_]]">
    <template>
      <div
          class$="tile
              [[getImageSelectedClass_(index, theme, backgroundSelection)]]"
          tabindex="0" title="[[item.attribution1]]" role="button"
          on-click="onImageClick_">
        <ntp-untrusted-iframe class="image"
            path="background_image?[[item.previewImageUrl.url]]">
        </ntp-untrusted-iframe>
        <div class="selected-circle"></div>
        <div class="selected-check"></div>
      </div>
    </template>
  </dom-repeat>
</ntp-grid>
<!--_html_template_end_-->`;
  }

  static get properties() {
    return {
      /** @type {!BackgroundSelection} */
      backgroundSelection: {
        type: Object,
        value: () => ({type: BackgroundSelectionType.NO_SELECTION}),
        notify: true,
      },

      /** @private */
      customBackgroundDisabledByPolicy_: {
        type: Boolean,
        value: () =>
            loadTimeData.getBoolean('customBackgroundDisabledByPolicy'),
      },

      /** @private */
      showBackgroundSelection_: {
        type: Boolean,
        computed: 'computeShowBackgroundSelection_(selectedCollection)',
      },

      /** @private {newTabPage.mojom.BackgroundCollection} */
      selectedCollection: {
        notify: true,
        observer: 'onSelectedCollectionChange_',
        type: Object,
        value: null,
      },

      /** @type {!newTabPage.mojom.Theme} */
      theme: Object,

      /** @private {!Array<!newTabPage.mojom.BackgroundCollection>} */
      collections_: Array,

      /** @private {!Array<!newTabPage.mojom.CollectionImage>} */
      images_: Array,
    };
  }

  constructor() {
    super();
    if (this.customBackgroundDisabledByPolicy_) {
      return;
    }
    /** @private {newTabPage.mojom.PageHandlerRemote} */
    this.pageHandler_ = BrowserProxy.getInstance().handler;
    this.pageHandler_.getBackgroundCollections().then(({collections}) => {
      this.collections_ = collections;
    });
  }

  /**
   * @return {boolean}
   * @private
   */
  computeShowBackgroundSelection_() {
    return !this.customBackgroundDisabledByPolicy_ && !this.selectedCollection;
  }

  /**
   * @return {string}
   * @private
   */
  getCustomBackgroundClass_() {
    switch (this.backgroundSelection.type) {
      case BackgroundSelectionType.NO_SELECTION:
        return this.theme && this.theme.backgroundImage &&
                this.theme.backgroundImage.url.url.startsWith(
                    'chrome-untrusted://new-tab-page/background.jpg') ?
            'selected' :
            '';
      default:
        return '';
    }
  }

  /**
   * @return {string}
   * @private
   */
  getNoBackgroundClass_() {
    switch (this.backgroundSelection.type) {
      case BackgroundSelectionType.NO_BACKGROUND:
        return 'selected';
      case BackgroundSelectionType.NO_SELECTION:
        return this.theme && !this.theme.backgroundImage &&
                !this.theme.dailyRefreshCollectionId ?
            'selected' :
            '';
      case BackgroundSelectionType.IMAGE:
      case BackgroundSelectionType.DAILY_REFRESH:
      default:
        return '';
    }
  }

  /**
   * @param {number} index
   * @return {string}
   * @private
   */
  getImageSelectedClass_(index) {
    const {url} = this.images_[index].imageUrl;
    switch (this.backgroundSelection.type) {
      case BackgroundSelectionType.IMAGE:
        return this.backgroundSelection.image.imageUrl.url === url ?
            'selected' :
            '';
      case BackgroundSelectionType.NO_SELECTION:
        return this.theme && this.theme.backgroundImage &&
                this.theme.backgroundImage.url.url === url &&
                !this.theme.dailyRefreshCollectionId ?
            'selected' :
            '';
      case BackgroundSelectionType.NO_BACKGROUND:
      case BackgroundSelectionType.DAILY_REFRESH:
      default:
        return '';
    }
  }

  /**
   * @param {!Event} e
   * @private
   */
  onCollectionClick_(e) {
    this.selectedCollection = this.$.collectionsRepeat.itemForElement(e.target);
    this.pageHandler_.onCustomizeDialogAction(
        newTabPage.mojom.CustomizeDialogAction.BACKGROUNDS_COLLECTION_OPENED);
  }

  /** @private */
  async onUploadFromDeviceClick_() {
    this.pageHandler_.onCustomizeDialogAction(
        newTabPage.mojom.CustomizeDialogAction
            .BACKGROUNDS_UPLOAD_FROM_DEVICE_CLICKED);
    const {success} = await this.pageHandler_.chooseLocalCustomBackground();
    if (success) {
      // The theme update is asynchronous. Close the dialog and allow ntp-app
      // to update the |backgroundSelection|.
      this.dispatchEvent(new Event('close', {bubbles: true, composed: true}));
    }
  }

  /** @private */
  onDefaultClick_() {
    if (this.backgroundSelection.type !==
        BackgroundSelectionType.NO_BACKGROUND) {
      this.pageHandler_.onCustomizeDialogAction(
          newTabPage.mojom.CustomizeDialogAction
              .BACKGROUNDS_NO_BACKGROUND_SELECTED);
    }
    this.backgroundSelection = {type: BackgroundSelectionType.NO_BACKGROUND};
  }

  /**
   * @param {!Event} e
   * @private
   */
  onImageClick_(e) {
    const image = this.$.imagesRepeat.itemForElement(e.target);
    if (this.backgroundSelection.type !== BackgroundSelectionType.IMAGE ||
        this.backgroundSelection.image !== image) {
      this.pageHandler_.onCustomizeDialogAction(
          newTabPage.mojom.CustomizeDialogAction.BACKGROUNDS_IMAGE_SELECTED);
    }
    this.backgroundSelection = {
      type: BackgroundSelectionType.IMAGE,
      image: image,
    };
  }

  /** @private */
  async onSelectedCollectionChange_() {
    this.images_ = [];
    if (!this.selectedCollection) {
      return;
    }
    const collectionId = this.selectedCollection.id;
    const {images} = await this.pageHandler_.getBackgroundImages(collectionId);
    // We check the IDs match since the user may have already moved to a
    // different collection before the results come back.
    if (!this.selectedCollection ||
        this.selectedCollection.id !== collectionId) {
      return;
    }
    this.images_ = images;
  }
}

customElements.define(
    CustomizeBackgroundsElement.is, CustomizeBackgroundsElement);
