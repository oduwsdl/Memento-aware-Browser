// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/polymer/v3_0/iron-pages/iron-pages.js';
import 'chrome://resources/polymer/v3_0/iron-selector/iron-selector.js';
import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';

import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {html, PolymerElement} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';
import {BrowserProxy} from './browser_proxy.js';

/**
 * Threshold for considering an interim speech transcript result as "confident
 * enough". The more confident the API is about a transcript, the higher the
 * confidence (number between 0 and 1).
 * @type {number}
 */
const RECOGNITION_CONFIDENCE_THRESHOLD = 0.5;

/**
 * Maximum number of characters recognized before force-submitting a query.
 * Includes characters of non-confident recognition transcripts.
 * @type {number}
 */
const QUERY_LENGTH_LIMIT = 120;

/**
 * Time in milliseconds to wait before closing the UI if no interaction has
 * occurred.
 * @type {number}
 */
const IDLE_TIMEOUT_MS = 8000;

/**
 * Time in milliseconds to wait before closing the UI after an error has
 * occurred. This is a short timeout used when no click-target is present.
 * @type {number}
 */
const ERROR_TIMEOUT_SHORT_MS = 3000;

/**
 * Time in milliseconds to wait before closing the UI after an error has
 * occurred. This is a longer timeout used when there is a click-target is
 * present.
 * @type {number}
 */
const ERROR_TIMEOUT_LONG_MS = 8000;

/**
 * The minimum transition time for the volume rings.
 * @private
 */
const VOLUME_ANIMATION_DURATION_MIN_MS = 170;

/**
 * The range of the transition time for the volume rings.
 * @private
 */
const VOLUME_ANIMATION_DURATION_RANGE_MS = 10;

/**
 * The set of controller states.
 * @enum {number}
 * @private
 */
const State = {
  // Initial state before voice recognition has been set up.
  UNINITIALIZED: -1,
  // Indicates that speech recognition has started, but no audio has yet
  // been captured.
  STARTED: 0,
  // Indicates that audio is being captured by the Web Speech API, but no
  // speech has yet been recognized. UI indicates that audio is being captured.
  AUDIO_RECEIVED: 1,
  // Indicates that speech has been recognized by the Web Speech API, but no
  // resulting transcripts have yet been received back. UI indicates that audio
  // is being captured and is pulsating audio button.
  SPEECH_RECEIVED: 2,
  // Indicates speech has been successfully recognized and text transcripts have
  // been reported back. UI indicates that audio is being captured and is
  // displaying transcripts received so far.
  RESULT_RECEIVED: 3,
  // Indicates that speech recognition has failed due to an error (or a no match
  // error) being received from the Web Speech API. A timeout may have occurred
  // as well. UI displays the error message.
  ERROR_RECEIVED: 4,
  // Indicates speech recognition has received a final search query but the UI
  // has not yet redirected. The UI is displaying the final query.
  RESULT_FINAL: 5,
};


/** @typedef {newTabPage.mojom.VoiceSearchError} */
const Error = newTabPage.mojom.VoiceSearchError;

/**
 * Returns the error type based on the error string received from the webkit
 * speech recognition API.
 * @param {string} webkitError The error string received from the webkit speech
 *     recognition API.
 * @return {!Error} The appropriate error state from the Error enum.
 */
function toError(webkitError) {
  switch (webkitError) {
    case 'aborted':
      return Error.ABORTED;
    case 'audio-capture':
      return Error.AUDIO_CAPTURE;
    case 'language-not-supported':
      return Error.LANGUAGE_NOT_SUPPORTED;
    case 'network':
      return Error.NETWORK;
    case 'no-speech':
      return Error.NO_SPEECH;
    case 'not-allowed':
      return Error.NOT_ALLOWED;
    case 'service-not-allowed':
      return Error.SERVICE_NOT_ALLOWED;
    case 'bad-grammar':
      return Error.BAD_GRAMMAR;
    default:
      return Error.OTHER;
  }
}

/**
 * Returns a timeout based on the error received from the webkit speech
 * recognition API.
 * @param {Error} error An error from the Error enum.
 * @return {number} The appropriate timeout in MS for displaying the error.
 */
function getErrorTimeout(error) {
  switch (error) {
    case Error.AUDIO_CAPTURE:
    case Error.NO_SPEECH:
    case Error.NOT_ALLOWED:
    case Error.NO_MATCH:
      return ERROR_TIMEOUT_LONG_MS;
    default:
      return ERROR_TIMEOUT_SHORT_MS;
  }
}

// Overlay that lats the user perform voice searches.
class VoiceSearchOverlayElement extends PolymerElement {
  static get is() {
    return 'ntp-voice-search-overlay';
  }

