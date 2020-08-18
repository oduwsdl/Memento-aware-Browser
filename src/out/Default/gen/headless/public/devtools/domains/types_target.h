// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_TARGET_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_TARGET_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_browser.h"
#include "headless/public/devtools/internal/types_forward_declarations_target.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace target {

class HEADLESS_EXPORT TargetInfo {
 public:
  static std::unique_ptr<TargetInfo> Parse(const base::Value& value, ErrorReporter* errors);
  ~TargetInfo() { }

  std::string GetTargetId() const { return target_id_; }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  std::string GetType() const { return type_; }
  void SetType(const std::string& value) { type_ = value; }

  std::string GetTitle() const { return title_; }
  void SetTitle(const std::string& value) { title_ = value; }

  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Whether the target has an attached client.
  bool GetAttached() const { return attached_; }
  void SetAttached(bool value) { attached_ = value; }

  // Opener target Id
  bool HasOpenerId() const { return !!opener_id_; }
  std::string GetOpenerId() const { DCHECK(HasOpenerId()); return opener_id_.value(); }
  void SetOpenerId(const std::string& value) { opener_id_ = value; }

  bool HasBrowserContextId() const { return !!browser_context_id_; }
  std::string GetBrowserContextId() const { DCHECK(HasBrowserContextId()); return browser_context_id_.value(); }
  void SetBrowserContextId(const std::string& value) { browser_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TargetInfo> Clone() const;

  template<int STATE>
  class TargetInfoBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetIdSet = 1 << 1,
    kTypeSet = 1 << 2,
    kTitleSet = 1 << 3,
    kUrlSet = 1 << 4,
    kAttachedSet = 1 << 5,
      kAllRequiredFieldsSet = (kTargetIdSet | kTypeSet | kTitleSet | kUrlSet | kAttachedSet | 0)
    };

    TargetInfoBuilder<STATE | kTargetIdSet>& SetTargetId(const std::string& value) {
      static_assert(!(STATE & kTargetIdSet), "property targetId should not have already been set");
      result_->SetTargetId(value);
      return CastState<kTargetIdSet>();
    }

    TargetInfoBuilder<STATE | kTypeSet>& SetType(const std::string& value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    TargetInfoBuilder<STATE | kTitleSet>& SetTitle(const std::string& value) {
      static_assert(!(STATE & kTitleSet), "property title should not have already been set");
      result_->SetTitle(value);
      return CastState<kTitleSet>();
    }

    TargetInfoBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    TargetInfoBuilder<STATE | kAttachedSet>& SetAttached(bool value) {
      static_assert(!(STATE & kAttachedSet), "property attached should not have already been set");
      result_->SetAttached(value);
      return CastState<kAttachedSet>();
    }

    TargetInfoBuilder<STATE>& SetOpenerId(const std::string& value) {
      result_->SetOpenerId(value);
      return *this;
    }

    TargetInfoBuilder<STATE>& SetBrowserContextId(const std::string& value) {
      result_->SetBrowserContextId(value);
      return *this;
    }

    std::unique_ptr<TargetInfo> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TargetInfo;
    TargetInfoBuilder() : result_(new TargetInfo()) { }

    template<int STEP> TargetInfoBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TargetInfoBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TargetInfo> result_;
  };

  static TargetInfoBuilder<0> Builder() {
    return TargetInfoBuilder<0>();
  }

 private:
  TargetInfo() { }

  std::string target_id_;
  std::string type_;
  std::string title_;
  std::string url_;
  bool attached_;
  base::Optional<std::string> opener_id_;
  base::Optional<std::string> browser_context_id_;

  DISALLOW_COPY_AND_ASSIGN(TargetInfo);
};


class HEADLESS_EXPORT RemoteLocation {
 public:
  static std::unique_ptr<RemoteLocation> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoteLocation() { }

  std::string GetHost() const { return host_; }
  void SetHost(const std::string& value) { host_ = value; }

  int GetPort() const { return port_; }
  void SetPort(int value) { port_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoteLocation> Clone() const;

  template<int STATE>
  class RemoteLocationBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kHostSet = 1 << 1,
    kPortSet = 1 << 2,
      kAllRequiredFieldsSet = (kHostSet | kPortSet | 0)
    };

    RemoteLocationBuilder<STATE | kHostSet>& SetHost(const std::string& value) {
      static_assert(!(STATE & kHostSet), "property host should not have already been set");
      result_->SetHost(value);
      return CastState<kHostSet>();
    }

    RemoteLocationBuilder<STATE | kPortSet>& SetPort(int value) {
      static_assert(!(STATE & kPortSet), "property port should not have already been set");
      result_->SetPort(value);
      return CastState<kPortSet>();
    }

    std::unique_ptr<RemoteLocation> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoteLocation;
    RemoteLocationBuilder() : result_(new RemoteLocation()) { }

    template<int STEP> RemoteLocationBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoteLocationBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoteLocation> result_;
  };

  static RemoteLocationBuilder<0> Builder() {
    return RemoteLocationBuilder<0>();
  }

 private:
  RemoteLocation() { }

  std::string host_;
  int port_;

  DISALLOW_COPY_AND_ASSIGN(RemoteLocation);
};


// Parameters for the ActivateTarget command.
class HEADLESS_EXPORT ActivateTargetParams {
 public:
  static std::unique_ptr<ActivateTargetParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ActivateTargetParams() { }

  std::string GetTargetId() const { return target_id_; }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ActivateTargetParams> Clone() const;

  template<int STATE>
  class ActivateTargetParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kTargetIdSet | 0)
    };

    ActivateTargetParamsBuilder<STATE | kTargetIdSet>& SetTargetId(const std::string& value) {
      static_assert(!(STATE & kTargetIdSet), "property targetId should not have already been set");
      result_->SetTargetId(value);
      return CastState<kTargetIdSet>();
    }

    std::unique_ptr<ActivateTargetParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ActivateTargetParams;
    ActivateTargetParamsBuilder() : result_(new ActivateTargetParams()) { }

    template<int STEP> ActivateTargetParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ActivateTargetParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ActivateTargetParams> result_;
  };

  static ActivateTargetParamsBuilder<0> Builder() {
    return ActivateTargetParamsBuilder<0>();
  }

 private:
  ActivateTargetParams() { }

  std::string target_id_;

  DISALLOW_COPY_AND_ASSIGN(ActivateTargetParams);
};


// Result for the ActivateTarget command.
class HEADLESS_EXPORT ActivateTargetResult {
 public:
  static std::unique_ptr<ActivateTargetResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ActivateTargetResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ActivateTargetResult> Clone() const;

  template<int STATE>
  class ActivateTargetResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ActivateTargetResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ActivateTargetResult;
    ActivateTargetResultBuilder() : result_(new ActivateTargetResult()) { }

    template<int STEP> ActivateTargetResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ActivateTargetResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ActivateTargetResult> result_;
  };

  static ActivateTargetResultBuilder<0> Builder() {
    return ActivateTargetResultBuilder<0>();
  }

 private:
  ActivateTargetResult() { }


  DISALLOW_COPY_AND_ASSIGN(ActivateTargetResult);
};


// Parameters for the AttachToTarget command.
class HEADLESS_EXPORT AttachToTargetParams {
 public:
  static std::unique_ptr<AttachToTargetParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AttachToTargetParams() { }

