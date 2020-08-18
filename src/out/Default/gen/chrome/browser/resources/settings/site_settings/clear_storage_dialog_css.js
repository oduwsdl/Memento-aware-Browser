// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

const template = document.createElement('template');
template.innerHTML = `
<dom-module id="clear-storage-dialog-shared"><!--_html_template_start_-->

  <template>
    <style>
      .detail-list {
        margin-top: 12px;
      }

      .detail {
        align-items: center;
        display: flex;
        margin-top: 8px;
      }

      .detail iron-icon {
        margin-inline-end: 16px;
      }
    </style>
  </template>
<!--_html_template_end_--></dom-module>
`;
document.body.appendChild(template.content.cloneNode(true));
