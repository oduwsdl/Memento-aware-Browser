// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE FEATURES FILE:
//   ['../../extensions/common/api/_behavior_features.json']
// DO NOT EDIT.

#include "extensions/common/api/behavior_features.h"

#include "extensions/common/features/complex_feature.h"
#include "extensions/common/features/feature_provider.h"
#include "extensions/common/features/manifest_feature.h"
#include "extensions/common/features/permission_feature.h"

namespace extensions {

void AddCoreBehaviorFeatures(FeatureProvider* provider) {
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("allow_deprecated_audio_api");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"8C3741E3AF0B93B6E8E0DDD499BB0B74839EA578","E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","307E96539209F95A1A8740C713E6998A73657D96","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB"});
    provider->AddFeature("allow_deprecated_audio_api", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("allow_secondary_kiosk_app_enabled_on_launch");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("allow_secondary_kiosk_app_enabled_on_launch", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("allow_usb_devices_permission_interface_class");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_session_types({FeatureSessionType::KIOSK});
    provider->AddFeature("allow_usb_devices_permission_interface_class", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("do_not_sync");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_component_extensions_auto_granted(false);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    feature->set_allowlist({"226CF815E39A363090A1E547D53063472B8279FA"});
    provider->AddFeature("do_not_sync", feature);
  }
  {
    std::vector<Feature*> features;
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("signin_screen");
      feature->set_channel(version_info::Channel::CANARY);
      feature->set_component_extensions_auto_granted(false);
      feature->set_location(SimpleFeature::UNPACKED_LOCATION);
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"05D1DBD6E8B9C4690FFA7D50E6F60C5290DC662A"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("signin_screen");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_component_extensions_auto_granted(false);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_location(SimpleFeature::POLICY_LOCATION);
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"85DA1AC24AF23CDA9F5A19858EB9C6E9E1BA57F6","EC3DE21E048B67319893889529354DFBFA96FD23","6B748A5C005F21B7CBCF4170C2F883E435DEB511"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("signin_screen");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_component_extensions_auto_granted(false);
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"E24F1786D842E91E74C27929B0B3715A4689A473","6F9E349A0561C78A0D3F41496FE521C5151C7F71","8EBDF73405D0B84CEABB8C7513C9B9FA9F1DC2CE","06BE211D5F014BAB34BC22D9DDA09C63A81D828E","3F50C3A83839D9C76334BCE81CDEC06174F266AF","2F47B526FA71F44816618C41EC55E5EE9543FDCC","86672C8D7A04E24EFB244BF96FE518C4C4809F73","1CF709D51B2B96CF79D00447300BD3BFBE401D21","40FF1103292F40C34066E023B8BE8CAE18306EAE","3C654B3B6682CA194E75AD044CEDE927675DDEE8","2FCBCE08B34CCA1728A85F1EFBD9A34DD2558B2E","7910EAFDAF64B947E1CB31B333A9BD14CA556B6C"});
      features.push_back(feature);
    }
    {
      SimpleFeature* feature = new SimpleFeature();
      feature->set_name("signin_screen");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_component_extensions_auto_granted(false);
      feature->set_extension_types({Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
      feature->set_location(SimpleFeature::POLICY_LOCATION);
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"FA84F98B32AFC3013F5711F8711F8F38DB210AB7","7FE4A999359A456C4B0FB7B7AD85CEA29CA50519","E219EE36A3B40612FD2A8CD6937B03EF0C97D3FE","4DBFC1C52D6660DD90791976DF7FEF7B3D360509","CDA6A10BE50CE65C59B766D0CE6A27E8E0A1533F","D85454743B32D9F5ABF3E5F18DF78809F3A0ABD4","04569B963251EB28C0906099668D98EE65ECA2D8","7BF5B69C3ACA9E6ACA5C480661B8073EB9FA32A9","5F2EF8E9F7E975090278D6A0AD039860430C5684","97A4DC8AFC1FCF665C71B624A55675C297AB256C","A00EB72B456C374F1EA86C09833C7DBB6CD95CAE","51DDBADA37EF4D25AD03CB1BB6451799456FE183","DD97CAE4D8658003658140109BC119188A19A5B8","320857126E2180A5751AA384B7B7332A4964BD8C"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("signin_screen");
    provider->AddFeature("signin_screen", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("zoom_without_bubble");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_THEME,Manifest::TYPE_SHARED_MODULE,Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
    feature->set_allowlist({"CBCC42ABED43A4B58FE3810E62AFFA010EB0349F"});
    provider->AddFeature("zoom_without_bubble", feature);
  }

}

}  // namespace extensions