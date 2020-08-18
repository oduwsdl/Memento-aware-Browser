// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import './icons.js';
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/js/action_link.js';
import 'chrome://resources/cr_elements/action_link_css.m.js';
import './strings.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import 'chrome://resources/polymer/v3_0/paper-progress/paper-progress.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';

import {getToastManager} from 'chrome://resources/cr_elements/cr_toast/cr_toast_manager.m.js';
import {assert} from 'chrome://resources/js/assert.m.js';
import {FocusRowBehavior} from 'chrome://resources/js/cr/ui/focus_row_behavior.m.js';
import {focusWithoutInk} from 'chrome://resources/js/cr/ui/focus_without_ink.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {HTMLEscape} from 'chrome://resources/js/util.m.js';
import {IronA11yAnnouncer} from 'chrome://resources/polymer/v3_0/iron-a11y-announcer/iron-a11y-announcer.js';
import {afterNextRender, beforeNextRender, html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {BrowserProxy} from './browser_proxy.js';
import {DangerType, States} from './constants.js';
import {IconLoader} from './icon_loader.js';

Polymer({
    is: 'downloads-item',

    _template: html`<!--_html_template_start_-->
<style include="action-link cr-hidden-style cr-icons">
  :host {
    --controlled-by-active-color: #333;
    --controlled-by-active-link-color: var(--google-blue-600);
    --controlled-by-inactive-color: #5a5a5a;
    display: flex;
    flex-direction: column;
    outline: none;
  }

  @media (prefers-color-scheme: dark) {
    :host {
      --controlled-by-active-color: inherit;
      --controlled-by-active-link-color: var(--cr-link-color);
      --controlled-by-inactive-color: inherit;
    }
  }

  cr-button {
    font-weight: 500;
    margin: 0;
    min-width: auto;
  }

  #date {
    font-size: 0.875rem;
    font-weight: 400;
    letter-spacing: .25px;
    margin: 21px auto 6px;
    padding-bottom: 4px;
    padding-top: 8px;
    width: var(--downloads-card-width);
  }

  #date:empty {
    display: none;
  }

  #content {
    border-radius: var(--cr-card-border-radius);
    display: flex;
    flex: none;
    margin: 6px auto;
    min-height: 103px;
    position: relative;
    width: var(--downloads-card-width);
  }

  #content.is-active {
    box-shadow: var(--cr-card-shadow);
  }

  @media (prefers-color-scheme: light) {
    #content.is-active {
      background-color: var(--cr-card-background-color);
    }
  }

  #content:not(.is-active) {
    background: rgba(255, 255, 255, .6);
    border: 1px var(--google-grey-300) solid;
  }

  @media (prefers-color-scheme: dark) {
    #content:not(.is-active) {
      background: none;  /* override */
      border-color: var(--google-grey-800);
    }
  }

  #details {
    border-inline-start: 1px #d8d8d8 solid;
    display: flex;
    flex: 1;
    flex-direction: column;
    min-width: 0;  /* This allows #url to ellide correctly. */
    padding-bottom: 12px;
    padding-inline-end: 16px;
    padding-inline-start: var(--downloads-card-margin);
    padding-top: 16px;
  }

  @media (prefers-color-scheme: dark) {
    #details {
      border-color: rgba(var(--google-grey-800-rgb), .8);
    }
  }

  #content:not(.is-active) #details {
    color: rgba(27, 27, 27, .6);
  }

  @media (prefers-color-scheme: dark) {
    #content:not(.is-active) #details {
      color: rgba(var(--google-grey-refresh-500-rgb), .6);
    }
  }

  #content:not(.is-active) #name {
    text-decoration: line-through;
  }

  @media (prefers-color-scheme: dark) {
    #content:not(.is-active) :-webkit-any(#name, #tag) {
      color: var(--google-grey-refresh-500);
    }
  }

  .icon-wrapper {
    align-self: center;
    flex: none;
    justify-content: center;
    margin: 0 24px;
  }

  .icon,
  #file-icon-wrapper {
    height: 32px;
    width: 32px;
  }

  #file-icon-wrapper {
    overflow: hidden;  /* Reduces file icon flicker on initial load. */
  }

  #content:-webkit-any(.show-progress, .dangerous) #file-icon-wrapper {
    /* TODO(dbeam): animate from top-aligned to centered when items finish?
     */
    align-self: flex-start;
    padding-top: 16px;
  }

  #content:not(.is-active) .icon {
    -webkit-filter: grayscale(100%);
    opacity: .5;
  }

  #file-icon-wrapper iron-icon[icon-color='paper-grey'] {
    color: var(--paper-grey-400);
  }

  #file-icon-wrapper iron-icon[icon-color='red'] {
    color: var(--google-red-700);
  }

  #file-icon-wrapper iron-icon[icon-color='yellow'] {
    color: var(--google-yellow-500);
  }

  @media (prefers-color-scheme: dark) {
    #file-icon-wrapper iron-icon[icon-color='red'] {
      color: var(--google-red-refresh-300);
    }
  }

  #file-icon-wrapper iron-icon[icon-color='grey'] {
    color: var(--google-grey-700);
  }

  @media (prefers-color-scheme: dark) {
    #file-icon-wrapper iron-icon[icon-color='grey'] {
      color: var(--google-grey-500);
    }
  }

  #name,
  #file-link,
  #url {
    max-width: 100%;
  }

  div[role='gridcell'] {
    display: inline;
  }

  #name,
  #file-link {
    font-weight: 500;
    word-break: break-all;
  }

  @media (prefers-color-scheme: light) {
    .is-active :-webkit-any(#name, #file-link, #show) {
      color: var(--google-blue-600);
    }
  }

  #name {
    margin-inline-end: 12px;  /* Only really affects #tag. */
  }

  #tag {
    color: #5a5a5a;
    font-weight: 500;
  }

  #url {
    color: inherit;
    display: block;
    margin-top: 6px;
    min-height: 0;
    overflow: hidden;
    text-decoration: none;
    text-overflow: ellipsis;
    white-space: nowrap;
  }

  .is-active #url {
    color: var(--cr-secondary-text-color);
  }

  #progress,
  #description:not(:empty),
  .controls {
    margin-top: 16px;
  }

  @media (prefers-color-scheme: light) {
    .is-active #description {
      color: #616161;
    }
  }

  #progress {
    /* TODO(dbeam): border-radius on container and progress bar. */
    --paper-progress-active-color: var(--google-blue-600);
    --paper-progress-container-color: rgb(223, 222, 223);
    width: auto;
  }

  @media (prefers-color-scheme: dark) {
    #progress {
      --paper-progress-active-color: var(--google-blue-refresh-300);
      --paper-progress-container-color: var(--google-grey-800);
    }
  }

  #show {
    margin: .7em 0;
  }

  #controlled-by,
  #controlled-by a {
    color: var(--controlled-by-inactive-color);
  }

  .is-active #controlled-by {
    color: var(--controlled-by-active-color);
    margin-inline-start: 8px;
  }

  .is-active #controlled-by a {
    color: var(--controlled-by-active-link-color);
  }


  cr-icon-button {
    --cr-icon-button-icon-size: 16px;
    --cr-icon-button-margin-end: 8px;
    margin-top: 8px;
  }

  #incognito {
    -webkit-mask-image: url(images/incognito_marker.svg);
    background-color: var(--cr-secondary-text-color);
    bottom: 20px;
    height: 16px;
    position: absolute;
    right: 16px;
    width: 16px;
  }

  :host-context([dir='rtl']) #incognito {
    left: 16px;
    right: initial;
  }

  #pauseOrResume,
  #dangerous .action-button,
  #openNow {
    margin-inline-end: 8px;
  }
</style>

<div id="date" role="heading" aria-level="2">[[computeDate_(data.hideDate,
    data.sinceString,
    data.dateString)]]</div>

<div id="content" on-dragstart="onDragStart_"
    class$="[[computeClass_(isActive_, isDangerous_, showProgress_)]]"
    focus-row-container>
  <!--
    TODO(hcarmona): Investigate displaying danger level as text in alt
    attribute and remove aria-hidden="true" from #file-icon-wrapper
  -->
  <div id="file-icon-wrapper" class="icon-wrapper" aria-hidden="true">
    <img class="icon" id="file-icon" alt="" hidden="[[!useFileIcon_]]"
    icon-color$="[[computeIconColor_(isDangerous_, data.dangerType,
    useFileIcon_)]]">
    <iron-icon class="icon" icon$="[[computeIcon_(
        isDangerous_, data.dangerType, useFileIcon_)]]"
        hidden="[[useFileIcon_]]" icon-color$="[[computeIconColor_(isDangerous_,
        data.dangerType, useFileIcon_)]]"></iron-icon>
  </div>

  <div id="details">
    <div id="title-area" role="gridcell"><!--
      Can't have any line breaks.
      --><a is="action-link" id="file-link" href="[[data.url]]"
          on-click="onFileLinkTap_" focus-row-control
          focus-type="fileLink"
          hidden="[[!completelyOnDisk_]]">[[data.fileName]]</a><!--
      Before #name.
      --><span id="name"
          hidden="[[completelyOnDisk_]]">[[data.fileName]]</span>
      <span id="tag">[[computeTag_(data.state,
                                   data.lastReasonText,
                                   data.fileExternallyRemoved)]]</span>
    </div>

    <div role="gridcell">
      <a id="url" target="_blank" on-click="onUrlTap_" focus-row-control
          focus-type="url">[[chopUrl_(data.url)]]</a>
    </div>

    <div id="description" role="gridcell"
        hidden$="[[!computeDescriptionVisible_(data.*)]]">
      [[computeDescription_(
          data.state,
          data.dangerType,
          data.fileName,
          data.progressStatusText)]]
    </div>

    <template is="dom-if" if="[[showProgress_]]">
      <div role="gridcell">
        <paper-progress id="progress"
            indeterminate="[[isIndeterminate_(data.percent)]]"
            value="[[data.percent]]"></paper-progress>
      </div>
    </template>

    <div id="safe" class="controls" hidden="[[isDangerous_]]">
      <div role="gridcell">
        <a is="action-link" id="show" on-click="onShowTap_"
            hidden="[[!completelyOnDisk_]]" focus-row-control
            focus-type="show">$i18n{controlShowInFolder}</a>
      </div>
      <template is="dom-if" if="[[data.retry]]">
        <div role="gridcell">
          <cr-button class="action-button" on-click="onRetryTap_"
              focus-row-control focus-type="retry">
            $i18n{controlRetry}
          </cr-button>
        </div>
      </template>
      <template is="dom-if" if="[[pauseOrResumeText_]]">
        <div role="gridcell">
          <cr-button on-click="onPauseOrResumeTap_" id="pauseOrResume"
              focus-row-control focus-type="pauseOrResume">
            [[pauseOrResumeText_]]
          </cr-button>
        </div>
      </template>
      <template is="dom-if" if="[[showOpenNow_]]">
        <div role="gridcell">
          <cr-button on-click="onOpenNowTap_" id="openNow" class="action-button"
                     focus-row-control focus-type="open">
            $i18n{controlOpenNow}
          </cr-button>
        </div>
      </template>
      <template is="dom-if" if="[[showCancel_]]">
        <div role="gridcell">
          <cr-button on-click="onCancelTap_" focus-row-control
              focus-type="cancel">
            $i18n{controlCancel}
          </cr-button>
        </div>
      </template>
      <span id="controlled-by"><!-- Text populated dynamically. --></span>
    </div>

    <template is="dom-if" if="[[isDangerous_]]">
      <div id="dangerous" class="controls">
        <!-- Dangerous file types (e.g. .exe, .jar). -->
        <template is="dom-if" if="[[!isMalware_]]">
          <div role="gridcell">
            <cr-button on-click="onDiscardDangerousTap_"
                class="action-button" focus-row-control
                focus-type="discard">$i18n{dangerDiscard}</cr-button>
          </div>
          <div role="gridcell">
            <cr-button on-click="onSaveDangerousTap_" focus-row-control
                focus-type="save">
              $i18n{dangerSave}</cr-button>
          </div>
        </template>

        <!-- Things that safe browsing has determined to be dangerous. -->
        <template is="dom-if" if="[[isMalware_]]">
          <div role="gridcell">
            <cr-button on-click="onDiscardDangerousTap_"
                class="action-button"
                focus-row-control focus-type="discard">
              $i18n{controlRemoveFromList}</cr-button>
          </div>
          <div role="gridcell">
            <cr-button on-click="onSaveDangerousTap_" focus-row-control
                focus-type="save">
              $i18n{dangerRestore}</cr-button>
          </div>
        </template>
      </div>
    </template>
  </div>
  <div role="gridcell">
    <cr-icon-button class="icon-clear"
        style$="[[computeRemoveStyle_(isDangerous_, showCancel_)]]"
        id="remove" title="$i18n{controlRemoveFromList}"
        aria-label$="[[controlRemoveFromListAriaLabel_]]"
        on-click="onRemoveTap_" focus-row-control focus-type="remove">
    </cr-icon-button>
  </div>
  <div id="incognito" title="$i18n{inIncognito}" hidden="[[!data.otr]]">
  </div>
</div>
<!--_html_template_end_-->`,

    behaviors: [
      FocusRowBehavior,
    ],

    /** Used by FocusRowBehavior. */
    overrideCustomEquivalent: true,

    properties: {
      /** @type {!downloads.Data} */
      data: Object,

      /** @private */
      completelyOnDisk_: {
        computed: 'computeCompletelyOnDisk_(' +
            'data.state, data.fileExternallyRemoved)',
        type: Boolean,
        value: true,
      },

      /** @private */
      controlledBy_: {
        computed: 'computeControlledBy_(data.byExtId, data.byExtName)',
        type: String,
        value: '',
      },

      /** @private */
      controlRemoveFromListAriaLabel_: {
        type: String,
        computed: 'computeControlRemoveFromListAriaLabel_(data.fileName)',
      },

      /** @private */
      isActive_: {
        computed: 'computeIsActive_(' +
            'data.state, data.fileExternallyRemoved)',
        type: Boolean,
        value: true,
      },

      /** @private */
      isDangerous_: {
        computed: 'computeIsDangerous_(data.state)',
        type: Boolean,
        value: false,
      },

      /** @private */
      isMalware_: {
        computed: 'computeIsMalware_(isDangerous_, data.dangerType)',
        type: Boolean,
        value: false,
      },

      /** @private */
      isInProgress_: {
        computed: 'computeIsInProgress_(data.state)',
        type: Boolean,
        value: false,
      },

      /** @private */
      pauseOrResumeText_: {
        computed: 'computePauseOrResumeText_(isInProgress_, data.resume)',
        type: String,
        observer: 'updatePauseOrResumeClass_',
      },

      /** @private */
      showCancel_: {
        computed: 'computeShowCancel_(data.state)',
        type: Boolean,
        value: false,
      },

      /** @private */
      showProgress_: {
        computed: 'computeShowProgress_(showCancel_, data.percent)',
        type: Boolean,
        value: false,
      },

      /** @private */
      showOpenNow_: {
        computed: 'computeShowOpenNow_(data.state)',
        type: Boolean,
        value: false,
      },

      useFileIcon_: Boolean,
    },

    hostAttributes: {
      role: 'row',
    },

    observers: [
      // TODO(dbeam): this gets called way more when I observe data.byExtId
      // and data.byExtName directly. Why?
      'observeControlledBy_(controlledBy_)',
      'observeIsDangerous_(isDangerous_, data)',
      'restoreFocusAfterCancelIfNeeded_(data)',
    ],

    /** @private {downloads.mojom.PageHandlerInterface} */
    mojoHandler_: null,

    /** @private {boolean} */
    restoreFocusAfterCancel_: false,

    /** @override */
    attached() {
      afterNextRender(this, function() {
        IronA11yAnnouncer.requestAvailability();
      });
    },

    /** @override */
    ready() {
      this.mojoHandler_ = BrowserProxy.getInstance().handler;
      this.content = this.$.content;
    },

    focusOnRemoveButton() {
      focusWithoutInk(this.$.remove);
    },

    /** Overrides FocusRowBehavior. */
    getCustomEquivalent(sampleElement) {
      if (sampleElement.getAttribute('focus-type') === 'cancel') {
        return this.$$('[focus-type="retry"]');
      }
      if (sampleElement.getAttribute('focus-type') === 'retry') {
        return this.$$('[focus-type="pauseOrResume"]');
      }
      return null;
    },

    /** @return {!HTMLElement} */
    getFileIcon() {
      return /** @type {!HTMLElement} */ (this.$['file-icon']);
    },

    /**
     * @param {string} url
     * @return {string} A reasonably long URL.
     * @private
     */
    chopUrl_(url) {
      return url.slice(0, 300);
    },

    /** @private */
    computeClass_() {
      const classes = [];

      if (this.isActive_) {
        classes.push('is-active');
      }

      if (this.isDangerous_) {
        classes.push('dangerous');
      }

      if (this.showProgress_) {
        classes.push('show-progress');
      }

      return classes.join(' ');
    },

    /**
     * @return {boolean}
     * @private
     */
    computeCompletelyOnDisk_() {
      return this.data.state === States.COMPLETE &&
          !this.data.fileExternallyRemoved;
    },

    /**
     * @return {string}
     * @private
     */
    computeControlledBy_() {
      if (!this.data.byExtId || !this.data.byExtName) {
        return '';
      }

      const url = `chrome://extensions/?id=${this.data.byExtId}`;
      const name = this.data.byExtName;
      return loadTimeData.getStringF('controlledByUrl', url, HTMLEscape(name));
    },

    /**
     * @return {string}
     * @private
     */
    computeControlRemoveFromListAriaLabel_() {
      return loadTimeData.getStringF(
          'controlRemoveFromListAriaLabel', this.data.fileName);
    },

    /**
     * @return {string}
     * @private
     */
    computeDate_() {
      assert(typeof this.data.hideDate === 'boolean');
      if (this.data.hideDate) {
        return '';
      }
      return assert(this.data.sinceString || this.data.dateString);
    },

    /** @private @return {boolean} */
    computeDescriptionVisible_() {
      return this.computeDescription_() !== '';
    },

    /**
     * @return {string}
     * @private
     */
    computeDescription_() {
      const data = this.data;

      switch (data.state) {
        case States.COMPLETE:
          switch (data.dangerType) {
            case DangerType.DEEP_SCANNED_SAFE:
              return loadTimeData.getString('deepScannedSafeDesc');
            case DangerType.DEEP_SCANNED_OPENED_DANGEROUS:
              return loadTimeData.getString('deepScannedOpenedDangerousDesc');
          }
          break;

        case States.MIXED_CONTENT:
          return loadTimeData.getString('mixedContentDownloadDesc');

        case States.DANGEROUS:
          const fileName = data.fileName;
          switch (data.dangerType) {
            case DangerType.DANGEROUS_FILE:
              return loadTimeData.getString('dangerFileDesc');

            case DangerType.DANGEROUS_URL:
            case DangerType.DANGEROUS_CONTENT:
            case DangerType.DANGEROUS_HOST:
              return loadTimeData.getString('dangerDownloadDesc');

            case DangerType.UNCOMMON_CONTENT:
              return loadTimeData.getString('dangerUncommonDesc');

            case DangerType.POTENTIALLY_UNWANTED:
              return loadTimeData.getString('dangerSettingsDesc');

            case DangerType.SENSITIVE_CONTENT_WARNING:
              return loadTimeData.getString('sensitiveContentWarningDesc');
          }
          break;

        case States.ASYNC_SCANNING:
          return loadTimeData.getString('asyncScanningDownloadDesc');

        case States.IN_PROGRESS:
        case States.PAUSED:  // Fallthrough.
          return data.progressStatusText;

        case States.INTERRUPTED:
          switch (data.dangerType) {
            case DangerType.SENSITIVE_CONTENT_BLOCK:
              return loadTimeData.getString('sensitiveContentBlockedDesc');
            case DangerType.BLOCKED_TOO_LARGE:
              return loadTimeData.getString('blockedTooLargeDesc');
            case DangerType.BLOCKED_PASSWORD_PROTECTED:
              return loadTimeData.getString('blockedPasswordProtectedDesc');
          }
      }

      return '';
    },

    /**
     * @return {string}
     * @private
     */
    computeIcon_() {
      if (this.data) {
        const dangerType = this.data.dangerType;
        if ((loadTimeData.getBoolean('requestsApVerdicts') &&
             dangerType === DangerType.UNCOMMON_CONTENT) ||
            dangerType === DangerType.SENSITIVE_CONTENT_WARNING) {
          return 'cr:error';
        }

        const WARNING_TYPES = [
          DangerType.SENSITIVE_CONTENT_BLOCK,
          DangerType.BLOCKED_TOO_LARGE,
          DangerType.BLOCKED_PASSWORD_PROTECTED,
        ];
        if (WARNING_TYPES.includes(dangerType)) {
          return 'cr:warning';
        }

        if (this.data.state === States.ASYNC_SCANNING) {
          return 'cr:error';
        }
      }
      if (this.isDangerous_) {
        return 'cr:warning';
      }
      if (!this.useFileIcon_) {
        return 'cr:insert-drive-file';
      }
      return '';
    },

    /**
     * @return {string}
     * @private
     */
    computeIconColor_() {
      if (this.data) {
        const dangerType = this.data.dangerType;
        if ((loadTimeData.getBoolean('requestsApVerdicts') &&
             dangerType === DangerType.UNCOMMON_CONTENT) ||
            dangerType === DangerType.SENSITIVE_CONTENT_WARNING) {
          return 'yellow';
        }

        const WARNING_TYPES = [
          DangerType.SENSITIVE_CONTENT_BLOCK,
          DangerType.BLOCKED_TOO_LARGE,
          DangerType.BLOCKED_PASSWORD_PROTECTED,
        ];
        if (WARNING_TYPES.includes(dangerType)) {
          return 'red';
        }

        if (this.data.state === States.ASYNC_SCANNING) {
          return 'grey';
        }
      }
      if (this.isDangerous_) {
        return 'red';
      }
      if (!this.useFileIcon_) {
        return 'paper-grey';
      }
      return '';
    },

    /**
     * @return {boolean}
     * @private
     */
    computeIsActive_() {
      return this.data.state !== States.CANCELLED &&
          this.data.state !== States.INTERRUPTED &&
          !this.data.fileExternallyRemoved;
    },

    /**
     * @return {boolean}
     * @private
     */
    computeIsDangerous_() {
      return this.data.state === States.DANGEROUS ||
             this.data.state === States.MIXED_CONTENT;
    },

    /**
     * @return {boolean}
     * @private
     */
    computeIsInProgress_() {
      return this.data.state === States.IN_PROGRESS;
    },

    /**
     * @return {boolean}
     * @private
     */
    computeIsMalware_() {
      return this.isDangerous_ &&
          (this.data.dangerType === DangerType.DANGEROUS_CONTENT ||
           this.data.dangerType === DangerType.DANGEROUS_HOST ||
           this.data.dangerType === DangerType.DANGEROUS_URL ||
           this.data.dangerType === DangerType.POTENTIALLY_UNWANTED);
    },

    /** @private */
    toggleButtonClass_() {
      this.$$('#pauseOrResume')
          .classList.toggle(
              'action-button',
              this.pauseOrResumeText_ ===
                  loadTimeData.getString('controlResume'));
    },

    /** @private */
    updatePauseOrResumeClass_() {
      if (!this.pauseOrResumeText_) {
        return;
      }

      // Wait for dom-if to switch to true, in case the text has just changed
      // from empty.
      beforeNextRender(this, () => this.toggleButtonClass_());
    },

    /**
     * @return {string}
     * @private
     */
    computePauseOrResumeText_() {
      if (this.data === undefined) {
        return '';
      }

      if (this.isInProgress_) {
        return loadTimeData.getString('controlPause');
      }
      if (this.data.resume) {
        return loadTimeData.getString('controlResume');
      }
      return '';
    },

    /**
     * @return {string}
     * @private
     */
    computeRemoveStyle_() {
      const canDelete = loadTimeData.getBoolean('allowDeletingHistory');
      const hideRemove = this.isDangerous_ || this.showCancel_ || !canDelete;
      return hideRemove ? 'visibility: hidden' : '';
    },

    /**
     * @return {boolean}
     * @private
     */
    computeShowCancel_() {
      return this.data.state === States.IN_PROGRESS ||
          this.data.state === States.PAUSED ||
          this.data.state === States.ASYNC_SCANNING;
    },

    /**
     * @return {boolean}
     * @private
     */
    computeShowProgress_() {
      return this.showCancel_ && this.data.percent >= -1 &&
          this.data.state !== States.ASYNC_SCANNING;
    },

    /**
     * @return {boolean}
     * @private
     */
    computeShowOpenNow_() {
      return this.data.state === States.ASYNC_SCANNING;
    },

    /**
     * @return {string}
     * @private
     */
    computeTag_() {
      switch (this.data.state) {
        case States.CANCELLED:
          return loadTimeData.getString('statusCancelled');

        case States.INTERRUPTED:
          return this.data.lastReasonText;

        case States.COMPLETE:
          return this.data.fileExternallyRemoved ?
              loadTimeData.getString('statusRemoved') :
              '';
      }

      return '';
    },

    /**
     * @return {boolean}
     * @private
     */
    isIndeterminate_() {
      return this.data.percent === -1;
    },

    /** @private */
    observeControlledBy_() {
      this.$['controlled-by'].innerHTML = this.controlledBy_;
      if (this.controlledBy_) {
        const link = this.$$('#controlled-by a');
        link.setAttribute('focus-row-control', '');
        link.setAttribute('focus-type', 'controlledBy');
      }
    },

    /** @private */
    observeIsDangerous_() {
      if (!this.data) {
        return;
      }

      const OVERRIDDEN_ICON_TYPES = [
        DangerType.SENSITIVE_CONTENT_BLOCK,
        DangerType.BLOCKED_TOO_LARGE,
        DangerType.BLOCKED_PASSWORD_PROTECTED,
      ];

      if (this.isDangerous_) {
        this.$.url.removeAttribute('href');
        this.useFileIcon_ = false;
      } else if (OVERRIDDEN_ICON_TYPES.includes(this.data.dangerType)) {
        this.useFileIcon_ = false;
      } else if (this.data.state === States.ASYNC_SCANNING) {
        this.useFileIcon_ = false;
      } else {
        this.$.url.href = assert(this.data.url);
        const path = this.data.filePath;
        IconLoader.getInstance()
            .loadIcon(this.$['file-icon'], path)
            .then(success => {
              if (path === this.data.filePath && this.data.state !==
                  States.ASYNC_SCANNING) {
                this.useFileIcon_ = success;
              }
            });
      }
    },

    /** @private */
    onCancelTap_() {
      this.restoreFocusAfterCancel_ = true;
      this.mojoHandler_.cancel(this.data.id);
    },

    /** @private */
    onDiscardDangerousTap_() {
      this.mojoHandler_.discardDangerous(this.data.id);
    },

    /** @private */
    onOpenNowTap_() {
      this.mojoHandler_.openDuringScanningRequiringGesture(this.data.id);
    },

    /**
     * @private
     * @param {Event} e
     */
    onDragStart_(e) {
      e.preventDefault();
      this.mojoHandler_.drag(this.data.id);
    },

    /**
     * @param {Event} e
     * @private
     */
    onFileLinkTap_(e) {
      e.preventDefault();
      this.mojoHandler_.openFileRequiringGesture(this.data.id);
    },

    /** @private */
    onUrlTap_() {
      chrome.send('metricsHandler:recordAction',
        ['Downloads_OpenUrlOfDownloadedItem']);
    },

    /** @private */
    onPauseOrResumeTap_() {
      if (this.isInProgress_) {
        this.mojoHandler_.pause(this.data.id);
      } else {
        this.mojoHandler_.resume(this.data.id);
      }
    },

    /** @private */
    onRemoveTap_() {
      const pieces = loadTimeData.getSubstitutedStringPieces(
          loadTimeData.getString('toastRemovedFromList'), this.data.fileName);
      pieces.forEach(p => {
        // Make the file name collapsible.
        p.collapsible = !!p.arg;
      });
      getToastManager().showForStringPieces(
          /**
           * @type {!Array<{collapsible: boolean,
           *                 value: string,
           *                 arg: (string|null)}>}
           */
          (pieces));
      this.fire('iron-announce', {
        text: loadTimeData.getString('undoDescription'),
      });
      this.mojoHandler_.remove(this.data.id);
    },

    /** @private */
    onRetryTap_() {
      this.mojoHandler_.retryDownload(this.data.id);
    },

    /** @private */
    onSaveDangerousTap_() {
      this.mojoHandler_.saveDangerousRequiringGesture(this.data.id);
    },

    /** @private */
    onShowTap_() {
      this.mojoHandler_.show(this.data.id);
    },

    /** @private */
    restoreFocusAfterCancelIfNeeded_() {
      if (!this.restoreFocusAfterCancel_) {
        return;
      }
      this.restoreFocusAfterCancel_ = false;
      setTimeout(() => {
        const element = this.getFocusRow().getFirstFocusable('retry');
        if (element) {
          element.focus();
        }
      });
    }
  });
