// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file was generated by:
//   tools/json_schema_compiler/compiler.py.
// NOTE: The format of types has changed. 'FooType' is now
//   'chrome.accessibilityPrivate.FooType'.
// Please run the closure compiler before committing changes.
// See https://chromium.googlesource.com/chromium/src/+/master/docs/closure_compilation.md

/** @fileoverview Externs generated from namespace: accessibilityPrivate */

/** @const */
chrome.accessibilityPrivate = {};

/**
 * Information about an alert
 * @typedef {{
 *   message: string
 * }}
 */
chrome.accessibilityPrivate.AlertInfo;

/**
 * Bounding rectangle in global screen coordinates.
 * @typedef {{
 *   left: number,
 *   top: number,
 *   width: number,
 *   height: number
 * }}
 */
chrome.accessibilityPrivate.ScreenRect;

/**
 * @enum {string}
 */
chrome.accessibilityPrivate.Gesture = {
  CLICK: 'click',
  SWIPE_LEFT1: 'swipeLeft1',
  SWIPE_UP1: 'swipeUp1',
  SWIPE_RIGHT1: 'swipeRight1',
  SWIPE_DOWN1: 'swipeDown1',
  SWIPE_LEFT2: 'swipeLeft2',
  SWIPE_UP2: 'swipeUp2',
  SWIPE_RIGHT2: 'swipeRight2',
  SWIPE_DOWN2: 'swipeDown2',
  SWIPE_LEFT3: 'swipeLeft3',
  SWIPE_UP3: 'swipeUp3',
  SWIPE_RIGHT3: 'swipeRight3',
  SWIPE_DOWN3: 'swipeDown3',
  SWIPE_LEFT4: 'swipeLeft4',
  SWIPE_UP4: 'swipeUp4',
  SWIPE_RIGHT4: 'swipeRight4',
  SWIPE_DOWN4: 'swipeDown4',
  TAP2: 'tap2',
  TAP3: 'tap3',
  TAP4: 'tap4',
};

/**
 * @enum {string}
 */
chrome.accessibilityPrivate.SwitchAccessCommand = {
  SELECT: 'select',
  NEXT: 'next',
  PREVIOUS: 'previous',
};

/**
 * @enum {string}
 */
chrome.accessibilityPrivate.SwitchAccessBubble = {
  BACK_BUTTON: 'backButton',
  MENU: 'menu',
};

/**
 * @enum {string}
 */
chrome.accessibilityPrivate.SwitchAccessMenuAction = {
  COPY: 'copy',
  CUT: 'cut',
  DECREMENT: 'decrement',
  DICTATION: 'dictation',
  END_TEXT_SELECTION: 'endTextSelection',
  INCREMENT: 'increment',
  JUMP_TO_BEGINNING_OF_TEXT: 'jumpToBeginningOfText',
  JUMP_TO_END_OF_TEXT: 'jumpToEndOfText',
  KEYBOARD: 'keyboard',
  MOVE_BACKWARD_ONE_CHAR_OF_TEXT: 'moveBackwardOneCharOfText',
  MOVE_BACKWARD_ONE_WORD_OF_TEXT: 'moveBackwardOneWordOfText',
  MOVE_CURSOR: 'moveCursor',
  MOVE_DOWN_ONE_LINE_OF_TEXT: 'moveDownOneLineOfText',
  MOVE_FORWARD_ONE_CHAR_OF_TEXT: 'moveForwardOneCharOfText',
  MOVE_FORWARD_ONE_WORD_OF_TEXT: 'moveForwardOneWordOfText',
  MOVE_UP_ONE_LINE_OF_TEXT: 'moveUpOneLineOfText',
  PASTE: 'paste',
  SCROLL_DOWN: 'scrollDown',
  SCROLL_LEFT: 'scrollLeft',
  SCROLL_RIGHT: 'scrollRight',
  SCROLL_UP: 'scrollUp',
  SELECT: 'select',
  SETTINGS: 'settings',
  START_TEXT_SELECTION: 'startTextSelection',
};

/**
 * @enum {string}
 */
chrome.accessibilityPrivate.SyntheticKeyboardEventType = {
  KEYUP: 'keyup',
  KEYDOWN: 'keydown',
};

/**
 * @typedef {{
 *   ctrl: (boolean|undefined),
 *   alt: (boolean|undefined),
 *   search: (boolean|undefined),
 *   shift: (boolean|undefined)
 * }}
 */
chrome.accessibilityPrivate.SyntheticKeyboardModifiers;

/**
 * @typedef {{
 *   type: !chrome.accessibilityPrivate.SyntheticKeyboardEventType,
 *   keyCode: number,
 *   modifiers: (!chrome.accessibilityPrivate.SyntheticKeyboardModifiers|undefined)
 * }}
 */
