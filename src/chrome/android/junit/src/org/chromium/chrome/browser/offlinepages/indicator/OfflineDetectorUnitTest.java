// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.offlinepages.indicator;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.verify;

import static org.chromium.chrome.browser.offlinepages.indicator.OfflineDetector.STATUS_INDICATOR_WAIT_ON_OFFLINE_DURATION_MS;
import static org.chromium.chrome.browser.offlinepages.indicator.OfflineDetector.setMockElapsedTimeSupplier;

import android.os.Handler;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.ArgumentCaptor;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

import org.chromium.base.test.BaseRobolectricTestRunner;
import org.chromium.chrome.browser.offlinepages.indicator.ConnectivityDetector.ConnectionState;

/**
 * Unit tests for {@link OfflineDetector}.
 */
@RunWith(BaseRobolectricTestRunner.class)
public class OfflineDetectorUnitTest {
    @Mock
    private ConnectivityDetector mConnectivityDetector;
    @Mock
    private Handler mHandler;

    private long mElapsedTimeMs;
    private OfflineDetector mOfflineDetector;

    private int mNotificationReceivedByObserver = 0;
    private boolean mLastNotificationReceivedIsOffline;

    @Before
    public void setUp() {
        MockitoAnnotations.initMocks(this);

        mElapsedTimeMs = 0;
        OfflineDetector.setMockElapsedTimeSupplier(() -> mElapsedTimeMs);

        OfflineDetector.setMockConnectivityDetector(mConnectivityDetector);

        mOfflineDetector =
                new OfflineDetector((Boolean offline) -> onConnectionStateChanged(offline));
        mOfflineDetector.setHandlerForTesting(mHandler);
    }

    @After
    public void tearDown() {
        OfflineDetector.setMockElapsedTimeSupplier(null);
    }

    /**
     * Tests that the online notification is sent immediately when the device goes online.
     * Also, verifies that the offline notification is sent after
     * |STATUS_INDICATOR_WAIT_ON_OFFLINE_DURATION_MS| time has elapsed.
     */
    @Test
    public void testCallbackInvokedOnConnectionChange() {
        // Change to online.
        changeConnectionState(false);
        assertEquals(0, mNotificationReceivedByObserver);
        assertFalse(mLastNotificationReceivedIsOffline);

        // Change to offline.
        changeConnectionState(true);
        assertEquals("Notification received immediately after connection changed to offline", 0,
                mNotificationReceivedByObserver);
        assertFalse("Notification received immediately after connection changed to offline",
                mLastNotificationReceivedIsOffline);
        final ArgumentCaptor<Runnable> captor = ArgumentCaptor.forClass(Runnable.class);
        verify(mHandler).postDelayed(
                captor.capture(), eq(STATUS_INDICATOR_WAIT_ON_OFFLINE_DURATION_MS));
        advanceTimeByMs(STATUS_INDICATOR_WAIT_ON_OFFLINE_DURATION_MS);
        captor.getValue().run();

        assertEquals("Notification count not updated after connection changed to offline", 1,
                mNotificationReceivedByObserver);
        assertTrue("Notification not received after connection changed to offline",
                mLastNotificationReceivedIsOffline);

        // Change to online.
        changeConnectionState(false);
        assertEquals("Notification count not updated after connection changed to online", 2,
                mNotificationReceivedByObserver);
        assertFalse("Notification not received after connection changed to online",
                mLastNotificationReceivedIsOffline);

        // Change to online again. It should not trigger a notification.
        changeConnectionState(false);
        assertEquals(
                "Extra notification received even though there is no change in connection state", 2,
                mNotificationReceivedByObserver);
        assertFalse(
                "Extra notification received even though there is no change in connection state",
                mLastNotificationReceivedIsOffline);
    }

    /**
     * Tests that when the device switches immediately from offline to online, then the callback is
     * not executed.
     */
    @Test
    public void testCallbackNotInvokedOfflineToFastOnline() {
        // Change to online.
        changeConnectionState(false);
        assertEquals(0, mNotificationReceivedByObserver);
        assertFalse(mLastNotificationReceivedIsOffline);

        // Change to offline.
        changeConnectionState(true);
        assertEquals("Notification received immediately after connection changed to offline", 0,
                mNotificationReceivedByObserver);
        assertFalse("Notification received immediately after connection changed to offline.",
                mLastNotificationReceivedIsOffline);
        final ArgumentCaptor<Runnable> captor = ArgumentCaptor.forClass(Runnable.class);
        verify(mHandler).postDelayed(
                captor.capture(), eq(STATUS_INDICATOR_WAIT_ON_OFFLINE_DURATION_MS));
        advanceTimeByMs(STATUS_INDICATOR_WAIT_ON_OFFLINE_DURATION_MS - 1000L);

        assertEquals("Notification received soon after connection changed to offline", 0,
                mNotificationReceivedByObserver);
        assertFalse("Notification received soon after connection changed to offline",
                mLastNotificationReceivedIsOffline);

        // Change to online.
        changeConnectionState(false);
        assertEquals("Extra notification received after connection changed to online", 0,
                mNotificationReceivedByObserver);
        assertFalse("Connection is reported as offline when it's online",
                mLastNotificationReceivedIsOffline);

        // Move clock forward by 1000ms so that the offline callback posts after
        // |STATUS_INDICATOR_WAIT_ON_OFFLINE_DURATION_MS|. This should not trigger a notification
        // since the connection is now online.
        advanceTimeByMs(1000L);
        captor.getValue().run();
        assertEquals("Extra notification received even though connection is still online", 0,
                mNotificationReceivedByObserver);
        assertFalse("Connection is reported as offline when it's online",
                mLastNotificationReceivedIsOffline);
    }

    private void changeConnectionState(boolean offline) {
        final int state = offline ? ConnectionState.NO_INTERNET : ConnectionState.VALIDATED;
        mOfflineDetector.onConnectionStateChanged(state);
    }

    private void advanceTimeByMs(long delta) {
        mElapsedTimeMs += delta;
        setMockElapsedTimeSupplier(() -> mElapsedTimeMs);
    }

    private void onConnectionStateChanged(boolean offline) {
        mNotificationReceivedByObserver++;
        mLastNotificationReceivedIsOffline = offline;
    }
}
