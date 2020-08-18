import {Polymer, html} from '//resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import './settings_page/main_page_behavior.m.js';
const template = document.createElement('template');
template.innerHTML = `
<dom-module id="settings-page-styles" assetpath="chrome://resources/">
  <template>
    <style>
      :host(.showing-subpage) settings-section:not(.expanded) {
        display: none;
      }

      :host > div > :not(.expanded) {
        /* The margin and padding here are doing two things: make the total
         * separation 24px; and make scrollIntoView align the section header
         * with the top item in the side nav menu. Both things are desired
         * by Alan (bettes@). */
        margin-bottom: 3px;
      }

      .expanded {
        min-height: 100%;
      }
    </style>
  </template>
</dom-module>
`;
document.body.appendChild(template.content.cloneNode(true));