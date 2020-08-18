// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE FEATURES FILE:
//   ['../../chrome/common/extensions/api/_permission_features.json']
// DO NOT EDIT.

#include "chrome/common/extensions/api/permission_features.h"

#include "extensions/common/features/complex_feature.h"
#include "extensions/common/features/feature_provider.h"
#include "extensions/common/features/manifest_feature.h"
#include "extensions/common/features/permission_feature.h"

namespace extensions {

void AddChromePermissionFeatures(FeatureProvider* provider) {
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("accessibilityFeatures.modify");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("accessibilityFeatures.modify", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("accessibilityFeatures.read");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("accessibilityFeatures.read");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LEGACY_PACKAGED_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"0EA6B717932AD64C469C1CCB6911457733295907","58B0C2968C335964D5433E89CA4D86628A0E3D4B"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("accessibilityFeatures.read");
    provider->AddFeature("accessibilityFeatures.read", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("accessibilityPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"0D209B5E4401BB8E7873B5AB5B1346A1CB067015","2FCBCE08B34CCA1728A85F1EFBD9A34DD2558B2E"});
    provider->AddFeature("accessibilityPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("activeTab");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    feature->set_min_manifest_version(2);
    provider->AddFeature("activeTab", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("activityLogPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"EE17C698905F7F2E6DDC87C9C30F11E164C829F4","C50DC2AC31D826BC977032AF12DE4694CC8467DC","AE27D69DBE571F4B1694F05C89B710C646792231","5107DE9024C329EEA9C9A72D94C16723790C6422"});
    provider->AddFeature("activityLogPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("autofillAssistantPrivate");
    feature->set_channel(version_info::Channel::UNKNOWN);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    feature->set_allowlist({"64B58C7B53E3E1447FD0DEA62C5E654206179F99"});
    provider->AddFeature("autofillAssistantPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("autofillPrivate");
    feature->set_channel(version_info::Channel::UNKNOWN);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    provider->AddFeature("autofillPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("autotestPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_allowlist({"05D1DBD6E8B9C4690FFA7D50E6F60C5290DC662A","0D209B5E4401BB8E7873B5AB5B1346A1CB067015","93CFDA3681E923AD7AB291CEDD98248396B5496C"});
    provider->AddFeature("autotestPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("background");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP});
    provider->AddFeature("background", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("bookmarks");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("bookmarks", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("brailleDisplayPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    provider->AddFeature("brailleDisplayPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("browsingData");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("browsingData", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("certificateProvider");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("certificateProvider", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("chromePrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    feature->set_allowlist({"2462D64ACB971A7E708757159C2B17761D4FF54A","3010EF507AFEF487EEA9CDE2930EC94867C60936","ABAABC5F49E022A76CBB12972A53B58354C04AC6"});
    provider->AddFeature("chromePrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("chromeosInfoPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","8C3741E3AF0B93B6E8E0DDD499BB0B74839EA578","E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","307E96539209F95A1A8740C713E6998A73657D96","A291B26E088FA6BA53FFD72F0916F06EBA7C585A","D7986543275120831B39EF28D1327552FC343960","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB","B620CF4203315F9F2E046EDED22C7571A935958D","B206D8716769728278D2D300349C6CB7D7DE2EF9","A3E3DE9E9F16B41D4A2FAD106BD6CA76B94A0C94","C2ABD68C33A5B485971C9638B80D6A2E9CBA78C4","B41E7F08E1179CC03CBD1F49E57CF353A40ADE07","8EBDF73405D0B84CEABB8C7513C9B9FA9F1DC2CE","72445193EB86716465275D4E2E84DACF47558FCF","51E46A03961884A4BA74CE7CA30A75CC6F360D74","6844C0E4DF3034BD3ED04E7BD957C7DE0EA83443","2B6C6A4A5940017146F3E58B7F90116206E84685","B6C2EFAB3EC3BF6EF03701408B6B09A67B2D0069","96FF2FFA5C9173C76D47184B3E86D267B37781DE","0136FCB13DB29FD5CD442F56E59E53B61F1DF96F","9834387FDA1F66A1B5CA06CB442137B556F12F2A","930F7D9989A5FBCDCCD7D85BB5C3B7006C24D91D","A9A9FC0228ADF541F0334F22BEFB8F9C245B21D7","46578A13607D38F1DC8E280C4F499FB0A2F9565C","898FB5A39687D210766B8998BA4530B99C9E6586","82F30B65397BC3E4ADE627BBD857AB8A58210648","C74B2AF138F9EDECD04D0965AB36CA66C8290466"});
    provider->AddFeature("chromeosInfoPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("clipboardRead");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("clipboardRead", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("clipboardWrite");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("clipboardWrite", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("cloudPrintPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP});
    feature->set_allowlist({"99060B01DE911EB85FD630C8BA6320C9186CA3AB"});
    provider->AddFeature("cloudPrintPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("commandLinePrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    provider->AddFeature("commandLinePrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("commands.accessibility");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"2FCBCE08B34CCA1728A85F1EFBD9A34DD2558B2E","75C7F4B720314B6CB1B5817CD86089DB95CD2461"});
    provider->AddFeature("commands.accessibility", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("contentSettings");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("contentSettings", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("contextMenus");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("contextMenus", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("cookies");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("cookies", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("cryptotokenPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    feature->set_allowlist({"E24F1786D842E91E74C27929B0B3715A4689A473"});
    provider->AddFeature("cryptotokenPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("dataReductionProxy");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_allowlist({"852290F2442EEE45EF673B8DA6090112079012A2"});
    provider->AddFeature("dataReductionProxy", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("debugger");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("debugger");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_allowlist({"AE27D69DBE571F4B1694F05C89B710C646792231"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("debugger");
    provider->AddFeature("debugger", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("declarativeContent");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    provider->AddFeature("declarativeContent", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("desktopCapture");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("desktopCapture", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("desktopCapturePrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("desktopCapturePrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("developerPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"AE27D69DBE571F4B1694F05C89B710C646792231","FA0501B579070BB9CBD4FCAEC8CB0EDF22BA2F04","4A4EA121622FCA3D78ED2AB534197F43D7189EE0","9FDE6E7F06FCFA11D9A05041C7FF6D8AE662F5D1","50B4A905D522C06E27CA6D099E3E54BDA1F152C5","BA0C8BB92084C9741312D90D3EA882526853455F","5F57A9AE8DFF5D6BB09DF8606270402612E871E5"});
    provider->AddFeature("developerPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("devtools");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("devtools", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("downloads");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    provider->AddFeature("downloads", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("downloads.open");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    provider->AddFeature("downloads.open", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("downloads.shelf");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    provider->AddFeature("downloads.shelf", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("echoPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("echoPrivate", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("enterprise.deviceAttributes");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
      feature->set_location(SimpleFeature::POLICY_LOCATION);
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("enterprise.deviceAttributes");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
      feature->set_location(SimpleFeature::POLICY_LOCATION);
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"E219EE36A3B40612FD2A8CD6937B03EF0C97D3FE","4DBFC1C52D6660DD90791976DF7FEF7B3D360509","CDA6A10BE50CE65C59B766D0CE6A27E8E0A1533F","D85454743B32D9F5ABF3E5F18DF78809F3A0ABD4","04569B963251EB28C0906099668D98EE65ECA2D8","7BF5B69C3ACA9E6ACA5C480661B8073EB9FA32A9","5F2EF8E9F7E975090278D6A0AD039860430C5684","97A4DC8AFC1FCF665C71B624A55675C297AB256C","A00EB72B456C374F1EA86C09833C7DBB6CD95CAE","51DDBADA37EF4D25AD03CB1BB6451799456FE183","DD97CAE4D8658003658140109BC119188A19A5B8","320857126E2180A5751AA384B7B7332A4964BD8C"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("enterprise.deviceAttributes");
    provider->AddFeature("enterprise.deviceAttributes", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("enterprise.hardwarePlatform");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_location(SimpleFeature::POLICY_LOCATION);
    provider->AddFeature("enterprise.hardwarePlatform", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("enterprise.networkingAttributes");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_location(SimpleFeature::POLICY_LOCATION);
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("enterprise.networkingAttributes");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
      feature->set_location(SimpleFeature::POLICY_LOCATION);
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"E219EE36A3B40612FD2A8CD6937B03EF0C97D3FE","4DBFC1C52D6660DD90791976DF7FEF7B3D360509","CDA6A10BE50CE65C59B766D0CE6A27E8E0A1533F","D85454743B32D9F5ABF3E5F18DF78809F3A0ABD4","04569B963251EB28C0906099668D98EE65ECA2D8","7BF5B69C3ACA9E6ACA5C480661B8073EB9FA32A9","5F2EF8E9F7E975090278D6A0AD039860430C5684","97A4DC8AFC1FCF665C71B624A55675C297AB256C","A00EB72B456C374F1EA86C09833C7DBB6CD95CAE","51DDBADA37EF4D25AD03CB1BB6451799456FE183","DD97CAE4D8658003658140109BC119188A19A5B8","320857126E2180A5751AA384B7B7332A4964BD8C"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("enterprise.networkingAttributes");
    provider->AddFeature("enterprise.networkingAttributes", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("enterprise.platformKeys");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP});
      feature->set_location(SimpleFeature::POLICY_LOCATION);
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("enterprise.platformKeys");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_location(SimpleFeature::EXTERNAL_COMPONENT_LOCATION);
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"EC8EA268128FECE14CEC68B90686D87755D87083"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("enterprise.platformKeys");
    provider->AddFeature("enterprise.platformKeys", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("enterprise.platformKeysPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"657FEC7E77355CA205B0E226586621F86B33F611","5894126C625EF31852F215ED301A5FF1F9B7D026","8DAE23A10703C926B21862B2F318FB4E110B17BD","34412790FC81BC9B563CBE599ED10ABF26B209F7","7F782E724FF51789B54DA82C7363DAB5043C1677","2C18988BCDC297196D5D6893005175DA1BC1E893"});
    provider->AddFeature("enterprise.platformKeysPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("enterprise.reportingPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_platforms({Feature::WIN_PLATFORM,Feature::MACOSX_PLATFORM,Feature::LINUX_PLATFORM});
    feature->set_allowlist({"86D63D90308742AA65B8B29AE2D39FED2D6DC310","031E5E4A54C39E4F46E11CE643584E9187915908","349E89FE0296161007623C0B4096B617D7CECD54","18B761AA5B58FA89E596EB7996B4C92C86775C7F","2012C0122892D332325339998251D1CC3CAE396A","86C81CACF5E2273044C491F1949E928E25F28E0A"});
    provider->AddFeature("enterprise.reportingPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("experimental");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_command_line_switch("experimental-extension-apis");
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("experimental", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("fileBrowserHandler");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("fileBrowserHandler", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("fileManagerPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"74E2D32A61B08D29521A8C4E360F581DE78F5CA5","A948368FC53BE437A55FEB414106E207925482F5","A13373C881097323F4DEF392474BE2E28DA6D4ED","8C726564C6DBE7380BAB388DE6CC7EC93EB44B06","5065C83E84321221675D20FBE4DC43C655CC8C6F","397F221E63F86BE34C30165613E95B6CC8D22A52","A3E3DE9E9F16B41D4A2FAD106BD6CA76B94A0C94","C2ABD68C33A5B485971C9638B80D6A2E9CBA78C4","B41E7F08E1179CC03CBD1F49E57CF353A40ADE07"});
    provider->AddFeature("fileManagerPrivate", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("fileSystemProvider");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("fileSystemProvider");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LEGACY_PACKAGED_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"0EA6B717932AD64C469C1CCB6911457733295907","58B0C2968C335964D5433E89CA4D86628A0E3D4B"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("fileSystemProvider");
    provider->AddFeature("fileSystemProvider", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("fontSettings");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("fontSettings", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("gcm");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("gcm", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("geolocation");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("geolocation", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("history");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("history", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("identity");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("identity", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("identity.email");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("identity.email", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("identityPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    provider->AddFeature("identityPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("idltest");
    feature->set_channel(version_info::Channel::UNKNOWN);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    provider->AddFeature("idltest", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("imageWriterPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"A291B26E088FA6BA53FFD72F0916F06EBA7C585A","D7986543275120831B39EF28D1327552FC343960","BCC85C0D7F85897F2699974421EA402144C35C0C","B620CF4203315F9F2E046EDED22C7571A935958D","B206D8716769728278D2D300349C6CB7D7DE2EF9","2B6C6A4A5940017146F3E58B7F90116206E84685","B6C2EFAB3EC3BF6EF03701408B6B09A67B2D0069","96FF2FFA5C9173C76D47184B3E86D267B37781DE","0136FCB13DB29FD5CD442F56E59E53B61F1DF96F"});
    provider->AddFeature("imageWriterPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("input");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM,Feature::WIN_PLATFORM,Feature::LINUX_PLATFORM});
    provider->AddFeature("input", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("inputMethodPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"2462D64ACB971A7E708757159C2B17761D4FF54A","3010EF507AFEF487EEA9CDE2930EC94867C60936","ABAABC5F49E022A76CBB12972A53B58354C04AC6"});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("inputMethodPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      feature->set_location(SimpleFeature::COMPONENT_LOCATION);
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("inputMethodPrivate");
    provider->AddFeature("inputMethodPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("languageSettingsPrivate");
    feature->set_channel(version_info::Channel::UNKNOWN);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    provider->AddFeature("languageSettingsPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("launcherSearchProvider");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"A948368FC53BE437A55FEB414106E207925482F5"});
    provider->AddFeature("launcherSearchProvider", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("lockWindowFullscreenPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_component_extensions_auto_granted(false);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"6A4A0389E8D47118E96E6221B0B7221CA3715801","EC8EA268128FECE14CEC68B90686D87755D87083","AA1C88257F51F7A9AFB947720AACE8CA7E9CF85C","A4577D8C2AF4CF26F40CBCA83FFA4251D6F6C8F8","EFCF5358672FEE04789FD2EC3638A67ADEDB6C8C","A8208CCC87F8261AFAEB6B85D5E8D47372DDEA6B"});
    provider->AddFeature("lockWindowFullscreenPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("login");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_LOGIN_SCREEN_EXTENSION,Manifest::TYPE_EXTENSION});
    feature->set_location(SimpleFeature::POLICY_LOCATION);
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"7FE4A999359A456C4B0FB7B7AD85CEA29CA50519","3F5995FE79A861F019C6F093BEF98D73FA9D3A5F","E219EE36A3B40612FD2A8CD6937B03EF0C97D3FE","4DBFC1C52D6660DD90791976DF7FEF7B3D360509","CDA6A10BE50CE65C59B766D0CE6A27E8E0A1533F","D85454743B32D9F5ABF3E5F18DF78809F3A0ABD4","04569B963251EB28C0906099668D98EE65ECA2D8","7BF5B69C3ACA9E6ACA5C480661B8073EB9FA32A9","5F2EF8E9F7E975090278D6A0AD039860430C5684","97A4DC8AFC1FCF665C71B624A55675C297AB256C","A00EB72B456C374F1EA86C09833C7DBB6CD95CAE","51DDBADA37EF4D25AD03CB1BB6451799456FE183","DD97CAE4D8658003658140109BC119188A19A5B8","320857126E2180A5751AA384B7B7332A4964BD8C","A24DE1B21A67E25FB62AC8491642038FE25DA75B","6B25164FFE2BADB5F1DBBD301CC022170267022D","4D15F9AFCF54E56F0A6E06D22DD15F133DCF0882","171F86E3D91235E5FC745282834BB3DA164F14B3","F7BDB4C21BFF955F851C6CF65167373BDEED6218","220ABCF657446B2CBEBDE2DDA09B6FC415E87FB7","B0092A67BFB22960DE49B11E9CA56035BD40BCFA","3899082721C4996840EA4DD3A7B604914FB915CF","0D0EF5C81661E90BAFD606EADD68D8BB5EDC7E9A","D53DFC9E0D738159557959ABCA61BDDC97470C87","579D5666AB7B27A2E9EA0B13FB7F70CA7D864F72","FC3BBFAD9D7E711BBBD8235E7640348A9B98EB5F"});
    provider->AddFeature("login", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("loginScreenStorage");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_LOGIN_SCREEN_EXTENSION,Manifest::TYPE_EXTENSION});
    feature->set_location(SimpleFeature::POLICY_LOCATION);
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"E219EE36A3B40612FD2A8CD6937B03EF0C97D3FE","4DBFC1C52D6660DD90791976DF7FEF7B3D360509","CDA6A10BE50CE65C59B766D0CE6A27E8E0A1533F","D85454743B32D9F5ABF3E5F18DF78809F3A0ABD4","04569B963251EB28C0906099668D98EE65ECA2D8","7BF5B69C3ACA9E6ACA5C480661B8073EB9FA32A9","5F2EF8E9F7E975090278D6A0AD039860430C5684","97A4DC8AFC1FCF665C71B624A55675C297AB256C","A00EB72B456C374F1EA86C09833C7DBB6CD95CAE","51DDBADA37EF4D25AD03CB1BB6451799456FE183","DD97CAE4D8658003658140109BC119188A19A5B8","320857126E2180A5751AA384B7B7332A4964BD8C","A24DE1B21A67E25FB62AC8491642038FE25DA75B","6B25164FFE2BADB5F1DBBD301CC022170267022D","4D15F9AFCF54E56F0A6E06D22DD15F133DCF0882","171F86E3D91235E5FC745282834BB3DA164F14B3","F7BDB4C21BFF955F851C6CF65167373BDEED6218","220ABCF657446B2CBEBDE2DDA09B6FC415E87FB7","B0092A67BFB22960DE49B11E9CA56035BD40BCFA","3899082721C4996840EA4DD3A7B604914FB915CF","0D0EF5C81661E90BAFD606EADD68D8BB5EDC7E9A","D53DFC9E0D738159557959ABCA61BDDC97470C87","579D5666AB7B27A2E9EA0B13FB7F70CA7D864F72","FC3BBFAD9D7E711BBBD8235E7640348A9B98EB5F"});
    provider->AddFeature("loginScreenStorage", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("loginScreenUi");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    feature->set_location(SimpleFeature::POLICY_LOCATION);
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"7FE4A999359A456C4B0FB7B7AD85CEA29CA50519","E219EE36A3B40612FD2A8CD6937B03EF0C97D3FE","4DBFC1C52D6660DD90791976DF7FEF7B3D360509","CDA6A10BE50CE65C59B766D0CE6A27E8E0A1533F","D85454743B32D9F5ABF3E5F18DF78809F3A0ABD4","04569B963251EB28C0906099668D98EE65ECA2D8","7BF5B69C3ACA9E6ACA5C480661B8073EB9FA32A9","5F2EF8E9F7E975090278D6A0AD039860430C5684","97A4DC8AFC1FCF665C71B624A55675C297AB256C","A00EB72B456C374F1EA86C09833C7DBB6CD95CAE","51DDBADA37EF4D25AD03CB1BB6451799456FE183","DD97CAE4D8658003658140109BC119188A19A5B8","320857126E2180A5751AA384B7B7332A4964BD8C"});
    provider->AddFeature("loginScreenUi", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("loginState");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LOGIN_SCREEN_EXTENSION,Manifest::TYPE_EXTENSION});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("loginState");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"EC3DE21E048B67319893889529354DFBFA96FD23"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("loginState");
    provider->AddFeature("loginState", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("management");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("management");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_allowlist({"AE27D69DBE571F4B1694F05C89B710C646792231","5107DE9024C329EEA9C9A72D94C16723790C6422","8C0B1873FFFB65E4D0F4D772879F7304CEF125C2","FA0501B579070BB9CBD4FCAEC8CB0EDF22BA2F04","EE17C698905F7F2E6DDC87C9C30F11E164C829F4","90113DA9516526D24DAF156C629CC41C049E8882","4A4EA121622FCA3D78ED2AB534197F43D7189EE0","9FDE6E7F06FCFA11D9A05041C7FF6D8AE662F5D1","50B4A905D522C06E27CA6D099E3E54BDA1F152C5","BA0C8BB92084C9741312D90D3EA882526853455F","5F57A9AE8DFF5D6BB09DF8606270402612E871E5","46578A13607D38F1DC8E280C4F499FB0A2F9565C","898FB5A39687D210766B8998BA4530B99C9E6586","82F30B65397BC3E4ADE627BBD857AB8A58210648","C74B2AF138F9EDECD04D0965AB36CA66C8290466"});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("management");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
      feature->set_allowlist({"B44D08FD98F1523ED5837D78D0A606EA9D6206E5"});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("management");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_session_types({FeatureSessionType::KIOSK});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("management");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
      feature->set_min_manifest_version(2);
      feature->set_allowlist({"E219EE36A3B40612FD2A8CD6937B03EF0C97D3FE","4DBFC1C52D6660DD90791976DF7FEF7B3D360509","CDA6A10BE50CE65C59B766D0CE6A27E8E0A1533F","D85454743B32D9F5ABF3E5F18DF78809F3A0ABD4","04569B963251EB28C0906099668D98EE65ECA2D8","7BF5B69C3ACA9E6ACA5C480661B8073EB9FA32A9","5F2EF8E9F7E975090278D6A0AD039860430C5684","97A4DC8AFC1FCF665C71B624A55675C297AB256C","A00EB72B456C374F1EA86C09833C7DBB6CD95CAE","51DDBADA37EF4D25AD03CB1BB6451799456FE183","DD97CAE4D8658003658140109BC119188A19A5B8","320857126E2180A5751AA384B7B7332A4964BD8C"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("management");
    provider->AddFeature("management", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("mdns");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"63ED55E43214C211F82122ED56407FF1A807F2A3","226CF815E39A363090A1E547D53063472B8279FA","1BFB3A47AA4A1E1C4714D919217602685CDD0FA7"});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("mdns");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("mdns");
    provider->AddFeature("mdns", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("mediaPlayerPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("mediaPlayerPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("mediaRouterPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_allowlist({"63ED55E43214C211F82122ED56407FF1A807F2A3","226CF815E39A363090A1E547D53063472B8279FA"});
    provider->AddFeature("mediaRouterPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("networking.castPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM,Feature::MACOSX_PLATFORM,Feature::WIN_PLATFORM});
    feature->set_allowlist({"63ED55E43214C211F82122ED56407FF1A807F2A3","FA01E0B81978950F2BC5A50512FD769725F57510","B11A93E7E5B541F8010245EBDE2C74647D6C14B9","F155646B5D1CA545F7E1E4E20D573DFDD44C2540","16CA7A47AAE4BE49B1E75A6B960C3875E945B264","226CF815E39A363090A1E547D53063472B8279FA"});
    provider->AddFeature("networking.castPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("notifications");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("notifications", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("pageCapture");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("pageCapture", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("passwordsPrivate");
    feature->set_channel(version_info::Channel::UNKNOWN);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    provider->AddFeature("passwordsPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("platformKeys");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("platformKeys", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("plugin");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("plugin", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("printing");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("printing", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("printingMetrics");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_location(SimpleFeature::POLICY_LOCATION);
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("printingMetrics", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("privacy");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("privacy", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("processes");
      feature->set_channel(version_info::Channel::DEV);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("processes");
      feature->set_channel(version_info::Channel::BETA);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"7D7A4B147FE39908A5AF13F85E38989C54BBE41C","0EEDFC0EED87871237213F34EBC7B4982A195C95"});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("processes");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"DF84F03F9B960409CCDE0D895B9650EBE81C0A8E","80B9DC58E5210749F052F5B4DB239C50CF72AEB6","7D7A4B147FE39908A5AF13F85E38989C54BBE41C","0EEDFC0EED87871237213F34EBC7B4982A195C95"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("processes");
    provider->AddFeature("processes", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("proxy");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("proxy");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("proxy");
    provider->AddFeature("proxy", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("resourcesPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    provider->AddFeature("resourcesPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("rtcPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    feature->set_allowlist({"53041A2FA309EECED01FFC751E7399186E860B2C","A74A4D44C7CFCD8844830E6140C8D763E12DD8F3","E7E2461CE072DF036CF9592740196159E2D7C089","312745D9BF916161191143F6490085EEA0434997"});
    provider->AddFeature("rtcPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("safeBrowsingPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_allowlist({"B281B98DDD6A379EF50D59BB1135419536C1C353","FD15C63ABA854733FDCBC1D4D34A71E963A12ABD","08455FA7CB8734168378F731B00B354CEEE0088F","86C81CACF5E2273044C491F1949E928E25F28E0A"});
    provider->AddFeature("safeBrowsingPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("sessions");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("sessions", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("settingsPrivate");
      feature->set_channel(version_info::Channel::UNKNOWN);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
      feature->set_location(SimpleFeature::COMPONENT_LOCATION);
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("settingsPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"63ED55E43214C211F82122ED56407FF1A807F2A3","226CF815E39A363090A1E547D53063472B8279FA"});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("settingsPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_session_types({FeatureSessionType::KIOSK});
      feature->set_allowlist({"E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","307E96539209F95A1A8740C713E6998A73657D96","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB","A9A9FC0228ADF541F0334F22BEFB8F9C245B21D7"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("settingsPrivate");
    provider->AddFeature("settingsPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("signedInDevices");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("signedInDevices", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("systemPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    provider->AddFeature("systemPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("tabCapture");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("tabCapture", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("tabs");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("tabs");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_allowlist({"AE27D69DBE571F4B1694F05C89B710C646792231","5107DE9024C329EEA9C9A72D94C16723790C6422"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("tabs");
    provider->AddFeature("tabs", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("terminalPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"0EA6B717932AD64C469C1CCB6911457733295907","58B0C2968C335964D5433E89CA4D86628A0E3D4B","3BC1ED0B3E6EFDC7BD4D3D1D75D44B52DEE0A226","38C361D4A0726CE45D3572D65071B6BDB3092371"});
    provider->AddFeature("terminalPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("topSites");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("topSites", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("transientBackground");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    provider->AddFeature("transientBackground", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("tts");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("tts", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("ttsEngine");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("ttsEngine", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("usersPrivate");
    feature->set_channel(version_info::Channel::UNKNOWN);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"0D209B5E4401BB8E7873B5AB5B1346A1CB067015"});
    provider->AddFeature("usersPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("wallpaper");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_EXTENSION});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("wallpaper", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("wallpaperPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("wallpaperPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("webNavigation");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("webNavigation", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("webcamPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","307E96539209F95A1A8740C713E6998A73657D96","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB","A9A9FC0228ADF541F0334F22BEFB8F9C245B21D7"});
    provider->AddFeature("webcamPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("webrtcAudioPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_allowlist({"80B9DC58E5210749F052F5B4DB239C50CF72AEB6","DF84F03F9B960409CCDE0D895B9650EBE81C0A8E","ADFA45434ABA2F1A4647E673F53FF37F8F6047A3"});
    provider->AddFeature("webrtcAudioPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("webrtcDesktopCapturePrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_allowlist({"80B9DC58E5210749F052F5B4DB239C50CF72AEB6","DF84F03F9B960409CCDE0D895B9650EBE81C0A8E","ADFA45434ABA2F1A4647E673F53FF37F8F6047A3"});
    provider->AddFeature("webrtcDesktopCapturePrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("webrtcLoggingPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"80B9DC58E5210749F052F5B4DB239C50CF72AEB6","DF84F03F9B960409CCDE0D895B9650EBE81C0A8E","63ED55E43214C211F82122ED56407FF1A807F2A3","226CF815E39A363090A1E547D53063472B8279FA","ADFA45434ABA2F1A4647E673F53FF37F8F6047A3","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB"});
    provider->AddFeature("webrtcLoggingPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("webrtcLoggingPrivate.audioDebug");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_component_extensions_auto_granted(false);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"ADFA45434ABA2F1A4647E673F53FF37F8F6047A3","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB"});
    provider->AddFeature("webrtcLoggingPrivate.audioDebug", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("webstorePrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP});
    feature->set_allowlist({"B44D08FD98F1523ED5837D78D0A606EA9D6206E5","2653F6F6C39BC6EEBD36A09AFB92A19782FF7EB4"});
    provider->AddFeature("webstorePrivate", feature);
  }

}

}  // namespace extensions