  static get template() {
    return html`<!--_html_template_start_-->
<style include="cr-icons">
  :host {
    --receiving-audio-color: var(--google-red-refresh-500);
    --speak-shown-duration: 2s;
  }

  .display-stack {
    display: grid;
  }

  .display-stack > * {
    grid-column-start: 1;
    grid-row-start: 1;
  }

  #dialog {
    align-items: center;
    background-color: var(--ntp-background-override-color);
    border: none;
    display: flex;
    height: 100%;
    justify-content: center;
    left: 0;
    margin: 0;
    padding: 0;
    top: 0;
    width: 100%;
  }

  #closeButton {
    --cr-icon-button-fill-color: var(--ntp-secondary-text-color);
    margin: 0;
    position: absolute;
    top: 16px;
  }

  :host-context([dir='ltr']) #closeButton {
    right: 16px;
  }

  :host-context([dir='rtl']) #closeButton {
    left: 16px;
  }

  #content {
    align-items: center;
    display: flex;
    flex-direction: row;
    width: 660px;
  }

  #texts {
    color: var(--ntp-secondary-text-color);
    flex-grow: 1;
    font-size: 32px;
    text-align: start;
  }

  *[text] {
    transition-delay: 200ms;
    transition-duration: 500ms;
    transition-property: opacity, padding-inline-start;
    transition-timing-function: ease-out;
    visibility: hidden;
    width: 100%;
  }

  *[text='waiting'],
  *[text='speak'] {
    opacity: 0;
    padding-inline-start: 50px;
  }

  *[text][visible] {
    opacity: 1;
    padding-inline-start: 0;
    visibility: visible;
  }

  *[text='speak'][visible] #speak {
    opacity: 0;
    transition: opacity 0ms var(--speak-shown-duration);
  }

  *[text='speak'] #listening {
    opacity: 0;
  }

  *[text='speak'][visible] #listening {
    opacity: 1;
    transition: opacity 750ms ease-out var(--speak-shown-duration);
  }

  #finalResult {
    color: var(--ntp-primary-text-color);
  }

  #errors,
  #errorLinks {
    display: inline;
  }

  #errorLinks a {
    color: var(--cr-link-color);
    font-size: 18px;
    font-weight: 500;
    margin-inline-start: 0.25em;
    text-decoration: none;
  }

  #micContainer {
    --mic-button-size: 165px;
    --mic-container-size: 300px;
    align-items: center;
    flex-shrink: 0;
    height: var(--mic-container-size);
    justify-items: center;
    width: var(--mic-container-size);
  }

  #micVolume {
    --mic-volume-size: calc(var(--mic-button-size) +
        var(--mic-volume-level) * (var(--mic-container-size) -
            var(--mic-button-size)));
    align-items: center;
    background-color: var(--ntp-border-color);
    border-radius: 50%;
    display: flex;
    height: var(--mic-volume-size);
    justify-content: center;
    transition-duration: var(--mic-volume-duration);
    transition-property: height, width;
    transition-timing-function: ease-in-out;
    width: var(--mic-volume-size);
  }

  #micVolumeCutout {
    background-color: var(--ntp-background-override-color);
    border-radius: 50%;
    height: var(--mic-button-size);
    width: var(--mic-button-size);
  }

  #micButton {
    border-radius: 50%;
    height: var(--mic-button-size);
    transition: background-color 200ms ease-in-out;
    width: var(--mic-button-size);
  }

  .receiving #micButton {
    background-color: var(--receiving-audio-color);
    border-color: var(--receiving-audio-color);
  }

  #micIcon {
    -webkit-mask-image: url(icons/mic.svg);
    -webkit-mask-repeat: no-repeat;
    -webkit-mask-size: 100%;
    background-color: var(--ntp-border-color);
    height: 80px;
    transition: background-color 200ms ease-in-out;
    width: 80px;
  }

  .listening #micIcon {
    background-color: var(--receiving-audio-color);
  }

  .receiving #micIcon {
    background-color: white;
  }
</style>
<dialog id="dialog" on-close="onOverlayClose_" on-click="onOverlayClick_"
    on-keydown="onOverlayKeydown_">
  <!-- Purely exists to capture focus upon opening the dialog. -->
  <div tabindex="-1"></div>
  <cr-icon-button id="closeButton" class="icon-clear" title="$i18n{close}">
  </cr-icon-button>
  <div id="content">
    <iron-selector id="texts" selected="[[getText_(state_)]]"
        attr-for-selected="text" fallback-selection="none" aria-live="polite"
        selected-attribute="visible" class="display-stack">
      <div text="none"></div>
      <div text="waiting">$i18n{waiting}</div>
      <div text="speak" class="display-stack">
        <div id="speak">$i18n{speak}</div>
        <div id="listening">$i18n{listening}</div>
      </div>
      <div text="result" aria-hidden="true">
        <span id="finalResult">[[finalResult_]]</span>
        <span>[[interimResult_]]</span>
      </div>
      <div text="error">
        <iron-pages id="errors" selected="[[getErrorText_(error_)]]"
            attr-for-selected="error" fallback-selection="other">
          <span error="no-speech">$i18n{noVoice}</span>
          <span error="audio-capture">$i18n{audioError}</span>
          <span error="network">$i18n{networkError}</span>
          <span error="not-allowed">$i18n{permissionError}</span>
          <span error="language-not-supported">$i18n{languageError}</span>
          <span error="no-match">$i18n{noTranslation}</span>
          <span error="other">$i18n{otherError}</span>
        </iron-pages>
        <iron-pages id="errorLinks" selected="[[getErrorLink_(error_)]]"
            attr-for-selected="link" fallback-selection="none">
          <span link="none"></span>
          <a link="learn-more" target="_blank" href="[[helpUrl_]]"
              on-click="onLearnMoreClick_" on-keydown="onLinkKeydown_"><!--
            -->$i18n{learnMore}
          </a>
          <a link="details" target="_blank" href="[[helpUrl_]]"
              on-keydown="onLinkKeydown_"><!--
            -->$i18n{details}
          </a>
          <a link="try-again" id="retryLink" href="#"
              on-click="onTryAgainClick_" on-keydown="onLinkKeydown_"><!--
            -->$i18n{tryAgain}
          </a>
        </iron-pages>
      </div>
    </iron-selector>
    <div id="micContainer" class$="[[getMicClass_(state_)]] display-stack">
      <div id="micVolume"
          style="--mic-volume-level: [[micVolumeLevel_]];
                --mic-volume-duration: [[micVolumeDuration_]]ms;">
        <div id="micVolumeCutout">
        </div>
      </div>
      <cr-button id="micButton" on-click="onMicClick_">
        <div id="micIcon"></div>
      </cr-button>
    </div>
  </div>
</dialog>
<!--_html_template_end_-->`;
  }

