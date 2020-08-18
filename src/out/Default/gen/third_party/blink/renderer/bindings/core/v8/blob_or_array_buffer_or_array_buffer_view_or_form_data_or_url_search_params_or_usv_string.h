// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_BLOB_OR_ARRAY_BUFFER_OR_ARRAY_BUFFER_VIEW_OR_FORM_DATA_OR_URL_SEARCH_PARAMS_OR_USV_STRING_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_BLOB_OR_ARRAY_BUFFER_OR_ARRAY_BUFFER_VIEW_OR_FORM_DATA_OR_URL_SEARCH_PARAMS_OR_USV_STRING_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/flexible_array_buffer_view.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class Blob;
class DOMArrayBuffer;
class FormData;
class URLSearchParams;

class CORE_EXPORT BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString final {
  DISALLOW_NEW();
 public:
  BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsArrayBuffer() const { return type_ == SpecificType::kArrayBuffer; }
  DOMArrayBuffer* GetAsArrayBuffer() const;
  void SetArrayBuffer(DOMArrayBuffer*);
  static BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString FromArrayBuffer(DOMArrayBuffer*);

  bool IsArrayBufferView() const { return type_ == SpecificType::kArrayBufferView; }
  NotShared<DOMArrayBufferView> GetAsArrayBufferView() const;
  void SetArrayBufferView(NotShared<DOMArrayBufferView>);
  static BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString FromArrayBufferView(NotShared<DOMArrayBufferView>);

  bool IsBlob() const { return type_ == SpecificType::kBlob; }
  Blob* GetAsBlob() const;
  void SetBlob(Blob*);
  static BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString FromBlob(Blob*);

  bool IsFormData() const { return type_ == SpecificType::kFormData; }
  FormData* GetAsFormData() const;
  void SetFormData(FormData*);
  static BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString FromFormData(FormData*);

  bool IsURLSearchParams() const { return type_ == SpecificType::kURLSearchParams; }
  URLSearchParams* GetAsURLSearchParams() const;
  void SetURLSearchParams(URLSearchParams*);
  static BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString FromURLSearchParams(URLSearchParams*);

  bool IsUSVString() const { return type_ == SpecificType::kUSVString; }
  const String& GetAsUSVString() const;
  void SetUSVString(const String&);
  static BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString FromUSVString(const String&);

  BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString(const BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString&);
  ~BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString();
  BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString& operator=(const BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString&);
  void Trace(Visitor*) const;

 private:
  enum class SpecificType {
    kNone,
    kArrayBuffer,
    kArrayBufferView,
    kBlob,
    kFormData,
    kURLSearchParams,
    kUSVString,
  };
  SpecificType type_;

  Member<DOMArrayBuffer> array_buffer_;
  NotShared<DOMArrayBufferView> array_buffer_view_;
  Member<Blob> blob_;
  Member<FormData> form_data_;
  Member<URLSearchParams> url_search_params_;
  String usv_string_;

  friend CORE_EXPORT v8::Local<v8::Value> ToV8(const BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString final {
 public:
  CORE_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString&, UnionTypeConversionMode, ExceptionState&);
};

CORE_EXPORT v8::Local<v8::Value> ToV8(const BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString> : public NativeValueTraitsBase<BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString> {
  CORE_EXPORT static BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  CORE_EXPORT static BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString NullValue() { return BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString(); }
};

template <>
struct V8TypeOf<BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString> {
  typedef V8BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::BlobOrArrayBufferOrArrayBufferViewOrFormDataOrURLSearchParamsOrUSVString)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_BLOB_OR_ARRAY_BUFFER_OR_ARRAY_BUFFER_VIEW_OR_FORM_DATA_OR_URL_SEARCH_PARAMS_OR_USV_STRING_H_
