#include "third_party/openscreen/src/osp/msgs/osp_messages.h"

#include "third_party/tinycbor/src/src/utf8_p.h"
#include "util/osp_logging.h"

namespace openscreen {
namespace msgs {
namespace {

#define CBOR_RETURN_WHAT_ON_ERROR(stmt, what)                           \
  {                                                                     \
    CborError error = stmt;                                             \
    /* Encoder-specific errors, so it's fine to check these even in the \
     * parser.                                                          \
     */                                                                 \
    OSP_DCHECK_NE(error, CborErrorTooFewItems);                             \
    OSP_DCHECK_NE(error, CborErrorTooManyItems);                            \
    OSP_DCHECK_NE(error, CborErrorDataTooLarge);                            \
    if (error != CborNoError && error != CborErrorOutOfMemory)          \
      return what;                                                      \
  }
#define CBOR_RETURN_ON_ERROR_INTERNAL(stmt) \
  CBOR_RETURN_WHAT_ON_ERROR(stmt, error)
#define CBOR_RETURN_ON_ERROR(stmt) CBOR_RETURN_WHAT_ON_ERROR(stmt, -error)

#define EXPECT_KEY_CONSTANT(it, key) ExpectKey(it, key, sizeof(key) - 1)
#define EXPECT_INT_KEY_CONSTANT(it, key) ExpectKey(it, key)

bool IsValidUtf8(const std::string& s) {
  const uint8_t* buffer = reinterpret_cast<const uint8_t*>(s.data());
  const uint8_t* end = buffer + s.size();
  while (buffer < end) {
    // TODO(btolsch): This is an implementation detail of tinycbor so we should
    // eventually replace this call with our own utf8 validation.
    if (get_utf8(&buffer, end) == ~0u)
      return false;
  }
  return true;
}
}  // namespace

CborError ExpectKey(CborValue* it, const uint64_t key) {
  if  (!cbor_value_is_unsigned_integer(it))
    return CborErrorImproperValue;
  uint64_t observed_key;
  CBOR_RETURN_ON_ERROR_INTERNAL(cbor_value_get_uint64(it, &observed_key));
  if (observed_key != key)
    return CborErrorImproperValue;
  CBOR_RETURN_ON_ERROR_INTERNAL(cbor_value_advance_fixed(it));
  return CborNoError;
}

CborError ExpectKey(CborValue* it, const char* key, size_t key_length) {
  if(!cbor_value_is_text_string(it))
    return CborErrorImproperValue;
  size_t observed_length = 0;
  CBOR_RETURN_ON_ERROR_INTERNAL(
      cbor_value_get_string_length(it, &observed_length));
  if (observed_length != key_length)
    return CborErrorImproperValue;
  std::string observed_key(key_length, 0);
  CBOR_RETURN_ON_ERROR_INTERNAL(cbor_value_copy_text_string(
      it, const_cast<char*>(observed_key.data()), &observed_length, nullptr));
  if (observed_key != key)
    return CborErrorImproperValue;
  CBOR_RETURN_ON_ERROR_INTERNAL(cbor_value_advance(it));
  return CborNoError;
}

// static
constexpr size_t CborEncodeBuffer::kDefaultInitialEncodeBufferSize;

// static
constexpr size_t CborEncodeBuffer::kDefaultMaxEncodeBufferSize;

CborEncodeBuffer::CborEncodeBuffer()
    : max_size_(kDefaultMaxEncodeBufferSize),
      position_(0),
      data_(kDefaultInitialEncodeBufferSize) {}
CborEncodeBuffer::CborEncodeBuffer(size_t initial_size, size_t max_size)
    : max_size_(max_size), position_(0), data_(initial_size) {}
CborEncodeBuffer::~CborEncodeBuffer() = default;

bool CborEncodeBuffer::SetType(const uint8_t encoded_id[], size_t size) {
  if (this->AvailableLength() < size) {
    if (!this->ResizeBy(size)) {
      return false;
    }
  }
  memcpy(&data_[position_], encoded_id, size);
  position_ += size;
  return true;
}

bool CborEncodeBuffer::Append(size_t length) {
  if (length == 0)
    return false;
  if ((data_.size() + length) > max_size_) {
    length = max_size_ - data_.size();
    if (length == 0)
      return false;
  }
  size_t append_area = data_.size();
  data_.resize(append_area + length);
  position_ = append_area;
  return true;
}

bool CborEncodeBuffer::ResizeBy(ssize_t delta) {
  if (delta == 0)
    return true;
  if (delta < 0 && static_cast<size_t>(-delta) > data_.size())
    return false;
  if (delta > 0 && (data_.size() + delta) > max_size_)
    return false;
  data_.resize(data_.size() + delta);
  return true;
}

bool IsError(ssize_t x) {
  return x < 0;
}

bool EncodeAgentInfoResponse(
    const AgentInfoResponse& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0xb};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodeAgentInfoResponse(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodeAgentInfoResponse(
    const AgentInfoResponse& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CborEncoder encoder2;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder1, &encoder2, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder2, 0));
  if (!IsValidUtf8(data.agent_info.friendly_name)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder2, data.agent_info.friendly_name.c_str(), data.agent_info.friendly_name.size()));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder2, 1));
  if (!IsValidUtf8(data.agent_info.model_name)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder2, data.agent_info.model_name.c_str(), data.agent_info.model_name.size()));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder1, &encoder2));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodeAgentStatusRequest(
    const AgentStatusRequest& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0xc};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodeAgentStatusRequest(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodeAgentStatusRequest(
    const AgentStatusRequest& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  int num_optionals_present = data.has_status;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 1 + num_optionals_present));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  if (data.has_status) {
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CborEncoder encoder2;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder1, &encoder2, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder2, "status", sizeof("status") - 1));
  if (!IsValidUtf8(data.status.status)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder2, data.status.status.c_str(), data.status.status.size()));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder1, &encoder2));
  }
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodeAgentStatusResponse(
    const AgentStatusResponse& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0xd};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodeAgentStatusResponse(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodeAgentStatusResponse(
    const AgentStatusResponse& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  int num_optionals_present = data.has_status;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 1 + num_optionals_present));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  if (data.has_status) {
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CborEncoder encoder2;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder1, &encoder2, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder2, "status", sizeof("status") - 1));
  if (!IsValidUtf8(data.status.status)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder2, data.status.status.c_str(), data.status.status.size()));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder1, &encoder2));
  }
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodeAuthenticationRequest(
    const AuthenticationRequest& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x43, 0xe9};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodeAuthenticationRequest(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodeAuthenticationRequest(
    const AuthenticationRequest& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 4));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, static_cast<uint64_t>(data.mechanism)));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_byte_string(&encoder1, data.salt.data(), data.salt.size()));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 3));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.cost));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodeAuthenticationResponse(
    const AuthenticationResponse& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x43, 0xea};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodeAuthenticationResponse(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodeAuthenticationResponse(
    const AuthenticationResponse& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 3));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, static_cast<uint64_t>(data.result)));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_byte_string(&encoder1, data.proof.data(), data.proof.size()));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodeAuthenticationResult(
    const AuthenticationResult& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x43, 0xeb};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodeAuthenticationResult(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodeAuthenticationResult(
    const AuthenticationResult& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, static_cast<uint64_t>(data.result)));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationConnectionCloseEvent(
    const PresentationConnectionCloseEvent& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x40, 0x71};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationConnectionCloseEvent(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationConnectionCloseEvent(
    const PresentationConnectionCloseEvent& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  int num_optionals_present = data.has_error_message;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 2 + num_optionals_present));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.connection_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, static_cast<uint64_t>(data.reason)));
  if (data.has_error_message) {
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 3));
  if (!IsValidUtf8(data.error_message)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder1, data.error_message.c_str(), data.error_message.size()));
  }
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationConnectionCloseRequest(
    const PresentationConnectionCloseRequest& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x40, 0x6f};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationConnectionCloseRequest(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationConnectionCloseRequest(
    const PresentationConnectionCloseRequest& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.connection_id));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationConnectionCloseResponse(
    const PresentationConnectionCloseResponse& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x40, 0x70};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationConnectionCloseResponse(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationConnectionCloseResponse(
    const PresentationConnectionCloseResponse& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, static_cast<uint64_t>(data.result)));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

