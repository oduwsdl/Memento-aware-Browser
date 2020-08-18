// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_IO_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_IO_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace io {

// Parameters for the Close command.
class HEADLESS_EXPORT CloseParams {
 public:
  static std::unique_ptr<CloseParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CloseParams() { }

  // Handle of the stream to close.
  std::string GetHandle() const { return handle_; }
  void SetHandle(const std::string& value) { handle_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CloseParams> Clone() const;

  template<int STATE>
  class CloseParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kHandleSet = 1 << 1,
      kAllRequiredFieldsSet = (kHandleSet | 0)
    };

    CloseParamsBuilder<STATE | kHandleSet>& SetHandle(const std::string& value) {
      static_assert(!(STATE & kHandleSet), "property handle should not have already been set");
      result_->SetHandle(value);
      return CastState<kHandleSet>();
    }

    std::unique_ptr<CloseParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CloseParams;
    CloseParamsBuilder() : result_(new CloseParams()) { }

    template<int STEP> CloseParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CloseParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CloseParams> result_;
  };

  static CloseParamsBuilder<0> Builder() {
    return CloseParamsBuilder<0>();
  }

 private:
  CloseParams() { }

  std::string handle_;

  DISALLOW_COPY_AND_ASSIGN(CloseParams);
};


// Result for the Close command.
class HEADLESS_EXPORT CloseResult {
 public:
  static std::unique_ptr<CloseResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CloseResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CloseResult> Clone() const;

  template<int STATE>
  class CloseResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<CloseResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CloseResult;
    CloseResultBuilder() : result_(new CloseResult()) { }

    template<int STEP> CloseResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CloseResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CloseResult> result_;
  };

  static CloseResultBuilder<0> Builder() {
    return CloseResultBuilder<0>();
  }

 private:
  CloseResult() { }


  DISALLOW_COPY_AND_ASSIGN(CloseResult);
};


// Parameters for the Read command.
class HEADLESS_EXPORT ReadParams {
 public:
  static std::unique_ptr<ReadParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReadParams() { }

  // Handle of the stream to read.
  std::string GetHandle() const { return handle_; }
  void SetHandle(const std::string& value) { handle_ = value; }

  // Seek to the specified offset before reading (if not specificed, proceed with offset
  // following the last read). Some types of streams may only support sequential reads.
  bool HasOffset() const { return !!offset_; }
  int GetOffset() const { DCHECK(HasOffset()); return offset_.value(); }
  void SetOffset(int value) { offset_ = value; }

  // Maximum number of bytes to read (left upon the agent discretion if not specified).
  bool HasSize() const { return !!size_; }
  int GetSize() const { DCHECK(HasSize()); return size_.value(); }
  void SetSize(int value) { size_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReadParams> Clone() const;

  template<int STATE>
  class ReadParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kHandleSet = 1 << 1,
      kAllRequiredFieldsSet = (kHandleSet | 0)
    };

    ReadParamsBuilder<STATE | kHandleSet>& SetHandle(const std::string& value) {
      static_assert(!(STATE & kHandleSet), "property handle should not have already been set");
      result_->SetHandle(value);
      return CastState<kHandleSet>();
    }

    ReadParamsBuilder<STATE>& SetOffset(int value) {
      result_->SetOffset(value);
      return *this;
    }

    ReadParamsBuilder<STATE>& SetSize(int value) {
      result_->SetSize(value);
      return *this;
    }

    std::unique_ptr<ReadParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReadParams;
    ReadParamsBuilder() : result_(new ReadParams()) { }

    template<int STEP> ReadParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReadParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReadParams> result_;
  };

  static ReadParamsBuilder<0> Builder() {
    return ReadParamsBuilder<0>();
  }

 private:
  ReadParams() { }

  std::string handle_;
  base::Optional<int> offset_;
  base::Optional<int> size_;

  DISALLOW_COPY_AND_ASSIGN(ReadParams);
};


// Result for the Read command.
class HEADLESS_EXPORT ReadResult {
 public:
  static std::unique_ptr<ReadResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReadResult() { }

  // Set if the data is base64-encoded
  bool HasBase64Encoded() const { return !!base64_encoded_; }
  bool GetBase64Encoded() const { DCHECK(HasBase64Encoded()); return base64_encoded_.value(); }
  void SetBase64Encoded(bool value) { base64_encoded_ = value; }

