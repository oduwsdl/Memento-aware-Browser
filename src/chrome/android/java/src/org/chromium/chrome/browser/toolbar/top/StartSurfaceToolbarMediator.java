// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.toolbar.top;

import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.ACCESSIBILITY_ENABLED;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.APP_MENU_BUTTON_HELPER;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.BUTTONS_CLICKABLE;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.IDENTITY_DISC_AT_START;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.IDENTITY_DISC_CLICK_HANDLER;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.IDENTITY_DISC_DESCRIPTION;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.IDENTITY_DISC_IMAGE;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.IDENTITY_DISC_IS_VISIBLE;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.INCOGNITO_STATE_PROVIDER;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.INCOGNITO_SWITCHER_VISIBLE;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.IN_START_SURFACE_MODE;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.IS_INCOGNITO;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.IS_VISIBLE;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.LOGO_IS_VISIBLE;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.NEW_TAB_BUTTON_AT_START;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.NEW_TAB_BUTTON_IS_VISIBLE;
import static org.chromium.chrome.browser.toolbar.top.StartSurfaceToolbarProperties.NEW_TAB_CLICK_HANDLER;

import android.view.View;

import androidx.annotation.VisibleForTesting;

import org.chromium.base.Callback;
import org.chromium.chrome.browser.compositor.layouts.EmptyOverviewModeObserver;
import org.chromium.chrome.browser.compositor.layouts.OverviewModeBehavior;
import org.chromium.chrome.browser.compositor.layouts.OverviewModeBehavior.OverviewModeObserver;
import org.chromium.chrome.browser.compositor.layouts.OverviewModeState;
import org.chromium.chrome.browser.identity_disc.IdentityDiscController;
import org.chromium.chrome.browser.search_engines.TemplateUrlServiceFactory;
import org.chromium.chrome.browser.tabmodel.EmptyTabModelSelectorObserver;
import org.chromium.chrome.browser.tabmodel.TabModel;
import org.chromium.chrome.browser.tabmodel.TabModelSelector;
import org.chromium.chrome.browser.tabmodel.TabModelSelectorObserver;
import org.chromium.chrome.browser.toolbar.ButtonData;
import org.chromium.chrome.browser.toolbar.IncognitoStateProvider;
import org.chromium.chrome.browser.ui.appmenu.AppMenuButtonHelper;
import org.chromium.chrome.browser.user_education.IPHCommandBuilder;
import org.chromium.chrome.browser.util.ChromeAccessibilityUtil;
import org.chromium.components.search_engines.TemplateUrlService.TemplateUrlServiceObserver;
import org.chromium.ui.modelutil.PropertyModel;

/** The mediator implements interacts between the views and the caller. */
class StartSurfaceToolbarMediator {
    private final PropertyModel mPropertyModel;
    private final IdentityDiscController mIdentityDiscController;
    private final Callback<IPHCommandBuilder> mShowIPHCallback;
    private final boolean mHideIncognitoSwitchWhenNoTabs;
    private final boolean mShowNewTabAndIdentityDiscAtStart;

    private TabModelSelector mTabModelSelector;
    private TemplateUrlServiceObserver mTemplateUrlObserver;
    private TabModelSelectorObserver mTabModelSelectorObserver;
    private OverviewModeBehavior mOverviewModeBehavior;
    private OverviewModeObserver mOverviewModeObserver;
    @OverviewModeState
    private int mOverviewModeState;
    private boolean mIsGoogleSearchEngine;

    StartSurfaceToolbarMediator(PropertyModel model, IdentityDiscController identityDiscController,
            Callback<IPHCommandBuilder> showIPHCallback, boolean hideIncognitoSwitchWhenNoTabs,
            boolean showNewTabAndIdentityDiscAtStart) {
        mPropertyModel = model;
        mOverviewModeState = OverviewModeState.NOT_SHOWN;
        mIdentityDiscController = identityDiscController;
        mIdentityDiscController.addObserver(this::identityDiscStateChanged);
        mShowIPHCallback = showIPHCallback;
        mHideIncognitoSwitchWhenNoTabs = hideIncognitoSwitchWhenNoTabs;
        mShowNewTabAndIdentityDiscAtStart = showNewTabAndIdentityDiscAtStart;
    }