PresentationConnectionMessage::Message::Message()
    : which(Which::kUninitialized), placeholder_(false) {}

PresentationConnectionMessage::Message::~Message() {
  switch (which) {
  case Which::kBytes:
    bytes.std::vector<uint8_t>::~vector();
    break;
  case Which::kString:
    str.std::string::~basic_string();
    break;
 case Which::kUninitialized: break;
  }
}

bool EncodePresentationConnectionMessage(
    const PresentationConnectionMessage& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x10};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationConnectionMessage(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationConnectionMessage(
    const PresentationConnectionMessage& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.connection_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  switch (data.message.which) {
  case PresentationConnectionMessage::Message::Which::kBytes:
  CBOR_RETURN_ON_ERROR(cbor_encode_byte_string(&encoder1, data.message.bytes.data(), data.message.bytes.size()));
    break;
  case PresentationConnectionMessage::Message::Which::kString:
  if (!IsValidUtf8(data.message.str)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder1, data.message.str.c_str(), data.message.str.size()));
    break;
  case PresentationConnectionMessage::Message::Which::kUninitialized:
    return -CborUnknownError;
  }
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationConnectionOpenRequest(
    const PresentationConnectionOpenRequest& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x40, 0x6d};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationConnectionOpenRequest(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationConnectionOpenRequest(
    const PresentationConnectionOpenRequest& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 3));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  if (!IsValidUtf8(data.presentation_id)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder1, data.presentation_id.c_str(), data.presentation_id.size()));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  if (!IsValidUtf8(data.url)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder1, data.url.c_str(), data.url.size()));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationConnectionOpenResponse(
    const PresentationConnectionOpenResponse& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x40, 0x6e};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationConnectionOpenResponse(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationConnectionOpenResponse(
    const PresentationConnectionOpenResponse& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 3));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, static_cast<uint64_t>(data.result)));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.connection_id));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationStartRequest(
    const PresentationStartRequest& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x40, 0x68};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationStartRequest(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationStartRequest(
    const PresentationStartRequest& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 4));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  if (!IsValidUtf8(data.presentation_id)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder1, data.presentation_id.c_str(), data.presentation_id.size()));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  if (!IsValidUtf8(data.url)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder1, data.url.c_str(), data.url.size()));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 3));
  {
  CborEncoder encoder2;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_array(&encoder1, &encoder2, data.headers.size()));
  for (const auto& x : data.headers) {
  CborEncoder encoder3;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_array(&encoder2, &encoder3, 2));
  if (!IsValidUtf8(x.key)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder3, x.key.c_str(), x.key.size()));
  if (!IsValidUtf8(x.value)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder3, x.value.c_str(), x.value.size()));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder2, &encoder3));
  }
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder1, &encoder2));
  }
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationStartResponse(
    const PresentationStartResponse& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x40, 0x69};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationStartResponse(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationStartResponse(
    const PresentationStartResponse& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 3));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, static_cast<uint64_t>(data.result)));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.connection_id));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationTerminationEvent(
    const PresentationTerminationEvent& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x40, 0x6c};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationTerminationEvent(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationTerminationEvent(
    const PresentationTerminationEvent& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  if (!IsValidUtf8(data.presentation_id)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder1, data.presentation_id.c_str(), data.presentation_id.size()));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, static_cast<uint64_t>(data.reason)));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationTerminationRequest(
    const PresentationTerminationRequest& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x40, 0x6a};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationTerminationRequest(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationTerminationRequest(
    const PresentationTerminationRequest& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 3));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  if (!IsValidUtf8(data.presentation_id)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder1, data.presentation_id.c_str(), data.presentation_id.size()));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, static_cast<uint64_t>(data.reason)));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationTerminationResponse(
    const PresentationTerminationResponse& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x40, 0x6b};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationTerminationResponse(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationTerminationResponse(
    const PresentationTerminationResponse& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, static_cast<uint64_t>(data.result)));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationUrlAvailabilityEvent(
    const PresentationUrlAvailabilityEvent& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0x40, 0x67};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationUrlAvailabilityEvent(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationUrlAvailabilityEvent(
    const PresentationUrlAvailabilityEvent& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.watch_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  {
  CborEncoder encoder2;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_array(&encoder1, &encoder2, data.url_availabilities.size()));
  for (const auto& x : data.url_availabilities) {
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder2, static_cast<uint64_t>(x)));
  }
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder1, &encoder2));
  }
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationUrlAvailabilityRequest(
    const PresentationUrlAvailabilityRequest& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0xe};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationUrlAvailabilityRequest(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationUrlAvailabilityRequest(
    const PresentationUrlAvailabilityRequest& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 4));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  {
  CborEncoder encoder2;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_array(&encoder1, &encoder2, data.urls.size()));
  for (const auto& x : data.urls) {
  if (!IsValidUtf8(x)) {
    return -CborErrorInvalidUtf8TextString;
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_text_string(&encoder2, x.c_str(), x.size()));
  }
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder1, &encoder2));
  }
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.watch_duration));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 3));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.watch_id));
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