  // Data that were read.
  std::string GetData() const { return data_; }
  void SetData(const std::string& value) { data_ = value; }

  // Set if the end-of-file condition occured while reading.
  bool GetEof() const { return eof_; }
  void SetEof(bool value) { eof_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReadResult> Clone() const;

  template<int STATE>
  class ReadResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDataSet = 1 << 1,
    kEofSet = 1 << 2,
      kAllRequiredFieldsSet = (kDataSet | kEofSet | 0)
    };

    ReadResultBuilder<STATE>& SetBase64Encoded(bool value) {
      result_->SetBase64Encoded(value);
      return *this;
    }

    ReadResultBuilder<STATE | kDataSet>& SetData(const std::string& value) {
      static_assert(!(STATE & kDataSet), "property data should not have already been set");
      result_->SetData(value);
      return CastState<kDataSet>();
    }

    ReadResultBuilder<STATE | kEofSet>& SetEof(bool value) {
      static_assert(!(STATE & kEofSet), "property eof should not have already been set");
      result_->SetEof(value);
      return CastState<kEofSet>();
    }

    std::unique_ptr<ReadResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReadResult;
    ReadResultBuilder() : result_(new ReadResult()) { }

    template<int STEP> ReadResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReadResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReadResult> result_;
  };

  static ReadResultBuilder<0> Builder() {
    return ReadResultBuilder<0>();
  }

 private:
  ReadResult() { }

  base::Optional<bool> base64_encoded_;
  std::string data_;
  bool eof_;

  DISALLOW_COPY_AND_ASSIGN(ReadResult);
};


// Parameters for the ResolveBlob command.
class HEADLESS_EXPORT ResolveBlobParams {
 public:
  static std::unique_ptr<ResolveBlobParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResolveBlobParams() { }

  // Object id of a Blob object wrapper.
  std::string GetObjectId() const { return object_id_; }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResolveBlobParams> Clone() const;

  template<int STATE>
  class ResolveBlobParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kObjectIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kObjectIdSet | 0)
    };

    ResolveBlobParamsBuilder<STATE | kObjectIdSet>& SetObjectId(const std::string& value) {
      static_assert(!(STATE & kObjectIdSet), "property objectId should not have already been set");
      result_->SetObjectId(value);
      return CastState<kObjectIdSet>();
    }

    std::unique_ptr<ResolveBlobParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResolveBlobParams;
    ResolveBlobParamsBuilder() : result_(new ResolveBlobParams()) { }

    template<int STEP> ResolveBlobParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResolveBlobParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResolveBlobParams> result_;
  };

  static ResolveBlobParamsBuilder<0> Builder() {
    return ResolveBlobParamsBuilder<0>();
  }

 private:
  ResolveBlobParams() { }

  std::string object_id_;

  DISALLOW_COPY_AND_ASSIGN(ResolveBlobParams);
};


// Result for the ResolveBlob command.
class HEADLESS_EXPORT ResolveBlobResult {
 public:
  static std::unique_ptr<ResolveBlobResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResolveBlobResult() { }

  // UUID of the specified Blob.
  std::string GetUuid() const { return uuid_; }
  void SetUuid(const std::string& value) { uuid_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResolveBlobResult> Clone() const;

  template<int STATE>
  class ResolveBlobResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUuidSet = 1 << 1,
      kAllRequiredFieldsSet = (kUuidSet | 0)
    };

    ResolveBlobResultBuilder<STATE | kUuidSet>& SetUuid(const std::string& value) {
      static_assert(!(STATE & kUuidSet), "property uuid should not have already been set");
      result_->SetUuid(value);
      return CastState<kUuidSet>();
    }

    std::unique_ptr<ResolveBlobResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResolveBlobResult;
    ResolveBlobResultBuilder() : result_(new ResolveBlobResult()) { }

    template<int STEP> ResolveBlobResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResolveBlobResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResolveBlobResult> result_;
  };

  static ResolveBlobResultBuilder<0> Builder() {
    return ResolveBlobResultBuilder<0>();
  }

 private:
  ResolveBlobResult() { }

  std::string uuid_;

  DISALLOW_COPY_AND_ASSIGN(ResolveBlobResult);
};


}  // namespace io

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_IO_H_
