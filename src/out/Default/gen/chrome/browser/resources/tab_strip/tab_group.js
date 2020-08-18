// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';

import {CustomElement} from './custom_element.js';
import {TabStripEmbedderProxy, TabStripEmbedderProxyImpl} from './tab_strip_embedder_proxy.js';
import {TabGroupVisualData} from './tabs_api_proxy.js';

export class TabGroupElement extends CustomElement {
  static get template() {
    return `<!--_html_template_start_-->
<style>
:host {
  --tabstrip-tab-group-title-height: 22px;
  --tabstrip-tab-group-title-margin: var(--tabstrip-tab-spacing);
}

:host(:empty:not([dragging])) {
  /* A tab group can temporarily become empty as a tab is being dragged out. */
  display: none;
}

#tabGroup {
  border-radius: 8px;
  box-shadow: 0 0 0 1px rgb(var(--tabstrip-tab-group-color-rgb));
  padding: var(--tabstrip-tab-spacing);
}

#chipContainer {
  min-width: 100%;
  width: 0;
}

#chip {
  display: inline-block;
  height: var(--tabstrip-tab-group-title-height);
  margin-bottom: var(--tabstrip-tab-group-title-margin);
  max-width: 100%;
}

#chip:focus {
  outline: none;
}

#title {
  background: rgb(var(--tabstrip-tab-group-color-rgb));
  border-radius: 4px;
  box-sizing: border-box;
  color: rgb(var(--tabstrip-tab-group-text-color-rgb));
  display: inline-block;
  height: var(--tabstrip-tab-group-title-height);
  line-height: var(--tabstrip-tab-group-title-height);
  max-width: 100%;
  overflow: hidden;
  padding: 0 6px;
  text-overflow: ellipsis;
  white-space: nowrap;
}

#title:empty {
  border-radius: 50%;
  height: 16px;
  margin-top: 4px;
  width: 16px;
}

#chip:focus #title {
  box-shadow: 0 0 0 2px var(--tabstrip-focus-outline-color);
  outline: none;
}

#tabs {
  /* Cached CSS variable so the children could use them and override the
   * original values. */
  --ungrouped-tab-thumbnail-height: var(--tabstrip-tab-thumbnail-height);

  display: flex;
  min-width: fit-content;
}

:host ::slotted(tabstrip-tab) {
  --tabstrip-tab-thumbnail-height: calc(
      var(--ungrouped-tab-thumbnail-height) -
      var(--tabstrip-tab-group-title-height) -
      var(--tabstrip-tab-group-title-margin));
  --tabstrip-tab-thumbnail-width: calc(
      var(--tabstrip-tab-thumbnail-height) *
      var(--tabstrip-tab-thumbnail-aspect-ratio));

  /* Recalculate tab heights and widths off new thumbnail sizes. */
  --tabstrip-tab-height: calc(var(--tabstrip-tab-title-height) +
                              var(--tabstrip-tab-thumbnail-height));
  --tabstrip-tab-width: var(--tabstrip-tab-thumbnail-width);
}

:host([getting-drag-image_]) #dragImage {
  /* Enough padding for the drop shadow on #tabGroup. The position of the
     drag image is translated with the same value as the padding, to ensure
     that the drag image stays in the same position as it would be without
     padding. This is to ensure drag events do not get canceled as drag targets
     move around. */
  --drag-image-padding: 25px;
  padding: var(--drag-image-padding);
  transform: translate(
      calc(var(--drag-image-x-direction, -1) * var(--drag-image-padding)),
      calc(-1 * var(--drag-image-padding)));
}

:host-context([dir='rtl']):host([getting-drag-image_]) #dragImage {
  --drag-image-x-direction: 1;
}

:host([getting-drag-image_]) #tabGroup {
  background: var(--tabstrip-background-color);
  border-radius: var(--tabstrip-tab-border-radius);
  box-shadow: var(--tabstrip-tab-dragging-shadow);
  height: var(--tabstrip-tab-height);
  overflow: hidden;
  transform: scale(var(--tabstrip-tab-drag-image-scale));
}

:host([getting-drag-image_]) ::slotted(tabstrip-tab) {
  --tabstrip-tab-active-border-color: var(--tabstrip-tab-separator-color);
}

:host([getting-drag-image_]) ::slotted(tabstrip-tab:first-child) {
  /* Make sure the first tab is always above the other tabs. */
  z-index: 4;
}

:host([getting-drag-image_]) ::slotted(tabstrip-tab:nth-child(2)),
:host([getting-drag-image_]) ::slotted(tabstrip-tab:nth-child(3)),
:host([getting-drag-image_]) ::slotted(tabstrip-tab:nth-child(4)),
:host([getting-drag-image_]) ::slotted(tabstrip-tab:nth-child(5)) {
  /* Add a negative margin to the 2nd - 5th tab to move them behind the first
     tab to give an impression that they are a stacked group of tabs.
     Transform cannot be used here since we also want the space the tabs
     take up to be moved. */
  margin-inline-start: calc(-1 * var(--tabstrip-tab-width));
}

:host([getting-drag-image_]) ::slotted(tabstrip-tab:nth-child(2)) {
  z-index: 3;
}

:host([getting-drag-image_]) ::slotted(tabstrip-tab:nth-child(3)) {
  z-index: 2;
}

:host([getting-drag-image_]) ::slotted(tabstrip-tab:nth-child(4)) {
  z-index: 1;
}

:host([getting-drag-image_]) ::slotted(tabstrip-tab:nth-child(5)) {
  padding: 0;
  z-index: 0;
}

:host([getting-drag-image_]) ::slotted(tabstrip-tab:nth-child(n + 6)) {
  display: none;
}

:host([dragging]) #dragPlaceholder {
  background: var(--tabstrip-tab-background-color);
  border-radius: var(--tabstrip-tab-border-radius);
  height: var(--tabstrip-tab-height);
  opacity: 0.5;
  width: var(--tabstrip-tab-width);
}

:host([dragging]) #dragImage {
  /* Position the actual drag image out of view so it is not visible. */
  position: absolute;
  top: 100vh;
}
</style>

<div id="dragPlaceholder"></div>

<div id="dragImage">
  <div id="tabGroup">
    <div id="chipContainer">
      <div id="chip" draggable="true" tabindex="0" role="button"
         aria-describedby="tabs">
        <div id="title"></div>
      </div>
    </div>
    <div id="tabs">
      <slot></slot>
    </div>
  </div>
</div>
<!--_html_template_end_-->`;
  }