  std::string GetTargetId() const { return target_id_; }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  // Enables "flat" access to the session via specifying sessionId attribute in the commands.
  // We plan to make this the default, deprecate non-flattened mode,
  // and eventually retire it. See crbug.com/991325.
  bool HasFlatten() const { return !!flatten_; }
  bool GetFlatten() const { DCHECK(HasFlatten()); return flatten_.value(); }
  void SetFlatten(bool value) { flatten_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AttachToTargetParams> Clone() const;

  template<int STATE>
  class AttachToTargetParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kTargetIdSet | 0)
    };

    AttachToTargetParamsBuilder<STATE | kTargetIdSet>& SetTargetId(const std::string& value) {
      static_assert(!(STATE & kTargetIdSet), "property targetId should not have already been set");
      result_->SetTargetId(value);
      return CastState<kTargetIdSet>();
    }

    AttachToTargetParamsBuilder<STATE>& SetFlatten(bool value) {
      result_->SetFlatten(value);
      return *this;
    }

    std::unique_ptr<AttachToTargetParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AttachToTargetParams;
    AttachToTargetParamsBuilder() : result_(new AttachToTargetParams()) { }

    template<int STEP> AttachToTargetParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AttachToTargetParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AttachToTargetParams> result_;
  };

  static AttachToTargetParamsBuilder<0> Builder() {
    return AttachToTargetParamsBuilder<0>();
  }

 private:
  AttachToTargetParams() { }

  std::string target_id_;
  base::Optional<bool> flatten_;

  DISALLOW_COPY_AND_ASSIGN(AttachToTargetParams);
};


// Result for the AttachToTarget command.
class HEADLESS_EXPORT AttachToTargetResult {
 public:
  static std::unique_ptr<AttachToTargetResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~AttachToTargetResult() { }

  // Id assigned to the session.
  std::string GetSessionId() const { return session_id_; }
  void SetSessionId(const std::string& value) { session_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AttachToTargetResult> Clone() const;

  template<int STATE>
  class AttachToTargetResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSessionIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSessionIdSet | 0)
    };

    AttachToTargetResultBuilder<STATE | kSessionIdSet>& SetSessionId(const std::string& value) {
      static_assert(!(STATE & kSessionIdSet), "property sessionId should not have already been set");
      result_->SetSessionId(value);
      return CastState<kSessionIdSet>();
    }

    std::unique_ptr<AttachToTargetResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AttachToTargetResult;
    AttachToTargetResultBuilder() : result_(new AttachToTargetResult()) { }

    template<int STEP> AttachToTargetResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AttachToTargetResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AttachToTargetResult> result_;
  };

  static AttachToTargetResultBuilder<0> Builder() {
    return AttachToTargetResultBuilder<0>();
  }

 private:
  AttachToTargetResult() { }

  std::string session_id_;

  DISALLOW_COPY_AND_ASSIGN(AttachToTargetResult);
};


// Parameters for the AttachToBrowserTarget command.
class HEADLESS_EXPORT AttachToBrowserTargetParams {
 public:
  static std::unique_ptr<AttachToBrowserTargetParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AttachToBrowserTargetParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AttachToBrowserTargetParams> Clone() const;

  template<int STATE>
  class AttachToBrowserTargetParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<AttachToBrowserTargetParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AttachToBrowserTargetParams;
    AttachToBrowserTargetParamsBuilder() : result_(new AttachToBrowserTargetParams()) { }

    template<int STEP> AttachToBrowserTargetParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AttachToBrowserTargetParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AttachToBrowserTargetParams> result_;
  };

  static AttachToBrowserTargetParamsBuilder<0> Builder() {
    return AttachToBrowserTargetParamsBuilder<0>();
  }

 private:
  AttachToBrowserTargetParams() { }


  DISALLOW_COPY_AND_ASSIGN(AttachToBrowserTargetParams);
};


// Result for the AttachToBrowserTarget command.
class HEADLESS_EXPORT AttachToBrowserTargetResult {
 public:
  static std::unique_ptr<AttachToBrowserTargetResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~AttachToBrowserTargetResult() { }

  // Id assigned to the session.
  std::string GetSessionId() const { return session_id_; }
  void SetSessionId(const std::string& value) { session_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AttachToBrowserTargetResult> Clone() const;

  template<int STATE>
  class AttachToBrowserTargetResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSessionIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSessionIdSet | 0)
    };

    AttachToBrowserTargetResultBuilder<STATE | kSessionIdSet>& SetSessionId(const std::string& value) {
      static_assert(!(STATE & kSessionIdSet), "property sessionId should not have already been set");
      result_->SetSessionId(value);
      return CastState<kSessionIdSet>();
    }

    std::unique_ptr<AttachToBrowserTargetResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AttachToBrowserTargetResult;
    AttachToBrowserTargetResultBuilder() : result_(new AttachToBrowserTargetResult()) { }

    template<int STEP> AttachToBrowserTargetResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AttachToBrowserTargetResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AttachToBrowserTargetResult> result_;
  };

  static AttachToBrowserTargetResultBuilder<0> Builder() {
    return AttachToBrowserTargetResultBuilder<0>();
  }

 private:
  AttachToBrowserTargetResult() { }

  std::string session_id_;

  DISALLOW_COPY_AND_ASSIGN(AttachToBrowserTargetResult);
};


// Parameters for the CloseTarget command.
class HEADLESS_EXPORT CloseTargetParams {
 public:
  static std::unique_ptr<CloseTargetParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CloseTargetParams() { }

  std::string GetTargetId() const { return target_id_; }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CloseTargetParams> Clone() const;

  template<int STATE>
  class CloseTargetParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kTargetIdSet | 0)
    };

    CloseTargetParamsBuilder<STATE | kTargetIdSet>& SetTargetId(const std::string& value) {
      static_assert(!(STATE & kTargetIdSet), "property targetId should not have already been set");
      result_->SetTargetId(value);
      return CastState<kTargetIdSet>();
    }

    std::unique_ptr<CloseTargetParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CloseTargetParams;
    CloseTargetParamsBuilder() : result_(new CloseTargetParams()) { }

    template<int STEP> CloseTargetParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CloseTargetParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CloseTargetParams> result_;
  };

  static CloseTargetParamsBuilder<0> Builder() {
    return CloseTargetParamsBuilder<0>();
  }

 private:
  CloseTargetParams() { }

  std::string target_id_;

  DISALLOW_COPY_AND_ASSIGN(CloseTargetParams);
};


// Result for the CloseTarget command.
class HEADLESS_EXPORT CloseTargetResult {
 public:
  static std::unique_ptr<CloseTargetResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CloseTargetResult() { }

  bool GetSuccess() const { return success_; }
  void SetSuccess(bool value) { success_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CloseTargetResult> Clone() const;

  template<int STATE>
  class CloseTargetResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSuccessSet = 1 << 1,
      kAllRequiredFieldsSet = (kSuccessSet | 0)
    };

    CloseTargetResultBuilder<STATE | kSuccessSet>& SetSuccess(bool value) {
      static_assert(!(STATE & kSuccessSet), "property success should not have already been set");
      result_->SetSuccess(value);
      return CastState<kSuccessSet>();
    }

    std::unique_ptr<CloseTargetResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CloseTargetResult;
    CloseTargetResultBuilder() : result_(new CloseTargetResult()) { }

    template<int STEP> CloseTargetResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CloseTargetResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CloseTargetResult> result_;
  };

  static CloseTargetResultBuilder<0> Builder() {
    return CloseTargetResultBuilder<0>();
  }

 private:
  CloseTargetResult() { }

  bool success_;

  DISALLOW_COPY_AND_ASSIGN(CloseTargetResult);
};


// Parameters for the ExposeDevToolsProtocol command.
class HEADLESS_EXPORT ExposeDevToolsProtocolParams {
 public:
  static std::unique_ptr<ExposeDevToolsProtocolParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ExposeDevToolsProtocolParams() { }