bool EncodePresentationUrlAvailabilityResponse(
    const PresentationUrlAvailabilityResponse& data,
    CborEncodeBuffer* buffer) {
  if (buffer->AvailableLength() == 0 &&
      !buffer->Append(CborEncodeBuffer::kDefaultInitialEncodeBufferSize))
    return false;
  const uint8_t type_id[] = {0xf};
  if(!buffer->SetType(type_id, sizeof(type_id))) {
    return false;
  }
  while (true) {
    size_t available_length = buffer->AvailableLength();
    ssize_t error_or_size = msgs::EncodePresentationUrlAvailabilityResponse(
        data, buffer->Position(), available_length);
    if (IsError(error_or_size)) {
      return false;
    } else if (error_or_size > static_cast<ssize_t>(available_length)) {
      if (!buffer->ResizeBy(error_or_size - available_length))
        return false;
    } else {
      buffer->ResizeBy(error_or_size - available_length);
      return true;
    }
  }
}

ssize_t EncodePresentationUrlAvailabilityResponse(
    const PresentationUrlAvailabilityResponse& data,
    uint8_t* buffer,
    size_t length) {
  CborEncoder encoder0;
  cbor_encoder_init(&encoder0, buffer, length, 0);
  CborEncoder encoder1;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_map(&encoder0, &encoder1, 2));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 0));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, data.request_id));
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder1, 1));
  {
  CborEncoder encoder2;
  CBOR_RETURN_ON_ERROR(cbor_encoder_create_array(&encoder1, &encoder2, data.url_availabilities.size()));
  for (const auto& x : data.url_availabilities) {
  CBOR_RETURN_ON_ERROR(cbor_encode_uint(&encoder2, static_cast<uint64_t>(x)));
  }
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder1, &encoder2));
  }
  CBOR_RETURN_ON_ERROR(cbor_encoder_close_container(&encoder0, &encoder1));
  size_t extra_bytes_needed = cbor_encoder_get_extra_bytes_needed(&encoder0);
  if (extra_bytes_needed) {
    return static_cast<ssize_t>(length + extra_bytes_needed);
  } else {
    return static_cast<ssize_t>(cbor_encoder_get_buffer_size(&encoder0, buffer));
  }
}

