// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/font_settings.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_FONT_SETTINGS_H__
#define CHROME_COMMON_EXTENSIONS_API_FONT_SETTINGS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace font_settings {

//
// Types
//

// Represents a font name.
struct FontName {
  FontName();
  ~FontName();
  FontName(FontName&& rhs);
  FontName& operator=(FontName&& rhs);

  // Populates a FontName object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, FontName* out);

  // Creates a FontName object from a base::Value, or NULL on failure.
  static std::unique_ptr<FontName> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FontName object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The font ID.
  std::string font_id;

  // The display name of the font.
  std::string display_name;


 private:
  DISALLOW_COPY_AND_ASSIGN(FontName);
};

// An ISO 15924 script code. The default, or global, script is represented by
// script code "Zyyy".
enum ScriptCode {
  SCRIPT_CODE_NONE,
  SCRIPT_CODE_AFAK,
  SCRIPT_CODE_ARAB,
  SCRIPT_CODE_ARMI,
  SCRIPT_CODE_ARMN,
  SCRIPT_CODE_AVST,
  SCRIPT_CODE_BALI,
  SCRIPT_CODE_BAMU,
  SCRIPT_CODE_BASS,
  SCRIPT_CODE_BATK,
  SCRIPT_CODE_BENG,
  SCRIPT_CODE_BLIS,
  SCRIPT_CODE_BOPO,
  SCRIPT_CODE_BRAH,
  SCRIPT_CODE_BRAI,
  SCRIPT_CODE_BUGI,
  SCRIPT_CODE_BUHD,
  SCRIPT_CODE_CAKM,
  SCRIPT_CODE_CANS,
  SCRIPT_CODE_CARI,
  SCRIPT_CODE_CHAM,
  SCRIPT_CODE_CHER,
  SCRIPT_CODE_CIRT,
  SCRIPT_CODE_COPT,
  SCRIPT_CODE_CPRT,
  SCRIPT_CODE_CYRL,
  SCRIPT_CODE_CYRS,
  SCRIPT_CODE_DEVA,
  SCRIPT_CODE_DSRT,
  SCRIPT_CODE_DUPL,
  SCRIPT_CODE_EGYD,
  SCRIPT_CODE_EGYH,
  SCRIPT_CODE_EGYP,
  SCRIPT_CODE_ELBA,
  SCRIPT_CODE_ETHI,
  SCRIPT_CODE_GEOR,
  SCRIPT_CODE_GEOK,
  SCRIPT_CODE_GLAG,
  SCRIPT_CODE_GOTH,
  SCRIPT_CODE_GRAN,
  SCRIPT_CODE_GREK,
  SCRIPT_CODE_GUJR,
  SCRIPT_CODE_GURU,
  SCRIPT_CODE_HANG,
  SCRIPT_CODE_HANI,
  SCRIPT_CODE_HANO,
  SCRIPT_CODE_HANS,
  SCRIPT_CODE_HANT,
  SCRIPT_CODE_HEBR,
  SCRIPT_CODE_HLUW,
  SCRIPT_CODE_HMNG,
  SCRIPT_CODE_HUNG,
  SCRIPT_CODE_INDS,
  SCRIPT_CODE_ITAL,
  SCRIPT_CODE_JAVA,
  SCRIPT_CODE_JPAN,
  SCRIPT_CODE_JURC,
  SCRIPT_CODE_KALI,
  SCRIPT_CODE_KHAR,
  SCRIPT_CODE_KHMR,
  SCRIPT_CODE_KHOJ,
  SCRIPT_CODE_KNDA,
  SCRIPT_CODE_KPEL,
  SCRIPT_CODE_KTHI,
  SCRIPT_CODE_LANA,
  SCRIPT_CODE_LAOO,
  SCRIPT_CODE_LATF,
  SCRIPT_CODE_LATG,
  SCRIPT_CODE_LATN,
  SCRIPT_CODE_LEPC,
  SCRIPT_CODE_LIMB,
  SCRIPT_CODE_LINA,
  SCRIPT_CODE_LINB,
  SCRIPT_CODE_LISU,
  SCRIPT_CODE_LOMA,
  SCRIPT_CODE_LYCI,
  SCRIPT_CODE_LYDI,
  SCRIPT_CODE_MAND,
  SCRIPT_CODE_MANI,
  SCRIPT_CODE_MAYA,
  SCRIPT_CODE_MEND,
  SCRIPT_CODE_MERC,
  SCRIPT_CODE_MERO,
  SCRIPT_CODE_MLYM,
  SCRIPT_CODE_MOON,
  SCRIPT_CODE_MONG,
  SCRIPT_CODE_MROO,
  SCRIPT_CODE_MTEI,
  SCRIPT_CODE_MYMR,
  SCRIPT_CODE_NARB,
  SCRIPT_CODE_NBAT,
  SCRIPT_CODE_NKGB,
  SCRIPT_CODE_NKOO,
  SCRIPT_CODE_NSHU,
  SCRIPT_CODE_OGAM,
  SCRIPT_CODE_OLCK,
  SCRIPT_CODE_ORKH,
  SCRIPT_CODE_ORYA,
  SCRIPT_CODE_OSMA,
  SCRIPT_CODE_PALM,
  SCRIPT_CODE_PERM,
  SCRIPT_CODE_PHAG,
  SCRIPT_CODE_PHLI,
  SCRIPT_CODE_PHLP,
  SCRIPT_CODE_PHLV,
  SCRIPT_CODE_PHNX,
  SCRIPT_CODE_PLRD,
  SCRIPT_CODE_PRTI,
  SCRIPT_CODE_RJNG,
  SCRIPT_CODE_RORO,
  SCRIPT_CODE_RUNR,
  SCRIPT_CODE_SAMR,
  SCRIPT_CODE_SARA,
  SCRIPT_CODE_SARB,
  SCRIPT_CODE_SAUR,
  SCRIPT_CODE_SGNW,
  SCRIPT_CODE_SHAW,
  SCRIPT_CODE_SHRD,
  SCRIPT_CODE_SIND,
  SCRIPT_CODE_SINH,
  SCRIPT_CODE_SORA,
  SCRIPT_CODE_SUND,
  SCRIPT_CODE_SYLO,
  SCRIPT_CODE_SYRC,
  SCRIPT_CODE_SYRE,
  SCRIPT_CODE_SYRJ,
  SCRIPT_CODE_SYRN,
  SCRIPT_CODE_TAGB,
  SCRIPT_CODE_TAKR,
  SCRIPT_CODE_TALE,
  SCRIPT_CODE_TALU,
  SCRIPT_CODE_TAML,
  SCRIPT_CODE_TANG,
  SCRIPT_CODE_TAVT,
  SCRIPT_CODE_TELU,
  SCRIPT_CODE_TENG,
  SCRIPT_CODE_TFNG,
  SCRIPT_CODE_TGLG,
  SCRIPT_CODE_THAA,
  SCRIPT_CODE_THAI,
  SCRIPT_CODE_TIBT,
  SCRIPT_CODE_TIRH,
  SCRIPT_CODE_UGAR,
  SCRIPT_CODE_VAII,
  SCRIPT_CODE_VISP,
  SCRIPT_CODE_WARA,
  SCRIPT_CODE_WOLE,
  SCRIPT_CODE_XPEO,
  SCRIPT_CODE_XSUX,
  SCRIPT_CODE_YIII,
  SCRIPT_CODE_ZMTH,
  SCRIPT_CODE_ZSYM,
  SCRIPT_CODE_ZYYY,
  SCRIPT_CODE_LAST = SCRIPT_CODE_ZYYY,
};


