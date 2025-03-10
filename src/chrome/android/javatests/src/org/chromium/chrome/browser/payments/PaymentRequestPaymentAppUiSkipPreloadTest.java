// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.payments;

import androidx.test.filters.MediumTest;

import org.junit.Assert;
import org.junit.ClassRule;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;

import org.chromium.base.metrics.RecordHistogram;
import org.chromium.base.test.util.CommandLineFlags;
import org.chromium.base.test.util.Feature;
import org.chromium.chrome.R;
import org.chromium.chrome.browser.flags.ChromeSwitches;
import org.chromium.chrome.browser.payments.PaymentRequestTestRule.AppPresence;
import org.chromium.chrome.browser.payments.PaymentRequestTestRule.AppSpeed;
import org.chromium.chrome.browser.payments.PaymentRequestTestRule.FactorySpeed;
import org.chromium.chrome.test.ChromeJUnit4ClassRunner;
import org.chromium.components.payments.PaymentFeatureList;
import org.chromium.ui.test.util.DisableAnimationsTestRule;

import java.util.concurrent.TimeoutException;

/**
 * A payment integration test for a merchant that requests payment via Bob Pay when performing the
 * single payment app UI skip optimization in addition to preloading PaymentRequest even before the
 * "Buy" button is clicked.
 */
@RunWith(ChromeJUnit4ClassRunner.class)
@CommandLineFlags.Add({
        ChromeSwitches.DISABLE_FIRST_RUN_EXPERIENCE,
        // Speed up the test by not looking up actual apps installed on the device.
        "disable-features=" + PaymentFeatureList.SERVICE_WORKER_PAYMENT_APPS,
})
public class PaymentRequestPaymentAppUiSkipPreloadTest {
    // Disable animations to reduce flakiness.
    @ClassRule
    public static DisableAnimationsTestRule sNoAnimationsRule = new DisableAnimationsTestRule();

    @Rule
    public PaymentRequestTestRule mPaymentRequestTestRule =
            new PaymentRequestTestRule("payment_request_bobpay_ui_skip_preload_test.html");

    /**
     * If Bob Pay is supported and installed, user should be able to pay with it. Here Bob Pay
     * responds to Chrome immediately.
     */
    @Test
    @MediumTest
    @Feature({"Payments"})
    public void testPayViaFastBobPay() throws TimeoutException {
        mPaymentRequestTestRule.addPaymentAppFactory(
                AppPresence.HAVE_APPS, FactorySpeed.FAST_FACTORY);
        mPaymentRequestTestRule.openPageAndClickBuyAndWait(mPaymentRequestTestRule.getDismissed());
        mPaymentRequestTestRule.expectResultContains(
                new String[] {"https://bobpay.com", "\"transaction\"", "1337"});
    }

    /**
     * If Bob Pay is supported and installed, user should be able to pay with it. Here Bob Pay
     * responds to Chrome after a slight delay.
     */
    @Test
    @MediumTest
    @Feature({"Payments"})
    public void testPayViaSlowBobPay() throws TimeoutException {
        mPaymentRequestTestRule.addPaymentAppFactory(
                AppPresence.HAVE_APPS, FactorySpeed.FAST_FACTORY);
        mPaymentRequestTestRule.openPageAndClickBuyAndWait(mPaymentRequestTestRule.getDismissed());
        mPaymentRequestTestRule.expectResultContains(
                new String[] {"https://bobpay.com", "\"transaction\"", "1337"});
    }

    /**
     * Test payment with a Bob Pay that is created with a delay, but responds immediately
     * to getInstruments.
     */
    @Test
    @MediumTest
    @Feature({"Payments"})
    public void testPayViaDelayedFastBobPay() throws TimeoutException {
        mPaymentRequestTestRule.addPaymentAppFactory("https://bobpay.com", AppPresence.HAVE_APPS,
                FactorySpeed.FAST_FACTORY, AppSpeed.SLOW_APP);
        mPaymentRequestTestRule.openPageAndClickBuyAndWait(mPaymentRequestTestRule.getDismissed());
        mPaymentRequestTestRule.expectResultContains(
                new String[] {"https://bobpay.com", "\"transaction\"", "1337"});
    }

    /**
     * Test payment with a Bob Pay that is created with a delay, and responds slowly to
     * getInstruments.
     */
    @Test
    @MediumTest
    @Feature({"Payments"})
    public void testPayViaDelayedSlowBobPay() throws TimeoutException {
        mPaymentRequestTestRule.addPaymentAppFactory("https://bobpay.com", AppPresence.HAVE_APPS,
                FactorySpeed.SLOW_FACTORY, AppSpeed.SLOW_APP);
        mPaymentRequestTestRule.openPageAndClickBuyAndWait(mPaymentRequestTestRule.getDismissed());
        mPaymentRequestTestRule.expectResultContains(
                new String[] {"https://bobpay.com", "\"transaction\"", "1337"});
        Assert.assertEquals(1,
                RecordHistogram.getHistogramValueCountForTesting("PaymentRequest.Events",
                        Event.REQUEST_METHOD_OTHER | Event.HAD_INITIAL_FORM_OF_PAYMENT
                                | Event.HAD_NECESSARY_COMPLETE_SUGGESTIONS | Event.SKIPPED_SHOW
                                | Event.AVAILABLE_METHOD_OTHER | Event.SELECTED_OTHER
                                | Event.PAY_CLICKED | Event.RECEIVED_INSTRUMENT_DETAILS
                                | Event.COMPLETED));
    }

    /** Two payments apps with the same payment method name should not skip payments UI. */
    @Test
    @MediumTest
    @Feature({"Payments"})
    public void testTwoPaymentsAppsWithTheSamePaymentMethodName() throws TimeoutException {
        mPaymentRequestTestRule.addPaymentAppFactory("https://bobpay.com", AppPresence.HAVE_APPS,
                FactorySpeed.FAST_FACTORY, AppSpeed.FAST_APP);
        mPaymentRequestTestRule.addPaymentAppFactory("https://bobpay.com", AppPresence.HAVE_APPS,
                FactorySpeed.FAST_FACTORY, AppSpeed.FAST_APP);
        mPaymentRequestTestRule.triggerUIAndWait(mPaymentRequestTestRule.getReadyToPay());
        mPaymentRequestTestRule.clickAndWait(
                R.id.button_primary, mPaymentRequestTestRule.getDismissed());
        mPaymentRequestTestRule.expectResultContains(
                new String[] {"https://bobpay.com", "\"transaction\"", "1337"});
        Assert.assertEquals(1,
                RecordHistogram.getHistogramValueCountForTesting("PaymentRequest.Events",
                        Event.REQUEST_METHOD_OTHER | Event.HAD_INITIAL_FORM_OF_PAYMENT
                                | Event.HAD_NECESSARY_COMPLETE_SUGGESTIONS | Event.SHOWN
                                | Event.AVAILABLE_METHOD_OTHER | Event.SELECTED_OTHER
                                | Event.PAY_CLICKED | Event.RECEIVED_INSTRUMENT_DETAILS
                                | Event.COMPLETED));
    }
}
