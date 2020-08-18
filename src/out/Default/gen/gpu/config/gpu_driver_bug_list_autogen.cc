// Copyright (c) 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
//    gpu/config/process_json.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#include "gpu/config/gpu_driver_bug_list_autogen.h"

#include "gpu/config/gpu_driver_bug_list_arrays_and_structs_autogen.h"
#include "gpu/config/gpu_driver_bug_list_exceptions_autogen.h"

namespace gpu {

const GpuControlList::Entry kGpuDriverBugListEntries[] = {
{
19,  // id
"Disable depth textures on older Qualcomm GPUs (legacy blacklist entry, original problem unclear)",
base::size(kFeatureListForWorkaroundsEntry19),  // features size
kFeatureListForWorkaroundsEntry19,  // features
base::size(kDisabledExtensionsForEntry19),  // DisabledExtensions size
kDisabledExtensionsForEntry19,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry19),  // CrBugs size
kCrBugsForWorkaroundsEntry19,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry19,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry19_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
31,  // id
"The Mali-3xx/4xx/Txxx driver does not guarantee flush ordering",
base::size(kFeatureListForWorkaroundsEntry31),  // features size
kFeatureListForWorkaroundsEntry31,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry31),  // CrBugs size
kCrBugsForWorkaroundsEntry31,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry31,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry31_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
33,  // id
"Share group-related crashes and poor context switching perf on Imagination drivers",
base::size(kFeatureListForWorkaroundsEntry33),  // features size
kFeatureListForWorkaroundsEntry33,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
0,  // CrBugs size
nullptr,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry33,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry33_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
37,  // id
"Program link fails in NVIDIA Linux if gl_Position is not set",
base::size(kFeatureListForWorkaroundsEntry37),  // features size
kFeatureListForWorkaroundsEntry37,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry37),  // CrBugs size
kCrBugsForWorkaroundsEntry37,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry37,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry37_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
54,  // id
"Clear uniforms before first program use on all platforms",
base::size(kFeatureListForWorkaroundsEntry54),  // features size
kFeatureListForWorkaroundsEntry54,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry54),  // CrBugs size
kCrBugsForWorkaroundsEntry54,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry54_619971032,  // more data
},
base::size(kExceptionsForEntry54),  // exceptions count
kExceptionsForEntry54,  // exceptions
},
{
55,  // id
"Mesa drivers in Linux handle varyings without static use incorrectly",
base::size(kFeatureListForWorkaroundsEntry55),  // features size
kFeatureListForWorkaroundsEntry55,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry55),  // CrBugs size
kCrBugsForWorkaroundsEntry55,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry55,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry55_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
59,  // id
"Multisampling is buggy in Intel IvyBridge",
base::size(kFeatureListForWorkaroundsEntry59),  // features size
kFeatureListForWorkaroundsEntry59,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry59),  // CrBugs size
kCrBugsForWorkaroundsEntry59,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x8086,  // vendor_id
base::size(kDevicesForWorkaroundsEntry59),  // Devices size
kDevicesForWorkaroundsEntry59,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry59_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
64,  // id
"Linux AMD drivers incorrectly return initial value of 1 for TEXTURE_MAX_ANISOTROPY",
base::size(kFeatureListForWorkaroundsEntry64),  // features size
kFeatureListForWorkaroundsEntry64,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry64),  // CrBugs size
kCrBugsForWorkaroundsEntry64,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x1002,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry64_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
65,  // id
"Linux NVIDIA drivers don't have the correct defaults for vertex attributes",
base::size(kFeatureListForWorkaroundsEntry65),  // features size
kFeatureListForWorkaroundsEntry65,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry65),  // CrBugs size
kCrBugsForWorkaroundsEntry65,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry65,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry65_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
68,  // id
"Disable partial swaps on Mesa drivers (detected with GL_RENDERER)",
base::size(kFeatureListForWorkaroundsEntry68),  // features size
kFeatureListForWorkaroundsEntry68,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry68),  // CrBugs size
kCrBugsForWorkaroundsEntry68,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry68,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry68_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
88,  // id
"Always rewrite vec/mat constructors to be consistent",
base::size(kFeatureListForWorkaroundsEntry88),  // features size
kFeatureListForWorkaroundsEntry88,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry88),  // CrBugs size
kCrBugsForWorkaroundsEntry88,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry88_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
90,  // id
"Linux AMD drivers handle struct scopes incorrectly",
base::size(kFeatureListForWorkaroundsEntry90),  // features size
kFeatureListForWorkaroundsEntry90,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry90),  // CrBugs size
kCrBugsForWorkaroundsEntry90,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x1002,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry90_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
108,  // id
"Mali-4xx on Linux does not support GL_RGB format",
base::size(kFeatureListForWorkaroundsEntry108),  // features size
kFeatureListForWorkaroundsEntry108,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry108),  // CrBugs size
kCrBugsForWorkaroundsEntry108,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry108,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry108_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
109,  // id
"MakeCurrent is slow on Linux with NVIDIA drivers",
base::size(kFeatureListForWorkaroundsEntry109),  // features size
kFeatureListForWorkaroundsEntry109,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry109),  // CrBugs size
kCrBugsForWorkaroundsEntry109,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry109,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry109_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
111,  // id
"Discard Framebuffer breaks WebGL on Mali-4xx Linux",
base::size(kFeatureListForWorkaroundsEntry111),  // features size
kFeatureListForWorkaroundsEntry111,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry111),  // CrBugs size
kCrBugsForWorkaroundsEntry111,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry111,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry111_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
118,  // id
"NVIDIA 331 series drivers shader compiler may crash when attempting to optimize pow()",
base::size(kFeatureListForWorkaroundsEntry118),  // features size
kFeatureListForWorkaroundsEntry118,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry118),  // CrBugs size
kCrBugsForWorkaroundsEntry118,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry118,  // driver info
&kGLStringsForWorkaroundsEntry118,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry118_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
123,  // id
"NVIDIA drivers before 346 lack features in NV_path_rendering and related extensions to implement driver level path rendering.",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry123),  // DisabledExtensions size
kDisabledExtensionsForEntry123,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry123),  // CrBugs size
kCrBugsForWorkaroundsEntry123,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry123,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry123_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
128,  // id
"Linux ATI drivers crash on binding incomplete cube map texture to FBO",
base::size(kFeatureListForWorkaroundsEntry128),  // features size
kFeatureListForWorkaroundsEntry128,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry128),  // CrBugs size
kCrBugsForWorkaroundsEntry128,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x1002,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry128_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
130,  // id
"NVIDIA fails glReadPixels from incomplete cube map texture",
base::size(kFeatureListForWorkaroundsEntry130),  // features size
kFeatureListForWorkaroundsEntry130,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry130),  // CrBugs size
kCrBugsForWorkaroundsEntry130,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry130,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry130_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
131,  // id
"Linux Mesa drivers crash on glTexSubImage2D() to texture storage bound to FBO",
base::size(kFeatureListForWorkaroundsEntry131),  // features size
kFeatureListForWorkaroundsEntry131,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry131),  // CrBugs size
kCrBugsForWorkaroundsEntry131,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry131,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry131_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
132,  // id
"On Intel GPUs MSAA performance is not acceptable for GPU rasterization",
base::size(kFeatureListForWorkaroundsEntry132),  // features size
kFeatureListForWorkaroundsEntry132,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry132),  // CrBugs size
kCrBugsForWorkaroundsEntry132,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x8086,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryActive,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry132_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
139,  // id
"Mesa drivers wrongly report supporting GL_EXT_texture_rg with GLES 2.0 prior version 11.1",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry139),  // DisabledExtensions size
kDisabledExtensionsForEntry139,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry139),  // CrBugs size
kCrBugsForWorkaroundsEntry139,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry139,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry139_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
142,  // id
"Pack parameters work incorrectly with pack buffer bound",
base::size(kFeatureListForWorkaroundsEntry142),  // features size
kFeatureListForWorkaroundsEntry142,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry142),  // CrBugs size
kCrBugsForWorkaroundsEntry142,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry142,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry142_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
150,  // id
"Alignment works incorrectly with unpack buffer bound",
base::size(kFeatureListForWorkaroundsEntry150),  // features size
kFeatureListForWorkaroundsEntry150,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry150),  // CrBugs size
kCrBugsForWorkaroundsEntry150,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry150,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry150_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
153,  // id
"Vivante GC1000 with EXT_multisampled_render_to_texture fails glReadPixels",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry153),  // DisabledExtensions size
kDisabledExtensionsForEntry153,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry153),  // CrBugs size
kCrBugsForWorkaroundsEntry153,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry153,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry153_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
159,  // id
"Framebuffer discarding can hurt performance on non-tilers",
base::size(kFeatureListForWorkaroundsEntry159),  // features size
kFeatureListForWorkaroundsEntry159,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry159),  // CrBugs size
kCrBugsForWorkaroundsEntry159,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry159,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry159_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
160,  // id
"Framebuffer discarding not useful on NVIDIA Kepler architecture and later",
base::size(kFeatureListForWorkaroundsEntry160),  // features size
kFeatureListForWorkaroundsEntry160,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry160),  // CrBugs size
kCrBugsForWorkaroundsEntry160,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry160,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry160_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
165,  // id
"Unpacking overlapping rows from unpack buffers is unstable on NVIDIA GL driver",
base::size(kFeatureListForWorkaroundsEntry165),  // features size
kFeatureListForWorkaroundsEntry165,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry165),  // CrBugs size
kCrBugsForWorkaroundsEntry165,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry165,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry165_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
168,  // id
"VirtualBox driver doesn't correctly support partial swaps.",
base::size(kFeatureListForWorkaroundsEntry168),  // features size
kFeatureListForWorkaroundsEntry168,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry168),  // CrBugs size
kCrBugsForWorkaroundsEntry168,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x80ee,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry168_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
190,  // id
"Disable partial swaps on Mesa drivers (detected with GL_VERSION)",
base::size(kFeatureListForWorkaroundsEntry190),  // features size
kFeatureListForWorkaroundsEntry190,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry190),  // CrBugs size
kCrBugsForWorkaroundsEntry190,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry190,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry190_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
192,  // id
"Decode and encode before generateMipmap for srgb format textures on os except macosx",
base::size(kFeatureListForWorkaroundsEntry192),  // features size
kFeatureListForWorkaroundsEntry192,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry192),  // CrBugs size
kCrBugsForWorkaroundsEntry192,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry192_619971032,  // more data
},
base::size(kExceptionsForEntry192),  // exceptions count
kExceptionsForEntry192,  // exceptions
},
{
198,  // id
"adjust src/dst region if blitting pixels outside framebuffer on Linux Intel",
base::size(kFeatureListForWorkaroundsEntry198),  // features size
kFeatureListForWorkaroundsEntry198,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry198),  // CrBugs size
kCrBugsForWorkaroundsEntry198,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x8086,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry198_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
199,  // id
"adjust src/dst region if blitting pixels outside framebuffer on Linux AMD",
base::size(kFeatureListForWorkaroundsEntry199),  // features size
kFeatureListForWorkaroundsEntry199,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry199),  // CrBugs size
kCrBugsForWorkaroundsEntry199,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x1002,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry199_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
201,  // id
"AMD drivers in Linux require invariant qualifier to match between vertex and fragment shaders",
base::size(kFeatureListForWorkaroundsEntry201),  // features size
kFeatureListForWorkaroundsEntry201,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry201),  // CrBugs size
kCrBugsForWorkaroundsEntry201,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x1002,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry201_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
203,  // id
"Mesa driver GL 3.3 requires invariant and centroid to match between shaders",
base::size(kFeatureListForWorkaroundsEntry203),  // features size
kFeatureListForWorkaroundsEntry203,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry203),  // CrBugs size
kCrBugsForWorkaroundsEntry203,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry203,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry203_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
206,  // id
"Disable KHR_blend_equation_advanced until cc shaders are updated",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry206),  // DisabledExtensions size
kDisabledExtensionsForEntry206,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry206),  // CrBugs size
kCrBugsForWorkaroundsEntry206,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry206_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
208,  // id
"Decode and Encode before generateMipmap for srgb format textures on Linux Mesa ANGLE path",
base::size(kFeatureListForWorkaroundsEntry208),  // features size
kFeatureListForWorkaroundsEntry208,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry208),  // CrBugs size
kCrBugsForWorkaroundsEntry208,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x8086,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry208,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry208_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
210,  // id
"Decode and Encode before generateMipmap for srgb format textures on Linux AMD",
base::size(kFeatureListForWorkaroundsEntry210),  // features size
kFeatureListForWorkaroundsEntry210,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry210),  // CrBugs size
kCrBugsForWorkaroundsEntry210,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x1002,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry210_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
213,  // id
"The Mali-Gxx driver does not guarantee flush ordering",
base::size(kFeatureListForWorkaroundsEntry213),  // features size
kFeatureListForWorkaroundsEntry213,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry213),  // CrBugs size
kCrBugsForWorkaroundsEntry213,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry213,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry213_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
214,  // id
"Some Adreno 3xx don't setup scissor state correctly when FBO0 is bound, nor support MSAA properly.",
base::size(kFeatureListForWorkaroundsEntry214),  // features size
kFeatureListForWorkaroundsEntry214,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry214),  // CrBugs size
kCrBugsForWorkaroundsEntry214,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry214,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry214_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
215,  // id
"Fake no-op GPU driver bug workaround for testing",
base::size(kFeatureListForWorkaroundsEntry215),  // features size
kFeatureListForWorkaroundsEntry215,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry215),  // CrBugs size
kCrBugsForWorkaroundsEntry215,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry215_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
222,  // id
"Software to Accelerated canvas update breaks Linux AMD",
base::size(kFeatureListForWorkaroundsEntry222),  // features size
kFeatureListForWorkaroundsEntry222,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry222),  // CrBugs size
kCrBugsForWorkaroundsEntry222,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x1002,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry222_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
223,  // id
"Force integer or srgb cube map texture complete on Linux AMD",
base::size(kFeatureListForWorkaroundsEntry223),  // features size
kFeatureListForWorkaroundsEntry223,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry223),  // CrBugs size
kCrBugsForWorkaroundsEntry223,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x1002,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry223_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
257,  // id
"Fake entry for testing disabling of WebGL extensions",
0,  // feature size
nullptr,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
base::size(kDisabledWebGLExtensionsForEntry257),  // DisabledWebGLExtensions size
kDisabledWebGLExtensionsForEntry257,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry257),  // CrBugs size
kCrBugsForWorkaroundsEntry257,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry257_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
265,  // id
"Crash in glQueryCounter() and glBeginQuery() with VMware driver ",
base::size(kFeatureListForWorkaroundsEntry265),  // features size
kFeatureListForWorkaroundsEntry265,  // features
base::size(kDisabledExtensionsForEntry265),  // DisabledExtensions size
kDisabledExtensionsForEntry265,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry265),  // CrBugs size
kCrBugsForWorkaroundsEntry265,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry265,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry265_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
270,  // id
"AMD Linux driver crashes when copyTexImage2D is called with PIXEL_UNPACK_BUFFER set to an uninitialized buffer",
base::size(kFeatureListForWorkaroundsEntry270),  // features size
kFeatureListForWorkaroundsEntry270,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry270),  // CrBugs size
kCrBugsForWorkaroundsEntry270,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x1002,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry270_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
274,  // id
"glTexStorage* are buggy when base mipmap level is not 0",
base::size(kFeatureListForWorkaroundsEntry274),  // features size
kFeatureListForWorkaroundsEntry274,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry274),  // CrBugs size
kCrBugsForWorkaroundsEntry274,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry274,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry274_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
283,  // id
"Some drivers can't recover after OUT_OF_MEM and context lost",
base::size(kFeatureListForWorkaroundsEntry283),  // features size
kFeatureListForWorkaroundsEntry283,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry283),  // CrBugs size
kCrBugsForWorkaroundsEntry283,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry283_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
285,  // id
"Context flush ordering doesn't seem to work on AMD",
base::size(kFeatureListForWorkaroundsEntry285),  // features size
kFeatureListForWorkaroundsEntry285,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry285),  // CrBugs size
kCrBugsForWorkaroundsEntry285,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x1002,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry285_619971032,  // more data
},
base::size(kExceptionsForEntry285),  // exceptions count
kExceptionsForEntry285,  // exceptions
},
{
289,  // id
"Fake entry for testing command buffer init failures on ES 2.0",
base::size(kFeatureListForWorkaroundsEntry289),  // features size
kFeatureListForWorkaroundsEntry289,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry289),  // CrBugs size
kCrBugsForWorkaroundsEntry289,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry289_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
291,  // id
"adjust src/dst region if blitting pixels outside framebuffer on Linux NVIDIA",
base::size(kFeatureListForWorkaroundsEntry291),  // features size
kFeatureListForWorkaroundsEntry291,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry291),  // CrBugs size
kCrBugsForWorkaroundsEntry291,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x10de,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry291_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
295,  // id
"Avoid waiting on a egl fence before swapping buffers and rely on implicit sync on Intel GPUs",
base::size(kFeatureListForWorkaroundsEntry295),  // features size
kFeatureListForWorkaroundsEntry295,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry295),  // CrBugs size
kCrBugsForWorkaroundsEntry295,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry295,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry295_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
296,  // id
"Avoid waiting on a egl fence before swapping buffers and rely on implicit sync on Broadcom GPUs",
base::size(kFeatureListForWorkaroundsEntry296),  // features size
kFeatureListForWorkaroundsEntry296,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry296),  // CrBugs size
kCrBugsForWorkaroundsEntry296,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
&kGLStringsForWorkaroundsEntry296,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry296_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
301,  // id
"Mesa hangs the system when allocating large textures",
base::size(kFeatureListForWorkaroundsEntry301),  // features size
kFeatureListForWorkaroundsEntry301,  // features
0,  // DisabledExtensions size
nullptr,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry301),  // CrBugs size
kCrBugsForWorkaroundsEntry301,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "5.0", nullptr},  // os_version
0x8086,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry301_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
315,  // id
"Disable GL_MESA_framebuffer_flip_y for desktop GL",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry315),  // DisabledExtensions size
kDisabledExtensionsForEntry315,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry315),  // CrBugs size
kCrBugsForWorkaroundsEntry315,  // CrBugs
{
GpuControlList::kOsAny,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x00,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
nullptr,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry315_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
{
331,  // id
"GL and Vulkan interop doesn't work with AMD GPU properly",
0,  // feature size
nullptr,  // features
base::size(kDisabledExtensionsForEntry331),  // DisabledExtensions size
kDisabledExtensionsForEntry331,  // DisabledExtensions
0,  // DisabledWebGLExtensions size
nullptr,  // DisabledWebGLExtensions
base::size(kCrBugsForWorkaroundsEntry331),  // CrBugs size
kCrBugsForWorkaroundsEntry331,  // CrBugs
{
GpuControlList::kOsLinux,  // os_type
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // os_version
0x1002,  // vendor_id
0,  // Devices size
nullptr,  // Devices
GpuControlList::kMultiGpuCategoryNone,  // multi_gpu_category
GpuControlList::kMultiGpuStyleNone,  // multi_gpu_style
&kDriverInfoForWorkaroundsEntry331,  // driver info
nullptr,  // GL strings
nullptr,  // machine model info
0,  // intel_gpu_series size
nullptr,  // intel_gpu_series
{GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr},  // intel_gpu_generation
&kMoreForEntry331_619971032,  // more data
},
0,  // exceptions count
nullptr,  // exceptions
},
};
const size_t kGpuDriverBugListEntryCount = 56;
}  // namespace gpu
