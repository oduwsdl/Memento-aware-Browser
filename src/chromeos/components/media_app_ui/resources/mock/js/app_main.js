// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * Provides a mock of http://go/media-app/index.ts which is pre-built and
 * brought in via DEPS to ../../app/js/app_main.js. Runs in an isolated guest.
 */

/**
 * Helper that returns UI that can serve as an effective mock of a fragment of
 * the real app, after loading a provided Blob URL.
 *
 * @typedef{function(string, string): Promise<!HTMLElement>}}
 */
let ModuleHandler;

/** @type{ModuleHandler} */
const createVideoChild = async (blobSrc) => {
  const video =
      /** @type{HTMLVideoElement} */ (document.createElement('video'));
  video.src = blobSrc;
  return video;
};

/** @type{ModuleHandler} */
const createImgChild = async (blobSrc, altText) => {
  const img = /** @type{!HTMLImageElement} */ (document.createElement('img'));
  img.src = blobSrc;
  img.alt = altText;
  try {
    await img.decode();
  } catch (error) {
    // Mimic what the real app does on decode errors so we can test error
    // handling for file access.
    img.alt = 'Unable to decode';
  }
  return img;
};

/**
 * A mock app used for testing when src-internal is not available.
 * @implements mediaApp.ClientApi
 */
class BacklightApp extends HTMLElement {
  constructor() {
    super();
    this.currentMedia =
        /** @type{!HTMLElement} */ (document.createElement('img'));
    this.appendChild(this.currentMedia);
  }

  /** @override  */
  async loadFiles(files) {
    let child;
    const file = files.item(0);
    if (file) {
      const isVideo = file.mimeType.match('^video/');
      const factory = isVideo ? createVideoChild : createImgChild;
      // Note the mock app will just leak this Blob URL.
      child = await factory(URL.createObjectURL(file.blob), file.name);
    } else {
      // Emulate zero state.
      child = document.createElement('img');
    }
    // Simulate an app that shows one image (either the loaded image or zero
    // state) at a time.
    this.replaceChild(child, this.currentMedia);
    this.currentMedia = child;
  }

  /** @override */
  setDelegate(delegate) {}
}
window.customElements.define('backlight-app', BacklightApp);

class VideoContainer extends HTMLElement {}
window.customElements.define('backlight-video-container', VideoContainer);

// Add error handlers similar to go/error-collector to test crash reporting in
// the mock app. The handlers in go/error-collector are compiled-in and have
// more sophisticated message extraction, with fewer assumptions.

/** @suppress{reportUnknownTypes,missingProperties} */
function sendCrashReport(params) {
  chrome.crashReportPrivate.reportError(params, () => {});
}
self.addEventListener('error', (event) => {
  const errorEvent = /** @type {ErrorEvent} */ (event);
  sendCrashReport({
    message: /** @type {Error} */ (errorEvent.error).message,
    url: window.location.href,
    product: 'ChromeOS_MediaAppMock',
    lineNumber: errorEvent.lineno,
    columnNumber: errorEvent.colno
  });
});
self.addEventListener('unhandledrejection', (event) => {
  const rejectionEvent = /** @type {{reason: Error}} */ (event);
  sendCrashReport({
    message: rejectionEvent.reason.message,
    url: window.location.href,
    product: 'ChromeOS_MediaAppMock',
  });
});

document.addEventListener('DOMContentLoaded', () => {
  // The "real" app first loads translations for populating strings in the app
  // for the initial load, then does this.
  document.body.appendChild(new BacklightApp());
});
