// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.ui.default_browser_promo;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.role.RoleManager;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.provider.Settings;

import androidx.annotation.VisibleForTesting;

import org.chromium.chrome.browser.flags.ChromeFeatureList;
import org.chromium.chrome.browser.lifecycle.ActivityLifecycleDispatcher;
import org.chromium.chrome.browser.lifecycle.Destroyable;
import org.chromium.chrome.browser.lifecycle.PauseResumeWithNativeObserver;
import org.chromium.chrome.browser.preferences.ChromePreferenceKeys;
import org.chromium.chrome.browser.preferences.SharedPreferencesManager;
import org.chromium.chrome.browser.ui.default_browser_promo.DefaultBrowserPromoDialog.DialogStyle;
import org.chromium.chrome.browser.ui.default_browser_promo.DefaultBrowserPromoMetrics.UIDismissalReason;
import org.chromium.chrome.browser.ui.default_browser_promo.DefaultBrowserPromoUtils.DefaultBrowserState;
import org.chromium.ui.base.WindowAndroid;

/**
 * Manage all types of default browser promo dialogs and listen to the activity state change to
 * trigger dialogs.
 */
public class DefaultBrowserPromoManager implements PauseResumeWithNativeObserver, Destroyable {
    private static final String SKIP_PRIMER_PARAM = "skip_primer";

    private final Activity mActivity;
    private DefaultBrowserPromoDialog mDialog;
    private @DefaultBrowserState int mCurrentState;
    private @DialogStyle Integer mPromoStyle;
    private ActivityLifecycleDispatcher mDispatcher;
    private WindowAndroid mWindowAndroid;

    /**
     * @param activity Activity to show promo dialogs.
     * @param dispatcher The {@link ActivityLifecycleDispatcher} of the current activity.
     * @param windowAndroid The {@link WindowAndroid} for sending an intent.
     * @return A {@link DefaultBrowserPromoManager} displaying dialogs based on android version and
     *         current default browser state in system.
     */
    public static DefaultBrowserPromoManager create(Activity activity,
            ActivityLifecycleDispatcher dispatcher, WindowAndroid windowAndroid) {
        return new DefaultBrowserPromoManager(activity, dispatcher, windowAndroid);
    }

    private DefaultBrowserPromoManager(Activity activity, ActivityLifecycleDispatcher dispatcher,
            WindowAndroid windowAndroid) {
        mActivity = activity;
        mDispatcher = dispatcher;
        mDispatcher.register(this);
        mWindowAndroid = windowAndroid;
    }

    /**
     * @param state The current {@link DefaultBrowserPromoUtils.DefaultBrowserState} in system.
     */
    public void promo(@DefaultBrowserPromoUtils.DefaultBrowserState int state) {
        promoInternal(state, Build.VERSION.SDK_INT);
    }

    private void promoInternal(
            @DefaultBrowserPromoUtils.DefaultBrowserState int state, int sdkInt) {
        mCurrentState = state;
        if (sdkInt >= Build.VERSION_CODES.Q) {
            promoByRoleManager();
        } else if (state == DefaultBrowserPromoUtils.DefaultBrowserState.NO_DEFAULT) {
            promoByDisambiguationSheet();
        } else if (sdkInt >= Build.VERSION_CODES.M) {
            promoBySystemSettings();
        }
    }

    @SuppressLint({"WrongConstant", "NewApi"})
    private void promoByRoleManager() {
        mPromoStyle = DialogStyle.ROLE_MANAGER;
        boolean shouldSkipPrimer = ChromeFeatureList.getFieldTrialParamByFeatureAsBoolean(
                ChromeFeatureList.ANDROID_DEFAULT_BROWSER_PROMO, SKIP_PRIMER_PARAM, false);
        Runnable onOK = () -> {
            RoleManager roleManager =
                    (RoleManager) mActivity.getSystemService(Context.ROLE_SERVICE);
            boolean isRoleAvailable = roleManager.isRoleAvailable(RoleManager.ROLE_BROWSER);
            boolean isRoleHeld = roleManager.isRoleHeld(RoleManager.ROLE_BROWSER);

            // TODO(crbug.com/1090103): check the condition before deciding
            // to show promo and remove the assertion.
            assert isRoleAvailable && !isRoleHeld;

            DefaultBrowserPromoMetrics.recordRoleManagerShow(mCurrentState);
            if (!shouldSkipPrimer) {
                DefaultBrowserPromoMetrics.recordUiDismissalReason(
                        mCurrentState, UIDismissalReason.CHANGE_DEFAULT);
            }

            Intent intent = roleManager.createRequestRoleIntent(RoleManager.ROLE_BROWSER);
            mWindowAndroid.showCancelableIntent(intent, (window, resultCode, data) -> {
                DefaultBrowserPromoMetrics.recordOutcome(
                        mCurrentState, DefaultBrowserPromoUtils.getCurrentDefaultBrowserState());
            }, null);
            destroy();
        };
        if (shouldSkipPrimer) {
            onOK.run();
        } else {
            showDialog(DefaultBrowserPromoDialog.DialogStyle.ROLE_MANAGER, onOK);
        }
    }

