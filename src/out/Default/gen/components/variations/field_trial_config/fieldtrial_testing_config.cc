// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE SCHEMA DEFINITION AND DESCRIPTION IN
//   field_trial_testing_config_schema.json
//   fieldtrial_testing_config.json
// DO NOT EDIT.

#include "fieldtrial_testing_config.h"

namespace variations {


const char* const array_kFieldTrialConfig_enable_features_149[] = {
      "use-new-media-cache",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_189[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_189[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_174[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_189,
      1,
      array_kFieldTrialConfig_form_factors_189,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_149,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_18[] = {
      "FFmpegDecodeOpaqueVP8",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_188[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_188[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_173[] = {
    {
      "libvpx_for_vp8",
      array_kFieldTrialConfig_platforms_188,
      1,
      array_kFieldTrialConfig_form_factors_188,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_18,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_148[] = {
      "IPH_WebUITabStrip",
      "WebUITabStrip",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_52[] = {
      {
        "availability",
        "any",
      },
      {
        "event_trigger",
        "name:webui_tab_strip_iph_triggered;comparator:<3;window:1;storage:365",
      },
      {
        "event_used",
        "name:webui_tab_strip_opened;comparator:==0;window:90;storage:365",
      },
      {
        "session_rate",
        "any",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_187[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_187[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_172[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_187,
      1,
      array_kFieldTrialConfig_form_factors_187,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_52,
      4,
      array_kFieldTrialConfig_enable_features_148,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_147[] = {
      "WebRtcHybridAgc",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_51[] = {
      {
        "saturation_margin",
        "5",
      },
      {
        "use_peaks_not_rms",
        "false",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_186[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_186[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_171[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_186,
      1,
      array_kFieldTrialConfig_form_factors_186,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_51,
      2,
      array_kFieldTrialConfig_enable_features_147,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_185[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_185[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_170[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_185,
      1,
      array_kFieldTrialConfig_form_factors_185,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_184[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_184[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_169[] = {
    {
      "pacing_factor:1.0,trust_vp8:true,trust_vp9:true,video_hysteresis:1.2,bitrate_adjuster:true,vp8_s0_boost:false",
      array_kFieldTrialConfig_platforms_184,
      1,
      array_kFieldTrialConfig_form_factors_184,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_183[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_183[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_168[] = {
    {
      "Enabled,vp8_br:10kbps,vp9_br:29kbps",
      array_kFieldTrialConfig_platforms_183,
      1,
      array_kFieldTrialConfig_form_factors_183,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_182[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_182[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_167[] = {
    {
      "2_V1",
      array_kFieldTrialConfig_platforms_182,
      1,
      array_kFieldTrialConfig_form_factors_182,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_181[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_181[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_166[] = {
    {
      "1.0,2875,80,40,-60,3",
      array_kFieldTrialConfig_platforms_181,
      1,
      array_kFieldTrialConfig_form_factors_181,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_180[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_180[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_165[] = {
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_180,
      1,
      array_kFieldTrialConfig_form_factors_180,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_146[] = {
      "NewEncodeCpuLoadEstimator",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_179[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_179[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_164[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_179,
      1,
      array_kFieldTrialConfig_form_factors_179,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_146,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_178[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_178[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_163[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_178,
      1,
      array_kFieldTrialConfig_form_factors_178,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_145[] = {
      "WebRTC-EnableWebRtcEcdsa",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_177[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_177[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_162[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_177,
      1,
      array_kFieldTrialConfig_form_factors_177,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_145,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_176[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_176[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_161[] = {
    {
      "QueueSize:800,MinBitrate:30000",
      array_kFieldTrialConfig_platforms_176,
      1,
      array_kFieldTrialConfig_form_factors_176,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_175[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_175[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_160[] = {
    {
      "persist,limit:3s,fraction:.8,interval:1s",
      array_kFieldTrialConfig_platforms_175,
      1,
      array_kFieldTrialConfig_form_factors_175,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_174[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_174[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_159[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_174,
      1,
      array_kFieldTrialConfig_form_factors_174,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_173[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_173[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_158[] = {
    {
      "Enabled-0-20-1",
      array_kFieldTrialConfig_platforms_173,
      1,
      array_kFieldTrialConfig_form_factors_173,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_172[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_172[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_157[] = {
    {
      "Enabled-95-0.9993",
      array_kFieldTrialConfig_platforms_172,
      1,
      array_kFieldTrialConfig_form_factors_172,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_171[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_171[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_156[] = {
    {
      "estimate_dtx_delay:true,time_stretch_cn:true",
      array_kFieldTrialConfig_platforms_171,
      1,
      array_kFieldTrialConfig_form_factors_171,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_144[] = {
      "WebPaymentsPerMethodCanMakePaymentQuota",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_170[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_170[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_155[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_170,
      1,
      array_kFieldTrialConfig_form_factors_170,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_144,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_50[] = {
      {
        "blocklist_additions",
        "00060000:e,fffd:e,ed5f25a4:e",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_169[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_169[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_154[] = {
    {
      "TestGroup",
      array_kFieldTrialConfig_platforms_169,
      1,
      array_kFieldTrialConfig_form_factors_169,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_50,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_17[] = {
      "AutoplayIgnoreWebAudio",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_168[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_168[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_153[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_168,
      1,
      array_kFieldTrialConfig_form_factors_168,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_17,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_143[] = {
      "UseSurfaceLayerForVideo",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_167[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_167[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_152[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_167,
      1,
      array_kFieldTrialConfig_form_factors_167,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_143,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_142[] = {
      "MojoVideoCapture",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_166[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_166[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_151[] = {
    {
      "Enabled2",
      array_kFieldTrialConfig_platforms_166,
      1,
      array_kFieldTrialConfig_form_factors_166,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_142,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_141[] = {
      "IsolatedCodeCache",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_165[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_165[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_150[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_165,
      1,
      array_kFieldTrialConfig_form_factors_165,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_141,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_140[] = {
      "V8ConcurrentInlining",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_164[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_164[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_disable_features_16[] = {
      "V8ConcurrentInlining",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_163[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_163[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_149[] = {
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_163,
      1,
      array_kFieldTrialConfig_form_factors_163,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_16,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_164,
      1,
      array_kFieldTrialConfig_form_factors_164,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_140,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_15[] = {
      "UsernameFirstFlow",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_162[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_162[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_148[] = {
    {
      "Default",
      array_kFieldTrialConfig_platforms_162,
      1,
      array_kFieldTrialConfig_form_factors_162,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_15,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_139[] = {
      "UserDataSnapshot",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_161[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_161[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_147[] = {
    {
      "UserDataSnapshot",
      array_kFieldTrialConfig_platforms_161,
      1,
      array_kFieldTrialConfig_form_factors_161,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_139,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_138[] = {
      "UseSkiaRenderer",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_160[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_160[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_146[] = {
    {
      "UseSkiaRenderer",
      array_kFieldTrialConfig_platforms_160,
      1,
      array_kFieldTrialConfig_form_factors_160,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_138,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_137[] = {
      "UsePreferredIntervalForVideo",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_49[] = {
      {
        "NumOfFramesToToggleInterval",
        "6",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_159[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_159[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_145[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_159,
      1,
      array_kFieldTrialConfig_form_factors_159,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_49,
      1,
      array_kFieldTrialConfig_enable_features_137,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_14[] = {
      "PreloadMediaEngagementData",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_158[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_158[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_144[] = {
    {
      "PreseedDisabled",
      array_kFieldTrialConfig_platforms_158,
      1,
      array_kFieldTrialConfig_form_factors_158,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_14,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_136[] = {
      "TrustedDOMTypes",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_157[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_157[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_143[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_157,
      1,
      array_kFieldTrialConfig_form_factors_157,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_136,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_156[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_156[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_142[] = {
    {
      "TranslateSubFrames",
      array_kFieldTrialConfig_platforms_156,
      1,
      array_kFieldTrialConfig_form_factors_156,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_48[] = {
      {
        "server_params",
        "smrd",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_155[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_155[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_141[] = {
    {
      "SmartRendering",
      array_kFieldTrialConfig_platforms_155,
      1,
      array_kFieldTrialConfig_form_factors_155,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_48,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_135[] = {
      "TranslateRankerAutoBlacklistOverride",
      "TranslateRankerEnforcement",
      "TranslateRankerQuery",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_47[] = {
      {
        "translate-ranker-model-url",
        "https://www.gstatic.com/chrome/intelligence/assist/ranker/models/translate/2017/03/translate_ranker_model_20170329.pb.bin",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_154[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_154[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_140[] = {
    {
      "launch_20180628_model_20170329_with_blacklist_override_default",
      array_kFieldTrialConfig_platforms_154,
      1,
      array_kFieldTrialConfig_form_factors_154,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_47,
      1,
      array_kFieldTrialConfig_enable_features_135,
      3,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_134[] = {
      "ThrottleInstallingServiceWorker",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_46[] = {
      {
        "limit",
        "5",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_153[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_153[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_139[] = {
    {
      "Emabled5_v1",
      array_kFieldTrialConfig_platforms_153,
      1,
      array_kFieldTrialConfig_form_factors_153,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_46,
      1,
      array_kFieldTrialConfig_enable_features_134,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_133[] = {
      "ThrottleDelayable",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_45[] = {
      {
        "EffectiveConnectionType1",
        "3G",
      },
      {
        "MaxDelayableRequests1",
        "8",
      },
      {
        "NonDelayableWeight1",
        "3.0",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_152[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_152[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_138[] = {
    {
      "MaxDelayable_3g_8_Weight3_20190215",
      array_kFieldTrialConfig_platforms_152,
      1,
      array_kFieldTrialConfig_form_factors_152,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_45,
      3,
      array_kFieldTrialConfig_enable_features_133,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_132[] = {
      "TextureLayerSkipWaitForActivation",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_151[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_151[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_137[] = {
    {
      "TextureLayerSkipWaitForActivation",
      array_kFieldTrialConfig_platforms_151,
      1,
      array_kFieldTrialConfig_form_factors_151,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_132,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_131[] = {
      "TextfieldFocusOnTapUp",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_150[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_150[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_136[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_150,
      1,
      array_kFieldTrialConfig_form_factors_150,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_131,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_130[] = {
      "TextFragmentAnchor",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_149[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_149[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_135[] = {
    {
      "Enabled_20191216",
      array_kFieldTrialConfig_platforms_149,
      1,
      array_kFieldTrialConfig_form_factors_149,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_130,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_129[] = {
      "TabHoverCards",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_44[] = {
      {
        "setting",
        "1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_148[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_148[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_134[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_148,
      1,
      array_kFieldTrialConfig_form_factors_148,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_44,
      1,
      array_kFieldTrialConfig_enable_features_129,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_128[] = {
      "TabHoverCardImages",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_147[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_147[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_133[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_147,
      1,
      array_kFieldTrialConfig_form_factors_147,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_128,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_127[] = {
      "PulseInterval",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_43[] = {
      {
        "PulseIntervalMinutes",
        "60",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_146[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_146[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_132[] = {
    {
      "Enabled_1_hour",
      array_kFieldTrialConfig_platforms_146,
      1,
      array_kFieldTrialConfig_form_factors_146,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_43,
      1,
      array_kFieldTrialConfig_enable_features_127,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_126[] = {
      "SyncInstanceIDTokenTTL",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_42[] = {
      {
        "time_to_live_seconds",
        "1209600",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_145[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_145[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_131[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_145,
      1,
      array_kFieldTrialConfig_form_factors_145,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_42,
      1,
      array_kFieldTrialConfig_enable_features_126,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_13[] = {
      "StorageServiceSandbox",
};
const char* const array_kFieldTrialConfig_enable_features_125[] = {
      "StorageServiceOutOfProcess",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_144[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_144[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_130[] = {
    {
      "Unsandboxed_BeforeSandboxAvailable",
      array_kFieldTrialConfig_platforms_144,
      1,
      array_kFieldTrialConfig_form_factors_144,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_125,
      1,
      array_kFieldTrialConfig_disable_features_13,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_124[] = {
      "SqlSkipPreload",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_143[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_143[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_129[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_143,
      1,
      array_kFieldTrialConfig_form_factors_143,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_124,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_123[] = {
      "AppendFrameOriginToNetworkIsolationKey",
      "SplitCacheByNetworkIsolationKey",
      "UseRegistrableDomainInNetworkIsolationKey",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_142[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_142[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_128[] = {
    {
      "Enabled_Stable",
      array_kFieldTrialConfig_platforms_142,
      1,
      array_kFieldTrialConfig_form_factors_142,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_123,
      3,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_122[] = {
      "SharingMatchPulseInterval",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_41[] = {
      {
        "SharingPulseDeltaAndroidHours",
        "0",
      },
      {
        "SharingPulseDeltaDesktopHours",
        "0",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_141[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_141[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_127[] = {
    {
      "Enabled_strict",
      array_kFieldTrialConfig_platforms_141,
      1,
      array_kFieldTrialConfig_form_factors_141,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_41,
      2,
      array_kFieldTrialConfig_enable_features_122,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_121[] = {
      "SharedClipboardUI",
      "SharingPeerConnectionReceiver",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_140[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_140[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_126[] = {
    {
      "Enabled_With_WebRTC_2020-05-21",
      array_kFieldTrialConfig_platforms_140,
      1,
      array_kFieldTrialConfig_form_factors_140,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_121,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_120[] = {
      "ServiceWorkerOnUI",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_139[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_139[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_125[] = {
    {
      "Enabled1",
      array_kFieldTrialConfig_platforms_139,
      1,
      array_kFieldTrialConfig_form_factors_139,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_120,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_119[] = {
      "CookiesWithoutSameSiteMustBeSecure",
      "SameSiteByDefaultCookies",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_138[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_138[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_124[] = {
    {
      "LaxByDefaultAndNoneRequiresSecure",
      array_kFieldTrialConfig_platforms_138,
      1,
      array_kFieldTrialConfig_form_factors_138,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_119,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_137[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_137[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_enable_features_118[] = {
      "ThreatDomDetailsTagAttributes",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_40[] = {
      {
        "tag_attribute_csv",
        "div,data-google-query-id,div,id,iframe,id",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_136[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_136[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_123[] = {
    {
      "AdIdentifiers",
      array_kFieldTrialConfig_platforms_136,
      1,
      array_kFieldTrialConfig_form_factors_136,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_40,
      1,
      array_kFieldTrialConfig_enable_features_118,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Default",
      array_kFieldTrialConfig_platforms_137,
      1,
      array_kFieldTrialConfig_form_factors_137,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_12[] = {
      "SafeBrowsingSuspiciousSiteTriggerQuota",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_135[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_135[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_enable_features_117[] = {
      "SafeBrowsingSuspiciousSiteTriggerQuota",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_39[] = {
      {
        "suspicious_site_trigger_quota",
        "10",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_134[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_134[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_122[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_134,
      1,
      array_kFieldTrialConfig_form_factors_134,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_39,
      1,
      array_kFieldTrialConfig_enable_features_117,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Control",
      array_kFieldTrialConfig_platforms_135,
      1,
      array_kFieldTrialConfig_form_factors_135,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_12,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_116[] = {
      "SafeBrowsingRealTimeUrlLookupEnabledWithToken",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_133[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_133[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_121[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_133,
      1,
      array_kFieldTrialConfig_form_factors_133,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_116,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_115[] = {
      "SafeBrowsingRealTimeUrlLookupEnabled",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_132[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_132[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_120[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_132,
      1,
      array_kFieldTrialConfig_form_factors_132,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_115,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_114[] = {
      "SafeBrowsingPasswordProtectionShowDomainsForSavedPasswords",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_131[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_131[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_119[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_131,
      1,
      array_kFieldTrialConfig_form_factors_131,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_114,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_113[] = {
      "SafeBrowsingPasswordProtectionForSignedInUsers",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_130[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_130[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_118[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_130,
      1,
      array_kFieldTrialConfig_form_factors_130,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_113,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_112[] = {
      "SafeBrowsingPasswordProtectionForSavedPasswords",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_129[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_129[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_117[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_129,
      1,
      array_kFieldTrialConfig_form_factors_129,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_112,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_111[] = {
      "SafeBrowsingCommittedInterstitials",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_128[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_128[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_116[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_128,
      1,
      array_kFieldTrialConfig_form_factors_128,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_111,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_127[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_127[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_disable_features_11[] = {
      "SafeBrowsingAdSamplerTrigger",
      "SafeBrowsingTriggerThrottlerDailyQuota",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_126[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_126[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_enable_features_110[] = {
      "SafeBrowsingAdSamplerTrigger",
      "SafeBrowsingTriggerThrottlerDailyQuota",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_38[] = {
      {
        "safe_browsing_ad_sampler_frequency_denominator",
        "1000",
      },
      {
        "trigger_type_and_quota_csv",
        "2,10",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_125[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_125[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_115[] = {
    {
      "AdSampler_NormalRate",
      array_kFieldTrialConfig_platforms_125,
      1,
      array_kFieldTrialConfig_form_factors_125,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_38,
      2,
      array_kFieldTrialConfig_enable_features_110,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Control",
      array_kFieldTrialConfig_platforms_126,
      1,
      array_kFieldTrialConfig_form_factors_126,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_11,
      2,
      NULL,
      NULL,
      0,
    },
    {
      "Default",
      array_kFieldTrialConfig_platforms_127,
      1,
      array_kFieldTrialConfig_form_factors_127,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_109[] = {
      "SafeBrowsingAdRedirectTrigger",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_37[] = {
      {
        "ad_redirect_trigger_quota",
        "10",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_124[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_124[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_114[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_124,
      1,
      array_kFieldTrialConfig_form_factors_124,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_37,
      1,
      array_kFieldTrialConfig_enable_features_109,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_108[] = {
      "SafeBrowsingAdPopupTrigger",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_36[] = {
      {
        "ad_popup_trigger_quota",
        "10",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_123[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_123[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_113[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_123,
      1,
      array_kFieldTrialConfig_form_factors_123,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_36,
      1,
      array_kFieldTrialConfig_enable_features_108,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_122[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_122[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_112[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_122,
      1,
      array_kFieldTrialConfig_form_factors_122,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_107[] = {
      "NetworkErrorLogging",
      "Reporting",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_121[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_121[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_111[] = {
    {
      "ReportingAndNELEnabled",
      array_kFieldTrialConfig_platforms_121,
      1,
      array_kFieldTrialConfig_form_factors_121,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_107,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_120[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_120[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_35[] = {
      {
        "sendingThreshold",
        "1.0",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_119[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_119[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_110[] = {
    {
      "ShowAndPossiblySend",
      array_kFieldTrialConfig_platforms_119,
      1,
      array_kFieldTrialConfig_form_factors_119,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_35,
      1,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "DontShowAndDontSend",
      array_kFieldTrialConfig_platforms_120,
      1,
      array_kFieldTrialConfig_form_factors_120,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_106[] = {
      "IPH_ReopenTab",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_34[] = {
      {
        "availability",
        ">=7",
      },
      {
        "event_conditions_met",
        "name:reopen_tab_conditions_met;comparator:>0;window:1;storage:365",
      },
      {
        "event_trigger",
        "name:reopen_tab_iph_triggered;comparator:==0;window:90;storage:365",
      },
      {
        "event_used",
        "name:tab_reopened;comparator:==0;window:90;storage:365",
      },
      {
        "session_rate",
        "==0",
      },
      {
        "x_new_tab_opened_timeout",
        "5",
      },
      {
        "x_tab_minimum_active_duration",
        "60",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_118[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_118[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_109[] = {
    {
      "Enabled_20190117",
      array_kFieldTrialConfig_platforms_118,
      1,
      array_kFieldTrialConfig_form_factors_118,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_34,
      7,
      array_kFieldTrialConfig_enable_features_106,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_105[] = {
      "RenderDocument",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_33[] = {
      {
        "level",
        "crashed-frame",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_117[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_117[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_108[] = {
    {
      "EnableForCrashedFrame",
      array_kFieldTrialConfig_platforms_117,
      1,
      array_kFieldTrialConfig_form_factors_117,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_33,
      1,
      array_kFieldTrialConfig_enable_features_105,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_104[] = {
      "QuotaExpandPoolSize",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_32[] = {
      {
        "PerHostRatio",
        "0.75",
      },
      {
        "PoolSizeRatio",
        "0.8",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_116[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_116[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_107[] = {
    {
      "Enabled_Pool_Four_Fifths_Origin_ThreeQuarters_20190710",
      array_kFieldTrialConfig_platforms_116,
      1,
      array_kFieldTrialConfig_form_factors_116,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_32,
      2,
      array_kFieldTrialConfig_enable_features_104,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_103[] = {
      "IPH_QuietNotificationPrompts",
      "QuietNotificationPrompts",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_31[] = {
      {
        "availability",
        "any",
      },
      {
        "crowd_deny_hold_back_chance",
        "0.3",
      },
      {
        "enable_adaptive_activation",
        "true",
      },
      {
        "enable_crowd_deny_triggering",
        "true",
      },
      {
        "event_trigger",
        "name:tabgroups_dummy;comparator:any;window:1;storage:1",
      },
      {
        "event_used",
        "name:tabgroups_dummy;comparator:any;window:1;storage:1",
      },
      {
        "session_rate",
        "any",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_115[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_115[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_106[] = {
    {
      "EnableWithAdaptiveActivation",
      array_kFieldTrialConfig_platforms_115,
      1,
      array_kFieldTrialConfig_form_factors_115,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_31,
      7,
      array_kFieldTrialConfig_enable_features_103,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_102[] = {
      "QuicDoesNotUseFeatures",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_30[] = {
      {
        "connection_options",
        "5RTO",
      },
      {
        "enable_quic",
        "true",
      },
      {
        "quic_version",
        "h3-Q050",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_114[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_114[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_105[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_114,
      1,
      array_kFieldTrialConfig_form_factors_114,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_30,
      3,
      array_kFieldTrialConfig_enable_features_102,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_101[] = {
      "ProtoDBSharedMigration",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_29[] = {
      {
        "migrate_BudgetManager",
        "true",
      },
      {
        "migrate_CachedImageFetcherDatabase",
        "true",
      },
      {
        "migrate_DomDistillerStore",
        "true",
      },
      {
        "migrate_DownloadDB",
        "true",
      },
      {
        "migrate_DownloadService",
        "true",
      },
      {
        "migrate_FeatureEngagementTrackerAvailabilityStore",
        "true",
      },
      {
        "migrate_FeatureEngagementTrackerEventStore",
        "true",
      },
      {
        "migrate_FeedContentDatabase",
        "true",
      },
      {
        "migrate_FeedJournalDatabase",
        "true",
      },
      {
        "migrate_NTPSnippetImages",
        "true",
      },
      {
        "migrate_NTPSnippets",
        "true",
      },
      {
        "migrate_NotificationSchedulerIcons",
        "true",
      },
      {
        "migrate_NotificationSchedulerImpressions",
        "true",
      },
      {
        "migrate_NotificationSchedulerNotifications",
        "true",
      },
      {
        "migrate_PreviewsHintCacheStore",
        "true",
      },
      {
        "migrate_PrintJobDatabase",
        "true",
      },
      {
        "migrate_StrikeService",
        "true",
      },
      {
        "migrate_UsageStatsSuspension",
        "true",
      },
      {
        "migrate_UsageStatsTokenMapping",
        "true",
      },
      {
        "migrate_UsageStatsWebsiteEvent",
        "true",
      },
      {
        "migrate_VideoDecodeStatsDB",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_113[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_113[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_104[] = {
    {
      "Enabled3",
      array_kFieldTrialConfig_platforms_113,
      1,
      array_kFieldTrialConfig_form_factors_113,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_29,
      21,
      array_kFieldTrialConfig_enable_features_101,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_100[] = {
      "ProactivelyThrottleLowPriorityRequests",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_28[] = {
      {
        "http_rtt_multiplier_for_proactive_throttling_2G",
        "1.0",
      },
      {
        "http_rtt_multiplier_for_proactive_throttling_3G",
        "1.0",
      },
      {
        "http_rtt_multiplier_for_proactive_throttling_Slow-2G",
        "1.0",
      },
      {
        "queued_requests_dispatch_periodicity_ms",
        "5",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_112[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_112[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_103[] = {
    {
      "Enabled_20190722",
      array_kFieldTrialConfig_platforms_112,
      1,
      array_kFieldTrialConfig_form_factors_112,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_28,
      4,
      array_kFieldTrialConfig_enable_features_100,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_99[] = {
      "ProactivelySwapBrowsingInstance",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_27[] = {
      {
        "level",
        "CrossSiteReuseProcess",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_111[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_111[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_102[] = {
    {
      "EnabledWithCrossSiteReuseProcess",
      array_kFieldTrialConfig_platforms_111,
      1,
      array_kFieldTrialConfig_form_factors_111,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_27,
      1,
      array_kFieldTrialConfig_enable_features_99,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_98[] = {
      "PreloadMetadataLazyLoad",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_110[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_110[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_101[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_110,
      1,
      array_kFieldTrialConfig_form_factors_110,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_98,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_97[] = {
      "PreconnectToSearch",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_26[] = {
      {
        "startup_delay_ms",
        "0",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_109[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_109[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_100[] = {
    {
      "EnabledWithoutStartupDelay",
      array_kFieldTrialConfig_platforms_109,
      1,
      array_kFieldTrialConfig_form_factors_109,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_26,
      1,
      array_kFieldTrialConfig_enable_features_97,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_10[] = {
      "NavigationPredictorPreconnectHoldback",
};
const char* const array_kFieldTrialConfig_enable_features_96[] = {
      "NetUnusedIdleSocketTimeout",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_25[] = {
      {
        "unused_idle_socket_timeout_seconds",
        "60",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_108[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_108[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_99[] = {
    {
      "EnabledWithExtendedSocket",
      array_kFieldTrialConfig_platforms_108,
      1,
      array_kFieldTrialConfig_form_factors_108,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_25,
      1,
      array_kFieldTrialConfig_enable_features_96,
      1,
      array_kFieldTrialConfig_disable_features_10,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_95[] = {
      "PolicyAtomicGroup",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_107[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_107[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_98[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_107,
      1,
      array_kFieldTrialConfig_form_factors_107,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_95,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_94[] = {
      "PersistentHistograms",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_24[] = {
      {
        "send_unreported_metrics",
        "yes",
      },
      {
        "storage",
        "MappedFile",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_106[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_106[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_97[] = {
    {
      "EnabledOnDisk5",
      array_kFieldTrialConfig_platforms_106,
      1,
      array_kFieldTrialConfig_form_factors_106,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_24,
      2,
      array_kFieldTrialConfig_enable_features_94,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_93[] = {
      "BlockPromptsIfDismissedOften",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_105[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_105[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_96[] = {
    {
      "BlockPromptsEnabled",
      array_kFieldTrialConfig_platforms_105,
      1,
      array_kFieldTrialConfig_form_factors_105,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_93,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_92[] = {
      "AlwaysAllowJustInTimePaymentApp",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_104[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_104[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_95[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_104,
      1,
      array_kFieldTrialConfig_form_factors_104,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_92,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_91[] = {
      "ImprovedCookieControls",
      "ImprovedCookieControlsForThirdPartyCookieBlocking",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_23[] = {
      {
        "DefaultInIncognito",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_103[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_103[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_94[] = {
    {
      "WithEnhancedExperiment_20200616",
      array_kFieldTrialConfig_platforms_103,
      1,
      array_kFieldTrialConfig_form_factors_103,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_23,
      1,
      array_kFieldTrialConfig_enable_features_91,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_90[] = {
      "PartitionConnectionsByNetworkIsolationKey",
      "PartitionHttpServerPropertiesByNetworkIsolationKey",
      "PartitionSSLSessionsByNetworkIsolationKey",
      "SplitHostCacheByNetworkIsolationKey",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_102[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_102[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_93[] = {
    {
      "Enabled4",
      array_kFieldTrialConfig_platforms_102,
      1,
      array_kFieldTrialConfig_form_factors_102,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_90,
      4,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_89[] = {
      "PaintHolding",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_101[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_101[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_92[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_101,
      1,
      array_kFieldTrialConfig_form_factors_101,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_89,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_88[] = {
      "OverflowIconsForMediaControls",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_100[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_100[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_91[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_100,
      1,
      array_kFieldTrialConfig_form_factors_100,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_88,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_87[] = {
      "ExtraSafelistedRequestHeadersForOutOfBlinkCors",
      "OutOfBlinkCors",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_22[] = {
      {
        "extra-safelisted-request-headers",
        "x-googapps-allowed-domains",
      },
      {
        "extra-safelisted-request-headers-for-enterprise",
        "x-googapps-allowed-domains",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_99[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_99[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_90[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_99,
      1,
      array_kFieldTrialConfig_form_factors_99,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_22,
      2,
      array_kFieldTrialConfig_enable_features_87,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_86[] = {
      "OmniboxUIExperimentHideSteadyStateUrlScheme",
      "OmniboxUIExperimentHideSteadyStateUrlTrivialSubdomains",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_98[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_98[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_89[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_98,
      1,
      array_kFieldTrialConfig_form_factors_98,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_86,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_85[] = {
      "OmniboxPreserveDefaultMatchAgainstAsyncUpdate",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_97[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_97[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_88[] = {
    {
      "Beta_Enabled",
      array_kFieldTrialConfig_platforms_97,
      1,
      array_kFieldTrialConfig_form_factors_97,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_85,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_84[] = {
      "OmniboxOnDeviceHeadProviderNonIncognito",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_96[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_96[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_87[] = {
    {
      "OnDeviceHeadSuggest_NonIncognito_Enabled",
      array_kFieldTrialConfig_platforms_96,
      1,
      array_kFieldTrialConfig_form_factors_96,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_84,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_83[] = {
      "OmniboxOnDeviceHeadProviderIncognito",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_95[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_95[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_86[] = {
    {
      "OnDeviceHeadSuggest_Incognito_Enabled",
      array_kFieldTrialConfig_platforms_95,
      1,
      array_kFieldTrialConfig_form_factors_95,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_83,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_82[] = {
      "OmniboxLocalEntitySuggestions",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_94[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_94[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_85[] = {
    {
      "DesktopAndAndroidExperiments",
      array_kFieldTrialConfig_platforms_94,
      1,
      array_kFieldTrialConfig_form_factors_94,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_82,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_81[] = {
      "OmniboxContextMenuShowFullUrls",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_93[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_93[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_84[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_93,
      1,
      array_kFieldTrialConfig_form_factors_93,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_81,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_80[] = {
      "NtpRealbox",
      "NtpRealboxMatchOmniboxTheme",
      "OmniboxDisplayTitleForCurrentUrl",
      "OmniboxDocumentProvider",
      "OmniboxHistoryQuickProviderAllowButDoNotScoreMidwordTerms",
      "OmniboxHistoryQuickProviderAllowMidwordContinuations",
      "OmniboxMaxURLMatches",
      "OmniboxOnFocusSuggestions",
      "OmniboxRemoveSuggestionsFromClipboard",
      "OmniboxRichEntitySuggestions",
      "OmniboxUIExperimentMaxAutocompleteMatches",
      "OmniboxZeroSuggestionsOnNTP",
      "QueryInOmnibox",
      "SearchSuggestChips",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_21[] = {
      {
        "OmniboxMaxURLMatches",
        "7",
      },
      {
        "UIMaxAutocompleteMatches",
        "8",
      },
      {
        "ZeroSuggestVariant:15:*",
        "RemoteNoUrl,Local",
      },
      {
        "ZeroSuggestVariant:1:*",
        "RemoteNoUrl,Local",
      },
      {
        "ZeroSuggestVariant:7:*",
        "RemoteNoUrl,Local",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_92[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_92[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_83[] = {
    {
      "DesktopExperiments",
      array_kFieldTrialConfig_platforms_92,
      1,
      array_kFieldTrialConfig_form_factors_92,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_21,
      5,
      array_kFieldTrialConfig_enable_features_80,
      14,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_79[] = {
      "AutofillUpstream",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_91[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_91[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_82[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_91,
      1,
      array_kFieldTrialConfig_form_factors_91,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_79,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_78[] = {
      "DisableSearchSuggestChips",
      "NtpWebUI",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_90[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_90[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_81[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_90,
      1,
      array_kFieldTrialConfig_form_factors_90,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_78,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_77[] = {
      "IPH_NewTab",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_20[] = {
      {
        "availability",
        "any",
      },
      {
        "event_new_tab_session_time_met",
        "name:new_tab_session_time_met;comparator:>=1;window:3650;storage:3650",
      },
      {
        "event_omnibox_used",
        "name:omnibox_used;comparator:>=1;window:3650;storage:3650",
      },
      {
        "event_trigger",
        "name:new_tab_trigger;comparator:==0;window:3650;storage:3650",
      },
      {
        "event_used",
        "name:new_tab_opened;comparator:==0;window:3650;storage:3650",
      },
      {
        "session_rate",
        "<0",
      },
      {
        "x_promo_string",
        "0",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_89[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_89[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_80[] = {
    {
      "Enabled_1",
      array_kFieldTrialConfig_platforms_89,
      1,
      array_kFieldTrialConfig_form_factors_89,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_20,
      7,
      array_kFieldTrialConfig_enable_features_77,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_76[] = {
      "AutofillCreditCardUploadFeedback",
      "AutofillEnableToolbarStatusChip",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_88[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_88[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_79[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_88,
      1,
      array_kFieldTrialConfig_form_factors_88,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_76,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_75[] = {
      "MirroringService",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_87[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_87[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_78[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_87,
      1,
      array_kFieldTrialConfig_form_factors_87,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_75,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_9[] = {
      "MergeBlockingNonBlockingPools",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_86[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_86[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_77[] = {
    {
      "Disabled",
      array_kFieldTrialConfig_platforms_86,
      1,
      array_kFieldTrialConfig_form_factors_86,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_9,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_74[] = {
      "UseMediaHistoryStore",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_85[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_85[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_76[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_85,
      1,
      array_kFieldTrialConfig_form_factors_85,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_74,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_84[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_84[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_75[] = {
    {
      "DBWindow5000Frames_20190225",
      array_kFieldTrialConfig_platforms_84,
      1,
      array_kFieldTrialConfig_form_factors_84,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_73[] = {
      "MaxOverlapBoundsForFixed",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_83[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_83[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_74[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_83,
      1,
      array_kFieldTrialConfig_form_factors_83,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_73,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_72[] = {
      "LowPriorityIframes",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_19[] = {
      {
        "max_effective_connection_type_threshold",
        "4G",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_82[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_82[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_73[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_82,
      1,
      array_kFieldTrialConfig_form_factors_82,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_19,
      1,
      array_kFieldTrialConfig_enable_features_72,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_71[] = {
      "UseFramePriorityInRenderProcessHost",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_81[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_81[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_72[] = {
    {
      "Enabled0",
      array_kFieldTrialConfig_platforms_81,
      1,
      array_kFieldTrialConfig_form_factors_81,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_71,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_70[] = {
      "TargetEmbeddingLookalikes",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_80[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_80[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_71[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_80,
      1,
      array_kFieldTrialConfig_form_factors_80,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_70,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_69[] = {
      "LoadingPredictorTableConfig",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_18[] = {
      {
        "max_hosts_to_track",
        "300",
      },
      {
        "max_origins_per_entry",
        "10",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_79[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_79[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_70[] = {
    {
      "Enabled_300_10",
      array_kFieldTrialConfig_platforms_79,
      1,
      array_kFieldTrialConfig_form_factors_79,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_18,
      2,
      array_kFieldTrialConfig_enable_features_69,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_68[] = {
      "LoadingPredictorDisregardAlwaysAccessesNetwork",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_78[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_78[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_69[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_78,
      1,
      array_kFieldTrialConfig_form_factors_78,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_68,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_67[] = {
      "ReducedReferrerGranularity",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_77[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_77[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_68[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_77,
      1,
      array_kFieldTrialConfig_form_factors_77,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_67,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_66[] = {
      "LegacyTLSEnforced",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_76[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_76[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_67[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_76,
      1,
      array_kFieldTrialConfig_form_factors_76,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_66,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_65[] = {
      "SetLowPriorityForBeacon",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_75[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_75[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_66[] = {
    {
      "Enabled_20191107",
      array_kFieldTrialConfig_platforms_75,
      1,
      array_kFieldTrialConfig_form_factors_75,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_65,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_64[] = {
      "KeepScriptResourceAlive",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_74[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_74[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_65[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_74,
      1,
      array_kFieldTrialConfig_form_factors_74,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_64,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_73[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_73[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_64[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_73,
      1,
      array_kFieldTrialConfig_form_factors_73,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_8[] = {
      "HighPriorityDatabaseTaskType",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_72[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_72[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_enable_features_63[] = {
      "HighPriorityDatabaseTaskType",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_71[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_71[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_63[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_71,
      1,
      array_kFieldTrialConfig_form_factors_71,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_63,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Control",
      array_kFieldTrialConfig_platforms_72,
      1,
      array_kFieldTrialConfig_form_factors_72,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_8,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_62[] = {
      "IPH_IncognitoWindow",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_17[] = {
      {
        "availability",
        "any",
      },
      {
        "event_incognito_window_session_time_met",
        "name:incognito_window_session_time_met;comparator:>=1;window:3650;storage:3650",
      },
      {
        "event_trigger",
        "name:incognito_window_trigger;comparator:==0;window:3650;storage:3650",
      },
      {
        "event_used",
        "name:incognito_window_opened;comparator:==0;window:3650;storage:3650",
      },
      {
        "session_rate",
        "<0",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_70[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_70[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_62[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_70,
      1,
      array_kFieldTrialConfig_form_factors_70,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_17,
      5,
      array_kFieldTrialConfig_enable_features_62,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_61[] = {
      "IncognitoDynamicQuota",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_16[] = {
      {
        "IncognitoQuotaRatioLowerBound",
        "0.1",
      },
      {
        "IncognitoQuotaRatioUpperBound",
        "0.2",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_69[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_69[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_61[] = {
    {
      "WideRange",
      array_kFieldTrialConfig_platforms_69,
      1,
      array_kFieldTrialConfig_form_factors_69,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_16,
      2,
      array_kFieldTrialConfig_enable_features_61,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_60[] = {
      "IncludeBetaForumMenuItem",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_68[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_68[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_60[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_68,
      1,
      array_kFieldTrialConfig_form_factors_68,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_60,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_59[] = {
      "HeapProfilerReporting",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_15[] = {
      {
        "sampling-rate",
        "1000000",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_67[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_67[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_59[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_67,
      1,
      array_kFieldTrialConfig_form_factors_67,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_15,
      1,
      array_kFieldTrialConfig_enable_features_59,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_58[] = {
      "MarkHttpAs",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_14[] = {
      {
        "treatment",
        "danger-warning",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_66[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_66[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_58[] = {
    {
      "enabled",
      array_kFieldTrialConfig_platforms_66,
      1,
      array_kFieldTrialConfig_form_factors_66,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_14,
      1,
      array_kFieldTrialConfig_enable_features_58,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_57[] = {
      "GpuWatchdogV2NewTimeout",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_65[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_65[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_57[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_65,
      1,
      array_kFieldTrialConfig_form_factors_65,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_57,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_56[] = {
      "GlobalMediaControlsPictureInPicture",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_64[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_64[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_56[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_64,
      1,
      array_kFieldTrialConfig_form_factors_64,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_56,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_55[] = {
      "GlobalMediaControls",
      "IPH_GlobalMediaControls",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_13[] = {
      {
        "availability",
        ">=0",
      },
      {
        "event_conditions_met",
        "name:media_backgrounded;comparator:>0;window:1;storage:365",
      },
      {
        "event_trigger",
        "name:global_media_controls_iph_triggered;comparator:==0;window:90;storage:365",
      },
      {
        "event_used",
        "name:global_media_controls_opened;comparator:==0;window:90;storage:365",
      },
      {
        "session_rate",
        "==0",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_63[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_63[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_55[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_63,
      1,
      array_kFieldTrialConfig_form_factors_63,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_13,
      5,
      array_kFieldTrialConfig_enable_features_55,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_54[] = {
      "GamepadPollingInterval",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_12[] = {
      {
        "interval-ms",
        "4",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_62[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_62[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_54[] = {
    {
      "EnabledGamepadPolling250Hz",
      array_kFieldTrialConfig_platforms_62,
      1,
      array_kFieldTrialConfig_form_factors_62,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_12,
      1,
      array_kFieldTrialConfig_enable_features_54,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_53[] = {
      "PrivacySettingsRedesign",
      "SafeBrowsingEnhancedProtection",
      "SyncSetupFriendlySettings",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_61[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_61[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_53[] = {
    {
      "Launched_20200616",
      array_kFieldTrialConfig_platforms_61,
      1,
      array_kFieldTrialConfig_form_factors_61,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_53,
      3,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_52[] = {
      "ForwardMemoryPressureEventsToGpuProcess",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_60[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_60[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_52[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_60,
      1,
      array_kFieldTrialConfig_form_factors_60,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_52,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_51[] = {
      "FormControlsRefresh",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_59[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_59[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_51[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_59,
      1,
      array_kFieldTrialConfig_form_factors_59,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_51,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_50[] = {
      "ForegroundVideoCaptureService",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_58[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_58[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_50[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_58,
      1,
      array_kFieldTrialConfig_form_factors_58,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_50,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_49[] = {
      "FontSrcLocalMatching",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_57[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_57[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_49[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_57,
      1,
      array_kFieldTrialConfig_form_factors_57,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_49,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_48[] = {
      "FontPreloadingDelaysRendering",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_11[] = {
      {
        "delay-in-ms",
        "150",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_56[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_56[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_48[] = {
    {
      "EnabledWithDelay150ms",
      array_kFieldTrialConfig_platforms_56,
      1,
      array_kFieldTrialConfig_form_factors_56,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_11,
      1,
      array_kFieldTrialConfig_enable_features_48,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_47[] = {
      "FlexNG",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_55[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_55[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_47[] = {
    {
      "Enabled_20200406",
      array_kFieldTrialConfig_platforms_55,
      1,
      array_kFieldTrialConfig_form_factors_55,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_47,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_46[] = {
      "FixedMaxBestEffortTasks",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_54[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_54[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_46[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_54,
      1,
      array_kFieldTrialConfig_form_factors_54,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_46,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_45[] = {
      "BlinkSchedulerBestEffortPriorityForFindInPage",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_53[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_53[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_45[] = {
    {
      "Enabled_20200601",
      array_kFieldTrialConfig_platforms_53,
      1,
      array_kFieldTrialConfig_form_factors_53,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_45,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_44[] = {
      "FilterAdsOnAbusiveSites",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_52[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_52[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_44[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_52,
      1,
      array_kFieldTrialConfig_form_factors_52,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_44,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_43[] = {
      "ExtensionsToolbarMenu",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_51[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_51[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_43[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_51,
      1,
      array_kFieldTrialConfig_form_factors_51,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_43,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_42[] = {
      "ExpectCTReporting",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_50[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_50[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_42[] = {
    {
      "ExpectCTReportingEnabled",
      array_kFieldTrialConfig_platforms_50,
      1,
      array_kFieldTrialConfig_form_factors_50,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_42,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_41[] = {
      "SafetyTip",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_10[] = {
      {
        "editdistance",
        "false",
      },
      {
        "editdistance_siteengagement",
        "true",
      },
      {
        "targetembedding",
        "false",
      },
      {
        "topsites",
        "true",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_49[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_49[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_41[] = {
    {
      "UIEnabled",
      array_kFieldTrialConfig_platforms_49,
      1,
      array_kFieldTrialConfig_form_factors_49,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_10,
      4,
      array_kFieldTrialConfig_enable_features_41,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_48[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_48[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_40[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_48,
      1,
      array_kFieldTrialConfig_form_factors_48,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_40[] = {
      "DynamicTcmallocTuning",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_9[] = {
      {
        "DynamicTcmallocScaleInvisibleTimeSec",
        "-1",
      },
      {
        "DynamicTcmallocTuneTimeSec",
        "120",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_47[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_47[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_enable_features_39[] = {
      "DynamicTcmallocTuning",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_8[] = {
      {
        "DynamicTcmallocScaleInvisibleTimeSec",
        "600",
      },
      {
        "DynamicTcmallocTuneTimeSec",
        "120",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_46[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_46[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_39[] = {
    {
      "EnabledAggressive_08222019",
      array_kFieldTrialConfig_platforms_46,
      1,
      array_kFieldTrialConfig_form_factors_46,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_8,
      2,
      array_kFieldTrialConfig_enable_features_39,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "EnabledConservative_08222019",
      array_kFieldTrialConfig_platforms_47,
      1,
      array_kFieldTrialConfig_form_factors_47,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_9,
      2,
      array_kFieldTrialConfig_enable_features_40,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_38[] = {
      "TreatUnsafeDownloadsAsActive",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_7[] = {
      {
        "BlockExtensionList",
        "mix_dl_blocked_for_testing",
      },
      {
        "SilentBlockExtensionList",
        "mix_dl_silently_blocked_for_testing",
      },
      {
        "TreatBlockListAsAllowlist",
        "false",
      },
      {
        "TreatSilentBlockListAsAllowlist",
        "false",
      },
      {
        "TreatWarnListAsAllowlist",
        "false",
      },
      {
        "WarnExtensionList",
        "exe,scr,msi,vb,dmg,pkg,crx",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_45[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_45[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_38[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_45,
      1,
      array_kFieldTrialConfig_form_factors_45,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_7,
      6,
      array_kFieldTrialConfig_enable_features_38,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_37[] = {
      "UseDownloadOfflineContentProvider",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_44[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_44[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_37[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_44,
      1,
      array_kFieldTrialConfig_form_factors_44,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_37,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_36[] = {
      "DisableMalwareExtensionsRemotely",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_43[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_43[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_36[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_43,
      1,
      array_kFieldTrialConfig_form_factors_43,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_36,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_35[] = {
      "DialMediaRouteProvider",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_42[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_42[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_35[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_42,
      1,
      array_kFieldTrialConfig_form_factors_42,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_35,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_34[] = {
      "TabGroups",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_41[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_41[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_34[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_41,
      1,
      array_kFieldTrialConfig_form_factors_41,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_34,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_7[] = {
      "FtpProtocol",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_40[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_40[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_33[] = {
    {
      "WithoutFtpSupport",
      array_kFieldTrialConfig_platforms_40,
      1,
      array_kFieldTrialConfig_form_factors_40,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_7,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_33[] = {
      "DelayAsyncScriptExecution",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_6[] = {
      {
        "delay_type",
        "first_paint_or_finished_parsing",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_39[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_39[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_32[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_39,
      1,
      array_kFieldTrialConfig_form_factors_39,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_6,
      1,
      array_kFieldTrialConfig_enable_features_33,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_32[] = {
      "DefaultPassthroughCommandDecoder",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_38[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_38[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_31[] = {
    {
      "Enabled_20191004",
      array_kFieldTrialConfig_platforms_38,
      1,
      array_kFieldTrialConfig_form_factors_38,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_32,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_31[] = {
      "DefaultEnableOopRasterization",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_37[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_37[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_30[] = {
    {
      "DefaultEnableOopRasterization",
      array_kFieldTrialConfig_platforms_37,
      1,
      array_kFieldTrialConfig_form_factors_37,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_31,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_30[] = {
      "DecodeJpeg420ImagesToYUV",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_36[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_36[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_29[] = {
    {
      "Experiment",
      array_kFieldTrialConfig_platforms_36,
      1,
      array_kFieldTrialConfig_form_factors_36,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_30,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_29[] = {
      "CodeCacheDeletionWithoutFilter",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_35[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_35[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_28[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_35,
      1,
      array_kFieldTrialConfig_form_factors_35,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_29,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_28[] = {
      "ClientSideDetectionModel",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_5[] = {
      {
        "ModelNum",
        "4",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_34[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_34[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_27[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_34,
      1,
      array_kFieldTrialConfig_form_factors_34,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_5,
      1,
      array_kFieldTrialConfig_enable_features_28,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_6[] = {
      "GlobalMediaControlsForCast",
};
const char* const array_kFieldTrialConfig_enable_features_27[] = {
      "CastMediaRouteProvider",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_33[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_33[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_enable_features_26[] = {
      "CastMediaRouteProvider",
      "GlobalMediaControlsForCast",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_32[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_32[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_26[] = {
    {
      "CMRP_and_GMCFC_enabled",
      array_kFieldTrialConfig_platforms_32,
      1,
      array_kFieldTrialConfig_form_factors_32,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_26,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "CMRP_enabled_GMCFC_disabled",
      array_kFieldTrialConfig_platforms_33,
      1,
      array_kFieldTrialConfig_form_factors_33,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_27,
      1,
      array_kFieldTrialConfig_disable_features_6,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_25[] = {
      "CacheStorageEagerReading",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_31[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_31[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_25[] = {
    {
      "Enabled2",
      array_kFieldTrialConfig_platforms_31,
      1,
      array_kFieldTrialConfig_form_factors_31,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_25,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_24[] = {
      "CSSReducedFontLoadingLayoutInvalidations",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_30[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_30[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_24[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_30,
      1,
      array_kFieldTrialConfig_form_factors_30,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_24,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_23[] = {
      "CSSReducedFontLoadingInvalidations",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_29[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_29[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_23[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_29,
      1,
      array_kFieldTrialConfig_form_factors_29,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_23,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_22[] = {
      "CSSOMViewScrollCoordinates",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_28[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_28[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_22[] = {
    {
      "EnableCSSOMViewScrollCoordinates",
      array_kFieldTrialConfig_platforms_28,
      1,
      array_kFieldTrialConfig_form_factors_28,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_22,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_21[] = {
      "CSSMatchedPropertiesCacheDependencies",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_27[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_27[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_21[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_27,
      1,
      array_kFieldTrialConfig_form_factors_27,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_21,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_26[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_26[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_20[] = {
    {
      "DetachTimeFg16x",
      array_kFieldTrialConfig_platforms_26,
      1,
      array_kFieldTrialConfig_form_factors_26,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_20[] = {
      "IPH_Bookmark",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_4[] = {
      {
        "availability",
        "any",
      },
      {
        "event_bookmark_added",
        "name:bookmark_added;comparator:==0;window:3650;storage:3650",
      },
      {
        "event_bookmark_session_time_met",
        "name:bookmark_session_time_met;comparator:>=1;window:3650;storage:3650",
      },
      {
        "event_trigger",
        "name:bookmark_trigger;comparator:==0;window:3650;storage:3650",
      },
      {
        "event_used",
        "name:bookmark_clicked;comparator:any;window:3650;storage:3650",
      },
      {
        "session_rate",
        "<=3",
      },
      {
        "x_promo_string",
        "IDS_BOOKMARK_PROMO_1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_25[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_25[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_19[] = {
    {
      "Enabled_1",
      array_kFieldTrialConfig_platforms_25,
      1,
      array_kFieldTrialConfig_form_factors_25,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_4,
      7,
      array_kFieldTrialConfig_enable_features_20,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_19[] = {
      "BlinkSchedulerPrioritizeCompositingUntilBeginMainFrame",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_24[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_24[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_18[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_24,
      1,
      array_kFieldTrialConfig_form_factors_24,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_19,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_5[] = {
      "BlinkSchedulerHighestPriorityForCompostingAfterInput",
};
const char* const array_kFieldTrialConfig_enable_features_18[] = {
      "BlinkSchedulerPrioritizeCompositingAfterInput",
      "BlinkSchedulerUseExplicitSignalForTriggeringCompositingPrioritization",
      "BlinkSchedulerUseWillBeginMainFrameForCompositingPrioritization",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_3[] = {
      {
        "number_of_tasks",
        "1",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_23[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_23[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_17[] = {
    {
      "ExplicitSignals_1task_high",
      array_kFieldTrialConfig_platforms_23,
      1,
      array_kFieldTrialConfig_form_factors_23,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_3,
      1,
      array_kFieldTrialConfig_enable_features_18,
      3,
      array_kFieldTrialConfig_disable_features_5,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_17[] = {
      "BlinkSchedulerHighPriorityInputOnCompositorThread",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_22[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_22[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_16[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_22,
      1,
      array_kFieldTrialConfig_form_factors_22,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_17,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_16[] = {
      "BlinkSchedulerWorkerThrottling",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_2[] = {
      {
        "max_budget_ms",
        "1000",
      },
      {
        "max_delay_ms",
        "60000",
      },
      {
        "recovery_rate",
        "0.01",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_21[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_21[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_15[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_21,
      1,
      array_kFieldTrialConfig_form_factors_21,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_2,
      3,
      array_kFieldTrialConfig_enable_features_16,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_15[] = {
      "AutofillUseVariationCountryCode",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_20[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_20[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_14[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_20,
      1,
      array_kFieldTrialConfig_form_factors_20,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_15,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_14[] = {
      "AutofillUseImprovedLabelDisambiguation",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_19[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_19[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_13[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_19,
      1,
      array_kFieldTrialConfig_form_factors_19,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_14,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_13[] = {
      "AutofillTokenPrefixMatching",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_18[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_18[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_12[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_18,
      1,
      array_kFieldTrialConfig_form_factors_18,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_13,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_12[] = {
      "AutofillEnforceMinRequiredFieldsForUpload",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_17[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_17[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_disable_features_4[] = {
      "AutofillEnforceMinRequiredFieldsForUpload",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_16[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_16[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_11[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_16,
      1,
      array_kFieldTrialConfig_form_factors_16,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_4,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "Control",
      array_kFieldTrialConfig_platforms_17,
      1,
      array_kFieldTrialConfig_form_factors_17,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_12,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_3[] = {
      "AutofillEnforceMinRequiredFieldsForQuery",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_15[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_15[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_enable_features_11[] = {
      "AutofillEnforceMinRequiredFieldsForQuery",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_14[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_14[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_disable_features_2[] = {
      "AutofillEnforceMinRequiredFieldsForQuery",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_13[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_13[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_disable_features_1[] = {
      "AutofillEnforceMinRequiredFieldsForQuery",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_12[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_12[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_10[] = {
    {
      "Enabled_AllSmallForms",
      array_kFieldTrialConfig_platforms_12,
      1,
      array_kFieldTrialConfig_form_factors_12,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_1,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "Enabled_NoSmallAddressForms",
      array_kFieldTrialConfig_platforms_13,
      1,
      array_kFieldTrialConfig_form_factors_13,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_2,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "Control_NoSmallForms",
      array_kFieldTrialConfig_platforms_14,
      1,
      array_kFieldTrialConfig_form_factors_14,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_11,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "Default_Enabled_NoSmallAddressForms",
      array_kFieldTrialConfig_platforms_15,
      1,
      array_kFieldTrialConfig_form_factors_15,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      array_kFieldTrialConfig_disable_features_3,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_10[] = {
      "AutofillPruneSuggestions",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_11[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_11[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_9[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_11,
      1,
      array_kFieldTrialConfig_form_factors_11,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_10,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_disable_features_0[] = {
      "AutofillProfileClientValidation ",
};
const char* const array_kFieldTrialConfig_enable_features_9[] = {
      "AutofillProfileServerValidation",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_10[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_10[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_enable_features_8[] = {
      "AutofillProfileClientValidation",
      "AutofillProfileServerValidation",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_9[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_9[] = {
      Study::PLATFORM_LINUX,
};
const char* const array_kFieldTrialConfig_disable_features[] = {
      "AutofillProfileServerValidation",
};
const char* const array_kFieldTrialConfig_enable_features_7[] = {
      "AutofillProfileClientValidation",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_8[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_8[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_8[] = {
    {
      "EnabledClient_20190211",
      array_kFieldTrialConfig_platforms_8,
      1,
      array_kFieldTrialConfig_form_factors_8,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_7,
      1,
      array_kFieldTrialConfig_disable_features,
      1,
      NULL,
      NULL,
      0,
    },
    {
      "EnabledClientServer_20190211",
      array_kFieldTrialConfig_platforms_9,
      1,
      array_kFieldTrialConfig_form_factors_9,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_8,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
    {
      "EnabledServer_20190211",
      array_kFieldTrialConfig_platforms_10,
      1,
      array_kFieldTrialConfig_form_factors_10,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_9,
      1,
      array_kFieldTrialConfig_disable_features_0,
      1,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_6[] = {
      "AutofillMetadataUploads",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_7[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_7[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_7[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_7,
      1,
      array_kFieldTrialConfig_form_factors_7,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_6,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_6[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_6[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_6[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_6,
      1,
      array_kFieldTrialConfig_form_factors_6,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      NULL,
      0,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_5[] = {
      "AutofillEnableSurfacingServerCardNickname",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_5[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_5[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_5[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_5,
      1,
      array_kFieldTrialConfig_form_factors_5,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_5,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_4[] = {
      "AutofillEnableCompanyName",
      "AutofillRejectCompanyBirthyear",
      "AutofillRejectCompanySocialTitle",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_4[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_4[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_4[] = {
    {
      "RejectBirthyearAndSocialTitleAsCompany_20200210",
      array_kFieldTrialConfig_platforms_4,
      1,
      array_kFieldTrialConfig_form_factors_4,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_4,
      3,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_3[] = {
      "AutofillCacheServerCardInfo",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_3[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_3[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_3[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_3,
      1,
      array_kFieldTrialConfig_form_factors_3,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_3,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_2[] = {
      "AutofillServerCommunication",
      "AutofillUseApi",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_1[] = {
      {
        "autofill-server-url",
        "https://content-autofill.googleapis.com/",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_2[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_2[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_2[] = {
    {
      "API_Enabled",
      array_kFieldTrialConfig_platforms_2,
      1,
      array_kFieldTrialConfig_form_factors_2,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_1,
      1,
      array_kFieldTrialConfig_enable_features_2,
      2,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_1[] = {
      "AudioServiceSandbox",
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_1[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_1[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_1[] = {
    {
      "AudioProcessSandboxLinux",
      array_kFieldTrialConfig_platforms_1,
      1,
      array_kFieldTrialConfig_form_factors_1,
      0,
      base::nullopt,
      NULL,
      NULL,
      0,
      array_kFieldTrialConfig_enable_features_1,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features_0[] = {
      "AutoupgradeMixedContent",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_0[] = {
      {
        "mode",
        "all-passive",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors_0[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms_0[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_0[] = {
    {
      "Enabled",
      array_kFieldTrialConfig_platforms_0,
      1,
      array_kFieldTrialConfig_form_factors_0,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params_0,
      1,
      array_kFieldTrialConfig_enable_features_0,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const char* const array_kFieldTrialConfig_enable_features[] = {
      "AlignFontDisplayAutoTimeoutWithLCPGoal",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params[] = {
      {
        "intervention-mode",
        "swap",
      },
      {
        "lcp-limit-in-ms",
        "1000",
      },
};
const Study::FormFactor array_kFieldTrialConfig_form_factors[] = {
};
const Study::Platform array_kFieldTrialConfig_platforms[] = {
      Study::PLATFORM_LINUX,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments[] = {
    {
      "EnabledWithSwapModeAndTimeout1000ms",
      array_kFieldTrialConfig_platforms,
      1,
      array_kFieldTrialConfig_form_factors,
      0,
      base::nullopt,
      NULL,
      array_kFieldTrialConfig_params,
      2,
      array_kFieldTrialConfig_enable_features,
      1,
      NULL,
      0,
      NULL,
      NULL,
      0,
    },
};
const FieldTrialTestingStudy array_kFieldTrialConfig_studies[] = {
  {
    "AlignFontDisplayAutoTimeoutWithLCPGoal",
    array_kFieldTrialConfig_experiments,
    1,
  },
  {
    "AllPassiveMixedContentAutoupgrade",
    array_kFieldTrialConfig_experiments_0,
    1,
  },
  {
    "AudioServiceSandboxLinux",
    array_kFieldTrialConfig_experiments_1,
    1,
  },
  {
    "AutofillAPIServer",
    array_kFieldTrialConfig_experiments_2,
    1,
  },
  {
    "AutofillCacheServerCardInfo",
    array_kFieldTrialConfig_experiments_3,
    1,
  },
  {
    "AutofillCompany",
    array_kFieldTrialConfig_experiments_4,
    1,
  },
  {
    "AutofillEnableSurfacingServerCardNickname",
    array_kFieldTrialConfig_experiments_5,
    1,
  },
  {
    "AutofillFieldMetadata",
    array_kFieldTrialConfig_experiments_6,
    1,
  },
  {
    "AutofillMetadataUploads",
    array_kFieldTrialConfig_experiments_7,
    1,
  },
  {
    "AutofillProfileValidation",
    array_kFieldTrialConfig_experiments_8,
    3,
  },
  {
    "AutofillPruneSuggestions",
    array_kFieldTrialConfig_experiments_9,
    1,
  },
  {
    "AutofillSmallFormSupport",
    array_kFieldTrialConfig_experiments_10,
    4,
  },
  {
    "AutofillSmallFormUploads",
    array_kFieldTrialConfig_experiments_11,
    2,
  },
  {
    "AutofillTokenPrefixMatching",
    array_kFieldTrialConfig_experiments_12,
    1,
  },
  {
    "AutofillUseImprovedLabelDisambiguation",
    array_kFieldTrialConfig_experiments_13,
    1,
  },
  {
    "AutofillUseVariationCountryCode",
    array_kFieldTrialConfig_experiments_14,
    1,
  },
  {
    "BlinkSchedulerDedicatedWorkerThrottling",
    array_kFieldTrialConfig_experiments_15,
    1,
  },
  {
    "BlinkSchedulerHighPriorityInputOnCompositorThread",
    array_kFieldTrialConfig_experiments_16,
    1,
  },
  {
    "BlinkSchedulerPrioritizeCompositingAfterInput",
    array_kFieldTrialConfig_experiments_17,
    1,
  },
  {
    "BlinkSchedulerPrioritizeRenderingUntilBeginMainFrame",
    array_kFieldTrialConfig_experiments_18,
    1,
  },
  {
    "BookmarkInProductHelp",
    array_kFieldTrialConfig_experiments_19,
    1,
  },
  {
    "BrowserScheduler",
    array_kFieldTrialConfig_experiments_20,
    1,
  },
  {
    "CSSMatchedPropertiesCacheDependencies",
    array_kFieldTrialConfig_experiments_21,
    1,
  },
  {
    "CSSOMViewScrollCoordinates",
    array_kFieldTrialConfig_experiments_22,
    1,
  },
  {
    "CSSReducedFontLoadingInvalidations",
    array_kFieldTrialConfig_experiments_23,
    1,
  },
  {
    "CSSReducedFontLoadingLayoutInvalidations",
    array_kFieldTrialConfig_experiments_24,
    1,
  },
  {
    "CacheStorageEagerReading",
    array_kFieldTrialConfig_experiments_25,
    1,
  },
  {
    "CastMediaRouteProviderAndGlobalMediaControlsForCast",
    array_kFieldTrialConfig_experiments_26,
    2,
  },
  {
    "ClientSideDetectionModel",
    array_kFieldTrialConfig_experiments_27,
    1,
  },
  {
    "CodeCacheDeletionWithoutFilter",
    array_kFieldTrialConfig_experiments_28,
    1,
  },
  {
    "DecodeJpegToYuv",
    array_kFieldTrialConfig_experiments_29,
    1,
  },
  {
    "DefaultEnableOopRasterization",
    array_kFieldTrialConfig_experiments_30,
    1,
  },
  {
    "DefaultPassthroughCommandDecoder",
    array_kFieldTrialConfig_experiments_31,
    1,
  },
  {
    "DelayAsyncScriptExecution",
    array_kFieldTrialConfig_experiments_32,
    1,
  },
  {
    "DeprecateFtp",
    array_kFieldTrialConfig_experiments_33,
    1,
  },
  {
    "DesktopTabGroups",
    array_kFieldTrialConfig_experiments_34,
    1,
  },
  {
    "DialMediaRouteProvider",
    array_kFieldTrialConfig_experiments_35,
    1,
  },
  {
    "DisableMalwareExtensionsRemotely",
    array_kFieldTrialConfig_experiments_36,
    1,
  },
  {
    "DownloadOfflineContentProvider",
    array_kFieldTrialConfig_experiments_37,
    1,
  },
  {
    "DownloadsAsMixedContent",
    array_kFieldTrialConfig_experiments_38,
    1,
  },
  {
    "DynamicTcmallocThreadCache",
    array_kFieldTrialConfig_experiments_39,
    2,
  },
  {
    "EnableMediaRouter",
    array_kFieldTrialConfig_experiments_40,
    1,
  },
  {
    "EnableSafetyTipUI",
    array_kFieldTrialConfig_experiments_41,
    1,
  },
  {
    "ExpectCTReporting",
    array_kFieldTrialConfig_experiments_42,
    1,
  },
  {
    "ExtensionsToolbarMenu",
    array_kFieldTrialConfig_experiments_43,
    1,
  },
  {
    "FilterAdsOnAbusiveSites",
    array_kFieldTrialConfig_experiments_44,
    1,
  },
  {
    "FindInPageBestEffortPriority",
    array_kFieldTrialConfig_experiments_45,
    1,
  },
  {
    "FixedMaxBestEffortTasks",
    array_kFieldTrialConfig_experiments_46,
    1,
  },
  {
    "FlexNG",
    array_kFieldTrialConfig_experiments_47,
    1,
  },
  {
    "FontPreloadingDelaysRendering",
    array_kFieldTrialConfig_experiments_48,
    1,
  },
  {
    "FontSrcLocalMatching",
    array_kFieldTrialConfig_experiments_49,
    1,
  },
  {
    "ForegroundVideoCaptureService",
    array_kFieldTrialConfig_experiments_50,
    1,
  },
  {
    "FormControlsRefresh",
    array_kFieldTrialConfig_experiments_51,
    1,
  },
  {
    "ForwardMemoryPressureEventsToGpuProcess",
    array_kFieldTrialConfig_experiments_52,
    1,
  },
  {
    "FriendlySettingsHats",
    array_kFieldTrialConfig_experiments_53,
    1,
  },
  {
    "GamepadPollingInterval",
    array_kFieldTrialConfig_experiments_54,
    1,
  },
  {
    "GlobalMediaControlsInProductHelp",
    array_kFieldTrialConfig_experiments_55,
    1,
  },
  {
    "GlobalMediaControlsPictureInPicture",
    array_kFieldTrialConfig_experiments_56,
    1,
  },
  {
    "GpuWatchdogV2NewTimeout",
    array_kFieldTrialConfig_experiments_57,
    1,
  },
  {
    "HTTPDangerWarning",
    array_kFieldTrialConfig_experiments_58,
    1,
  },
  {
    "HeapProfiling",
    array_kFieldTrialConfig_experiments_59,
    1,
  },
  {
    "IncludeBetaForumMenuItem",
    array_kFieldTrialConfig_experiments_60,
    1,
  },
  {
    "IncognitoDynamicQuota",
    array_kFieldTrialConfig_experiments_61,
    1,
  },
  {
    "IncognitoWindowInProductHelp",
    array_kFieldTrialConfig_experiments_62,
    1,
  },
  {
    "IndexedDBHighPriority",
    array_kFieldTrialConfig_experiments_63,
    2,
  },
  {
    "InstanceID",
    array_kFieldTrialConfig_experiments_64,
    1,
  },
  {
    "KeepScriptResourceAlive",
    array_kFieldTrialConfig_experiments_65,
    1,
  },
  {
    "KeepaliveRequestPriority",
    array_kFieldTrialConfig_experiments_66,
    1,
  },
  {
    "LegacyTLSDeprecation2",
    array_kFieldTrialConfig_experiments_67,
    1,
  },
  {
    "LimitReferrerGranularity",
    array_kFieldTrialConfig_experiments_68,
    1,
  },
  {
    "LoadingPredictorDisregardAlwaysAccessesNetwork",
    array_kFieldTrialConfig_experiments_69,
    1,
  },
  {
    "LoadingPredictorTableConfig",
    array_kFieldTrialConfig_experiments_70,
    1,
  },
  {
    "LookalikeTargetEmbeddingHeuristic",
    array_kFieldTrialConfig_experiments_71,
    1,
  },
  {
    "LowPriorityAdProcesses",
    array_kFieldTrialConfig_experiments_72,
    1,
  },
  {
    "LowPriorityIframes2",
    array_kFieldTrialConfig_experiments_73,
    1,
  },
  {
    "MaxOverlapBoundsForFixed",
    array_kFieldTrialConfig_experiments_74,
    1,
  },
  {
    "MediaCapabilitiesWithParameters",
    array_kFieldTrialConfig_experiments_75,
    1,
  },
  {
    "MediaHistory",
    array_kFieldTrialConfig_experiments_76,
    1,
  },
  {
    "MergeBlockingNonBlockingPools",
    array_kFieldTrialConfig_experiments_77,
    1,
  },
  {
    "MirroringService",
    array_kFieldTrialConfig_experiments_78,
    1,
  },
  {
    "MyChromeEverywhere",
    array_kFieldTrialConfig_experiments_79,
    1,
  },
  {
    "NewTabInProductHelp",
    array_kFieldTrialConfig_experiments_80,
    1,
  },
  {
    "NtpWebUIDesktop",
    array_kFieldTrialConfig_experiments_81,
    1,
  },
  {
    "OfferUploadCreditCards",
    array_kFieldTrialConfig_experiments_82,
    1,
  },
  {
    "OmniboxBundledExperimentV1",
    array_kFieldTrialConfig_experiments_83,
    1,
  },
  {
    "OmniboxContextMenuShowFullUrls",
    array_kFieldTrialConfig_experiments_84,
    1,
  },
  {
    "OmniboxLocalEntities",
    array_kFieldTrialConfig_experiments_85,
    1,
  },
  {
    "OmniboxOnDeviceHeadSuggestIncognito",
    array_kFieldTrialConfig_experiments_86,
    1,
  },
  {
    "OmniboxOnDeviceHeadSuggestNonIncognito",
    array_kFieldTrialConfig_experiments_87,
    1,
  },
  {
    "OmniboxPreserveDefaultMatchAgainstAsyncUpdate",
    array_kFieldTrialConfig_experiments_88,
    1,
  },
  {
    "OmniboxSteadyStateElisions",
    array_kFieldTrialConfig_experiments_89,
    1,
  },
  {
    "OutOfBlinkCors",
    array_kFieldTrialConfig_experiments_90,
    1,
  },
  {
    "OverflowIconsForMediaControls",
    array_kFieldTrialConfig_experiments_91,
    1,
  },
  {
    "PaintHolding",
    array_kFieldTrialConfig_experiments_92,
    1,
  },
  {
    "PartitionConnectionsByNetworkIsolationKey",
    array_kFieldTrialConfig_experiments_93,
    1,
  },
  {
    "PasswordCheck",
    array_kFieldTrialConfig_experiments_94,
    1,
  },
  {
    "PaymentRequestAlwaysAllowJustInTimePaymentApp",
    array_kFieldTrialConfig_experiments_95,
    1,
  },
  {
    "PermissionPromptUIViews",
    array_kFieldTrialConfig_experiments_96,
    1,
  },
  {
    "PersistentHistograms",
    array_kFieldTrialConfig_experiments_97,
    1,
  },
  {
    "PolicyAtomicGroup",
    array_kFieldTrialConfig_experiments_98,
    1,
  },
  {
    "PreconnectSameOriginDesktop",
    array_kFieldTrialConfig_experiments_99,
    1,
  },
  {
    "PreconnectToSearch",
    array_kFieldTrialConfig_experiments_100,
    1,
  },
  {
    "PreloadMetadataLazyLoad",
    array_kFieldTrialConfig_experiments_101,
    1,
  },
  {
    "ProactivelySwapBrowsingInstance",
    array_kFieldTrialConfig_experiments_102,
    1,
  },
  {
    "ProactivelyThrottleLowPriorityRequests",
    array_kFieldTrialConfig_experiments_103,
    1,
  },
  {
    "ProtoDBSharedMigration",
    array_kFieldTrialConfig_experiments_104,
    1,
  },
  {
    "QUIC",
    array_kFieldTrialConfig_experiments_105,
    1,
  },
  {
    "QuietNotificationPrompts",
    array_kFieldTrialConfig_experiments_106,
    1,
  },
  {
    "QuotaExpandPoolSize",
    array_kFieldTrialConfig_experiments_107,
    1,
  },
  {
    "RenderDocument",
    array_kFieldTrialConfig_experiments_108,
    1,
  },
  {
    "ReopenTabInProductHelp",
    array_kFieldTrialConfig_experiments_109,
    1,
  },
  {
    "ReportCertificateErrors",
    array_kFieldTrialConfig_experiments_110,
    2,
  },
  {
    "ReportingAPIAndNetworkErrorLogging",
    array_kFieldTrialConfig_experiments_111,
    1,
  },
  {
    "SSLCommonNameMismatchHandling",
    array_kFieldTrialConfig_experiments_112,
    1,
  },
  {
    "SafeBrowsingAdPopupTrigger",
    array_kFieldTrialConfig_experiments_113,
    1,
  },
  {
    "SafeBrowsingAdRedirectTrigger",
    array_kFieldTrialConfig_experiments_114,
    1,
  },
  {
    "SafeBrowsingAdSamplerTrigger",
    array_kFieldTrialConfig_experiments_115,
    3,
  },
  {
    "SafeBrowsingCommittedInterstitials",
    array_kFieldTrialConfig_experiments_116,
    1,
  },
  {
    "SafeBrowsingPasswordProtectionForSavedPasswords",
    array_kFieldTrialConfig_experiments_117,
    1,
  },
  {
    "SafeBrowsingPasswordProtectionForSignedInUsers",
    array_kFieldTrialConfig_experiments_118,
    1,
  },
  {
    "SafeBrowsingPasswordProtectionShowDomainsForSavedPasswords",
    array_kFieldTrialConfig_experiments_119,
    1,
  },
  {
    "SafeBrowsingRealTimeUrlLookupEnabled",
    array_kFieldTrialConfig_experiments_120,
    1,
  },
  {
    "SafeBrowsingRealTimeUrlLookupEnabledWithToken",
    array_kFieldTrialConfig_experiments_121,
    1,
  },
  {
    "SafeBrowsingSuspiciousSiteTrigger",
    array_kFieldTrialConfig_experiments_122,
    2,
  },
  {
    "SafeBrowsingThreatDomDetailsTagAttributes",
    array_kFieldTrialConfig_experiments_123,
    2,
  },
  {
    "SameSiteByDefaultCookies_Linux",
    array_kFieldTrialConfig_experiments_124,
    1,
  },
  {
    "ServiceWorkerOnUI",
    array_kFieldTrialConfig_experiments_125,
    1,
  },
  {
    "SharedClipboard",
    array_kFieldTrialConfig_experiments_126,
    1,
  },
  {
    "SharingFilterDevices",
    array_kFieldTrialConfig_experiments_127,
    1,
  },
  {
    "SplitCacheByNetworkIsolationKey",
    array_kFieldTrialConfig_experiments_128,
    1,
  },
  {
    "SqlSkipPreload",
    array_kFieldTrialConfig_experiments_129,
    1,
  },
  {
    "StorageServiceOutOfProcess",
    array_kFieldTrialConfig_experiments_130,
    1,
  },
  {
    "SyncInstanceIDTokenTTL",
    array_kFieldTrialConfig_experiments_131,
    1,
  },
  {
    "SyncRefreshDeviceInfo",
    array_kFieldTrialConfig_experiments_132,
    1,
  },
  {
    "TabHoverCardImages",
    array_kFieldTrialConfig_experiments_133,
    1,
  },
  {
    "TabHoverCards",
    array_kFieldTrialConfig_experiments_134,
    1,
  },
  {
    "TextFragmentAnchor",
    array_kFieldTrialConfig_experiments_135,
    1,
  },
  {
    "TextfieldFocusOnTapUp",
    array_kFieldTrialConfig_experiments_136,
    1,
  },
  {
    "TextureLayerSkipWaitForActivation",
    array_kFieldTrialConfig_experiments_137,
    1,
  },
  {
    "ThrottleDelayable",
    array_kFieldTrialConfig_experiments_138,
    1,
  },
  {
    "ThrottleInstallingServiceWorker",
    array_kFieldTrialConfig_experiments_139,
    1,
  },
  {
    "TranslateRankerModel",
    array_kFieldTrialConfig_experiments_140,
    1,
  },
  {
    "TranslateServerStudy",
    array_kFieldTrialConfig_experiments_141,
    1,
  },
  {
    "TranslateSubFramesStudy",
    array_kFieldTrialConfig_experiments_142,
    1,
  },
  {
    "TrustedTypes",
    array_kFieldTrialConfig_experiments_143,
    1,
  },
  {
    "UnifiedAutoplay",
    array_kFieldTrialConfig_experiments_144,
    1,
  },
  {
    "UsePreferredIntervalForVideo",
    array_kFieldTrialConfig_experiments_145,
    1,
  },
  {
    "UseSkiaRenderer",
    array_kFieldTrialConfig_experiments_146,
    1,
  },
  {
    "UserDataSnapshot",
    array_kFieldTrialConfig_experiments_147,
    1,
  },
  {
    "UsernameFirstFlow",
    array_kFieldTrialConfig_experiments_148,
    1,
  },
  {
    "V8ConcurrentInlining",
    array_kFieldTrialConfig_experiments_149,
    2,
  },
  {
    "V8SiteIsolatedCodeCache",
    array_kFieldTrialConfig_experiments_150,
    1,
  },
  {
    "VideoCaptureService",
    array_kFieldTrialConfig_experiments_151,
    1,
  },
  {
    "VideoSurfaceLayer",
    array_kFieldTrialConfig_experiments_152,
    1,
  },
  {
    "WebAudioAutoplay",
    array_kFieldTrialConfig_experiments_153,
    1,
  },
  {
    "WebBluetoothBlocklist",
    array_kFieldTrialConfig_experiments_154,
    1,
  },
  {
    "WebPaymentsPerMethodCanMakePaymentQuota",
    array_kFieldTrialConfig_experiments_155,
    1,
  },
  {
    "WebRTC-Audio-NetEqDecisionLogicSettings",
    array_kFieldTrialConfig_experiments_156,
    1,
  },
  {
    "WebRTC-Audio-NetEqDelayHistogram",
    array_kFieldTrialConfig_experiments_157,
    1,
  },
  {
    "WebRTC-Audio-NewOpusPacketLossRateOptimization",
    array_kFieldTrialConfig_experiments_158,
    1,
  },
  {
    "WebRTC-Audio-SendSideBwe",
    array_kFieldTrialConfig_experiments_159,
    1,
  },
  {
    "WebRTC-Bwe-MaxRttLimit",
    array_kFieldTrialConfig_experiments_160,
    1,
  },
  {
    "WebRTC-CongestionWindow",
    array_kFieldTrialConfig_experiments_161,
    1,
  },
  {
    "WebRTC-EnableWebRtcEcdsa",
    array_kFieldTrialConfig_experiments_162,
    1,
  },
  {
    "WebRTC-LocalIPPermissionCheck",
    array_kFieldTrialConfig_experiments_163,
    1,
  },
  {
    "WebRTC-NewCpuLoadEstimator",
    array_kFieldTrialConfig_experiments_164,
    1,
  },
  {
    "WebRTC-Pacer-BlockAudio",
    array_kFieldTrialConfig_experiments_165,
    1,
  },
  {
    "WebRTC-ProbingScreenshareBwe",
    array_kFieldTrialConfig_experiments_166,
    1,
  },
  {
    "WebRTC-VP8ConferenceTemporalLayers",
    array_kFieldTrialConfig_experiments_167,
    1,
  },
  {
    "WebRTC-Video-MinVideoBitrate",
    array_kFieldTrialConfig_experiments_168,
    1,
  },
  {
    "WebRTC-VideoRateControl",
    array_kFieldTrialConfig_experiments_169,
    1,
  },
  {
    "WebRTC-Vp9ExternalRefCtrl",
    array_kFieldTrialConfig_experiments_170,
    1,
  },
  {
    "WebRtcHybridAgc",
    array_kFieldTrialConfig_experiments_171,
    1,
  },
  {
    "WebUITabStrip",
    array_kFieldTrialConfig_experiments_172,
    1,
  },
  {
    "libvpx_for_vp8",
    array_kFieldTrialConfig_experiments_173,
    1,
  },
  {
    "use-new-media-cache",
    array_kFieldTrialConfig_experiments_174,
    1,
  },
};
const FieldTrialTestingConfig kFieldTrialConfig = {
  array_kFieldTrialConfig_studies,
  176,
};

}  // namespace variations
