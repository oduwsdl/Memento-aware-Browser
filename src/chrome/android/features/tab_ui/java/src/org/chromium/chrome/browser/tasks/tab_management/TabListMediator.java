// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.tasks.tab_management;

import static org.chromium.chrome.browser.tasks.tab_management.MessageCardViewProperties.MESSAGE_TYPE;
import static org.chromium.chrome.browser.tasks.tab_management.TabListModel.CardProperties.CARD_ALPHA;
import static org.chromium.chrome.browser.tasks.tab_management.TabListModel.CardProperties.CARD_TYPE;
import static org.chromium.chrome.browser.tasks.tab_management.TabListModel.CardProperties.ModelType.TAB;

import android.app.Activity;
import android.content.ComponentCallbacks;
import android.content.Context;
import android.content.res.ColorStateList;
import android.content.res.Configuration;
import android.graphics.Bitmap;
import android.graphics.drawable.Drawable;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.text.TextUtils;
import android.util.Pair;
import android.view.View;
import android.view.accessibility.AccessibilityNodeInfo;
import android.view.accessibility.AccessibilityNodeInfo.AccessibilityAction;

import androidx.annotation.IntDef;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.VisibleForTesting;
import androidx.appcompat.content.res.AppCompatResources;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.ItemTouchHelper;

import org.chromium.base.Callback;
import org.chromium.base.Log;
import org.chromium.base.metrics.RecordHistogram;
import org.chromium.base.metrics.RecordUserAction;
import org.chromium.base.task.PostTask;
import org.chromium.chrome.browser.compositor.layouts.content.TabContentManager;
import org.chromium.chrome.browser.multiwindow.MultiWindowUtils;
import org.chromium.chrome.browser.native_page.NativePageFactory;
import org.chromium.chrome.browser.profiles.Profile;
import org.chromium.chrome.browser.search_engines.TemplateUrlServiceFactory;
import org.chromium.chrome.browser.tab.EmptyTabObserver;
import org.chromium.chrome.browser.tab.Tab;
import org.chromium.chrome.browser.tab.TabCreationState;
import org.chromium.chrome.browser.tab.TabLaunchType;
import org.chromium.chrome.browser.tab.TabObserver;
import org.chromium.chrome.browser.tab.TabSelectionType;
import org.chromium.chrome.browser.tabmodel.EmptyTabModelFilter;
import org.chromium.chrome.browser.tabmodel.TabList;
import org.chromium.chrome.browser.tabmodel.TabModel;
import org.chromium.chrome.browser.tabmodel.TabModelFilter;
import org.chromium.chrome.browser.tabmodel.TabModelObserver;
import org.chromium.chrome.browser.tabmodel.TabModelSelector;
import org.chromium.chrome.browser.tabmodel.TabModelUtils;
import org.chromium.chrome.browser.tasks.pseudotab.PseudoTab;
import org.chromium.chrome.browser.tasks.pseudotab.TabAttributeCache;
import org.chromium.chrome.browser.tasks.tab_groups.EmptyTabGroupModelFilterObserver;
import org.chromium.chrome.browser.tasks.tab_groups.TabGroupModelFilter;
import org.chromium.chrome.browser.tasks.tab_groups.TabGroupUtils;
import org.chromium.chrome.browser.tasks.tab_management.TabProperties.UiType;
import org.chromium.chrome.tab_ui.R;
import org.chromium.components.browser_ui.widget.selectable_list.SelectionDelegate;
import org.chromium.components.embedder_support.util.UrlUtilities;
import org.chromium.components.feature_engagement.FeatureConstants;
import org.chromium.components.search_engines.TemplateUrlService;
import org.chromium.content_public.browser.LoadUrlParams;
import org.chromium.content_public.browser.NavigationController;
import org.chromium.content_public.browser.NavigationHandle;
import org.chromium.content_public.browser.NavigationHistory;
import org.chromium.content_public.browser.UiThreadTaskTraits;
import org.chromium.ui.base.PageTransition;
import org.chromium.ui.modelutil.PropertyModel;
import org.chromium.ui.modelutil.SimpleRecyclerViewAdapter;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Mediator for business logic for the tab grid. This class should be initialized with a list of
 * tabs and a TabModel to observe for changes and should not have any logic around what the list
 * signifies.
 * TODO(yusufo): Move some of the logic here to a parent component to make the above true.
 */
class TabListMediator {
    // Comparator to sort Tabs in descending order of the last shown time.
    private static final Comparator<PseudoTab> LAST_SHOWN_COMPARATOR =
            (a, b) -> (Long.compare(b.getTimestampMillis(), a.getTimestampMillis()));

    private boolean mVisible;
    private boolean mShownIPH;

    /**
     * An interface to get the thumbnails to be shown inside the tab grid cards.
     */
    public interface ThumbnailProvider {
        /**
         * @see TabContentManager#getTabThumbnailWithCallback
         */
        void getTabThumbnailWithCallback(
                int tabId, Callback<Bitmap> callback, boolean forceUpdate, boolean writeToCache);
    }

    /**
     * An interface to handle requests about updating TabGridDialog.
     */
    public interface TabGridDialogHandler {
        /**
         * This method updates the status of the ungroup bar in TabGridDialog.
         *
         * @param status The status in {@link TabGridDialogView.UngroupBarStatus} that the ungroup
         *         bar should be updated to.
         */
        void updateUngroupBarStatus(@TabGridDialogView.UngroupBarStatus int status);

        /**
         * This method updates the content of the TabGridDialog.
         *
         * @param tabId The id of the {@link Tab} that is used to update TabGridDialog.
         */
        void updateDialogContent(int tabId);
    }

    /**
     * An interface to expose functionality needed to support reordering in grid layouts in
     * accessibility mode.
     */
    public interface TabGridAccessibilityHelper {
        /**
         * This method gets the possible actions for reordering a tab in grid layout.
         *
         * @param view The host view that triggers the accessibility action.
         * @return The list of possible {@link AccessibilityAction}s for host view.
         */
        List<AccessibilityAction> getPotentialActionsForView(View view);

        /**
         * This method gives the previous and target position of current reordering based on the
         * host view and current action.
         *
         * @param view   The host view that triggers the accessibility action.
         * @param action The id of the action.
         * @return {@link Pair} that contains previous and target position of this action.
         */
        Pair<Integer, Integer> getPositionsOfReorderAction(View view, int action);

        /**
         * This method returns whether the given action is a type of the reordering actions.
         *
         * @param action The accessibility action.
         * @return Whether the given action is a reordering action.
         */
        boolean isReorderAction(int action);
    }

    /**
     * The object to set to {@link TabProperties#THUMBNAIL_FETCHER} for the TabGridViewBinder to
     * obtain the thumbnail asynchronously.
     */
    static class ThumbnailFetcher {
        static Callback<Bitmap> sBitmapCallbackForTesting;
        static int sFetchCountForTesting;
        private ThumbnailProvider mThumbnailProvider;
        private int mId;
        private boolean mForceUpdate;
        private boolean mWriteToCache;

        ThumbnailFetcher(
                ThumbnailProvider provider, int id, boolean forceUpdate, boolean writeToCache) {
            mThumbnailProvider = provider;
            mId = id;
            mForceUpdate = forceUpdate;
            mWriteToCache = writeToCache;
        }

        void fetch(Callback<Bitmap> callback) {
            Callback<Bitmap> forking = (bitmap) -> {
                if (sBitmapCallbackForTesting != null) sBitmapCallbackForTesting.onResult(bitmap);
                callback.onResult(bitmap);
            };
            sFetchCountForTesting++;
            mThumbnailProvider.getTabThumbnailWithCallback(
                    mId, forking, mForceUpdate, mWriteToCache);
        }
    }

    /**
     * An interface to show IPH for a tab.
     */
    public interface IphProvider { void showIPH(View anchor); }

    private final IphProvider mIphProvider = new IphProvider() {
        private static final int IPH_DELAY_MS = 1000;

        @Override
        public void showIPH(View anchor) {
            if (mShownIPH) return;
            mShownIPH = true;

            new Handler().postDelayed(
                    ()
                            -> TabGroupUtils.maybeShowIPH(
                                    FeatureConstants.TAB_GROUPS_YOUR_TABS_ARE_TOGETHER_FEATURE,
                                    anchor),
                    IPH_DELAY_MS);
        }
    };

    /**
     * An interface to get a SelectionDelegate that contains the selected items for a selectable
     * tab list.
     */
    public interface SelectionDelegateProvider { SelectionDelegate getSelectionDelegate(); }

