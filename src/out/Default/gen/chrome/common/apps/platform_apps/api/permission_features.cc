// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE FEATURES FILE:
//   ['../../chrome/common/apps/platform_apps/api/_permission_features.json']
// DO NOT EDIT.

#include "chrome/common/apps/platform_apps/api/permission_features.h"

#include "extensions/common/features/complex_feature.h"
#include "extensions/common/features/feature_provider.h"
#include "extensions/common/features/manifest_feature.h"
#include "extensions/common/features/permission_feature.h"

namespace extensions {

void AddChromeAppsPermissionFeatures(FeatureProvider* provider) {
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("arcAppsPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"46578A13607D38F1DC8E280C4F499FB0A2F9565C","898FB5A39687D210766B8998BA4530B99C9E6586","82F30B65397BC3E4ADE627BBD857AB8A58210648","C74B2AF138F9EDECD04D0965AB36CA66C8290466"});
    provider->AddFeature("arcAppsPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("browser");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("browser", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("firstRunPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_location(SimpleFeature::COMPONENT_LOCATION);
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    provider->AddFeature("firstRunPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("mediaGalleries");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("mediaGalleries", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("mediaGalleries.allAutoDetected");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("mediaGalleries.allAutoDetected", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("mediaGalleries.copyTo");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("mediaGalleries.copyTo", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("mediaGalleries.delete");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("mediaGalleries.delete", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("mediaGalleries.read");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("mediaGalleries.read", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("mediaGalleries.scan");
    feature->set_channel(version_info::Channel::DEV);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("mediaGalleries.scan", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("musicManagerPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_allowlist({"4B1D0E19C6C43C008C44A8278C8B5BFE15ABEB3C","B8F61FD1B25DE03706DBB8906A73261E4DBB992A","F7FA7ABC1ECB89BA8EE6656847EFABBF43BB9BCA","4FE45FA56EF6A25FDE8C302C44045CA9CE8A605A","3D14248405B8A59043420AAC160077C99E7788A9","A6C87307BBE5886CC5F1393025000E2FE8060BF2","3407516021EA3669C0EC8E65E6B9837E5A521B9C"});
    provider->AddFeature("musicManagerPrivate", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("pointerLock");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("pointerLock", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("syncFileSystem");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    provider->AddFeature("syncFileSystem", feature);
  }
  {
    PermissionFeature* feature = new PermissionFeature();
    feature->set_name("webstoreWidgetPrivate");
    feature->set_channel(version_info::Channel::STABLE);
    feature->set_extension_types({Manifest::TYPE_PLATFORM_APP});
    feature->set_platforms({Feature::CHROMEOS_PLATFORM});
    feature->set_allowlist({"A948368FC53BE437A55FEB414106E207925482F5","8C726564C6DBE7380BAB388DE6CC7EC93EB44B06","5065C83E84321221675D20FBE4DC43C655CC8C6F"});
    provider->AddFeature("webstoreWidgetPrivate", feature);
  }

}

}  // namespace extensions