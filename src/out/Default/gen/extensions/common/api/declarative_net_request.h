// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/declarative_net_request.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_DECLARATIVE_NET_REQUEST_H__
#define EXTENSIONS_COMMON_API_DECLARATIVE_NET_REQUEST_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace declarative_net_request {

//
// Properties
//

// The maximum number of rules that an extension can specify across its enabled
// static rulesets. Any excess rules will be ignored and an install warning will
// be raised.
extern const int MAX_NUMBER_OF_RULES;

// The maximum number of dynamic rules that an extension can add.
extern const int MAX_NUMBER_OF_DYNAMIC_RULES;

// Time interval within which <code>MAX_GETMATCHEDRULES_CALLS_PER_INTERVAL
// getMatchedRules</code> calls can be made, specified in minutes. Additional
// calls will fail immediately and set $(ref:runtime.lastError). Note:
// <code>getMatchedRules</code> calls associated with a user gesture are exempt
// from the quota.
extern const int GETMATCHEDRULES_QUOTA_INTERVAL;

// The number of times <code>getMatchedRules</code> can be called within a
// period of <code>GETMATCHEDRULES_QUOTA_INTERVAL</code>.
extern const int MAX_GETMATCHEDRULES_CALLS_PER_INTERVAL;

// The maximum number of regular expression rules that an extension can add.
// This limit is evaluated separately for the set of dynamic rules and those
// specified in the rule resources file.
extern const int MAX_NUMBER_OF_REGEX_RULES;

// The maximum number of static <code>Rulesets</code> an extension can specify
// as part of the <code>"rule_resources"</code> manifest key.
extern const int MAX_NUMBER_OF_STATIC_RULESETS;

// Ruleset ID for the dynamic rules added by the extension.
extern const char DYNAMIC_RULESET_ID[];

//
// Types
//

// This describes the resource type of the network request.
enum ResourceType {
  RESOURCE_TYPE_NONE,
  RESOURCE_TYPE_MAIN_FRAME,
  RESOURCE_TYPE_SUB_FRAME,
  RESOURCE_TYPE_STYLESHEET,
  RESOURCE_TYPE_SCRIPT,
  RESOURCE_TYPE_IMAGE,
  RESOURCE_TYPE_FONT,
  RESOURCE_TYPE_OBJECT,
  RESOURCE_TYPE_XMLHTTPREQUEST,
  RESOURCE_TYPE_PING,
  RESOURCE_TYPE_CSP_REPORT,
  RESOURCE_TYPE_MEDIA,
  RESOURCE_TYPE_WEBSOCKET,
  RESOURCE_TYPE_OTHER,
  RESOURCE_TYPE_LAST = RESOURCE_TYPE_OTHER,
};


const char* ToString(ResourceType as_enum);
ResourceType ParseResourceType(const std::string& as_string);

// This describes whether the request is first or third party to the frame in
// which it originated. A request is said to be first party if it has the same
// domain (eTLD+1) as the frame in which the request originated.
enum DomainType {
  DOMAIN_TYPE_NONE,
  DOMAIN_TYPE_FIRSTPARTY,
  DOMAIN_TYPE_THIRDPARTY,
  DOMAIN_TYPE_LAST = DOMAIN_TYPE_THIRDPARTY,
};


const char* ToString(DomainType as_enum);
DomainType ParseDomainType(const std::string& as_string);

// This describes the possible operations for a "modifyHeaders" rule.
// TODO(crbug.com/947591): Add documentation once implementation is complete.
enum HeaderOperation {
  HEADER_OPERATION_NONE,
  HEADER_OPERATION_APPEND,
  HEADER_OPERATION_SET,
  HEADER_OPERATION_REMOVE,
  HEADER_OPERATION_LAST = HEADER_OPERATION_REMOVE,
};


const char* ToString(HeaderOperation as_enum);
HeaderOperation ParseHeaderOperation(const std::string& as_string);