//static
Type TypeEnumValidator::SafeCast(uint64_t type_id) {
  switch (type_id) {
    case uint64_t{11}: return Type::kAgentInfoResponse;
    case uint64_t{12}: return Type::kAgentStatusRequest;
    case uint64_t{13}: return Type::kAgentStatusResponse;
    case uint64_t{1001}: return Type::kAuthenticationRequest;
    case uint64_t{1002}: return Type::kAuthenticationResponse;
    case uint64_t{1003}: return Type::kAuthenticationResult;
    case uint64_t{113}: return Type::kPresentationConnectionCloseEvent;
    case uint64_t{111}: return Type::kPresentationConnectionCloseRequest;
    case uint64_t{112}: return Type::kPresentationConnectionCloseResponse;
    case uint64_t{16}: return Type::kPresentationConnectionMessage;
    case uint64_t{109}: return Type::kPresentationConnectionOpenRequest;
    case uint64_t{110}: return Type::kPresentationConnectionOpenResponse;
    case uint64_t{104}: return Type::kPresentationStartRequest;
    case uint64_t{105}: return Type::kPresentationStartResponse;
    case uint64_t{108}: return Type::kPresentationTerminationEvent;
    case uint64_t{106}: return Type::kPresentationTerminationRequest;
    case uint64_t{107}: return Type::kPresentationTerminationResponse;
    case uint64_t{103}: return Type::kPresentationUrlAvailabilityEvent;
    case uint64_t{14}: return Type::kPresentationUrlAvailabilityRequest;
    case uint64_t{15}: return Type::kPresentationUrlAvailabilityResponse;
    default: return Type::kUnknown;
  }
}