  static get properties() {
    return {
      /** @private */
      interimResult_: String,

      /** @private */
      finalResult_: String,

      /** @private */
      state_: {
        type: Number,
        value: State.UNINITIALIZED,
      },

      /** @private */
      error_: Number,

      /** @private */
      helpUrl_: {
        type: String,
        readOnly: true,
        value: `https://support.google.com/chrome/?` +
            `p=ui_voice_search&hl=${window.navigator.language}`,
      },

      /** @private */
      micVolumeLevel_: {
        type: Number,
        value: 0,
      },

      /** @private */
      micVolumeDuration_: {
        type: Number,
        value: VOLUME_ANIMATION_DURATION_MIN_MS,
      },
    };
  }

  constructor() {
    super();
    /** @private {newTabPage.mojom.PageHandlerRemote} */
    this.pageHandler_ = BrowserProxy.getInstance().handler;
    /** @private {webkitSpeechRecognition} */
    this.voiceRecognition_ = new webkitSpeechRecognition();
    this.voiceRecognition_.continuous = false;
    this.voiceRecognition_.interimResults = true;
    this.voiceRecognition_.lang = window.navigator.language;
    this.voiceRecognition_.onaudiostart = this.onAudioStart_.bind(this);
    this.voiceRecognition_.onspeechstart = this.onSpeechStart_.bind(this);
    this.voiceRecognition_.onresult = this.onResult_.bind(this);
    this.voiceRecognition_.onend = this.onEnd_.bind(this);
    this.voiceRecognition_.onerror = (e) => {
      this.onError_(toError(e.error));
    };
    this.voiceRecognition_.onnomatch = () => {
      this.onError_(Error.NO_MATCH);
    };
    /** @private {number|undefined} */
    this.timerId_ = undefined;
  }

  /** @override */
  connectedCallback() {
    super.connectedCallback();
    this.$.dialog.showModal();
    this.start();
  }

  /** @private */
  start() {
    this.voiceRecognition_.start();
    this.state_ = State.STARTED;
    this.resetIdleTimer_();
  }

  /** @private */
  onOverlayClose_() {
    this.voiceRecognition_.abort();
    this.dispatchEvent(new Event('close'));
  }

  /** @private */
  onOverlayClick_() {
    this.$.dialog.close();
    this.pageHandler_.onVoiceSearchAction(
        newTabPage.mojom.VoiceSearchAction.CLOSE_OVERLAY);
  }

