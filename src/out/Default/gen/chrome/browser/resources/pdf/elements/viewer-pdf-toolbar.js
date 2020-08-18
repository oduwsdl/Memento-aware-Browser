// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/polymer/v3_0/paper-progress/paper-progress.js';
import 'chrome://resources/cr_elements/icons.m.js';
import './icons.js';
import './viewer-bookmark.js';
import './viewer-page-selector.js';
import './viewer-toolbar-dropdown.js';
// <if expr="chromeos">
import './viewer-pen-options.js';
// </if>

import {AnchorAlignment} from 'chrome://resources/cr_elements/cr_action_menu/cr_action_menu.m.js';
import {assert} from 'chrome://resources/js/assert.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {Bookmark} from '../bookmark_type.js';
import {SaveRequestType} from '../constants.js';

Polymer({
  is: 'viewer-pdf-toolbar',

  _template: html`<!--_html_template_start_-->
    <style include="cr-hidden-style">
      :host {
        --pdf-toolbar-background-color: rgb(50, 54, 57);
        --pdf-toolbar-text-color: rgb(241, 241, 241);
      }

      :host ::selection {
        background: rgba(255, 255, 255, 0.3);
      }

      /* We introduce a wrapper aligner element to help with laying out the main
       * toolbar content without changing the bottom-aligned progress bar. */
      #aligner {
        align-items: center;
        display: flex;
        padding: 0 8px;
        width: 100%;
      }

      #title {
        flex: 5;
        font-size: 0.87rem;
        font-weight: 500;
        overflow: hidden;
        text-overflow: ellipsis;
        white-space: nowrap;
      }

      #pageselector-container {
        text-align: center;
        /* The container resizes according to the width of the toolbar. On small
         * screens with large numbers of pages, overflow page numbers without
         * wrapping. */
        white-space: nowrap;
      }

      #buttons {
        flex: 5;
        text-align: end;
        user-select: none;
      }

      cr-icon-button {
        --cr-icon-button-fill-color: var(--pdf-toolbar-text-color);
        margin: 6px;
      }

      cr-icon-button:hover {
        background: rgba(255, 255, 255, 0.08);
        border-radius: 50%;
      }

      paper-progress {
        --paper-progress-active-color: var(--google-blue-300);
        --paper-progress-container-color: transparent;
        --paper-progress-height: 3px;
        transition: opacity 150ms;
        width: 100%;
      }

      #toolbar {
        background-color: var(--pdf-toolbar-background-color);
        box-shadow: var(--cr-elevation-2);
        position: relative;
      }

      #annotations-bar {
        align-items: center;
        background-color: rgb(32, 33, 34);
        justify-content: center;
      }

      #toolbar,
      #annotations-bar {
        color: var(--pdf-toolbar-text-color);
        display: flex;
        height: 48px;
        padding: 0 16px;
      }

      #progress-container {
        bottom: 0;
        left: 0;
        margin: 0;
        position: absolute;
        right: 0;
        top: auto;
        width: auto;
      }

      #pen,
      #highlighter {
        --dropdown-width: 346px;
      }

      #pen,
      #highlighter {
        --dropdown-open-background: var(--pdf-viewer-background-color);
      }

      #eraser {
        opacity: 0.38;
      }

      #eraser[selected],
      #eraser:focus,
      #eraser:hover {
        opacity: 1;
      }

      #annotation-separator {
        background: white;
        height: 30px;
        margin-inline-end: 12px;
        margin-inline-start: 12px;
        opacity: 0.38;
        width: 1px;
      }

      :host([annotation-mode]) #annotate {
        background-color: rgba(255, 255, 255, 0.24);
        border-radius: 50%;
      }

      #bookmarks {
        margin-inline-start: 8px;
      }

      #pen {
        margin-inline-end: 10px;
      }

      #highlighter {
        margin-inline-end: 6px;
      }

      .invisible {
        visibility: hidden;
      }

      @media(max-width: 675px) {
        #bookmarks,
        #rotate-left {
          display: none;
        }
      }

      @media(max-width: 450px) {
        #rotate-right {
          display: none;
        }
      }

      @media(max-width: 400px) {
        #buttons,
        #pageselector-container {
          display: none;
        }
      }
    </style>
    <div id="toolbar">
      <div id="aligner">
        <span id="title" title="[[docTitle]]">
          <span>[[docTitle]]</span>
        </span>

        <div id="pageselector-container">
          <viewer-page-selector id="pageselector" class="invisible"
              doc-length="[[docLength]]" page-no="[[pageNo]]">
          </viewer-page-selector>
        </div>

        <div id="buttons" class="invisible">
<if expr="chromeos">
          <template is="dom-if" if="[[pdfAnnotationsEnabled_]]">
            <cr-icon-button id="annotate" iron-icon="pdf:create"
                disabled="[[!annotationAvailable]]" on-click="toggleAnnotation"
                aria-label$="$i18n{tooltipAnnotate}"
                title="$i18n{tooltipAnnotate}"></cr-icon-button>
          </template>
</if>

          <cr-icon-button id="rotate-right" iron-icon="pdf:rotate-right"
              disabled="[[annotationMode]]" on-click="rotateRight"
              aria-label$="$i18n{tooltipRotateCW}"
              title="$i18n{tooltipRotateCW}"></cr-icon-button>

          <cr-icon-button id="download" iron-icon="cr:file-download"
              on-click="onDownloadClick_" aria-label$="$i18n{tooltipDownload}"
              title="$i18n{tooltipDownload}"></cr-icon-button>
          <cr-action-menu id="downloadMenu">
            <button class="dropdown-item" on-click="onDownloadEditedClick_">
              $i18n{downloadEdited}
            </button>
            <button class="dropdown-item" on-click="onDownloadOriginalClick_">
              $i18n{downloadOriginal}
            </button>
          </cr-action-menu>

          <cr-icon-button id="print" iron-icon="cr:print" on-click="print"
              hidden="[[!printingEnabled_]]" title="$i18n{tooltipPrint}"
              aria-label$="$i18n{tooltipPrint}"></cr-icon-button>

          <viewer-toolbar-dropdown id="bookmarks"
                                   selected
                                   metrics-id="bookmarks"
                                   hidden$="[[!bookmarks.length]]"
                                   open-icon="pdf:bookmark"
                                   closed-icon="pdf:bookmark-border"
                                   header="$i18n{bookmarks}">
            <template is="dom-repeat" items="[[bookmarks]]">
              <viewer-bookmark bookmark="[[item]]" depth="0"></viewer-bookmark>
            </template>
          </viewer-toolbar-dropdown>
        </div>
      </div>
      <div id="progress-container">
        <paper-progress id="progress"
            value="[[loadProgress]]"
            indeterminate="[[annotationMode]]"></paper-progress>
      </div>
    </div>

<if expr="chromeos">
    <div id="annotations-bar" hidden>
      <viewer-toolbar-dropdown id="pen"
          selected$="[[isAnnotationTool_('pen', annotationTool.tool)]]"
          open-after-select
          on-click="annotationToolClicked_"
          open-icon="pdf:marker"
          closed-icon="pdf:marker"
          dropdown-centered
          hide-header
          header="$i18n{annotationPen}"
          style="--pen-tip-fill: #000000">
        <viewer-pen-options
          selected-color="#000000"
          selected-size="0.1429"
          strings="[[strings]]"
          on-selected-size-changed="annotationToolOptionChanged_"
          on-selected-color-changed="annotationToolOptionChanged_">
        </viewer-pen-options>
      </viewer-toolbar-dropdown>

      <viewer-toolbar-dropdown id="highlighter"
          selected$="[[isAnnotationTool_('highlighter', annotationTool.tool)]]"
          open-after-select
          on-click="annotationToolClicked_"
          open-icon="pdf:highlighter"
          closed-icon="pdf:highlighter"
          dropdown-centered
          hide-header
          header="$i18n{annotationHighlighter}"
          style="--pen-tip-fill: #ffbc00">
        <viewer-pen-options
          selected-color="#ffbc00"
          selected-size="0.7143"
          strings="[[strings]]"
          on-selected-size-changed="annotationToolOptionChanged_"
          on-selected-color-changed="annotationToolOptionChanged_">
        </viewer-pen-options>
      </viewer-toolbar-dropdown>

      <cr-icon-button id="eraser"
          selected$="[[isAnnotationTool_('eraser', annotationTool.tool)]]"
          on-click="annotationToolClicked_" iron-icon="pdf:eraser"
          aria-label$="$i18n{annotationEraser}"
          title="$i18n{annotationEraser}"></cr-icon-button>

      <div id="annotation-separator"></div>

      <cr-icon-button id="undo" disabled="[[!canUndoAnnotation]]"
          iron-icon="pdf:undo" on-click="undo"
          aria-label$="$i18n{annotationUndo}"
          title="$i18n{annotationUndo}"></cr-icon-button>

      <cr-icon-button id="redo" disabled="[[!canRedoAnnotation]]"
          iron-icon="pdf:redo" on-click="redo"
          aria-label$="$i18n{annotationRedo}"
          title="$i18n{annotationRedo}"></cr-icon-button>
    </div>
</if>
<!--_html_template_end_-->`,

  properties: {
    /**
     * Whether annotation mode can be entered. This would be false if for
     * example the PDF is encrypted or password protected. Note, this is
     * true regardless of whether the feature flag is enabled.
     */
    annotationAvailable: {
      type: Boolean,
      value: true,
    },

    /** Whether the viewer is currently in annotation mode. */
    annotationMode: {
      type: Boolean,
      notify: true,
      value: false,
      reflectToAttribute: true,
    },

    /** @type {?AnnotationTool} */
    annotationTool: {
      type: Object,
      value: null,
      notify: true,
    },

    /**
     * Tree of PDF bookmarks (empty if the document has no bookmarks).
     * @type {!Array<!Bookmark>}
     */
    bookmarks: {
      type: Array,
      value: () => [],
    },

    canRedoAnnotation: {
      type: Boolean,
      value: false,
    },

    canUndoAnnotation: {
      type: Boolean,
      value: false,
    },

    /** The number of pages in the PDF document. */
    docLength: Number,

    /** The title of the PDF document. */
    docTitle: String,

    /** The current loading progress of the PDF document (0 - 100). */
    loadProgress: {
      type: Number,
      observer: 'loadProgressChanged_',
    },

    /** Whether the toolbar is opened and visible. */
    opened: {
      type: Boolean,
      value: true,
    },

    /** The number of the page being viewed (1-based). */
    pageNo: Number,

    /**
     * Whether the PDF Annotations feature is enabled.
     * @private
     */
    pdfAnnotationsEnabled_: {
      type: Boolean,
      value: false,
    },

    /**
     * Whether the Printing feature is enabled.
     * @private
     */
    printingEnabled_: {
      type: Boolean,
      value: false,
    },

    strings: {
      type: Object,
      observer: 'onStringsSet_',
    },
  },

  /** @type {?Object} */
  animation_: null,

  /** @private {boolean} */
  hasEdits_: false,

  /** @private {boolean} */
  hasAnnotations_: false,

  /**
   * Whether the PDF Form save feature is enabled.
   * @private {boolean}
   */
  pdfFormSaveEnabled_: false,

  /**
   * @param {number} newProgress
   * @param {number} oldProgress
   * @private
   */
  loadProgressChanged_(newProgress, oldProgress) {
    const loaded = newProgress >= 100;
    const progressReset = newProgress < oldProgress;
    if (progressReset || loaded) {
      this.$.pageselector.classList.toggle('invisible', !loaded);
      this.$.buttons.classList.toggle('invisible', !loaded);
      this.$.progress.style.opacity = loaded ? 0 : 1;
      // <if expr="chromeos">
      this.$['annotations-bar'].hidden = !loaded || !this.annotationMode;
      // </if>
    }
  },

  hide() {
    if (this.opened && !this.shouldKeepOpen()) {
      this.toggleVisibility();
    }
  },

  show() {
    if (!this.opened) {
      this.toggleVisibility();
    }
  },

  toggleVisibility() {
    this.opened = !this.opened;

    // We keep a handle on the animation in order to cancel the filling
    // behavior of previous animations.
    if (this.animation_) {
      this.animation_.cancel();
    }

    if (this.opened) {
      this.animation_ = this.animate(
          [{transform: 'translateY(-100%)'}, {transform: 'translateY(0%)'}], {
            duration: 250,
            easing: 'cubic-bezier(0, 0, 0.2, 1)',
            fill: 'forwards',
          });
    } else {
      this.animation_ = this.animate(
          [{transform: 'translateY(0%)'}, {transform: 'translateY(-100%)'}], {
            duration: 250,
            easing: 'cubic-bezier(0.4, 0, 1, 1)',
            fill: 'forwards',
          });
    }
  },

  setIsEditing() {
    this.hasEdits_ = true;
  },

  selectPageNumber() {
    this.$.pageselector.select();
  },

  /** @return {boolean} Whether the toolbar should be kept open. */
  shouldKeepOpen() {
    return this.$.bookmarks.dropdownOpen || this.loadProgress < 100 ||
        this.$.pageselector.isActive() || this.annotationMode ||
        this.$.downloadMenu.open;
  },

  /** @return {boolean} Whether a dropdown was open and was hidden. */
  hideDropdowns() {
    let result = false;
    if (this.$.bookmarks.dropdownOpen) {
      this.$.bookmarks.toggleDropdown();
      result = true;
    }
    // <if expr="chromeos">
    if (this.$.pen.dropdownOpen) {
      this.$.pen.toggleDropdown();
      result = true;
    }
    if (this.$.highlighter.dropdownOpen) {
      this.$.highlighter.toggleDropdown();
      result = true;
    }
    // </if>
    return result;
  },

  /** @param {number} lowerBound */
  setDropdownLowerBound(lowerBound) {
    this.$.bookmarks.lowerBound = lowerBound;
  },

  rotateRight() {
    this.fire('rotate-right');
  },

  /** @private */
  onDownloadClick_() {
    if (!this.hasAnnotations_ &&
        (!this.hasEdits_ || !this.pdfFormSaveEnabled_)) {
      this.fire('save', SaveRequestType.ORIGINAL);
      return;
    }
    this.$.downloadMenu.showAt(this.$.download, {
      anchorAlignmentX: AnchorAlignment.CENTER,
      anchorAlignmentY: AnchorAlignment.AFTER_END,
      noOffset: true,
    });
  },

  /** @private */
  onDownloadOriginalClick_() {
    this.fire('save', SaveRequestType.ORIGINAL);
    this.$.downloadMenu.close();
  },

  /** @private */
  onDownloadEditedClick_() {
    this.fire(
        'save',
        this.hasAnnotations_ ? SaveRequestType.ANNOTATION :
                               SaveRequestType.EDITED);
    this.$.downloadMenu.close();
  },

  print() {
    this.fire('print');
  },

  undo() {
    this.fire('undo');
  },

  redo() {
    this.fire('redo');
  },

  toggleAnnotation() {
    this.annotationMode = !this.annotationMode;
    if (this.annotationMode) {
      this.hasAnnotations_ = true;
      // Select pen tool when entering annotation mode.
      this.updateAnnotationTool_(/** @type {!HTMLElement} */ (this.$.pen));
    }
    this.dispatchEvent(new CustomEvent('annotation-mode-toggled', {
      detail: {
        value: this.annotationMode,
      },
    }));
  },

  /**
   * @param {!Event} e
   * @private
   */
  annotationToolClicked_(e) {
    this.updateAnnotationTool_(/** @type {!HTMLElement} */ (e.currentTarget));
  },

  /**
   * @param {!Event} e
   * @private
   */
  annotationToolOptionChanged_(e) {
    const element = e.currentTarget.parentElement;
    if (!this.annotationTool || element.id !== this.annotationTool.tool) {
      return;
    }
    this.updateAnnotationTool_(e.currentTarget.parentElement);
  },

  /**
   * @param {!HTMLElement} element
   * @private
   */
  updateAnnotationTool_(element) {
    const tool = element.id;
    const options = element.querySelector('viewer-pen-options') || {
      selectedSize: 1,
      selectedColor: undefined,
    };
    const attributeStyleMap = element.attributeStyleMap;
    attributeStyleMap.set('--pen-tip-fill', options.selectedColor);
    attributeStyleMap.set(
        '--pen-tip-border',
        options.selectedColor === '#000000' ? 'currentcolor' :
                                              options.selectedColor);
    this.annotationTool = {
      tool: tool,
      size: options.selectedSize,
      color: options.selectedColor,
    };
  },

  /**
   * @param {string} toolName
   * @return {boolean} Whether the annotation tool is using tool |toolName|.
   * @private
   */
  isAnnotationTool_(toolName) {
    return !!this.annotationTool && this.annotationTool.tool === toolName;
  },

  /** @private */
  onStringsSet_() {
    assert(this.strings);

    this.pdfAnnotationsEnabled_ =
        loadTimeData.getBoolean('pdfAnnotationsEnabled');
    this.pdfFormSaveEnabled_ = loadTimeData.getBoolean('pdfFormSaveEnabled');
    this.printingEnabled_ = loadTimeData.getBoolean('printingEnabled');
  },
});
