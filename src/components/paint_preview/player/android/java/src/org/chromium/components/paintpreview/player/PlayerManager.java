// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.components.paintpreview.player;

import android.content.Context;
import android.graphics.Rect;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.FrameLayout;

import androidx.annotation.VisibleForTesting;

import org.chromium.base.TraceEvent;
import org.chromium.base.UnguessableToken;
import org.chromium.components.paintpreview.browser.NativePaintPreviewServiceProvider;
import org.chromium.components.paintpreview.player.frame.PlayerFrameCoordinator;
import org.chromium.url.GURL;

import java.util.HashMap;
import java.util.Map;

import javax.annotation.Nonnull;
import javax.annotation.Nullable;

/**
 * This is the only public class in this package and is hence the access point of this component for
 * the outer world. Users should call {@link #destroy()}  to ensure the native part is destroyed.
 */
public class PlayerManager {
    private Context mContext;
    private PlayerCompositorDelegateImpl mDelegate;
    private PlayerFrameCoordinator mRootFrameCoordinator;
    private FrameLayout mHostView;
    private Runnable mViewReadyCallback;
    private static final String sInitEvent = "paint_preview PlayerManager init";
    private PlayerSwipeRefreshHandler mPlayerSwipeRefreshHandler;

    /**
     * Creates a new {@link PlayerManager}.
     * @param url The url for the stored content that should be shown.
     * @param nativePaintPreviewServiceProvider The native paint preview service.
     * @param directoryKey The key for the directory storing the data.
     * @param linkClickHandler Called with a url to trigger a navigation.
     * @param refreshCallback Called when the paint preview should be refreshed.
     * @param viewReadyCallback Called when the view is ready. Will not be called if compositorError
     *     is called prior to the view being ready.
     * @param backgroundColor The color used for the background.
     * @param compositorErrorCallback Called when the compositor has had an error (either during
     *     initialization or due to a disconnect).
     */
    public PlayerManager(GURL url, Context context,
            NativePaintPreviewServiceProvider nativePaintPreviewServiceProvider,
            String directoryKey, @Nonnull LinkClickHandler linkClickHandler,
            @Nullable Runnable refreshCallback, Runnable viewReadyCallback, int backgroundColor,
            Runnable compositorErrorCallback) {
        TraceEvent.startAsync(sInitEvent, hashCode());
        mContext = context;
        mDelegate = new PlayerCompositorDelegateImpl(nativePaintPreviewServiceProvider, url,
                directoryKey, this::onCompositorReady, linkClickHandler, compositorErrorCallback);
        mHostView = new FrameLayout(mContext);
        if (refreshCallback != null) {
            mPlayerSwipeRefreshHandler = new PlayerSwipeRefreshHandler(mContext, refreshCallback);
        }
        mHostView.setLayoutParams(
                new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
        mHostView.setBackgroundColor(backgroundColor);
        mViewReadyCallback = viewReadyCallback;
    }

    /**
     * Called by {@link PlayerCompositorDelegateImpl} when the compositor is initialized. This
     * method initializes a sub-component for each frame and adds the view for the root frame to
     * {@link #mHostView}.
     */
    private void onCompositorReady(UnguessableToken rootFrameGuid, UnguessableToken[] frameGuids,
            int[] frameContentSize, int[] subFramesCount, UnguessableToken[] subFrameGuids,
            int[] subFrameClipRects) {
        PaintPreviewFrame rootFrame = buildFrameTreeHierarchy(rootFrameGuid, frameGuids,
                frameContentSize, subFramesCount, subFrameGuids, subFrameClipRects);

        mRootFrameCoordinator = new PlayerFrameCoordinator(mContext, mDelegate, rootFrame.getGuid(),
                rootFrame.getContentWidth(), rootFrame.getContentHeight(), true,
                mPlayerSwipeRefreshHandler);
        buildSubFrameCoordinators(mRootFrameCoordinator, rootFrame);
        mHostView.addView(mRootFrameCoordinator.getView(),
                new FrameLayout.LayoutParams(
                        ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
        if (mPlayerSwipeRefreshHandler != null) {
            mHostView.addView(mPlayerSwipeRefreshHandler.getView());
        }
        TraceEvent.finishAsync(sInitEvent, hashCode());
        mViewReadyCallback.run();
    }

    /**
     * This method builds a hierarchy of {@link PaintPreviewFrame}s from primitive variables that
     * originate from native. Detailed explanation of the parameters can be found in {@link
     * PlayerCompositorDelegateImpl#onCompositorReady}.
     *
     * @return The root {@link PaintPreviewFrame}
     */
    @VisibleForTesting
    static PaintPreviewFrame buildFrameTreeHierarchy(UnguessableToken rootFrameGuid,
            UnguessableToken[] frameGuids, int[] frameContentSize, int[] subFramesCount,
            UnguessableToken[] subFrameGuids, int[] subFrameClipRects) {
        Map<UnguessableToken, PaintPreviewFrame> framesMap = new HashMap<>();
        for (int i = 0; i < frameGuids.length; i++) {
            framesMap.put(frameGuids[i],
                    new PaintPreviewFrame(
                            frameGuids[i], frameContentSize[i * 2], frameContentSize[(i * 2) + 1]));
        }

        int subFrameIdIndex = 0;
        for (int i = 0; i < frameGuids.length; i++) {
            PaintPreviewFrame currentFrame = framesMap.get(frameGuids[i]);
            int currentFrameSubFrameCount = subFramesCount[i];
            PaintPreviewFrame[] subFrames = new PaintPreviewFrame[currentFrameSubFrameCount];
            Rect[] subFrameClips = new Rect[currentFrameSubFrameCount];
            for (int subFrameIndex = 0; subFrameIndex < currentFrameSubFrameCount;
                    subFrameIndex++, subFrameIdIndex++) {
                subFrames[subFrameIndex] = framesMap.get(subFrameGuids[subFrameIdIndex]);
                int x = subFrameClipRects[subFrameIdIndex * 4];
                int y = subFrameClipRects[subFrameIdIndex * 4 + 1];
                int width = subFrameClipRects[subFrameIdIndex * 4 + 2];
                int height = subFrameClipRects[subFrameIdIndex * 4 + 3];
                subFrameClips[subFrameIndex] = new Rect(x, y, x + width, y + height);
            }
            currentFrame.setSubFrames(subFrames);
            currentFrame.setSubFrameClips(subFrameClips);
        }
        return framesMap.get(rootFrameGuid);
    }

    /**
     * Recursively builds {@link PlayerFrameCoordinator}s for the sub-frames of the given frame and
     * adds them to the given frameCoordinator.
     */
    private void buildSubFrameCoordinators(
            PlayerFrameCoordinator frameCoordinator, PaintPreviewFrame frame) {
        if (frame.getSubFrames() == null || frame.getSubFrames().length == 0) {
            return;
        }

        for (int i = 0; i < frame.getSubFrames().length; i++) {
            PaintPreviewFrame childFrame = frame.getSubFrames()[i];
            PlayerFrameCoordinator childCoordinator = new PlayerFrameCoordinator(mContext,
                    mDelegate, childFrame.getGuid(), childFrame.getContentWidth(),
                    childFrame.getContentHeight(), false, null);
            buildSubFrameCoordinators(childCoordinator, childFrame);
            frameCoordinator.addSubFrame(childCoordinator, frame.getSubFrameClips()[i]);
        }
    }

    public void destroy() {
        if (mDelegate != null) {
            mDelegate.destroy();
            mDelegate = null;
        }
    }

    public View getView() {
        return mHostView;
    }
}
