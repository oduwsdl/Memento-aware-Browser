// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/i18n.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_I18N_H__
#define CHROME_COMMON_EXTENSIONS_API_I18N_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace i18n {

//
// Types
//

// An ISO language code such as <code>en</code> or <code>fr</code>. For a
// complete list of languages supported by this method, see <a
// href='http://src.chromium.org/viewvc/chrome/trunk/src/third_party/cld/languages/internal/languages.cc'>kLanguageInfoTable</a>. For an unknown language, <code>und</code> will be returned, which means that [percentage] of the text is unknown to CLD
typedef std::string LanguageCode;


//
// Functions
//

namespace GetAcceptLanguages {

namespace Results {

// Array of LanguageCode
std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& languages);
}  // namespace Results

}  // namespace GetAcceptLanguages

}  // namespace i18n
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_I18N_H__
