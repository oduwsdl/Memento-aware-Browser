// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE FEATURES FILE:
//   ['../../extensions/common/api/_manifest_features.json']
// DO NOT EDIT.

#include "extensions/common/api/manifest_features.h"

#include "extensions/common/features/complex_feature.h"
#include "extensions/common/features/feature_provider.h"
#include "extensions/common/features/manifest_feature.h"
#include "extensions/common/features/permission_feature.h"

namespace extensions {

void AddCoreManifestFeatures(FeatureProvider* provider) {
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("action_handlers");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("action_handlers", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("app");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("app", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("app.background");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_min_manifest_version(2);
    provider->AddFeature("app.background", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("app.content_security_policy");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_min_manifest_version(2);
    feature->set_allowlist({"53041A2FA309EECED01FFC751E7399186E860B2C","312745D9BF916161191143F6490085EEA0434997","E7E2461CE072DF036CF9592740196159E2D7C089","A74A4D44C7CFCD8844830E6140C8D763E12DD8F3","5107DE9024C329EEA9C9A72D94C16723790C6422"});
    provider->AddFeature("app.content_security_policy", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("background");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("background", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("background.persistent");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    feature->set_min_manifest_version(2);
    provider->AddFeature("background.persistent", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("background.service_worker");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_min_manifest_version(2);
    provider->AddFeature("background.service_worker", feature);
  }
  {
    std::vector<Feature*> features;
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("bluetooth");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM,Feature::WIN_PLATFORM,Feature::MACOSX_PLATFORM});
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("bluetooth");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::LINUX_PLATFORM});
      feature->set_allowlist({"9E287A8257E58EFB13E89C86A4B75A3AC4B058D8","1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","307E96539209F95A1A8740C713E6998A73657D96","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB","A9A9FC0228ADF541F0334F22BEFB8F9C245B21D7"});
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("bluetooth");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"75C7F4B720314B6CB1B5817CD86089DB95CD2461"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("bluetooth");
    provider->AddFeature("bluetooth", feature);
  }
  {
    std::vector<Feature*> features;
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("content_capabilities");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"950D13BB9B4794F4CA2A68D3597E5DFAA47C88AE","0EEB39B7A9A52CAAE6A072F83320435749B184A4","99717FF3BE1AFB5B343CDD024E53873C1783521B","4895B1DBB92D52488F8D9FFDF9CC7B95C7258C9A","A3880AA78DB0004DE841CC980959D8443F3A8E40","C8B53B3C2CC39CB504B19D990165684FF0CE880C"});
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("content_capabilities");
      feature->set_channel(version_info::Channel::CANARY);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("content_capabilities");
    provider->AddFeature("content_capabilities", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("content_security_policy");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("content_security_policy", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("current_locale");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("current_locale", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("declarative_net_request");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_feature_flag("DeclarativeNetRequest");
    feature->set_min_manifest_version(2);
    provider->AddFeature("declarative_net_request", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("default_locale");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("default_locale", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("description");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("description", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("differential_fingerprint");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("differential_fingerprint", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("externally_connectable");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("externally_connectable", feature);
  }
  {
    std::vector<Feature*> features;
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("file_handlers");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_HOSTED_APP});
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("file_handlers");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"2FC374607C2DF285634B67C64A2E356C607091C3","3727DD3E564B6055387425027AD74C58784ACC15","12E618C3C6E97495AAECF2AC12DEB082353241C6"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("file_handlers");
    provider->AddFeature("file_handlers", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("host_permissions");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_min_manifest_version(3);
    provider->AddFeature("host_permissions", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("icons");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("icons", feature);
  }
  {
    std::vector<Feature*> features;
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("incognito");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("incognito");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_location(SimpleFeature::COMPONENT_LOCATION);
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("incognito");
    provider->AddFeature("incognito", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("key");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("key", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("kiosk");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("kiosk", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("kiosk.always_update");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("kiosk.always_update", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("kiosk.required_platform_version");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("kiosk.required_platform_version", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("kiosk_enabled");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("kiosk_enabled", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("kiosk_only");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("kiosk_only", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("kiosk_secondary_apps");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("kiosk_secondary_apps", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("manifest_version");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("manifest_version", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("mime_types");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"787000072C6FBB934AF5A42275CDE73FC977D995","2FC374607C2DF285634B67C64A2E356C607091C3","5D3851BEFF680AB6D954B76678EFCCE834465C23","12E618C3C6E97495AAECF2AC12DEB082353241C6","3727DD3E564B6055387425027AD74C58784ACC15","CBCC42ABED43A4B58FE3810E62AFFA010EB0349F"});
    provider->AddFeature("mime_types", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("mime_types_handler");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"787000072C6FBB934AF5A42275CDE73FC977D995","2FC374607C2DF285634B67C64A2E356C607091C3","12E618C3C6E97495AAECF2AC12DEB082353241C6","3727DD3E564B6055387425027AD74C58784ACC15","CBCC42ABED43A4B58FE3810E62AFFA010EB0349F"});
    provider->AddFeature("mime_types_handler", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("nacl_modules");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_max_manifest_version(2);
    provider->AddFeature("nacl_modules", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("name");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("name", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("oauth2");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("oauth2", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("oauth2.auto_approve");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"F57FDBA2822F21B82A4C417405ABC51241CC6426","C41AD9DCD670210295614257EF8C9945AD68D86E","64291898C201DAF15B090EC4B9EC270BEB6BE6FF","4B1D0E19C6C43C008C44A8278C8B5BFE15ABEB3C","F7FA7ABC1ECB89BA8EE6656847EFABBF43BB9BCA","07BD6A765FFC289FF755D7CAB2893A40EC337FEC","896B85CC7E913E11C34892C1425A093C0701D386","11A01C82EF355E674E4F9728A801F5C3CB40D83F","F410C88469990EE7947450311D24B8AF2ADB2595","A8208CCC87F8261AFAEB6B85D5E8D47372DDEA6B","A4577D8C2AF4CF26F40CBCA83FFA4251D6F6C8F8","EFCF5358672FEE04789FD2EC3638A67ADEDB6C8C"});
    provider->AddFeature("oauth2.auto_approve", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("offline_enabled");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("offline_enabled", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("options_ui");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("options_ui", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("permissions");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("permissions", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("replacement_android_app");
    feature->set_channel(version_info::Channel::UNKNOWN);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_min_manifest_version(2);
    provider->AddFeature("replacement_android_app", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("replacement_web_app");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_min_manifest_version(2);
    provider->AddFeature("replacement_web_app", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("sandbox");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP});
    feature->set_min_manifest_version(2);
    provider->AddFeature("sandbox", feature);
  }
  {
    std::vector<Feature*> features;
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("sockets");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("sockets");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"3BC1ED0B3E6EFDC7BD4D3D1D75D44B52DEE0A226","38C361D4A0726CE45D3572D65071B6BDB3092371"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("sockets");
    provider->AddFeature("sockets", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("usb_printers");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("usb_printers", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("version");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("version", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("version_name");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("version_name", feature);
  }
  {
    std::vector<Feature*> features;
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("web_accessible_resources");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP});
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("web_accessible_resources");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_location(SimpleFeature::COMPONENT_LOCATION);
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("web_accessible_resources");
    provider->AddFeature("web_accessible_resources", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("web_app_file_handlers");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
    provider->AddFeature("web_app_file_handlers", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("web_app_linked_shortcut_items");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
    provider->AddFeature("web_app_linked_shortcut_items", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("web_app_shortcut_icons");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
    provider->AddFeature("web_app_shortcut_icons", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("webview");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_min_manifest_version(2);
    provider->AddFeature("webview", feature);
  }

}

}  // namespace extensions