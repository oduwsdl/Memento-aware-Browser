// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * settings-idle-load is a simple variant of dom-if designed for lazy
 * loading and rendering of elements that are accessed imperatively. A URL is
 * given that holds the elements to be loaded lazily.
 */
import {Polymer, html, templatize, TemplateInstanceBase} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {assert} from '//resources/js/assert.m.js';
import {ensureLazyLoaded} from '../ensure_lazy_loaded.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <slot></slot>
<!--_html_template_end_-->`,
  is: 'settings-idle-load',

  properties: {
    /**
     * If specified, it will be loaded via an HTML import before stamping the
     * template.
     */
    url: String,
  },

  /** @private {?Element} */
  child_: null,

  /** @private {?Element|?TemplateInstanceBase} */
  instance_: null,

  /** @private {number} */
  idleCallback_: 0,

  /** @override */
  attached() {
    this.idleCallback_ = requestIdleCallback(() => {
      this.get();
    });
  },

  /** @override */
  detached() {
    // No-op if callback already fired.
    cancelIdleCallback(this.idleCallback_);
  },

  /**
   * @param {!function():!Promise} requestFn Requests the lazy module.
   * @return {!Promise<!Element>} Resolves with the stamped child element after
   *     the lazy module has been loaded.
   */
  requestLazyModule_(requestFn) {
    return new Promise((resolve, reject) => {
      requestFn().then(() => {
        const template =
            /** @type {!HTMLTemplateElement} */ (this.getContentChildren()[0]);
        const TemplateClass = templatize(template, this, {
          mutableData: false,
          forwardHostProp: this._forwardHostPropV2,
        });

        this.instance_ = new TemplateClass();

        assert(!this.child_);
        this.child_ = this.instance_.root.firstElementChild;

        this.parentNode.insertBefore(this.instance_.root, this);
        resolve(this.child_);

        this.fire('lazy-loaded');
      }, reject);
    });
  },

  /**
   * @return {!Promise<Element>} Child element which has been stamped into the
   *     DOM tree.
   */
  get() {
    if (this.loading_) {
      return this.loading_;
    }

    // clang-format off
    // Polymer 2 codepath
    // clang-format on

    // Polymer 3 codepath, do not delete next line comment.
    const requestLazyModuleFn = ensureLazyLoaded;

    this.loading_ = this.requestLazyModule_(requestLazyModuleFn);
    return this.loading_;
  },

  /**
   * @param {string} prop
   * @param {Object} value
   */
  _forwardHostPropV2(prop, value) {
    if (this.instance_) {
      this.instance_.forwardHostProp(prop, value);
    }
  },
});