  std::string GetTargetId() const { return target_id_; }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  // Binding name, 'cdp' if not specified.
  bool HasBindingName() const { return !!binding_name_; }
  std::string GetBindingName() const { DCHECK(HasBindingName()); return binding_name_.value(); }
  void SetBindingName(const std::string& value) { binding_name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ExposeDevToolsProtocolParams> Clone() const;

  template<int STATE>
  class ExposeDevToolsProtocolParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kTargetIdSet | 0)
    };

    ExposeDevToolsProtocolParamsBuilder<STATE | kTargetIdSet>& SetTargetId(const std::string& value) {
      static_assert(!(STATE & kTargetIdSet), "property targetId should not have already been set");
      result_->SetTargetId(value);
      return CastState<kTargetIdSet>();
    }

    ExposeDevToolsProtocolParamsBuilder<STATE>& SetBindingName(const std::string& value) {
      result_->SetBindingName(value);
      return *this;
    }

    std::unique_ptr<ExposeDevToolsProtocolParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ExposeDevToolsProtocolParams;
    ExposeDevToolsProtocolParamsBuilder() : result_(new ExposeDevToolsProtocolParams()) { }

    template<int STEP> ExposeDevToolsProtocolParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ExposeDevToolsProtocolParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ExposeDevToolsProtocolParams> result_;
  };

  static ExposeDevToolsProtocolParamsBuilder<0> Builder() {
    return ExposeDevToolsProtocolParamsBuilder<0>();
  }

 private:
  ExposeDevToolsProtocolParams() { }

  std::string target_id_;
  base::Optional<std::string> binding_name_;

  DISALLOW_COPY_AND_ASSIGN(ExposeDevToolsProtocolParams);
};


// Result for the ExposeDevToolsProtocol command.
class HEADLESS_EXPORT ExposeDevToolsProtocolResult {
 public:
  static std::unique_ptr<ExposeDevToolsProtocolResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ExposeDevToolsProtocolResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ExposeDevToolsProtocolResult> Clone() const;

  template<int STATE>
  class ExposeDevToolsProtocolResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ExposeDevToolsProtocolResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ExposeDevToolsProtocolResult;
    ExposeDevToolsProtocolResultBuilder() : result_(new ExposeDevToolsProtocolResult()) { }

    template<int STEP> ExposeDevToolsProtocolResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ExposeDevToolsProtocolResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ExposeDevToolsProtocolResult> result_;
  };

  static ExposeDevToolsProtocolResultBuilder<0> Builder() {
    return ExposeDevToolsProtocolResultBuilder<0>();
  }

 private:
  ExposeDevToolsProtocolResult() { }


  DISALLOW_COPY_AND_ASSIGN(ExposeDevToolsProtocolResult);
};


// Parameters for the CreateBrowserContext command.
class HEADLESS_EXPORT CreateBrowserContextParams {
 public:
  static std::unique_ptr<CreateBrowserContextParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CreateBrowserContextParams() { }

  // If specified, disposes this context when debugging session disconnects.
  bool HasDisposeOnDetach() const { return !!dispose_on_detach_; }
  bool GetDisposeOnDetach() const { DCHECK(HasDisposeOnDetach()); return dispose_on_detach_.value(); }
  void SetDisposeOnDetach(bool value) { dispose_on_detach_ = value; }

  // Proxy server, similar to the one passed to --proxy-server
  bool HasProxyServer() const { return !!proxy_server_; }
  std::string GetProxyServer() const { DCHECK(HasProxyServer()); return proxy_server_.value(); }
  void SetProxyServer(const std::string& value) { proxy_server_ = value; }

  // Proxy bypass list, similar to the one passed to --proxy-bypass-list
  bool HasProxyBypassList() const { return !!proxy_bypass_list_; }
  std::string GetProxyBypassList() const { DCHECK(HasProxyBypassList()); return proxy_bypass_list_.value(); }
  void SetProxyBypassList(const std::string& value) { proxy_bypass_list_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CreateBrowserContextParams> Clone() const;

  template<int STATE>
  class CreateBrowserContextParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    CreateBrowserContextParamsBuilder<STATE>& SetDisposeOnDetach(bool value) {
      result_->SetDisposeOnDetach(value);
      return *this;
    }

    CreateBrowserContextParamsBuilder<STATE>& SetProxyServer(const std::string& value) {
      result_->SetProxyServer(value);
      return *this;
    }

    CreateBrowserContextParamsBuilder<STATE>& SetProxyBypassList(const std::string& value) {
      result_->SetProxyBypassList(value);
      return *this;
    }

    std::unique_ptr<CreateBrowserContextParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CreateBrowserContextParams;
    CreateBrowserContextParamsBuilder() : result_(new CreateBrowserContextParams()) { }

    template<int STEP> CreateBrowserContextParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CreateBrowserContextParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CreateBrowserContextParams> result_;
  };

  static CreateBrowserContextParamsBuilder<0> Builder() {
    return CreateBrowserContextParamsBuilder<0>();
  }

 private:
  CreateBrowserContextParams() { }

  base::Optional<bool> dispose_on_detach_;
  base::Optional<std::string> proxy_server_;
  base::Optional<std::string> proxy_bypass_list_;

  DISALLOW_COPY_AND_ASSIGN(CreateBrowserContextParams);
};


// Result for the CreateBrowserContext command.
class HEADLESS_EXPORT CreateBrowserContextResult {
 public:
  static std::unique_ptr<CreateBrowserContextResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CreateBrowserContextResult() { }

  // The id of the context created.
  std::string GetBrowserContextId() const { return browser_context_id_; }
  void SetBrowserContextId(const std::string& value) { browser_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CreateBrowserContextResult> Clone() const;

  template<int STATE>
  class CreateBrowserContextResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBrowserContextIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kBrowserContextIdSet | 0)
    };

    CreateBrowserContextResultBuilder<STATE | kBrowserContextIdSet>& SetBrowserContextId(const std::string& value) {
      static_assert(!(STATE & kBrowserContextIdSet), "property browserContextId should not have already been set");
      result_->SetBrowserContextId(value);
      return CastState<kBrowserContextIdSet>();
    }

    std::unique_ptr<CreateBrowserContextResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CreateBrowserContextResult;
    CreateBrowserContextResultBuilder() : result_(new CreateBrowserContextResult()) { }

    template<int STEP> CreateBrowserContextResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CreateBrowserContextResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CreateBrowserContextResult> result_;
  };

  static CreateBrowserContextResultBuilder<0> Builder() {
    return CreateBrowserContextResultBuilder<0>();
  }

 private:
  CreateBrowserContextResult() { }

  std::string browser_context_id_;

  DISALLOW_COPY_AND_ASSIGN(CreateBrowserContextResult);
};


// Parameters for the GetBrowserContexts command.
class HEADLESS_EXPORT GetBrowserContextsParams {
 public:
  static std::unique_ptr<GetBrowserContextsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetBrowserContextsParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetBrowserContextsParams> Clone() const;

  template<int STATE>
  class GetBrowserContextsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetBrowserContextsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetBrowserContextsParams;
    GetBrowserContextsParamsBuilder() : result_(new GetBrowserContextsParams()) { }

    template<int STEP> GetBrowserContextsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetBrowserContextsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetBrowserContextsParams> result_;
  };

  static GetBrowserContextsParamsBuilder<0> Builder() {
    return GetBrowserContextsParamsBuilder<0>();
  }

 private:
  GetBrowserContextsParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetBrowserContextsParams);
};


// Result for the GetBrowserContexts command.
class HEADLESS_EXPORT GetBrowserContextsResult {
 public:
  static std::unique_ptr<GetBrowserContextsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetBrowserContextsResult() { }

  // An array of browser context ids.
  const std::vector<std::string>* GetBrowserContextIds() const { return &browser_context_ids_; }
  void SetBrowserContextIds(std::vector<std::string> value) { browser_context_ids_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetBrowserContextsResult> Clone() const;

  template<int STATE>
  class GetBrowserContextsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBrowserContextIdsSet = 1 << 1,
      kAllRequiredFieldsSet = (kBrowserContextIdsSet | 0)
    };

    GetBrowserContextsResultBuilder<STATE | kBrowserContextIdsSet>& SetBrowserContextIds(std::vector<std::string> value) {
      static_assert(!(STATE & kBrowserContextIdsSet), "property browserContextIds should not have already been set");
      result_->SetBrowserContextIds(std::move(value));
      return CastState<kBrowserContextIdsSet>();
    }

    std::unique_ptr<GetBrowserContextsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetBrowserContextsResult;
    GetBrowserContextsResultBuilder() : result_(new GetBrowserContextsResult()) { }

