// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/virtual_keyboard.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/virtual_keyboard.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace virtual_keyboard {
//
// Types
//

FeatureRestrictions::FeatureRestrictions()
 {}

FeatureRestrictions::~FeatureRestrictions() {}
FeatureRestrictions::FeatureRestrictions(FeatureRestrictions&& rhs)
: auto_complete_enabled(std::move(rhs.auto_complete_enabled)),
auto_correct_enabled(std::move(rhs.auto_correct_enabled)),
handwriting_enabled(std::move(rhs.handwriting_enabled)),
spell_check_enabled(std::move(rhs.spell_check_enabled)),
voice_input_enabled(std::move(rhs.voice_input_enabled)){
}

FeatureRestrictions& FeatureRestrictions::operator=(FeatureRestrictions&& rhs)
{
auto_complete_enabled = std::move(rhs.auto_complete_enabled);
auto_correct_enabled = std::move(rhs.auto_correct_enabled);
handwriting_enabled = std::move(rhs.handwriting_enabled);
spell_check_enabled = std::move(rhs.spell_check_enabled);
voice_input_enabled = std::move(rhs.voice_input_enabled);
return *this;
}

// static
bool FeatureRestrictions::Populate(
    const base::Value& value, FeatureRestrictions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* auto_complete_enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("autoCompleteEnabled", &auto_complete_enabled_value)) {
    {
      bool temp;
      if (!auto_complete_enabled_value->GetAsBoolean(&temp)) {
        out->auto_complete_enabled.reset();
        return false;
      }
      else
        out->auto_complete_enabled.reset(new bool(temp));
    }
  }

  const base::Value* auto_correct_enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("autoCorrectEnabled", &auto_correct_enabled_value)) {
    {
      bool temp;
      if (!auto_correct_enabled_value->GetAsBoolean(&temp)) {
        out->auto_correct_enabled.reset();
        return false;
      }
      else
        out->auto_correct_enabled.reset(new bool(temp));
    }
  }

  const base::Value* handwriting_enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("handwritingEnabled", &handwriting_enabled_value)) {
    {
      bool temp;
      if (!handwriting_enabled_value->GetAsBoolean(&temp)) {
        out->handwriting_enabled.reset();
        return false;
      }
      else
        out->handwriting_enabled.reset(new bool(temp));
    }
  }

  const base::Value* spell_check_enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("spellCheckEnabled", &spell_check_enabled_value)) {
    {
      bool temp;
      if (!spell_check_enabled_value->GetAsBoolean(&temp)) {
        out->spell_check_enabled.reset();
        return false;
      }
      else
        out->spell_check_enabled.reset(new bool(temp));
    }
  }

  const base::Value* voice_input_enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("voiceInputEnabled", &voice_input_enabled_value)) {
    {
      bool temp;
      if (!voice_input_enabled_value->GetAsBoolean(&temp)) {
        out->voice_input_enabled.reset();
        return false;
      }
      else
        out->voice_input_enabled.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<FeatureRestrictions> FeatureRestrictions::FromValue(const base::Value& value) {
  std::unique_ptr<FeatureRestrictions> out(new FeatureRestrictions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> FeatureRestrictions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->auto_complete_enabled.get()) {
    to_value_result->SetWithoutPathExpansion("autoCompleteEnabled", std::make_unique<base::Value>(*this->auto_complete_enabled));

  }
  if (this->auto_correct_enabled.get()) {
    to_value_result->SetWithoutPathExpansion("autoCorrectEnabled", std::make_unique<base::Value>(*this->auto_correct_enabled));

  }
  if (this->handwriting_enabled.get()) {
    to_value_result->SetWithoutPathExpansion("handwritingEnabled", std::make_unique<base::Value>(*this->handwriting_enabled));

  }
  if (this->spell_check_enabled.get()) {
    to_value_result->SetWithoutPathExpansion("spellCheckEnabled", std::make_unique<base::Value>(*this->spell_check_enabled));

  }
  if (this->voice_input_enabled.get()) {
    to_value_result->SetWithoutPathExpansion("voiceInputEnabled", std::make_unique<base::Value>(*this->voice_input_enabled));

  }

  return to_value_result;
}



//
// Functions
//

namespace RestrictFeatures {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* restrictions_value = NULL;
  if (args.Get(0, &restrictions_value) &&
      !restrictions_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!restrictions_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!FeatureRestrictions::Populate(*dictionary, &params->restrictions)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const FeatureRestrictions& update) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((update).ToValue());

  return create_results;
}
}  // namespace RestrictFeatures

}  // namespace virtual_keyboard
}  // namespace api
}  // namespace extensions

