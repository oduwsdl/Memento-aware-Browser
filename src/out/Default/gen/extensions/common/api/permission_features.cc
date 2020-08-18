// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE FEATURES FILE:
//   ['../../extensions/common/api/_permission_features.json']
// DO NOT EDIT.

#include "extensions/common/api/permission_features.h"

#include "extensions/common/features/complex_feature.h"
#include "extensions/common/features/feature_provider.h"
#include "extensions/common/features/manifest_feature.h"
#include "extensions/common/features/permission_feature.h"

namespace extensions {

void AddCorePermissionFeatures(FeatureProvider* provider) {
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("alarms");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_min_manifest_version(2);
    provider->AddFeature("alarms", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("app.window.alpha");
      feature->set_channel(version_info::Channel::DEV);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("app.window.alpha");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_allowlist({"0F42756099D914A026DADFA182871C015735DD95","2D22CDB6583FD0A13758AEBE8B15E45208B4E9A7","E7E2461CE072DF036CF9592740196159E2D7C089","A74A4D44C7CFCD8844830E6140C8D763E12DD8F3","312745D9BF916161191143F6490085EEA0434997","53041A2FA309EECED01FFC751E7399186E860B2C","A07A5B743CD82A1C2579DB77D353C98A23201EEF","F16F23C83C5F6DAD9B65A120448B34056DD80691","0F585FB1D0FDFBEBCE1FEB5E9DFFB6DA476B8C9B"});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("app.window.alpha");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"06BE211D5F014BAB34BC22D9DDA09C63A81D828E","F94EE6AB36D6C6588670B2B01EB65212D9C64E33","B9EF10DDFEA11EF77873CC5009809E5037FC4C7A"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("app.window.alpha");
    provider->AddFeature("app.window.alpha", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("app.window.alwaysOnTop");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("app.window.alwaysOnTop", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("app.window.fullscreen");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("app.window.fullscreen", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("app.window.fullscreen.overrideEsc");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("app.window.fullscreen.overrideEsc", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("app.window.ime");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"06BE211D5F014BAB34BC22D9DDA09C63A81D828E","F94EE6AB36D6C6588670B2B01EB65212D9C64E33","B9EF10DDFEA11EF77873CC5009809E5037FC4C7A"});
    provider->AddFeature("app.window.ime", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("app.window.shape");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("app.window.shape", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("appview");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("appview", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("audio");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_session_types({FeatureSessionType::KIOSK});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("audio");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"75C7F4B720314B6CB1B5817CD86089DB95CD2461"});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("audio");
      feature->set_channel(version_info::Channel::DEV);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("audio");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_allowlist({"8C3741E3AF0B93B6E8E0DDD499BB0B74839EA578","E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","307E96539209F95A1A8740C713E6998A73657D96","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("audio");
    provider->AddFeature("audio", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("audioCapture");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("audioCapture");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"3F50C3A83839D9C76334BCE81CDEC06174F266AF","39BE69F11F68E4EED080DA3DC2394F7885B7AFF9","FF78670081967CE21DB86A04AD94A0498F01E20A","0C0426C12F94156F330FFAF346A976BA8878DE78","AC4538682FCECD28587C7A0F80849F78F4872BC2","CCA4D85A67ADD65DA6C02E49EE3C080C54A8211C","05EBA3051DFCA6AF17070AEE5FE8C66322FF4738"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("audioCapture");
    provider->AddFeature("audioCapture", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("bluetoothPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM,Feature::WIN_PLATFORM,Feature::MACOSX_PLATFORM,Feature::LINUX_PLATFORM});
      feature->set_allowlist({"1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","307E96539209F95A1A8740C713E6998A73657D96","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB","89715614FAA2B4C2853802D70261D2A9D0756FC8","61FF4757F9420B62B19BA5C96084649339DB31F5","F3013F58BED982D1BC75943792FF877E5D458672","1B7734733E207CCE5C33BFAA544CA89634BF881F","23EEC2E3B4F6A62F5E6C8556364F7B749F9A809C","D238B3D5DB5836AEC1733DA4237CF93B7F96F495","B2FEB5422C0F105AED7027E363886F1FE29F13F6","2F6F6FDB84E0290ABAB7A9D7571EB344821E5F12","5B9E39EA374B136CBE7AED2D872003107642EAD5","E0E94FB0C01FFB9CDC7A5F098C99B5A8D2F95902","52E0557059A7A28F74ED1D92DDD997E0CCD37806","A9A9FC0228ADF541F0334F22BEFB8F9C245B21D7"});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("bluetoothPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"75C7F4B720314B6CB1B5817CD86089DB95CD2461"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("bluetoothPrivate");
    provider->AddFeature("bluetoothPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("cast");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"9448CAB302F268FB4917D06F70703893DCDA26C4","63ED55E43214C211F82122ED56407FF1A807F2A3","226CF815E39A363090A1E547D53063472B8279FA"});
    provider->AddFeature("cast", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("cecPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_session_types({FeatureSessionType::KIOSK});
    feature->set_allowlist({"1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","307E96539209F95A1A8740C713E6998A73657D96","E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB","A9A9FC0228ADF541F0334F22BEFB8F9C245B21D7"});
    provider->AddFeature("cecPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("clipboard");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("clipboard", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("crashReportPrivate");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"0EA6B717932AD64C469C1CCB6911457733295907","58B0C2968C335964D5433E89CA4D86628A0E3D4B","3BC1ED0B3E6EFDC7BD4D3D1D75D44B52DEE0A226","38C361D4A0726CE45D3572D65071B6BDB3092371","06BE211D5F014BAB34BC22D9DDA09C63A81D828E"});
    provider->AddFeature("crashReportPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("declarativeNetRequest");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_feature_flag("DeclarativeNetRequest");
    feature->set_min_manifest_version(2);
    provider->AddFeature("declarativeNetRequest", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("declarativeNetRequestFeedback");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION});
    feature->set_feature_flag("DeclarativeNetRequest");
    feature->set_min_manifest_version(2);
    provider->AddFeature("declarativeNetRequestFeedback", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("declarativeWebRequest");
    feature->set_channel(version_info::Channel::BETA);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("declarativeWebRequest", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("diagnostics");
      feature->set_channel(version_info::Channel::DEV);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("diagnostics");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_allowlist({"7AE714FFD394E073F0294CFA134C9F91DB5FBAA4","C7DA3A55C2355F994D3FDDAD120B426A0DF63843","75E3CFFFC530582C583E4690EF97C70B9C8423B7"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("diagnostics");
    provider->AddFeature("diagnostics", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("displaySource");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("displaySource", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("dns");
      feature->set_channel(version_info::Channel::DEV);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("dns");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
      feature->set_allowlist({"7AE714FFD394E073F0294CFA134C9F91DB5FBAA4","C7DA3A55C2355F994D3FDDAD120B426A0DF63843","75E3CFFFC530582C583E4690EF97C70B9C8423B7"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("dns");
    provider->AddFeature("dns", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("documentScan");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("documentScan", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("externally_connectable.all_urls");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"54ECAB4579BDE8FDAF9B29ED335F9946EE504A52","E24F1786D842E91E74C27929B0B3715A4689A473","A28C9619C4C41306FA5236FB4D94DA812F504DE8"});
    provider->AddFeature("externally_connectable.all_urls", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("feedbackPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"7910EAFDAF64B947E1CB31B333A9BD14CA556B6C","1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","8C3741E3AF0B93B6E8E0DDD499BB0B74839EA578","E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","307E96539209F95A1A8740C713E6998A73657D96","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB","A9A9FC0228ADF541F0334F22BEFB8F9C245B21D7"});
    provider->AddFeature("feedbackPrivate", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("fileSystem");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("fileSystem");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"2FC374607C2DF285634B67C64A2E356C607091C3","3727DD3E564B6055387425027AD74C58784ACC15","12E618C3C6E97495AAECF2AC12DEB082353241C6","2B6C6A4A5940017146F3E58B7F90116206E84685","B6C2EFAB3EC3BF6EF03701408B6B09A67B2D0069","96FF2FFA5C9173C76D47184B3E86D267B37781DE","0136FCB13DB29FD5CD442F56E59E53B61F1DF96F","CBCC42ABED43A4B58FE3810E62AFFA010EB0349F"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("fileSystem");
    provider->AddFeature("fileSystem", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("fileSystem.directory");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("fileSystem.directory", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("fileSystem.requestDownloads");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"A3E3DE9E9F16B41D4A2FAD106BD6CA76B94A0C94","C2ABD68C33A5B485971C9638B80D6A2E9CBA78C4","B41E7F08E1179CC03CBD1F49E57CF353A40ADE07"});
    provider->AddFeature("fileSystem.requestDownloads", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("fileSystem.requestFileSystem");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("fileSystem.requestFileSystem", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("fileSystem.retainEntries");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("fileSystem.retainEntries", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("fileSystem.write");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("fileSystem.write");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"2FC374607C2DF285634B67C64A2E356C607091C3","3727DD3E564B6055387425027AD74C58784ACC15","12E618C3C6E97495AAECF2AC12DEB082353241C6"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("fileSystem.write");
    provider->AddFeature("fileSystem.write", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("hid");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("hid");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"496B6890097EB6E19809ADEADD095A8721FBB2E0","AD8ED80B705E1818AAD4684F9FF62B43D6D79620","E24F1786D842E91E74C27929B0B3715A4689A473","A28C9619C4C41306FA5236FB4D94DA812F504DE8","D7CD4B3956B1F6E970E4AFCBCD4094B1EF4D07B9","D4EFCCC0CC612380762758BB96C7997224BD6395","4839A26B29CD1BD021B2E126EF6D28C9CB84018B","8F44FBB4474CCDF23450B166C9E83E85BD03AE24"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("hid");
    provider->AddFeature("hid", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("idle");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("idle", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("lockScreen");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"6F9C741B8E0E546652134F1138DF0284A7C9B21E","47448626CB266C60AA2404E4EB426E025DF497DF"});
    provider->AddFeature("lockScreen", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("mediaPerceptionPrivate");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_session_types({FeatureSessionType::KIOSK});
      feature->set_allowlist({"E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","307E96539209F95A1A8740C713E6998A73657D96","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB","A9A9FC0228ADF541F0334F22BEFB8F9C245B21D7"});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("mediaPerceptionPrivate");
      feature->set_channel(version_info::Channel::DEV);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_allowlist({"3970B660353CA07962DAD1A5C1B75A7B87835943","E0DEFFD4518AF92D2DB1F575FF390EE35F58200C","B7B5CF88FE1AAE4B84B81B949A69AD18E512A33A"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("mediaPerceptionPrivate");
    provider->AddFeature("mediaPerceptionPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("metricsPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"A948368FC53BE437A55FEB414106E207925482F5","2FC374607C2DF285634B67C64A2E356C607091C3","3727DD3E564B6055387425027AD74C58784ACC15","12E618C3C6E97495AAECF2AC12DEB082353241C6","3727DD3E564B6055387425027AD74C58784ACC15","C41AD9DCD670210295614257EF8C9945AD68D86E","7AE714FFD394E073F0294CFA134C9F91DB5FBAA4","C7DA3A55C2355F994D3FDDAD120B426A0DF63843","75E3CFFFC530582C583E4690EF97C70B9C8423B7","06BE211D5F014BAB34BC22D9DDA09C63A81D828E","CFBF7EE448FA48960FFDA7CEB30F7A21B26AA981","B9EF10DDFEA11EF77873CC5009809E5037FC4C7A","D2DAA9362153E8A5E3CF593E6DF4666421ABAD21","D7986543275120831B39EF28D1327552FC343960","A291B26E088FA6BA53FFD72F0916F06EBA7C585A","07BD6A765FFC289FF755D7CAB2893A40EC337FEC","896B85CC7E913E11C34892C1425A093C0701D386","11A01C82EF355E674E4F9728A801F5C3CB40D83F","F410C88469990EE7947450311D24B8AF2ADB2595","9E527CDA9D7C50844E8A5DB964A54A640AE48F98","DF52618D0B040D8A054D8348D2E84DDEEE5974E7","269D721F163E587BC53C6F83553BF9CE2BB143CD","6B55A5329E3F1F30F6032BDB20B2EB4378DBF767","C449A798C495E6CF7D6AF10162113D564E67AD12","01E9FFA9A8F3C18271FE91BEE46207F3B81755CC","97B23E01B2AA064E8332EE43A7A85C628AADC3F2","63ED55E43214C211F82122ED56407FF1A807F2A3","226CF815E39A363090A1E547D53063472B8279FA","0EA6B717932AD64C469C1CCB6911457733295907","58B0C2968C335964D5433E89CA4D86628A0E3D4B","3BC1ED0B3E6EFDC7BD4D3D1D75D44B52DEE0A226","38C361D4A0726CE45D3572D65071B6BDB3092371","B620CF4203315F9F2E046EDED22C7571A935958D","B206D8716769728278D2D300349C6CB7D7DE2EF9","2B6C6A4A5940017146F3E58B7F90116206E84685","B6C2EFAB3EC3BF6EF03701408B6B09A67B2D0069","96FF2FFA5C9173C76D47184B3E86D267B37781DE","0136FCB13DB29FD5CD442F56E59E53B61F1DF96F","CBCC42ABED43A4B58FE3810E62AFFA010EB0349F","75C7F4B720314B6CB1B5817CD86089DB95CD2461","46578A13607D38F1DC8E280C4F499FB0A2F9565C","898FB5A39687D210766B8998BA4530B99C9E6586","82F30B65397BC3E4ADE627BBD857AB8A58210648","A3E3DE9E9F16B41D4A2FAD106BD6CA76B94A0C94","B41E7F08E1179CC03CBD1F49E57CF353A40ADE07","C74B2AF138F9EDECD04D0965AB36CA66C8290466"});
    provider->AddFeature("metricsPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("nativeMessaging");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("nativeMessaging", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("networking.config");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("networking.config", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("networking.onc");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM});
      feature->set_session_types({FeatureSessionType::AUTOLAUNCHED_KIOSK});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("networking.onc");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      feature->set_platforms({Feature::CHROMEOS_PLATFORM,Feature::MACOSX_PLATFORM,Feature::WIN_PLATFORM,Feature::LINUX_PLATFORM});
      feature->set_allowlist({"0DE0F05680A4A056BCEC864ED8DDA84296F82B40","1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","8C3741E3AF0B93B6E8E0DDD499BB0B74839EA578","E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","307E96539209F95A1A8740C713E6998A73657D96","63ED55E43214C211F82122ED56407FF1A807F2A3","226CF815E39A363090A1E547D53063472B8279FA","7AE714FFD394E073F0294CFA134C9F91DB5FBAA4","C7DA3A55C2355F994D3FDDAD120B426A0DF63843","75E3CFFFC530582C583E4690EF97C70B9C8423B7","23D8847AE3EE90122AA34657360AFEEC8B3E611B","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB","2F6F6FDB84E0290ABAB7A9D7571EB344821E5F12","5B9E39EA374B136CBE7AED2D872003107642EAD5","E0E94FB0C01FFB9CDC7A5F098C99B5A8D2F95902","52E0557059A7A28F74ED1D92DDD997E0CCD37806","61FF4757F9420B62B19BA5C96084649339DB31F5","6FB7E1B6C0247B687AC14772E87A117F5F5E4497","9834387FDA1F66A1B5CA06CB442137B556F12F2A","A9A9FC0228ADF541F0334F22BEFB8F9C245B21D7"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("networking.onc");
    provider->AddFeature("networking.onc", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("networkingPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM,Feature::MACOSX_PLATFORM,Feature::WIN_PLATFORM,Feature::LINUX_PLATFORM});
    feature->set_allowlist({"0DE0F05680A4A056BCEC864ED8DDA84296F82B40","1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","8C3741E3AF0B93B6E8E0DDD499BB0B74839EA578","E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","307E96539209F95A1A8740C713E6998A73657D96","63ED55E43214C211F82122ED56407FF1A807F2A3","FA01E0B81978950F2BC5A50512FD769725F57510","B11A93E7E5B541F8010245EBDE2C74647D6C14B9","F155646B5D1CA545F7E1E4E20D573DFDD44C2540","16CA7A47AAE4BE49B1E75A6B960C3875E945B264","226CF815E39A363090A1E547D53063472B8279FA","7AE714FFD394E073F0294CFA134C9F91DB5FBAA4","C7DA3A55C2355F994D3FDDAD120B426A0DF63843","75E3CFFFC530582C583E4690EF97C70B9C8423B7","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB","2F6F6FDB84E0290ABAB7A9D7571EB344821E5F12","5B9E39EA374B136CBE7AED2D872003107642EAD5","E0E94FB0C01FFB9CDC7A5F098C99B5A8D2F95902","52E0557059A7A28F74ED1D92DDD997E0CCD37806","A9A9FC0228ADF541F0334F22BEFB8F9C245B21D7"});
    provider->AddFeature("networkingPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("power");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("power", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("printerProvider");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("printerProvider", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("runtime");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("runtime", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("serial");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("serial", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("socket");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("socket");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"32A1BA997F8AB8DE29ED1BA94AAF00CF2A3FEFA7"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("socket");
    provider->AddFeature("socket", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("storage");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      feature->set_min_manifest_version(2);
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("storage");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_LOGIN_SCREEN_EXTENSION});
      feature->set_min_manifest_version(2);
      feature->set_allowlist({"7FE4A999359A456C4B0FB7B7AD85CEA29CA50519","E219EE36A3B40612FD2A8CD6937B03EF0C97D3FE","4DBFC1C52D6660DD90791976DF7FEF7B3D360509","CDA6A10BE50CE65C59B766D0CE6A27E8E0A1533F","D85454743B32D9F5ABF3E5F18DF78809F3A0ABD4","04569B963251EB28C0906099668D98EE65ECA2D8","7BF5B69C3ACA9E6ACA5C480661B8073EB9FA32A9","5F2EF8E9F7E975090278D6A0AD039860430C5684","97A4DC8AFC1FCF665C71B624A55675C297AB256C","A00EB72B456C374F1EA86C09833C7DBB6CD95CAE","51DDBADA37EF4D25AD03CB1BB6451799456FE183","DD97CAE4D8658003658140109BC119188A19A5B8","320857126E2180A5751AA384B7B7332A4964BD8C"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("storage");
    provider->AddFeature("storage", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("system.cpu");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("system.cpu");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
      feature->set_allowlist({"B44D08FD98F1523ED5837D78D0A606EA9D6206E5"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("system.cpu");
    provider->AddFeature("system.cpu", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("system.display");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("system.display");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
      feature->set_allowlist({"B44D08FD98F1523ED5837D78D0A606EA9D6206E5"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("system.display");
    provider->AddFeature("system.display", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("system.memory");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("system.memory");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
      feature->set_allowlist({"B44D08FD98F1523ED5837D78D0A606EA9D6206E5"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("system.memory");
    provider->AddFeature("system.memory", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("system.network");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("system.network");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
      feature->set_allowlist({"B44D08FD98F1523ED5837D78D0A606EA9D6206E5"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("system.network");
    provider->AddFeature("system.network", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("system.powerSource");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_session_types({FeatureSessionType::KIOSK});
    provider->AddFeature("system.powerSource", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("system.storage");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("system.storage");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_HOSTED_APP});
      feature->set_allowlist({"B44D08FD98F1523ED5837D78D0A606EA9D6206E5"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("system.storage");
    provider->AddFeature("system.storage", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("u2fDevices");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"496B6890097EB6E19809ADEADD095A8721FBB2E0","AD8ED80B705E1818AAD4684F9FF62B43D6D79620","E24F1786D842E91E74C27929B0B3715A4689A473","A28C9619C4C41306FA5236FB4D94DA812F504DE8","6F9E349A0561C78A0D3F41496FE521C5151C7F71","C06709A259378015404ED20F75C7D08547E0F10B"});
    provider->AddFeature("u2fDevices", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("unlimitedStorage");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP,Manifest::TYPE_HOSTED_APP,Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("unlimitedStorage", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("usb");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("usb");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"496B6890097EB6E19809ADEADD095A8721FBB2E0","AD8ED80B705E1818AAD4684F9FF62B43D6D79620","E24F1786D842E91E74C27929B0B3715A4689A473","A28C9619C4C41306FA5236FB4D94DA812F504DE8"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("usb");
    provider->AddFeature("usb", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("usbDevices");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("usbDevices");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"496B6890097EB6E19809ADEADD095A8721FBB2E0","AD8ED80B705E1818AAD4684F9FF62B43D6D79620","E24F1786D842E91E74C27929B0B3715A4689A473","A28C9619C4C41306FA5236FB4D94DA812F504DE8","D7CD4B3956B1F6E970E4AFCBCD4094B1EF4D07B9","D4EFCCC0CC612380762758BB96C7997224BD6395","4839A26B29CD1BD021B2E126EF6D28C9CB84018B","8F44FBB4474CCDF23450B166C9E83E85BD03AE24"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("usbDevices");
    provider->AddFeature("usbDevices", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("videoCapture");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("videoCapture");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"A434B90223C3C52F2B69DB494736B63C612C774D"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("videoCapture");
    provider->AddFeature("videoCapture", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("virtualKeyboard");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_session_types({FeatureSessionType::KIOSK});
    provider->AddFeature("virtualKeyboard", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("virtualKeyboardPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"3F50C3A83839D9C76334BCE81CDEC06174F266AF","06BE211D5F014BAB34BC22D9DDA09C63A81D828E","CFBF7EE448FA48960FFDA7CEB30F7A21B26AA981","F94EE6AB36D6C6588670B2B01EB65212D9C64E33","3E03D9B67FDD31B2438D1CF5070573415DCB3CBA","E703483CEF33DEC18B4B6DD84B5C776FB9182BDB","A3BC37E2148AC4E99BE4B16AF9D42DD1E592BBBE","1C93BD3CF875F4A73C0B2A163BB8FBDA8B8B3D80","307E96539209F95A1A8740C713E6998A73657D96","4F25792AF1AA7483936DE29C07806F203C7170A0","BD8781D757D830FC2E85470A1B6E8A718B7EE0D9","4AC2B6C63C6480D150DFDA13E4A5956EB1D0DDBB","81986D4F846CEDDDB962643FA501D1780DD441BB","A9A9FC0228ADF541F0334F22BEFB8F9C245B21D7"});
    provider->AddFeature("virtualKeyboardPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("vpnProvider");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("vpnProvider", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("webRequest");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
    provider->AddFeature("webRequest", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("webRequestBlocking");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION,Manifest::TYPE_LEGACY_PACKAGED_APP});
      feature->set_max_manifest_version(2);
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("webRequestBlocking");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_location(SimpleFeature::POLICY_LOCATION);
      feature->set_min_manifest_version(3);
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("webRequestBlocking");
    provider->AddFeature("webRequestBlocking", feature);
  }
  {
    std::vector<Feature*> features;
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("webview");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
      features.push_back(feature);
    }
    {
      PermissionFeature* feature = new PermissionFeature();
      feature->set_name("webview");
      feature->set_channel(version_info::Channel::STABLE);
      feature->set_extension_types({Manifest::TYPE_EXTENSION});
      feature->set_allowlist({"63ED55E43214C211F82122ED56407FF1A807F2A3","226CF815E39A363090A1E547D53063472B8279FA"});
      features.push_back(feature);
    }
    ComplexFeature* feature(new ComplexFeature(&features));
    feature->set_name("webview");
    provider->AddFeature("webview", feature);
  }

}

}  // namespace extensions