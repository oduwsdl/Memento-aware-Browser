// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.weblayer_private;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.Nullable;
import androidx.annotation.VisibleForTesting;

import org.chromium.base.ObserverList;
import org.chromium.base.annotations.CalledByNative;
import org.chromium.base.annotations.JNINamespace;
import org.chromium.base.annotations.NativeMethods;
import org.chromium.chrome.browser.infobar.InfoBarIdentifier;
import org.chromium.content_public.browser.WebContents;
import org.chromium.ui.KeyboardVisibilityDelegate.KeyboardVisibilityListener;

import java.util.ArrayList;

/**
 * A container for all the infobars of a specific tab.
 * Note that infobars creation can be initiated from Java or from native code.
 * When initiated from native code, special code is needed to keep the Java and native infobar in
 * sync, see NativeInfoBar.
 */
@JNINamespace("weblayer")
public class InfoBarContainer implements KeyboardVisibilityListener, InfoBar.Container {
    private static final String TAG = "InfoBarContainer";

    // TODO(crbug.com/1025620): Port over //chrome's listening to AccessibilityUtil if/as needed.

    /**
     * A listener for the InfoBar animations.
     */
    public interface InfoBarAnimationListener {
        public static final int ANIMATION_TYPE_SHOW = 0;
        public static final int ANIMATION_TYPE_SWAP = 1;
        public static final int ANIMATION_TYPE_HIDE = 2;

        /**
         * Notifies the subscriber when an animation is completed.
         */
        void notifyAnimationFinished(int animationType);

        /**
         * Notifies the subscriber when all animations are finished.
         * @param frontInfoBar The frontmost infobar or {@code null} if none are showing.
         */
        void notifyAllAnimationsFinished(InfoBarUiItem frontInfoBar);
    }

    /**
     * An observer that is notified of changes to a {@link InfoBarContainer} object.
     */
    public interface InfoBarContainerObserver {
        /**
         * Called when an {@link InfoBar} is about to be added (before the animation).
         * @param container The notifying {@link InfoBarContainer}
         * @param infoBar An {@link InfoBar} being added
         * @param isFirst Whether the infobar container was empty
         */
        void onAddInfoBar(InfoBarContainer container, InfoBar infoBar, boolean isFirst);

        /**
         * Called when an {@link InfoBar} is about to be removed (before the animation).
         * @param container The notifying {@link InfoBarContainer}
         * @param infoBar An {@link InfoBar} being removed
         * @param isLast Whether the infobar container is going to be empty
         */
        void onRemoveInfoBar(InfoBarContainer container, InfoBar infoBar, boolean isLast);

        /**
         * Called when the InfobarContainer is attached to the window.
         * @param hasInfobars True if infobar container has infobars to show.
         */
        void onInfoBarContainerAttachedToWindow(boolean hasInfobars);

        /**
         * A notification that the shown ratio of the infobar container has changed.
         * @param container The notifying {@link InfoBarContainer}
         * @param shownRatio The shown ratio of the infobar container.
         */
        void onInfoBarContainerShownRatioChanged(InfoBarContainer container, float shownRatio);
    }

    // TODO(crbug.com/1025620): Observe WebContents to reset the state of the InfoBarContainer when
    // the user navigates, a la //chrome's observing of Tab here.

    public void onTabDidGainActive() {
        initializeContainerView(mTab.getBrowser().getContext());
        updateWebContents();
        mInfoBarContainerView.addToParentView();
    }

    public void onTabDidLoseActive() {
        mInfoBarContainerView.removeFromParentView();
        destroyContainerView();
    }

    /** The list of all InfoBars in this container, regardless of whether they've been shown yet. */
    private final ArrayList<InfoBar> mInfoBars = new ArrayList<>();

    private final ObserverList<InfoBarContainerObserver> mObservers = new ObserverList<>();
    private final ObserverList<InfoBarAnimationListener> mAnimationListeners = new ObserverList<>();