chrome.accessibilityPrivate.SyntheticKeyboardEvent;

/**
 * @enum {string}
 */
chrome.accessibilityPrivate.SyntheticMouseEventType = {
  PRESS: 'press',
  RELEASE: 'release',
  DRAG: 'drag',
  MOVE: 'move',
  ENTER: 'enter',
  EXIT: 'exit',
};

/**
 * @typedef {{
 *   type: !chrome.accessibilityPrivate.SyntheticMouseEventType,
 *   x: number,
 *   y: number
 * }}
 */
chrome.accessibilityPrivate.SyntheticMouseEvent;

/**
 * @enum {string}
 */
chrome.accessibilityPrivate.SelectToSpeakState = {
  SELECTING: 'selecting',
  SPEAKING: 'speaking',
  INACTIVE: 'inactive',
};

/**
 * @enum {string}
 */
chrome.accessibilityPrivate.FocusType = {
  GLOW: 'glow',
  SOLID: 'solid',
  DASHED: 'dashed',
};

/**
 * @typedef {{
 *   rects: !Array<!chrome.accessibilityPrivate.ScreenRect>,
 *   type: !chrome.accessibilityPrivate.FocusType,
 *   color: string,
 *   secondaryColor: (string|undefined),
 *   backgroundColor: (string|undefined),
 *   id: (string|undefined)
 * }}
 */
chrome.accessibilityPrivate.FocusRingInfo;

/**
 * Called to translate localeCodeToTranslate into human-readable string in the
 * locale specified by displayLocaleCode
 * @param {string} localeCodeToTranslate
 * @param {string} displayLocaleCode
 * @return {string} The human-readable locale string in the provided locale.
 */
chrome.accessibilityPrivate.getDisplayNameForLocale = function(localeCodeToTranslate, displayLocaleCode) {};

/**
 * Called to request battery status from Chrome OS system.
 * @param {function(string): void} callback Returns battery description as a
 *     string.
 */
chrome.accessibilityPrivate.getBatteryDescription = function(callback) {};

/**
 * Enables or disables native accessibility support. Once disabled, it is up to
 * the calling extension to provide accessibility for web contents.
 * @param {boolean} enabled True if native accessibility support should be
 *     enabled.
 */
chrome.accessibilityPrivate.setNativeAccessibilityEnabled = function(enabled) {};

/**
 * Sets the given accessibility focus rings for this extension.
 * @param {!Array<!chrome.accessibilityPrivate.FocusRingInfo>} focusRings Array
 *     of focus rings to draw.
 */
chrome.accessibilityPrivate.setFocusRings = function(focusRings) {};

/**
 * Sets the bounds of the accessibility highlight.
 * @param {!Array<!chrome.accessibilityPrivate.ScreenRect>} rects Array of
 *     rectangles to draw the highlight around.
 * @param {string} color CSS-style hex color string beginning with # like
 *     #FF9982 or #EEE.
 */
chrome.accessibilityPrivate.setHighlights = function(rects, color) {};

/**
 * Sets the calling extension as a listener of all keyboard events optionally
 * allowing the calling extension to capture/swallow the key event via DOM apis.
 * Returns false via callback when unable to set the listener.
 * @param {boolean} enabled True if the caller wants to listen to key events;
 *     false to stop listening to events. Note that there is only ever one
 *     extension listening to key events.
 * @param {boolean} capture True if key events should be swallowed natively and
 *     not propagated if preventDefault() gets called by the extension's
 *     background page.
 */
chrome.accessibilityPrivate.setKeyboardListener = function(enabled, capture) {};

/**
 * Darkens or undarkens the screen.
 * @param {boolean} enabled True to darken screen; false to undarken screen.
 */
chrome.accessibilityPrivate.darkenScreen = function(enabled) {};

/**
 * When enabled, forwards key events to the Switch Access extension
 * @param {boolean} shouldForward
 */
chrome.accessibilityPrivate.forwardKeyEventsToSwitchAccess = function(shouldForward) {};

/**
 * Shows the Switch Access menu next to the specified rectangle and with the
 * given actions
 * @param {!chrome.accessibilityPrivate.SwitchAccessBubble} bubble Which bubble
 *     to show/hide
 * @param {boolean} show True if the bubble should be shown, false otherwise
 * @param {!chrome.accessibilityPrivate.ScreenRect=} anchor A rectangle
 *     indicating the bounds of the object the menu should be displayed next to.
 * @param {!Array<!chrome.accessibilityPrivate.SwitchAccessMenuAction>=} actions
 *     The actions to be shown in the menu.
 */