    template<int STEP> GetBrowserContextsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetBrowserContextsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetBrowserContextsResult> result_;
  };

  static GetBrowserContextsResultBuilder<0> Builder() {
    return GetBrowserContextsResultBuilder<0>();
  }

 private:
  GetBrowserContextsResult() { }

  std::vector<std::string> browser_context_ids_;

  DISALLOW_COPY_AND_ASSIGN(GetBrowserContextsResult);
};


// Parameters for the CreateTarget command.
class HEADLESS_EXPORT CreateTargetParams {
 public:
  static std::unique_ptr<CreateTargetParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CreateTargetParams() { }

  // The initial URL the page will be navigated to.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Frame width in DIP (headless chrome only).
  bool HasWidth() const { return !!width_; }
  int GetWidth() const { DCHECK(HasWidth()); return width_.value(); }
  void SetWidth(int value) { width_ = value; }

  // Frame height in DIP (headless chrome only).
  bool HasHeight() const { return !!height_; }
  int GetHeight() const { DCHECK(HasHeight()); return height_.value(); }
  void SetHeight(int value) { height_ = value; }

  // The browser context to create the page in.
  bool HasBrowserContextId() const { return !!browser_context_id_; }
  std::string GetBrowserContextId() const { DCHECK(HasBrowserContextId()); return browser_context_id_.value(); }
  void SetBrowserContextId(const std::string& value) { browser_context_id_ = value; }

  // Whether BeginFrames for this target will be controlled via DevTools (headless chrome only,
  // not supported on MacOS yet, false by default).
  bool HasEnableBeginFrameControl() const { return !!enable_begin_frame_control_; }
  bool GetEnableBeginFrameControl() const { DCHECK(HasEnableBeginFrameControl()); return enable_begin_frame_control_.value(); }
  void SetEnableBeginFrameControl(bool value) { enable_begin_frame_control_ = value; }

  // Whether to create a new Window or Tab (chrome-only, false by default).
  bool HasNewWindow() const { return !!new_window_; }
  bool GetNewWindow() const { DCHECK(HasNewWindow()); return new_window_.value(); }
  void SetNewWindow(bool value) { new_window_ = value; }

  // Whether to create the target in background or foreground (chrome-only,
  // false by default).
  bool HasBackground() const { return !!background_; }
  bool GetBackground() const { DCHECK(HasBackground()); return background_.value(); }
  void SetBackground(bool value) { background_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CreateTargetParams> Clone() const;

  template<int STATE>
  class CreateTargetParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
      kAllRequiredFieldsSet = (kUrlSet | 0)
    };

    CreateTargetParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    CreateTargetParamsBuilder<STATE>& SetWidth(int value) {
      result_->SetWidth(value);
      return *this;
    }

    CreateTargetParamsBuilder<STATE>& SetHeight(int value) {
      result_->SetHeight(value);
      return *this;
    }

    CreateTargetParamsBuilder<STATE>& SetBrowserContextId(const std::string& value) {
      result_->SetBrowserContextId(value);
      return *this;
    }

    CreateTargetParamsBuilder<STATE>& SetEnableBeginFrameControl(bool value) {
      result_->SetEnableBeginFrameControl(value);
      return *this;
    }

    CreateTargetParamsBuilder<STATE>& SetNewWindow(bool value) {
      result_->SetNewWindow(value);
      return *this;
    }

    CreateTargetParamsBuilder<STATE>& SetBackground(bool value) {
      result_->SetBackground(value);
      return *this;
    }

    std::unique_ptr<CreateTargetParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CreateTargetParams;
    CreateTargetParamsBuilder() : result_(new CreateTargetParams()) { }

    template<int STEP> CreateTargetParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CreateTargetParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CreateTargetParams> result_;
  };

  static CreateTargetParamsBuilder<0> Builder() {
    return CreateTargetParamsBuilder<0>();
  }

 private:
  CreateTargetParams() { }

  std::string url_;
  base::Optional<int> width_;
  base::Optional<int> height_;
  base::Optional<std::string> browser_context_id_;
  base::Optional<bool> enable_begin_frame_control_;
  base::Optional<bool> new_window_;
  base::Optional<bool> background_;

  DISALLOW_COPY_AND_ASSIGN(CreateTargetParams);
};


// Result for the CreateTarget command.
class HEADLESS_EXPORT CreateTargetResult {
 public:
  static std::unique_ptr<CreateTargetResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CreateTargetResult() { }

  // The id of the page opened.
  std::string GetTargetId() const { return target_id_; }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CreateTargetResult> Clone() const;

  template<int STATE>
  class CreateTargetResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kTargetIdSet | 0)
    };

    CreateTargetResultBuilder<STATE | kTargetIdSet>& SetTargetId(const std::string& value) {
      static_assert(!(STATE & kTargetIdSet), "property targetId should not have already been set");
      result_->SetTargetId(value);
      return CastState<kTargetIdSet>();
    }

    std::unique_ptr<CreateTargetResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CreateTargetResult;
    CreateTargetResultBuilder() : result_(new CreateTargetResult()) { }

    template<int STEP> CreateTargetResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CreateTargetResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CreateTargetResult> result_;
  };

  static CreateTargetResultBuilder<0> Builder() {
    return CreateTargetResultBuilder<0>();
  }

 private:
  CreateTargetResult() { }

  std::string target_id_;

  DISALLOW_COPY_AND_ASSIGN(CreateTargetResult);
};


// Parameters for the DetachFromTarget command.
class HEADLESS_EXPORT DetachFromTargetParams {
 public:
  static std::unique_ptr<DetachFromTargetParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DetachFromTargetParams() { }

  // Session to detach.
  bool HasSessionId() const { return !!session_id_; }
  std::string GetSessionId() const { DCHECK(HasSessionId()); return session_id_.value(); }
  void SetSessionId(const std::string& value) { session_id_ = value; }

  // Deprecated.
  bool HasTargetId() const { return !!target_id_; }
  std::string GetTargetId() const { DCHECK(HasTargetId()); return target_id_.value(); }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DetachFromTargetParams> Clone() const;

  template<int STATE>
  class DetachFromTargetParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    DetachFromTargetParamsBuilder<STATE>& SetSessionId(const std::string& value) {
      result_->SetSessionId(value);
      return *this;
    }

    DetachFromTargetParamsBuilder<STATE>& SetTargetId(const std::string& value) {
      result_->SetTargetId(value);
      return *this;
    }

    std::unique_ptr<DetachFromTargetParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DetachFromTargetParams;
    DetachFromTargetParamsBuilder() : result_(new DetachFromTargetParams()) { }

    template<int STEP> DetachFromTargetParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DetachFromTargetParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DetachFromTargetParams> result_;
  };

  static DetachFromTargetParamsBuilder<0> Builder() {
    return DetachFromTargetParamsBuilder<0>();
  }

 private:
  DetachFromTargetParams() { }

  base::Optional<std::string> session_id_;
  base::Optional<std::string> target_id_;

  DISALLOW_COPY_AND_ASSIGN(DetachFromTargetParams);
};


// Result for the DetachFromTarget command.
class HEADLESS_EXPORT DetachFromTargetResult {
 public:
  static std::unique_ptr<DetachFromTargetResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DetachFromTargetResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DetachFromTargetResult> Clone() const;

  template<int STATE>
  class DetachFromTargetResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DetachFromTargetResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DetachFromTargetResult;
    DetachFromTargetResultBuilder() : result_(new DetachFromTargetResult()) { }

    template<int STEP> DetachFromTargetResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DetachFromTargetResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DetachFromTargetResult> result_;
  };

  static DetachFromTargetResultBuilder<0> Builder() {
    return DetachFromTargetResultBuilder<0>();
  }

 private:
  DetachFromTargetResult() { }


  DISALLOW_COPY_AND_ASSIGN(DetachFromTargetResult);
};


// Parameters for the DisposeBrowserContext command.
class HEADLESS_EXPORT DisposeBrowserContextParams {
 public:
  static std::unique_ptr<DisposeBrowserContextParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisposeBrowserContextParams() { }