    private final InfoBarContainerView.ContainerViewObserver mContainerViewObserver =
            new InfoBarContainerView.ContainerViewObserver() {
                @Override
                public void notifyAnimationFinished(int animationType) {
                    for (InfoBarAnimationListener listener : mAnimationListeners) {
                        listener.notifyAnimationFinished(animationType);
                    }
                }

                @Override
                public void notifyAllAnimationsFinished(InfoBarUiItem frontInfoBar) {
                    for (InfoBarAnimationListener listener : mAnimationListeners) {
                        listener.notifyAllAnimationsFinished(frontInfoBar);
                    }
                }

                @Override
                public void onShownRatioChanged(float shownFraction) {
                    for (InfoBarContainer.InfoBarContainerObserver observer : mObservers) {
                        observer.onInfoBarContainerShownRatioChanged(
                                InfoBarContainer.this, shownFraction);
                    }
                }
            };

    /** The tab that hosts this infobar container. */
    private final TabImpl mTab;

    /** Native InfoBarContainer pointer which will be set by InfoBarContainerJni.get().init(). */
    private long mNativeInfoBarContainer;

    /** True when this container has been emptied and its native counterpart has been destroyed. */
    private boolean mDestroyed;

    /** Whether or not this View should be hidden. */
    private boolean mIsHidden;

    /**
     * The view for this {@link InfoBarContainer}. It will be null when the {@link Tab} is detached
     * from a {@link ChromeActivity}.
     */
    private @Nullable InfoBarContainerView mInfoBarContainerView;

    InfoBarContainer(TabImpl tab) {
        mTab = tab;

        // Chromium's InfoBarContainer may add an InfoBar immediately during this initialization
        // call, so make sure everything in the InfoBarContainer is completely ready beforehand.
        mNativeInfoBarContainer = InfoBarContainerJni.get().init(InfoBarContainer.this);
    }

    /**
     * Adds an {@link InfoBarContainerObserver}.
     * @param observer The {@link InfoBarContainerObserver} to add.
     */
    public void addObserver(InfoBarContainerObserver observer) {
        mObservers.addObserver(observer);
    }

    /**
     * Removes a {@link InfoBarContainerObserver}.
     * @param observer The {@link InfoBarContainerObserver} to remove.
     */
    public void removeObserver(InfoBarContainerObserver observer) {
        mObservers.removeObserver(observer);
    }

    /**
     * Sets the parent {@link ViewGroup} that contains the {@link InfoBarContainer}.
     */
    public void setParentView(ViewGroup parent) {
        assert mTab.getBrowser().getActiveTab() == mTab;
        if (mInfoBarContainerView != null) mInfoBarContainerView.setParentView(parent);
    }

    @VisibleForTesting
    public void addAnimationListener(InfoBarAnimationListener listener) {
        mAnimationListeners.addObserver(listener);
    }

    /**
     * Removes the passed in {@link InfoBarAnimationListener} from the {@link InfoBarContainer}.
     */
    public void removeAnimationListener(InfoBarAnimationListener listener) {
        mAnimationListeners.removeObserver(listener);
    }

    /**
     * Adds an InfoBar to the view hierarchy.
     * @param infoBar InfoBar to add to the View hierarchy.
     */
    @CalledByNative
    private void addInfoBar(InfoBar infoBar) {
        assert !mDestroyed;
        if (infoBar == null) {
            return;
        }
        if (mInfoBars.contains(infoBar)) {
            assert false : "Trying to add an info bar that has already been added.";
            return;
        }

        infoBar.setContext(mInfoBarContainerView.getContext());
        infoBar.setContainer(this);

        // We notify observers immediately (before the animation starts).
        for (InfoBarContainerObserver observer : mObservers) {
            observer.onAddInfoBar(this, infoBar, mInfoBars.isEmpty());
        }

        assert mInfoBarContainerView != null : "The container view is null when adding an InfoBar";

        // We add the infobar immediately to mInfoBars but we wait for the animation to end to
        // notify it's been added, as tests rely on this notification but expects the infobar view
        // to be available when they get the notification.
        mInfoBars.add(infoBar);

        mInfoBarContainerView.addInfoBar(infoBar);
    }