    /**
     * An interface to get the onClickListener when clicking on a grid card.
     */
    interface GridCardOnClickListenerProvider {
        /**
         * @return {@link TabActionListener} to open Tab Grid dialog.
         * If the given {@link Tab} is not able to create group, return null;
         */
        @Nullable
        TabActionListener openTabGridDialog(@NonNull Tab tab);

        /**
         * Run additional actions on tab selection.
         * @param tabId The ID of selected {@link Tab}.
         */
        void onTabSelecting(int tabId);
    }

    @IntDef({TabClosedFrom.TAB_STRIP, TabClosedFrom.GRID_TAB_SWITCHER,
            TabClosedFrom.GRID_TAB_SWITCHER_GROUP})
    @Retention(RetentionPolicy.SOURCE)
    private @interface TabClosedFrom {
        int TAB_STRIP = 0;
        // int TAB_GRID_SHEET = 1;  // Obsolete
        int GRID_TAB_SWITCHER = 2;
        int GRID_TAB_SWITCHER_GROUP = 3;
        int NUM_ENTRIES = 4;
    }

    private static final String TAG = "TabListMediator";
    private static Map<Integer, Integer> sTabClosedFromMapTabClosedFromMap = new HashMap<>();

    private final Context mContext;
    private final TabListModel mModel;
    private final TabModelSelector mTabModelSelector;
    private final TabActionListener mTabClosedListener;
    private final PseudoTab.TitleProvider mTitleProvider;
    private final SelectionDelegateProvider mSelectionDelegateProvider;
    private final GridCardOnClickListenerProvider mGridCardOnClickListenerProvider;
    private final TabGridDialogHandler mTabGridDialogHandler;
    private final String mComponentName;
    private final TabListFaviconProvider mTabListFaviconProvider;

    private ThumbnailProvider mThumbnailProvider;
    private boolean mActionsOnAllRelatedTabs;
    private ComponentCallbacks mComponentCallbacks;
    private TabGridItemTouchHelperCallback mTabGridItemTouchHelperCallback;
    private int mNextTabId = Tab.INVALID_TAB_ID;
    private @UiType int mUiType;
    private int mSearchChipIconDrawableId;

    private final TabActionListener mTabSelectedListener = new TabActionListener() {
        @Override
        public void run(int tabId) {
            if (mModel.indexFromId(tabId) == TabModel.INVALID_TAB_INDEX) return;

            mNextTabId = tabId;

            if (!mActionsOnAllRelatedTabs || TabUiFeatureUtilities.isConditionalTabStripEnabled()) {
                Tab currentTab = mTabModelSelector.getCurrentTab();
                Tab newlySelectedTab =
                        TabModelUtils.getTabById(mTabModelSelector.getCurrentModel(), tabId);

                // We filtered the tab switching related metric for components that takes actions on
                // all related tabs (e.g. GTS) because that component can switch to different
                // TabModel before switching tabs, while this class only contains information for
                // all tabs that are in the same TabModel, more specifically:
                //   * For Tabs.TabOffsetOfSwitch, we do not want to log anything if the user
                //     switched from normal to incognito or vice-versa.
                //   * For MobileTabSwitched, as compared to the VTS, we need to account for
                //     MobileTabReturnedToCurrentTab action. This action is defined as return to the
                //     same tab as before entering the component, and we don't have this information
                //     here.
                recordUserSwitchedTab(currentTab, newlySelectedTab);
            }
            if (mGridCardOnClickListenerProvider != null) {
                mGridCardOnClickListenerProvider.onTabSelecting(tabId);
            } else {
                mTabModelSelector.getCurrentModel().setIndex(
                        TabModelUtils.getTabIndexById(mTabModelSelector.getCurrentModel(), tabId),
                        TabSelectionType.FROM_USER);
            }
        }

        /**
         * Records MobileTabSwitched for the component. Also, records Tabs.TabOffsetOfSwitch but
         * only when fromTab and toTab are within the same group. This method only records UMA
         * for components other than TabSwitcher.
         *
         * @param fromTab The previous selected tab.
         * @param toTab The new selected tab.
         */
        private void recordUserSwitchedTab(Tab fromTab, Tab toTab) {
            int fromFilterIndex = mTabModelSelector.getTabModelFilterProvider()
                                          .getCurrentTabModelFilter()
                                          .indexOf(fromTab);
            int toFilterIndex = mTabModelSelector.getTabModelFilterProvider()
                                        .getCurrentTabModelFilter()
                                        .indexOf(toTab);

            RecordUserAction.record("MobileTabSwitched." + mComponentName);
            if (TabUiFeatureUtilities.isConditionalTabStripEnabled()) {
                assert fromFilterIndex != toFilterIndex;
                RecordHistogram.recordSparseHistogram("Tabs.TabOffsetOfSwitch." + mComponentName,
                        fromFilterIndex - toFilterIndex);
                return;
            }

            if (fromFilterIndex != toFilterIndex) return;

            int fromIndex = TabModelUtils.getTabIndexById(
                    mTabModelSelector.getCurrentModel(), fromTab.getId());
            int toIndex = TabModelUtils.getTabIndexById(
                    mTabModelSelector.getCurrentModel(), toTab.getId());

            RecordHistogram.recordSparseHistogram(
                    "Tabs.TabOffsetOfSwitch." + mComponentName, fromIndex - toIndex);
        }
    };

    private final TabActionListener mSelectableTabOnClickListener = new TabActionListener() {
        @Override
        public void run(int tabId) {
            int index = mModel.indexFromId(tabId);
            if (index == TabModel.INVALID_TAB_INDEX) return;
            boolean selected = mModel.get(index).model.get(TabProperties.IS_SELECTED);
            if (selected) {
                RecordUserAction.record("TabMultiSelect.TabUnselected");
            } else {
                RecordUserAction.record("TabMultiSelect.TabSelected");
            }
            mModel.get(index).model.set(TabProperties.IS_SELECTED, !selected);
        }
    };

    private final TabObserver mTabObserver = new EmptyTabObserver() {
        @Override
        public void onDidStartNavigation(Tab tab, NavigationHandle navigationHandle) {
            if (NativePageFactory.isNativePageUrl(tab.getUrlString(), tab.isIncognito())) return;
            if (navigationHandle.isSameDocument() || !navigationHandle.isInMainFrame()) return;
            if (mModel.indexFromId(tab.getId()) == TabModel.INVALID_TAB_INDEX) return;
            mModel.get(mModel.indexFromId(tab.getId()))
                    .model.set(TabProperties.FAVICON,
                            mTabListFaviconProvider.getDefaultFaviconDrawable(tab.isIncognito()));
        }

        @Override
        public void onTitleUpdated(Tab updatedTab) {
            int index = mModel.indexFromId(updatedTab.getId());
            if (index == TabModel.INVALID_TAB_INDEX) return;
            mModel.get(index).model.set(
                    TabProperties.TITLE, getLatestTitleForTab(PseudoTab.fromTab(updatedTab)));
        }

        @Override
        public void onFaviconUpdated(Tab updatedTab, Bitmap icon) {
            updateFaviconForTab(PseudoTab.fromTab(updatedTab), icon);
        }

        @Override
        public void onUrlUpdated(Tab tab) {
            if (!TabUiFeatureUtilities.isTabGroupsAndroidContinuationEnabled()) return;
            int index = mModel.indexFromId(tab.getId());

            if (index == TabModel.INVALID_TAB_INDEX && mActionsOnAllRelatedTabs) {
                Tab currentGroupSelectedTab =
                        TabGroupUtils.getSelectedTabInGroupForTab(mTabModelSelector, tab);
                if (currentGroupSelectedTab == null) return;
                index = mModel.indexFromId(currentGroupSelectedTab.getId());
            }

            if (index == TabModel.INVALID_TAB_INDEX) return;
            mModel.get(index).model.set(TabProperties.URL_DOMAIN, getDomainForTab(tab));
        }
    };

    private final TabModelObserver mTabModelObserver;

    private @Nullable TemplateUrlService.TemplateUrlServiceObserver mTemplateUrlObserver;

    private TabGroupTitleEditor mTabGroupTitleEditor;

    private TabGroupModelFilter.Observer mTabGroupObserver;

    private View.AccessibilityDelegate mAccessibilityDelegate;

    /**
     * Interface for implementing a {@link Runnable} that takes a tabId for a generic action.
     */
    public interface TabActionListener { void run(int tabId); }

