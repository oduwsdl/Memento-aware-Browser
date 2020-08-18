// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE FEATURES FILE:
//   ['../../extensions/common/api/_api_features.json']
// DO NOT EDIT.

#include "extensions/common/api/api_features.h"

#include "extensions/common/features/complex_feature.h"
#include "extensions/common/features/feature_provider.h"
#include "extensions/common/features/manifest_feature.h"
#include "extensions/common/features/permission_feature.h"

namespace extensions {

void AddCoreAPIFeatures(FeatureProvider* provider) {
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("alarms");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:alarms"});
    provider->AddFeature("alarms", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("app.currentWindowInternal");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT});
    feature->set_internal(true);
    feature->set_noparent(true);
    provider->AddFeature("app.currentWindowInternal", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("app.currentWindowInternal.setShape");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:app.window.shape"});
    feature->set_internal(true);
    feature->set_noparent(true);
    provider->AddFeature("app.currentWindowInternal.setShape", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("app.runtime");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT});
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_noparent(true);
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("app.runtime");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_component_extensions_auto_granted(false);
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_noparent(true);
      feature->set_allowlist({"2FC374607C2DF285634B67C64A2E356C607091C3","3727DD3E564B6055387425027AD74C58784ACC15","12E618C3C6E97495AAECF2AC12DEB082353241C6"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("app.runtime");
    provider->AddFeature("app.runtime", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("app.window");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT});
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_noparent(true);
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("app.window");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_component_extensions_auto_granted(false);
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_noparent(true);
      feature->set_allowlist({"B9EF10DDFEA11EF77873CC5009809E5037FC4C7A","06BE211D5F014BAB34BC22D9DDA09C63A81D828E","F94EE6AB36D6C6588670B2B01EB65212D9C64E33"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("app.window");
    provider->AddFeature("app.window", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("appViewEmbedderInternal");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:appview"});
    feature->set_internal(true);
    provider->AddFeature("appViewEmbedderInternal", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("appViewGuestInternal");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_internal(true);
    provider->AddFeature("appViewGuestInternal", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("audio");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:audio"});
    provider->AddFeature("audio", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("automation");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:automation"});
    provider->AddFeature("automation", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("automation.languageAnnotationForStringAttribute");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_command_line_switch("enable-experimental-accessibility-chromevox-sub-node-language-switching");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:automation"});
    provider->AddFeature("automation.languageAnnotationForStringAttribute", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("automationInternal");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:automation"});
    feature->set_internal(true);
    provider->AddFeature("automationInternal", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("bluetooth");
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_dependencies({"manifest:bluetooth"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("bluetooth");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_matches({"chrome://bluetooth-pairing/*","chrome://os-settings/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("bluetooth");
    provider->AddFeature("bluetooth", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("bluetoothLowEnergy");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:bluetooth"});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM,Feature::LINUX_PLATFORM});
    provider->AddFeature("bluetoothLowEnergy", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("bluetoothPrivate");
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_dependencies({"permission:bluetoothPrivate"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("bluetoothPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_matches({"chrome://bluetooth-pairing/*","chrome://os-settings/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("bluetoothPrivate");
    provider->AddFeature("bluetoothPrivate", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("bluetoothSocket");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:bluetooth"});
    provider->AddFeature("bluetoothSocket", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("cecPrivate");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:cecPrivate"});
    provider->AddFeature("cecPrivate", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("clipboard");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:clipboard"});
    provider->AddFeature("clipboard", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("clipboard.onClipboardDataChanged");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:clipboardRead"});
    provider->AddFeature("clipboard.onClipboardDataChanged", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("clipboard.setImageData");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:clipboardWrite"});
    provider->AddFeature("clipboard.setImageData", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("crashReportPrivate");
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_dependencies({"permission:crashReportPrivate"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("crashReportPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_UNTRUSTED_CONTEXT});
      feature->set_matches({"chrome-untrusted://help-app/*","chrome-untrusted://media-app/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("crashReportPrivate");
    provider->AddFeature("crashReportPrivate", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("declarativeNetRequest");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:declarativeNetRequest"});
    provider->AddFeature("declarativeNetRequest", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("declarativeNetRequest.onRuleMatchedDebug");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:declarativeNetRequest","permission:declarativeNetRequestFeedback"});
    feature->set_location(SimpleFeature::UNPACKED_LOCATION);
    provider->AddFeature("declarativeNetRequest.onRuleMatchedDebug", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("declarativeWebRequest");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:declarativeWebRequest"});
    provider->AddFeature("declarativeWebRequest", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("diagnostics");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:diagnostics"});
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("diagnostics", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("displaySource");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:displaySource"});
    provider->AddFeature("displaySource", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("dns");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:dns"});
    provider->AddFeature("dns", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("documentScan");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:documentScan"});
    provider->AddFeature("documentScan", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("events");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::CONTENT_SCRIPT_CONTEXT,Feature::WEBUI_UNTRUSTED_CONTEXT,Feature::WEBUI_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT,Feature::WEB_PAGE_CONTEXT,Feature::UNBLESSED_EXTENSION_CONTEXT,Feature::BLESSED_EXTENSION_CONTEXT,Feature::BLESSED_WEB_PAGE_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_EXTENSION});
    feature->set_internal(true);
    feature->set_matches({"<all_urls>"});
    provider->AddFeature("events", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("extensionTypes");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_internal(true);
    provider->AddFeature("extensionTypes", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("feedbackPrivate");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:feedbackPrivate"});
    provider->AddFeature("feedbackPrivate", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("feedbackPrivate.readLogSource");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:feedbackPrivate"});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_session_types({FeatureSessionType::KIOSK});
    provider->AddFeature("feedbackPrivate.readLogSource", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("fileSystem");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:fileSystem"});
    feature->set_disallow_for_service_workers(true);
    provider->AddFeature("fileSystem", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("guestViewInternal");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_internal(true);
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("guestViewInternal");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_internal(true);
      feature->set_matches({"chrome://add-supervision/*","chrome://assistant-optin/*","chrome://cellular-setup/*","chrome://discards/*","chrome://extensions/*","chrome://home/*","chrome://chrome-signin/*","chrome://hats/*","chrome://mobilesetup/*","chrome://oobe/*","chrome://password-change/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("guestViewInternal");
    provider->AddFeature("guestViewInternal", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("hid");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:hid"});
    provider->AddFeature("hid", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("hid.getUserSelectedDevices");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:hid"});
    provider->AddFeature("hid.getUserSelectedDevices", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("idle");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:idle"});
    provider->AddFeature("idle", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("idle.getAutoLockDelay");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:idle"});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("idle.getAutoLockDelay", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("lockScreen.data");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:lockScreen"});
    provider->AddFeature("lockScreen.data", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("lockScreen.data.create");
    feature->set_contexts({Feature::LOCK_SCREEN_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:lockScreen"});
    provider->AddFeature("lockScreen.data.create", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("management");
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_dependencies({"permission:management"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("management");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_matches({"chrome://extensions/*","chrome://settings/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("management");
    provider->AddFeature("management", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("management.canInstallReplacementAndroidApp");
    feature->set_channel(version_info::Channel::UNKNOWN);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:replacement_android_app"});
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("management.canInstallReplacementAndroidApp", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("management.getPermissionWarningsByManifest");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("management.getPermissionWarningsByManifest", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("management.getSelf");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("management.getSelf", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("management.installReplacementAndroidApp");
    feature->set_channel(version_info::Channel::UNKNOWN);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:replacement_android_app"});
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("management.installReplacementAndroidApp", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("management.installReplacementWebApp");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:replacement_web_app"});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("management.installReplacementWebApp", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("management.uninstallSelf");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("management.uninstallSelf", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("mediaPerceptionPrivate");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:mediaPerceptionPrivate"});
    provider->AddFeature("mediaPerceptionPrivate", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("metricsPrivate");
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_dependencies({"permission:metricsPrivate"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("metricsPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_matches({"chrome://bookmarks/*","chrome://extensions/*","chrome://os-settings/*","chrome://settings/*","chrome://sync-confirmation/*","chrome://tab-strip/*","chrome://welcome/*"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("metricsPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_UNTRUSTED_CONTEXT});
      feature->set_matches({"chrome-untrusted://help-app/*","chrome-untrusted://media-app/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("metricsPrivate");
    provider->AddFeature("metricsPrivate", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("metricsPrivate.getIsCrashReportingEnabled");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:metricsPrivate"});
    feature->set_allowlist({"2FC374607C2DF285634B67C64A2E356C607091C3","3727DD3E564B6055387425027AD74C58784ACC15","12E618C3C6E97495AAECF2AC12DEB082353241C6","3727DD3E564B6055387425027AD74C58784ACC15","C41AD9DCD670210295614257EF8C9945AD68D86E","D7986543275120831B39EF28D1327552FC343960","A291B26E088FA6BA53FFD72F0916F06EBA7C585A","07BD6A765FFC289FF755D7CAB2893A40EC337FEC","896B85CC7E913E11C34892C1425A093C0701D386","11A01C82EF355E674E4F9728A801F5C3CB40D83F","F410C88469990EE7947450311D24B8AF2ADB2595","63ED55E43214C211F82122ED56407FF1A807F2A3","226CF815E39A363090A1E547D53063472B8279FA","B620CF4203315F9F2E046EDED22C7571A935958D","B206D8716769728278D2D300349C6CB7D7DE2EF9","2B6C6A4A5940017146F3E58B7F90116206E84685","B6C2EFAB3EC3BF6EF03701408B6B09A67B2D0069","96FF2FFA5C9173C76D47184B3E86D267B37781DE","0136FCB13DB29FD5CD442F56E59E53B61F1DF96F","46578A13607D38F1DC8E280C4F499FB0A2F9565C","898FB5A39687D210766B8998BA4530B99C9E6586","82F30B65397BC3E4ADE627BBD857AB8A58210648","A3E3DE9E9F16B41D4A2FAD106BD6CA76B94A0C94","B41E7F08E1179CC03CBD1F49E57CF353A40ADE07","C74B2AF138F9EDECD04D0965AB36CA66C8290466"});
    provider->AddFeature("metricsPrivate.getIsCrashReportingEnabled", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("mimeHandlerPrivate");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:mime_types_handler"});
    provider->AddFeature("mimeHandlerPrivate", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("mojoPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_EXTENSION});
    feature->set_allowlist({"63ED55E43214C211F82122ED56407FF1A807F2A3","226CF815E39A363090A1E547D53063472B8279FA","B41E7F08E1179CC03CBD1F49E57CF353A40ADE07","A3E3DE9E9F16B41D4A2FAD106BD6CA76B94A0C94"});
    provider->AddFeature("mojoPrivate", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("networking.config");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:networking.config"});
    provider->AddFeature("networking.config", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("networking.onc");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:networking.onc"});
    feature->set_source("networkingPrivate");
    provider->AddFeature("networking.onc", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("networkingPrivate");
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_dependencies({"permission:networkingPrivate"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("networkingPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_matches({"chrome://network/*","chrome://oobe/*","chrome://internet-config-dialog/*","chrome://internet-detail-dialog/*","chrome://os-settings/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("networkingPrivate");
    feature->set_alias("networking.onc");
    provider->AddFeature("networkingPrivate", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("power");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:power"});
    provider->AddFeature("power", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("printerProvider");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:printerProvider"});
    feature->set_disallow_for_service_workers(true);
    provider->AddFeature("printerProvider", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("printerProviderInternal");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:printerProvider"});
    feature->set_disallow_for_service_workers(true);
    feature->set_internal(true);
    provider->AddFeature("printerProviderInternal", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("runtime", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime.connect");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_WEB_PAGE_CONTEXT,Feature::CONTENT_SCRIPT_CONTEXT,Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT,Feature::UNBLESSED_EXTENSION_CONTEXT,Feature::WEB_PAGE_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    feature->set_matches({"<all_urls>"});
    provider->AddFeature("runtime.connect", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime.connectNative");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:nativeMessaging"});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("runtime.connectNative", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime.getBackgroundPage");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT});
    feature->set_disallow_for_service_workers(true);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("runtime.getBackgroundPage", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime.getManifest");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT,Feature::UNBLESSED_EXTENSION_CONTEXT,Feature::CONTENT_SCRIPT_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("runtime.getManifest", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime.getURL");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT,Feature::UNBLESSED_EXTENSION_CONTEXT,Feature::CONTENT_SCRIPT_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("runtime.getURL", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime.id");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT,Feature::UNBLESSED_EXTENSION_CONTEXT,Feature::CONTENT_SCRIPT_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("runtime.id", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime.lastError");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::CONTENT_SCRIPT_CONTEXT,Feature::WEBUI_UNTRUSTED_CONTEXT,Feature::WEBUI_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT,Feature::WEB_PAGE_CONTEXT,Feature::UNBLESSED_EXTENSION_CONTEXT,Feature::BLESSED_EXTENSION_CONTEXT,Feature::BLESSED_WEB_PAGE_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    feature->set_matches({"<all_urls>"});
    provider->AddFeature("runtime.lastError", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime.onConnect");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT,Feature::UNBLESSED_EXTENSION_CONTEXT,Feature::CONTENT_SCRIPT_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("runtime.onConnect", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime.onConnectNative");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:nativeMessaging"});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("runtime.onConnectNative", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime.onMessage");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT,Feature::UNBLESSED_EXTENSION_CONTEXT,Feature::CONTENT_SCRIPT_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("runtime.onMessage", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("runtime.sendMessage");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::BLESSED_WEB_PAGE_CONTEXT,Feature::CONTENT_SCRIPT_CONTEXT,Feature::BLESSED_EXTENSION_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT,Feature::UNBLESSED_EXTENSION_CONTEXT,Feature::WEB_PAGE_CONTEXT});
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
      feature->set_matches({"<all_urls>"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("runtime.sendMessage");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
      feature->set_matches({"chrome://password-change/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("runtime.sendMessage");
    provider->AddFeature("runtime.sendMessage", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("runtime.sendNativeMessage");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:nativeMessaging"});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("runtime.sendNativeMessage", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("serial");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:serial"});
    provider->AddFeature("serial", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("socket");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:socket"});
    provider->AddFeature("socket", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("sockets.tcp");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:sockets"});
    provider->AddFeature("sockets.tcp", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("sockets.tcpServer");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:sockets"});
    provider->AddFeature("sockets.tcpServer", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("sockets.udp");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"manifest:sockets"});
    provider->AddFeature("sockets.udp", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("storage");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::UNBLESSED_EXTENSION_CONTEXT,Feature::CONTENT_SCRIPT_CONTEXT});
    feature->set_dependencies({"permission:storage"});
    provider->AddFeature("storage", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("system.cpu");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:system.cpu"});
    provider->AddFeature("system.cpu", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("system.display");
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_dependencies({"permission:system.display"});
      feature->set_disallow_for_service_workers(true);
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("system.display");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_matches({"chrome://os-settings/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("system.display");
    provider->AddFeature("system.display", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("system.memory");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:system.memory"});
    provider->AddFeature("system.memory", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("system.network");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:system.network"});
    provider->AddFeature("system.network", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("system.powerSource");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:system.powerSource"});
    provider->AddFeature("system.powerSource", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("system.storage");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:system.storage"});
    provider->AddFeature("system.storage", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("system.storage.getAvailableCapacity");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:system.storage"});
    provider->AddFeature("system.storage.getAvailableCapacity", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("test");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT,Feature::BLESSED_WEB_PAGE_CONTEXT,Feature::CONTENT_SCRIPT_CONTEXT,Feature::LOCK_SCREEN_EXTENSION_CONTEXT,Feature::UNBLESSED_EXTENSION_CONTEXT});
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("test");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_matches({"chrome://extensions/*"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("test");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_UNTRUSTED_CONTEXT});
      feature->set_matches({"chrome-untrusted://api-test/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("test");
    provider->AddFeature("test", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("types");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_internal(true);
    provider->AddFeature("types", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("usb");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:usb"});
    provider->AddFeature("usb", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("virtualKeyboard");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:virtualKeyboard"});
    provider->AddFeature("virtualKeyboard", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("vpnProvider");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:vpnProvider"});
    provider->AddFeature("vpnProvider", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("webRequest");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:webRequest"});
    provider->AddFeature("webRequest", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("webRequestInternal");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_internal(true);
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("webRequestInternal");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_internal(true);
      feature->set_matches({"chrome://add-supervision/*","chrome://assistant-optin/*","chrome://cellular-setup/*","chrome://chrome-signin/*","chrome://discards/*","chrome://hats/*","chrome://home/*","chrome://mobilesetup/*","chrome://oobe/*","chrome://password-change/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("webRequestInternal");
    provider->AddFeature("webRequestInternal", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("webViewInternal");
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_dependencies({"permission:webview"});
      feature->set_internal(true);
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("webViewInternal");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_internal(true);
      feature->set_matches({"chrome://add-supervision/*","chrome://assistant-optin/*","chrome://cellular-setup/*","chrome://chrome-signin/*","chrome://discards/*","chrome://hats/*","chrome://home/*","chrome://mobilesetup/*","chrome://oobe/*","chrome://password-change/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("webViewInternal");
    provider->AddFeature("webViewInternal", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("webViewRequest");
      feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
      feature->set_dependencies({"permission:webview"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("webViewRequest");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_contexts({Feature::WEBUI_CONTEXT});
      feature->set_matches({"chrome://add-supervision/*","chrome://assistant-optin/*","chrome://cellular-setup/*","chrome://chrome-signin/*","chrome://discards/*","chrome://hats/*","chrome://home/*","chrome://mobilesetup/*","chrome://oobe/*"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("webViewRequest");
    provider->AddFeature("webViewRequest", feature);
  }

}

}  // namespace extensions