const char* ToString(ScriptCode as_enum);
ScriptCode ParseScriptCode(const std::string& as_string);

// A CSS generic font family.
enum GenericFamily {
  GENERIC_FAMILY_NONE,
  GENERIC_FAMILY_STANDARD,
  GENERIC_FAMILY_SANSSERIF,
  GENERIC_FAMILY_SERIF,
  GENERIC_FAMILY_FIXED,
  GENERIC_FAMILY_CURSIVE,
  GENERIC_FAMILY_FANTASY,
  GENERIC_FAMILY_LAST = GENERIC_FAMILY_FANTASY,
};


const char* ToString(GenericFamily as_enum);
GenericFamily ParseGenericFamily(const std::string& as_string);

// One of<br><var>not_controllable</var>: cannot be controlled by any
// extension<br><var>controlled_by_other_extensions</var>: controlled by
// extensions with higher
// precedence<br><var>controllable_by_this_extension</var>: can be controlled by
// this extension<br><var>controlled_by_this_extension</var>: controlled by this
// extension
enum LevelOfControl {
  LEVEL_OF_CONTROL_NONE,
  LEVEL_OF_CONTROL_NOT_CONTROLLABLE,
  LEVEL_OF_CONTROL_CONTROLLED_BY_OTHER_EXTENSIONS,
  LEVEL_OF_CONTROL_CONTROLLABLE_BY_THIS_EXTENSION,
  LEVEL_OF_CONTROL_CONTROLLED_BY_THIS_EXTENSION,
  LEVEL_OF_CONTROL_LAST = LEVEL_OF_CONTROL_CONTROLLED_BY_THIS_EXTENSION,
};


const char* ToString(LevelOfControl as_enum);
LevelOfControl ParseLevelOfControl(const std::string& as_string);