    /**
     * Construct the Mediator with the given Models and observing hooks from the given
     * ChromeActivity.
     * @param context The context used to get some configuration information.
     * @param model The Model to keep state about a list of {@link Tab}s.
     * @param tabModelSelector {@link TabModelSelector} that will provide and receive signals about
     *                                                 the tabs concerned.
     * @param thumbnailProvider {@link ThumbnailProvider} to provide screenshot related details.
     * @param titleProvider {@link PseudoTab.TitleProvider} for a given tab's title to show.
     * @param tabListFaviconProvider Provider for all favicon related drawables.
     * @param actionOnRelatedTabs Whether tab-related actions should be operated on all related
     *                            tabs.
     * @param selectionDelegateProvider Provider for a {@link SelectionDelegate} that is used for
     *                                  a selectable list. It's null when selection is not possible.
     * @param gridCardOnClickListenerProvider Provides the onClickListener for opening dialog when
     *                                        click on a grid card.
     * @param dialogHandler A handler to handle requests about updating TabGridDialog.
     * @param componentName This is a unique string to identify different components.
     * @param uiType The type of UI this mediator should be building.
     */
    public TabListMediator(Context context, TabListModel model, TabModelSelector tabModelSelector,
            @Nullable ThumbnailProvider thumbnailProvider,
            @Nullable PseudoTab.TitleProvider titleProvider,
            TabListFaviconProvider tabListFaviconProvider, boolean actionOnRelatedTabs,
            @Nullable SelectionDelegateProvider selectionDelegateProvider,
            @Nullable GridCardOnClickListenerProvider gridCardOnClickListenerProvider,
            @Nullable TabGridDialogHandler dialogHandler, String componentName,
            @UiType int uiType) {
        mContext = context;
        mTabModelSelector = tabModelSelector;
        mThumbnailProvider = thumbnailProvider;
        mModel = model;
        mTabListFaviconProvider = tabListFaviconProvider;
        mComponentName = componentName;
        mTitleProvider = titleProvider;
        mSelectionDelegateProvider = selectionDelegateProvider;
        mGridCardOnClickListenerProvider = gridCardOnClickListenerProvider;
        mTabGridDialogHandler = dialogHandler;
        mActionsOnAllRelatedTabs = actionOnRelatedTabs;
        mUiType = uiType;

        mTabModelObserver = new TabModelObserver() {
            @Override
            public void didSelectTab(Tab tab, int type, int lastId) {
                mNextTabId = Tab.INVALID_TAB_ID;
                if (tab.getId() == lastId) return;
                int oldIndex = mModel.indexFromId(lastId);
                if (oldIndex != TabModel.INVALID_TAB_INDEX) {
                    mModel.get(oldIndex).model.set(TabProperties.IS_SELECTED, false);
                }
                int newIndex = mModel.indexFromId(tab.getId());
                if (newIndex == TabModel.INVALID_TAB_INDEX) return;

                mModel.get(newIndex).model.set(TabProperties.IS_SELECTED, true);
            }

            @Override
            public void tabClosureUndone(Tab tab) {
                onTabAdded(tab, !mActionsOnAllRelatedTabs);
                if (TabUiFeatureUtilities.isConditionalTabStripEnabled()) {
                    mTabModelSelector.getCurrentModel().setIndex(
                            TabModelUtils.getTabIndexById(
                                    mTabModelSelector.getCurrentModel(), tab.getId()),
                            TabSelectionType.FROM_USER);
                }
                if (sTabClosedFromMapTabClosedFromMap.containsKey(tab.getId())) {
                    @TabClosedFrom
                    int from = sTabClosedFromMapTabClosedFromMap.get(tab.getId());
                    switch (from) {
                        case TabClosedFrom.TAB_STRIP:
                            RecordUserAction.record("TabStrip.UndoCloseTab");
                            break;
                        case TabClosedFrom.GRID_TAB_SWITCHER:
                            RecordUserAction.record("GridTabSwitch.UndoCloseTab");
                            break;
                        case TabClosedFrom.GRID_TAB_SWITCHER_GROUP:
                            RecordUserAction.record("GridTabSwitcher.UndoCloseTabGroup");
                            break;
                        default:
                            assert false
                                : "tabClosureUndone for tab that closed from an unknown UI";
                    }
                    sTabClosedFromMapTabClosedFromMap.remove(tab.getId());
                }
                // TODO(yuezhanggg): clean up updateTab() calls in this class.
                if (mActionsOnAllRelatedTabs) {
                    TabModelFilter filter = mTabModelSelector.getTabModelFilterProvider()
                                                    .getCurrentTabModelFilter();
                    int index = filter.indexOf(tab);
                    if (index == TabList.INVALID_TAB_INDEX
                            || getRelatedTabsForId(tab.getId()).size() == 1
                            || index >= mModel.size()) {
                        return;
                    }
                    Tab currentGroupSelectedTab = filter.getTabAt(index);

                    assert mModel.indexFromId(currentGroupSelectedTab.getId()) == index;

                    updateTab(index, PseudoTab.fromTab(currentGroupSelectedTab),
                            mModel.get(index).model.get(TabProperties.IS_SELECTED), false, false);
                }
            }

            @Override
            public void didAddTab(
                    Tab tab, @TabLaunchType int type, @TabCreationState int creationState) {
                boolean isTabModelRestoreCompleted = mTabModelSelector.getTabModelFilterProvider()
                                                             .getCurrentTabModelFilter()
                                                             .isTabModelRestored();
                if (!isTabModelRestoreCompleted) return;
                onTabAdded(tab, !mActionsOnAllRelatedTabs);
                if (type == TabLaunchType.FROM_RESTORE && mActionsOnAllRelatedTabs) {
                    // When tab is restored after restoring stage (e.g. exiting multi-window mode,
                    // switching between dark/light mode in incognito), we need to update related
                    // property models.
                    TabModelFilter filter = mTabModelSelector.getTabModelFilterProvider()
                                                    .getCurrentTabModelFilter();
                    int index = filter.indexOf(tab);
                    if (index == TabList.INVALID_TAB_INDEX) return;
                    Tab currentGroupSelectedTab = filter.getTabAt(index);
                    // TabModel and TabListModel may be in the process of syncing up through
                    // restoring. Examples of this situation are switching between light/dark mode
                    // in incognito, exiting multi-window mode, etc.
                    if (mModel.indexFromId(currentGroupSelectedTab.getId()) != index) {
                        return;
                    }
                    updateTab(index, PseudoTab.fromTab(currentGroupSelectedTab),
                            mModel.get(index).model.get(TabProperties.IS_SELECTED), false, false);
                }
            }

            @Override
            public void willCloseTab(Tab tab, boolean animate) {
                if (mModel.indexFromId(tab.getId()) == TabModel.INVALID_TAB_INDEX) return;
                tab.removeObserver(mTabObserver);
                mModel.removeAt(mModel.indexFromId(tab.getId()));
            }

            @Override
            public void didMoveTab(Tab tab, int newIndex, int curIndex) {
                if (mTabModelSelector.getTabModelFilterProvider().getCurrentTabModelFilter()
                                instanceof TabGroupModelFilter) {
                    return;
                }
                onTabMoved(newIndex, curIndex);
            }

            @Override
            public void tabRemoved(Tab tab) {
                if (mModel.indexFromId(tab.getId()) == TabModel.INVALID_TAB_INDEX) return;
                mModel.removeAt(mModel.indexFromId(tab.getId()));
            }
        };

        mTabModelSelector.getTabModelFilterProvider().addTabModelFilterObserver(mTabModelObserver);

        if (mTabModelSelector.getTabModelFilterProvider().getCurrentTabModelFilter()
                        instanceof TabGroupModelFilter) {
            mTabGroupObserver = new EmptyTabGroupModelFilterObserver() {
                @Override
                public void didMoveWithinGroup(
                        Tab movedTab, int tabModelOldIndex, int tabModelNewIndex) {
                    if (tabModelNewIndex == tabModelOldIndex) return;

                    int curPosition = mModel.indexFromId(movedTab.getId());
                    TabModel tabModel = mTabModelSelector.getCurrentModel();

                    if (!isValidMovePosition(curPosition)) return;

                    Tab destinationTab = tabModel.getTabAt(tabModelNewIndex > tabModelOldIndex
                                    ? tabModelNewIndex - 1
                                    : tabModelNewIndex + 1);

                    int newPosition = mModel.indexFromId(destinationTab.getId());
                    if (!isValidMovePosition(newPosition)) return;
                    mModel.move(curPosition, newPosition);
                }

                @Override
                public void didMoveTabOutOfGroup(Tab movedTab, int prevFilterIndex) {
                    assert !(mActionsOnAllRelatedTabs && mTabGridDialogHandler != null);
                    TabGroupModelFilter filter =
                            (TabGroupModelFilter) mTabModelSelector.getTabModelFilterProvider()
                                    .getCurrentTabModelFilter();
                    boolean isUngroupingLastTabInGroup =
                            filter.getTabAt(prevFilterIndex).getId() == movedTab.getId();
                    if (mActionsOnAllRelatedTabs) {
                        if (isUngroupingLastTabInGroup) {
                            return;
                        }
                        Tab currentSelectedTab = mTabModelSelector.getCurrentTab();
                        int index = TabModelUtils.getTabIndexById(
                                mTabModelSelector.getTabModelFilterProvider()
                                        .getCurrentTabModelFilter(),
                                movedTab.getId());
                        addTabInfoToModel(PseudoTab.fromTab(movedTab), index,
                                currentSelectedTab.getId() == movedTab.getId());
                        boolean isSelected = mTabModelSelector.getCurrentTabId()
                                == filter.getTabAt(prevFilterIndex).getId();
                        updateTab(prevFilterIndex,
                                PseudoTab.fromTab(filter.getTabAt(prevFilterIndex)), isSelected,
                                true, false);
                    } else {
                        int curIndex = mModel.indexFromId(movedTab.getId());
                        if (!isValidMovePosition(curIndex)) return;
                        mModel.removeAt(curIndex);
                        if (mTabGridDialogHandler != null) {
                            mTabGridDialogHandler.updateDialogContent(isUngroupingLastTabInGroup
                                            ? Tab.INVALID_TAB_ID
                                            : filter.getTabAt(prevFilterIndex).getId());
                        }
                    }
                }

                @Override
                public void didMergeTabToGroup(Tab movedTab, int selectedTabIdInGroup) {
                    if (!mActionsOnAllRelatedTabs) return;
                    Pair<Integer, Integer> positions =
                            mModel.getIndexesForMergeToGroup(mTabModelSelector.getCurrentModel(),
                                    getRelatedTabsForId(movedTab.getId()));
                    int srcIndex = positions.second;
                    int desIndex = positions.first;

                    if (!isValidMovePosition(srcIndex) || !isValidMovePosition(desIndex)) return;
                    mModel.removeAt(srcIndex);
                    if (getRelatedTabsForId(movedTab.getId()).size() == 2) {
                        // When users use drop-to-merge to create a group.
                        RecordUserAction.record("TabGroup.Created.DropToMerge");
                    } else {
                        RecordUserAction.record("TabGrid.Drag.DropToMerge");
                    }

                    desIndex = srcIndex > desIndex ? desIndex : desIndex - 1;
                    Tab newSelectedTab = mTabModelSelector.getTabModelFilterProvider()
                                                 .getCurrentTabModelFilter()
                                                 .getTabAt(desIndex);
                    boolean isSelected = mTabModelSelector.getCurrentTab() == newSelectedTab;
                    updateTab(desIndex, PseudoTab.fromTab(newSelectedTab), isSelected, true, false);
                }

                @Override
                public void didMoveTabGroup(
                        Tab movedTab, int tabModelOldIndex, int tabModelNewIndex) {
                    if (!mActionsOnAllRelatedTabs || tabModelNewIndex == tabModelOldIndex) return;
                    TabGroupModelFilter filter =
                            (TabGroupModelFilter) mTabModelSelector.getTabModelFilterProvider()
                                    .getCurrentTabModelFilter();
                    List<Tab> relatedTabs = getRelatedTabsForId(movedTab.getId());
                    Tab currentGroupSelectedTab =
                            TabGroupUtils.getSelectedTabInGroupForTab(mTabModelSelector, movedTab);
                    TabModel tabModel = mTabModelSelector.getCurrentModel();
                    int curPosition = mModel.indexFromId(currentGroupSelectedTab.getId());
                    if (curPosition == TabModel.INVALID_TAB_INDEX) {
                        // Sync TabListModel with updated TabGroupModelFilter.
                        int indexToUpdate = filter.indexOf(tabModel.getTabAt(tabModelOldIndex));
                        mModel.updateTabListModelIdForGroup(currentGroupSelectedTab, indexToUpdate);
                        curPosition = mModel.indexFromId(currentGroupSelectedTab.getId());
                    }
                    if (!isValidMovePosition(curPosition)) return;

                    // Find the tab which was in the destination index before this move. Use that
                    // tab to figure out the new position.
                    int destinationTabIndex = tabModelNewIndex > tabModelOldIndex
                            ? tabModelNewIndex - relatedTabs.size()
                            : tabModelNewIndex + 1;
                    Tab destinationTab = tabModel.getTabAt(destinationTabIndex);
                    Tab destinationGroupSelectedTab = TabGroupUtils.getSelectedTabInGroupForTab(
                            mTabModelSelector, destinationTab);
                    int newPosition = mModel.indexFromId(destinationGroupSelectedTab.getId());
                    if (newPosition == TabModel.INVALID_TAB_INDEX) {
                        int indexToUpdate = filter.indexOf(destinationTab)
                                + (tabModelNewIndex > tabModelOldIndex ? 1 : -1);
                        mModel.updateTabListModelIdForGroup(
                                destinationGroupSelectedTab, indexToUpdate);
                        newPosition = mModel.indexFromId(destinationGroupSelectedTab.getId());
                    }
                    if (!isValidMovePosition(newPosition)) return;

                    mModel.move(curPosition, newPosition);
                }

                @Override
                public void didCreateGroup(
                        List<Tab> tabs, List<Integer> tabOriginalIndex, boolean isSameGroup) {}
            };

            ((TabGroupModelFilter) mTabModelSelector.getTabModelFilterProvider().getTabModelFilter(
                     false))
                    .addTabGroupObserver(mTabGroupObserver);
            ((TabGroupModelFilter) mTabModelSelector.getTabModelFilterProvider().getTabModelFilter(
                     true))
                    .addTabGroupObserver(mTabGroupObserver);
        }

        // TODO(meiliang): follow up with unit tests to test the close signal is sent correctly with
        // the recommendedNextTab.
        mTabClosedListener = new TabActionListener() {
            @Override
            public void run(int tabId) {
                // TODO(crbug.com/990698): Consider disabling all touch events during animation.
                if (mModel.indexFromId(tabId) == TabModel.INVALID_TAB_INDEX) return;
                Tab closingTab =
                        TabModelUtils.getTabById(mTabModelSelector.getCurrentModel(), tabId);
                if (closingTab == null) return;

                RecordUserAction.record("MobileTabClosed." + mComponentName);

                if (mActionsOnAllRelatedTabs) {
                    List<Tab> related = getRelatedTabsForId(tabId);
                    if (related.size() > 1) {
                        onGroupClosedFrom(tabId);
                        mTabModelSelector.getCurrentModel().closeMultipleTabs(related, true);
                        return;
                    }
                }
                onTabClosedFrom(tabId, mComponentName);

                Tab currentTab = mTabModelSelector.getCurrentTab();
                Tab nextTab = currentTab == closingTab ? getNextTab(tabId) : null;

                mTabModelSelector.getCurrentModel().closeTab(
                        closingTab, nextTab, false, false, true);
            }

            private Tab getNextTab(int closingTabId) {
                int closingTabIndex = mModel.indexFromId(closingTabId);

                if (closingTabIndex == TabModel.INVALID_TAB_INDEX) {
                    assert false;
                    return null;
                }

                int nextTabId = Tab.INVALID_TAB_ID;
                if (mModel.size() > 1) {
                    PropertyModel nextCardModel = closingTabIndex == 0
                            ? mModel.get(closingTabIndex + 1).model
                            : mModel.get(closingTabIndex - 1).model;
                    nextTabId = nextCardModel.get(CARD_TYPE) == TAB
                            ? nextCardModel.get(TabProperties.TAB_ID)
                            : Tab.INVALID_TAB_ID;
                }

                return TabModelUtils.getTabById(mTabModelSelector.getCurrentModel(), nextTabId);
            }
        };

        mTabGridItemTouchHelperCallback =
                new TabGridItemTouchHelperCallback(mModel, mTabModelSelector, mTabClosedListener,
                        mTabGridDialogHandler, mComponentName, mActionsOnAllRelatedTabs);
    }

