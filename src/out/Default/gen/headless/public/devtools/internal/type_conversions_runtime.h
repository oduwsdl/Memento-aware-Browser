// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_RUNTIME_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_RUNTIME_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {





template <>
struct FromValue<runtime::RemoteObject> {
  static std::unique_ptr<runtime::RemoteObject> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::RemoteObject::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::RemoteObject& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::CustomPreview> {
  static std::unique_ptr<runtime::CustomPreview> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::CustomPreview::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::CustomPreview& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::ObjectPreview> {
  static std::unique_ptr<runtime::ObjectPreview> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ObjectPreview::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ObjectPreview& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::PropertyPreview> {
  static std::unique_ptr<runtime::PropertyPreview> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::PropertyPreview::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::PropertyPreview& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::EntryPreview> {
  static std::unique_ptr<runtime::EntryPreview> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::EntryPreview::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::EntryPreview& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::PropertyDescriptor> {
  static std::unique_ptr<runtime::PropertyDescriptor> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::PropertyDescriptor::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::PropertyDescriptor& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::InternalPropertyDescriptor> {
  static std::unique_ptr<runtime::InternalPropertyDescriptor> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::InternalPropertyDescriptor::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::InternalPropertyDescriptor& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::PrivatePropertyDescriptor> {
  static std::unique_ptr<runtime::PrivatePropertyDescriptor> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::PrivatePropertyDescriptor::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::PrivatePropertyDescriptor& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::CallArgument> {
  static std::unique_ptr<runtime::CallArgument> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::CallArgument::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::CallArgument& value) {
  return value.Serialize();
}



template <>
struct FromValue<runtime::ExecutionContextDescription> {
  static std::unique_ptr<runtime::ExecutionContextDescription> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ExecutionContextDescription::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ExecutionContextDescription& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::ExceptionDetails> {
  static std::unique_ptr<runtime::ExceptionDetails> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ExceptionDetails::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ExceptionDetails& value) {
  return value.Serialize();
}




template <>
struct FromValue<runtime::CallFrame> {
  static std::unique_ptr<runtime::CallFrame> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::CallFrame::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::CallFrame& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::StackTrace> {
  static std::unique_ptr<runtime::StackTrace> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::StackTrace::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::StackTrace& value) {
  return value.Serialize();
}



template <>
struct FromValue<runtime::StackTraceId> {
  static std::unique_ptr<runtime::StackTraceId> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::StackTraceId::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::StackTraceId& value) {
  return value.Serialize();
}

template <>
struct FromValue<runtime::RemoteObjectType> {
  static runtime::RemoteObjectType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return runtime::RemoteObjectType::OBJECT;
    }
    if (value.GetString() == "object")
      return runtime::RemoteObjectType::OBJECT;
    if (value.GetString() == "function")
      return runtime::RemoteObjectType::FUNCTION;
    if (value.GetString() == "undefined")
      return runtime::RemoteObjectType::UNDEFINED;
    if (value.GetString() == "string")
      return runtime::RemoteObjectType::STRING;
    if (value.GetString() == "number")
      return runtime::RemoteObjectType::NUMBER;
    if (value.GetString() == "boolean")
      return runtime::RemoteObjectType::BOOLEAN;
    if (value.GetString() == "symbol")
      return runtime::RemoteObjectType::SYMBOL;
    if (value.GetString() == "bigint")
      return runtime::RemoteObjectType::BIGINT;
    if (value.GetString() == "wasm")
      return runtime::RemoteObjectType::WASM;
    errors->AddError("invalid enum value");
    return runtime::RemoteObjectType::OBJECT;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::RemoteObjectType& value) {
  switch (value) {
    case runtime::RemoteObjectType::OBJECT:
      return std::make_unique<base::Value>("object");
    case runtime::RemoteObjectType::FUNCTION:
      return std::make_unique<base::Value>("function");
    case runtime::RemoteObjectType::UNDEFINED:
      return std::make_unique<base::Value>("undefined");
    case runtime::RemoteObjectType::STRING:
      return std::make_unique<base::Value>("string");
    case runtime::RemoteObjectType::NUMBER:
      return std::make_unique<base::Value>("number");
    case runtime::RemoteObjectType::BOOLEAN:
      return std::make_unique<base::Value>("boolean");
    case runtime::RemoteObjectType::SYMBOL:
      return std::make_unique<base::Value>("symbol");
    case runtime::RemoteObjectType::BIGINT:
      return std::make_unique<base::Value>("bigint");
    case runtime::RemoteObjectType::WASM:
      return std::make_unique<base::Value>("wasm");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<runtime::RemoteObjectSubtype> {
  static runtime::RemoteObjectSubtype Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return runtime::RemoteObjectSubtype::ARRAY;
    }
    if (value.GetString() == "array")
      return runtime::RemoteObjectSubtype::ARRAY;
    if (value.GetString() == "null")
      return runtime::RemoteObjectSubtype::NONE;
    if (value.GetString() == "node")
      return runtime::RemoteObjectSubtype::NODE;
    if (value.GetString() == "regexp")
      return runtime::RemoteObjectSubtype::REGEXP;
    if (value.GetString() == "date")
      return runtime::RemoteObjectSubtype::DATE;
    if (value.GetString() == "map")
      return runtime::RemoteObjectSubtype::MAP;
    if (value.GetString() == "set")
      return runtime::RemoteObjectSubtype::SET;
    if (value.GetString() == "weakmap")
      return runtime::RemoteObjectSubtype::WEAKMAP;
    if (value.GetString() == "weakset")
      return runtime::RemoteObjectSubtype::WEAKSET;
    if (value.GetString() == "iterator")
      return runtime::RemoteObjectSubtype::ITERATOR;
    if (value.GetString() == "generator")
      return runtime::RemoteObjectSubtype::GENERATOR;
    if (value.GetString() == "error")
      return runtime::RemoteObjectSubtype::ERR;
    if (value.GetString() == "proxy")
      return runtime::RemoteObjectSubtype::PROXY;
    if (value.GetString() == "promise")
      return runtime::RemoteObjectSubtype::PROMISE;
    if (value.GetString() == "typedarray")
      return runtime::RemoteObjectSubtype::TYPEDARRAY;
    if (value.GetString() == "arraybuffer")
      return runtime::RemoteObjectSubtype::ARRAYBUFFER;
    if (value.GetString() == "dataview")
      return runtime::RemoteObjectSubtype::DATAVIEW;
    if (value.GetString() == "i32")
      return runtime::RemoteObjectSubtype::I32;
    if (value.GetString() == "i64")
      return runtime::RemoteObjectSubtype::I64;
    if (value.GetString() == "f32")
      return runtime::RemoteObjectSubtype::F32;
    if (value.GetString() == "f64")
      return runtime::RemoteObjectSubtype::F64;
    if (value.GetString() == "v128")
      return runtime::RemoteObjectSubtype::V128;
    if (value.GetString() == "externref")
      return runtime::RemoteObjectSubtype::EXTERNREF;
    errors->AddError("invalid enum value");
    return runtime::RemoteObjectSubtype::ARRAY;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::RemoteObjectSubtype& value) {
  switch (value) {
    case runtime::RemoteObjectSubtype::ARRAY:
      return std::make_unique<base::Value>("array");
    case runtime::RemoteObjectSubtype::NONE:
      return std::make_unique<base::Value>("null");
    case runtime::RemoteObjectSubtype::NODE:
      return std::make_unique<base::Value>("node");
    case runtime::RemoteObjectSubtype::REGEXP:
      return std::make_unique<base::Value>("regexp");
    case runtime::RemoteObjectSubtype::DATE:
      return std::make_unique<base::Value>("date");
    case runtime::RemoteObjectSubtype::MAP:
      return std::make_unique<base::Value>("map");
    case runtime::RemoteObjectSubtype::SET:
      return std::make_unique<base::Value>("set");
    case runtime::RemoteObjectSubtype::WEAKMAP:
      return std::make_unique<base::Value>("weakmap");
    case runtime::RemoteObjectSubtype::WEAKSET:
      return std::make_unique<base::Value>("weakset");
    case runtime::RemoteObjectSubtype::ITERATOR:
      return std::make_unique<base::Value>("iterator");
    case runtime::RemoteObjectSubtype::GENERATOR:
      return std::make_unique<base::Value>("generator");
    case runtime::RemoteObjectSubtype::ERR:
      return std::make_unique<base::Value>("error");
    case runtime::RemoteObjectSubtype::PROXY:
      return std::make_unique<base::Value>("proxy");
    case runtime::RemoteObjectSubtype::PROMISE:
      return std::make_unique<base::Value>("promise");
    case runtime::RemoteObjectSubtype::TYPEDARRAY:
      return std::make_unique<base::Value>("typedarray");
    case runtime::RemoteObjectSubtype::ARRAYBUFFER:
      return std::make_unique<base::Value>("arraybuffer");
    case runtime::RemoteObjectSubtype::DATAVIEW:
      return std::make_unique<base::Value>("dataview");
    case runtime::RemoteObjectSubtype::I32:
      return std::make_unique<base::Value>("i32");
    case runtime::RemoteObjectSubtype::I64:
      return std::make_unique<base::Value>("i64");
    case runtime::RemoteObjectSubtype::F32:
      return std::make_unique<base::Value>("f32");
    case runtime::RemoteObjectSubtype::F64:
      return std::make_unique<base::Value>("f64");
    case runtime::RemoteObjectSubtype::V128:
      return std::make_unique<base::Value>("v128");
    case runtime::RemoteObjectSubtype::EXTERNREF:
      return std::make_unique<base::Value>("externref");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<runtime::ObjectPreviewType> {
  static runtime::ObjectPreviewType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return runtime::ObjectPreviewType::OBJECT;
    }
    if (value.GetString() == "object")
      return runtime::ObjectPreviewType::OBJECT;
    if (value.GetString() == "function")
      return runtime::ObjectPreviewType::FUNCTION;
    if (value.GetString() == "undefined")
      return runtime::ObjectPreviewType::UNDEFINED;
    if (value.GetString() == "string")
      return runtime::ObjectPreviewType::STRING;
    if (value.GetString() == "number")
      return runtime::ObjectPreviewType::NUMBER;
    if (value.GetString() == "boolean")
      return runtime::ObjectPreviewType::BOOLEAN;
    if (value.GetString() == "symbol")
      return runtime::ObjectPreviewType::SYMBOL;
    if (value.GetString() == "bigint")
      return runtime::ObjectPreviewType::BIGINT;
    errors->AddError("invalid enum value");
    return runtime::ObjectPreviewType::OBJECT;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ObjectPreviewType& value) {
  switch (value) {
    case runtime::ObjectPreviewType::OBJECT:
      return std::make_unique<base::Value>("object");
    case runtime::ObjectPreviewType::FUNCTION:
      return std::make_unique<base::Value>("function");
    case runtime::ObjectPreviewType::UNDEFINED:
      return std::make_unique<base::Value>("undefined");
    case runtime::ObjectPreviewType::STRING:
      return std::make_unique<base::Value>("string");
    case runtime::ObjectPreviewType::NUMBER:
      return std::make_unique<base::Value>("number");
    case runtime::ObjectPreviewType::BOOLEAN:
      return std::make_unique<base::Value>("boolean");
    case runtime::ObjectPreviewType::SYMBOL:
      return std::make_unique<base::Value>("symbol");
    case runtime::ObjectPreviewType::BIGINT:
      return std::make_unique<base::Value>("bigint");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<runtime::ObjectPreviewSubtype> {
  static runtime::ObjectPreviewSubtype Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return runtime::ObjectPreviewSubtype::ARRAY;
    }
    if (value.GetString() == "array")
      return runtime::ObjectPreviewSubtype::ARRAY;
    if (value.GetString() == "null")
      return runtime::ObjectPreviewSubtype::NONE;
    if (value.GetString() == "node")
      return runtime::ObjectPreviewSubtype::NODE;
    if (value.GetString() == "regexp")
      return runtime::ObjectPreviewSubtype::REGEXP;
    if (value.GetString() == "date")
      return runtime::ObjectPreviewSubtype::DATE;
    if (value.GetString() == "map")
      return runtime::ObjectPreviewSubtype::MAP;
    if (value.GetString() == "set")
      return runtime::ObjectPreviewSubtype::SET;
    if (value.GetString() == "weakmap")
      return runtime::ObjectPreviewSubtype::WEAKMAP;
    if (value.GetString() == "weakset")
      return runtime::ObjectPreviewSubtype::WEAKSET;
    if (value.GetString() == "iterator")
      return runtime::ObjectPreviewSubtype::ITERATOR;
    if (value.GetString() == "generator")
      return runtime::ObjectPreviewSubtype::GENERATOR;
    if (value.GetString() == "error")
      return runtime::ObjectPreviewSubtype::ERR;
    errors->AddError("invalid enum value");
    return runtime::ObjectPreviewSubtype::ARRAY;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ObjectPreviewSubtype& value) {
  switch (value) {
    case runtime::ObjectPreviewSubtype::ARRAY:
      return std::make_unique<base::Value>("array");
    case runtime::ObjectPreviewSubtype::NONE:
      return std::make_unique<base::Value>("null");
    case runtime::ObjectPreviewSubtype::NODE:
      return std::make_unique<base::Value>("node");
    case runtime::ObjectPreviewSubtype::REGEXP:
      return std::make_unique<base::Value>("regexp");
    case runtime::ObjectPreviewSubtype::DATE:
      return std::make_unique<base::Value>("date");
    case runtime::ObjectPreviewSubtype::MAP:
      return std::make_unique<base::Value>("map");
    case runtime::ObjectPreviewSubtype::SET:
      return std::make_unique<base::Value>("set");
    case runtime::ObjectPreviewSubtype::WEAKMAP:
      return std::make_unique<base::Value>("weakmap");
    case runtime::ObjectPreviewSubtype::WEAKSET:
      return std::make_unique<base::Value>("weakset");
    case runtime::ObjectPreviewSubtype::ITERATOR:
      return std::make_unique<base::Value>("iterator");
    case runtime::ObjectPreviewSubtype::GENERATOR:
      return std::make_unique<base::Value>("generator");
    case runtime::ObjectPreviewSubtype::ERR:
      return std::make_unique<base::Value>("error");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<runtime::PropertyPreviewType> {
  static runtime::PropertyPreviewType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return runtime::PropertyPreviewType::OBJECT;
    }
    if (value.GetString() == "object")
      return runtime::PropertyPreviewType::OBJECT;
    if (value.GetString() == "function")
      return runtime::PropertyPreviewType::FUNCTION;
    if (value.GetString() == "undefined")
      return runtime::PropertyPreviewType::UNDEFINED;
    if (value.GetString() == "string")
      return runtime::PropertyPreviewType::STRING;
    if (value.GetString() == "number")
      return runtime::PropertyPreviewType::NUMBER;
    if (value.GetString() == "boolean")
      return runtime::PropertyPreviewType::BOOLEAN;
    if (value.GetString() == "symbol")
      return runtime::PropertyPreviewType::SYMBOL;
    if (value.GetString() == "accessor")
      return runtime::PropertyPreviewType::ACCESSOR;
    if (value.GetString() == "bigint")
      return runtime::PropertyPreviewType::BIGINT;
    errors->AddError("invalid enum value");
    return runtime::PropertyPreviewType::OBJECT;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::PropertyPreviewType& value) {
  switch (value) {
    case runtime::PropertyPreviewType::OBJECT:
      return std::make_unique<base::Value>("object");
    case runtime::PropertyPreviewType::FUNCTION:
      return std::make_unique<base::Value>("function");
    case runtime::PropertyPreviewType::UNDEFINED:
      return std::make_unique<base::Value>("undefined");
    case runtime::PropertyPreviewType::STRING:
      return std::make_unique<base::Value>("string");
    case runtime::PropertyPreviewType::NUMBER:
      return std::make_unique<base::Value>("number");
    case runtime::PropertyPreviewType::BOOLEAN:
      return std::make_unique<base::Value>("boolean");
    case runtime::PropertyPreviewType::SYMBOL:
      return std::make_unique<base::Value>("symbol");
    case runtime::PropertyPreviewType::ACCESSOR:
      return std::make_unique<base::Value>("accessor");
    case runtime::PropertyPreviewType::BIGINT:
      return std::make_unique<base::Value>("bigint");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<runtime::PropertyPreviewSubtype> {
  static runtime::PropertyPreviewSubtype Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return runtime::PropertyPreviewSubtype::ARRAY;
    }
    if (value.GetString() == "array")
      return runtime::PropertyPreviewSubtype::ARRAY;
    if (value.GetString() == "null")
      return runtime::PropertyPreviewSubtype::NONE;
    if (value.GetString() == "node")
      return runtime::PropertyPreviewSubtype::NODE;
    if (value.GetString() == "regexp")
      return runtime::PropertyPreviewSubtype::REGEXP;
    if (value.GetString() == "date")
      return runtime::PropertyPreviewSubtype::DATE;
    if (value.GetString() == "map")
      return runtime::PropertyPreviewSubtype::MAP;
    if (value.GetString() == "set")
      return runtime::PropertyPreviewSubtype::SET;
    if (value.GetString() == "weakmap")
      return runtime::PropertyPreviewSubtype::WEAKMAP;
    if (value.GetString() == "weakset")
      return runtime::PropertyPreviewSubtype::WEAKSET;
    if (value.GetString() == "iterator")
      return runtime::PropertyPreviewSubtype::ITERATOR;
    if (value.GetString() == "generator")
      return runtime::PropertyPreviewSubtype::GENERATOR;
    if (value.GetString() == "error")
      return runtime::PropertyPreviewSubtype::ERR;
    errors->AddError("invalid enum value");
    return runtime::PropertyPreviewSubtype::ARRAY;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::PropertyPreviewSubtype& value) {
  switch (value) {
    case runtime::PropertyPreviewSubtype::ARRAY:
      return std::make_unique<base::Value>("array");
    case runtime::PropertyPreviewSubtype::NONE:
      return std::make_unique<base::Value>("null");
    case runtime::PropertyPreviewSubtype::NODE:
      return std::make_unique<base::Value>("node");
    case runtime::PropertyPreviewSubtype::REGEXP:
      return std::make_unique<base::Value>("regexp");
    case runtime::PropertyPreviewSubtype::DATE:
      return std::make_unique<base::Value>("date");
    case runtime::PropertyPreviewSubtype::MAP:
      return std::make_unique<base::Value>("map");
    case runtime::PropertyPreviewSubtype::SET:
      return std::make_unique<base::Value>("set");
    case runtime::PropertyPreviewSubtype::WEAKMAP:
      return std::make_unique<base::Value>("weakmap");
    case runtime::PropertyPreviewSubtype::WEAKSET:
      return std::make_unique<base::Value>("weakset");
    case runtime::PropertyPreviewSubtype::ITERATOR:
      return std::make_unique<base::Value>("iterator");
    case runtime::PropertyPreviewSubtype::GENERATOR:
      return std::make_unique<base::Value>("generator");
    case runtime::PropertyPreviewSubtype::ERR:
      return std::make_unique<base::Value>("error");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<runtime::AwaitPromiseParams> {
  static std::unique_ptr<runtime::AwaitPromiseParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::AwaitPromiseParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::AwaitPromiseParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::AwaitPromiseResult> {
  static std::unique_ptr<runtime::AwaitPromiseResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::AwaitPromiseResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::AwaitPromiseResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::CallFunctionOnParams> {
  static std::unique_ptr<runtime::CallFunctionOnParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::CallFunctionOnParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::CallFunctionOnParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::CallFunctionOnResult> {
  static std::unique_ptr<runtime::CallFunctionOnResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::CallFunctionOnResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::CallFunctionOnResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::CompileScriptParams> {
  static std::unique_ptr<runtime::CompileScriptParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::CompileScriptParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::CompileScriptParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::CompileScriptResult> {
  static std::unique_ptr<runtime::CompileScriptResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::CompileScriptResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::CompileScriptResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::DisableParams> {
  static std::unique_ptr<runtime::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::DisableResult> {
  static std::unique_ptr<runtime::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::DiscardConsoleEntriesParams> {
  static std::unique_ptr<runtime::DiscardConsoleEntriesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::DiscardConsoleEntriesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::DiscardConsoleEntriesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::DiscardConsoleEntriesResult> {
  static std::unique_ptr<runtime::DiscardConsoleEntriesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::DiscardConsoleEntriesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::DiscardConsoleEntriesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::EnableParams> {
  static std::unique_ptr<runtime::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::EnableResult> {
  static std::unique_ptr<runtime::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::EvaluateParams> {
  static std::unique_ptr<runtime::EvaluateParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::EvaluateParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::EvaluateParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::EvaluateResult> {
  static std::unique_ptr<runtime::EvaluateResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::EvaluateResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::EvaluateResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::GetIsolateIdParams> {
  static std::unique_ptr<runtime::GetIsolateIdParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::GetIsolateIdParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::GetIsolateIdParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::GetIsolateIdResult> {
  static std::unique_ptr<runtime::GetIsolateIdResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::GetIsolateIdResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::GetIsolateIdResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::GetHeapUsageParams> {
  static std::unique_ptr<runtime::GetHeapUsageParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::GetHeapUsageParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::GetHeapUsageParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::GetHeapUsageResult> {
  static std::unique_ptr<runtime::GetHeapUsageResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::GetHeapUsageResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::GetHeapUsageResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::GetPropertiesParams> {
  static std::unique_ptr<runtime::GetPropertiesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::GetPropertiesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::GetPropertiesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::GetPropertiesResult> {
  static std::unique_ptr<runtime::GetPropertiesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::GetPropertiesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::GetPropertiesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::GlobalLexicalScopeNamesParams> {
  static std::unique_ptr<runtime::GlobalLexicalScopeNamesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::GlobalLexicalScopeNamesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::GlobalLexicalScopeNamesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::GlobalLexicalScopeNamesResult> {
  static std::unique_ptr<runtime::GlobalLexicalScopeNamesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::GlobalLexicalScopeNamesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::GlobalLexicalScopeNamesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::QueryObjectsParams> {
  static std::unique_ptr<runtime::QueryObjectsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::QueryObjectsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::QueryObjectsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::QueryObjectsResult> {
  static std::unique_ptr<runtime::QueryObjectsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::QueryObjectsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::QueryObjectsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::ReleaseObjectParams> {
  static std::unique_ptr<runtime::ReleaseObjectParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ReleaseObjectParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ReleaseObjectParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::ReleaseObjectResult> {
  static std::unique_ptr<runtime::ReleaseObjectResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ReleaseObjectResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ReleaseObjectResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::ReleaseObjectGroupParams> {
  static std::unique_ptr<runtime::ReleaseObjectGroupParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ReleaseObjectGroupParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ReleaseObjectGroupParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::ReleaseObjectGroupResult> {
  static std::unique_ptr<runtime::ReleaseObjectGroupResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ReleaseObjectGroupResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ReleaseObjectGroupResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::RunIfWaitingForDebuggerParams> {
  static std::unique_ptr<runtime::RunIfWaitingForDebuggerParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::RunIfWaitingForDebuggerParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::RunIfWaitingForDebuggerParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::RunIfWaitingForDebuggerResult> {
  static std::unique_ptr<runtime::RunIfWaitingForDebuggerResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::RunIfWaitingForDebuggerResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::RunIfWaitingForDebuggerResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::RunScriptParams> {
  static std::unique_ptr<runtime::RunScriptParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::RunScriptParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::RunScriptParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::RunScriptResult> {
  static std::unique_ptr<runtime::RunScriptResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::RunScriptResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::RunScriptResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::SetAsyncCallStackDepthParams> {
  static std::unique_ptr<runtime::SetAsyncCallStackDepthParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::SetAsyncCallStackDepthParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::SetAsyncCallStackDepthParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::SetAsyncCallStackDepthResult> {
  static std::unique_ptr<runtime::SetAsyncCallStackDepthResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::SetAsyncCallStackDepthResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::SetAsyncCallStackDepthResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::SetCustomObjectFormatterEnabledParams> {
  static std::unique_ptr<runtime::SetCustomObjectFormatterEnabledParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::SetCustomObjectFormatterEnabledParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::SetCustomObjectFormatterEnabledParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::SetCustomObjectFormatterEnabledResult> {
  static std::unique_ptr<runtime::SetCustomObjectFormatterEnabledResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::SetCustomObjectFormatterEnabledResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::SetCustomObjectFormatterEnabledResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::SetMaxCallStackSizeToCaptureParams> {
  static std::unique_ptr<runtime::SetMaxCallStackSizeToCaptureParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::SetMaxCallStackSizeToCaptureParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::SetMaxCallStackSizeToCaptureParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::SetMaxCallStackSizeToCaptureResult> {
  static std::unique_ptr<runtime::SetMaxCallStackSizeToCaptureResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::SetMaxCallStackSizeToCaptureResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::SetMaxCallStackSizeToCaptureResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::TerminateExecutionParams> {
  static std::unique_ptr<runtime::TerminateExecutionParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::TerminateExecutionParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::TerminateExecutionParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::TerminateExecutionResult> {
  static std::unique_ptr<runtime::TerminateExecutionResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::TerminateExecutionResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::TerminateExecutionResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::AddBindingParams> {
  static std::unique_ptr<runtime::AddBindingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::AddBindingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::AddBindingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::AddBindingResult> {
  static std::unique_ptr<runtime::AddBindingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::AddBindingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::AddBindingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::RemoveBindingParams> {
  static std::unique_ptr<runtime::RemoveBindingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::RemoveBindingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::RemoveBindingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::RemoveBindingResult> {
  static std::unique_ptr<runtime::RemoveBindingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::RemoveBindingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::RemoveBindingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::BindingCalledParams> {
  static std::unique_ptr<runtime::BindingCalledParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::BindingCalledParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::BindingCalledParams& value) {
  return value.Serialize();
}

template <>
struct FromValue<runtime::ConsoleAPICalledType> {
  static runtime::ConsoleAPICalledType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return runtime::ConsoleAPICalledType::LOG;
    }
    if (value.GetString() == "log")
      return runtime::ConsoleAPICalledType::LOG;
    if (value.GetString() == "debug")
      return runtime::ConsoleAPICalledType::DEBUG;
    if (value.GetString() == "info")
      return runtime::ConsoleAPICalledType::INFO;
    if (value.GetString() == "error")
      return runtime::ConsoleAPICalledType::ERR;
    if (value.GetString() == "warning")
      return runtime::ConsoleAPICalledType::WARNING;
    if (value.GetString() == "dir")
      return runtime::ConsoleAPICalledType::DIR;
    if (value.GetString() == "dirxml")
      return runtime::ConsoleAPICalledType::DIRXML;
    if (value.GetString() == "table")
      return runtime::ConsoleAPICalledType::TABLE;
    if (value.GetString() == "trace")
      return runtime::ConsoleAPICalledType::TRACE;
    if (value.GetString() == "clear")
      return runtime::ConsoleAPICalledType::CLEAR;
    if (value.GetString() == "startGroup")
      return runtime::ConsoleAPICalledType::START_GROUP;
    if (value.GetString() == "startGroupCollapsed")
      return runtime::ConsoleAPICalledType::START_GROUP_COLLAPSED;
    if (value.GetString() == "endGroup")
      return runtime::ConsoleAPICalledType::END_GROUP;
    if (value.GetString() == "assert")
      return runtime::ConsoleAPICalledType::ASSERT;
    if (value.GetString() == "profile")
      return runtime::ConsoleAPICalledType::PROFILE;
    if (value.GetString() == "profileEnd")
      return runtime::ConsoleAPICalledType::PROFILE_END;
    if (value.GetString() == "count")
      return runtime::ConsoleAPICalledType::COUNT;
    if (value.GetString() == "timeEnd")
      return runtime::ConsoleAPICalledType::TIME_END;
    errors->AddError("invalid enum value");
    return runtime::ConsoleAPICalledType::LOG;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ConsoleAPICalledType& value) {
  switch (value) {
    case runtime::ConsoleAPICalledType::LOG:
      return std::make_unique<base::Value>("log");
    case runtime::ConsoleAPICalledType::DEBUG:
      return std::make_unique<base::Value>("debug");
    case runtime::ConsoleAPICalledType::INFO:
      return std::make_unique<base::Value>("info");
    case runtime::ConsoleAPICalledType::ERR:
      return std::make_unique<base::Value>("error");
    case runtime::ConsoleAPICalledType::WARNING:
      return std::make_unique<base::Value>("warning");
    case runtime::ConsoleAPICalledType::DIR:
      return std::make_unique<base::Value>("dir");
    case runtime::ConsoleAPICalledType::DIRXML:
      return std::make_unique<base::Value>("dirxml");
    case runtime::ConsoleAPICalledType::TABLE:
      return std::make_unique<base::Value>("table");
    case runtime::ConsoleAPICalledType::TRACE:
      return std::make_unique<base::Value>("trace");
    case runtime::ConsoleAPICalledType::CLEAR:
      return std::make_unique<base::Value>("clear");
    case runtime::ConsoleAPICalledType::START_GROUP:
      return std::make_unique<base::Value>("startGroup");
    case runtime::ConsoleAPICalledType::START_GROUP_COLLAPSED:
      return std::make_unique<base::Value>("startGroupCollapsed");
    case runtime::ConsoleAPICalledType::END_GROUP:
      return std::make_unique<base::Value>("endGroup");
    case runtime::ConsoleAPICalledType::ASSERT:
      return std::make_unique<base::Value>("assert");
    case runtime::ConsoleAPICalledType::PROFILE:
      return std::make_unique<base::Value>("profile");
    case runtime::ConsoleAPICalledType::PROFILE_END:
      return std::make_unique<base::Value>("profileEnd");
    case runtime::ConsoleAPICalledType::COUNT:
      return std::make_unique<base::Value>("count");
    case runtime::ConsoleAPICalledType::TIME_END:
      return std::make_unique<base::Value>("timeEnd");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<runtime::ConsoleAPICalledParams> {
  static std::unique_ptr<runtime::ConsoleAPICalledParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ConsoleAPICalledParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ConsoleAPICalledParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::ExceptionRevokedParams> {
  static std::unique_ptr<runtime::ExceptionRevokedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ExceptionRevokedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ExceptionRevokedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::ExceptionThrownParams> {
  static std::unique_ptr<runtime::ExceptionThrownParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ExceptionThrownParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ExceptionThrownParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::ExecutionContextCreatedParams> {
  static std::unique_ptr<runtime::ExecutionContextCreatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ExecutionContextCreatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ExecutionContextCreatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::ExecutionContextDestroyedParams> {
  static std::unique_ptr<runtime::ExecutionContextDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ExecutionContextDestroyedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ExecutionContextDestroyedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::ExecutionContextsClearedParams> {
  static std::unique_ptr<runtime::ExecutionContextsClearedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::ExecutionContextsClearedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::ExecutionContextsClearedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<runtime::InspectRequestedParams> {
  static std::unique_ptr<runtime::InspectRequestedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return runtime::InspectRequestedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const runtime::InspectRequestedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_RUNTIME_H_