//
// Functions
//

namespace ClearFont {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The script for which the font should be cleared. If omitted, the global
    // script font setting is cleared.
    ScriptCode script;

    // The generic font family for which the font should be cleared.
    GenericFamily generic_family;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ClearFont

namespace GetFont {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The script for which the font should be retrieved. If omitted, the font
    // setting for the global script (script code "Zyyy") is retrieved.
    ScriptCode script;

    // The generic font family for which the font should be retrieved.
    GenericFamily generic_family;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The font ID. Rather than the literal font ID preference value, this may be
  // the ID of the font that the system resolves the preference value to. So,
  // <var>fontId</var> can differ from the font passed to <code>setFont</code>,
  // if, for example, the font is not available on the system. The empty string
  // signifies fallback to the global script font setting.
  std::string font_id;

  // The level of control this extension has over the setting.
  LevelOfControl level_of_control;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace Results

}  // namespace GetFont

namespace SetFont {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The script code which the font should be set. If omitted, the font setting
    // for the global script (script code "Zyyy") is set.
    ScriptCode script;

    // The generic font family for which the font should be set.
    GenericFamily generic_family;

    // The font ID. The empty string means to fallback to the global script font
    // setting.
    std::string font_id;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetFont

namespace GetFontList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<FontName>& results);
}  // namespace Results

}  // namespace GetFontList

namespace ClearDefaultFontSize {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // This parameter is currently unused.
  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  // This parameter is currently unused.
  std::unique_ptr<Details> details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ClearDefaultFontSize

namespace GetDefaultFontSize {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // This parameter is currently unused.
  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  // This parameter is currently unused.
  std::unique_ptr<Details> details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The font size in pixels.
  int pixel_size;

  // The level of control this extension has over the setting.
  LevelOfControl level_of_control;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace Results

}  // namespace GetDefaultFontSize

namespace SetDefaultFontSize {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The font size in pixels.
    int pixel_size;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetDefaultFontSize

namespace ClearDefaultFixedFontSize {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // This parameter is currently unused.
  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  // This parameter is currently unused.
  std::unique_ptr<Details> details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ClearDefaultFixedFontSize

namespace GetDefaultFixedFontSize {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // This parameter is currently unused.
  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  // This parameter is currently unused.
  std::unique_ptr<Details> details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The font size in pixels.
  int pixel_size;

  // The level of control this extension has over the setting.
  LevelOfControl level_of_control;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace Results

}  // namespace GetDefaultFixedFontSize

namespace SetDefaultFixedFontSize {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The font size in pixels.
    int pixel_size;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetDefaultFixedFontSize

namespace ClearMinimumFontSize {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // This parameter is currently unused.
  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  // This parameter is currently unused.
  std::unique_ptr<Details> details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ClearMinimumFontSize

namespace GetMinimumFontSize {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // This parameter is currently unused.
  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  // This parameter is currently unused.
  std::unique_ptr<Details> details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The font size in pixels.
  int pixel_size;

  // The level of control this extension has over the setting.
  LevelOfControl level_of_control;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace Results

}  // namespace GetMinimumFontSize

namespace SetMinimumFontSize {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The font size in pixels.
    int pixel_size;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetMinimumFontSize

//
// Events
//

namespace OnFontChanged {

extern const char kEventName[];  // "fontSettings.onFontChanged"

struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The font ID. See the description in <code>getFont</code>.
  std::string font_id;

  // The script code for which the font setting has changed.
  ScriptCode script;

  // The generic font family for which the font setting has changed.
  GenericFamily generic_family;

  // The level of control this extension has over the setting.
  LevelOfControl level_of_control;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace OnFontChanged

namespace OnDefaultFontSizeChanged {

extern const char kEventName[];  // "fontSettings.onDefaultFontSizeChanged"

struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The font size in pixels.
  int pixel_size;

  // The level of control this extension has over the setting.
  LevelOfControl level_of_control;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace OnDefaultFontSizeChanged

namespace OnDefaultFixedFontSizeChanged {

extern const char kEventName[];  // "fontSettings.onDefaultFixedFontSizeChanged"

struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The font size in pixels.
  int pixel_size;

  // The level of control this extension has over the setting.
  LevelOfControl level_of_control;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace OnDefaultFixedFontSizeChanged

namespace OnMinimumFontSizeChanged {

extern const char kEventName[];  // "fontSettings.onMinimumFontSizeChanged"

struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The font size in pixels.
  int pixel_size;

  // The level of control this extension has over the setting.
  LevelOfControl level_of_control;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace OnMinimumFontSizeChanged

}  // namespace font_settings
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_FONT_SETTINGS_H__