    public void initWithNative(Profile profile) {
        mTabListFaviconProvider.initWithNative(profile);
        if (TabUiFeatureUtilities.isTabGroupsAndroidContinuationEnabled()) {
            mTabGroupTitleEditor = new TabGroupTitleEditor(mTabModelSelector) {
                @Override
                protected void updateTabGroupTitle(Tab tab, String title) {
                    // Only update title in PropertyModel for tab switcher.
                    if (!mActionsOnAllRelatedTabs) return;
                    Tab currentGroupSelectedTab =
                            TabGroupUtils.getSelectedTabInGroupForTab(mTabModelSelector, tab);
                    int index = mModel.indexFromId(currentGroupSelectedTab.getId());
                    if (index == TabModel.INVALID_TAB_INDEX) return;
                    mModel.get(index).model.set(TabProperties.TITLE, title);
                }

                @Override
                protected void deleteTabGroupTitle(int tabRootId) {
                    TabGroupUtils.deleteTabGroupTitle(tabRootId);
                }

                @Override
                protected String getTabGroupTitle(int tabRootId) {
                    return TabGroupUtils.getTabGroupTitle(tabRootId);
                }

                @Override
                protected void storeTabGroupTitle(int tabRootId, String title) {
                    TabGroupUtils.storeTabGroupTitle(tabRootId, title);
                }
            };
        }

        if (TabUiFeatureUtilities.ENABLE_SEARCH_CHIP.getValue()) {
            mSearchChipIconDrawableId = getSearchChipIconDrawableId();
            mTemplateUrlObserver = () -> {
                mSearchChipIconDrawableId = getSearchChipIconDrawableId();
                for (int i = 0; i < mModel.size(); i++) {
                    mModel.get(i).model.set(
                            TabProperties.SEARCH_CHIP_ICON_DRAWABLE_ID, mSearchChipIconDrawableId);
                }
            };
            TemplateUrlServiceFactory.get().addObserver(mTemplateUrlObserver);
        }
    }

