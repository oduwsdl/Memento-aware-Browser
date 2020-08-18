// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

const template = document.createElement('template');
template.innerHTML = `
<dom-module id="search-engine-entry"><!--_html_template_start_-->

  <template>
    <style>
      site-favicon {
        margin-inline-end: 8px;
        min-width: 16px;
      }
    </style>
  </template>
<!--_html_template_end_--></dom-module>
`;
document.body.appendChild(template.content.cloneNode(true));
