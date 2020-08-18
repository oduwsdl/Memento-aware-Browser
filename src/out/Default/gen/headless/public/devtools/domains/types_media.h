// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_MEDIA_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_MEDIA_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_media.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace media {

// Have one type per entry in MediaLogRecord::Type
// Corresponds to kMessage
class HEADLESS_EXPORT PlayerMessage {
 public:
  static std::unique_ptr<PlayerMessage> Parse(const base::Value& value, ErrorReporter* errors);
  ~PlayerMessage() { }

  // Keep in sync with MediaLogMessageLevel
  // We are currently keeping the message level 'error' separate from the
  // PlayerError type because right now they represent different things,
  // this one being a DVLOG(ERROR) style log message that gets printed
  // based on what log level is selected in the UI, and the other is a
  // representation of a media::PipelineStatus object. Soon however we're
  // going to be moving away from using PipelineStatus for errors and
  // introducing a new error type which should hopefully let us integrate
  // the error log level into the PlayerError type.
  ::headless::media::PlayerMessageLevel GetLevel() const { return level_; }
  void SetLevel(::headless::media::PlayerMessageLevel value) { level_ = value; }

  std::string GetMessage() const { return message_; }
  void SetMessage(const std::string& value) { message_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PlayerMessage> Clone() const;

  template<int STATE>
  class PlayerMessageBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kLevelSet = 1 << 1,
    kMessageSet = 1 << 2,
      kAllRequiredFieldsSet = (kLevelSet | kMessageSet | 0)
    };

    PlayerMessageBuilder<STATE | kLevelSet>& SetLevel(::headless::media::PlayerMessageLevel value) {
      static_assert(!(STATE & kLevelSet), "property level should not have already been set");
      result_->SetLevel(value);
      return CastState<kLevelSet>();
    }

    PlayerMessageBuilder<STATE | kMessageSet>& SetMessage(const std::string& value) {
      static_assert(!(STATE & kMessageSet), "property message should not have already been set");
      result_->SetMessage(value);
      return CastState<kMessageSet>();
    }

    std::unique_ptr<PlayerMessage> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PlayerMessage;
    PlayerMessageBuilder() : result_(new PlayerMessage()) { }

    template<int STEP> PlayerMessageBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PlayerMessageBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PlayerMessage> result_;
  };

  static PlayerMessageBuilder<0> Builder() {
    return PlayerMessageBuilder<0>();
  }

 private:
  PlayerMessage() { }

  ::headless::media::PlayerMessageLevel level_;
  std::string message_;

  DISALLOW_COPY_AND_ASSIGN(PlayerMessage);
};


// Corresponds to kMediaPropertyChange
class HEADLESS_EXPORT PlayerProperty {
 public:
  static std::unique_ptr<PlayerProperty> Parse(const base::Value& value, ErrorReporter* errors);
  ~PlayerProperty() { }

  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PlayerProperty> Clone() const;

  template<int STATE>
  class PlayerPropertyBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kNameSet | kValueSet | 0)
    };

    PlayerPropertyBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    PlayerPropertyBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<PlayerProperty> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PlayerProperty;
    PlayerPropertyBuilder() : result_(new PlayerProperty()) { }

    template<int STEP> PlayerPropertyBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PlayerPropertyBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PlayerProperty> result_;
  };

  static PlayerPropertyBuilder<0> Builder() {
    return PlayerPropertyBuilder<0>();
  }

 private:
  PlayerProperty() { }

  std::string name_;
  std::string value_;

  DISALLOW_COPY_AND_ASSIGN(PlayerProperty);
};


// Corresponds to kMediaEventTriggered
class HEADLESS_EXPORT PlayerEvent {
 public:
  static std::unique_ptr<PlayerEvent> Parse(const base::Value& value, ErrorReporter* errors);
  ~PlayerEvent() { }

  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PlayerEvent> Clone() const;

  template<int STATE>
  class PlayerEventBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTimestampSet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kTimestampSet | kValueSet | 0)
    };

    PlayerEventBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    PlayerEventBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<PlayerEvent> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PlayerEvent;
    PlayerEventBuilder() : result_(new PlayerEvent()) { }

    template<int STEP> PlayerEventBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PlayerEventBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PlayerEvent> result_;
  };

  static PlayerEventBuilder<0> Builder() {
    return PlayerEventBuilder<0>();
  }

 private:
  PlayerEvent() { }

  double timestamp_;
  std::string value_;

  DISALLOW_COPY_AND_ASSIGN(PlayerEvent);
};


// Corresponds to kMediaError
class HEADLESS_EXPORT PlayerError {
 public:
  static std::unique_ptr<PlayerError> Parse(const base::Value& value, ErrorReporter* errors);
  ~PlayerError() { }

  ::headless::media::PlayerErrorType GetType() const { return type_; }
  void SetType(::headless::media::PlayerErrorType value) { type_ = value; }

