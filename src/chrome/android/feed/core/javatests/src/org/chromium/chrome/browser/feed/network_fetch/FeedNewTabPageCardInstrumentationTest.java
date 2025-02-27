// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import static androidx.test.espresso.Espresso.onView;
import static androidx.test.espresso.action.ViewActions.click;
import static androidx.test.espresso.matcher.ViewMatchers.withId;

import androidx.test.espresso.contrib.RecyclerViewActions;
import androidx.test.filters.MediumTest;

import org.junit.Before;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;

import org.chromium.base.test.util.CommandLineFlags;
import org.chromium.base.test.util.Feature;
import org.chromium.chrome.browser.ChromeActivity;
import org.chromium.chrome.browser.flags.ChromeFeatureList;
import org.chromium.chrome.browser.flags.ChromeSwitches;
import org.chromium.chrome.feed.R;
import org.chromium.chrome.test.ChromeActivityTestRule;
import org.chromium.chrome.test.util.ChromeRenderTestRule;
import org.chromium.chrome.test.util.NewTabPageTestUtils;
import org.chromium.chrome.test.util.browser.Features;
import org.chromium.chrome.test.util.browser.WPRArchiveDirectory;
import org.chromium.components.embedder_support.util.UrlConstants;
import org.chromium.content_public.browser.test.ContentJUnit4ClassRunner;

import java.io.IOException;

/**
 * Tests for {@link FeedNewTabPage} using WPR record/replay infra to mock the backend.
 * Other tests could be found in {@link FeedNewTabPageCardRenderTest}.
 */
@RunWith(ContentJUnit4ClassRunner.class)
@CommandLineFlags.Add(ChromeSwitches.DISABLE_FIRST_RUN_EXPERIENCE)
@Features.EnableFeatures(ChromeFeatureList.INTEREST_FEED_CONTENT_SUGGESTIONS)
public final class FeedNewTabPageCardInstrumentationTest {
    @Rule
    public ChromeActivityTestRule<ChromeActivity> mActivityTestRule =
            new ChromeActivityTestRule<>(ChromeActivity.class);

    @Rule
    public ChromeRenderTestRule mRenderTestRule = new ChromeRenderTestRule();

    @Before
    public void setUp() {
        mActivityTestRule.startMainActivityOnBlankPage();
    }

    @Test
    @MediumTest
    @Feature({"FeedNewTabPage", "WPRRecordReplayTest", "RenderTest"})
    @WPRArchiveDirectory("chrome/android/feed/core/javatests/src/org/chromium/chrome/"
            + "browser/feed/wpr_tests")
    public void
    launchNTP_withMultipleFeedCardsRendered() throws IOException, InterruptedException {
        mActivityTestRule.loadUrlInNewTab(UrlConstants.NTP_URL);
        NewTabPageTestUtils.waitForNtpLoaded(mActivityTestRule.getActivity().getActivityTab());

        // scroll to "More" button
        onView(withId(R.id.feed_stream_recycler_view))
                .perform(RecyclerViewActions.scrollToPosition(3));

        // Click "More" button
        onView(withId(R.id.action_button)).perform(click());

        Thread.sleep(2000);

        // Scroll to position 5 to trigger a network resource load for the cards
        onView(withId(R.id.feed_stream_recycler_view))
                .perform(RecyclerViewActions.scrollToPosition(5));

        // Scroll down to bottom
        onView(withId(R.id.feed_stream_recycler_view))
                .perform(RecyclerViewActions.scrollToPosition(11));

        // Wait till image resource loaded
        Thread.sleep(4000);
        mRenderTestRule.render(
                mActivityTestRule.getActivity().getActivityTab().getNativePage().getView(),
                "feed_wpr_render_position_11");

        // Scroll back to position 3 to see previously rendered card
        onView(withId(R.id.feed_stream_recycler_view))
                .perform(RecyclerViewActions.scrollToPosition(3));

        // Wait till it finish rendering cards
        Thread.sleep(1000);
        mRenderTestRule.render(
                mActivityTestRule.getActivity().getActivityTab().getNativePage().getView(),
                "feed_wpr_render_position_3");
    }
}
