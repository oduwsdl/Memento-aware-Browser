// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-collapse/iron-collapse.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import './code_section.js';
import './shared_style.js';

import {CrContainerShadowBehavior} from 'chrome://resources/cr_elements/cr_container_shadow_behavior.m.js';
import {assert, assertNotReached} from 'chrome://resources/js/assert.m.js';
import {FocusOutlineManager} from 'chrome://resources/js/cr/ui/focus_outline_manager.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {afterNextRender, html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {navigation, Page} from './navigation_helper.js';

/** @typedef {chrome.developerPrivate.ManifestError} */
let ManifestError;
/** @typedef {chrome.developerPrivate.RuntimeError} */
let RuntimeError;

/** @interface */
export class ErrorPageDelegate {
  /**
   * @param {string} extensionId
   * @param {!Array<number>=} errorIds
   * @param {chrome.developerPrivate.ErrorType=} type
   */
  deleteErrors(extensionId, errorIds, type) {}

  /**
   * @param {chrome.developerPrivate.RequestFileSourceProperties} args
   * @return {!Promise<!chrome.developerPrivate.RequestFileSourceResponse>}
   */
  requestFileSource(args) {}
}

/**
 * Get the URL relative to the main extension url. If the url is
 * unassociated with the extension, this will be the full url.
 * @param {string} url
 * @param {?(ManifestError|RuntimeError)} error
 * @return {string}
 */
function getRelativeUrl(url, error) {
  const fullUrl = 'chrome-extension://' + error.extensionId + '/';
  return url.startsWith(fullUrl) ? url.substring(fullUrl.length) : url;
}

/**
 * Given 3 strings, this function returns the correct one for the type of
 * error that |item| is.
 * @param {!ManifestError|!RuntimeError} item
 * @param {string} log
 * @param {string} warn
 * @param {string} error
 * @return {string}
 * @private
 */
function getErrorSeverityText_(item, log, warn, error) {
  if (item.type === chrome.developerPrivate.ErrorType.RUNTIME) {
    switch (item.severity) {
      case chrome.developerPrivate.ErrorLevel.LOG:
        return log;
      case chrome.developerPrivate.ErrorLevel.WARN:
        return warn;
      case chrome.developerPrivate.ErrorLevel.ERROR:
        return error;
    }
    assertNotReached();
  }
  assert(item.type === chrome.developerPrivate.ErrorType.MANIFEST);
  return warn;
}