  std::string GetBrowserContextId() const { return browser_context_id_; }
  void SetBrowserContextId(const std::string& value) { browser_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisposeBrowserContextParams> Clone() const;

  template<int STATE>
  class DisposeBrowserContextParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBrowserContextIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kBrowserContextIdSet | 0)
    };

    DisposeBrowserContextParamsBuilder<STATE | kBrowserContextIdSet>& SetBrowserContextId(const std::string& value) {
      static_assert(!(STATE & kBrowserContextIdSet), "property browserContextId should not have already been set");
      result_->SetBrowserContextId(value);
      return CastState<kBrowserContextIdSet>();
    }

    std::unique_ptr<DisposeBrowserContextParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisposeBrowserContextParams;
    DisposeBrowserContextParamsBuilder() : result_(new DisposeBrowserContextParams()) { }

    template<int STEP> DisposeBrowserContextParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisposeBrowserContextParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisposeBrowserContextParams> result_;
  };

  static DisposeBrowserContextParamsBuilder<0> Builder() {
    return DisposeBrowserContextParamsBuilder<0>();
  }

 private:
  DisposeBrowserContextParams() { }

  std::string browser_context_id_;

  DISALLOW_COPY_AND_ASSIGN(DisposeBrowserContextParams);
};


// Result for the DisposeBrowserContext command.
class HEADLESS_EXPORT DisposeBrowserContextResult {
 public:
  static std::unique_ptr<DisposeBrowserContextResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisposeBrowserContextResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisposeBrowserContextResult> Clone() const;

  template<int STATE>
  class DisposeBrowserContextResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisposeBrowserContextResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisposeBrowserContextResult;
    DisposeBrowserContextResultBuilder() : result_(new DisposeBrowserContextResult()) { }

    template<int STEP> DisposeBrowserContextResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisposeBrowserContextResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisposeBrowserContextResult> result_;
  };

  static DisposeBrowserContextResultBuilder<0> Builder() {
    return DisposeBrowserContextResultBuilder<0>();
  }

 private:
  DisposeBrowserContextResult() { }


  DISALLOW_COPY_AND_ASSIGN(DisposeBrowserContextResult);
};


// Parameters for the GetTargetInfo command.
class HEADLESS_EXPORT GetTargetInfoParams {
 public:
  static std::unique_ptr<GetTargetInfoParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetTargetInfoParams() { }

  bool HasTargetId() const { return !!target_id_; }
  std::string GetTargetId() const { DCHECK(HasTargetId()); return target_id_.value(); }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetTargetInfoParams> Clone() const;

  template<int STATE>
  class GetTargetInfoParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GetTargetInfoParamsBuilder<STATE>& SetTargetId(const std::string& value) {
      result_->SetTargetId(value);
      return *this;
    }

    std::unique_ptr<GetTargetInfoParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetTargetInfoParams;
    GetTargetInfoParamsBuilder() : result_(new GetTargetInfoParams()) { }

    template<int STEP> GetTargetInfoParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetTargetInfoParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetTargetInfoParams> result_;
  };

  static GetTargetInfoParamsBuilder<0> Builder() {
    return GetTargetInfoParamsBuilder<0>();
  }

 private:
  GetTargetInfoParams() { }

  base::Optional<std::string> target_id_;

  DISALLOW_COPY_AND_ASSIGN(GetTargetInfoParams);
};


// Result for the GetTargetInfo command.
class HEADLESS_EXPORT GetTargetInfoResult {
 public:
  static std::unique_ptr<GetTargetInfoResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetTargetInfoResult() { }

  const ::headless::target::TargetInfo* GetTargetInfo() const { return target_info_.get(); }
  void SetTargetInfo(std::unique_ptr<::headless::target::TargetInfo> value) { target_info_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetTargetInfoResult> Clone() const;

  template<int STATE>
  class GetTargetInfoResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetInfoSet = 1 << 1,
      kAllRequiredFieldsSet = (kTargetInfoSet | 0)
    };

    GetTargetInfoResultBuilder<STATE | kTargetInfoSet>& SetTargetInfo(std::unique_ptr<::headless::target::TargetInfo> value) {
      static_assert(!(STATE & kTargetInfoSet), "property targetInfo should not have already been set");
      result_->SetTargetInfo(std::move(value));
      return CastState<kTargetInfoSet>();
    }

    std::unique_ptr<GetTargetInfoResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetTargetInfoResult;
    GetTargetInfoResultBuilder() : result_(new GetTargetInfoResult()) { }

    template<int STEP> GetTargetInfoResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetTargetInfoResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetTargetInfoResult> result_;
  };

  static GetTargetInfoResultBuilder<0> Builder() {
    return GetTargetInfoResultBuilder<0>();
  }

 private:
  GetTargetInfoResult() { }

  std::unique_ptr<::headless::target::TargetInfo> target_info_;

  DISALLOW_COPY_AND_ASSIGN(GetTargetInfoResult);
};


// Parameters for the GetTargets command.
class HEADLESS_EXPORT GetTargetsParams {
 public:
  static std::unique_ptr<GetTargetsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetTargetsParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetTargetsParams> Clone() const;

  template<int STATE>
  class GetTargetsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetTargetsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetTargetsParams;
    GetTargetsParamsBuilder() : result_(new GetTargetsParams()) { }

    template<int STEP> GetTargetsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetTargetsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetTargetsParams> result_;
  };

  static GetTargetsParamsBuilder<0> Builder() {
    return GetTargetsParamsBuilder<0>();
  }

 private:
  GetTargetsParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetTargetsParams);
};


// Result for the GetTargets command.
class HEADLESS_EXPORT GetTargetsResult {
 public:
  static std::unique_ptr<GetTargetsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetTargetsResult() { }

  // The list of targets.
  const std::vector<std::unique_ptr<::headless::target::TargetInfo>>* GetTargetInfos() const { return &target_infos_; }
  void SetTargetInfos(std::vector<std::unique_ptr<::headless::target::TargetInfo>> value) { target_infos_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetTargetsResult> Clone() const;

  template<int STATE>
  class GetTargetsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetInfosSet = 1 << 1,
      kAllRequiredFieldsSet = (kTargetInfosSet | 0)
    };

    GetTargetsResultBuilder<STATE | kTargetInfosSet>& SetTargetInfos(std::vector<std::unique_ptr<::headless::target::TargetInfo>> value) {
      static_assert(!(STATE & kTargetInfosSet), "property targetInfos should not have already been set");
      result_->SetTargetInfos(std::move(value));
      return CastState<kTargetInfosSet>();
    }

    std::unique_ptr<GetTargetsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetTargetsResult;
    GetTargetsResultBuilder() : result_(new GetTargetsResult()) { }

    template<int STEP> GetTargetsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetTargetsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetTargetsResult> result_;
  };

  static GetTargetsResultBuilder<0> Builder() {
    return GetTargetsResultBuilder<0>();
  }

 private:
  GetTargetsResult() { }

  std::vector<std::unique_ptr<::headless::target::TargetInfo>> target_infos_;

  DISALLOW_COPY_AND_ASSIGN(GetTargetsResult);
};


// Parameters for the SendMessageToTarget command.
class HEADLESS_EXPORT SendMessageToTargetParams {
 public:
  static std::unique_ptr<SendMessageToTargetParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SendMessageToTargetParams() { }

  std::string GetMessage() const { return message_; }
  void SetMessage(const std::string& value) { message_ = value; }

  // Identifier of the session.
  bool HasSessionId() const { return !!session_id_; }
  std::string GetSessionId() const { DCHECK(HasSessionId()); return session_id_.value(); }
  void SetSessionId(const std::string& value) { session_id_ = value; }

  // Deprecated.
  bool HasTargetId() const { return !!target_id_; }
  std::string GetTargetId() const { DCHECK(HasTargetId()); return target_id_.value(); }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SendMessageToTargetParams> Clone() const;

