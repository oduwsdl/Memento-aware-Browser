#ifndef THIRD_PARTY_OPENSCREEN_SRC_OSP_MSGS_OSP_MESSAGES_H_
#define THIRD_PARTY_OPENSCREEN_SRC_OSP_MSGS_OSP_MESSAGES_H_

#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "third_party/tinycbor/src/src/cbor.h"

namespace openscreen {
namespace msgs {

enum CborErrors {
  kParserEOF = -CborErrorUnexpectedEOF,
};

class CborEncodeBuffer;

struct AgentInfo {
  bool operator==(const AgentInfo& other) const;
  bool operator!=(const AgentInfo& other) const;

  std::string friendly_name;
  std::string model_name;
};

struct AgentInfoRequest {
  bool operator==(const AgentInfoRequest& other) const;
  bool operator!=(const AgentInfoRequest& other) const;

  uint64_t request_id;
};

struct AgentInfoResponse {
  // type key: 11
  bool operator==(const AgentInfoResponse& other) const;
  bool operator!=(const AgentInfoResponse& other) const;

  uint64_t request_id;
  AgentInfo agent_info;
};

struct Status {
  bool operator==(const Status& other) const;
  bool operator!=(const Status& other) const;

  std::string status;
};

struct AgentStatusRequest {
  // type key: 12
  bool operator==(const AgentStatusRequest& other) const;
  bool operator!=(const AgentStatusRequest& other) const;

  uint64_t request_id;
  bool has_status;
  Status status;
};

struct AgentStatusResponse {
  // type key: 13
  bool operator==(const AgentStatusResponse& other) const;
  bool operator!=(const AgentStatusResponse& other) const;