  // When this switches to using media::Status instead of PipelineStatus
  // we can remove "errorCode" and replace it with the fields from
  // a Status instance. This also seems like a duplicate of the error
  // level enum - there is a todo bug to have that level removed and
  // use this instead. (crbug.com/1068454)
  std::string GetErrorCode() const { return error_code_; }
  void SetErrorCode(const std::string& value) { error_code_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PlayerError> Clone() const;

  template<int STATE>
  class PlayerErrorBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
    kErrorCodeSet = 1 << 2,
      kAllRequiredFieldsSet = (kTypeSet | kErrorCodeSet | 0)
    };

    PlayerErrorBuilder<STATE | kTypeSet>& SetType(::headless::media::PlayerErrorType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    PlayerErrorBuilder<STATE | kErrorCodeSet>& SetErrorCode(const std::string& value) {
      static_assert(!(STATE & kErrorCodeSet), "property errorCode should not have already been set");
      result_->SetErrorCode(value);
      return CastState<kErrorCodeSet>();
    }

    std::unique_ptr<PlayerError> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PlayerError;
    PlayerErrorBuilder() : result_(new PlayerError()) { }

    template<int STEP> PlayerErrorBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PlayerErrorBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PlayerError> result_;
  };

  static PlayerErrorBuilder<0> Builder() {
    return PlayerErrorBuilder<0>();
  }

 private:
  PlayerError() { }

  ::headless::media::PlayerErrorType type_;
  std::string error_code_;

  DISALLOW_COPY_AND_ASSIGN(PlayerError);
};


// Parameters for the Enable command.
class HEADLESS_EXPORT EnableParams {
 public:
  static std::unique_ptr<EnableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableParams;
    EnableParamsBuilder() : result_(new EnableParams()) { }

    template<int STEP> EnableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableParams> result_;
  };

  static EnableParamsBuilder<0> Builder() {
    return EnableParamsBuilder<0>();
  }

 private:
  EnableParams() { }


  DISALLOW_COPY_AND_ASSIGN(EnableParams);
};


// Result for the Enable command.
class HEADLESS_EXPORT EnableResult {
 public:
  static std::unique_ptr<EnableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableResult> Clone() const;

  template<int STATE>
  class EnableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableResult;
    EnableResultBuilder() : result_(new EnableResult()) { }

    template<int STEP> EnableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableResult> result_;
  };

  static EnableResultBuilder<0> Builder() {
    return EnableResultBuilder<0>();
  }

 private:
  EnableResult() { }


  DISALLOW_COPY_AND_ASSIGN(EnableResult);
};


// Parameters for the Disable command.
class HEADLESS_EXPORT DisableParams {
 public:
  static std::unique_ptr<DisableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableParams> Clone() const;

  template<int STATE>
  class DisableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableParams;
    DisableParamsBuilder() : result_(new DisableParams()) { }

    template<int STEP> DisableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableParams> result_;
  };

  static DisableParamsBuilder<0> Builder() {
    return DisableParamsBuilder<0>();
  }

 private:
  DisableParams() { }


  DISALLOW_COPY_AND_ASSIGN(DisableParams);
};


// Result for the Disable command.
class HEADLESS_EXPORT DisableResult {
 public:
  static std::unique_ptr<DisableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableResult> Clone() const;

  template<int STATE>
  class DisableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableResult;
    DisableResultBuilder() : result_(new DisableResult()) { }

    template<int STEP> DisableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableResult> result_;
  };

  static DisableResultBuilder<0> Builder() {
    return DisableResultBuilder<0>();
  }

 private:
  DisableResult() { }


  DISALLOW_COPY_AND_ASSIGN(DisableResult);
};


// Parameters for the PlayerPropertiesChanged event.
class HEADLESS_EXPORT PlayerPropertiesChangedParams {
 public:
  static std::unique_ptr<PlayerPropertiesChangedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PlayerPropertiesChangedParams() { }

  std::string GetPlayerId() const { return player_id_; }
  void SetPlayerId(const std::string& value) { player_id_ = value; }

  const std::vector<std::unique_ptr<::headless::media::PlayerProperty>>* GetProperties() const { return &properties_; }
  void SetProperties(std::vector<std::unique_ptr<::headless::media::PlayerProperty>> value) { properties_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PlayerPropertiesChangedParams> Clone() const;

  template<int STATE>
  class PlayerPropertiesChangedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPlayerIdSet = 1 << 1,
    kPropertiesSet = 1 << 2,
      kAllRequiredFieldsSet = (kPlayerIdSet | kPropertiesSet | 0)
    };