  template<int STATE>
  class SendMessageToTargetParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kMessageSet = 1 << 1,
      kAllRequiredFieldsSet = (kMessageSet | 0)
    };

    SendMessageToTargetParamsBuilder<STATE | kMessageSet>& SetMessage(const std::string& value) {
      static_assert(!(STATE & kMessageSet), "property message should not have already been set");
      result_->SetMessage(value);
      return CastState<kMessageSet>();
    }

    SendMessageToTargetParamsBuilder<STATE>& SetSessionId(const std::string& value) {
      result_->SetSessionId(value);
      return *this;
    }

    SendMessageToTargetParamsBuilder<STATE>& SetTargetId(const std::string& value) {
      result_->SetTargetId(value);
      return *this;
    }

    std::unique_ptr<SendMessageToTargetParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SendMessageToTargetParams;
    SendMessageToTargetParamsBuilder() : result_(new SendMessageToTargetParams()) { }

    template<int STEP> SendMessageToTargetParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SendMessageToTargetParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SendMessageToTargetParams> result_;
  };

  static SendMessageToTargetParamsBuilder<0> Builder() {
    return SendMessageToTargetParamsBuilder<0>();
  }

 private:
  SendMessageToTargetParams() { }

  std::string message_;
  base::Optional<std::string> session_id_;
  base::Optional<std::string> target_id_;

  DISALLOW_COPY_AND_ASSIGN(SendMessageToTargetParams);
};


// Result for the SendMessageToTarget command.
class HEADLESS_EXPORT SendMessageToTargetResult {
 public:
  static std::unique_ptr<SendMessageToTargetResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SendMessageToTargetResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SendMessageToTargetResult> Clone() const;

  template<int STATE>
  class SendMessageToTargetResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SendMessageToTargetResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SendMessageToTargetResult;
    SendMessageToTargetResultBuilder() : result_(new SendMessageToTargetResult()) { }

    template<int STEP> SendMessageToTargetResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SendMessageToTargetResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SendMessageToTargetResult> result_;
  };

  static SendMessageToTargetResultBuilder<0> Builder() {
    return SendMessageToTargetResultBuilder<0>();
  }

 private:
  SendMessageToTargetResult() { }


  DISALLOW_COPY_AND_ASSIGN(SendMessageToTargetResult);
};


// Parameters for the SetAutoAttach command.
class HEADLESS_EXPORT SetAutoAttachParams {
 public:
  static std::unique_ptr<SetAutoAttachParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetAutoAttachParams() { }

  // Whether to auto-attach to related targets.
  bool GetAutoAttach() const { return auto_attach_; }
  void SetAutoAttach(bool value) { auto_attach_ = value; }

  // Whether to pause new targets when attaching to them. Use `Runtime.runIfWaitingForDebugger`
  // to run paused targets.
  bool GetWaitForDebuggerOnStart() const { return wait_for_debugger_on_start_; }
  void SetWaitForDebuggerOnStart(bool value) { wait_for_debugger_on_start_ = value; }

  // Enables "flat" access to the session via specifying sessionId attribute in the commands.
  // We plan to make this the default, deprecate non-flattened mode,
  // and eventually retire it. See crbug.com/991325.
  bool HasFlatten() const { return !!flatten_; }
  bool GetFlatten() const { DCHECK(HasFlatten()); return flatten_.value(); }
  void SetFlatten(bool value) { flatten_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetAutoAttachParams> Clone() const;

  template<int STATE>
  class SetAutoAttachParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAutoAttachSet = 1 << 1,
    kWaitForDebuggerOnStartSet = 1 << 2,
      kAllRequiredFieldsSet = (kAutoAttachSet | kWaitForDebuggerOnStartSet | 0)
    };

    SetAutoAttachParamsBuilder<STATE | kAutoAttachSet>& SetAutoAttach(bool value) {
      static_assert(!(STATE & kAutoAttachSet), "property autoAttach should not have already been set");
      result_->SetAutoAttach(value);
      return CastState<kAutoAttachSet>();
    }

    SetAutoAttachParamsBuilder<STATE | kWaitForDebuggerOnStartSet>& SetWaitForDebuggerOnStart(bool value) {
      static_assert(!(STATE & kWaitForDebuggerOnStartSet), "property waitForDebuggerOnStart should not have already been set");
      result_->SetWaitForDebuggerOnStart(value);
      return CastState<kWaitForDebuggerOnStartSet>();
    }

    SetAutoAttachParamsBuilder<STATE>& SetFlatten(bool value) {
      result_->SetFlatten(value);
      return *this;
    }

    std::unique_ptr<SetAutoAttachParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetAutoAttachParams;
    SetAutoAttachParamsBuilder() : result_(new SetAutoAttachParams()) { }

    template<int STEP> SetAutoAttachParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetAutoAttachParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetAutoAttachParams> result_;
  };

  static SetAutoAttachParamsBuilder<0> Builder() {
    return SetAutoAttachParamsBuilder<0>();
  }

 private:
  SetAutoAttachParams() { }

  bool auto_attach_;
  bool wait_for_debugger_on_start_;
  base::Optional<bool> flatten_;

  DISALLOW_COPY_AND_ASSIGN(SetAutoAttachParams);
};


// Result for the SetAutoAttach command.
class HEADLESS_EXPORT SetAutoAttachResult {
 public:
  static std::unique_ptr<SetAutoAttachResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetAutoAttachResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetAutoAttachResult> Clone() const;

  template<int STATE>
  class SetAutoAttachResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetAutoAttachResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetAutoAttachResult;
    SetAutoAttachResultBuilder() : result_(new SetAutoAttachResult()) { }

    template<int STEP> SetAutoAttachResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetAutoAttachResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetAutoAttachResult> result_;
  };

  static SetAutoAttachResultBuilder<0> Builder() {
    return SetAutoAttachResultBuilder<0>();
  }

 private:
  SetAutoAttachResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetAutoAttachResult);
};


// Parameters for the SetDiscoverTargets command.
class HEADLESS_EXPORT SetDiscoverTargetsParams {
 public:
  static std::unique_ptr<SetDiscoverTargetsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDiscoverTargetsParams() { }

  // Whether to discover available targets.
  bool GetDiscover() const { return discover_; }
  void SetDiscover(bool value) { discover_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDiscoverTargetsParams> Clone() const;

  template<int STATE>
  class SetDiscoverTargetsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDiscoverSet = 1 << 1,
      kAllRequiredFieldsSet = (kDiscoverSet | 0)
    };

    SetDiscoverTargetsParamsBuilder<STATE | kDiscoverSet>& SetDiscover(bool value) {
      static_assert(!(STATE & kDiscoverSet), "property discover should not have already been set");
      result_->SetDiscover(value);
      return CastState<kDiscoverSet>();
    }

    std::unique_ptr<SetDiscoverTargetsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDiscoverTargetsParams;
    SetDiscoverTargetsParamsBuilder() : result_(new SetDiscoverTargetsParams()) { }

    template<int STEP> SetDiscoverTargetsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDiscoverTargetsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDiscoverTargetsParams> result_;
  };

  static SetDiscoverTargetsParamsBuilder<0> Builder() {
    return SetDiscoverTargetsParamsBuilder<0>();
  }

 private:
  SetDiscoverTargetsParams() { }

  bool discover_;

  DISALLOW_COPY_AND_ASSIGN(SetDiscoverTargetsParams);
};


// Result for the SetDiscoverTargets command.
class HEADLESS_EXPORT SetDiscoverTargetsResult {
 public:
  static std::unique_ptr<SetDiscoverTargetsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDiscoverTargetsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDiscoverTargetsResult> Clone() const;

  template<int STATE>
  class SetDiscoverTargetsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetDiscoverTargetsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDiscoverTargetsResult;
    SetDiscoverTargetsResultBuilder() : result_(new SetDiscoverTargetsResult()) { }

    template<int STEP> SetDiscoverTargetsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDiscoverTargetsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDiscoverTargetsResult> result_;
  };

  static SetDiscoverTargetsResultBuilder<0> Builder() {
    return SetDiscoverTargetsResultBuilder<0>();
  }

 private:
  SetDiscoverTargetsResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetDiscoverTargetsResult);
};


// Parameters for the SetRemoteLocations command.
class HEADLESS_EXPORT SetRemoteLocationsParams {
 public:
  static std::unique_ptr<SetRemoteLocationsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetRemoteLocationsParams() { }

