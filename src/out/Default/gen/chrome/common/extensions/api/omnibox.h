// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/omnibox.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_OMNIBOX_H__
#define CHROME_COMMON_EXTENSIONS_API_OMNIBOX_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace omnibox {

//
// Types
//

// The style type.
enum DescriptionStyleType {
  DESCRIPTION_STYLE_TYPE_NONE,
  DESCRIPTION_STYLE_TYPE_URL,
  DESCRIPTION_STYLE_TYPE_MATCH,
  DESCRIPTION_STYLE_TYPE_DIM,
  DESCRIPTION_STYLE_TYPE_LAST = DESCRIPTION_STYLE_TYPE_DIM,
};


const char* ToString(DescriptionStyleType as_enum);
DescriptionStyleType ParseDescriptionStyleType(const std::string& as_string);

// The window disposition for the omnibox query. This is the recommended context
// to display results. For example, if the omnibox command is to navigate to a
// certain URL, a disposition of 'newForegroundTab' means the navigation should
// take place in a new selected tab.
enum OnInputEnteredDisposition {
  ON_INPUT_ENTERED_DISPOSITION_NONE,
  ON_INPUT_ENTERED_DISPOSITION_CURRENTTAB,
  ON_INPUT_ENTERED_DISPOSITION_NEWFOREGROUNDTAB,
  ON_INPUT_ENTERED_DISPOSITION_NEWBACKGROUNDTAB,
  ON_INPUT_ENTERED_DISPOSITION_LAST = ON_INPUT_ENTERED_DISPOSITION_NEWBACKGROUNDTAB,
};


const char* ToString(OnInputEnteredDisposition as_enum);
OnInputEnteredDisposition ParseOnInputEnteredDisposition(const std::string& as_string);

// A suggest result.
struct SuggestResult {
  SuggestResult();
  ~SuggestResult();
  SuggestResult(SuggestResult&& rhs);
  SuggestResult& operator=(SuggestResult&& rhs);

  // Populates a SuggestResult object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, SuggestResult* out);

  // Creates a SuggestResult object from a base::Value, or NULL on failure.
  static std::unique_ptr<SuggestResult> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SuggestResult object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The style ranges for the description, as provided by the extension.
  struct DescriptionStylesType {
    DescriptionStylesType();
    ~DescriptionStylesType();
    DescriptionStylesType(DescriptionStylesType&& rhs);
    DescriptionStylesType& operator=(DescriptionStylesType&& rhs);

    // Populates a DescriptionStylesType object from a base::Value. Returns
    // whether |out| was successfully populated.
    static bool Populate(const base::Value& value, DescriptionStylesType* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this DescriptionStylesType object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    int offset;

    // The style type
    DescriptionStyleType type;

    std::unique_ptr<int> length;


   private:
    DISALLOW_COPY_AND_ASSIGN(DescriptionStylesType);
  };


  // The style ranges for the description, as provided by ToValue().
  struct DescriptionStylesRawType {
    DescriptionStylesRawType();
    ~DescriptionStylesRawType();
    DescriptionStylesRawType(DescriptionStylesRawType&& rhs);
    DescriptionStylesRawType& operator=(DescriptionStylesRawType&& rhs);

    // Populates a DescriptionStylesRawType object from a base::Value. Returns
    // whether |out| was successfully populated.
    static bool Populate(const base::Value& value, DescriptionStylesRawType* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this DescriptionStylesRawType object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    int offset;

    int type;


   private:
    DISALLOW_COPY_AND_ASSIGN(DescriptionStylesRawType);
  };



  // The text that is put into the URL bar, and that is sent to the extension when
  // the user chooses this entry.
  std::string content;

  // The text that is displayed in the URL dropdown. Can contain XML-style markup
  // for styling. The supported tags are 'url' (for a literal URL), 'match' (for
  // highlighting text that matched what the user's query), and 'dim' (for dim
  // helper text). The styles can be nested, eg. <dim><match>dimmed
  // match</match></dim>. You must escape the five predefined entities to display
  // them as text: stackoverflow.com/a/1091953/89484
  std::string description;

  // Whether the suggest result can be deleted by the user.
  std::unique_ptr<bool> deletable;

