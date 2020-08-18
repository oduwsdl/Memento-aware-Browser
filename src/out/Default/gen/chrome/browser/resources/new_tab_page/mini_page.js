// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

/** Element used to display a stylized NTP image. */
class MiniPageElement extends PolymerElement {
  static get is() {
    return 'ntp-mini-page';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style>
  :host {
    --ntp-mini-page-shortcut-color: var(--google-grey-refresh-300);
  }

  .mini-page {
    align-items: center;
    display: flex;
    flex-direction: column;
    height: 100%;
    justify-content: center;
    width: 100%;
  }

  .mini-header {
    height: 28%;
    width: 92%;
  }

  :host(:not([single-colored-logo])) .mini-header {
    background-image: url(icons/colored_header.svg);
    background-repeat: no-repeat;
    background-size: 100%;
  }

  :host([single-colored-logo]) .mini-header {
    -webkit-mask-image: url(icons/colored_header.svg);
    -webkit-mask-repeat: no-repeat;
    -webkit-mask-size: 100%;
    background-color: var(--google-grey-refresh-300);
  }

  .mini-shortcuts {
    -webkit-mask-image: url(icons/shortcut_circles.svg);
    -webkit-mask-repeat: no-repeat;
    -webkit-mask-size: 100%;
    background-color: var(--ntp-mini-page-shortcut-color);
    height: 29%;
    margin-top: 8%;
    width: 82%;
  }

  @media (prefers-color-scheme: dark) {
    :host(:not([single-colored-logo])) .mini-header,
    .mini-header {
      -webkit-mask-image: url(icons/colored_header.svg);
      -webkit-mask-repeat: no-repeat;
      -webkit-mask-size: 100%;
      background: white;
    }
  }
</style>
<div class="mini-page">
  <div class="mini-header"></div>
  <div class="mini-shortcuts"></div>
</div>
<!--_html_template_end_-->`;
  }
}

customElements.define(MiniPageElement.is, MiniPageElement);