  // List of remote locations.
  const std::vector<std::unique_ptr<::headless::target::RemoteLocation>>* GetLocations() const { return &locations_; }
  void SetLocations(std::vector<std::unique_ptr<::headless::target::RemoteLocation>> value) { locations_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetRemoteLocationsParams> Clone() const;

  template<int STATE>
  class SetRemoteLocationsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kLocationsSet = 1 << 1,
      kAllRequiredFieldsSet = (kLocationsSet | 0)
    };

    SetRemoteLocationsParamsBuilder<STATE | kLocationsSet>& SetLocations(std::vector<std::unique_ptr<::headless::target::RemoteLocation>> value) {
      static_assert(!(STATE & kLocationsSet), "property locations should not have already been set");
      result_->SetLocations(std::move(value));
      return CastState<kLocationsSet>();
    }

    std::unique_ptr<SetRemoteLocationsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetRemoteLocationsParams;
    SetRemoteLocationsParamsBuilder() : result_(new SetRemoteLocationsParams()) { }

    template<int STEP> SetRemoteLocationsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetRemoteLocationsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetRemoteLocationsParams> result_;
  };

  static SetRemoteLocationsParamsBuilder<0> Builder() {
    return SetRemoteLocationsParamsBuilder<0>();
  }

 private:
  SetRemoteLocationsParams() { }

  std::vector<std::unique_ptr<::headless::target::RemoteLocation>> locations_;

  DISALLOW_COPY_AND_ASSIGN(SetRemoteLocationsParams);
};


// Result for the SetRemoteLocations command.
class HEADLESS_EXPORT SetRemoteLocationsResult {
 public:
  static std::unique_ptr<SetRemoteLocationsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetRemoteLocationsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetRemoteLocationsResult> Clone() const;

  template<int STATE>
  class SetRemoteLocationsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetRemoteLocationsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetRemoteLocationsResult;
    SetRemoteLocationsResultBuilder() : result_(new SetRemoteLocationsResult()) { }

    template<int STEP> SetRemoteLocationsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetRemoteLocationsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetRemoteLocationsResult> result_;
  };

  static SetRemoteLocationsResultBuilder<0> Builder() {
    return SetRemoteLocationsResultBuilder<0>();
  }

 private:
  SetRemoteLocationsResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetRemoteLocationsResult);
};


// Parameters for the AttachedToTarget event.
class HEADLESS_EXPORT AttachedToTargetParams {
 public:
  static std::unique_ptr<AttachedToTargetParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AttachedToTargetParams() { }

  // Identifier assigned to the session used to send/receive messages.
  std::string GetSessionId() const { return session_id_; }
  void SetSessionId(const std::string& value) { session_id_ = value; }

  const ::headless::target::TargetInfo* GetTargetInfo() const { return target_info_.get(); }
  void SetTargetInfo(std::unique_ptr<::headless::target::TargetInfo> value) { target_info_ = std::move(value); }

  bool GetWaitingForDebugger() const { return waiting_for_debugger_; }
  void SetWaitingForDebugger(bool value) { waiting_for_debugger_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AttachedToTargetParams> Clone() const;

  template<int STATE>
  class AttachedToTargetParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSessionIdSet = 1 << 1,
    kTargetInfoSet = 1 << 2,
    kWaitingForDebuggerSet = 1 << 3,
      kAllRequiredFieldsSet = (kSessionIdSet | kTargetInfoSet | kWaitingForDebuggerSet | 0)
    };

    AttachedToTargetParamsBuilder<STATE | kSessionIdSet>& SetSessionId(const std::string& value) {
      static_assert(!(STATE & kSessionIdSet), "property sessionId should not have already been set");
      result_->SetSessionId(value);
      return CastState<kSessionIdSet>();
    }

    AttachedToTargetParamsBuilder<STATE | kTargetInfoSet>& SetTargetInfo(std::unique_ptr<::headless::target::TargetInfo> value) {
      static_assert(!(STATE & kTargetInfoSet), "property targetInfo should not have already been set");
      result_->SetTargetInfo(std::move(value));
      return CastState<kTargetInfoSet>();
    }

    AttachedToTargetParamsBuilder<STATE | kWaitingForDebuggerSet>& SetWaitingForDebugger(bool value) {
      static_assert(!(STATE & kWaitingForDebuggerSet), "property waitingForDebugger should not have already been set");
      result_->SetWaitingForDebugger(value);
      return CastState<kWaitingForDebuggerSet>();
    }

    std::unique_ptr<AttachedToTargetParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AttachedToTargetParams;
    AttachedToTargetParamsBuilder() : result_(new AttachedToTargetParams()) { }

    template<int STEP> AttachedToTargetParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AttachedToTargetParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AttachedToTargetParams> result_;
  };

  static AttachedToTargetParamsBuilder<0> Builder() {
    return AttachedToTargetParamsBuilder<0>();
  }

 private:
  AttachedToTargetParams() { }

  std::string session_id_;
  std::unique_ptr<::headless::target::TargetInfo> target_info_;
  bool waiting_for_debugger_;

  DISALLOW_COPY_AND_ASSIGN(AttachedToTargetParams);
};


// Parameters for the DetachedFromTarget event.
class HEADLESS_EXPORT DetachedFromTargetParams {
 public:
  static std::unique_ptr<DetachedFromTargetParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DetachedFromTargetParams() { }

  // Detached session identifier.
  std::string GetSessionId() const { return session_id_; }
  void SetSessionId(const std::string& value) { session_id_ = value; }

  // Deprecated.
  bool HasTargetId() const { return !!target_id_; }
  std::string GetTargetId() const { DCHECK(HasTargetId()); return target_id_.value(); }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DetachedFromTargetParams> Clone() const;

  template<int STATE>
  class DetachedFromTargetParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSessionIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSessionIdSet | 0)
    };

    DetachedFromTargetParamsBuilder<STATE | kSessionIdSet>& SetSessionId(const std::string& value) {
      static_assert(!(STATE & kSessionIdSet), "property sessionId should not have already been set");
      result_->SetSessionId(value);
      return CastState<kSessionIdSet>();
    }

    DetachedFromTargetParamsBuilder<STATE>& SetTargetId(const std::string& value) {
      result_->SetTargetId(value);
      return *this;
    }

    std::unique_ptr<DetachedFromTargetParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DetachedFromTargetParams;
    DetachedFromTargetParamsBuilder() : result_(new DetachedFromTargetParams()) { }

    template<int STEP> DetachedFromTargetParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DetachedFromTargetParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DetachedFromTargetParams> result_;
  };

  static DetachedFromTargetParamsBuilder<0> Builder() {
    return DetachedFromTargetParamsBuilder<0>();
  }

 private:
  DetachedFromTargetParams() { }

  std::string session_id_;
  base::Optional<std::string> target_id_;

  DISALLOW_COPY_AND_ASSIGN(DetachedFromTargetParams);
};


// Parameters for the ReceivedMessageFromTarget event.
class HEADLESS_EXPORT ReceivedMessageFromTargetParams {
 public:
  static std::unique_ptr<ReceivedMessageFromTargetParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReceivedMessageFromTargetParams() { }

  // Identifier of a session which sends a message.
  std::string GetSessionId() const { return session_id_; }
  void SetSessionId(const std::string& value) { session_id_ = value; }

  std::string GetMessage() const { return message_; }
  void SetMessage(const std::string& value) { message_ = value; }

  // Deprecated.
  bool HasTargetId() const { return !!target_id_; }
  std::string GetTargetId() const { DCHECK(HasTargetId()); return target_id_.value(); }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReceivedMessageFromTargetParams> Clone() const;

  template<int STATE>
  class ReceivedMessageFromTargetParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSessionIdSet = 1 << 1,
    kMessageSet = 1 << 2,
      kAllRequiredFieldsSet = (kSessionIdSet | kMessageSet | 0)
    };

    ReceivedMessageFromTargetParamsBuilder<STATE | kSessionIdSet>& SetSessionId(const std::string& value) {
      static_assert(!(STATE & kSessionIdSet), "property sessionId should not have already been set");
      result_->SetSessionId(value);
      return CastState<kSessionIdSet>();
    }

    ReceivedMessageFromTargetParamsBuilder<STATE | kMessageSet>& SetMessage(const std::string& value) {
      static_assert(!(STATE & kMessageSet), "property message should not have already been set");
      result_->SetMessage(value);
      return CastState<kMessageSet>();
    }

    ReceivedMessageFromTargetParamsBuilder<STATE>& SetTargetId(const std::string& value) {
      result_->SetTargetId(value);
      return *this;
    }

    std::unique_ptr<ReceivedMessageFromTargetParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReceivedMessageFromTargetParams;
    ReceivedMessageFromTargetParamsBuilder() : result_(new ReceivedMessageFromTargetParams()) { }

    template<int STEP> ReceivedMessageFromTargetParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReceivedMessageFromTargetParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReceivedMessageFromTargetParams> result_;
  };

  static ReceivedMessageFromTargetParamsBuilder<0> Builder() {
    return ReceivedMessageFromTargetParamsBuilder<0>();
  }

 private:
  ReceivedMessageFromTargetParams() { }

  std::string session_id_;
  std::string message_;
  base::Optional<std::string> target_id_;

  DISALLOW_COPY_AND_ASSIGN(ReceivedMessageFromTargetParams);
};


// Parameters for the TargetCreated event.
class HEADLESS_EXPORT TargetCreatedParams {
 public:
  static std::unique_ptr<TargetCreatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TargetCreatedParams() { }

  const ::headless::target::TargetInfo* GetTargetInfo() const { return target_info_.get(); }
  void SetTargetInfo(std::unique_ptr<::headless::target::TargetInfo> value) { target_info_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TargetCreatedParams> Clone() const;

  template<int STATE>
  class TargetCreatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetInfoSet = 1 << 1,
      kAllRequiredFieldsSet = (kTargetInfoSet | 0)
    };

    TargetCreatedParamsBuilder<STATE | kTargetInfoSet>& SetTargetInfo(std::unique_ptr<::headless::target::TargetInfo> value) {
      static_assert(!(STATE & kTargetInfoSet), "property targetInfo should not have already been set");
      result_->SetTargetInfo(std::move(value));
      return CastState<kTargetInfoSet>();
    }

    std::unique_ptr<TargetCreatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TargetCreatedParams;
    TargetCreatedParamsBuilder() : result_(new TargetCreatedParams()) { }

    template<int STEP> TargetCreatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TargetCreatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TargetCreatedParams> result_;
  };

  static TargetCreatedParamsBuilder<0> Builder() {
    return TargetCreatedParamsBuilder<0>();
  }

 private:
  TargetCreatedParams() { }

  std::unique_ptr<::headless::target::TargetInfo> target_info_;

  DISALLOW_COPY_AND_ASSIGN(TargetCreatedParams);
};


// Parameters for the TargetDestroyed event.
class HEADLESS_EXPORT TargetDestroyedParams {
 public:
  static std::unique_ptr<TargetDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TargetDestroyedParams() { }

  std::string GetTargetId() const { return target_id_; }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TargetDestroyedParams> Clone() const;

  template<int STATE>
  class TargetDestroyedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kTargetIdSet | 0)
    };

    TargetDestroyedParamsBuilder<STATE | kTargetIdSet>& SetTargetId(const std::string& value) {
      static_assert(!(STATE & kTargetIdSet), "property targetId should not have already been set");
      result_->SetTargetId(value);
      return CastState<kTargetIdSet>();
    }

    std::unique_ptr<TargetDestroyedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TargetDestroyedParams;
    TargetDestroyedParamsBuilder() : result_(new TargetDestroyedParams()) { }

    template<int STEP> TargetDestroyedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TargetDestroyedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TargetDestroyedParams> result_;
  };

  static TargetDestroyedParamsBuilder<0> Builder() {
    return TargetDestroyedParamsBuilder<0>();
  }

 private:
  TargetDestroyedParams() { }

  std::string target_id_;

  DISALLOW_COPY_AND_ASSIGN(TargetDestroyedParams);
};


// Parameters for the TargetCrashed event.
class HEADLESS_EXPORT TargetCrashedParams {
 public:
  static std::unique_ptr<TargetCrashedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TargetCrashedParams() { }

  std::string GetTargetId() const { return target_id_; }
  void SetTargetId(const std::string& value) { target_id_ = value; }

  // Termination status type.
  std::string GetStatus() const { return status_; }
  void SetStatus(const std::string& value) { status_ = value; }

  // Termination error code.
  int GetErrorCode() const { return error_code_; }
  void SetErrorCode(int value) { error_code_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TargetCrashedParams> Clone() const;

  template<int STATE>
  class TargetCrashedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetIdSet = 1 << 1,
    kStatusSet = 1 << 2,
    kErrorCodeSet = 1 << 3,
      kAllRequiredFieldsSet = (kTargetIdSet | kStatusSet | kErrorCodeSet | 0)
    };

    TargetCrashedParamsBuilder<STATE | kTargetIdSet>& SetTargetId(const std::string& value) {
      static_assert(!(STATE & kTargetIdSet), "property targetId should not have already been set");
      result_->SetTargetId(value);
      return CastState<kTargetIdSet>();
    }

    TargetCrashedParamsBuilder<STATE | kStatusSet>& SetStatus(const std::string& value) {
      static_assert(!(STATE & kStatusSet), "property status should not have already been set");
      result_->SetStatus(value);
      return CastState<kStatusSet>();
    }

    TargetCrashedParamsBuilder<STATE | kErrorCodeSet>& SetErrorCode(int value) {
      static_assert(!(STATE & kErrorCodeSet), "property errorCode should not have already been set");
      result_->SetErrorCode(value);
      return CastState<kErrorCodeSet>();
    }

    std::unique_ptr<TargetCrashedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TargetCrashedParams;
    TargetCrashedParamsBuilder() : result_(new TargetCrashedParams()) { }

    template<int STEP> TargetCrashedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TargetCrashedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TargetCrashedParams> result_;
  };

  static TargetCrashedParamsBuilder<0> Builder() {
    return TargetCrashedParamsBuilder<0>();
  }

 private:
  TargetCrashedParams() { }

  std::string target_id_;
  std::string status_;
  int error_code_;

  DISALLOW_COPY_AND_ASSIGN(TargetCrashedParams);
};


// Parameters for the TargetInfoChanged event.
class HEADLESS_EXPORT TargetInfoChangedParams {
 public:
  static std::unique_ptr<TargetInfoChangedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TargetInfoChangedParams() { }

  const ::headless::target::TargetInfo* GetTargetInfo() const { return target_info_.get(); }
  void SetTargetInfo(std::unique_ptr<::headless::target::TargetInfo> value) { target_info_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TargetInfoChangedParams> Clone() const;

  template<int STATE>
  class TargetInfoChangedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTargetInfoSet = 1 << 1,
      kAllRequiredFieldsSet = (kTargetInfoSet | 0)
    };

    TargetInfoChangedParamsBuilder<STATE | kTargetInfoSet>& SetTargetInfo(std::unique_ptr<::headless::target::TargetInfo> value) {
      static_assert(!(STATE & kTargetInfoSet), "property targetInfo should not have already been set");
      result_->SetTargetInfo(std::move(value));
      return CastState<kTargetInfoSet>();
    }

    std::unique_ptr<TargetInfoChangedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TargetInfoChangedParams;
    TargetInfoChangedParamsBuilder() : result_(new TargetInfoChangedParams()) { }

    template<int STEP> TargetInfoChangedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TargetInfoChangedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TargetInfoChangedParams> result_;
  };

  static TargetInfoChangedParamsBuilder<0> Builder() {
    return TargetInfoChangedParamsBuilder<0>();
  }

 private:
  TargetInfoChangedParams() { }

  std::unique_ptr<::headless::target::TargetInfo> target_info_;

  DISALLOW_COPY_AND_ASSIGN(TargetInfoChangedParams);
};


}  // namespace target

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_TARGET_H_