  constructor() {
    super();

    /** @private @const {!TabStripEmbedderProxy} */
    this.embedderApi_ = TabStripEmbedderProxyImpl.getInstance();

    /** @private @const {!HTMLElement} */
    this.chip_ = /** @type {!HTMLElement} */ (this.$('#chip'));
    this.chip_.addEventListener('click', () => this.onClickChip_());
    this.chip_.addEventListener(
        'keydown', e => this.onKeydownChip_(/** @type {!KeyboardEvent} */ (e)));

    /**
     * Flag indicating if this element can accept dragover events. This flag
     * is updated by TabListElement while animating.
     * @private {boolean}
     */
    this.isValidDragOverTarget_ = true;
  }

  /** @return {boolean} */
  get isValidDragOverTarget() {
    return !this.hasAttribute('dragging_') && this.isValidDragOverTarget_;
  }

  /** @param {boolean} isValid */
  set isValidDragOverTarget(isValid) {
    this.isValidDragOverTarget_ = isValid;
  }

  /** @return {!HTMLElement} */
  getDragImage() {
    return /** @type {!HTMLElement} */ (this.$('#dragImage'));
  }

  /** @private */
  onClickChip_() {
    if (!this.dataset.groupId) {
      return;
    }

    const boundingBox = this.$('#chip').getBoundingClientRect();
    this.embedderApi_.showEditDialogForGroup(
        this.dataset.groupId, boundingBox.left, boundingBox.top,
        boundingBox.width, boundingBox.height);
  }

  /**
   * @param {!KeyboardEvent} event
   * @private
   */
  onKeydownChip_(event) {
    if (event.key === 'Enter' || event.key === ' ') {
      this.onClickChip_();
    }
  }

  /** @param {boolean} enabled */
  setDragging(enabled) {
    // Since the draggable target is the #chip, if the #chip moves and is no
    // longer under the pointer while the dragstart event is happening, the drag
    // will get canceled. This is unfortunately the behavior of the native drag
    // and drop API. The workaround is to have two different attributes: one
    // to get the drag image and start the drag event while keeping #chip in
    // place, and another to update the placeholder to take the place of where
    // the #chip would be.
    this.toggleAttribute('getting-drag-image_', enabled);
    requestAnimationFrame(() => {
      this.toggleAttribute('dragging', enabled);
    });
  }

  /**
   * @param {!TabGroupVisualData} visualData
   */
  updateVisuals(visualData) {
    this.$('#title').innerText = visualData.title;
    this.style.setProperty('--tabstrip-tab-group-color-rgb', visualData.color);
    this.style.setProperty(
        '--tabstrip-tab-group-text-color-rgb', visualData.textColor);

    // Content strings are empty for the label and are instead replaced by
    // the aria-describedby attribute on the chip.
    if (visualData.title) {
      this.chip_.setAttribute(
          'aria-label',
          loadTimeData.getStringF('namedGroupLabel', visualData.title, ''));
    } else {
      this.chip_.setAttribute(
          'aria-label', loadTimeData.getStringF('unnamedGroupLabel', ''));
    }
  }
}

customElements.define('tabstrip-tab-group', TabGroupElement);

/**
 * @param {!Element} element
 * @return {boolean}
 */
export function isTabGroupElement(element) {
  return element.tagName === 'TABSTRIP-TAB-GROUP';
}
