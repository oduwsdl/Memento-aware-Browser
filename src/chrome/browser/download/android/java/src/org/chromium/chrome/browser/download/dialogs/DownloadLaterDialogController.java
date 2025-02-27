// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.download.dialogs;

/**
 * Receives events from download later dialog.
 */
public interface DownloadLaterDialogController {
    /**
     * Called when the selection changed in the download later dialog.
     * @param choice The selection of the download time in the download later dialog.
     */
    void onDownloadLaterDialogComplete(@DownloadLaterDialogChoice int choice);

    /**
     * Called when the user cancel or dismiss the download location dialog.
     */
    void onDownloadLaterDialogCanceled();
}