    private void onTabClosedFrom(int tabId, String fromComponent) {
        @TabClosedFrom
        int from;
        if (fromComponent.equals(TabGroupUiCoordinator.COMPONENT_NAME)) {
            from = TabClosedFrom.TAB_STRIP;
        } else if (fromComponent.equals(TabSwitcherCoordinator.COMPONENT_NAME)) {
            from = TabClosedFrom.GRID_TAB_SWITCHER;
        } else {
            Log.w(TAG, "Attempting to close tab from Unknown UI");
            return;
        }
        sTabClosedFromMapTabClosedFromMap.put(tabId, from);
    }

    private void onGroupClosedFrom(int tabId) {
        sTabClosedFromMapTabClosedFromMap.put(tabId, TabClosedFrom.GRID_TAB_SWITCHER_GROUP);
    }

    @VisibleForTesting
    void setActionOnAllRelatedTabsForTesting(boolean actionOnAllRelatedTabs) {
        mActionsOnAllRelatedTabs = actionOnAllRelatedTabs;
    }

    private List<Tab> getRelatedTabsForId(int id) {
        TabModelFilter filter =
                mTabModelSelector.getTabModelFilterProvider().getCurrentTabModelFilter();
        return filter == null ? new ArrayList<>() : filter.getRelatedTabList(id);
    }

    private int getIndexOfTab(Tab tab, boolean onlyShowRelatedTabs) {
        int index;
        if (onlyShowRelatedTabs) {
            if (mModel.size() == 0) return TabList.INVALID_TAB_INDEX;
            List<Tab> related = getRelatedTabsForId(mModel.get(0).model.get(TabProperties.TAB_ID));
            index = related.indexOf(tab);
            if (index == -1) return TabList.INVALID_TAB_INDEX;
        } else {
            index = TabModelUtils.getTabIndexById(
                    mTabModelSelector.getTabModelFilterProvider().getCurrentTabModelFilter(),
                    tab.getId());
            // TODO(wychen): the title (tab count in the group) is wrong when it's not the last
            //  tab added in the group.
        }
        return index;
    }

    private void onTabAdded(Tab tab, boolean onlyShowRelatedTabs) {
        int index = getIndexOfTab(tab, onlyShowRelatedTabs);
        if (index == TabList.INVALID_TAB_INDEX) return;

        addTabInfoToModel(PseudoTab.fromTab(tab), index, mTabModelSelector.getCurrentTab() == tab);
    }

    private void onTabMoved(int newIndex, int curIndex) {
        // Handle move without groups enabled.
        if (mTabModelSelector.getTabModelFilterProvider().getCurrentTabModelFilter()
                        instanceof EmptyTabModelFilter) {
            if (!isValidMovePosition(curIndex) || !isValidMovePosition(newIndex)) return;
            mModel.move(curIndex, newIndex);
        }
    }

    private boolean isValidMovePosition(int position) {
        return position != TabModel.INVALID_TAB_INDEX && position < mModel.size();
    }

    /**
     * Hide the blue border for selected tab for the Tab-to-Grid resizing stage.
     * The selected border should re-appear in the final fading-in stage.
     */
    void prepareOverview() {
        if (!TabUiFeatureUtilities.isTabToGtsAnimationEnabled()
                || !mTabModelSelector.isTabStateInitialized()) {
            return;
        }

        assert mVisible;
        int selectedTabCount = 0;
        int tabsCount = 0;
        for (int i = 0; i < mModel.size(); i++) {
            if (mModel.get(i).model.get(CARD_TYPE) != TAB) continue;

            if (mModel.get(i).model.get(TabProperties.IS_SELECTED)) selectedTabCount++;
            mModel.get(i).model.set(TabProperties.IS_SELECTED, false);
            tabsCount += 1;
        }
        assert (selectedTabCount == 1 || tabsCount == 0)
            : "There should be exactly one selected tab or no tabs at all when calling "
              + "TabListMediator.prepareOverview()";
    }

    private boolean areTabsUnchanged(@Nullable List<PseudoTab> tabs) {
        int tabsCount = 0;
        for (int i = 0; i < mModel.size(); i++) {
            if (mModel.get(i).model.get(CARD_TYPE) == TAB) {
                tabsCount += 1;
            }
        }
        if (tabs == null) {
            return tabsCount == 0;
        }
        if (tabs.size() != tabsCount) return false;
        for (int i = 0; i < tabs.size(); i++) {
            if (mModel.get(i).model.get(CARD_TYPE) == TAB
                    && mModel.get(i).model.get(TabProperties.TAB_ID) != tabs.get(i).getId()) {
                return false;
            }
        }
        return true;
    }

    /**
     * Initialize the component with a list of tabs to show in a grid.
     * @param tabs The list of tabs to be shown.
     * @param quickMode Whether to skip capturing the selected live tab for the thumbnail.
     * @param mruMode Whether to sort the Tabs in MRU order.
     * @return Whether the {@link TabListRecyclerView} can be shown quickly.
     */
    boolean resetWithListOfTabs(
            @Nullable List<PseudoTab> tabs, boolean quickMode, boolean mruMode) {
        List<PseudoTab> tabsList = tabs;
        if (tabs != null && mruMode) {
            // Make a copy to sort since the input may be unmodifiable.
            tabsList = new ArrayList<>(tabs);
            Collections.sort(tabsList, LAST_SHOWN_COMPARATOR);
        }

        mVisible = tabsList != null;
        if (areTabsUnchanged(tabsList)) {
            if (tabsList == null) return true;

            for (int i = 0; i < tabsList.size(); i++) {
                PseudoTab tab = tabsList.get(i);
                boolean isSelected = mTabModelSelector.getCurrentTabId() == tab.getId();
                updateTab(i, tab, isSelected, false, quickMode);
            }
            return true;
        }
        mModel.set(new ArrayList<>());
        if (tabsList == null) {
            return true;
        }
        int currentTabId = mTabModelSelector.getCurrentTabId();

        for (int i = 0; i < tabsList.size(); i++) {
            PseudoTab tab = tabsList.get(i);
            addTabInfoToModel(tab, i, isSelectedTab(tab, currentTabId));
        }

        return false;
    }

    void postHiding() {
        mVisible = false;
    }

    private boolean isSelectedTab(PseudoTab tab, int tabModelSelectedTabId) {
        SelectionDelegate<Integer> selectionDelegate = getTabSelectionDelegate();
        if (selectionDelegate == null) {
            return tab.getId() == tabModelSelectedTabId;
        } else {
            return selectionDelegate.isItemSelected(tab.getId());
        }
    }

    /**
     * @see TabSwitcherMediator.ResetHandler#softCleanup
     */
    void softCleanup() {
        assert !mVisible;
        for (int i = 0; i < mModel.size(); i++) {
            if (mModel.get(i).model.get(CARD_TYPE) == TAB) {
                mModel.get(i).model.set(TabProperties.THUMBNAIL_FETCHER, null);
            }
        }
    }