// Describes the kind of action to take if a given RuleCondition matches.
enum RuleActionType {
  RULE_ACTION_TYPE_NONE,
  RULE_ACTION_TYPE_BLOCK,
  RULE_ACTION_TYPE_REDIRECT,
  RULE_ACTION_TYPE_ALLOW,
  RULE_ACTION_TYPE_UPGRADESCHEME,
  RULE_ACTION_TYPE_MODIFYHEADERS,
  RULE_ACTION_TYPE_ALLOWALLREQUESTS,
  RULE_ACTION_TYPE_LAST = RULE_ACTION_TYPE_ALLOWALLREQUESTS,
};


const char* ToString(RuleActionType as_enum);
RuleActionType ParseRuleActionType(const std::string& as_string);

struct Ruleset {
  Ruleset();
  ~Ruleset();
  Ruleset(Ruleset&& rhs);
  Ruleset& operator=(Ruleset&& rhs);

  // Populates a Ruleset object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Ruleset* out, base::string16* error);

  // Creates a Ruleset object from a base::Value, or NULL on failure.
  static std::unique_ptr<Ruleset> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Ruleset object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // A non-empty string uniquely identifying the ruleset. IDs beginning with '_'
  // are reserved for internal use.
  std::string id;

  // The path of the JSON ruleset relative to the extension directory.
  std::string path;

  // Whether the ruleset is enabled by default.
  bool enabled;


 private:
  DISALLOW_COPY_AND_ASSIGN(Ruleset);
};

struct QueryKeyValue {
  QueryKeyValue();
  ~QueryKeyValue();
  QueryKeyValue(QueryKeyValue&& rhs);
  QueryKeyValue& operator=(QueryKeyValue&& rhs);

  // Populates a QueryKeyValue object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, QueryKeyValue* out, base::string16* error);

  // Creates a QueryKeyValue object from a base::Value, or NULL on failure.
  static std::unique_ptr<QueryKeyValue> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this QueryKeyValue object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string key;

  std::string value;


 private:
  DISALLOW_COPY_AND_ASSIGN(QueryKeyValue);
};

struct QueryTransform {
  QueryTransform();
  ~QueryTransform();
  QueryTransform(QueryTransform&& rhs);
  QueryTransform& operator=(QueryTransform&& rhs);

  // Populates a QueryTransform object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, QueryTransform* out, base::string16* error);

  // Creates a QueryTransform object from a base::Value, or NULL on failure.
  static std::unique_ptr<QueryTransform> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this QueryTransform object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The list of query keys to be removed.
  std::unique_ptr<std::vector<std::string>> remove_params;

  // The list of query key-value pairs to be added or replaced.
  std::unique_ptr<std::vector<QueryKeyValue>> add_or_replace_params;


 private:
  DISALLOW_COPY_AND_ASSIGN(QueryTransform);
};

struct URLTransform {
  URLTransform();
  ~URLTransform();
  URLTransform(URLTransform&& rhs);
  URLTransform& operator=(URLTransform&& rhs);

  // Populates a URLTransform object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, URLTransform* out, base::string16* error);

  // Creates a URLTransform object from a base::Value, or NULL on failure.
  static std::unique_ptr<URLTransform> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this URLTransform object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The new scheme for the request. Allowed values are "http", "https", "ftp" and
  // "chrome-extension".
  std::unique_ptr<std::string> scheme;

  // The new host for the request.
  std::unique_ptr<std::string> host;

  // The new port for the request. If empty, the existing port is cleared.
  std::unique_ptr<std::string> port;

  // The new path for the request. If empty, the existing path is cleared.
  std::unique_ptr<std::string> path;

  // The new query for the request. Should be either empty, in which case the
  // existing query is cleared; or should begin with '?'.
  std::unique_ptr<std::string> query;

  // Add, remove or replace query key-value pairs.
  std::unique_ptr<QueryTransform> query_transform;