    void onNativeLibraryReady() {
        assert mTemplateUrlObserver == null;

        mTemplateUrlObserver = new TemplateUrlServiceObserver() {
            @Override
            public void onTemplateURLServiceChanged() {
                updateLogoVisibility(TemplateUrlServiceFactory.get().isDefaultSearchEngineGoogle());
            }
        };

        TemplateUrlServiceFactory.get().addObserver(mTemplateUrlObserver);
        mIsGoogleSearchEngine = TemplateUrlServiceFactory.get().isDefaultSearchEngineGoogle();
        updateLogoVisibility(TemplateUrlServiceFactory.get().isDefaultSearchEngineGoogle());
    }

    void destroy() {
        if (mTemplateUrlObserver != null) {
            TemplateUrlServiceFactory.get().removeObserver(mTemplateUrlObserver);
        }
        if (mTabModelSelectorObserver != null) {
            mTabModelSelector.removeObserver(mTabModelSelectorObserver);
        }
        if (mOverviewModeObserver != null) {
            mOverviewModeBehavior.removeOverviewModeObserver(mOverviewModeObserver);
        }
    }

    void setAppMenuButtonHelper(AppMenuButtonHelper appMenuButtonHelper) {
        mPropertyModel.set(APP_MENU_BUTTON_HELPER, appMenuButtonHelper);
    }

    void setOnNewTabClickHandler(View.OnClickListener listener) {
        mPropertyModel.set(NEW_TAB_CLICK_HANDLER, listener);
    }

    void setTabModelSelector(TabModelSelector selector) {
        mTabModelSelector = selector;

        if (mTabModelSelectorObserver == null) {
            mTabModelSelectorObserver = new EmptyTabModelSelectorObserver() {
                @Override
                public void onTabModelSelected(TabModel newModel, TabModel oldModel) {
                    mPropertyModel.set(IS_INCOGNITO, mTabModelSelector.isIncognitoSelected());
                    updateIdentityDisc(
                            mIdentityDiscController.getForStartSurface(mOverviewModeState));
                    if (mHideIncognitoSwitchWhenNoTabs) {
                        mPropertyModel.set(INCOGNITO_SWITCHER_VISIBLE, hasIncognitoTabs());
                    }
                }
            };
        }
        mPropertyModel.set(IS_INCOGNITO, mTabModelSelector.isIncognitoSelected());
        updateIdentityDisc(mIdentityDiscController.getForStartSurface(mOverviewModeState));
        mTabModelSelector.addObserver(mTabModelSelectorObserver);
    }

    // TODO(crbug.com/1042997): share with TabSwitcherModeTTPhone.
    private boolean hasIncognitoTabs() {
        if (mTabModelSelector == null) return false;

        // Check if there is no incognito tab, or all the incognito tabs are being closed.
        TabModel incognitoTabModel = mTabModelSelector.getModel(true);
        for (int i = 0; i < incognitoTabModel.getCount(); i++) {
            if (!incognitoTabModel.getTabAt(i).isClosing()) return true;
        }
        return false;
    }

    void setStartSurfaceMode(boolean inStartSurfaceMode) {
        mPropertyModel.set(IN_START_SURFACE_MODE, inStartSurfaceMode);
    }

    void setStartSurfaceToolbarVisibility(boolean shouldShowStartSurfaceToolbar) {
        mPropertyModel.set(IS_VISIBLE, shouldShowStartSurfaceToolbar);
    }

    void setIncognitoStateProvider(IncognitoStateProvider provider) {
        mPropertyModel.set(INCOGNITO_STATE_PROVIDER, provider);
    }

    void onAccessibilityStatusChanged(boolean enabled) {
        mPropertyModel.set(ACCESSIBILITY_ENABLED, enabled);
        updateNewTabButtonVisibility();
    }

    void onBottomToolbarVisibilityChanged(boolean isVisible) {}

