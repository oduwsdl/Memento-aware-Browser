// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/cr_elements/md_select_css.m.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import './shortcut_input.js';

import {CrContainerShadowBehavior} from 'chrome://resources/cr_elements/cr_container_shadow_behavior.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {ItemBehavior} from './item_behavior.js';
import {KeyboardShortcutDelegate} from './keyboard_shortcut_delegate.js';

// The UI to display and manage keyboard shortcuts set for extension commands.
Polymer({
  is: 'extensions-keyboard-shortcuts',

  _template: html`<!--_html_template_start_-->
<style include="md-select cr-shared-style">
  :host {
    height: 100%;
  }

  .shortcut-card {
    background-color: var(--cr-card-background-color);
    border-radius: var(--cr-card-border-radius);
    box-shadow: var(--cr-card-shadow);
    color: var(--cr-primary-text-color);
    margin: 0 auto 16px auto;
    padding-bottom: 8px;
    width: var(--cr-toolbar-field-width);
  }

  .shortcut-card:last-of-type {
    margin-bottom: 64px;
  }

  #container {
    box-sizing: border-box;
    height: 100%;
    overflow: overlay;
    padding-top: 24px;
  }

  .command-entry {
    align-items: start;
    display: flex;
    /* Makes top/bottom spacing of each row more even, while leaving
       space for cr-input error message in between rows. */
    margin-bottom: -8px;
    padding-top: 16px;
  }

  .command-name {
    /* Align with cr-input by matching the field's top padding. */
    flex: 1;
    margin-top: 6px;
  }

  .command-entry .md-select {
    /* TODO(johntlee): line-height needs adjustment to fix large fonts. */
    line-height: 22px;
    margin-inline-start: var(--cr-section-padding);
  }

  .card-title {
    align-items: center;
    border-bottom: var(--cr-separator-line);
    display: flex;
    margin-bottom: 9px;
    padding: 16px var(--cr-section-padding);
  }

  .icon {
    height: 20px;
    margin-inline-end: 20px;
    width: 20px;
  }

  .card-controls {
    /* We line up the controls with the name, which is after the
       20px left padding + 20px icon + 20px margin on the icon. */
    margin-inline-end: 20px;
    margin-inline-start: 60px;
  }
</style>
<div id="container">
  <template is="dom-repeat" items="[[calculateShownItems_(items.*)]]">
    <div class="shortcut-card">
      <div class="card-title cr-title-text">
        <img class="icon" src="[[item.iconUrl]]"
            alt$="[[appOrExtension(
                item.type,
                '$i18nPolymer{appIcon}',
                '$i18nPolymer{extensionIcon}')]]">
        <span role="heading" aria-level="2">[[item.name]]</span>
      </div>
      <div class="card-controls">
        <template is="dom-repeat" items="[[item.commands]]" as="command">
          <div class="command-entry" command="[[command]]">
            <span class="command-name">[[command.description]]</span>
            <extensions-shortcut-input delegate="[[delegate]]"
                item="[[item.id]]" shortcut="[[command.keybinding]]"
                command-name="[[command.name]]">
            </extensions-shortcut-input>
            <!-- Binding "value" to triggerScopeChange_ to trigger update
                only after CommandScope_ becomes available. -->
            <select class="md-select" on-change="onScopeChanged_"
                disabled$="[[computeScopeDisabled_(command)]]"
                value="[[
                    triggerScopeChange_(command.scope, CommandScope_)]]">
              <option value$="[[CommandScope_.CHROME]]">
                $i18n{shortcutScopeInChrome}
              </option>
              <option value$="[[CommandScope_.GLOBAL]]">
                $i18n{shortcutScopeGlobal}
              </option>
            </select>
          </div>
        </template>
      </div>
    </div>
  </template>
</div>
<!--_html_template_end_-->`,

  behaviors: [CrContainerShadowBehavior, ItemBehavior],

  properties: {
    /** @type {!KeyboardShortcutDelegate} */
    delegate: Object,

    /** @type {Array<!chrome.developerPrivate.ExtensionInfo>} */
    items: Array,

    /**
     * Proxying the enum to be used easily by the html template.
     * @private
     */
    CommandScope_: {
      type: Object,
      value: chrome.developerPrivate.CommandScope,
    },
  },

  listeners: {
    'view-enter-start': 'onViewEnter_',
  },

  /** @private */
  onViewEnter_() {
    chrome.metricsPrivate.recordUserAction('Options_ExtensionCommands');
  },

  /**
   * @return {!Array<!chrome.developerPrivate.ExtensionInfo>}
   * @private
   */
  calculateShownItems_() {
    return this.items.filter(function(item) {
      return item.commands.length > 0;
    });
  },

  /**
   * A polymer bug doesn't allow for databinding of a string property as a
   * boolean, but it is correctly interpreted from a function.
   * Bug: https://github.com/Polymer/polymer/issues/3669
   * @param {string} keybinding
   * @return {boolean}
   * @private
   */
  hasKeybinding_(keybinding) {
    return !!keybinding;
  },

  /**
   * Determines whether to disable the dropdown menu for the command's scope.
   * @param {!chrome.developerPrivate.Command} command
   * @return {boolean}
   * @private
   */
  computeScopeDisabled_(command) {
    return command.isExtensionAction || !command.isActive;
  },

  /**
   * This function exists to force trigger an update when CommandScope_
   * becomes available.
   * @param {string} scope
   * @return {string}
   */
  triggerScopeChange_(scope) {
    return scope;
  },

  /** @private */
  onCloseButtonClick_() {
    this.fire('close');
  },

  /**
   * @param {!{target: HTMLSelectElement, model: Object}} event
   * @private
   */
  onScopeChanged_(event) {
    this.delegate.updateExtensionCommandScope(
        event.model.get('item.id'), event.model.get('command.name'),
        /** @type {chrome.developerPrivate.CommandScope} */
        (event.target.value));
  },
});
