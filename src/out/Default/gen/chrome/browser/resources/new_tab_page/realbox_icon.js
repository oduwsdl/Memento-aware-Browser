// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import './strings.m.js';

import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

const DOCUMENT_MATCH_TYPE = 'document';

// The LHS icon. Used on autocomplete matches as well as the realbox input to
// render icons, favicons, and entity images.
class RealboxIconElement extends PolymerElement {
  static get is() {
    return 'ntp-realbox-icon';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style>
  :host {
    align-items: center;
    display: flex;
    flex-shrink: 0;
    justify-content: center;
    width: 32px;
  }

  #imageContainer {
    align-items: center;
    border-radius: 8px;
    display: none;
    height: 32px;
    justify-content: center;
    overflow: hidden;
    width: 32px;
  }

  :host-context(ntp-realbox-match[has-image]) #imageContainer {
    display: flex;
  }

  #image {
    max-height: 32px;
    max-width: 32px;
  }

  #icon {
    -webkit-mask-position: center;
    -webkit-mask-repeat: no-repeat;
    -webkit-mask-size: 16px;
    background-color: var(--search-box-icon, var(--google-grey-refresh-700));
    background-position: center center;
    background-repeat: no-repeat;
    background-size: 16px;
    height: 24px;
    width: 24px;
  }

  :host-context(ntp-realbox-match[has-image]) #icon {
    display: none;
  }

  :host([in-searchbox][background-image='google_g.png']) #icon {
    background-size: 12px;
  }

  :host([in-searchbox][mask-image='search.svg']) #icon {
    -webkit-mask-size: 20px;  /* Loupe in realbox is larger than in matches. */
  }
</style>
<div id="imageContainer" style$="[[imageContainerStyle_]]">
    <image id="image" src$="[[imageSrc_]]"></image>
</div>
<div id="icon" style$="[[iconStyle_]]">
</div>

<!--_html_template_end_-->`;
  }

  static get properties() {
    return {
      //========================================================================
      // Public properties
      //========================================================================

      /**
       * Used as a background image on #icon if non-empty.
       * @type {string}
       */
      backgroundImage: {
        type: String,
        computed: `computeBackgroundImage_(match.faviconDataUrl, match)`,
        reflectToAttribute: true,
      },

      /**
       * The default icon to show when no match is selected and/or for
       * non-navigation matches. Only set in the context of the realbox input.
       * @type {string}
       */
      defaultIcon: {
        type: String,
        value: '',
      },

      /**
       * Used as a mask image on #icon if |backgroundImage| is empty.
       * @type {string}
       */
      maskImage: {
        type: String,
        computed: `computeMaskImage_(match)`,
        reflectToAttribute: true,
      },

      /**
       * @type {!search.mojom.AutocompleteMatch}
       */
      match: {
        type: Object,
      },

      //========================================================================
      // Private properties
      //========================================================================

      /**
       * @type {string}
       * @private
       */
      iconStyle_: {
        type: String,
        computed: `computeIconStyle_(backgroundImage, maskImage)`,
      },

      /**
       * @type {string}
       * @private
       */
      imageContainerStyle_: {
        type: String,
        computed: `computeImageContainerStyle_(imageSrc_, match)`,
      },

      /**
       * @type {string}
       * @private
       */
      imageSrc_: {
        type: String,
        computed: `computeImageSrc_(match.imageDataUrl, match)`,
      },
    };
  }

  //============================================================================
  // Helpers
  //============================================================================

  /**
   * @returns {string}
   * @private
   * @suppress {checkTypes}
   */
  computeBackgroundImage_() {
    // If the match is a navigation one and has a favicon loaded, display that
    // as background image. Otherwise, display the colored SVG icon for
    // 'document' matches.
    // If 'google_g' is the default icon, display that as background image when
    // there is no match or the match is not a navigation one. Otherwise, don't
    // use a background image (use a mask image instead).
    if (this.match && !this.match.isSearchType) {
      if (this.match.faviconDataUrl) {
        return this.match.faviconDataUrl;
      } else if (this.match.type === DOCUMENT_MATCH_TYPE) {
        return this.match.iconUrl;
      } else {
        return '';
      }
    } else if (this.defaultIcon === 'google_g.png') {
      return this.defaultIcon;
    } else {
      return '';
    }
  }

  /**
   * @returns {string}
   * @private
   */
  computeMaskImage_() {
    // Use the match icon if available. Otherwise use the default icon.
    if (this.match) {
      return this.match.iconUrl;
    } else {
      return this.defaultIcon;
    }
  }

  /**
   * @returns {string}
   * @private
   */
  computeIconStyle_() {
    // Use a background image if applicabale. Otherwise use a mask image.
    if (this.backgroundImage) {
      return `background-image: url(${this.backgroundImage});` +
          `background-color: transparent;`;
    } else {
      return `-webkit-mask-image: url(${this.maskImage});`;
    }
  }

  /**
   * @returns {string}
   * @private
   */
  computeImageContainerStyle_() {
    // Show a background color until the image loads.
    return (this.match && this.match.imageDominantColor && !this.imageSrc_) ?
        // .25 opacity matching c/b/u/views/omnibox/omnibox_match_cell_view.cc.
        `background-color: ${this.match.imageDominantColor}40;` :
        'background-color: transparent;';
  }

  /**
   * @returns {string}
   * @private
   * @suppress {checkTypes}
   */
  computeImageSrc_() {
    if (!this.match) {
      return '';
    }

    if (this.match.imageDataUrl) {
      return this.match.imageDataUrl;
    } else if (
        this.match.imageUrl && this.match.imageUrl.startsWith('data:image/')) {
      // zero-prefix matches come with the image content in |match.imageUrl|.
      return this.match.imageUrl;
    } else {
      return '';
    }
  }
}

customElements.define(RealboxIconElement.is, RealboxIconElement);
