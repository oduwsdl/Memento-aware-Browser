// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';

import {DragWrapper} from 'chrome://resources/js/cr/ui/drag_wrapper.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {DragAndDropHandler} from './drag_and_drop_handler.js';

Polymer({
  is: 'extensions-drop-overlay',

  _template: html`<!--_html_template_start_-->
<style include="cr-hidden-style">
  :host {
    align-items: center;
    background-color: rgba(241, 241, 241, .9);
    color: var(--cr-secondary-text-color);
    display: flex;
    height: 100%;
    justify-content: center;
    position: absolute;
    width: 100%;
    z-index: 10;
  }

  @media (prefers-color-scheme: dark) {
    :host {
      /* TODO(dbeam): share with cr-dialog dialog::backdrop? */
      background-color: rgba(0, 0, 0, .6);
    }
  }

  #container {
    align-items: center;
    display: flex;
    flex-direction: column;
  }

  iron-icon {
    height: 64px;
    margin-bottom: 16px;
    width: 64px;
  }

  #text {
    color: #6e6e6e;
    font-size: 123.1%;
    font-weight: 500;
  }
</style>
<div id="container">
  <iron-icon icon="cr:extension"></iron-icon>
  <div id="text">$i18n{dropToInstall}</div>
</div>
<!--_html_template_end_-->`,

  properties: {
    /** @private {boolean} */
    dragEnabled: {
      type: Boolean,
      observer: 'dragEnabledChanged_',
    }
  },

  /** @override */
  created() {
    this.hidden = true;
    const dragTarget = document.documentElement;
    this.dragWrapperHandler_ = new DragAndDropHandler(true, dragTarget);
    // TODO(devlin): All these dragTarget listeners leak (they aren't removed
    // when the element is). This only matters in tests at the moment, but would
    // be good to fix.
    dragTarget.addEventListener('extension-drag-started', () => {
      this.hidden = false;
    });
    dragTarget.addEventListener('extension-drag-ended', () => {
      this.hidden = true;
    });
    dragTarget.addEventListener('drag-and-drop-load-error', (e) => {
      this.fire('load-error', e.detail);
    });
    this.dragWrapper_ = new DragWrapper(dragTarget, this.dragWrapperHandler_);
  },

  /**
   * @param {boolean} dragEnabled
   * @private
   */
  dragEnabledChanged_(dragEnabled) {
    this.dragWrapperHandler_.dragEnabled = dragEnabled;
  },
});
