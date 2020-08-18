// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_components/managed_footnote/managed_footnote.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import './shared_style.js';

import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

Polymer({
  is: 'extensions-checkup',

  _template: html`<!--_html_template_start_-->
<style include="cr-shared-style iron-flex shared-style">
  :host {
    --checkup-card-margin: 24px;
    --banner-img-height: 115px;
    --banner-img-width: 298px;
  }

  #card {
    background-color: var(--cr-card-background-color);
    border-radius: var(--cr-card-border-radius);
    box-shadow: var(--cr-card-shadow);
    overflow: hidden;
    padding: var(--checkup-card-margin);
    transition: height var(--drawer-transition);
  }

  #banner-img {
    background: url(checkup_image.svg);
    background-repeat: no-repeat;
    display: inline-block;
    float: right;
    /* Height and width match the dimensions of the banner image. */
    height: var(--banner-img-height);
    width: var(--banner-img-width);
  }

  #banner-description {
    flex-basis: var(--extensions-card-width);
    text-overflow: ellipsis;
  }

  #banner-title {
    color: var(--cr-primary-text-color);
    font-size: 123%;
  }

  /* 932px is the last screen width in which we can fit a banner that spans two
     columns and can be calculated by adding 2 card widths of
     var(--extensions-card-width) and the column gap var(--grid-gutter) and
     maintain padding of 60px on either side of the content on this page
     (see content-wrapper in item-list.html).*/
  @media (max-width: 931px) {
    #banner-img {
      display: block;
      float: initial;
      margin: 12px auto 0;
    }
  }

  @media (prefers-color-scheme: dark) {
    #banner-img {
      background: url(checkup_image_dark.svg);
    }
  }

</style>
<div id="card">
  <div id="banner-title" class="cr-title-text">$i18n{checkupTitle}</div>
  <div id="banner-img"></div>
  <div id="banner-description" class="cr-secondary-text">
    <p>$i18n{checkupBody1}</p>
    <p>$i18n{checkupBody2}</p>
  </div>
</div>
<!--_html_template_end_-->`,

});