    @VisibleForTesting
    public View getViewForTesting() {
        return mInfoBarContainerView;
    }

    /**
     * Adds an InfoBar to the view hierarchy.
     * @param infoBar InfoBar to add to the View hierarchy.
     */
    @VisibleForTesting
    public void addInfoBarForTesting(InfoBar infoBar) {
        addInfoBar(infoBar);
    }

    @Override
    public void notifyInfoBarViewChanged() {
        assert !mDestroyed;
        if (mInfoBarContainerView != null) mInfoBarContainerView.notifyInfoBarViewChanged();
    }

    /**
     * Sets the visibility for the {@link InfoBarContainerView}.
     * @param visibility One of {@link View#GONE}, {@link View#INVISIBLE}, or {@link View#VISIBLE}.
     */
    public void setVisibility(int visibility) {
        if (mInfoBarContainerView != null) mInfoBarContainerView.setVisibility(visibility);
    }

    /**
     * @return The visibility of the {@link InfoBarContainerView}.
     */
    public int getVisibility() {
        return mInfoBarContainerView != null ? mInfoBarContainerView.getVisibility() : View.GONE;
    }

    @Override
    public void removeInfoBar(InfoBar infoBar) {
        assert !mDestroyed;

        if (!mInfoBars.remove(infoBar)) {
            assert false : "Trying to remove an InfoBar that is not in this container.";
            return;
        }

        // Notify observers immediately, before any animations begin.
        for (InfoBarContainerObserver observer : mObservers) {
            observer.onRemoveInfoBar(this, infoBar, mInfoBars.isEmpty());
        }

        assert mInfoBarContainerView
                != null : "The container view is null when removing an InfoBar.";
        mInfoBarContainerView.removeInfoBar(infoBar);
    }

    @Override
    public boolean isDestroyed() {
        return mDestroyed;
    }

    public void destroy() {
        destroyContainerView();
        if (mNativeInfoBarContainer != 0) {
            InfoBarContainerJni.get().destroy(mNativeInfoBarContainer, InfoBarContainer.this);
            mNativeInfoBarContainer = 0;
        }
        mDestroyed = true;
    }

    /**
     * @return all of the InfoBars held in this container.
     */
    @VisibleForTesting
    public ArrayList<InfoBar> getInfoBarsForTesting() {
        return mInfoBars;
    }

    /**
     * @return True if the container has any InfoBars.
     */
    @CalledByNative
    public boolean hasInfoBars() {
        return !mInfoBars.isEmpty();
    }

    /**
     * @return InfoBarIdentifier of the InfoBar which is currently at the top of the infobar stack,
     *         or InfoBarIdentifier.INVALID if there are no infobars.
     */
    @CalledByNative
    private @InfoBarIdentifier int getTopInfoBarIdentifier() {
        if (!hasInfoBars()) return InfoBarIdentifier.INVALID;
        return mInfoBars.get(0).getInfoBarIdentifier();
    }

    /**
     * Hides or stops hiding this View.
     *
     * @param isHidden Whether this View is should be hidden.
     */
    public void setHidden(boolean isHidden) {
        mIsHidden = isHidden;
        if (mInfoBarContainerView == null) return;
        mInfoBarContainerView.setHidden(isHidden);
    }

    /**
     * Sets whether the InfoBarContainer is allowed to auto-hide when the user scrolls the page.
     * Expected to be called when Touch Exploration is enabled.
     * @param isAllowed Whether auto-hiding is allowed.
     */
    private static void setIsAllowedToAutoHide(boolean isAllowed) {
        InfoBarContainerView.setIsAllowedToAutoHide(isAllowed);
    }