    private void updateTab(int index, PseudoTab pseudoTab, boolean isSelected, boolean isUpdatingId,
            boolean quickMode) {
        if (index < 0 || index >= mModel.size()) return;
        if (isUpdatingId) {
            mModel.get(index).model.set(TabProperties.TAB_ID, pseudoTab.getId());
        } else {
            assert mModel.get(index).model.get(TabProperties.TAB_ID) == pseudoTab.getId();
        }

        // TODO(wychen): refactor this.
        boolean isRealTab = pseudoTab.hasRealTab();
        TabActionListener tabSelectedListener;
        if (!isRealTab) {
            tabSelectedListener = null;
        } else if (mGridCardOnClickListenerProvider == null
                || getRelatedTabsForId(pseudoTab.getId()).size() == 1
                || !mActionsOnAllRelatedTabs) {
            tabSelectedListener = mTabSelectedListener;
        } else {
            tabSelectedListener =
                    mGridCardOnClickListenerProvider.openTabGridDialog(pseudoTab.getTab());

            if (tabSelectedListener == null) {
                tabSelectedListener = mTabSelectedListener;
            }
        }
        mModel.get(index).model.set(TabProperties.TAB_SELECTED_LISTENER, tabSelectedListener);
        mModel.get(index).model.set(TabProperties.IS_SELECTED, isSelected);
        mModel.get(index).model.set(TabProperties.TITLE, getLatestTitleForTab(pseudoTab));
        if (isRealTab) {
            mModel.get(index).model.set(
                    TabProperties.URL_DOMAIN, getDomainForTab(pseudoTab.getTab()));
        }
        if (TabUiFeatureUtilities.ENABLE_SEARCH_CHIP.getValue() && mUiType == UiType.CLOSABLE
                && isRealTab) {
            mModel.get(index).model.set(
                    TabProperties.SEARCH_QUERY, getLastSearchTerm(pseudoTab.getTab()));
            mModel.get(index).model.set(TabProperties.SEARCH_LISTENER,
                    SearchTermChipUtils.getSearchQueryListener(
                            pseudoTab.getTab(), mTabSelectedListener));
            mModel.get(index).model.set(
                    TabProperties.SEARCH_CHIP_ICON_DRAWABLE_ID, mSearchChipIconDrawableId);
        }

        updateFaviconForTab(pseudoTab, null);
        boolean forceUpdate = isSelected && !quickMode;
        if (mThumbnailProvider != null && mVisible
                && (mModel.get(index).model.get(TabProperties.THUMBNAIL_FETCHER) == null
                        || forceUpdate || isUpdatingId)) {
            ThumbnailFetcher callback =
                    new ThumbnailFetcher(mThumbnailProvider, pseudoTab.getId(), forceUpdate,
                            forceUpdate && !TabUiFeatureUtilities.isTabToGtsAnimationEnabled());
            mModel.get(index).model.set(TabProperties.THUMBNAIL_FETCHER, callback);
        }
    }

    /**
     * @return The callback that hosts the logic for swipe and drag related actions.
     */
    ItemTouchHelper.SimpleCallback getItemTouchHelperCallback(final float swipeToDismissThreshold,
            final float mergeThreshold, final float ungroupThreshold, final Profile profile) {
        mTabGridItemTouchHelperCallback.setupCallback(
                swipeToDismissThreshold, mergeThreshold, ungroupThreshold, profile);
        return mTabGridItemTouchHelperCallback;
    }

    void registerOrientationListener(GridLayoutManager manager) {
        // TODO(yuezhanggg): Try to dynamically determine span counts based on screen width,
        // minimum card width and padding.
        mComponentCallbacks = new ComponentCallbacks() {
            @Override
            public void onConfigurationChanged(Configuration newConfig) {
                updateSpanCountForOrientation(manager, newConfig.orientation);
            }

            @Override
            public void onLowMemory() {}
        };
        mContext.registerComponentCallbacks(mComponentCallbacks);
    }

    /**
     * Update the grid layout span count and span size lookup base on orientation.
     * @param manager     The {@link GridLayoutManager} used to update the span count.
     * @param orientation The orientation base on which we update the span count.
     */
    void updateSpanCountForOrientation(GridLayoutManager manager, int orientation) {
        // When in multi-window mode, the span count is fixed to 2 to keep tab card size reasonable.
        int spanCount = orientation == Configuration.ORIENTATION_PORTRAIT
                        || MultiWindowUtils.getInstance().isInMultiWindowMode((Activity) mContext)
                ? TabListCoordinator.GRID_LAYOUT_SPAN_COUNT_PORTRAIT
                : TabListCoordinator.GRID_LAYOUT_SPAN_COUNT_LANDSCAPE;
        manager.setSpanCount(spanCount);
        manager.setSpanSizeLookup(new GridLayoutManager.SpanSizeLookup() {
            @Override
            public int getSpanSize(int position) {
                int itemType = mModel.get(position).type;

                if (itemType == TabProperties.UiType.MESSAGE) return manager.getSpanCount();
                return 1;
            }
        });
    }

    /**
     * Setup the {@link View.AccessibilityDelegate} for grid layout.
     * @param helper The {@link TabGridAccessibilityHelper} used to setup accessibility support.
     */
    void setupAccessibilityDelegate(TabGridAccessibilityHelper helper) {
        if (!TabUiFeatureUtilities.isTabGroupsAndroidContinuationEnabled()) {
            return;
        }
        mAccessibilityDelegate = new View.AccessibilityDelegate() {
            @Override
            public void onInitializeAccessibilityNodeInfo(View host, AccessibilityNodeInfo info) {
                super.onInitializeAccessibilityNodeInfo(host, info);
                if (Build.VERSION.SDK_INT < Build.VERSION_CODES.LOLLIPOP) {
                    return;
                }
                for (AccessibilityAction action : helper.getPotentialActionsForView(host)) {
                    info.addAction(action);
                }
            }

            @Override
            public boolean performAccessibilityAction(View host, int action, Bundle args) {
                if (!helper.isReorderAction(action)) {
                    return super.performAccessibilityAction(host, action, args);
                }

                Pair<Integer, Integer> positions = helper.getPositionsOfReorderAction(host, action);
                int currentPosition = positions.first;
                int targetPosition = positions.second;
                if (!isValidMovePosition(currentPosition) || !isValidMovePosition(targetPosition)) {
                    return false;
                }
                mModel.move(currentPosition, targetPosition);
                RecordUserAction.record("TabGrid.AccessibilityDelegate.Reordered");
                return true;
            }
        };
    }

    /**
     * Exposes a {@link TabGroupTitleEditor} to modify the title of a tab group.
     * @return The {@link TabGroupTitleEditor} used to modify the title of a tab group.
     */
    @Nullable
    TabGroupTitleEditor getTabGroupTitleEditor() {
        return mTabGroupTitleEditor;
    }

    /**
     * Destroy any members that needs clean up.
     */
    public void destroy() {
        TabModel tabModel = mTabModelSelector.getCurrentModel();
        if (tabModel != null) {
            for (int i = 0; i < tabModel.getCount(); i++) {
                tabModel.getTabAt(i).removeObserver(mTabObserver);
            }
        }
        if (mTabModelObserver != null) {
            mTabModelSelector.getTabModelFilterProvider().removeTabModelFilterObserver(
                    mTabModelObserver);
        }
        if (mTabGroupObserver != null) {
            ((TabGroupModelFilter) mTabModelSelector.getTabModelFilterProvider().getTabModelFilter(
                     false))
                    .removeTabGroupObserver(mTabGroupObserver);
            ((TabGroupModelFilter) mTabModelSelector.getTabModelFilterProvider().getTabModelFilter(
                     true))
                    .removeTabGroupObserver(mTabGroupObserver);
        }
        if (mComponentCallbacks != null) {
            mContext.unregisterComponentCallbacks(mComponentCallbacks);
        }
        if (mTabGroupTitleEditor != null) {
            mTabGroupTitleEditor.destroy();
        }
        if (mTemplateUrlObserver != null) {
            TemplateUrlServiceFactory.get().removeObserver(mTemplateUrlObserver);
        }
    }