  // The new fragment for the request. Should be either empty, in which case the
  // existing fragment is cleared; or should begin with '#'.
  std::unique_ptr<std::string> fragment;

  // The new username for the request.
  std::unique_ptr<std::string> username;

  // The new password for the request.
  std::unique_ptr<std::string> password;


 private:
  DISALLOW_COPY_AND_ASSIGN(URLTransform);
};

struct Redirect {
  Redirect();
  ~Redirect();
  Redirect(Redirect&& rhs);
  Redirect& operator=(Redirect&& rhs);

  // Populates a Redirect object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Redirect* out, base::string16* error);

  // Creates a Redirect object from a base::Value, or NULL on failure.
  static std::unique_ptr<Redirect> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Redirect object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Path relative to the extension directory. Should start with '/'.
  std::unique_ptr<std::string> extension_path;

  // Url transformations to perform.
  std::unique_ptr<URLTransform> transform;

  // The redirect url. Redirects to JavaScript urls are not allowed.
  std::unique_ptr<std::string> url;

  // Substitution pattern for rules which specify a <code>regexFilter</code>. The
  // first match of <code>regexFilter</code> within the url will be replaced with
  // this pattern. Within <code>regexSubstitution</code>, backslash-escaped digits
  // (\1 to \9) can be used to insert the corresponding capture groups. \0 refers
  // to the entire matching text.
  std::unique_ptr<std::string> regex_substitution;


 private:
  DISALLOW_COPY_AND_ASSIGN(Redirect);
};

struct RuleCondition {
  RuleCondition();
  ~RuleCondition();
  RuleCondition(RuleCondition&& rhs);
  RuleCondition& operator=(RuleCondition&& rhs);

  // Populates a RuleCondition object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, RuleCondition* out, base::string16* error);

  // Creates a RuleCondition object from a base::Value, or NULL on failure.
  static std::unique_ptr<RuleCondition> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RuleCondition object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // <p>The pattern which is matched against the network request url. Supported
  // constructs:</p><p><b>'*'</b>  : Wildcard: Matches any number of
  // characters.</p><p><b>'|'</b>  : Left/right anchor: If used at either end of
  // the pattern,               specifies the beginning/end of the url
  // respectively.</p><p><b>'||'</b> : Domain name anchor: If used at the
  // beginning of the pattern,               specifies the start of a (sub-)domain
  // of the URL.</p><p><b>'^'</b>  : Separator character: This matches anything
  // except a letter, a               digit or one of the following: _ - . %. This
  // can also match               the end of the URL.</p><p>Therefore
  // <code>urlFilter</code> is composed of the following parts: (optional
  // Left/Domain name anchor) + pattern + (optional Right anchor).</p><p>If
  // omitted, all urls are matched. An empty string is not allowed.</p><p>A
  // pattern beginning with <code>||*</code> is not allowed. Use <code>*</code>
  // instead.</p><p>Note: Only one of <code>urlFilter</code> or
  // <code>regexFilter</code> can be specified.</p><p>Note: The
  // <code>urlFilter</code> must be composed of only ASCII characters. This is
  // matched against a url where the host is encoded in the punycode format (in
  // case of internationalized domains) and any other non-ascii characters are url
  // encoded in utf-8. For example, when the request url is http://abc.рф?q=ф,
  // the <code>urlFilter</code> will be matched against the url
  // http://abc.xn--p1ai/?q=%D1%84.</p>
  std::unique_ptr<std::string> url_filter;

  // <p>Regular expression to match against the network request url. This follows
  // the <a href = "https://github.com/google/re2/wiki/Syntax">RE2
  // syntax</a>.</p><p>Note: Only one of <code>urlFilter</code> or
  // <code>regexFilter</code> can be specified.</p><p>Note: The
  // <code>regexFilter</code> must be composed of only ASCII characters. This is
  // matched against a url where the host is encoded in the punycode format (in
  // case of internationalized domains) and any other non-ascii characters are url
  // encoded in utf-8.</p>
  std::unique_ptr<std::string> regex_filter;

