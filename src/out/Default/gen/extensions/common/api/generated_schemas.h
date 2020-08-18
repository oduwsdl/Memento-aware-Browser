// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITIONS IN
//   extensions/common/api
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_GENERATED_SCHEMAS_H__
#define EXTENSIONS_COMMON_API_GENERATED_SCHEMAS_H__

#include "base/strings/string_piece.h"

namespace extensions {
namespace api {

class GeneratedSchemas {
 public:
  // Determines if schema named |name| is generated.
  static bool IsGenerated(base::StringPiece name);

  // Gets the API schema named |name|.
  static base::StringPiece Get(base::StringPiece name);
};

}  // namespace api
}  // namespace extensions

#endif  // EXTENSIONS_COMMON_API_GENERATED_SCHEMAS_H__