  /**
   * Handles <ENTER> or <SPACE> to trigger a query if we have recognized speech.
   * @param {KeyboardEvent} e
   * @private
   */
  onOverlayKeydown_(e) {
    if (['Enter', ' '].includes(e.key) && this.finalResult_) {
      this.onFinalResult_();
    } else if (e.key === 'Escape') {
      this.onOverlayClick_();
    }
  }

  /**
   * Handles <ENTER> or <SPACE> to simulate click.
   * @param {KeyboardEvent} e
   * @private
   */
  onLinkKeydown_(e) {
    if (!['Enter', ' '].includes(e.key)) {
      return;
    }
    // Otherwise, we may trigger overlay-wide keyboard shortcuts.
    e.stopPropagation();
    // Otherwise, we open the link twice.
    e.preventDefault();
    e.target.click();
  }

  /** @private */
  onLearnMoreClick_() {
    this.pageHandler_.onVoiceSearchAction(
        newTabPage.mojom.VoiceSearchAction.SUPPORT_LINK_CLICKED);
  }

  /**
   * @param {!Event} e
   * @private
   */
  onTryAgainClick_(e) {
    // Otherwise, we close the overlay.
    e.stopPropagation();
    this.start();
    this.pageHandler_.onVoiceSearchAction(
        newTabPage.mojom.VoiceSearchAction.TRY_AGAIN_LINK);
  }

  /**
   * @param {!Event} e
   * @private
   */
  onMicClick_(e) {
    if (this.state_ !== State.ERROR_RECEIVED ||
        this.error_ !== Error.NO_MATCH) {
      return;
    }
    // Otherwise, we close the overlay.
    e.stopPropagation();
    this.start();
    this.pageHandler_.onVoiceSearchAction(
        newTabPage.mojom.VoiceSearchAction.TRY_AGAIN_MIC_BUTTON);
  }

  /** @private */
  resetIdleTimer_() {
    BrowserProxy.getInstance().clearTimeout(this.timerId_);
    this.timerId_ = BrowserProxy.getInstance().setTimeout(
        this.onIdleTimeout_.bind(this), IDLE_TIMEOUT_MS);
  }

  /** @private */
  onIdleTimeout_() {
    if (this.state_ === State.RESULT_FINAL) {
      // Waiting for query redirect.
      return;
    }
    if (this.finalResult_) {
      // Query what we recognized so far.
      this.onFinalResult_();
      return;
    }
    this.voiceRecognition_.abort();
    this.onError_(Error.NO_MATCH);
  }

  /**
   * @param {number} duration
   * @private
   */
  resetErrorTimer_(duration) {
    BrowserProxy.getInstance().clearTimeout(this.timerId_);
    this.timerId_ = BrowserProxy.getInstance().setTimeout(() => {
      this.$.dialog.close();
    }, duration);
  }

  /** @private */
  onAudioStart_() {
    this.resetIdleTimer_();
    this.state_ = State.AUDIO_RECEIVED;
  }

  /** @private */
  onSpeechStart_() {
    this.resetIdleTimer_();
    this.state_ = State.SPEECH_RECEIVED;
    this.animateVolume_();
  }

  /**
   * @param {SpeechRecognitionEvent} e
   * @private
   */
  onResult_(e) {
    this.resetIdleTimer_();

    switch (this.state_) {
      case State.STARTED:
        // Network bugginess (the onspeechstart packet was lost).
        this.onAudioStart_();
        this.onSpeechStart_();
        break;
      case State.AUDIO_RECEIVED:
        // Network bugginess (the onaudiostart packet was lost).
        this.onSpeechStart_();
        break;
      case State.SPEECH_RECEIVED:
      case State.RESULT_RECEIVED:
        // Normal, expected states for processing results.
        break;
      default:
        // Not expecting results in any other states.
        return;
    }

    const results = e.results;
    if (results.length === 0) {
      return;
    }
    this.state_ = State.RESULT_RECEIVED;
    this.interimResult_ = '';
    this.finalResult_ = '';

    const finalResult = results[e.resultIndex];
    // Process final results.
    if (finalResult.isFinal) {
      this.finalResult_ = finalResult[0].transcript;
      this.onFinalResult_();
      return;
    }

    // Process interim results.
    for (let j = 0; j < results.length; j++) {
      const result = results[j][0];
      if (result.confidence > RECOGNITION_CONFIDENCE_THRESHOLD) {
        this.finalResult_ += result.transcript;
      } else {
        this.interimResult_ += result.transcript;
      }
    }

    // Force-stop long queries.
    if (this.interimResult_.length > QUERY_LENGTH_LIMIT) {
      this.onFinalResult_();
    }
  }