    PlayerPropertiesChangedParamsBuilder<STATE | kPlayerIdSet>& SetPlayerId(const std::string& value) {
      static_assert(!(STATE & kPlayerIdSet), "property playerId should not have already been set");
      result_->SetPlayerId(value);
      return CastState<kPlayerIdSet>();
    }

    PlayerPropertiesChangedParamsBuilder<STATE | kPropertiesSet>& SetProperties(std::vector<std::unique_ptr<::headless::media::PlayerProperty>> value) {
      static_assert(!(STATE & kPropertiesSet), "property properties should not have already been set");
      result_->SetProperties(std::move(value));
      return CastState<kPropertiesSet>();
    }

    std::unique_ptr<PlayerPropertiesChangedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PlayerPropertiesChangedParams;
    PlayerPropertiesChangedParamsBuilder() : result_(new PlayerPropertiesChangedParams()) { }

    template<int STEP> PlayerPropertiesChangedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PlayerPropertiesChangedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PlayerPropertiesChangedParams> result_;
  };

  static PlayerPropertiesChangedParamsBuilder<0> Builder() {
    return PlayerPropertiesChangedParamsBuilder<0>();
  }

 private:
  PlayerPropertiesChangedParams() { }

  std::string player_id_;
  std::vector<std::unique_ptr<::headless::media::PlayerProperty>> properties_;

  DISALLOW_COPY_AND_ASSIGN(PlayerPropertiesChangedParams);
};


// Parameters for the PlayerEventsAdded event.
class HEADLESS_EXPORT PlayerEventsAddedParams {
 public:
  static std::unique_ptr<PlayerEventsAddedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PlayerEventsAddedParams() { }

  std::string GetPlayerId() const { return player_id_; }
  void SetPlayerId(const std::string& value) { player_id_ = value; }

  const std::vector<std::unique_ptr<::headless::media::PlayerEvent>>* GetEvents() const { return &events_; }
  void SetEvents(std::vector<std::unique_ptr<::headless::media::PlayerEvent>> value) { events_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PlayerEventsAddedParams> Clone() const;

  template<int STATE>
  class PlayerEventsAddedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPlayerIdSet = 1 << 1,
    kEventsSet = 1 << 2,
      kAllRequiredFieldsSet = (kPlayerIdSet | kEventsSet | 0)
    };

    PlayerEventsAddedParamsBuilder<STATE | kPlayerIdSet>& SetPlayerId(const std::string& value) {
      static_assert(!(STATE & kPlayerIdSet), "property playerId should not have already been set");
      result_->SetPlayerId(value);
      return CastState<kPlayerIdSet>();
    }

    PlayerEventsAddedParamsBuilder<STATE | kEventsSet>& SetEvents(std::vector<std::unique_ptr<::headless::media::PlayerEvent>> value) {
      static_assert(!(STATE & kEventsSet), "property events should not have already been set");
      result_->SetEvents(std::move(value));
      return CastState<kEventsSet>();
    }

    std::unique_ptr<PlayerEventsAddedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PlayerEventsAddedParams;
    PlayerEventsAddedParamsBuilder() : result_(new PlayerEventsAddedParams()) { }

    template<int STEP> PlayerEventsAddedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PlayerEventsAddedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PlayerEventsAddedParams> result_;
  };

  static PlayerEventsAddedParamsBuilder<0> Builder() {
    return PlayerEventsAddedParamsBuilder<0>();
  }

 private:
  PlayerEventsAddedParams() { }

  std::string player_id_;
  std::vector<std::unique_ptr<::headless::media::PlayerEvent>> events_;

  DISALLOW_COPY_AND_ASSIGN(PlayerEventsAddedParams);
};


// Parameters for the PlayerMessagesLogged event.
class HEADLESS_EXPORT PlayerMessagesLoggedParams {
 public:
  static std::unique_ptr<PlayerMessagesLoggedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PlayerMessagesLoggedParams() { }

  std::string GetPlayerId() const { return player_id_; }
  void SetPlayerId(const std::string& value) { player_id_ = value; }

  const std::vector<std::unique_ptr<::headless::media::PlayerMessage>>* GetMessages() const { return &messages_; }
  void SetMessages(std::vector<std::unique_ptr<::headless::media::PlayerMessage>> value) { messages_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PlayerMessagesLoggedParams> Clone() const;

  template<int STATE>
  class PlayerMessagesLoggedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPlayerIdSet = 1 << 1,
    kMessagesSet = 1 << 2,
      kAllRequiredFieldsSet = (kPlayerIdSet | kMessagesSet | 0)
    };

    PlayerMessagesLoggedParamsBuilder<STATE | kPlayerIdSet>& SetPlayerId(const std::string& value) {
      static_assert(!(STATE & kPlayerIdSet), "property playerId should not have already been set");
      result_->SetPlayerId(value);
      return CastState<kPlayerIdSet>();
    }