  // An array of style ranges for the description, as provided by the extension.
  std::unique_ptr<std::vector<DescriptionStylesType>> description_styles;

  // An array of style ranges for the description, as provided by ToValue().
  std::unique_ptr<std::vector<DescriptionStylesRawType>> description_styles_raw;


 private:
  DISALLOW_COPY_AND_ASSIGN(SuggestResult);
};

// A suggest result.
struct DefaultSuggestResult {
  DefaultSuggestResult();
  ~DefaultSuggestResult();
  DefaultSuggestResult(DefaultSuggestResult&& rhs);
  DefaultSuggestResult& operator=(DefaultSuggestResult&& rhs);

  // Populates a DefaultSuggestResult object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, DefaultSuggestResult* out);

  // Creates a DefaultSuggestResult object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<DefaultSuggestResult> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DefaultSuggestResult object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The style ranges for the description, as provided by the extension.
  struct DescriptionStylesType {
    DescriptionStylesType();
    ~DescriptionStylesType();
    DescriptionStylesType(DescriptionStylesType&& rhs);
    DescriptionStylesType& operator=(DescriptionStylesType&& rhs);

    // Populates a DescriptionStylesType object from a base::Value. Returns
    // whether |out| was successfully populated.
    static bool Populate(const base::Value& value, DescriptionStylesType* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this DescriptionStylesType object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    int offset;

    // The style type
    DescriptionStyleType type;

    std::unique_ptr<int> length;


   private:
    DISALLOW_COPY_AND_ASSIGN(DescriptionStylesType);
  };


  // The style ranges for the description, as provided by ToValue().
  struct DescriptionStylesRawType {
    DescriptionStylesRawType();
    ~DescriptionStylesRawType();
    DescriptionStylesRawType(DescriptionStylesRawType&& rhs);
    DescriptionStylesRawType& operator=(DescriptionStylesRawType&& rhs);

    // Populates a DescriptionStylesRawType object from a base::Value. Returns
    // whether |out| was successfully populated.
    static bool Populate(const base::Value& value, DescriptionStylesRawType* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this DescriptionStylesRawType object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    int offset;

    int type;


   private:
    DISALLOW_COPY_AND_ASSIGN(DescriptionStylesRawType);
  };



  // The text that is displayed in the URL dropdown. Can contain XML-style markup
  // for styling. The supported tags are 'url' (for a literal URL), 'match' (for
  // highlighting text that matched what the user's query), and 'dim' (for dim
  // helper text). The styles can be nested, eg. <dim><match>dimmed
  // match</match></dim>.
  std::string description;

  // An array of style ranges for the description, as provided by the extension.
  std::unique_ptr<std::vector<DescriptionStylesType>> description_styles;

  // An array of style ranges for the description, as provided by ToValue().
  std::unique_ptr<std::vector<DescriptionStylesRawType>> description_styles_raw;


 private:
  DISALLOW_COPY_AND_ASSIGN(DefaultSuggestResult);
};


//
// Functions
//

namespace SendSuggestions {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int request_id;

  // An array of suggest results
  std::vector<SuggestResult> suggest_results;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SendSuggestions

namespace SetDefaultSuggestion {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // A partial SuggestResult object, without the 'content' parameter.
  DefaultSuggestResult suggestion;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetDefaultSuggestion

//
// Events
//

namespace OnInputStarted {

extern const char kEventName[];  // "omnibox.onInputStarted"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnInputStarted

namespace OnInputChanged {

extern const char kEventName[];  // "omnibox.onInputChanged"

std::unique_ptr<base::ListValue> Create(const std::string& text);
}  // namespace OnInputChanged

namespace OnInputEntered {

extern const char kEventName[];  // "omnibox.onInputEntered"

std::unique_ptr<base::ListValue> Create(const std::string& text, const OnInputEnteredDisposition& disposition);
}  // namespace OnInputEntered

namespace OnInputCancelled {

extern const char kEventName[];  // "omnibox.onInputCancelled"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnInputCancelled

namespace OnDeleteSuggestion {

extern const char kEventName[];  // "omnibox.onDeleteSuggestion"

// Text of the deleted suggestion.
std::unique_ptr<base::ListValue> Create(const std::string& text);
}  // namespace OnDeleteSuggestion

}  // namespace omnibox
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_OMNIBOX_H__