  // Whether the <code>urlFilter</code> or <code>regexFilter</code> (whichever is
  // specified) is case sensitive. Default is true.
  std::unique_ptr<bool> is_url_filter_case_sensitive;

  // <p>The rule will only match network requests originating from the list of
  // <code>domains</code>. If the list is omitted, the rule is applied to requests
  // from all domains. An empty list is not allowed.</p><p>Note: sub-domains like
  // "a.example.com" are also allowed. The entries must consist of only ascii
  // characters. Use punycode encoding for internationalized domains.</p>
  std::unique_ptr<std::vector<std::string>> domains;

  // <p>The rule will not match network requests originating from the list of
  // <code> excludedDomains</code>. If the list is empty or omitted, no domains
  // are excluded. This takes precedence over <code> domains</code>.</p><p>Note:
  // sub-domains like "a.example.com" are also allowed. The entries must consist
  // of only ascii characters. Use punycode encoding for internationalized
  // domains.</p>
  std::unique_ptr<std::vector<std::string>> excluded_domains;

  // <p>List of resource types which the rule can match. An empty list is not
  // allowed.</p><p>Note: this must be specified for <code>allowAllRequests</code>
  // rules and may only include the <code>sub_frame</code> and
  // <code>main_frame</code> resource types.</p>
  std::unique_ptr<std::vector<ResourceType>> resource_types;

  // List of resource types which the rule won't match. Only one of
  // <code>resourceTypes</code> and <code>excludedResourceTypes</code> should be
  // specified. If neither of them is specified, all resource types except
  // "main_frame" are blocked.
  std::unique_ptr<std::vector<ResourceType>> excluded_resource_types;

  // Specifies whether the network request is first-party or third-party to the
  // domain from which it originated. If omitted, all requests are accepted.
  DomainType domain_type;


 private:
  DISALLOW_COPY_AND_ASSIGN(RuleCondition);
};

struct ModifyHeaderInfo {
  ModifyHeaderInfo();
  ~ModifyHeaderInfo();
  ModifyHeaderInfo(ModifyHeaderInfo&& rhs);
  ModifyHeaderInfo& operator=(ModifyHeaderInfo&& rhs);

  // Populates a ModifyHeaderInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ModifyHeaderInfo* out, base::string16* error);

  // Creates a ModifyHeaderInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ModifyHeaderInfo> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ModifyHeaderInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string header;

  HeaderOperation operation;

  std::unique_ptr<std::string> value;


 private:
  DISALLOW_COPY_AND_ASSIGN(ModifyHeaderInfo);
};

struct RuleAction {
  RuleAction();
  ~RuleAction();
  RuleAction(RuleAction&& rhs);
  RuleAction& operator=(RuleAction&& rhs);

  // Populates a RuleAction object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, RuleAction* out, base::string16* error);

  // Creates a RuleAction object from a base::Value, or NULL on failure.
  static std::unique_ptr<RuleAction> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RuleAction object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The type of action to perform.
  RuleActionType type;

  // Describes how the redirect should be performed. Only valid for redirect
  // rules.
  std::unique_ptr<Redirect> redirect;

  // The request headers to modify for the request. Only valid if RuleActionType
  // is "modifyHeaders". TODO(crbug.com/947591): Add documentation once
  // implementation is complete.
  std::unique_ptr<std::vector<ModifyHeaderInfo>> request_headers;

  // The response headers to modify for the request. Only valid if RuleActionType
  // is "modifyHeaders". TODO(crbug.com/947591): Add documentation once
  // implementation is complete.
  std::unique_ptr<std::vector<ModifyHeaderInfo>> response_headers;


 private:
  DISALLOW_COPY_AND_ASSIGN(RuleAction);
};

