// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/keywords.json5


#include "third_party/blink/renderer/core/keywords.h"

#include "base/stl_util.h"  // for base::size()
#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"

namespace blink {
namespace keywords {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void *) - 1) / sizeof(void *))];

const AtomicString& kAnonymous = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kAsync = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kAuto = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kCol = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kColgroup = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kDecimal = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kDone = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kEager = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kEmail = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kEnter = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kFetch = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kFont = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kGo = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kHigh = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kImage = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kInvisible = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kLazy = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kLow = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kManual = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kNext = reinterpret_cast<AtomicString*>(&names_storage)[19];
const AtomicString& kNoReferrer = reinterpret_cast<AtomicString*>(&names_storage)[20];
const AtomicString& kNoReferrerWhenDowngrade = reinterpret_cast<AtomicString*>(&names_storage)[21];
const AtomicString& kNone = reinterpret_cast<AtomicString*>(&names_storage)[22];
const AtomicString& kNumeric = reinterpret_cast<AtomicString*>(&names_storage)[23];
const AtomicString& kOff = reinterpret_cast<AtomicString*>(&names_storage)[24];
const AtomicString& kOn = reinterpret_cast<AtomicString*>(&names_storage)[25];
const AtomicString& kOrigin = reinterpret_cast<AtomicString*>(&names_storage)[26];
const AtomicString& kOriginWhenCrossOrigin = reinterpret_cast<AtomicString*>(&names_storage)[27];
const AtomicString& kPrevious = reinterpret_cast<AtomicString*>(&names_storage)[28];
const AtomicString& kRow = reinterpret_cast<AtomicString*>(&names_storage)[29];
const AtomicString& kRowgroup = reinterpret_cast<AtomicString*>(&names_storage)[30];
const AtomicString& kSameOrigin = reinterpret_cast<AtomicString*>(&names_storage)[31];
const AtomicString& kScript = reinterpret_cast<AtomicString*>(&names_storage)[32];
const AtomicString& kSearch = reinterpret_cast<AtomicString*>(&names_storage)[33];
const AtomicString& kSend = reinterpret_cast<AtomicString*>(&names_storage)[34];
const AtomicString& kStatic = reinterpret_cast<AtomicString*>(&names_storage)[35];
const AtomicString& kStrictOrigin = reinterpret_cast<AtomicString*>(&names_storage)[36];
const AtomicString& kStrictOriginWhenCrossOrigin = reinterpret_cast<AtomicString*>(&names_storage)[37];
const AtomicString& kStyle = reinterpret_cast<AtomicString*>(&names_storage)[38];
const AtomicString& kSync = reinterpret_cast<AtomicString*>(&names_storage)[39];
const AtomicString& kTel = reinterpret_cast<AtomicString*>(&names_storage)[40];
const AtomicString& kText = reinterpret_cast<AtomicString*>(&names_storage)[41];
const AtomicString& kTrack = reinterpret_cast<AtomicString*>(&names_storage)[42];
const AtomicString& kUnsafeUrl = reinterpret_cast<AtomicString*>(&names_storage)[43];
const AtomicString& kUrl = reinterpret_cast<AtomicString*>(&names_storage)[44];
const AtomicString& kUseCredentials = reinterpret_cast<AtomicString*>(&names_storage)[45];

void Init() {
  static bool is_loaded = false;
  if (is_loaded) return;
  is_loaded = true;

  struct NameEntry {
    const char* name;
    unsigned hash;
    unsigned char length;
  };

  static const NameEntry kNames[] = {
    { "anonymous", 4545318, 9 },
    { "async", 2556481, 5 },
    { "auto", 4834735, 4 },
    { "col", 12850806, 3 },
    { "colgroup", 3733719, 8 },
    { "decimal", 15005416, 7 },
    { "done", 11685723, 4 },
    { "eager", 9356754, 5 },
    { "email", 13948917, 5 },
    { "enter", 3509546, 5 },
    { "fetch", 10988466, 5 },
    { "font", 4588695, 4 },
    { "go", 16685295, 2 },
    { "high", 11748844, 4 },
    { "image", 10287573, 5 },
    { "invisible", 2501496, 9 },
    { "lazy", 14911204, 4 },
    { "low", 9523344, 3 },
    { "manual", 13405319, 6 },
    { "next", 13682113, 4 },
    { "no-referrer", 11307242, 11 },
    { "no-referrer-when-downgrade", 13148966, 26 },
    { "none", 3454253, 4 },
    { "numeric", 14288860, 7 },
    { "off", 2568997, 3 },
    { "on", 15191431, 2 },
    { "origin", 2361284, 6 },
    { "origin-when-cross-origin", 3289, 24 },
    { "previous", 8004999, 8 },
    { "row", 4500977, 3 },
    { "rowgroup", 4745876, 8 },
    { "same-origin", 9467849, 11 },
    { "script", 7137273, 6 },
    { "search", 6906057, 6 },
    { "send", 3212636, 4 },
    { "static", 11475552, 6 },
    { "strict-origin", 8241020, 13 },
    { "strict-origin-when-cross-origin", 8451554, 31 },
    { "style", 10993676, 5 },
    { "sync", 14643608, 4 },
    { "tel", 1681717, 3 },
    { "text", 2784654, 4 },
    { "track", 10988706, 5 },
    { "unsafe-url", 4220484, 10 },
    { "url", 10560150, 3 },
    { "use-credentials", 15500527, 15 },
  };

  for (size_t i = 0; i < base::size(kNames); ++i) {
    StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length, kNames[i].hash);
    void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
    new (address) AtomicString(impl);
  }
}

}  // namespace keywords
}  // namespace blink