ssize_t DecodeAgentInfoResponse(
    const uint8_t* buffer,
    size_t length,
    AgentInfoResponse* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 2) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  if (cbor_value_get_type(&it1) != CborMapType) {
    return -1;
  }
  CborValue it2;
  size_t it2_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it1, &it2_length));
  if (it2_length != 2) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it1, &it2));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it2, 0));
  size_t length0 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it2, CborValidateUtf8));
  if (cbor_value_is_length_known(&it2)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it2, &length0));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it2, &length0));
  }
  data->agent_info.friendly_name.resize(length0);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it2, const_cast<char*>(data->agent_info.friendly_name.data()), &length0, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it2));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it2, 1));
  size_t length1 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it2, CborValidateUtf8));
  if (cbor_value_is_length_known(&it2)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it2, &length1));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it2, &length1));
  }
  data->agent_info.model_name.resize(length1);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it2, const_cast<char*>(data->agent_info.model_name.data()), &length1, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it2));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it1, &it2));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodeAgentStatusRequest(
    const uint8_t* buffer,
    size_t length,
    AgentStatusRequest* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 2 && it1_length != 1) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  if (it1_length > 1) {
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
    data->has_status = true;
  if (cbor_value_get_type(&it1) != CborMapType) {
    return -1;
  }
  CborValue it2;
  size_t it2_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it1, &it2_length));
  if (it2_length != 1) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it1, &it2));
  CBOR_RETURN_ON_ERROR(EXPECT_KEY_CONSTANT(&it2, "status"));
  size_t length0 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it2, CborValidateUtf8));
  if (cbor_value_is_length_known(&it2)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it2, &length0));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it2, &length0));
  }
  data->status.status.resize(length0);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it2, const_cast<char*>(data->status.status.data()), &length0, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it2));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it1, &it2));
  } else {
    data->has_status = false;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodeAgentStatusResponse(
    const uint8_t* buffer,
    size_t length,
    AgentStatusResponse* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 2 && it1_length != 1) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  if (it1_length > 1) {
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
    data->has_status = true;
  if (cbor_value_get_type(&it1) != CborMapType) {
    return -1;
  }
  CborValue it2;
  size_t it2_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it1, &it2_length));
  if (it2_length != 1) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it1, &it2));
  CBOR_RETURN_ON_ERROR(EXPECT_KEY_CONSTANT(&it2, "status"));
  size_t length0 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it2, CborValidateUtf8));
  if (cbor_value_is_length_known(&it2)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it2, &length0));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it2, &length0));
  }
  data->status.status.resize(length0);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it2, const_cast<char*>(data->status.status.data()), &length0, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it2));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it1, &it2));
  } else {
    data->has_status = false;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodeAuthenticationRequest(
    const uint8_t* buffer,
    size_t length,
    AuthenticationRequest* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 4) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, reinterpret_cast<uint64_t*>(&data->mechanism)));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  size_t length0 = 0;  if (cbor_value_is_length_known(&it1)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it1, &length0));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it1, &length0));
  }
  data->salt.resize(length0);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_byte_string(&it1, const_cast<uint8_t*>(data->salt.data()), &length0, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 3));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->cost));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodeAuthenticationResponse(
    const uint8_t* buffer,
    size_t length,
    AuthenticationResponse* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 3) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, reinterpret_cast<uint64_t*>(&data->result)));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  size_t length0 = 0;  if (cbor_value_is_length_known(&it1)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it1, &length0));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it1, &length0));
  }
  data->proof.resize(length0);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_byte_string(&it1, const_cast<uint8_t*>(data->proof.data()), &length0, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodeAuthenticationResult(
    const uint8_t* buffer,
    size_t length,
    AuthenticationResult* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 1) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, reinterpret_cast<uint64_t*>(&data->result)));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationConnectionCloseEvent(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionCloseEvent* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 3 && it1_length != 2) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->connection_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, reinterpret_cast<uint64_t*>(&data->reason)));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  if (it1_length > 2) {
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 3));
    data->has_error_message = true;
  size_t length0 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it1, CborValidateUtf8));
  if (cbor_value_is_length_known(&it1)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it1, &length0));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it1, &length0));
  }
  data->error_message.resize(length0);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it1, const_cast<char*>(data->error_message.data()), &length0, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it1));
  } else {
    data->has_error_message = false;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationConnectionCloseRequest(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionCloseRequest* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 2) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->connection_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationConnectionCloseResponse(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionCloseResponse* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 2) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, reinterpret_cast<uint64_t*>(&data->result)));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationConnectionMessage(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionMessage* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 2) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->connection_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  CborType type0 = cbor_value_get_type(&it1);
  if (type0 == CborByteStringType) {
  data->message.which = decltype(data->message)::Which::kBytes;
  new (&data->message.bytes) std::vector<uint8_t>();
  size_t length1 = 0;  if (cbor_value_is_length_known(&it1)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it1, &length1));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it1, &length1));
  }
  data->message.bytes.resize(length1);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_byte_string(&it1, const_cast<uint8_t*>(data->message.bytes.data()), &length1, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it1));
  }
 else   if (type0 == CborTextStringType) {
  data->message.which = decltype(data->message)::Which::kString;
  new (&data->message.str) std::string();
  size_t length2 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it1, CborValidateUtf8));
  if (cbor_value_is_length_known(&it1)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it1, &length2));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it1, &length2));
  }
  data->message.str.resize(length2);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it1, const_cast<char*>(data->message.str.data()), &length2, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it1));
  }
 else { return -1; }
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationConnectionOpenRequest(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionOpenRequest* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 3) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  size_t length0 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it1, CborValidateUtf8));
  if (cbor_value_is_length_known(&it1)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it1, &length0));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it1, &length0));
  }
  data->presentation_id.resize(length0);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it1, const_cast<char*>(data->presentation_id.data()), &length0, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  size_t length1 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it1, CborValidateUtf8));
  if (cbor_value_is_length_known(&it1)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it1, &length1));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it1, &length1));
  }
  data->url.resize(length1);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it1, const_cast<char*>(data->url.data()), &length1, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationConnectionOpenResponse(
    const uint8_t* buffer,
    size_t length,
    PresentationConnectionOpenResponse* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 3) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, reinterpret_cast<uint64_t*>(&data->result)));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->connection_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationStartRequest(
    const uint8_t* buffer,
    size_t length,
    PresentationStartRequest* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 4) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  size_t length0 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it1, CborValidateUtf8));
  if (cbor_value_is_length_known(&it1)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it1, &length0));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it1, &length0));
  }
  data->presentation_id.resize(length0);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it1, const_cast<char*>(data->presentation_id.data()), &length0, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  size_t length1 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it1, CborValidateUtf8));
  if (cbor_value_is_length_known(&it1)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it1, &length1));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it1, &length1));
  }
  data->url.resize(length1);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it1, const_cast<char*>(data->url.data()), &length1, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 3));
  if (cbor_value_get_type(&it1) != CborArrayType) {
    return -1;
  }
  {
  CborValue it2;
  size_t it2_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_array_length(&it1, &it2_length));
  data->headers.resize(it2_length);
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it1, &it2));
  for (auto i = data->headers.begin(); i != data->headers.end(); ++i) {
  if (cbor_value_get_type(&it2) != CborArrayType) {
    return -1;
  }
  CborValue it3;
  size_t it3_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_array_length(&it2, &it3_length));
  if (it3_length != 2) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it2, &it3));
  size_t length2 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it3, CborValidateUtf8));
  if (cbor_value_is_length_known(&it3)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it3, &length2));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it3, &length2));
  }
  (*i).key.resize(length2);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it3, const_cast<char*>((*i).key.data()), &length2, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it3));
  size_t length3 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it3, CborValidateUtf8));
  if (cbor_value_is_length_known(&it3)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it3, &length3));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it3, &length3));
  }
  (*i).value.resize(length3);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it3, const_cast<char*>((*i).value.data()), &length3, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it3));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it2, &it3));
  }
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it1, &it2));
  }
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationStartResponse(
    const uint8_t* buffer,
    size_t length,
    PresentationStartResponse* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 3) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, reinterpret_cast<uint64_t*>(&data->result)));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->connection_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationTerminationEvent(
    const uint8_t* buffer,
    size_t length,
    PresentationTerminationEvent* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 2) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  size_t length0 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it1, CborValidateUtf8));
  if (cbor_value_is_length_known(&it1)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it1, &length0));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it1, &length0));
  }
  data->presentation_id.resize(length0);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it1, const_cast<char*>(data->presentation_id.data()), &length0, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, reinterpret_cast<uint64_t*>(&data->reason)));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationTerminationRequest(
    const uint8_t* buffer,
    size_t length,
    PresentationTerminationRequest* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 3) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  size_t length0 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it1, CborValidateUtf8));
  if (cbor_value_is_length_known(&it1)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it1, &length0));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it1, &length0));
  }
  data->presentation_id.resize(length0);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it1, const_cast<char*>(data->presentation_id.data()), &length0, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, reinterpret_cast<uint64_t*>(&data->reason)));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationTerminationResponse(
    const uint8_t* buffer,
    size_t length,
    PresentationTerminationResponse* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 2) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, reinterpret_cast<uint64_t*>(&data->result)));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationUrlAvailabilityEvent(
    const uint8_t* buffer,
    size_t length,
    PresentationUrlAvailabilityEvent* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 2) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->watch_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  if (cbor_value_get_type(&it1) != CborArrayType) {
    return -1;
  }
  {
  CborValue it2;
  size_t it2_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_array_length(&it1, &it2_length));
  data->url_availabilities.resize(it2_length);
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it1, &it2));
  for (auto i = data->url_availabilities.begin(); i != data->url_availabilities.end(); ++i) {
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it2, reinterpret_cast<uint64_t*>(&(*i))));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it2));
  }
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it1, &it2));
  }
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationUrlAvailabilityRequest(
    const uint8_t* buffer,
    size_t length,
    PresentationUrlAvailabilityRequest* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 4) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  if (cbor_value_get_type(&it1) != CborArrayType) {
    return -1;
  }
  {
  CborValue it2;
  size_t it2_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_array_length(&it1, &it2_length));
  data->urls.resize(it2_length);
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it1, &it2));
  for (auto i = data->urls.begin(); i != data->urls.end(); ++i) {
  size_t length0 = 0;  CBOR_RETURN_ON_ERROR(cbor_value_validate(&it2, CborValidateUtf8));
  if (cbor_value_is_length_known(&it2)) {
    CBOR_RETURN_ON_ERROR(cbor_value_get_string_length(&it2, &length0));
  } else {
    CBOR_RETURN_ON_ERROR(cbor_value_calculate_string_length(&it2, &length0));
  }
  (*i).resize(length0);
  CBOR_RETURN_ON_ERROR(cbor_value_copy_text_string(&it2, const_cast<char*>((*i).data()), &length0, nullptr));
  CBOR_RETURN_ON_ERROR(cbor_value_advance(&it2));
  }
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it1, &it2));
  }
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 2));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->watch_duration));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 3));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->watch_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