    void setOverviewModeBehavior(OverviewModeBehavior overviewModeBehavior) {
        assert overviewModeBehavior != null;
        assert mOverviewModeBehavior
                == null
            : "TODO(https://crbug.com/1084528): the overview mode manager should set at most once.";

        mOverviewModeBehavior = overviewModeBehavior;
        mOverviewModeObserver = new EmptyOverviewModeObserver() {
            @Override
            public void onOverviewModeStateChanged(
                    @OverviewModeState int overviewModeState, boolean showTabSwitcherToolbar) {
                mOverviewModeState = overviewModeState;
                updateNewTabButtonVisibility();
                updateLogoVisibility(mIsGoogleSearchEngine);
                updateIdentityDisc(mIdentityDiscController.getForStartSurface(mOverviewModeState));
            }
            @Override
            public void onOverviewModeStartedShowing(boolean showToolbar) {
                if (mHideIncognitoSwitchWhenNoTabs) {
                    mPropertyModel.set(INCOGNITO_SWITCHER_VISIBLE, hasIncognitoTabs());
                }
                if (mOverviewModeState == OverviewModeState.SHOWN_TABSWITCHER_OMNIBOX_ONLY
                        || mShowNewTabAndIdentityDiscAtStart) {
                    mPropertyModel.set(NEW_TAB_BUTTON_AT_START, true);
                }
                if (mShowNewTabAndIdentityDiscAtStart) {
                    mPropertyModel.set(IDENTITY_DISC_AT_START, true);
                }
            }
            @Override
            public void onOverviewModeFinishedShowing() {
                mPropertyModel.set(BUTTONS_CLICKABLE, true);
            }
            @Override
            public void onOverviewModeStartedHiding(boolean showToolbar, boolean delayAnimation) {
                mPropertyModel.set(BUTTONS_CLICKABLE, false);
            }
        };
        mOverviewModeBehavior.addOverviewModeObserver(mOverviewModeObserver);
    }

    private void updateLogoVisibility(boolean isGoogleSearchEngine) {
        mIsGoogleSearchEngine = isGoogleSearchEngine;
        boolean shouldShowLogo =
                (mOverviewModeState == OverviewModeState.SHOWN_HOMEPAGE
                        || mOverviewModeState == OverviewModeState.SHOWN_TABSWITCHER_TASKS_ONLY
                        || mOverviewModeState == OverviewModeState.SHOWN_TABSWITCHER_OMNIBOX_ONLY)
                && mIsGoogleSearchEngine;
        mPropertyModel.set(LOGO_IS_VISIBLE, shouldShowLogo);
    }

    @VisibleForTesting
    void identityDiscStateChanged(boolean canShowHint) {
        // If the identity disc wants to be hidden and is hidden, there's nothing we need to do.
        if (!canShowHint && !mPropertyModel.get(IDENTITY_DISC_IS_VISIBLE)) return;
        updateIdentityDisc(mIdentityDiscController.getForStartSurface(mOverviewModeState));
    }

    @VisibleForTesting
    void updateIdentityDisc(ButtonData buttonData) {
        boolean shouldShow = buttonData.canShow && !mTabModelSelector.isIncognitoSelected();
        if (shouldShow) {
            mPropertyModel.set(IDENTITY_DISC_CLICK_HANDLER, buttonData.onClickListener);
            // Take a defensive copy of the Drawable, since Drawables aren't immutable, and another
            // view mutating our drawable could cause it to display incorrectly.
            mPropertyModel.set(
                    IDENTITY_DISC_IMAGE, buttonData.drawable.getConstantState().newDrawable());
            mPropertyModel.set(IDENTITY_DISC_DESCRIPTION, buttonData.contentDescriptionResId);
            mPropertyModel.set(IDENTITY_DISC_IS_VISIBLE, true);
            mShowIPHCallback.onResult(buttonData.iphCommandBuilder);
        } else {
            mPropertyModel.set(IDENTITY_DISC_IS_VISIBLE, false);
        }
    }

    private void updateNewTabButtonVisibility() {
        // This toolbar is only shown for tab switcher when accessibility is enabled. Note that
        // OverviewListLayout will be shown as the tab switcher instead of the star surface.
        boolean isShownTabswitcherState = mOverviewModeState == OverviewModeState.SHOWN_TABSWITCHER
                || mOverviewModeState == OverviewModeState.SHOWN_TABSWITCHER_TASKS_ONLY
                || mOverviewModeState == OverviewModeState.SHOWN_TABSWITCHER_OMNIBOX_ONLY
                || ChromeAccessibilityUtil.get().isAccessibilityEnabled();
        mPropertyModel.set(NEW_TAB_BUTTON_IS_VISIBLE, isShownTabswitcherState);
    }
}
