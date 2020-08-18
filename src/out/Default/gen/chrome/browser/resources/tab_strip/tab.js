// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import './strings.m.js';

import {assert} from 'chrome://resources/js/assert.m.js';
import {getFavicon} from 'chrome://resources/js/icon.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {isRTL} from 'chrome://resources/js/util.m.js';

import {AlertIndicatorsElement} from './alert_indicators.js';
import {CustomElement} from './custom_element.js';
import {TabStripEmbedderProxy, TabStripEmbedderProxyImpl} from './tab_strip_embedder_proxy.js';
import {tabStripOptions} from './tab_strip_options.js';
import {TabSwiper} from './tab_swiper.js';
import {CloseTabAction, TabData, TabNetworkState, TabsApiProxy, TabsApiProxyImpl} from './tabs_api_proxy.js';

const DEFAULT_ANIMATION_DURATION = 125;

/**
 * @param {!TabData} tab
 * @return {string}
 */
function getAccessibleTitle(tab) {
  const tabTitle = tab.title;

  if (tab.crashed) {
    return loadTimeData.getStringF('tabCrashed', tabTitle);
  }

  if (tab.networkState === TabNetworkState.ERROR) {
    return loadTimeData.getStringF('tabNetworkError', tabTitle);
  }

  return tabTitle;
}

/**
 * TODO(crbug.com/1025390): padding-inline-end cannot be animated yet.
 * @return {string}
 */
function getPaddingInlineEndProperty() {
  return isRTL() ? 'paddingLeft' : 'paddingRight';
}