ssize_t DecodePresentationUrlAvailabilityResponse(
    const uint8_t* buffer,
    size_t length,
    PresentationUrlAvailabilityResponse* data) {
  CborParser parser;
  CborValue it0;
  CBOR_RETURN_ON_ERROR(cbor_parser_init(buffer, length, 0, &parser, &it0));
  if (cbor_value_get_type(&it0) != CborMapType) {
    return -1;
  }
  CborValue it1;
  size_t it1_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_map_length(&it0, &it1_length));
  if (it1_length != 2) {
    return -1;
  }
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it0, &it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 0));
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it1, &data->request_id));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it1));
  CBOR_RETURN_ON_ERROR(EXPECT_INT_KEY_CONSTANT(&it1, 1));
  if (cbor_value_get_type(&it1) != CborArrayType) {
    return -1;
  }
  {
  CborValue it2;
  size_t it2_length = 0;
  CBOR_RETURN_ON_ERROR(cbor_value_get_array_length(&it1, &it2_length));
  data->url_availabilities.resize(it2_length);
  CBOR_RETURN_ON_ERROR(cbor_value_enter_container(&it1, &it2));
  for (auto i = data->url_availabilities.begin(); i != data->url_availabilities.end(); ++i) {
  CBOR_RETURN_ON_ERROR(cbor_value_get_uint64(&it2, reinterpret_cast<uint64_t*>(&(*i))));
  CBOR_RETURN_ON_ERROR(cbor_value_advance_fixed(&it2));
  }
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it1, &it2));
  }
  CBOR_RETURN_ON_ERROR(cbor_value_leave_container(&it0, &it1));
  auto result = static_cast<ssize_t>(cbor_value_get_next_byte(&it0) - buffer);
  return result;
}