  /** @private */
  onFinalResult_() {
    if (!this.finalResult_) {
      this.onError_(Error.NO_MATCH);
      return;
    }
    this.state_ = State.RESULT_FINAL;
    const searchParams = new URLSearchParams();
    searchParams.append('q', this.finalResult_);
    // Add a parameter to indicate that this request is a voice search.
    searchParams.append('gs_ivs', '1');
    // Build the query URL.
    const queryUrl =
        new URL('/search', loadTimeData.getString('googleBaseUrl'));
    queryUrl.search = searchParams.toString();
    this.pageHandler_.onVoiceSearchAction(
        newTabPage.mojom.VoiceSearchAction.QUERY_SUBMITTED);
    BrowserProxy.getInstance().navigate(queryUrl.href);
  }

  /** @private */
  onEnd_() {
    switch (this.state_) {
      case State.STARTED:
        this.onError_(Error.AUDIO_CAPTURE);
        return;
      case State.AUDIO_RECEIVED:
        this.onError_(Error.NO_SPEECH);
        return;
      case State.SPEECH_RECEIVED:
      case State.RESULT_RECEIVED:
        this.onError_(Error.NO_MATCH);
        return;
      case State.ERROR_RECEIVED:
      case State.RESULT_FINAL:
        return;
      default:
        this.onError_(Error.OTHER);
        return;
    }
  }

  /**
   * @param {Error} error
   * @private
   */
  onError_(error) {
    this.pageHandler_.onVoiceSearchError(error);
    if (error === Error.ABORTED) {
      // We are in the process of closing voice search.
      return;
    }
    this.error_ = error;
    this.state_ = State.ERROR_RECEIVED;
    this.resetErrorTimer_(getErrorTimeout(error));
  }

  /** @private */
  animateVolume_() {
    this.micVolumeLevel_ = 0;
    this.micVolumeDuration_ = VOLUME_ANIMATION_DURATION_MIN_MS;
    if (this.state_ !== State.SPEECH_RECEIVED &&
        this.state_ !== State.RESULT_RECEIVED) {
      return;
    }
    this.micVolumeLevel_ = BrowserProxy.getInstance().random();
    this.micVolumeDuration_ = Math.round(
        VOLUME_ANIMATION_DURATION_MIN_MS +
        BrowserProxy.getInstance().random() *
            VOLUME_ANIMATION_DURATION_RANGE_MS);
    BrowserProxy.getInstance().setTimeout(
        this.animateVolume_.bind(this), this.micVolumeDuration_);
  }

  /**
   * @return {string}
   * @private
   */
  getText_() {
    switch (this.state_) {
      case State.STARTED:
        return 'waiting';
      case State.AUDIO_RECEIVED:
      case State.SPEECH_RECEIVED:
        return 'speak';
      case State.RESULT_RECEIVED:
      case State.RESULT_FINAL:
        return 'result';
      case State.ERROR_RECEIVED:
        return 'error';
      default:
        return 'none';
    }
  }

  /**
   * @return {string}
   * @private
   */
  getErrorText_() {
    switch (this.error_) {
      case Error.NO_SPEECH:
        return 'no-speech';
      case Error.AUDIO_CAPTURE:
        return 'audio-capture';
      case Error.NETWORK:
        return 'network';
      case Error.NOT_ALLOWED:
      case Error.SERVICE_NOT_ALLOWED:
        return 'not-allowed';
      case Error.LANGUAGE_NOT_SUPPORTED:
        return 'language-not-supported';
      case Error.NO_MATCH:
        return 'no-match';
      case Error.ABORTED:
      case Error.OTHER:
      default:
        return 'other';
    }
  }

  /**
   * @return {string}
   * @private
   */
  getErrorLink_() {
    switch (this.error_) {
      case Error.NO_SPEECH:
      case Error.AUDIO_CAPTURE:
        return 'learn-more';
      case Error.NOT_ALLOWED:
      case Error.SERVICE_NOT_ALLOWED:
        return 'details';
      case Error.NO_MATCH:
        return 'try-again';
      default:
        return 'none';
    }
  }

  /**
   * @return {string}
   * @private
   */
  getMicClass_() {
    switch (this.state_) {
      case State.AUDIO_RECEIVED:
        return 'listening';
      case State.SPEECH_RECEIVED:
      case State.RESULT_RECEIVED:
        return 'receiving';
      default:
        return '';
    }
  }
}

customElements.define(VoiceSearchOverlayElement.is, VoiceSearchOverlayElement);