Polymer({
  is: 'extensions-error-page',

  _template: html`<!--_html_template_start_-->
<style include="cr-icons cr-shared-style shared-style">
  :host {
    display: block;
    height: 100%;
  }

  iron-icon {
    --iron-icon-fill-color: var(--google-grey-refresh-700);
    flex-shrink: 0;
    height: var(--cr-icon-size);
    width: var(--cr-icon-size);
  }

  iron-icon[icon='cr:warning'] {
    /* TODO(dbeam): find dark mode equivalent for this orange. */
    --iron-icon-fill-color: var(--paper-orange-500);
  }

  iron-icon[icon='cr:error'] {
    --iron-icon-fill-color: var(--error-color);
  }

  .section {
    padding: 0 var(--cr-section-padding);
  }

  #heading {
    align-items: center;
    display: flex;
    height: 40px;
    margin-bottom: 30px;
    padding: 8px 12px 0;
  }

  #heading span {
    flex: 1;
    margin: 0 10px;
  }

  #errorsList {
    min-height: 100px;
  }

  .error-item {
    padding-inline-start: 0;
  }

  .error-item cr-icon-button {
    margin: 0;
  }

  .error-item.selected {
    background-color: rgba(0, 0, 0, 0.08);
  }

  .error-item .start {
    align-items: center;
    align-self: stretch;  /* Makes the tappable area fill its parent. */
    display: flex;
    flex: 1;
    padding: 0 var(--cr-section-padding);
  }

  .error-message {
    flex-grow: 1;
    margin-inline-start: 10px;
    word-break: break-word;
  }

  .devtools-controls {
    padding: 0 var(--cr-section-padding);
  }

  .details-heading {
    align-items: center;
    display: flex;
    height: var(--cr-section-min-height);
  }

  .stack-trace-container {
    list-style: none;
    margin-top: 0;
    padding: 0;
  }

  .stack-trace-container li {
    cursor: pointer;
    font-family: monospace;
    padding: 4px;
  }

  .stack-trace-container li.selected,
  .stack-trace-container li:hover {
    background: var(--google-blue-100);
    color: var(--google-grey-900);  /* Same in light & dark modes. */
  }

  extensions-code-section {
    height: 200px;
    margin-bottom: 20px;
  }

  :host-context(.focus-outline-visible) .start:focus {
    outline: -webkit-focus-ring-color auto 5px;
  }

  .start:focus {
    outline: none;
  }

  .context-url {
    word-wrap: break-word;
  }
</style>
<div class="page-container" id="container">
  <div class="page-content">
    <div id="heading" class="cr-title-text">
      <cr-icon-button class="icon-arrow-back no-overlap" id="closeButton"
          aria-label="$i18n{back}" on-click="onCloseButtonTap_">
      </cr-icon-button>
      <span role="heading" aria-level="2">$i18n{errorsPageHeading}</span>
      <cr-button on-click="onClearAllTap_" hidden="[[!entries_.length]]">
        $i18n{clearAll}
      </cr-button>
    </div>
    <div class="section">
      <div id="errorsList">
        <template is="dom-repeat" items="[[entries_]]">
          <div class="item-container">
            <div class$="cr-row error-item
                [[computeErrorClass_(item, selectedEntry_)]]">
              <div actionable class="start" on-click="onErrorItemAction_"
                  on-keydown="onErrorItemAction_" tabindex="0"
                  role="button" aria-expanded$="[[isAriaExpanded_(
                      index, selectedEntry_)]]">
                <iron-icon icon$="cr:[[computeErrorIcon_(item)]]"
                    title$="[[computeErrorTypeLabel_(item)]]">
                </iron-icon>
                <div id$="[[item.id]]" class="error-message">
                  [[item.message]]
                </div>
                <div class$="cr-icon [[iconName_(index, selectedEntry_)]]">
                </div>
              </div>
              <div class="separator"></div>
              <cr-icon-button class="icon-delete-gray"
                  on-click="onDeleteErrorAction_"
                  aria-describedby$="[[item.id]]"
                  aria-label="$i18n{clearEntry}"></cr-icon-button>
            </div>
            <iron-collapse opened="[[isOpened_(index, selectedEntry_)]]">
              <div class="devtools-controls">
                <template is="dom-if"
                    if="[[computeIsRuntimeError_(item)]]">
                  <div class="details-heading cr-title-text" role="heading"
                      aria-level="3">
                    $i18n{errorContext}
                  </div>
                  <span class="context-url">
                    [[getContextUrl_(
                        item, '$i18nPolymer{errorContextUnknown}')]]
                  </span>
                  <div class="details-heading cr-title-text" role="heading"
                      aria-level="3">
                    $i18n{stackTrace}
                  </div>
                  <ul class="stack-trace-container"
                      on-keydown="onStackKeydown_">
                    <template is="dom-repeat" items="[[item.stackTrace]]">
                      <li on-click="onStackFrameTap_"
                          tabindex$="[[getStackFrameTabIndex_(item,
                              selectedStackFrame_)]]"
                          hidden="[[!shouldDisplayFrame_(item.url)]]"
                          class$="[[getStackFrameClass_(item,
                              selectedStackFrame_)]]">
                        [[getStackTraceLabel_(item)]]
                      </li>
                    </template>
                  </ul>
                </template>
                <extensions-code-section code="[[code_]]"
                    is-active="[[isOpened_(index, selectedEntry_)]]"
                    could-not-display-code="$i18n{noErrorsToShow}">
                </extensions-code-section>
              </div>
            </iron-collapse>
          </div>
        </template>
      </div>
    </div>
  </div>
</div>
<!--_html_template_end_-->`,

  behaviors: [CrContainerShadowBehavior],

  properties: {
    /** @type {!chrome.developerPrivate.ExtensionInfo|undefined} */
    data: Object,

    /** @type {!ErrorPageDelegate|undefined} */
    delegate: Object,

    // Whether or not dev mode is enabled.
    inDevMode: {
      type: Boolean,
      value: false,
      observer: 'onInDevModeChanged_',
    },

    /** @private {!Array<!(ManifestError|RuntimeError)>} */
    entries_: Array,

    /** @private {?chrome.developerPrivate.RequestFileSourceResponse} */
    code_: Object,

    /**
     * Index into |entries_|.
     * @private
     */
    selectedEntry_: {
      type: Number,
      observer: 'onSelectedErrorChanged_',
    },

    /** @private {?chrome.developerPrivate.StackFrame}*/
    selectedStackFrame_: {
      type: Object,
      value() {
        return null;
      },
    },
  },

  observers: [
    'observeDataChanges_(data.*)',
  ],

  listeners: {
    'view-enter-start': 'onViewEnterStart_',
  },

  /** @override */
  ready() {
    FocusOutlineManager.forDocument(document);
  },

  /** @return {!ManifestError|!RuntimeError} */
  getSelectedError() {
    return this.entries_[this.selectedEntry_];
  },

  /**
   * Focuses the back button when page is loaded.
   * @private
   */
  onViewEnterStart_() {
    afterNextRender(this, () => focusWithoutInk(this.$.closeButton));
    chrome.metricsPrivate.recordUserAction('Options_ViewExtensionErrors');
  },

  /**
   * @param {!ManifestError|!RuntimeError} error
   * @param {string} unknown
   * @return {string}
   * @private
   */
  getContextUrl_(error, unknown) {
    return error.contextUrl ? getRelativeUrl(error.contextUrl, error) : unknown;
  },

  /**
   * Watches for changes to |data| in order to fetch the corresponding
   * file source.
   * @private
   */
  observeDataChanges_() {
    const errors = this.data.manifestErrors.concat(this.data.runtimeErrors);
    this.entries_ = errors;
    this.selectedEntry_ = -1;  // This also help reset code-section content.
    if (this.entries_.length) {
      this.selectedEntry_ = 0;
    }
  },

  /** @private */
  onCloseButtonTap_() {
    navigation.navigateTo({page: Page.LIST});
  },

  /** @private */
  onClearAllTap_() {
    const ids = this.entries_.map(entry => entry.id);
    this.delegate.deleteErrors(this.data.id, ids);
  },

  /**
   * @param {!ManifestError|!RuntimeError} error
   * @return {string}
   * @private
   */
  computeErrorIcon_(error) {
    // Do not i18n these strings, they're CSS classes.
    return getErrorSeverityText_(error, 'info', 'warning', 'error');
  },

  /**
   * @param {!ManifestError|!RuntimeError} error
   * @return {string}
   * @private
   */
  computeErrorTypeLabel_(error) {
    return getErrorSeverityText_(
        error, loadTimeData.getString('logLevel'),
        loadTimeData.getString('warnLevel'),
        loadTimeData.getString('errorLevel'));
  },

  /**
   * @param {!Event} e
   * @private
   */
  onDeleteErrorAction_(e) {
    this.delegate.deleteErrors(
        this.data.id, [(/** @type {!{model:Object}} */ (e)).model.item.id]);
    e.stopPropagation();
  },

  /** private */
  onInDevModeChanged_() {
    if (!this.inDevMode) {
      // Wait until next render cycle in case error page is loading.
      this.async(() => {
        this.onCloseButtonTap_();
      });
    }
  },

  /**
   * Fetches the source for the selected error and populates the code section.
   * @private
   */
  onSelectedErrorChanged_() {
    this.code_ = null;

    if (this.selectedEntry_ < 0) {
      return;
    }

    const error = this.getSelectedError();
    const args = {
      extensionId: error.extensionId,
      message: error.message,
    };
    switch (error.type) {
      case chrome.developerPrivate.ErrorType.MANIFEST:
        args.pathSuffix = error.source;
        args.manifestKey = error.manifestKey;
        args.manifestSpecific = error.manifestSpecific;
        break;
      case chrome.developerPrivate.ErrorType.RUNTIME:
        // slice(1) because pathname starts with a /.
        args.pathSuffix = new URL(error.source).pathname.slice(1);
        args.lineNumber = error.stackTrace && error.stackTrace[0] ?
            error.stackTrace[0].lineNumber :
            0;
        this.selectedStackFrame_ = error.stackTrace && error.stackTrace[0] ?
            error.stackTrace[0] :
            null;
        break;
    }
    this.delegate.requestFileSource(args).then(code => this.code_ = code);
  },

  /**
   * @return {boolean}
   * @private
   */
  computeIsRuntimeError_(item) {
    return item.type === chrome.developerPrivate.ErrorType.RUNTIME;
  },

  /**
   * The description is a human-readable summation of the frame, in the
   * form "<relative_url>:<line_number> (function)", e.g.
   * "myfile.js:25 (myFunction)".
   * @param {!chrome.developerPrivate.StackFrame} frame
   * @return {string}
   * @private
   */
  getStackTraceLabel_(frame) {
    let description = getRelativeUrl(frame.url, this.getSelectedError()) + ':' +
        frame.lineNumber;

    if (frame.functionName) {
      const functionName = frame.functionName === '(anonymous function)' ?
          loadTimeData.getString('anonymousFunction') :
          frame.functionName;
      description += ' (' + functionName + ')';
    }

    return description;
  },

  /**
   * @param {chrome.developerPrivate.StackFrame} frame
   * @return {string}
   * @private
   */
  getStackFrameClass_(frame) {
    return frame === this.selectedStackFrame_ ? 'selected' : '';
  },

  /**
   * @param {!chrome.developerPrivate.StackFrame} frame
   * @return {number}
   * @private
   */
  getStackFrameTabIndex_(frame) {
    return frame === this.selectedStackFrame_ ? 0 : -1;
  },

  /**
   * This function is used to determine whether or not we want to show a
   * stack frame. We don't want to show code from internal scripts.
   * @param {string} url
   * @return {boolean}
   * @private
   */
  shouldDisplayFrame_(url) {
    // All our internal scripts are in the 'extensions::' namespace.
    return !/^extensions::/.test(url);
  },

  /**
   * @param {!chrome.developerPrivate.StackFrame} frame
   * @private
   */
  updateSelected_(frame) {
    this.selectedStackFrame_ = assert(frame);

    const selectedError = this.getSelectedError();
    this.delegate
        .requestFileSource({
          extensionId: selectedError.extensionId,
          message: selectedError.message,
          pathSuffix: getRelativeUrl(frame.url, selectedError),
          lineNumber: frame.lineNumber,
        })
        .then(code => this.code_ = code);
  },

  /**
   * @param {!Event} e
   * @private
   */
  onStackFrameTap_(e) {
    const frame = /** @type {!{model:Object}} */ (e).model.item;
    this.updateSelected_(frame);
  },

  /**
   * @param {!Event} e
   * @private
   */
  onStackKeydown_(e) {
    let direction = 0;

    if (e.key === 'ArrowDown') {
      direction = 1;
    } else if (e.key === 'ArrowUp') {
      direction = -1;
    } else {
      return;
    }

    e.preventDefault();

    const list = e.target.parentElement.querySelectorAll('li');

    for (let i = 0; i < list.length; ++i) {
      if (list[i].classList.contains('selected')) {
        const polymerEvent = /** @type {!{model: !Object}} */ (e);
        const frame = polymerEvent.model.item.stackTrace[i + direction];
        if (frame) {
          this.updateSelected_(frame);
          list[i + direction].focus();  // Preserve focus.
        }
        return;
      }
    }
  },

  /**
   * Computes the class name for the error item depending on whether its
   * the currently selected error.
   * @param {number} index
   * @return {string}
   * @private
   */
  computeErrorClass_(index) {
    return index === this.selectedEntry_ ? 'selected' : '';
  },

  /** @private */
  iconName_(index) {
    return index === this.selectedEntry_ ? 'icon-expand-less' :
                                           'icon-expand-more';
  },

  /**
   * Determine if the iron-collapse should be opened (expanded).
   * @param {number} index
   * @return {boolean}
   * @private
   */
  isOpened_(index) {
    return index === this.selectedEntry_;
  },


  /**
   * @param {number} index
   * @return {string} The aria-expanded value as a string.
   * @private
   */
  isAriaExpanded_(index) {
    return this.isOpened_(index).toString();
  },

  /**
   * @param {!{type: string, code: string, model: !{index: number}}} e
   * @private
   */
  onErrorItemAction_(e) {
    if (e.type === 'keydown' && !((e.code === 'Space' || e.code === 'Enter'))) {
      return;
    }

    // Call preventDefault() to avoid the browser scrolling when the space key
    // is pressed.
    e.preventDefault();
    this.selectedEntry_ =
        this.selectedEntry_ === e.model.index ? -1 : e.model.index;
  },
});
