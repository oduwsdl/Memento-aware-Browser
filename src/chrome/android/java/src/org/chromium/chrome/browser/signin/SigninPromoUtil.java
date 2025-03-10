// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.chrome.browser.signin;

import android.accounts.Account;
import android.app.Activity;
import android.text.TextUtils;

import androidx.annotation.VisibleForTesting;
import androidx.collection.ArraySet;

import org.chromium.base.annotations.CalledByNative;
import org.chromium.base.supplier.Supplier;
import org.chromium.chrome.browser.ChromeVersionInfo;
import org.chromium.chrome.browser.preferences.Pref;
import org.chromium.chrome.browser.preferences.PrefServiceBridge;
import org.chromium.components.signin.AccountManagerFacadeProvider;
import org.chromium.components.signin.AccountUtils;
import org.chromium.components.signin.metrics.SigninAccessPoint;
import org.chromium.ui.base.WindowAndroid;

import java.util.Collections;
import java.util.List;
import java.util.Set;

/**
* Helper functions for promoting sign in.
*/
public class SigninPromoUtil {
    private SigninPromoUtil() {}

    /**
     * Launches the signin promo if it needs to be displayed.
     * @param activity The parent activity.
     * @return Whether the signin promo is shown.
     */
    public static boolean launchSigninPromoIfNeeded(final Activity activity) {
        SigninPreferencesManager preferencesManager = SigninPreferencesManager.getInstance();
        int currentMajorVersion = ChromeVersionInfo.getProductMajorVersion();
        boolean wasSignedIn = TextUtils.isEmpty(
                PrefServiceBridge.getInstance().getString(Pref.GOOGLE_SERVICES_LAST_USERNAME));
        List<String> accountNames = AccountUtils.toAccountNames(
                AccountManagerFacadeProvider.getInstance().tryGetGoogleAccounts());
        Supplier<Set<String>> accountNamesSupplier = () -> new ArraySet<>(accountNames);
        if (!shouldLaunchSigninPromo(preferencesManager, currentMajorVersion,
                    IdentityServicesProvider.get().getIdentityManager().hasPrimaryAccount(),
                    wasSignedIn, accountNamesSupplier)) {
            return false;
        }

        SigninUtils.startSigninActivityIfAllowed(activity, SigninAccessPoint.SIGNIN_PROMO);
        preferencesManager.setSigninPromoLastShownVersion(currentMajorVersion);
        preferencesManager.setSigninPromoLastAccountNames(new ArraySet<>(accountNames));
        return true;
    }

    /**
     * Launches the signin promo if it needs to be displayed.
     * @param preferencesManager the preferences manager to persist data
     * @param currentMajorVersion the current major version of Chrome
     * @param isSignedIn is user currently signed in
     * @param wasSignedIn has used manually signed out
     * @param accountNamesSupplier the supplier of the set of account names currently on device.
     *         Supplier is used here because AccountManagerFacade cache may be not populated yet, so
     *         it makes sense to check other flags before getting accounts.
     * @return Whether the signin promo should be shown.
     */
    @VisibleForTesting
    static boolean shouldLaunchSigninPromo(SigninPreferencesManager preferencesManager,
            int currentMajorVersion, boolean isSignedIn, boolean wasSignedIn,
            Supplier<Set<String>> accountNamesSupplier) {
        int lastPromoMajorVersion = preferencesManager.getSigninPromoLastShownVersion();
        if (lastPromoMajorVersion == 0) {
            preferencesManager.setSigninPromoLastShownVersion(currentMajorVersion);
            return false;
        }

        // Don't show if user is signed in.
        if (isSignedIn) return false;

        // Don't show if user has manually signed out.
        if (wasSignedIn) return false;

        // Promo can be shown at most once every 2 Chrome major versions.
        if (currentMajorVersion < lastPromoMajorVersion + 2) return false;

        // Defer getting accounts, as AccountManagerFacade cache may be not populated yet.
        Set<String> accountNames = accountNamesSupplier.get();
        // Don't show if there are no Google accounts on the device.
        if (accountNames.isEmpty()) return false;

        // Don't show if no new accounts have been added after the last time promo was shown.
        Set<String> previousAccountNames = preferencesManager.getSigninPromoLastAccountNames();
        return previousAccountNames == null || !previousAccountNames.containsAll(accountNames);
    }

    /**
     * @param signinPromoController The {@link SigninPromoController} that maintains the view.
     * @param profileDataCache The {@link ProfileDataCache} that stores profile data.
     * @param view The {@link PersonalizedSigninPromoView} that should be set up.
     * @param listener The {@link SigninPromoController.OnDismissListener} to be set to the view.
     */
    public static void setupPromoViewFromCache(SigninPromoController signinPromoController,
            ProfileDataCache profileDataCache, PersonalizedSigninPromoView view,
            SigninPromoController.OnDismissListener listener) {
        DisplayableProfileData profileData = null;
        List<Account> accounts = AccountManagerFacadeProvider.getInstance().tryGetGoogleAccounts();
        if (accounts.size() > 0) {
            String defaultAccountName = accounts.get(0).name;
            profileDataCache.update(Collections.singletonList(defaultAccountName));
            profileData = profileDataCache.getProfileDataOrDefault(defaultAccountName);
        }
        signinPromoController.detach();
        signinPromoController.setupPromoView(view.getContext(), view, profileData, listener);
    }

    /**
     * A convenience method to create an SigninActivity, passing the access point as an
     * intent extra.
     * @param window WindowAndroid from which to get the Activity/Context.
     * @param accessPoint for metrics purposes.
     */
    @CalledByNative
    private static void openSigninActivityForPromo(WindowAndroid window, int accessPoint) {
        Activity activity = window.getActivity().get();
        if (activity != null) {
            SigninUtils.startSigninActivityIfAllowed(activity, accessPoint);
        }
    }
}