export class TabElement extends CustomElement {
  static get template() {
    return `<!--_html_template_start_-->
<style>
  :host {
    --tabstrip-tab-transition-duration: 250ms;

    display: block;
    height: var(--tabstrip-tab-height);
    padding-inline-end: var(--tabstrip-tab-spacing);
    position: relative;
    transform-origin: top left;
    width: var(--tabstrip-tab-width);
  }

  :host-context([dir='rtl']) {
    transform-origin: top right;
  }

  #tab {
    background: var(--tabstrip-tab-background-color);
    border-radius: var(--tabstrip-tab-border-radius);
    box-shadow: 0 0 0 1px var(--tabstrip-tab-separator-color);
    color: var(--tabstrip-tab-text-color);
    display: flex;
    flex-direction: column;
    height: var(--tabstrip-tab-height);
    overflow: hidden;
    width: var(--tabstrip-tab-width);
  }

  #tab:focus {
    outline: none;
  }

  :host-context(.focus-outline-visible) #tab:focus {
    box-shadow: 0 0 0 2px var(--tabstrip-focus-outline-color);
  }

  :host([active]) #tab {
    box-shadow: 0 0 0 2px var(--tabstrip-tab-active-border-color);
  }

  :host-context(.focus-outline-visible):host([active]) #tab:focus {
    box-shadow: 0 0 0 4px var(--tabstrip-focus-outline-color),
                0 0 0 2px var(--tabstrip-tab-active-border-color);
  }

  #title {
    align-items: center;
    border-block-end: 1px solid var(--tabstrip-tab-separator-color);
    box-sizing: border-box;
    display: flex;
    height: var(--tabstrip-tab-title-height);
    justify-content: center;
    margin: 0;
    overflow: hidden;
  }

  #faviconContainer {
    --favicon-size: 16px;
    flex-shrink: 0;
    height: var(--favicon-size);
    margin-inline-end: 8px;
    margin-inline-start: 12px;
    max-width: var(--favicon-size);
    position: relative;
    /* When transitioning to the default visible state, the margin and max-width
     * transitions should finish first, then the opacity should be set to 1.
     * This prevents the favicon and loading spinners from looking cropped
     * while the element transitions. */
    transition: margin var(--tabstrip-tab-transition-duration),
                max-width var(--tabstrip-tab-transition-duration),
                opacity 0ms linear var(--tabstrip-tab-transition-duration);
    width: var(--favicon-size);
  }

  :host([hide-icon_]) #faviconContainer {
    margin-inline-end: 0;
    max-width: 0;
    opacity: 0;
    /* When transitioning to the hidden state, set opacity immediately to 0
     * while transitioning the other values normally. */
    transition: margin var(--tabstrip-tab-transition-duration),
                max-width var(--tabstrip-tab-transition-duration),
                opacity 0ms;
  }

  :host([pinned]) #faviconContainer {
    margin: 0;
  }

  #progressSpinner,
  #favicon,
  #crashedIcon {
    height: var(--favicon-size);
    left: 50%;
    position: absolute;
    top: 50%;
    transform: translate(-50%, -50%);
    width: var(--favicon-size);
  }

  #progressSpinner {
    -webkit-mask:
        url(chrome://resources/images/throbber_small.svg)
        center/contain no-repeat;
    display: none;
  }

  #favicon {
    background-size: contain;
    transition: border-radius var(--tabstrip-tab-transition-duration);
  }

  #crashedIcon {
    -webkit-mask:
        url(chrome://theme/IDR_CRASH_SAD_FAVICON@2x)
        center/contain no-repeat;
    background-color: currentColor;
    opacity: 0;
    transform: translate(-50%, 100%);
  }

  #blocked {
    background: var(--tabstrip-tab-blocked-color);
    border: solid 1px var(--tabstrip-tab-background-color);
    border-radius: 50%;
    bottom: 0;
    display: none;
    height: 6px;
    position: absolute;
    right: 0;
    transform: translate(50%, 50%);
    width: 6px;
  }

  :host([waiting_]) #progressSpinner,
  :host([loading_]) #progressSpinner {
    display: block;
  }

  :host([loading_]) #favicon {
    border-radius: 50%;
    height: calc(var(--favicon-size) - 6px);
    overflow: hidden;
    width: calc(var(--favicon-size) - 6px);
  }

  :host([waiting_]) #progressSpinner {
    background-color: var(--tabstrip-tab-waiting-spinning-color);
    transform: /* Center first, then flip horizontally. */
              translate(-50%, -50%) scaleX(-1);
  }

  :host([waiting_]) #favicon {
    display: none;
  }

  :host([loading_]) #progressSpinner {
    background-color: var(--tabstrip-tab-loading-spinning-color);
  }

  :host([crashed_]) #favicon {
    opacity: 0;
    transform: translate(-50%, 100%);
    transition:
        opacity var(--tabstrip-tab-transition-duration),
        transform var(--tabstrip-tab-transition-duration);
  }

  :host([crashed_]) #crashedIcon {
    opacity: 1;
    transform: translate(-50%, -50%);
    transition:
        opacity var(--tabstrip-tab-transition-duration),
        transform var(--tabstrip-tab-transition-duration);
    /* Wait until transition for #favicon finishes. */
    transition-delay: var(--tabstrip-tab-transition-duration);
  }

  :host([blocked_]) #blocked {
    display: block;
  }

  :host([active][blocked_]) #blocked {
    display: none;
  }

  #titleText {
    flex: 1;
    font-size: 100%;
    font-weight: normal;
    overflow: hidden;
    text-overflow: ellipsis;
    white-space: nowrap;
  }

  :host([has-alert-states_]) #titleText {
    margin-inline-end: 4px;
  }

  #close {
    -webkit-appearance: none;
    -webkit-tap-highlight-color: transparent;
    align-items: center;
    background-color: transparent;
    border: 0;
    color: inherit;
    cursor: pointer;
    display: flex;
    flex-shrink: 0;
    height: 100%;
    justify-content: center;
    outline: none;
    padding: 0;
    position: relative;
    width: 36px;
  }

  #closeIcon {
    -webkit-mask:
        url(chrome://resources/images/icon_clear.svg) center/contain no-repeat;
    background-color: currentColor;
    display: block;
    height: 18px;
    position: relative;
    width: 18px;
  }

  :host-context(.focus-outline-visible) #close:focus #closeIconFocus {
    background: currentColor;
    border-radius: 50%;
    height: 24px;
    opacity: 0.16;
    position: absolute;
    width: 24px;
  }

  #thumbnail {
    align-items: flex-start;
    background: var(--tabstrip-tab-background-color);
    display: flex;
    flex: 1;
    height: var(--tabstrip-tab-thumbnail-height);
    justify-content: center;
    width: var(--tabstrip-tab-thumbnail-width);
  }

  #thumbnailImg {
    min-height: 100%;
    object-fit: cover;
    pointer-events: none;
    width: 100%;
  }

  #thumbnailImg:not([src]) {
    display: none;
    pointer-events: none;
    width: 100%;
  }

  /* Pinned tab styles */
  :host([pinned]) {
    --tabstrip-tab-height: var(--tabstrip-pinned-tab-size);
    --tabstrip-tab-width: var(--tabstrip-pinned-tab-size);
  }

  :host([pinned]) #title {
    border-block-end: 0;
    height: 100%;
  }

  :host([pinned]) #titleText,
  :host([pinned]) #close,
  :host([pinned]) #thumbnail {
    display: none;
  }

  :host([pinned][has-alert-states_]) #faviconContainer {
    display: none;
  }

  :host([dragging_]) #dragPlaceholder {
    background: var(--tabstrip-tab-background-color);
    border-radius: var(--tabstrip-tab-border-radius);
    height: 100%;
    opacity: 0.5;
    width: 100%;
  }

  /* When being dragged, the contents of the drag image needs to be off-screen
   * with nothing else on top or below obscuring it. */
  :host([dragging_]) #dragImage {
    /* Enough padding to not crop the box shadow set on #tab below. */
    --drag-image-padding: 25px;
    align-items: center;
    display: flex;
    height: 100%;
    justify-content: center;
    padding-block-end: var(--drag-image-padding);
    padding-block-start: var(--drag-image-padding);
    padding-inline-end: calc(
        var(--tabstrip-tab-spacing) + var(--drag-image-padding));
    padding-inline-start: var(--drag-image-padding);
    position: absolute;
    top: 100vh;
    width: 100%;
  }

  :host([dragging_]) #tab {
    box-shadow: var(--tabstrip-tab-dragging-shadow);
    transform: scale(var(--tabstrip-tab-drag-image-scale));
  }
</style>

<div id="dragPlaceholder"></div>

<!--
  #dragImage is a wrapper that wraps the entire #tab contents so that #tab can
  be styled with properties, such as box-shadow, that extend beyond #tab's
  boundaries and #dragImage can add padding to itself to contain all of #tab's
  styles. When the tab is not being dragged, the #dragImage parent has no use.
-->
<div id="dragImage">
  <div id="tab" role="tab" tabindex="0"
      aria-labelledby="titleText alertIndicators">
    <header id="title">
      <div id="faviconContainer" aria-hidden="true">
        <div id="progressSpinner"></div>
        <div id="favicon"></div>
        <div id="crashedIcon"></div>
        <div id="blocked"></div>
      </div>
      <h2 id="titleText"></h2>
      <tabstrip-alert-indicators id="alertIndicators">
      </tabstrip-alert-indicators>
      <button id="close" aria-describedby="titleText">
        <span id="closeIconFocus"></span>
        <span id="closeIcon"></span>
      </button>
    </header>

    <div id="thumbnail">
      <img id="thumbnailImg">
    </div>
  </div>
</div>
<!--_html_template_end_-->`;
  }

