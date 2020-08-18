// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE FEATURES FILE:
//   ['../../chrome/common/apps/platform_apps/api/_api_features.json']
// DO NOT EDIT.

#include "chrome/common/apps/platform_apps/api/api_features.h"

#include "extensions/common/features/complex_feature.h"
#include "extensions/common/features/feature_provider.h"
#include "extensions/common/features/manifest_feature.h"
#include "extensions/common/features/permission_feature.h"

namespace extensions {

void AddChromeAppsAPIFeatures(FeatureProvider* provider) {
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("arcAppsPrivate");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:arcAppsPrivate"});
    provider->AddFeature("arcAppsPrivate", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("browser");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:browser"});
    provider->AddFeature("browser", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("firstRunPrivate");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:firstRunPrivate"});
    provider->AddFeature("firstRunPrivate", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("mediaGalleries");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:mediaGalleries"});
    provider->AddFeature("mediaGalleries", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("musicManagerPrivate");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:musicManagerPrivate"});
    provider->AddFeature("musicManagerPrivate", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("syncFileSystem");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:syncFileSystem"});
    provider->AddFeature("syncFileSystem", feature);
  }
  {
    SimpleFeature* feature = new SimpleFeature();
    feature->set_name("webstoreWidgetPrivate");
    feature->set_contexts({Feature::BLESSED_EXTENSION_CONTEXT});
    feature->set_dependencies({"permission:webstoreWidgetPrivate"});
    provider->AddFeature("webstoreWidgetPrivate", feature);
  }

}

}  // namespace extensions