bool AgentInfo::operator==(const AgentInfo& other) const {
  return this->friendly_name == other.friendly_name &&
         this->model_name == other.model_name;
}
bool AgentInfo::operator!=(const AgentInfo& other) const {
  return !(*this == other);
}

bool AgentInfoRequest::operator==(const AgentInfoRequest& other) const {
  return this->request_id == other.request_id;
}
bool AgentInfoRequest::operator!=(const AgentInfoRequest& other) const {
  return !(*this == other);
}

bool AgentInfoResponse::operator==(const AgentInfoResponse& other) const {
  return this->request_id == other.request_id &&
         this->agent_info == other.agent_info;
}
bool AgentInfoResponse::operator!=(const AgentInfoResponse& other) const {
  return !(*this == other);
}

bool AgentStatusRequest::operator==(const AgentStatusRequest& other) const {
  return this->request_id == other.request_id &&
         this->status == other.status;
}
bool AgentStatusRequest::operator!=(const AgentStatusRequest& other) const {
  return !(*this == other);
}

bool AgentStatusResponse::operator==(const AgentStatusResponse& other) const {
  return this->request_id == other.request_id &&
         this->status == other.status;
}
bool AgentStatusResponse::operator!=(const AgentStatusResponse& other) const {
  return !(*this == other);
}

bool AuthenticationRequest::operator==(const AuthenticationRequest& other) const {
  return this->request_id == other.request_id &&
         this->mechanism == other.mechanism &&
         this->salt == other.salt &&
         this->cost == other.cost;
}
bool AuthenticationRequest::operator!=(const AuthenticationRequest& other) const {
  return !(*this == other);
}

bool AuthenticationResponse::operator==(const AuthenticationResponse& other) const {
  return this->request_id == other.request_id &&
         this->result == other.result &&
         this->proof == other.proof;
}
bool AuthenticationResponse::operator!=(const AuthenticationResponse& other) const {
  return !(*this == other);
}

bool AuthenticationResult::operator==(const AuthenticationResult& other) const {
  return this->result == other.result;
}
bool AuthenticationResult::operator!=(const AuthenticationResult& other) const {
  return !(*this == other);
}

bool HttpHeader::operator==(const HttpHeader& other) const {
  return this->key == other.key &&
         this->value == other.value;
}
bool HttpHeader::operator!=(const HttpHeader& other) const {
  return !(*this == other);
}

bool PresentationConnectionCloseEvent::operator==(const PresentationConnectionCloseEvent& other) const {
  return this->connection_id == other.connection_id &&
         this->reason == other.reason &&
         this->error_message == other.error_message;
}
bool PresentationConnectionCloseEvent::operator!=(const PresentationConnectionCloseEvent& other) const {
  return !(*this == other);
}

bool PresentationConnectionCloseRequest::operator==(const PresentationConnectionCloseRequest& other) const {
  return this->request_id == other.request_id &&
         this->connection_id == other.connection_id;
}
bool PresentationConnectionCloseRequest::operator!=(const PresentationConnectionCloseRequest& other) const {
  return !(*this == other);
}

