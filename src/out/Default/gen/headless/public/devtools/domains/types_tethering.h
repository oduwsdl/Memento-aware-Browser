// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_TETHERING_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_TETHERING_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_tethering.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace tethering {

// Parameters for the Bind command.
class HEADLESS_EXPORT BindParams {
 public:
  static std::unique_ptr<BindParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~BindParams() { }

  // Port number to bind.
  int GetPort() const { return port_; }
  void SetPort(int value) { port_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BindParams> Clone() const;

  template<int STATE>
  class BindParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPortSet = 1 << 1,
      kAllRequiredFieldsSet = (kPortSet | 0)
    };

    BindParamsBuilder<STATE | kPortSet>& SetPort(int value) {
      static_assert(!(STATE & kPortSet), "property port should not have already been set");
      result_->SetPort(value);
      return CastState<kPortSet>();
    }

    std::unique_ptr<BindParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BindParams;
    BindParamsBuilder() : result_(new BindParams()) { }

    template<int STEP> BindParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BindParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BindParams> result_;
  };

  static BindParamsBuilder<0> Builder() {
    return BindParamsBuilder<0>();
  }

 private:
  BindParams() { }

  int port_;

  DISALLOW_COPY_AND_ASSIGN(BindParams);
};


// Result for the Bind command.
class HEADLESS_EXPORT BindResult {
 public:
  static std::unique_ptr<BindResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~BindResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BindResult> Clone() const;

  template<int STATE>
  class BindResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<BindResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BindResult;
    BindResultBuilder() : result_(new BindResult()) { }

    template<int STEP> BindResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BindResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BindResult> result_;
  };

  static BindResultBuilder<0> Builder() {
    return BindResultBuilder<0>();
  }

 private:
  BindResult() { }


  DISALLOW_COPY_AND_ASSIGN(BindResult);
};


// Parameters for the Unbind command.
class HEADLESS_EXPORT UnbindParams {
 public:
  static std::unique_ptr<UnbindParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~UnbindParams() { }

  // Port number to unbind.
  int GetPort() const { return port_; }
  void SetPort(int value) { port_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<UnbindParams> Clone() const;

  template<int STATE>
  class UnbindParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPortSet = 1 << 1,
      kAllRequiredFieldsSet = (kPortSet | 0)
    };

    UnbindParamsBuilder<STATE | kPortSet>& SetPort(int value) {
      static_assert(!(STATE & kPortSet), "property port should not have already been set");
      result_->SetPort(value);
      return CastState<kPortSet>();
    }

    std::unique_ptr<UnbindParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class UnbindParams;
    UnbindParamsBuilder() : result_(new UnbindParams()) { }

    template<int STEP> UnbindParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<UnbindParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<UnbindParams> result_;
  };

  static UnbindParamsBuilder<0> Builder() {
    return UnbindParamsBuilder<0>();
  }

 private:
  UnbindParams() { }

  int port_;

  DISALLOW_COPY_AND_ASSIGN(UnbindParams);
};


// Result for the Unbind command.
class HEADLESS_EXPORT UnbindResult {
 public:
  static std::unique_ptr<UnbindResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~UnbindResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<UnbindResult> Clone() const;

  template<int STATE>
  class UnbindResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<UnbindResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class UnbindResult;
    UnbindResultBuilder() : result_(new UnbindResult()) { }

    template<int STEP> UnbindResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<UnbindResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<UnbindResult> result_;
  };

  static UnbindResultBuilder<0> Builder() {
    return UnbindResultBuilder<0>();
  }

 private:
  UnbindResult() { }


  DISALLOW_COPY_AND_ASSIGN(UnbindResult);
};


// Parameters for the Accepted event.
class HEADLESS_EXPORT AcceptedParams {
 public:
  static std::unique_ptr<AcceptedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AcceptedParams() { }

  // Port number that was successfully bound.
  int GetPort() const { return port_; }
  void SetPort(int value) { port_ = value; }

  // Connection id to be used.
  std::string GetConnectionId() const { return connection_id_; }
  void SetConnectionId(const std::string& value) { connection_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AcceptedParams> Clone() const;

  template<int STATE>
  class AcceptedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPortSet = 1 << 1,
    kConnectionIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kPortSet | kConnectionIdSet | 0)
    };

    AcceptedParamsBuilder<STATE | kPortSet>& SetPort(int value) {
      static_assert(!(STATE & kPortSet), "property port should not have already been set");
      result_->SetPort(value);
      return CastState<kPortSet>();
    }

    AcceptedParamsBuilder<STATE | kConnectionIdSet>& SetConnectionId(const std::string& value) {
      static_assert(!(STATE & kConnectionIdSet), "property connectionId should not have already been set");
      result_->SetConnectionId(value);
      return CastState<kConnectionIdSet>();
    }

    std::unique_ptr<AcceptedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AcceptedParams;
    AcceptedParamsBuilder() : result_(new AcceptedParams()) { }

    template<int STEP> AcceptedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AcceptedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AcceptedParams> result_;
  };

  static AcceptedParamsBuilder<0> Builder() {
    return AcceptedParamsBuilder<0>();
  }

 private:
  AcceptedParams() { }

  int port_;
  std::string connection_id_;

  DISALLOW_COPY_AND_ASSIGN(AcceptedParams);
};


}  // namespace tethering

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_TETHERING_H_
