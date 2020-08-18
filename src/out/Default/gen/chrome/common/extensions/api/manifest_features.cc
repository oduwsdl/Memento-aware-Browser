// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE FEATURES FILE:
//   ['../../chrome/common/extensions/api/_manifest_features.json']
// DO NOT EDIT.

#include "chrome/common/extensions/api/manifest_features.h"

#include "extensions/common/features/complex_feature.h"
#include "extensions/common/features/feature_provider.h"
#include "extensions/common/features/manifest_feature.h"
#include "extensions/common/features/permission_feature.h"

namespace extensions {

void AddChromeManifestFeatures(FeatureProvider* provider) {
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("about_page");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_SHARED_MODULE});
    provider->AddFeature("about_page", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("action");
    feature->set_channel(version_info::Channel::UNKNOWN);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    provider->AddFeature("action", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("app.icon_color");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
    provider->AddFeature("app.icon_color", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("app.isolation");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP});
    provider->AddFeature("app.isolation", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("app.launch");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP});
    provider->AddFeature("app.launch", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("app.linked_icons");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
    provider->AddFeature("app.linked_icons", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("app.theme_color");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
    provider->AddFeature("app.theme_color", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("author");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("author", feature);
  }
  {
    std::vector<Feature*> features;
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("automation");
      feature->set_channel(version_info::Channel::DEV);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("automation");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
      feature->set_allowlist({"2FCBCE08B34CCA1728A85F1EFBD9A34DD2558B2E"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("automation");
    provider->AddFeature("automation", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("browser_action");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    provider->AddFeature("browser_action", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("chrome_settings_overrides");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_platforms({Feature::WIN_PLATFORM,Feature::MACOSX_PLATFORM});
    provider->AddFeature("chrome_settings_overrides", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("chrome_url_overrides");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("chrome_url_overrides", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("commands");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_min_manifest_version(2);
    provider->AddFeature("commands", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("content_scripts");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("content_scripts", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("converted_from_user_script");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP});
    provider->AddFeature("converted_from_user_script", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("devtools_page");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("devtools_page", feature);
  }
  {
    std::vector<Feature*> features;
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("display_in_launcher");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_HOSTED_APP});
      feature->set_location(SimpleFeature::COMPONENT_LOCATION);
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("display_in_launcher");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      feature->set_allowlist({"64291898C201DAF15B090EC4B9EC270BEB6BE6FF","07BD6A765FFC289FF755D7CAB2893A40EC337FEC","896B85CC7E913E11C34892C1425A093C0701D386","11A01C82EF355E674E4F9728A801F5C3CB40D83F","F410C88469990EE7947450311D24B8AF2ADB2595"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("display_in_launcher");
    provider->AddFeature("display_in_launcher", feature);
  }
  {
    std::vector<Feature*> features;
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("display_in_new_tab_page");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_HOSTED_APP});
      feature->set_location(SimpleFeature::COMPONENT_LOCATION);
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("display_in_new_tab_page");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      feature->set_allowlist({"64291898C201DAF15B090EC4B9EC270BEB6BE6FF","07BD6A765FFC289FF755D7CAB2893A40EC337FEC","896B85CC7E913E11C34892C1425A093C0701D386","11A01C82EF355E674E4F9728A801F5C3CB40D83F","F410C88469990EE7947450311D24B8AF2ADB2595"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("display_in_new_tab_page");
    provider->AddFeature("display_in_new_tab_page", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("event_rules");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_THEME});
    provider->AddFeature("event_rules", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("export");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_SHARED_MODULE});
    provider->AddFeature("export", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("file_browser_handlers");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("file_browser_handlers", feature);
  }
  {
    std::vector<Feature*> features;
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("file_system_provider_capabilities");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("file_system_provider_capabilities");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LEGACY_PACKAGED_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"0EA6B717932AD64C469C1CCB6911457733295907","58B0C2968C335964D5433E89CA4D86628A0E3D4B"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("file_system_provider_capabilities");
    provider->AddFeature("file_system_provider_capabilities", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("homepage_url");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("homepage_url", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("import");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("import", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("input_components");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("input_components", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("minimum_chrome_version");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("minimum_chrome_version", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("natively_connectable");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    provider->AddFeature("natively_connectable", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("omnibox");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("omnibox", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("optional_permissions");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("optional_permissions", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("options_page");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP});
    provider->AddFeature("options_page", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("page_action");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    provider->AddFeature("page_action", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("platforms");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("platforms", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("requirements");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("requirements", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("short_name");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("short_name", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("signature");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("signature", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("spellcheck");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    provider->AddFeature("spellcheck", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("storage");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    feature->set_min_manifest_version(2);
    provider->AddFeature("storage", feature);
  }
  {
    std::vector<Feature*> features;
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("system_indicator");
      feature->set_channel(version_info::Channel::DEV);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      ManifestFeature* feature = new ManifestFeature();
      feature->set_name("system_indicator");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
      feature->set_allowlist({"F29716B08705C9D3C12CDFE3F638BAE709570C31","53041A2FA309EECED01FFC751E7399186E860B2C","312745D9BF916161191143F6490085EEA0434997","A74A4D44C7CFCD8844830E6140C8D763E12DD8F3","E7E2461CE072DF036CF9592740196159E2D7C089","49DA0B9CCEEA299186C6E7226FD66922D57543DC"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("system_indicator");
    provider->AddFeature("system_indicator", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("theme");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_THEME});
    provider->AddFeature("theme", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("tts_engine");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("tts_engine", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("update_url");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    provider->AddFeature("update_url", feature);
  }
  {
    ManifestFeature* feature = new ManifestFeature();
    feature->set_name("url_handlers");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("url_handlers", feature);
  }

}

}  // namespace extensions