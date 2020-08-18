// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {Polymer, html} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import '//resources/cr_elements/cr_button/cr_button.m.js';
import {assert} from '//resources/js/assert.m.js';
import {I18nBehavior} from '//resources/js/i18n_behavior.m.js';
import {ExtensionControlBrowserProxyImpl} from '../extension_control_browser_proxy.m.js';
import '../i18n_setup.js';
import '../settings_shared_css.m.js';

Polymer({
  _template: html`<!--_html_template_start_-->
    <style include="settings-shared">
      :host {
        align-items: center;
        display: flex;
        margin-inline-start: 36px;
        min-height: var(--settings-row-min-height);
      }

      img {
        /* Dimensions of the image are set in the URL. */
        margin-inline-end: 16px;
      }

      /* Using ">" operator to ensure that this CSS rule will not accidentally
       * be applied to a search highlight span (which is inserted dynamically if
       * when search "hit" occurs within this element. */
      :host > span {
        flex: 1;
        margin-inline-end: 8px;
      }
    </style>
    <img role="presentation" src="chrome://extension-icon/[[extensionId]]/20/1">
    <span inner-h-t-m-l="[[getLabel_(extensionId, extensionName)]]"></span>
    <template is="dom-if" if="[[extensionCanBeDisabled]]" restamp>
      <cr-button on-click="onDisableTap_">$i18n{disable}</cr-button>
    </template>
<!--_html_template_end_-->`,
  is: 'extension-controlled-indicator',

  behaviors: [I18nBehavior],

  properties: {
    extensionCanBeDisabled: Boolean,
    extensionId: String,
    extensionName: String,
  },

  /**
   * @param {string} extensionId
   * @param {string} extensionName
   * @return {string}
   * @private
   */
  getLabel_(extensionId, extensionName) {
    if (this.extensionId === undefined || this.extensionName === undefined) {
      return '';
    }

    const manageUrl = 'chrome://extensions/?id=' + this.extensionId;
    return this.i18nAdvanced('controlledByExtension', {
      substitutions:
          ['<a href="' + manageUrl + '" target="_blank">' + this.extensionName +
           '</a>'],
    });
  },

  /** @private */
  onDisableTap_() {
    assert(this.extensionCanBeDisabled);
    ExtensionControlBrowserProxyImpl.getInstance().disableExtension(
        assert(this.extensionId));
    this.fire('extension-disable');
  },
});