  constructor() {
    super();

    this.alertIndicatorsEl_ = /** @type {!AlertIndicatorsElement} */
        (this.$('tabstrip-alert-indicators'));
    // Normally, custom elements will get upgraded automatically once added to
    // the DOM, but TabElement may need to update properties on
    // AlertIndicatorElement before this happens, so upgrade it manually.
    customElements.upgrade(this.alertIndicatorsEl_);

    /** @private {!HTMLElement} */
    this.closeButtonEl_ = /** @type {!HTMLElement} */ (this.$('#close'));
    this.closeButtonEl_.setAttribute(
        'aria-label', loadTimeData.getString('closeTab'));

    /** @private {!HTMLElement} */
    this.dragImageEl_ = /** @type {!HTMLElement} */ (this.$('#dragImage'));

    /** @private {!HTMLElement} */
    this.tabEl_ = /** @type {!HTMLElement} */ (this.$('#tab'));

    /** @private {!HTMLElement} */
    this.faviconEl_ = /** @type {!HTMLElement} */ (this.$('#favicon'));

    /** @private {!HTMLElement} */
    this.thumbnailContainer_ =
        /** @type {!HTMLElement} */ (this.$('#thumbnail'));

    /** @private {!Image} */
    this.thumbnail_ = /** @type {!Image} */ (this.$('#thumbnailImg'));

    /** @private {!TabData} */
    this.tab_;

    /** @private {!TabsApiProxy} */
    this.tabsApi_ = TabsApiProxyImpl.getInstance();

    /** @private {!TabStripEmbedderProxy} */
    this.embedderApi_ = TabStripEmbedderProxyImpl.getInstance();

    /** @private {!HTMLElement} */
    this.titleTextEl_ = /** @type {!HTMLElement} */ (this.$('#titleText'));

    /**
     * Flag indicating if this TabElement can accept dragover events. This
     * is used to pause dragover events while animating as animating causes
     * the elements below the pointer to shift.
     * @private {boolean}
     */
    this.isValidDragOverTarget_ = true;

    this.tabEl_.addEventListener('click', () => this.onClick_());
    this.tabEl_.addEventListener('contextmenu', e => this.onContextMenu_(e));
    this.tabEl_.addEventListener(
        'keydown', e => this.onKeyDown_(/** @type {!KeyboardEvent} */ (e)));
    this.closeButtonEl_.addEventListener('click', e => this.onClose_(e));
    this.addEventListener('swipe', () => this.onSwipe_());

    /** @private @const {!TabSwiper} */
    this.tabSwiper_ = new TabSwiper(this);

    /** @private {!Function} */
    this.onTabActivating_ = (tabId) => {};
  }