struct Rule {
  Rule();
  ~Rule();
  Rule(Rule&& rhs);
  Rule& operator=(Rule&& rhs);

  // Populates a Rule object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Rule* out, base::string16* error);

  // Creates a Rule object from a base::Value, or NULL on failure.
  static std::unique_ptr<Rule> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Rule object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // An id which uniquely identifies a rule. Mandatory and should be >= 1.
  int id;

  // Rule priority. Mandatory and should be >= 1. This is used to break ties
  // between multiple matching rules.
  std::unique_ptr<int> priority;

  // The condition under which this rule is triggered.
  RuleCondition condition;

  // The action to take if this rule is matched.
  RuleAction action;


 private:
  DISALLOW_COPY_AND_ASSIGN(Rule);
};

struct MatchedRule {
  MatchedRule();
  ~MatchedRule();
  MatchedRule(MatchedRule&& rhs);
  MatchedRule& operator=(MatchedRule&& rhs);

  // Populates a MatchedRule object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, MatchedRule* out, base::string16* error);

  // Creates a MatchedRule object from a base::Value, or NULL on failure.
  static std::unique_ptr<MatchedRule> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MatchedRule object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // A matching rule's ID.
  int rule_id;

  // ID of the $(ref:Ruleset) this rule belongs to. For a rule originating from
  // the set of dynamic rules, this will be equal to $(ref:DYNAMIC_RULESET_ID).
  std::string ruleset_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(MatchedRule);
};

struct MatchedRuleInfo {
  MatchedRuleInfo();
  ~MatchedRuleInfo();
  MatchedRuleInfo(MatchedRuleInfo&& rhs);
  MatchedRuleInfo& operator=(MatchedRuleInfo&& rhs);

  // Populates a MatchedRuleInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, MatchedRuleInfo* out, base::string16* error);

  // Creates a MatchedRuleInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<MatchedRuleInfo> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MatchedRuleInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  MatchedRule rule;

  // The time the rule was matched. Timestamps will correspond to the Javascript
  // convention for times, i.e. number of milliseconds since the epoch.
  double time_stamp;

  // The tabId of the tab from which the request originated if the tab is still
  // active. Else -1.
  int tab_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(MatchedRuleInfo);
};

struct MatchedRulesFilter {
  MatchedRulesFilter();
  ~MatchedRulesFilter();
  MatchedRulesFilter(MatchedRulesFilter&& rhs);
  MatchedRulesFilter& operator=(MatchedRulesFilter&& rhs);

  // Populates a MatchedRulesFilter object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, MatchedRulesFilter* out, base::string16* error);

  // Creates a MatchedRulesFilter object from a base::Value, or NULL on failure.
  static std::unique_ptr<MatchedRulesFilter> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MatchedRulesFilter object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // If specified, only matches rules for the given tab.
  std::unique_ptr<int> tab_id;

  // If specified, only matches rules after the given timestamp.
  std::unique_ptr<double> min_time_stamp;


 private:
  DISALLOW_COPY_AND_ASSIGN(MatchedRulesFilter);
};

struct RulesMatchedDetails {
  RulesMatchedDetails();
  ~RulesMatchedDetails();
  RulesMatchedDetails(RulesMatchedDetails&& rhs);
  RulesMatchedDetails& operator=(RulesMatchedDetails&& rhs);

  // Populates a RulesMatchedDetails object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, RulesMatchedDetails* out, base::string16* error);

  // Creates a RulesMatchedDetails object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<RulesMatchedDetails> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RulesMatchedDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Rules matching the given filter.
  std::vector<MatchedRuleInfo> rules_matched_info;


 private:
  DISALLOW_COPY_AND_ASSIGN(RulesMatchedDetails);
};

struct RequestDetails {
  RequestDetails();
  ~RequestDetails();
  RequestDetails(RequestDetails&& rhs);
  RequestDetails& operator=(RequestDetails&& rhs);

