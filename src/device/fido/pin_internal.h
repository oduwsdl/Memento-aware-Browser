// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file contains additional declarations for CTAP2 PIN support. Only
// implementations of the PIN protocol should need to include this file. For all
// other code, see |pin.h|.

#ifndef DEVICE_FIDO_PIN_INTERNAL_H_
#define DEVICE_FIDO_PIN_INTERNAL_H_

#include <stdint.h>

#include "components/cbor/values.h"
#include "device/fido/pin.h"
#include "third_party/boringssl/src/include/openssl/ec.h"
#include "third_party/boringssl/src/include/openssl/sha.h"

namespace device {
namespace pin {

// Subcommand enumerates the subcommands to the main |authenticatorClientPIN|
// command. See
// https://fidoalliance.org/specs/fido-v2.0-rd-20180702/fido-client-to-authenticator-protocol-v2.0-rd-20180702.html#authenticatorClientPIN
enum class Subcommand : uint8_t {
  kGetRetries = 0x01,
  kGetKeyAgreement = 0x02,
  kSetPIN = 0x03,
  kChangePIN = 0x04,
  kGetPINToken = 0x05,
  kGetUvToken = 0x06,
  kGetUvRetries = 0x07,
};

// RequestKey enumerates the keys in the top-level CBOR map for all PIN
// commands.
enum class RequestKey : int {
  kProtocol = 0x01,
  kSubcommand = 0x02,
  kKeyAgreement = 0x03,
  kPINAuth = 0x04,
  kNewPINEnc = 0x05,
  kPINHashEnc = 0x06,
  kMinPINLength = 0x07,
  kMinPINLengthRPIDs = 0x08,
  kPermissions = 0x09,
  kPermissionsRPID = 0x0A,
};

// Permission list flags. See
// https://drafts.fidoalliance.org/fido-2/stable-links-to-latest/fido-client-to-authenticator-protocol.html#permissions
enum class Permissions : uint8_t {
  kMakeCredential = 0x01,
  kGetAssertion = 0x02,
  kCredentialManagement = 0x04,
  kBioEnrollment = 0x08,
  kPlatformConfiguration = 0x10,
};

// ResponseKey enumerates the keys in the top-level CBOR map for all PIN
// responses.
enum class ResponseKey : int {
  kKeyAgreement = 1,
  kPINToken = 2,
  kRetries = 3,
  kUvRetries = 5,
};

// PointFromKeyAgreementResponse returns an |EC_POINT| that represents the same
// P-256 point as |response|. It returns |nullopt| if |response| encodes an
// invalid point.
base::Optional<bssl::UniquePtr<EC_POINT>> PointFromKeyAgreementResponse(
    const EC_GROUP* group,
    const KeyAgreementResponse& response);

// CalculateSharedKey writes the CTAP2 shared key between |key| and |peers_key|
// to |out_shared_key|.
void CalculateSharedKey(const EC_KEY* key,
                        const EC_POINT* peers_key,
                        uint8_t out_shared_key[SHA256_DIGEST_LENGTH]);

// EncodeCOSEPublicKey returns the public part of |key| as a COSE structure.
cbor::Value::MapValue EncodeCOSEPublicKey(const EC_KEY* key);

// Encrypt encrypts |plaintext| using |key|, writing the ciphertext to
// |out_ciphertext|. |plaintext| must be a whole number of AES blocks.
void Encrypt(const uint8_t key[SHA256_DIGEST_LENGTH],
             base::span<const uint8_t> plaintext,
             uint8_t* out_ciphertext);

// Decrypt AES-256 CBC decrypts some number of whole blocks from |ciphertext|
// into |plaintext|, using |key|.
void Decrypt(const uint8_t key[SHA256_DIGEST_LENGTH],
             base::span<const uint8_t> ciphertext,
             uint8_t* out_plaintext);

}  // namespace pin
}  // namespace device

#endif  // DEVICE_FIDO_PIN_INTERNAL_H_