    private void addTabInfoToModel(final PseudoTab pseudoTab, int index, boolean isSelected) {
        assert index != TabModel.INVALID_TAB_INDEX;
        // If the new tab is already in the target position of TabListModel, skip redundant
        // addition. The only exception is when we undo a group-tabs operation. In that case, it is
        // possible that the tab being added back has the same id as the PropertyModel of the
        // group.
        if (index < mModel.size()) {
            int type = mModel.get(index).type;
            PropertyModel model = mModel.get(index).model;
            if ((type == UiType.CLOSABLE || type == UiType.SELECTABLE || type == UiType.STRIP)
                    && model.get(TabProperties.TAB_ID) == pseudoTab.getId()
                    && !TabUiFeatureUtilities.isTabGroupsAndroidEnabled()) {
                return;
            }
        }
        boolean showIPH = false;
        boolean isRealTab = pseudoTab.hasRealTab();
        if (mActionsOnAllRelatedTabs && !mShownIPH && isRealTab) {
            showIPH = getRelatedTabsForId(pseudoTab.getId()).size() > 1;
        }
        TabActionListener tabSelectedListener;
        if (!isRealTab) {
            tabSelectedListener = null;
        } else if (mGridCardOnClickListenerProvider == null
                || getRelatedTabsForId(pseudoTab.getId()).size() == 1
                || !mActionsOnAllRelatedTabs) {
            tabSelectedListener = mTabSelectedListener;
        } else {
            tabSelectedListener =
                    mGridCardOnClickListenerProvider.openTabGridDialog(pseudoTab.getTab());
            if (tabSelectedListener == null) {
                tabSelectedListener = mTabSelectedListener;
            }
        }

        int selectedTabBackgroundDrawableId = pseudoTab.isIncognito()
                ? R.drawable.selected_tab_background_incognito
                : R.drawable.selected_tab_background;

        int tabstripFaviconBackgroundDrawableId = pseudoTab.isIncognito()
                ? R.color.favicon_background_color_incognito
                : R.color.favicon_background_color;
        PropertyModel tabInfo =
                new PropertyModel.Builder(TabProperties.ALL_KEYS_TAB_GRID)
                        .with(TabProperties.TAB_ID, pseudoTab.getId())
                        .with(TabProperties.TITLE, getLatestTitleForTab(pseudoTab))
                        .with(TabProperties.URL_DOMAIN,
                                isRealTab ? getDomainForTab(pseudoTab.getTab()) : null)
                        .with(TabProperties.FAVICON,
                                mTabListFaviconProvider.getDefaultFaviconDrawable(
                                        pseudoTab.isIncognito()))
                        .with(TabProperties.IS_SELECTED, isSelected)
                        .with(TabProperties.IPH_PROVIDER, showIPH ? mIphProvider : null)
                        .with(CARD_ALPHA, 1f)
                        .with(TabProperties.TAB_CLOSED_LISTENER,
                                isRealTab ? mTabClosedListener : null)
                        .with(TabProperties.CARD_ANIMATION_STATUS,
                                ClosableTabGridView.AnimationStatus.CARD_RESTORE)
                        .with(TabProperties.TAB_SELECTION_DELEGATE,
                                isRealTab ? getTabSelectionDelegate() : null)
                        .with(TabProperties.IS_INCOGNITO, pseudoTab.isIncognito())
                        .with(TabProperties.SELECTED_TAB_BACKGROUND_DRAWABLE_ID,
                                selectedTabBackgroundDrawableId)
                        .with(TabProperties.TABSTRIP_FAVICON_BACKGROUND_COLOR_ID,
                                tabstripFaviconBackgroundDrawableId)
                        .with(TabProperties.ACCESSIBILITY_DELEGATE, mAccessibilityDelegate)
                        .with(CARD_TYPE, TAB)
                        .build();

        if (TabUiFeatureUtilities.ENABLE_SEARCH_CHIP.getValue() && mUiType == UiType.CLOSABLE
                && isRealTab) {
            tabInfo.set(TabProperties.SEARCH_QUERY, getLastSearchTerm(pseudoTab.getTab()));
            tabInfo.set(TabProperties.SEARCH_LISTENER,
                    SearchTermChipUtils.getSearchQueryListener(
                            pseudoTab.getTab(), mTabSelectedListener));
            tabInfo.set(TabProperties.SEARCH_CHIP_ICON_DRAWABLE_ID, mSearchChipIconDrawableId);
        }

        if (mUiType == UiType.SELECTABLE) {
            // Incognito in both light/dark theme is the same as non-incognito mode in dark theme.
            // Non-incognito mode and incognito in both light/dark themes in dark theme all look
            // dark.
            ColorStateList checkedDrawableColorList = AppCompatResources.getColorStateList(mContext,
                    pseudoTab.isIncognito() ? R.color.default_icon_color_dark
                                            : R.color.default_icon_color_inverse);
            ColorStateList actionButtonBackgroundColorList =
                    AppCompatResources.getColorStateList(mContext,
                            pseudoTab.isIncognito() ? R.color.default_icon_color_light
                                                    : R.color.default_icon_color);
            // TODO(995876): Update color modern_blue_300 to active_color_dark when the associated
            // bug is landed.
            ColorStateList actionbuttonSelectedBackgroundColorList =
                    AppCompatResources.getColorStateList(mContext,
                            pseudoTab.isIncognito() ? R.color.modern_blue_300
                                                    : R.color.default_control_color_active);

            tabInfo.set(TabProperties.CHECKED_DRAWABLE_STATE_LIST, checkedDrawableColorList);
            tabInfo.set(TabProperties.SELECTABLE_TAB_ACTION_BUTTON_BACKGROUND,
                    actionButtonBackgroundColorList);
            tabInfo.set(TabProperties.SELECTABLE_TAB_ACTION_BUTTON_SELECTED_BACKGROUND,
                    actionbuttonSelectedBackgroundColorList);
            tabInfo.set(
                    TabProperties.SELECTABLE_TAB_CLICKED_LISTENER, mSelectableTabOnClickListener);
        } else {
            tabInfo.set(TabProperties.TAB_SELECTED_LISTENER, tabSelectedListener);
            tabInfo.set(TabProperties.TAB_CLOSED_LISTENER, mTabClosedListener);
        }

        if (index >= mModel.size()) {
            mModel.add(new SimpleRecyclerViewAdapter.ListItem(mUiType, tabInfo));
        } else {
            mModel.add(index, new SimpleRecyclerViewAdapter.ListItem(mUiType, tabInfo));
        }

        updateFaviconForTab(pseudoTab, null);

        if (mThumbnailProvider != null && mVisible) {
            ThumbnailFetcher callback = new ThumbnailFetcher(mThumbnailProvider, pseudoTab.getId(),
                    isSelected, isSelected && !TabUiFeatureUtilities.isTabToGtsAnimationEnabled());
            tabInfo.set(TabProperties.THUMBNAIL_FETCHER, callback);
        }
        if (pseudoTab.getTab() != null) pseudoTab.getTab().addObserver(mTabObserver);
    }

    // TODO(wychen): make this work with PseudoTab.
    private String getLastSearchTerm(Tab tab) {
        assert TabUiFeatureUtilities.ENABLE_SEARCH_CHIP.getValue();
        if (mActionsOnAllRelatedTabs && TabUiFeatureUtilities.isTabGroupsAndroidEnabled()
                && getRelatedTabsForId(tab.getId()).size() > 1) {
            return null;
        }
        return TabAttributeCache.getLastSearchTerm(tab.getId());
    }

    private int getSearchChipIconDrawableId() {
        int iconDrawableId;
        if (TabUiFeatureUtilities.ENABLE_SEARCH_CHIP_ADAPTIVE.getValue()) {
            iconDrawableId = TemplateUrlServiceFactory.get().isDefaultSearchEngineGoogle()
                    ? R.drawable.ic_logo_googleg_24dp
                    : R.drawable.ic_search;
        } else {
            iconDrawableId = R.drawable.ic_search;
        }
        return iconDrawableId;
    }

    // TODO(wychen): make this work with PseudoTab.
    private String getDomainForTab(Tab tab) {
        if (!TabUiFeatureUtilities.isTabGroupsAndroidContinuationEnabled()) return "";
        if (!mActionsOnAllRelatedTabs) return getDomain(tab);

        List<Tab> relatedTabs = getRelatedTabsForId(tab.getId());

        List<String> domainNames = new ArrayList<>();

        for (int i = 0; i < relatedTabs.size(); i++) {
            String domain = getDomain(relatedTabs.get(i));
            domainNames.add(domain);
        }
        // TODO(1024925): Address i18n issue for the list delimiter.
        return TextUtils.join(", ", domainNames);
    }

    private String getDomain(Tab tab) {
        String domain = UrlUtilities.getDomainAndRegistry(tab.getUrlString(), false);

        if (domain.isEmpty()) return tab.getUrlString();
        return domain;
    }