bool PresentationConnectionCloseResponse::operator==(const PresentationConnectionCloseResponse& other) const {
  return this->request_id == other.request_id &&
         this->result == other.result;
}
bool PresentationConnectionCloseResponse::operator!=(const PresentationConnectionCloseResponse& other) const {
  return !(*this == other);
}

bool PresentationConnectionMessage::operator==(const PresentationConnectionMessage& other) const {
  return this->connection_id == other.connection_id &&
         this->message == other.message;
}
bool PresentationConnectionMessage::operator!=(const PresentationConnectionMessage& other) const {
  return !(*this == other);
}

bool PresentationConnectionMessage::Message::operator==(const PresentationConnectionMessage::Message& other) const {
  return this->which == other.which &&
         (this->which != Which::kBytes || this->bytes == other.bytes) &&
         (this->which != Which::kString || this->str == other.str);
}
bool PresentationConnectionMessage::Message::operator!=(const PresentationConnectionMessage::Message& other) const {
  return !(*this == other);
}

bool PresentationConnectionOpenRequest::operator==(const PresentationConnectionOpenRequest& other) const {
  return this->request_id == other.request_id &&
         this->presentation_id == other.presentation_id &&
         this->url == other.url;
}
bool PresentationConnectionOpenRequest::operator!=(const PresentationConnectionOpenRequest& other) const {
  return !(*this == other);
}

bool PresentationConnectionOpenResponse::operator==(const PresentationConnectionOpenResponse& other) const {
  return this->request_id == other.request_id &&
         this->result == other.result &&
         this->connection_id == other.connection_id;
}
bool PresentationConnectionOpenResponse::operator!=(const PresentationConnectionOpenResponse& other) const {
  return !(*this == other);
}

bool PresentationStartRequest::operator==(const PresentationStartRequest& other) const {
  return this->request_id == other.request_id &&
         this->presentation_id == other.presentation_id &&
         this->url == other.url &&
         this->headers == other.headers;
}
bool PresentationStartRequest::operator!=(const PresentationStartRequest& other) const {
  return !(*this == other);
}

bool PresentationStartResponse::operator==(const PresentationStartResponse& other) const {
  return this->request_id == other.request_id &&
         this->result == other.result &&
         this->connection_id == other.connection_id;
}
bool PresentationStartResponse::operator!=(const PresentationStartResponse& other) const {
  return !(*this == other);
}

bool PresentationTerminationEvent::operator==(const PresentationTerminationEvent& other) const {
  return this->presentation_id == other.presentation_id &&
         this->reason == other.reason;
}
bool PresentationTerminationEvent::operator!=(const PresentationTerminationEvent& other) const {
  return !(*this == other);
}

bool PresentationTerminationRequest::operator==(const PresentationTerminationRequest& other) const {
  return this->request_id == other.request_id &&
         this->presentation_id == other.presentation_id &&
         this->reason == other.reason;
}
bool PresentationTerminationRequest::operator!=(const PresentationTerminationRequest& other) const {
  return !(*this == other);
}

bool PresentationTerminationResponse::operator==(const PresentationTerminationResponse& other) const {
  return this->request_id == other.request_id &&
         this->result == other.result;
}
bool PresentationTerminationResponse::operator!=(const PresentationTerminationResponse& other) const {
  return !(*this == other);
}

bool PresentationUrlAvailabilityEvent::operator==(const PresentationUrlAvailabilityEvent& other) const {
  return this->watch_id == other.watch_id &&
         this->url_availabilities == other.url_availabilities;
}
bool PresentationUrlAvailabilityEvent::operator!=(const PresentationUrlAvailabilityEvent& other) const {
  return !(*this == other);
}

bool PresentationUrlAvailabilityRequest::operator==(const PresentationUrlAvailabilityRequest& other) const {
  return this->request_id == other.request_id &&
         this->urls == other.urls &&
         this->watch_duration == other.watch_duration &&
         this->watch_id == other.watch_id;
}
bool PresentationUrlAvailabilityRequest::operator!=(const PresentationUrlAvailabilityRequest& other) const {
  return !(*this == other);
}

bool PresentationUrlAvailabilityResponse::operator==(const PresentationUrlAvailabilityResponse& other) const {
  return this->request_id == other.request_id &&
         this->url_availabilities == other.url_availabilities;
}
bool PresentationUrlAvailabilityResponse::operator!=(const PresentationUrlAvailabilityResponse& other) const {
  return !(*this == other);
}

bool Status::operator==(const Status& other) const {
  return this->status == other.status;
}
bool Status::operator!=(const Status& other) const {
  return !(*this == other);
}

}  // namespace msgs
}  // namespace openscreen