    PlayerMessagesLoggedParamsBuilder<STATE | kMessagesSet>& SetMessages(std::vector<std::unique_ptr<::headless::media::PlayerMessage>> value) {
      static_assert(!(STATE & kMessagesSet), "property messages should not have already been set");
      result_->SetMessages(std::move(value));
      return CastState<kMessagesSet>();
    }

    std::unique_ptr<PlayerMessagesLoggedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PlayerMessagesLoggedParams;
    PlayerMessagesLoggedParamsBuilder() : result_(new PlayerMessagesLoggedParams()) { }

    template<int STEP> PlayerMessagesLoggedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PlayerMessagesLoggedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PlayerMessagesLoggedParams> result_;
  };

  static PlayerMessagesLoggedParamsBuilder<0> Builder() {
    return PlayerMessagesLoggedParamsBuilder<0>();
  }

 private:
  PlayerMessagesLoggedParams() { }

  std::string player_id_;
  std::vector<std::unique_ptr<::headless::media::PlayerMessage>> messages_;

  DISALLOW_COPY_AND_ASSIGN(PlayerMessagesLoggedParams);
};


// Parameters for the PlayerErrorsRaised event.
class HEADLESS_EXPORT PlayerErrorsRaisedParams {
 public:
  static std::unique_ptr<PlayerErrorsRaisedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PlayerErrorsRaisedParams() { }

  std::string GetPlayerId() const { return player_id_; }
  void SetPlayerId(const std::string& value) { player_id_ = value; }

  const std::vector<std::unique_ptr<::headless::media::PlayerError>>* GetErrors() const { return &errors_; }
  void SetErrors(std::vector<std::unique_ptr<::headless::media::PlayerError>> value) { errors_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PlayerErrorsRaisedParams> Clone() const;

  template<int STATE>
  class PlayerErrorsRaisedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPlayerIdSet = 1 << 1,
    kErrorsSet = 1 << 2,
      kAllRequiredFieldsSet = (kPlayerIdSet | kErrorsSet | 0)
    };

    PlayerErrorsRaisedParamsBuilder<STATE | kPlayerIdSet>& SetPlayerId(const std::string& value) {
      static_assert(!(STATE & kPlayerIdSet), "property playerId should not have already been set");
      result_->SetPlayerId(value);
      return CastState<kPlayerIdSet>();
    }

    PlayerErrorsRaisedParamsBuilder<STATE | kErrorsSet>& SetErrors(std::vector<std::unique_ptr<::headless::media::PlayerError>> value) {
      static_assert(!(STATE & kErrorsSet), "property errors should not have already been set");
      result_->SetErrors(std::move(value));
      return CastState<kErrorsSet>();
    }

    std::unique_ptr<PlayerErrorsRaisedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PlayerErrorsRaisedParams;
    PlayerErrorsRaisedParamsBuilder() : result_(new PlayerErrorsRaisedParams()) { }

    template<int STEP> PlayerErrorsRaisedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PlayerErrorsRaisedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PlayerErrorsRaisedParams> result_;
  };

  static PlayerErrorsRaisedParamsBuilder<0> Builder() {
    return PlayerErrorsRaisedParamsBuilder<0>();
  }

 private:
  PlayerErrorsRaisedParams() { }

  std::string player_id_;
  std::vector<std::unique_ptr<::headless::media::PlayerError>> errors_;

  DISALLOW_COPY_AND_ASSIGN(PlayerErrorsRaisedParams);
};


// Parameters for the PlayersCreated event.
class HEADLESS_EXPORT PlayersCreatedParams {
 public:
  static std::unique_ptr<PlayersCreatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PlayersCreatedParams() { }

  const std::vector<std::string>* GetPlayers() const { return &players_; }
  void SetPlayers(std::vector<std::string> value) { players_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PlayersCreatedParams> Clone() const;

  template<int STATE>
  class PlayersCreatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPlayersSet = 1 << 1,
      kAllRequiredFieldsSet = (kPlayersSet | 0)
    };

    PlayersCreatedParamsBuilder<STATE | kPlayersSet>& SetPlayers(std::vector<std::string> value) {
      static_assert(!(STATE & kPlayersSet), "property players should not have already been set");
      result_->SetPlayers(std::move(value));
      return CastState<kPlayersSet>();
    }

    std::unique_ptr<PlayersCreatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PlayersCreatedParams;
    PlayersCreatedParamsBuilder() : result_(new PlayersCreatedParams()) { }

    template<int STEP> PlayersCreatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PlayersCreatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PlayersCreatedParams> result_;
  };

  static PlayersCreatedParamsBuilder<0> Builder() {
    return PlayersCreatedParamsBuilder<0>();
  }

 private:
  PlayersCreatedParams() { }

  std::vector<std::string> players_;

  DISALLOW_COPY_AND_ASSIGN(PlayersCreatedParams);
};


}  // namespace media

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_MEDIA_H_