    @Nullable
    private SelectionDelegate<Integer> getTabSelectionDelegate() {
        return mSelectionDelegateProvider == null
                ? null
                : mSelectionDelegateProvider.getSelectionDelegate();
    }

    @VisibleForTesting
    String getLatestTitleForTab(PseudoTab pseudoTab) {
        String originalTitle = pseudoTab.getTitle(mTitleProvider);
        if (!mActionsOnAllRelatedTabs || mTabGroupTitleEditor == null) return originalTitle;
        // If the group degrades to a single tab, delete the stored title.
        if (getRelatedTabsForId(pseudoTab.getId()).size() <= 1) {
            return originalTitle;
        }
        String storedTitle = mTabGroupTitleEditor.getTabGroupTitle(pseudoTab.getRootId());
        return storedTitle == null ? originalTitle : storedTitle;
    }

    int selectedTabId() {
        if (mNextTabId != Tab.INVALID_TAB_ID) {
            return mNextTabId;
        }

        return mTabModelSelector.getCurrentTabId();
    }

    /**
     * Find the index of the given tab in the {@link TabListRecyclerView}.
     * Note that Tabs may have different index in {@link TabListRecyclerView} and {@link
     * TabModelSelector}, like when {@link resetWithListOfTabs} above is called with MRU mode
     * enabled.
     * @param tabId The given Tab id.
     * @return The index of the Tab in the {@link TabListRecyclerView}.
     */
    int indexOfTab(int tabId) {
        return mModel.indexFromId(tabId);
    }

    @VisibleForTesting
    void updateFaviconForTab(PseudoTab pseudoTab, @Nullable Bitmap icon) {
        int modelIndex = mModel.indexFromId(pseudoTab.getId());
        if (modelIndex == Tab.INVALID_TAB_ID) return;
        List<Tab> relatedTabList = getRelatedTabsForId(pseudoTab.getId());

        Callback<Drawable> faviconCallback = drawable -> {
            assert drawable != null;
            // Need to re-get the index because the original index can be stale when callback is
            // triggered.
            int index = mModel.indexFromId(pseudoTab.getId());
            if (index != TabModel.INVALID_TAB_INDEX && drawable != null) {
                mModel.get(index).model.set(TabProperties.FAVICON, drawable);
            }
        };

        if (mActionsOnAllRelatedTabs && relatedTabList.size() > 1) {
            if (!TabUiFeatureUtilities.isTabGroupsAndroidContinuationEnabled()) {
                // For tab group card in grid tab switcher, the favicon is set to be null.
                mModel.get(modelIndex).model.set(TabProperties.FAVICON, null);
                return;
            }

            // The order of the url list matches the multi-thumbnail.
            List<String> urls = new ArrayList<>();
            urls.add(pseudoTab.getUrl());
            for (int i = 0; urls.size() < 4 && i < relatedTabList.size(); i++) {
                if (pseudoTab.getId() == relatedTabList.get(i).getId()) continue;
                urls.add(relatedTabList.get(i).getUrlString());
            }

            // For tab group card in grid tab switcher, the favicon is the composed favicon.
            mTabListFaviconProvider.getComposedFaviconImageAsync(
                    urls, pseudoTab.isIncognito(), faviconCallback);

            return;
        }
        if (!mTabListFaviconProvider.isInitialized()) {
            return;
        }

        // If there is an available icon, we fetch favicon synchronously; otherwise asynchronously.
        if (icon != null) {
            Drawable drawable = mTabListFaviconProvider.getFaviconForUrlSync(
                    pseudoTab.getUrl(), pseudoTab.isIncognito(), icon);
            mModel.get(modelIndex).model.set(TabProperties.FAVICON, drawable);
            return;
        }

        mTabListFaviconProvider.getFaviconForUrlAsync(
                pseudoTab.getUrl(), pseudoTab.isIncognito(), faviconCallback);
    }

    /**
     * Inserts a special {@link org.chromium.ui.modelutil.MVCListAdapter.ListItem} at given index of
     * the current {@link TabListModel}.
     *
     * @param index The index of the {@link org.chromium.ui.modelutil.MVCListAdapter.ListItem} to be
     *              inserted.
     * @param uiType The view type the model will bind to.
     * @param model The model that will be bound to a view.
     */
    void addSpecialItemToModel(int index, @UiType int uiType, PropertyModel model) {
        mModel.add(index, new SimpleRecyclerViewAdapter.ListItem(uiType, model));
    }

    /**
     * Removes a special {@link @link org.chromium.ui.modelutil.MVCListAdapter.ListItem} that
     * has the given {@code uiType} and/or its {@link PropertyModel} has the given
     * {@code itemIdentifier} from the current {@link TabListModel}.
     *
     * @param uiType The uiType to match.
     * @param itemIdentifier The itemIdentifier to match. This can be obsoleted if the {@link @link
     *         org.chromium.ui.modelutil.MVCListAdapter.ListItem} does not need additional
     *         identifier.
     */
    void removeSpecialItemFromModel(@UiType int uiType, int itemIdentifier) {
        int index = TabModel.INVALID_TAB_INDEX;
        if (uiType == UiType.MESSAGE) {
            if (itemIdentifier == MessageService.MessageType.ALL) {
                while (mModel.lastIndexForMessageItem() != TabModel.INVALID_TAB_INDEX) {
                    index = mModel.lastIndexForMessageItem();
                    mModel.removeAt(index);
                }
                return;
            }
            index = mModel.lastIndexForMessageItemFromType(itemIdentifier);
        } else if (uiType == UiType.NEW_TAB_TILE) {
            index = mModel.getIndexForNewTabTile();
        }

        if (index == TabModel.INVALID_TAB_INDEX) return;

        assert validateItemAt(index, uiType, itemIdentifier);
        mModel.removeAt(index);
    }

    private boolean validateItemAt(int index, @UiType int uiType, int itemIdentifier) {
        if (uiType == UiType.MESSAGE) {
            return mModel.get(index).type == uiType
                    && mModel.get(index).model.get(MESSAGE_TYPE) == itemIdentifier;
        } else if (uiType == UiType.NEW_TAB_TILE) {
            return mModel.get(index).type == uiType;
        }

        return false;
    }

    @VisibleForTesting
    View.AccessibilityDelegate getAccessibilityDelegateForTesting() {
        return mAccessibilityDelegate;
    }

    /**
     * These functions are wrapped in an inner class here for the formal equivalence checker, and
     * it has to be at the end of the file. Otherwise the lambda and interface orders would be
     * changed, resulting in differences.
     */
    @VisibleForTesting
    static class SearchTermChipUtils {
        static @VisibleForTesting Boolean sIsSearchChipAdaptiveIconEnabledForTesting;

        private static TabObserver sLazyNavigateToLastSearchQuery = new EmptyTabObserver() {
            @Override
            public void onPageLoadStarted(Tab tab, String url) {
                assert tab.getWebContents() != null;
                if (tab.getWebContents() == null) return;

                // Directly calling navigateToLastSearchQuery() would lead to unsafe re-entrant
                // calls to NavigateToPendingEntry.
                PostTask.postTask(
                        UiThreadTaskTraits.USER_BLOCKING, () -> navigateToLastSearchQuery(tab));
                tab.removeObserver(sLazyNavigateToLastSearchQuery);
            }
        };

        @VisibleForTesting
        static void navigateToLastSearchQuery(Tab tab) {
            if (tab.getWebContents() == null) {
                tab.addObserver(sLazyNavigateToLastSearchQuery);
                return;
            }
            NavigationController controller = tab.getWebContents().getNavigationController();
            NavigationHistory history = controller.getNavigationHistory();
            for (int i = history.getCurrentEntryIndex() - 1; i >= 0; i--) {
                int offset = i - history.getCurrentEntryIndex();
                if (!controller.canGoToOffset(offset)) continue;

                String url = history.getEntryAtIndex(i).getOriginalUrl();
                String query = TemplateUrlServiceFactory.get().getSearchQueryForUrl(url);
                if (TextUtils.isEmpty(query)) continue;

                tab.loadUrl(new LoadUrlParams(url, PageTransition.KEYWORD_GENERATED));
                return;
            }
        }

        private static TabActionListener getSearchQueryListener(
                Tab originalTab, TabActionListener select) {
            return (tabId) -> {
                if (originalTab == null) return;
                assert tabId == originalTab.getId();
                RecordUserAction.record("TabGrid.TabSearchChipTapped");
                select.run(tabId);
                navigateToLastSearchQuery(originalTab);
            };
        }
    }
}