  uint64_t request_id;
  bool has_status;
  Status status;
};

enum class AuthenticationMechanism : uint64_t {
  kHkdfOfScryptOfPsk = 1ull,
};
inline std::ostream& operator<<(std::ostream& os, const AuthenticationMechanism& val) {
  switch (val) {
    case AuthenticationMechanism::kHkdfOfScryptOfPsk: os << "kHkdfOfScryptOfPsk"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}

struct AuthenticationRequest {
  // type key: 1001
  bool operator==(const AuthenticationRequest& other) const;
  bool operator!=(const AuthenticationRequest& other) const;

  uint64_t request_id;
  AuthenticationMechanism mechanism;
  std::vector<uint8_t> salt;
  uint64_t cost;
};

enum class AuthenticationResponseResult : uint64_t {
  kOk = 0ull,
  kUnknownError = 1ull,
  kMechanismUnknown = 2ull,
  kSaltTooSmall = 3ull,
  kCostTooLow = 4ull,
  kCostTooHigh = 5ull,
  kSecretUnknown = 6ull,
  kCalculationTookTooLong = 7ull,
};
inline std::ostream& operator<<(std::ostream& os, const AuthenticationResponseResult& val) {
  switch (val) {
    case AuthenticationResponseResult::kOk: os << "kOk"; break;
    case AuthenticationResponseResult::kUnknownError: os << "kUnknownError"; break;
    case AuthenticationResponseResult::kMechanismUnknown: os << "kMechanismUnknown"; break;
    case AuthenticationResponseResult::kSaltTooSmall: os << "kSaltTooSmall"; break;
    case AuthenticationResponseResult::kCostTooLow: os << "kCostTooLow"; break;
    case AuthenticationResponseResult::kCostTooHigh: os << "kCostTooHigh"; break;
    case AuthenticationResponseResult::kSecretUnknown: os << "kSecretUnknown"; break;
    case AuthenticationResponseResult::kCalculationTookTooLong: os << "kCalculationTookTooLong"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}

struct AuthenticationResponse {
  // type key: 1002
  bool operator==(const AuthenticationResponse& other) const;
  bool operator!=(const AuthenticationResponse& other) const;

  uint64_t request_id;
  AuthenticationResponseResult result;
  std::vector<uint8_t> proof;
};

enum class AuthenticationResultResult : uint64_t {
  kAuthenticated = 0ull,
  kUnknownError = 1ull,
  kProofInvalid = 2ull,
};
inline std::ostream& operator<<(std::ostream& os, const AuthenticationResultResult& val) {
  switch (val) {
    case AuthenticationResultResult::kAuthenticated: os << "kAuthenticated"; break;
    case AuthenticationResultResult::kUnknownError: os << "kUnknownError"; break;
    case AuthenticationResultResult::kProofInvalid: os << "kProofInvalid"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}

struct AuthenticationResult {
  // type key: 1003
  bool operator==(const AuthenticationResult& other) const;
  bool operator!=(const AuthenticationResult& other) const;

  AuthenticationResultResult result;
};

struct HttpHeader {
  bool operator==(const HttpHeader& other) const;
  bool operator!=(const HttpHeader& other) const;

  std::string key;
  std::string value;
};

enum class PresentationConnectionCloseEvent_reason : uint64_t {
  kCloseMethodCalled = 1ull,
  kConnectionObjectDiscarded = 10ull,
  kUnrecoverableErrorWhileSendingOrReceivingMessage = 100ull,
};
inline std::ostream& operator<<(std::ostream& os, const PresentationConnectionCloseEvent_reason& val) {
  switch (val) {
    case PresentationConnectionCloseEvent_reason::kCloseMethodCalled: os << "kCloseMethodCalled"; break;
    case PresentationConnectionCloseEvent_reason::kConnectionObjectDiscarded: os << "kConnectionObjectDiscarded"; break;
    case PresentationConnectionCloseEvent_reason::kUnrecoverableErrorWhileSendingOrReceivingMessage: os << "kUnrecoverableErrorWhileSendingOrReceivingMessage"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}

struct PresentationConnectionCloseEvent {
  // type key: 113
  bool operator==(const PresentationConnectionCloseEvent& other) const;
  bool operator!=(const PresentationConnectionCloseEvent& other) const;

  uint64_t connection_id;
  PresentationConnectionCloseEvent_reason reason;
  bool has_error_message;
  std::string error_message;
};

struct PresentationConnectionCloseRequest {
  // type key: 111
  bool operator==(const PresentationConnectionCloseRequest& other) const;
  bool operator!=(const PresentationConnectionCloseRequest& other) const;

  uint64_t request_id;
  uint64_t connection_id;
};

enum class PresentationConnectionCloseResponse_result : uint64_t {
  kSuccess = 0ull,
  kInvalidConnectionId = 1ull,
};
inline std::ostream& operator<<(std::ostream& os, const PresentationConnectionCloseResponse_result& val) {
  switch (val) {
    case PresentationConnectionCloseResponse_result::kSuccess: os << "kSuccess"; break;
    case PresentationConnectionCloseResponse_result::kInvalidConnectionId: os << "kInvalidConnectionId"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}

struct PresentationConnectionCloseResponse {
  // type key: 112
  bool operator==(const PresentationConnectionCloseResponse& other) const;
  bool operator!=(const PresentationConnectionCloseResponse& other) const;

  uint64_t request_id;
  PresentationConnectionCloseResponse_result result;
};

struct PresentationConnectionMessage {
  // type key: 16
  bool operator==(const PresentationConnectionMessage& other) const;
  bool operator!=(const PresentationConnectionMessage& other) const;

  uint64_t connection_id;
  struct Message {
    Message();
    ~Message();

  bool operator==(const Message& other) const;
  bool operator!=(const Message& other) const;

  enum class Which {
    kBytes,
    kString,
    kUninitialized,
  } which;
  union {
    std::vector<uint8_t> bytes;
    std::string str;
    bool placeholder_;
  };
  };
  Message message;
};

struct PresentationConnectionOpenRequest {
  // type key: 109
  bool operator==(const PresentationConnectionOpenRequest& other) const;
  bool operator!=(const PresentationConnectionOpenRequest& other) const;

  uint64_t request_id;
  std::string presentation_id;
  std::string url;
};

enum class Result : uint64_t {
  kSuccess = 1ull,
  kInvalidUrl = 10ull,
  kInvalidPresentationId = 11ull,
  kTimeout = 100ull,
  kTransientError = 101ull,
  kPermanentError = 102ull,
  kTerminating = 103ull,
  kUnknownError = 199ull,
};
inline std::ostream& operator<<(std::ostream& os, const Result& val) {
  switch (val) {
    case Result::kSuccess: os << "kSuccess"; break;
    case Result::kInvalidUrl: os << "kInvalidUrl"; break;
    case Result::kInvalidPresentationId: os << "kInvalidPresentationId"; break;
    case Result::kTimeout: os << "kTimeout"; break;
    case Result::kTransientError: os << "kTransientError"; break;
    case Result::kPermanentError: os << "kPermanentError"; break;
    case Result::kTerminating: os << "kTerminating"; break;
    case Result::kUnknownError: os << "kUnknownError"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}

enum class PresentationConnectionOpenResponse_result : uint64_t {
  kSuccess = 1ull,
  kInvalidUrl = 10ull,
  kInvalidPresentationId = 11ull,
  kTimeout = 100ull,
  kTransientError = 101ull,
  kPermanentError = 102ull,
  kTerminating = 103ull,
  kUnknownError = 199ull,
};
inline std::ostream& operator<<(std::ostream& os, const PresentationConnectionOpenResponse_result& val) {
  switch (val) {
    case PresentationConnectionOpenResponse_result::kSuccess: os << "kSuccess"; break;
    case PresentationConnectionOpenResponse_result::kInvalidUrl: os << "kInvalidUrl"; break;
    case PresentationConnectionOpenResponse_result::kInvalidPresentationId: os << "kInvalidPresentationId"; break;
    case PresentationConnectionOpenResponse_result::kTimeout: os << "kTimeout"; break;
    case PresentationConnectionOpenResponse_result::kTransientError: os << "kTransientError"; break;
    case PresentationConnectionOpenResponse_result::kPermanentError: os << "kPermanentError"; break;
    case PresentationConnectionOpenResponse_result::kTerminating: os << "kTerminating"; break;
    case PresentationConnectionOpenResponse_result::kUnknownError: os << "kUnknownError"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}
inline bool operator==(const PresentationConnectionOpenResponse_result& child, const Result& parent) {
  switch (child) {
    case PresentationConnectionOpenResponse_result::kSuccess: return parent == Result::kSuccess;
    case PresentationConnectionOpenResponse_result::kInvalidUrl: return parent == Result::kInvalidUrl;
    case PresentationConnectionOpenResponse_result::kInvalidPresentationId: return parent == Result::kInvalidPresentationId;
    case PresentationConnectionOpenResponse_result::kTimeout: return parent == Result::kTimeout;
    case PresentationConnectionOpenResponse_result::kTransientError: return parent == Result::kTransientError;
    case PresentationConnectionOpenResponse_result::kPermanentError: return parent == Result::kPermanentError;
    case PresentationConnectionOpenResponse_result::kTerminating: return parent == Result::kTerminating;
    case PresentationConnectionOpenResponse_result::kUnknownError: return parent == Result::kUnknownError;
    default: return false;
  }
}
inline bool operator==(const Result& parent, const PresentationConnectionOpenResponse_result& child) {
  return child == parent;
}
inline bool operator!=(const PresentationConnectionOpenResponse_result& child, const Result& parent) {
  return !(child == parent);
}
inline bool operator!=(const Result& parent, const PresentationConnectionOpenResponse_result& child) {
  return !(parent == child);
}

struct PresentationConnectionOpenResponse {
  // type key: 110
  bool operator==(const PresentationConnectionOpenResponse& other) const;
  bool operator!=(const PresentationConnectionOpenResponse& other) const;

  uint64_t request_id;
  PresentationConnectionOpenResponse_result result;
  uint64_t connection_id;
};

struct PresentationStartRequest {
  // type key: 104
  bool operator==(const PresentationStartRequest& other) const;
  bool operator!=(const PresentationStartRequest& other) const;

  uint64_t request_id;
  std::string presentation_id;
  std::string url;
  std::vector<HttpHeader> headers;
};

enum class PresentationStartResponse_result : uint64_t {
  kSuccess = 1ull,
  kInvalidUrl = 10ull,
  kInvalidPresentationId = 11ull,
  kTimeout = 100ull,
  kTransientError = 101ull,
  kPermanentError = 102ull,
  kTerminating = 103ull,
  kUnknownError = 199ull,
};
inline std::ostream& operator<<(std::ostream& os, const PresentationStartResponse_result& val) {
  switch (val) {
    case PresentationStartResponse_result::kSuccess: os << "kSuccess"; break;
    case PresentationStartResponse_result::kInvalidUrl: os << "kInvalidUrl"; break;
    case PresentationStartResponse_result::kInvalidPresentationId: os << "kInvalidPresentationId"; break;
    case PresentationStartResponse_result::kTimeout: os << "kTimeout"; break;
    case PresentationStartResponse_result::kTransientError: os << "kTransientError"; break;
    case PresentationStartResponse_result::kPermanentError: os << "kPermanentError"; break;
    case PresentationStartResponse_result::kTerminating: os << "kTerminating"; break;
    case PresentationStartResponse_result::kUnknownError: os << "kUnknownError"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}
inline bool operator==(const PresentationStartResponse_result& child, const Result& parent) {
  switch (child) {
    case PresentationStartResponse_result::kSuccess: return parent == Result::kSuccess;
    case PresentationStartResponse_result::kInvalidUrl: return parent == Result::kInvalidUrl;
    case PresentationStartResponse_result::kInvalidPresentationId: return parent == Result::kInvalidPresentationId;
    case PresentationStartResponse_result::kTimeout: return parent == Result::kTimeout;
    case PresentationStartResponse_result::kTransientError: return parent == Result::kTransientError;
    case PresentationStartResponse_result::kPermanentError: return parent == Result::kPermanentError;
    case PresentationStartResponse_result::kTerminating: return parent == Result::kTerminating;
    case PresentationStartResponse_result::kUnknownError: return parent == Result::kUnknownError;
    default: return false;
  }
}
inline bool operator==(const Result& parent, const PresentationStartResponse_result& child) {
  return child == parent;
}
inline bool operator!=(const PresentationStartResponse_result& child, const Result& parent) {
  return !(child == parent);
}
inline bool operator!=(const Result& parent, const PresentationStartResponse_result& child) {
  return !(parent == child);
}

struct PresentationStartResponse {
  // type key: 105
  bool operator==(const PresentationStartResponse& other) const;
  bool operator!=(const PresentationStartResponse& other) const;

  uint64_t request_id;
  PresentationStartResponse_result result;
  uint64_t connection_id;
};

enum class PresentationTerminationEvent_reason : uint64_t {
  kReceiverCalledTerminate = 1ull,
  kUserTerminatedViaReceiver = 2ull,
  kControllerCalledTerminate = 10ull,
  kUserTerminatedViaController = 11ull,
  kReceiverReplacedPresentation = 20ull,
  kReceiverIdleTooLong = 30ull,
  kReceiverAttemptedToNavigate = 31ull,
  kReceiverPoweringDown = 100ull,
  kReceiverCrashed = 101ull,
  kUnknown = 255ull,
};
inline std::ostream& operator<<(std::ostream& os, const PresentationTerminationEvent_reason& val) {
  switch (val) {
    case PresentationTerminationEvent_reason::kReceiverCalledTerminate: os << "kReceiverCalledTerminate"; break;
    case PresentationTerminationEvent_reason::kUserTerminatedViaReceiver: os << "kUserTerminatedViaReceiver"; break;
    case PresentationTerminationEvent_reason::kControllerCalledTerminate: os << "kControllerCalledTerminate"; break;
    case PresentationTerminationEvent_reason::kUserTerminatedViaController: os << "kUserTerminatedViaController"; break;
    case PresentationTerminationEvent_reason::kReceiverReplacedPresentation: os << "kReceiverReplacedPresentation"; break;
    case PresentationTerminationEvent_reason::kReceiverIdleTooLong: os << "kReceiverIdleTooLong"; break;
    case PresentationTerminationEvent_reason::kReceiverAttemptedToNavigate: os << "kReceiverAttemptedToNavigate"; break;
    case PresentationTerminationEvent_reason::kReceiverPoweringDown: os << "kReceiverPoweringDown"; break;
    case PresentationTerminationEvent_reason::kReceiverCrashed: os << "kReceiverCrashed"; break;
    case PresentationTerminationEvent_reason::kUnknown: os << "kUnknown"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}

struct PresentationTerminationEvent {
  // type key: 108
  bool operator==(const PresentationTerminationEvent& other) const;
  bool operator!=(const PresentationTerminationEvent& other) const;

  std::string presentation_id;
  PresentationTerminationEvent_reason reason;
};

enum class PresentationTerminationRequest_reason : uint64_t {
  kControllerCalledTerminate = 10ull,
  kUserTerminatedViaController = 11ull,
  kUnknown = 255ull,
};
inline std::ostream& operator<<(std::ostream& os, const PresentationTerminationRequest_reason& val) {
  switch (val) {
    case PresentationTerminationRequest_reason::kControllerCalledTerminate: os << "kControllerCalledTerminate"; break;
    case PresentationTerminationRequest_reason::kUserTerminatedViaController: os << "kUserTerminatedViaController"; break;
    case PresentationTerminationRequest_reason::kUnknown: os << "kUnknown"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}

struct PresentationTerminationRequest {
  // type key: 106
  bool operator==(const PresentationTerminationRequest& other) const;
  bool operator!=(const PresentationTerminationRequest& other) const;

  uint64_t request_id;
  std::string presentation_id;
  PresentationTerminationRequest_reason reason;
};

enum class PresentationTerminationResponse_result : uint64_t {
  kSuccess = 1ull,
  kInvalidUrl = 10ull,
  kInvalidPresentationId = 11ull,
  kTimeout = 100ull,
  kTransientError = 101ull,
  kPermanentError = 102ull,
  kTerminating = 103ull,
  kUnknownError = 199ull,
};
inline std::ostream& operator<<(std::ostream& os, const PresentationTerminationResponse_result& val) {
  switch (val) {
    case PresentationTerminationResponse_result::kSuccess: os << "kSuccess"; break;
    case PresentationTerminationResponse_result::kInvalidUrl: os << "kInvalidUrl"; break;
    case PresentationTerminationResponse_result::kInvalidPresentationId: os << "kInvalidPresentationId"; break;
    case PresentationTerminationResponse_result::kTimeout: os << "kTimeout"; break;
    case PresentationTerminationResponse_result::kTransientError: os << "kTransientError"; break;
    case PresentationTerminationResponse_result::kPermanentError: os << "kPermanentError"; break;
    case PresentationTerminationResponse_result::kTerminating: os << "kTerminating"; break;
    case PresentationTerminationResponse_result::kUnknownError: os << "kUnknownError"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}
inline bool operator==(const PresentationTerminationResponse_result& child, const Result& parent) {
  switch (child) {
    case PresentationTerminationResponse_result::kSuccess: return parent == Result::kSuccess;
    case PresentationTerminationResponse_result::kInvalidUrl: return parent == Result::kInvalidUrl;
    case PresentationTerminationResponse_result::kInvalidPresentationId: return parent == Result::kInvalidPresentationId;
    case PresentationTerminationResponse_result::kTimeout: return parent == Result::kTimeout;
    case PresentationTerminationResponse_result::kTransientError: return parent == Result::kTransientError;
    case PresentationTerminationResponse_result::kPermanentError: return parent == Result::kPermanentError;
    case PresentationTerminationResponse_result::kTerminating: return parent == Result::kTerminating;
    case PresentationTerminationResponse_result::kUnknownError: return parent == Result::kUnknownError;
    default: return false;
  }
}
inline bool operator==(const Result& parent, const PresentationTerminationResponse_result& child) {
  return child == parent;
}
inline bool operator!=(const PresentationTerminationResponse_result& child, const Result& parent) {
  return !(child == parent);
}
inline bool operator!=(const Result& parent, const PresentationTerminationResponse_result& child) {
  return !(parent == child);
}

struct PresentationTerminationResponse {
  // type key: 107
  bool operator==(const PresentationTerminationResponse& other) const;
  bool operator!=(const PresentationTerminationResponse& other) const;

  uint64_t request_id;
  PresentationTerminationResponse_result result;
};

enum class UrlAvailability : uint64_t {
  kAvailable = 0ull,
  kUnavailable = 1ull,
  kInvalid = 10ull,
};
inline std::ostream& operator<<(std::ostream& os, const UrlAvailability& val) {
  switch (val) {
    case UrlAvailability::kAvailable: os << "kAvailable"; break;
    case UrlAvailability::kUnavailable: os << "kUnavailable"; break;
    case UrlAvailability::kInvalid: os << "kInvalid"; break;
    default: os << "Unknown Value: " << static_cast<int>(val);
      break;
    }
  return os;
}

struct PresentationUrlAvailabilityEvent {
  // type key: 103
  bool operator==(const PresentationUrlAvailabilityEvent& other) const;
  bool operator!=(const PresentationUrlAvailabilityEvent& other) const;

  uint64_t watch_id;
  std::vector<UrlAvailability> url_availabilities;
};

struct PresentationUrlAvailabilityRequest {
  // type key: 14
  bool operator==(const PresentationUrlAvailabilityRequest& other) const;
  bool operator!=(const PresentationUrlAvailabilityRequest& other) const;

  uint64_t request_id;
  std::vector<std::string> urls;
  uint64_t watch_duration;
  uint64_t watch_id;
};

struct PresentationUrlAvailabilityResponse {
  // type key: 15
  bool operator==(const PresentationUrlAvailabilityResponse& other) const;
  bool operator!=(const PresentationUrlAvailabilityResponse& other) const;

  uint64_t request_id;
  std::vector<UrlAvailability> url_availabilities;
};

enum class Type : uint64_t {
    kUnknown = 0ull,
    kAgentInfoResponse = 11ull,
    kAgentStatusRequest = 12ull,
    kAgentStatusResponse = 13ull,
    kAuthenticationRequest = 1001ull,
    kAuthenticationResponse = 1002ull,
    kAuthenticationResult = 1003ull,
    kPresentationConnectionCloseEvent = 113ull,
    kPresentationConnectionCloseRequest = 111ull,
    kPresentationConnectionCloseResponse = 112ull,
    kPresentationConnectionMessage = 16ull,
    kPresentationConnectionOpenRequest = 109ull,
    kPresentationConnectionOpenResponse = 110ull,
    kPresentationStartRequest = 104ull,
    kPresentationStartResponse = 105ull,
    kPresentationTerminationEvent = 108ull,
    kPresentationTerminationRequest = 106ull,
    kPresentationTerminationResponse = 107ull,
    kPresentationUrlAvailabilityEvent = 103ull,
    kPresentationUrlAvailabilityRequest = 14ull,
    kPresentationUrlAvailabilityResponse = 15ull,
};

bool EncodeAgentInfoResponse(
    const AgentInfoResponse& data,
    CborEncodeBuffer* buffer);
ssize_t EncodeAgentInfoResponse(
    const AgentInfoResponse& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodeAgentInfoResponse(
    const uint8_t* buffer,
    size_t length,
    AgentInfoResponse* data);

bool EncodeAgentStatusRequest(
    const AgentStatusRequest& data,
    CborEncodeBuffer* buffer);
ssize_t EncodeAgentStatusRequest(
    const AgentStatusRequest& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodeAgentStatusRequest(
    const uint8_t* buffer,
    size_t length,
    AgentStatusRequest* data);

bool EncodeAgentStatusResponse(
    const AgentStatusResponse& data,
    CborEncodeBuffer* buffer);
ssize_t EncodeAgentStatusResponse(
    const AgentStatusResponse& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodeAgentStatusResponse(
    const uint8_t* buffer,
    size_t length,
    AgentStatusResponse* data);

bool EncodeAuthenticationRequest(
    const AuthenticationRequest& data,
    CborEncodeBuffer* buffer);
ssize_t EncodeAuthenticationRequest(
    const AuthenticationRequest& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodeAuthenticationRequest(
    const uint8_t* buffer,
    size_t length,
    AuthenticationRequest* data);

bool EncodeAuthenticationResponse(
    const AuthenticationResponse& data,
    CborEncodeBuffer* buffer);
ssize_t EncodeAuthenticationResponse(
    const AuthenticationResponse& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodeAuthenticationResponse(
    const uint8_t* buffer,
    size_t length,
    AuthenticationResponse* data);

bool EncodeAuthenticationResult(
    const AuthenticationResult& data,
    CborEncodeBuffer* buffer);
ssize_t EncodeAuthenticationResult(
    const AuthenticationResult& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodeAuthenticationResult(
    const uint8_t* buffer,
    size_t length,
    AuthenticationResult* data);

bool EncodePresentationConnectionCloseEvent(
    const PresentationConnectionCloseEvent& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationConnectionCloseEvent(
    const PresentationConnectionCloseEvent& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationConnectionCloseEvent(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionCloseEvent* data);

bool EncodePresentationConnectionCloseRequest(
    const PresentationConnectionCloseRequest& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationConnectionCloseRequest(
    const PresentationConnectionCloseRequest& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationConnectionCloseRequest(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionCloseRequest* data);

bool EncodePresentationConnectionCloseResponse(
    const PresentationConnectionCloseResponse& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationConnectionCloseResponse(
    const PresentationConnectionCloseResponse& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationConnectionCloseResponse(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionCloseResponse* data);

bool EncodePresentationConnectionMessage(
    const PresentationConnectionMessage& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationConnectionMessage(
    const PresentationConnectionMessage& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationConnectionMessage(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionMessage* data);

bool EncodePresentationConnectionOpenRequest(
    const PresentationConnectionOpenRequest& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationConnectionOpenRequest(
    const PresentationConnectionOpenRequest& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationConnectionOpenRequest(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionOpenRequest* data);

bool EncodePresentationConnectionOpenResponse(
    const PresentationConnectionOpenResponse& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationConnectionOpenResponse(
    const PresentationConnectionOpenResponse& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationConnectionOpenResponse(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionOpenResponse* data);

bool EncodePresentationStartRequest(
    const PresentationStartRequest& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationStartRequest(
    const PresentationStartRequest& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationStartRequest(
    const uint8_t* buffer,
    size_t length,
    PresentationStartRequest* data);

bool EncodePresentationStartResponse(
    const PresentationStartResponse& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationStartResponse(
    const PresentationStartResponse& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationStartResponse(
    const uint8_t* buffer,
    size_t length,
    PresentationStartResponse* data);

bool EncodePresentationTerminationEvent(
    const PresentationTerminationEvent& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationTerminationEvent(
    const PresentationTerminationEvent& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationTerminationEvent(
    const uint8_t* buffer,
    size_t length,
    PresentationTerminationEvent* data);

bool EncodePresentationTerminationRequest(
    const PresentationTerminationRequest& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationTerminationRequest(
    const PresentationTerminationRequest& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationTerminationRequest(
    const uint8_t* buffer,
    size_t length,
    PresentationTerminationRequest* data);

bool EncodePresentationTerminationResponse(
    const PresentationTerminationResponse& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationTerminationResponse(
    const PresentationTerminationResponse& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationTerminationResponse(
    const uint8_t* buffer,
    size_t length,
    PresentationTerminationResponse* data);

bool EncodePresentationUrlAvailabilityEvent(
    const PresentationUrlAvailabilityEvent& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationUrlAvailabilityEvent(
    const PresentationUrlAvailabilityEvent& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationUrlAvailabilityEvent(
    const uint8_t* buffer,
    size_t length,
    PresentationUrlAvailabilityEvent* data);

bool EncodePresentationUrlAvailabilityRequest(
    const PresentationUrlAvailabilityRequest& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationUrlAvailabilityRequest(
    const PresentationUrlAvailabilityRequest& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationUrlAvailabilityRequest(
    const uint8_t* buffer,
    size_t length,
    PresentationUrlAvailabilityRequest* data);

bool EncodePresentationUrlAvailabilityResponse(
    const PresentationUrlAvailabilityResponse& data,
    CborEncodeBuffer* buffer);
ssize_t EncodePresentationUrlAvailabilityResponse(
    const PresentationUrlAvailabilityResponse& data,
    uint8_t* buffer,
    size_t length);
ssize_t DecodePresentationUrlAvailabilityResponse(
    const uint8_t* buffer,
    size_t length,
    PresentationUrlAvailabilityResponse* data);

class TypeEnumValidator {
 public:
  static Type SafeCast(uint64_t type_id);
};

class CborEncodeBuffer {
 public:
  static constexpr size_t kDefaultInitialEncodeBufferSize = 250;
  static constexpr size_t kDefaultMaxEncodeBufferSize = 64000;

  CborEncodeBuffer();
  CborEncodeBuffer(size_t initial_size, size_t max_size);
  ~CborEncodeBuffer();

  bool Append(size_t length);
  bool ResizeBy(ssize_t length);
  bool SetType(const uint8_t encoded_id[], size_t size);

  const uint8_t* data() const { return data_.data(); }
  size_t size() const { return data_.size(); }

  uint8_t* Position() { return &data_[0] + position_; }
  size_t AvailableLength() { return data_.size() - position_; }

 private:
  size_t max_size_;
  size_t position_;
  std::vector<uint8_t> data_;
};

CborError ExpectKey(CborValue* it, const uint64_t key);
CborError ExpectKey(CborValue* it, const char* key, size_t key_length);

}  // namespace msgs
}  // namespace openscreen
#endif  // THIRD_PARTY_OPENSCREEN_SRC_OSP_MSGS_OSP_MESSAGES_H_