chrome.accessibilityPrivate.updateSwitchAccessBubble = function(bubble, show, anchor, actions) {};

/**
 * Sets current ARC app to use native ARC support.
 * @param {boolean} enabled True for ChromeVox (native), false for TalkBack.
 */
chrome.accessibilityPrivate.setNativeChromeVoxArcSupportForCurrentApp = function(enabled) {};

/**
 * Sends a fabricated key event.
 * @param {!chrome.accessibilityPrivate.SyntheticKeyboardEvent} keyEvent The
 *     event to send.
 */
chrome.accessibilityPrivate.sendSyntheticKeyEvent = function(keyEvent) {};

/**
 * Enables or disables mouse events in ChromeVox.
 * @param {boolean} enabled True if ChromeVox should receive mouse events.
 */
chrome.accessibilityPrivate.enableChromeVoxMouseEvents = function(enabled) {};

/**
 * Sends a fabricated mouse event.
 * @param {!chrome.accessibilityPrivate.SyntheticMouseEvent} mouseEvent The
 *     event to send.
 */
chrome.accessibilityPrivate.sendSyntheticMouseEvent = function(mouseEvent) {};

/**
 * Called by the Select-to-Speak extension when Select-to-Speak has changed
 * states, between selecting with the mouse, speaking, and inactive.
 * @param {!chrome.accessibilityPrivate.SelectToSpeakState} state
 */
chrome.accessibilityPrivate.onSelectToSpeakStateChanged = function(state) {};

/**
 * Called by the Autoclick extension when findScrollableBoundsForPoint has found
 * a scrolling container. |rect| will be the bounds of the nearest scrollable
 * ancestor of the node at the point requested using
 * findScrollableBoundsForPoint.
 * @param {!chrome.accessibilityPrivate.ScreenRect} rect
 */
chrome.accessibilityPrivate.onScrollableBoundsForPointFound = function(rect) {};

/**
 * Toggles dictation between active and inactive states.
 */
chrome.accessibilityPrivate.toggleDictation = function() {};

/**
 * Shows or hides the virtual keyboard.
 * @param {boolean} isVisible
 */
chrome.accessibilityPrivate.setVirtualKeyboardVisible = function(isVisible) {};

/**
 * Opens a specified settings subpage. To open a page with url
 * chrome://settings/manageAccessibility/tts, pass in the substring
 * 'manageAccessibility/tts'.
 * @param {string} subpage
 */
chrome.accessibilityPrivate.openSettingsSubpage = function(subpage) {};

/**
 * Fired whenever ChromeVox should output introduction.
 * @type {!ChromeEvent}
 */
chrome.accessibilityPrivate.onIntroduceChromeVox;

/**
 * Fired when an accessibility gesture is detected by the touch exploration
 * controller.
 * @type {!ChromeEvent}
 */
chrome.accessibilityPrivate.onAccessibilityGesture;

/**
 * Fired when we first detect two fingers are held down, which can be used to
 * toggle spoken feedback on some touch-only devices.
 * @type {!ChromeEvent}
 */
chrome.accessibilityPrivate.onTwoFingerTouchStart;

/**
 * Fired when the user is no longer holding down two fingers (including
 * releasing one, holding down three, or moving them).
 * @type {!ChromeEvent}
 */
chrome.accessibilityPrivate.onTwoFingerTouchStop;

/**
 * Fired when Chrome OS wants to change the Select-to-Speak state, between
 * selecting with the mouse, speaking, and inactive.
 * @type {!ChromeEvent}
 */
chrome.accessibilityPrivate.onSelectToSpeakStateChangeRequested;

/**
 * Fired when Chrome OS has received a key event corresponding to a Switch
 * Access command.
 * @type {!ChromeEvent}
 */
chrome.accessibilityPrivate.onSwitchAccessCommand;

/**
 * Fired when an internal component within accessibility wants to force speech
 * output for an accessibility extension. Do not use without approval from
 * accessibility owners.
 * @type {!ChromeEvent}
 */
chrome.accessibilityPrivate.onAnnounceForAccessibility;

/**
 * Fired when an internal component within accessibility wants to find the
 * nearest scrolling container at a given screen coordinate. Used in Automatic
 * Clicks.
 * @type {!ChromeEvent}
 */
chrome.accessibilityPrivate.findScrollableBoundsForPoint;

/**
 * Fired when a custom spoken feedback on the active window gets enabled or
 * disabled. Called from ARC++ accessibility.
 * @type {!ChromeEvent}
 */
chrome.accessibilityPrivate.onCustomSpokenFeedbackToggled;
