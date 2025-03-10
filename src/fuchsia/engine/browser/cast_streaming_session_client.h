// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FUCHSIA_ENGINE_BROWSER_CAST_STREAMING_SESSION_CLIENT_H_
#define FUCHSIA_ENGINE_BROWSER_CAST_STREAMING_SESSION_CLIENT_H_

#include <fuchsia/web/cpp/fidl.h>

#include "fuchsia/cast_streaming/public/cast_streaming_session.h"
#include "fuchsia/engine/cast_streaming_session.mojom.h"
#include "mojo/public/cpp/bindings/associated_remote.h"
#include "mojo/public/cpp/bindings/remote.h"

namespace media {
class MojoDecoderBufferWriter;
}  // namespace media

// Owns the CastStreamingSession and sends buffers to the renderer process via
// a Mojo service.
class CastStreamingSessionClient
    : public cast_streaming::CastStreamingSession::Client {
 public:
  explicit CastStreamingSessionClient(
      fidl::InterfaceRequest<fuchsia::web::MessagePort> message_port_request);
  ~CastStreamingSessionClient() final;

  CastStreamingSessionClient(const CastStreamingSessionClient&) = delete;
  CastStreamingSessionClient& operator=(const CastStreamingSessionClient&) =
      delete;

  void StartMojoConnection(mojo::AssociatedRemote<mojom::CastStreamingReceiver>
                               cast_streaming_receiver);

 private:
  // Handler for |cast_streaming_receiver_| disconnect.
  void OnMojoDisconnect();

  // Callback for mojom::CastStreamingReceiver::EnableReceiver()
  void OnReceiverEnabled();

  // cast_streaming::CastStreamingSession::Client implementation.
  void OnInitializationSuccess(
      base::Optional<media::AudioDecoderConfig> audio_decoder_config,
      base::Optional<media::VideoDecoderConfig> video_decoder_config) final;
  void OnInitializationFailure() final;
  void OnAudioFrameReceived(scoped_refptr<media::DecoderBuffer> buffer) final;
  void OnVideoFrameReceived(scoped_refptr<media::DecoderBuffer> buffer) final;
  void OnReceiverSessionEnded() final;

  fidl::InterfaceRequest<fuchsia::web::MessagePort> message_port_request_;
  mojo::AssociatedRemote<mojom::CastStreamingReceiver> cast_streaming_receiver_;
  cast_streaming::CastStreamingSession cast_streaming_session_;

  mojo::Remote<mojom::CastStreamingBufferReceiver> audio_remote_;
  std::unique_ptr<media::MojoDecoderBufferWriter> audio_buffer_writer_;

  mojo::Remote<mojom::CastStreamingBufferReceiver> video_remote_;
  std::unique_ptr<media::MojoDecoderBufferWriter> video_buffer_writer_;
};

#endif  // FUCHSIA_ENGINE_BROWSER_CAST_STREAMING_SESSION_CLIENT_H_