    private void promoBySystemSettings() {
        mPromoStyle = DialogStyle.SYSTEM_SETTINGS;
        showDialog(DefaultBrowserPromoDialog.DialogStyle.SYSTEM_SETTINGS, () -> {
            // Users are leaving Chrome, so the app may be shut down or killed in the background.
            // Save state to pref for checking result on the next app start up.
            SharedPreferencesManager.getInstance().writeBoolean(
                    ChromePreferenceKeys.DEFAULT_BROWSER_PROMO_PROMOED_BY_SYSTEM_SETTINGS, true);
            SharedPreferencesManager.getInstance().writeInt(
                    ChromePreferenceKeys.DEFAULT_BROWSER_PROMO_LAST_DEFAULT_STATE, mCurrentState);
            DefaultBrowserPromoMetrics.recordUiDismissalReason(
                    mCurrentState, UIDismissalReason.CHANGE_DEFAULT);

            Intent intent = new Intent(Settings.ACTION_MANAGE_DEFAULT_APPS_SETTINGS);
            mActivity.startActivity(intent);
        });
    }

    private void promoByDisambiguationSheet() {
        mPromoStyle = DialogStyle.DISAMBIGUATION_SHEET;
        showDialog(DialogStyle.DISAMBIGUATION_SHEET, () -> {
            DefaultBrowserPromoMetrics.recordUiDismissalReason(
                    mCurrentState, UIDismissalReason.CHANGE_DEFAULT);

            Intent intent = new Intent(Intent.ACTION_MAIN);
            intent.addCategory(Intent.CATEGORY_BROWSABLE);
            mActivity.startActivity(intent);
        });
    }

    private void showDialog(@DialogStyle int style, Runnable okCallback) {
        mDialog = DefaultBrowserPromoDialog.createDialog(mActivity, style, okCallback, () -> {
            DefaultBrowserPromoMetrics.recordUiDismissalReason(
                    mCurrentState, UIDismissalReason.NO_THANKS);
            destroy();
        });

        DefaultBrowserPromoMetrics.recordDialogShow(mCurrentState);
        mDialog.show();
    }

    @Override
    public void onResumeWithNative() {
        // TODO(crbug.com/1090103): Edge case: user might shut down chrome when disambiguation sheet
        // or role manager dialog is shown, leading to no metrics recording.
        if (mPromoStyle == DialogStyle.DISAMBIGUATION_SHEET) {
            DefaultBrowserPromoMetrics.recordOutcome(
                    mCurrentState, DefaultBrowserPromoUtils.getCurrentDefaultBrowserState());
            destroy();
        } else if (mPromoStyle == DialogStyle.SYSTEM_SETTINGS) {
            // Result may also be confirmed on start up of chrome tabbed activity.
            DefaultBrowserPromoUtils.maybeRecordOutcomeOnStart();
            destroy();
        }
    }

    @Override
    public void onPauseWithNative() {}

    @Override
    public void destroy() {
        mPromoStyle = null;
        mDispatcher.unregister(this);
    }

    @VisibleForTesting
    public DefaultBrowserPromoDialog getDialogForTesting() {
        return mDialog;
    }

    @VisibleForTesting
    public void promoForTesting(
            @DefaultBrowserPromoUtils.DefaultBrowserState int state, int sdkInt) {
        promoInternal(state, sdkInt);
    }
}