  /** @return {!TabData} */
  get tab() {
    return this.tab_;
  }

  /** @param {!TabData} tab */
  set tab(tab) {
    assert(this.tab_ !== tab);
    this.toggleAttribute('active', tab.active);
    this.tabEl_.setAttribute('aria-selected', tab.active.toString());
    this.toggleAttribute('hide-icon_', !tab.showIcon);
    this.toggleAttribute(
        'waiting_',
        !tab.shouldHideThrobber &&
            tab.networkState === TabNetworkState.WAITING);
    this.toggleAttribute(
        'loading_',
        !tab.shouldHideThrobber &&
            tab.networkState === TabNetworkState.LOADING);
    this.toggleAttribute('pinned', tab.pinned);
    this.toggleAttribute('blocked_', tab.blocked);
    this.setAttribute('draggable', true);
    this.toggleAttribute('crashed_', tab.crashed);

    if (tab.title) {
      this.titleTextEl_.textContent = tab.title;
    } else if (
        !tab.shouldHideThrobber &&
        (tab.networkState === TabNetworkState.WAITING ||
         tab.networkState === TabNetworkState.LOADING)) {
      this.titleTextEl_.textContent = loadTimeData.getString('loadingTab');
    } else {
      this.titleTextEl_.textContent = loadTimeData.getString('defaultTabTitle');
    }
    this.titleTextEl_.setAttribute('aria-label', getAccessibleTitle(tab));

    if (tab.networkState === TabNetworkState.WAITING ||
        (tab.networkState === TabNetworkState.LOADING &&
         tab.isDefaultFavicon)) {
      this.faviconEl_.style.backgroundImage = 'none';
    } else if (tab.favIconUrl) {
      this.faviconEl_.style.backgroundImage = `url(${tab.favIconUrl})`;
    } else {
      this.faviconEl_.style.backgroundImage = getFavicon('');
    }

    // Expose the ID to an attribute to allow easy querySelector use
    this.setAttribute('data-tab-id', tab.id);

    this.alertIndicatorsEl_.updateAlertStates(tab.alertStates)
        .then((alertIndicatorsCount) => {
          this.toggleAttribute('has-alert-states_', alertIndicatorsCount > 0);
        });

    if (!this.tab_ || (this.tab_.pinned !== tab.pinned && !tab.pinned)) {
      this.tabSwiper_.startObserving();
    } else if (this.tab_.pinned !== tab.pinned && tab.pinned) {
      this.tabSwiper_.stopObserving();
    }

    this.tab_ = Object.freeze(tab);
  }

  /** @return {boolean} */
  get isValidDragOverTarget() {
    return !this.hasAttribute('dragging_') && this.isValidDragOverTarget_;
  }

  /** @param {boolean} isValid */
  set isValidDragOverTarget(isValid) {
    this.isValidDragOverTarget_ = isValid;
  }

  /** @param {!Function} callback */
  set onTabActivating(callback) {
    this.onTabActivating_ = callback;
  }

  focus() {
    this.tabEl_.focus();
  }

  /** @return {!HTMLElement} */
  getDragImage() {
    return this.dragImageEl_;
  }

  /**
   * @param {string} imgData
   */
  updateThumbnail(imgData) {
    this.thumbnail_.src = imgData;
  }

  /** @private */
  onClick_() {
    if (!this.tab_ || this.tabSwiper_.wasSwiping()) {
      return;
    }

    const tabId = this.tab_.id;
    this.onTabActivating_(tabId);
    this.tabsApi_.activateTab(tabId);

    if (tabStripOptions.autoCloseEnabled) {
      this.embedderApi_.closeContainer();
    }
  }

  /**
   * @param {!Event} event
   * @private
   */
  onContextMenu_(event) {
    event.preventDefault();

    if (!this.tab_) {
      return;
    }

    this.embedderApi_.showTabContextMenu(
        this.tab_.id, event.clientX, event.clientY);
    event.stopPropagation();
  }