    // KeyboardVisibilityListener implementation.
    @Override
    public void keyboardVisibilityChanged(boolean isKeyboardShowing) {
        assert mInfoBarContainerView != null;
        boolean isShowing = (mInfoBarContainerView.getVisibility() == View.VISIBLE);
        if (isKeyboardShowing) {
            if (isShowing) {
                mInfoBarContainerView.setVisibility(View.INVISIBLE);
            }
        } else {
            if (!isShowing && !mIsHidden) {
                mInfoBarContainerView.setVisibility(View.VISIBLE);
            }
        }
    }

    private void updateWebContents() {
        // When the tab is detached, we don't update the InfoBarContainer web content so that it
        // stays null until the tab is attached to some ChromeActivity.
        if (mInfoBarContainerView == null) return;
        WebContents webContents = mTab.getWebContents();

        if (webContents != null && webContents != mInfoBarContainerView.getWebContents()) {
            mInfoBarContainerView.setWebContents(webContents);
            if (mNativeInfoBarContainer != 0) {
                InfoBarContainerJni.get().setWebContents(
                        mNativeInfoBarContainer, InfoBarContainer.this, webContents);
            }
        }
    }

    private void initializeContainerView(Context chromeActivity) {
        assert chromeActivity
                != null
            : "ChromeActivity should not be null when initializing InfoBarContainerView";
        mInfoBarContainerView = new InfoBarContainerView(chromeActivity, mContainerViewObserver,
                mTab, /*isTablet=*/!mTab.getBrowser().isWindowOnSmallDevice());

        mInfoBarContainerView.addOnAttachStateChangeListener(
                new View.OnAttachStateChangeListener() {
                    @Override
                    public void onViewAttachedToWindow(View view) {
                        for (InfoBarContainer.InfoBarContainerObserver observer : mObservers) {
                            observer.onInfoBarContainerAttachedToWindow(!mInfoBars.isEmpty());
                        }
                    }

                    @Override
                    public void onViewDetachedFromWindow(View view) {}
                });

        mInfoBarContainerView.setHidden(mIsHidden);
        setParentView(mTab.getBrowser().getViewController().getInfoBarContainerParentView());

        mTab.getBrowser().getWindowAndroid().getKeyboardDelegate().addKeyboardVisibilityListener(
                this);
    }

    private void destroyContainerView() {
        if (mInfoBarContainerView != null) {
            mInfoBarContainerView.setWebContents(null);
            if (mNativeInfoBarContainer != 0) {
                InfoBarContainerJni.get().setWebContents(
                        mNativeInfoBarContainer, InfoBarContainer.this, null);
            }
            mInfoBarContainerView.destroy();
            mInfoBarContainerView = null;
        }

        mTab.getBrowser().getWindowAndroid().getKeyboardDelegate().removeKeyboardVisibilityListener(
                this);
    }

    @Override
    public boolean isFrontInfoBar(InfoBar infoBar) {
        if (mInfoBars.isEmpty()) return false;
        return mInfoBars.get(0) == infoBar;
    }

    /**
     * Returns true if any animations are pending or in progress.
     */
    @VisibleForTesting
    public boolean isAnimating() {
        assert mInfoBarContainerView != null;
        return mInfoBarContainerView.isAnimating();
    }

    /**
     * @return The {@link InfoBarContainerView} this class holds.
     */
    @VisibleForTesting
    public InfoBarContainerView getContainerViewForTesting() {
        return mInfoBarContainerView;
    }

    @NativeMethods
    interface Natives {
        long init(InfoBarContainer caller);
        void setWebContents(long nativeInfoBarContainerAndroid, InfoBarContainer caller,
                WebContents webContents);
        void destroy(long nativeInfoBarContainerAndroid, InfoBarContainer caller);
    }
}