  // Populates a RequestDetails object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, RequestDetails* out, base::string16* error);

  // Creates a RequestDetails object from a base::Value, or NULL on failure.
  static std::unique_ptr<RequestDetails> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RequestDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the request. Request IDs are unique within a browser session.
  std::string request_id;

  // The URL of the request.
  std::string url;

  // The origin where the request was initiated. This does not change through
  // redirects. If this is an opaque origin, the string 'null' will be used.
  std::unique_ptr<std::string> initiator;

  // Standard HTTP method.
  std::string method;

  // The value 0 indicates that the request happens in the main frame; a positive
  // value indicates the ID of a subframe in which the request happens. If the
  // document of a (sub-)frame is loaded (<code>type</code> is
  // <code>main_frame</code> or <code>sub_frame</code>), <code>frameId</code>
  // indicates the ID of this frame, not the ID of the outer frame. Frame IDs are
  // unique within a tab.
  int frame_id;

  // ID of frame that wraps the frame which sent the request. Set to -1 if no
  // parent frame exists.
  int parent_frame_id;

  // The ID of the tab in which the request takes place. Set to -1 if the request
  // isn't related to a tab.
  int tab_id;

  // The resource type of the request.
  ResourceType type;


 private:
  DISALLOW_COPY_AND_ASSIGN(RequestDetails);
};

struct MatchedRuleInfoDebug {
  MatchedRuleInfoDebug();
  ~MatchedRuleInfoDebug();
  MatchedRuleInfoDebug(MatchedRuleInfoDebug&& rhs);
  MatchedRuleInfoDebug& operator=(MatchedRuleInfoDebug&& rhs);

  // Populates a MatchedRuleInfoDebug object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, MatchedRuleInfoDebug* out, base::string16* error);

  // Creates a MatchedRuleInfoDebug object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<MatchedRuleInfoDebug> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MatchedRuleInfoDebug object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  MatchedRule rule;

  // Details about the request for which the rule was matched.
  RequestDetails request;


 private:
  DISALLOW_COPY_AND_ASSIGN(MatchedRuleInfoDebug);
};


//
// Functions
//

namespace UpdateDynamicRules {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args, base::string16* error);
  ~Params();

  // The IDs of rules to remove.
  std::vector<int> rule_ids_to_remove;

  // The rules to add.
  std::vector<Rule> rules_to_add;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace UpdateDynamicRules

namespace GetDynamicRules {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Rule>& rules);
}  // namespace Results

}  // namespace GetDynamicRules

namespace UpdateEnabledRulesets {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args, base::string16* error);
  ~Params();

  // The set of ids corresponding to a static $(ref:Ruleset) that should be
  // disabled.
  std::vector<std::string> ruleset_ids_to_disable;

  // The set of ids corresponding to a static $(ref:Ruleset) that should be
  // enabled.
  std::vector<std::string> ruleset_ids_to_enable;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace UpdateEnabledRulesets

namespace GetEnabledRulesets {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& ruleset_ids);
}  // namespace Results

}  // namespace GetEnabledRulesets

namespace GetMatchedRules {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args, base::string16* error);
  ~Params();

  // An object to filter the list of matched rules.
  std::unique_ptr<MatchedRulesFilter> filter;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const RulesMatchedDetails& details);
}  // namespace Results

}  // namespace GetMatchedRules

namespace SetActionCountAsBadgeText {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args, base::string16* error);
  ~Params();

  bool enable;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetActionCountAsBadgeText

//
// Events
//

namespace OnRuleMatchedDebug {

extern const char kEventName[];  // "declarativeNetRequest.onRuleMatchedDebug"

// The rule that has been matched along with information about the associated
// request.
std::unique_ptr<base::ListValue> Create(const MatchedRuleInfoDebug& info);
}  // namespace OnRuleMatchedDebug

}  // namespace declarative_net_request
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_DECLARATIVE_NET_REQUEST_H__