  /**
   * @param {!Event} event
   * @private
   */
  onClose_(event) {
    assert(this.tab_);
    event.stopPropagation();
    this.tabsApi_.closeTab(this.tab_.id, CloseTabAction.CLOSE_BUTTON);
  }

  /** @private */
  onSwipe_() {
    assert(this.tab_);
    this.tabsApi_.closeTab(this.tab_.id, CloseTabAction.SWIPED_TO_CLOSE);
  }

  /**
   * @param {!KeyboardEvent} event
   * @private
   */
  onKeyDown_(event) {
    if (event.key === 'Enter' || event.key === ' ') {
      this.onClick_();
    }
  }

  resetSwipe() {
    this.tabSwiper_.reset();
  }

  /**
   * @param {boolean} isDragging
   */
  setDragging(isDragging) {
    this.toggleAttribute('dragging_', isDragging);
  }

  /**
   * @return {!Promise}
   */
  slideIn() {
    const paddingInlineEnd = getPaddingInlineEndProperty();

    // If this TabElement is the last tab, there needs to be enough space for
    // the view to scroll to it. Therefore, immediately take up all the space
    // it needs to and only animate the scale.
    const isLastChild = this.nextElementSibling === null;

    const startState = {
      maxWidth: isLastChild ? 'var(--tabstrip-tab-width)' : 0,
      transform: `scale(0)`,
    };
    startState[paddingInlineEnd] =
        isLastChild ? 'var(--tabstrip-tab-spacing)' : 0;

    const finishState = {
      maxWidth: `var(--tabstrip-tab-width)`,
      transform: `scale(1)`,
    };
    finishState[paddingInlineEnd] = 'var(--tabstrip-tab-spacing)';

    return new Promise(resolve => {
      const animation = this.animate([startState, finishState], {
        duration: 300,
        easing: 'cubic-bezier(.4, 0, 0, 1)',
      });
      animation.onfinish = () => {
        resolve();
      };

      // TODO(crbug.com/1035678) By the next animation frame, the animation
      // should start playing. By the time another animation frame happens,
      // force play the animation if the animation has not yet begun. Remove
      // if/when the Blink issue has been fixed.
      requestAnimationFrame(() => {
        requestAnimationFrame(() => {
          if (animation.pending) {
            animation.play();
          }
        });
      });
    });
  }

  /**
   * @return {!Promise}
   */
  slideOut() {
    if (!this.embedderApi_.isVisible() || this.tab_.pinned ||
        this.tabSwiper_.wasSwiping()) {
      this.remove();
      return Promise.resolve();
    }

    return new Promise(resolve => {
      const finishCallback = () => {
        this.remove();
        resolve();
      };

      const translateAnimation = this.animate(
          {
            transform: ['translateY(0)', 'translateY(-100%)'],
          },
          {
            duration: 150,
            easing: 'cubic-bezier(.4, 0, 1, 1)',
            fill: 'forwards',
          });
      const opacityAnimation = this.animate(
          {
            opacity: [1, 0],
          },
          {
            delay: 97.5,
            duration: 50,
            fill: 'forwards',
          });

      const widthAnimationKeyframes = {
        maxWidth: ['var(--tabstrip-tab-width)', 0],
      };
      widthAnimationKeyframes[getPaddingInlineEndProperty()] =
          ['var(--tabstrip-tab-spacing)', 0];
      const widthAnimation = this.animate(widthAnimationKeyframes, {
        delay: 97.5,
        duration: 300,
        easing: 'cubic-bezier(.4, 0, 0, 1)',
        fill: 'forwards',
      });

      const visibilityChangeListener = () => {
        if (!this.embedderApi_.isVisible()) {
          // If a tab strip becomes hidden during the animation, the onfinish
          // event will not get fired until the tab strip becomes visible again.
          // Therefore, when the tab strip becomes hidden, immediately call the
          // finish callback.
          translateAnimation.cancel();
          opacityAnimation.cancel();
          widthAnimation.cancel();
          finishCallback();
        }
      };

      document.addEventListener(
          'visibilitychange', visibilityChangeListener, {once: true});
      // The onfinish handler is put on the width animation, as it will end
      // last.
      widthAnimation.onfinish = () => {
        document.removeEventListener(
            'visibilitychange', visibilityChangeListener);
        finishCallback();
      };
    });
  }
}

customElements.define('tabstrip-tab', TabElement);

/**
 * @param {!Element} element
 * @return {boolean}
 */
export function isTabElement(element) {
  return element.tagName === 'TABSTRIP-TAB';
}
