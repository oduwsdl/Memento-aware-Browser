// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'chrome://resources/cr_elements/cr_button/cr_button.m.js';
import 'chrome://resources/cr_elements/cr_icon_button/cr_icon_button.m.js';
import 'chrome://resources/cr_elements/cr_icons_css.m.js';
import 'chrome://resources/cr_elements/cr_toggle/cr_toggle.m.js';
import 'chrome://resources/cr_elements/hidden_style_css.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_style_css.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/js/action_link.js';
import 'chrome://resources/cr_elements/action_link_css.m.js';
import './icons.js';
import './shared_style.js';
import './shared_vars.js';
import './strings.m.js';
import 'chrome://resources/polymer/v3_0/iron-flex-layout/iron-flex-layout-classes.js';
import 'chrome://resources/polymer/v3_0/iron-icon/iron-icon.js';
import 'chrome://resources/polymer/v3_0/paper-tooltip/paper-tooltip.js';

import {getToastManager} from 'chrome://resources/cr_elements/cr_toast/cr_toast_manager.m.js';
import {assert, assertNotReached} from 'chrome://resources/js/assert.m.js';
import {I18nBehavior} from 'chrome://resources/js/i18n_behavior.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {flush, html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {ItemBehavior} from './item_behavior.js';
import {computeInspectableViewLabel, EnableControl, getEnableControl, getItemSource, getItemSourceString, isEnabled, SourceType, userCanChangeEnablement} from './item_util.js';
import {navigation, Page} from './navigation_helper.js';

/** @interface */
export class ItemDelegate {
  /** @param {string} id */
  deleteItem(id) {}

  /**
   * @param {string} id
   * @param {boolean} isEnabled
   */
  setItemEnabled(id, isEnabled) {}

  /**
   * @param {string} id
   * @param {boolean} isAllowedIncognito
   */
  setItemAllowedIncognito(id, isAllowedIncognito) {}

  /**
   * @param {string} id
   * @param {boolean} isAllowedOnFileUrls
   */
  setItemAllowedOnFileUrls(id, isAllowedOnFileUrls) {}

  /**
   * @param {string} id
   * @param {!chrome.developerPrivate.HostAccess} hostAccess
   */
  setItemHostAccess(id, hostAccess) {}

  /**
   * @param {string} id
   * @param {boolean} collectsErrors
   */
  setItemCollectsErrors(id, collectsErrors) {}

  /**
   * @param {string} id
   * @param {chrome.developerPrivate.ExtensionView} view
   */
  inspectItemView(id, view) {}

  /**
   * @param {string} url
   */
  openUrl(url) {}

  /**
   * @param {string} id
   * @return {!Promise}
   */
  reloadItem(id) {}

  /** @param {string} id */
  repairItem(id) {}

  /** @param {!chrome.developerPrivate.ExtensionInfo} extension */
  showItemOptionsPage(extension) {}

  /** @param {string} id */
  showInFolder(id) {}

  /**
   * @param {string} id
   * @return {!Promise<string>}
   */
  getExtensionSize(id) {}

  /**
   * @param {string} id
   * @param {string} host
   * @return {!Promise<void>}
   */
  addRuntimeHostPermission(id, host) {}

  /**
   * @param {string} id
   * @param {string} host
   * @return {!Promise<void>}
   */
  removeRuntimeHostPermission(id, host) {}
}

Polymer({
  is: 'extensions-item',

  _template: html`<!--_html_template_start_-->
<style include="iron-flex cr-shared-style cr-hidden-style cr-icons action-link
    shared-style">
  .bounded-text,
  .multiline-clippable-text,
  .clippable-flex-text {
    /** Ensure that the text does not overflow its container. */
    overflow: hidden;
    text-overflow: ellipsis;
  }

  .bounded-text,
  .clippable-flex-text {
    white-space: nowrap;
  }

  .clippable-flex-text {
    /**
     * These labels can be arbitrarily long. We want to ensure that these
     * shrink, rather than the neighboring content.
     */
    flex-shrink: 1;
  }

  cr-tooltip-icon {
    margin-inline-end: 8px;
  }

  #icon-wrapper {
    align-self: flex-start;
    display: flex;
    padding: 6px;
    position: relative;
  }

  #icon {
    height: 36px;
    width: 36px;
  }

  #card {
    background-color: var(--cr-card-background-color);
    border-radius: var(--cr-card-border-radius);
    box-shadow: var(--cr-card-shadow);
    display: flex;
    flex-direction: column;
    height: var(--extensions-card-height);
    /* Duration matches --drawer-transition from toolbar.html. */
    transition: height 300ms cubic-bezier(.25, .1, .25, 1);
  }

  #card.dev-mode {
    height: 208px;
  }

  #main {
    display: flex;
    flex: 1;
    min-height: 0;
    padding: 16px 20px;
  }

  #content {
    display: flex;
    flex: 1;
    flex-direction: column;
    margin-inline-start: 24px;
    overflow: hidden;
  }

  #name-and-version {
    color: var(--cr-primary-text-color);
    margin-bottom: 4px;
  }

  #name {
    margin-inline-end: 8px;
  }

  #description {
    flex: 1;
  }

  #warnings {
    color: var(--error-color);
    flex: 1;
    margin-bottom: 8px;
  }

  #error-icon {
    --iron-icon-fill-color: var(--error-color);
    height: 18px;
    margin-inline-end: 4px;
    width: 18px;
  }

  #extension-id {
    flex-shrink: 0;
  }

  #inspect-views {
    display: flex;
    white-space: nowrap;
  }

  #inspect-views > span {
    margin-inline-end: 4px;
  }

  #button-strip {
    box-sizing: border-box;
    flex-shrink: 0;
    height: var(--cr-section-min-height);
    padding-bottom: 8px;
    padding-inline-end: 20px;
    padding-top: 8px;
  }

  #button-strip cr-button {
    margin-inline-start: 8px;
  }

  #source-indicator {
    margin-inline-start: 24px;
    margin-top: 24px;
    position: absolute;
  }

  .source-icon-wrapper {
    align-items: center;
    background: rgb(241, 89, 43);  /* Same in light & dark modes. */
    border-radius: 50%;  /* 50% border radius === a circle */
    box-shadow: 0 1px 1px 0 rgba(0, 0, 0, 0.22),
                0 2px 2px 0 rgba(0, 0, 0, 0.12);
    display: flex;
    height: 22px;
    justify-content: center;
    width: 22px;
  }

  #source-indicator iron-icon {
    color: white;
    height: 16px;
    width: 16px;
  }

  paper-tooltip {
    --paper-tooltip-min-width: 0;
  }

  #errors-button {
    color: var(--error-color);
  }

  #dev-reload-button {
    margin-inline-end: 12px;
  }

  #blacklisted-warning:empty {
    display: none;
  }

  #a11yAssociation {
    height: 0;
    overflow: hidden;
  }
</style>
<!-- Invisible instead of hidden because VoiceOver refuses to read text of
  element that's hidden when referenced by an aria label.  Unfortunately,
  this text can be found by Ctrl + F because it isn't hidden. -->
<div id="a11yAssociation" aria-hidden="true">
  [[a11yAssociation_(data.name)]]
</div>
<div id="card" class$="[[computeClasses_(data.state, inDevMode)]]">
  <div id="main">
    <div id="icon-wrapper">
      <img id="icon" src="[[data.iconUrl]]"
          aria-describedby="a11yAssociation"
          alt$="[[appOrExtension(
              data.type,
              '$i18nPolymer{appIcon}',
              '$i18nPolymer{extensionIcon}')]]">
      <template is="dom-if"
          if="[[computeSourceIndicatorIcon_(data.*)]]">
        <div id="source-indicator">
          <div class="source-icon-wrapper" role="img"
              aria-describedby="a11yAssociation"
              aria-label$="[[computeSourceIndicatorText_(data.*)]]">
            <iron-icon icon="[[computeSourceIndicatorIcon_(data.*)]]">
            </iron-icon>
          </div>
        </div>
      </template>
    </div>
    <!-- This needs to be separate from the source-indicator since it can't
         be contained inside of a position:relative parent element. -->
    <template is="dom-if"
        if="[[computeSourceIndicatorIcon_(data.*)]]">
      <paper-tooltip id="source-indicator-text" for="source-indicator"
          position="top" fit-to-visible-bounds aria-hidden="true">
        [[computeSourceIndicatorText_(data.*)]]
      </paper-tooltip>
    </template>
    <div id="content">
      <!--Note: We wrap inspect-views in a div so that the outer div
          doesn't shrink (because it's not display: flex).-->
      <div>
        <div id="name-and-version" class="layout horizontal center">
          <div id="name" role="heading" aria-level="3"
              class="clippable-flex-text">[[data.name]]</div>
          <span id="version" class="cr-secondary-text" hidden$="[[!inDevMode]]">
            [[data.version]]
          </span>
        </div>
      </div>
      <div id="description" class="cr-secondary-text multiline-clippable-text"
          hidden$="[[hasWarnings_(data.disableReasons.*, data.*)]]">
        [[data.description]]
      </div>
      <template is="dom-if"
          if="[[hasWarnings_(data.disableReasons.*, data.*)]]">
        <div id="warnings">
          <iron-icon id="error-icon" icon="cr:error"></iron-icon>
          <span id="runtime-warnings" aria-describedby="a11yAssociation"
              hidden$="[[!data.runtimeWarnings.length]]">
            <template is="dom-repeat" items="[[data.runtimeWarnings]]">
              [[item]]
            </template>
          </span>
          <span id="suspicious-warning" aria-describedby="a11yAssociation"
              hidden$="[[!data.disableReasons.suspiciousInstall]]">
            $i18n{itemSuspiciousInstall}
            <a target="_blank" href="$i18n{suspiciousInstallHelpUrl}">
              $i18n{learnMore}
            </a>
          </span>
          <span id="corrupted-warning" aria-describedby="a11yAssociation"
              hidden$="[[!data.disableReasons.corruptInstall]]">
            $i18n{itemCorruptInstall}
          </span>
          <span id="blacklisted-warning"><!-- No whitespace
            -->[[data.blacklistText]]<!-- so we can use :empty in css.
         --></span>
        </div>
      </template>
      <template is="dom-if" if="[[inDevMode]]">
        <div id="extension-id" class="bounded-text cr-secondary-text">
          [[data.id]]
        </div>
        <template is="dom-if"
            if="[[!computeInspectViewsHidden_(data.views)]]">
          <!--Note: We wrap inspect-views in a div so that the outer div
              doesn't shrink (because it's not display: flex).-->
          <div>
            <div id="inspect-views" class="cr-secondary-text">
              <span aria-describedby="a11yAssociation">
                $i18n{itemInspectViews}
              </span>
              <a class="clippable-flex-text" is="action-link"
                  title="[[computeFirstInspectTitle_(data.views)]]"
                  on-click="onInspectTap_">
                [[computeFirstInspectLabel_(data.views)]]
              </a>
              <a is="action-link"
                  hidden$="[[computeExtraViewsHidden_(data.views)]]"
                  on-click="onExtraInspectTap_">
                [[computeExtraInspectLabel_(data.views)]]
              </a>
            </div>
          </div>
        </template>
      </template>
    </div>
  </div>
  <div id="button-strip" class="layout horizontal center cr-secondary-text">
    <div class="layout flex horizontal center">
      <cr-button id="detailsButton" on-click="onDetailsTap_"
          aria-describedby="a11yAssociation">
        $i18n{itemDetails}
      </cr-button>
      <cr-button id="remove-button" on-click="onRemoveTap_"
          aria-describedby="a11yAssociation"
          hidden="[[data.mustRemainInstalled]]">
        $i18n{remove}
      </cr-button>
      <template is="dom-if" if="[[shouldShowErrorsButton_(data.*)]]">
        <cr-button id="errors-button" on-click="onErrorsTap_"
            aria-describedby="a11yAssociation">
          $i18n{itemErrors}
        </cr-button>
      </template>
    </div>
    <template is="dom-if" if="[[!computeDevReloadButtonHidden_(data.*)]]">
      <cr-icon-button id="dev-reload-button" class="icon-refresh no-overlap"
          aria-label="$i18n{itemReload}" aria-describedby="a11yAssociation"
          on-click="onReloadTap_"></cr-icon-button>
    </template>
    <template is="dom-if"
        if="[[showRepairButton_(data.disableReasons.corruptInstall)]]">
      <cr-button id="repair-button" class="action-button"
          aria-describedby="a11yAssociation" on-click="onRepairTap_">
        $i18n{itemRepair}
      </cr-button>
    </template>
    <template is="dom-if" if="[[showReloadButton_(data.state)]]">
      <cr-button id="terminated-reload-button" on-click="onReloadTap_"
          aria-describedby="a11yAssociation" class="action-button">
        $i18n{itemReload}
      </cr-button>
    </template>
    <cr-tooltip-icon id="parentDisabledPermissionsToolTip"
        hidden$="[[!data.disableReasons.parentDisabledPermissions]]"
        tooltip-text="$i18n{parentDisabledPermissions}"
        icon-class="cr20:kite"
        icon-aria-label="$i18n{parentDisabledPermissions}">
    </cr-tooltip-icon>
    <cr-toggle id="enableToggle"
        aria-label$="[[appOrExtension(
            data.type,
            '$i18nPolymer{appEnabled}',
            '$i18nPolymer{extensionEnabled}')]]"
        aria-describedby="a11yAssociation"
        checked="[[isEnabled_(data.state)]]"
        on-change="onEnableToggleChange_"
        disabled$="[[!isEnableToggleEnabled_(data.*)]]"
        hidden$="[[!showEnableToggle_(data.*)]]">
    </cr-toggle>
  </div>
</div>
<!--_html_template_end_-->`,

  behaviors: [I18nBehavior, ItemBehavior],

  properties: {
    // The item's delegate, or null.
    delegate: {
      type: Object,
    },

    // Whether or not dev mode is enabled.
    inDevMode: {
      type: Boolean,
      value: false,
    },

    // The underlying ExtensionInfo itself. Public for use in declarative
    // bindings.
    /** @type {chrome.developerPrivate.ExtensionInfo} */
    data: {
      type: Object,
    },

    // Whether or not the expanded view of the item is shown.
    /** @private */
    showingDetails_: {
      type: Boolean,
      value: false,
    },
  },

  /** Prevents reloading the same item while it's already being reloaded. */
  isReloading_: false,

  observers: [
    'observeIdVisibility_(inDevMode, showingDetails_, data.id)',
  ],

  /** @return {!HTMLElement} The "Details" button. */
  getDetailsButton() {
    return /** @type {!HTMLElement} */ (this.$.detailsButton);
  },

  /** @return {?HTMLElement} The "Errors" button, if it exists. */
  getErrorsButton() {
    return /** @type {?HTMLElement} */ (this.$$('#errors-button'));
  },

  /** @private string */
  a11yAssociation_() {
    // Don't use I18nBehavior.i18n because of additional checks it performs.
    // Polymer ensures that this string is not stamped into arbitrary HTML.
    // |this.data.name| can contain any data including html tags.
    // ex: "My <video> download extension!"
    return loadTimeData.getStringF('extensionA11yAssociation', this.data.name);
  },

  /** @private */
  observeIdVisibility_(inDevMode, showingDetails, id) {
    flush();
    const idElement = this.$$('#extension-id');
    if (idElement) {
      assert(this.data);
      idElement.innerHTML = this.i18n('itemId', this.data.id);
    }
  },

  /**
   * @return {boolean}
   * @private
   */
  shouldShowErrorsButton_() {
    // When the error console is disabled (happens when
    // --disable-error-console command line flag is used or when in the
    // Stable/Beta channel), |installWarnings| is populated.
    if (this.data.installWarnings && this.data.installWarnings.length > 0) {
      return true;
    }

    // When error console is enabled |installedWarnings| is not populated.
    // Instead |manifestErrors| and |runtimeErrors| are used.
    return this.data.manifestErrors.length > 0 ||
        this.data.runtimeErrors.length > 0;
  },

  /** @private */
  onRemoveTap_() {
    this.delegate.deleteItem(this.data.id);
  },

  /** @private */
  onEnableToggleChange_() {
    this.delegate.setItemEnabled(this.data.id, this.$.enableToggle.checked);
    this.$.enableToggle.checked = this.isEnabled_();
  },

  /** @private */
  onErrorsTap_() {
    if (this.data.installWarnings && this.data.installWarnings.length > 0) {
      this.fire('show-install-warnings', this.data.installWarnings);
      return;
    }

    navigation.navigateTo({page: Page.ERRORS, extensionId: this.data.id});
  },

  /** @private */
  onDetailsTap_() {
    navigation.navigateTo({page: Page.DETAILS, extensionId: this.data.id});
  },

  /**
   * @param {!{model: !{item: !chrome.developerPrivate.ExtensionView}}} e
   * @private
   */
  onInspectTap_(e) {
    this.delegate.inspectItemView(this.data.id, this.data.views[0]);
  },

  /** @private */
  onExtraInspectTap_() {
    navigation.navigateTo({page: Page.DETAILS, extensionId: this.data.id});
  },

  /** @private */
  onReloadTap_() {
    // Don't reload if in the middle of an update.
    if (this.isReloading_) {
      return;
    }

    this.isReloading_ = true;

    const toastManager = getToastManager();
    // Keep the toast open indefinitely.
    toastManager.duration = 0;
    toastManager.show(this.i18n('itemReloading'));
    this.delegate.reloadItem(this.data.id)
        .then(
            () => {
              toastManager.hide();
              toastManager.duration = 3000;
              toastManager.show(this.i18n('itemReloaded'));
              this.isReloading_ = false;
            },
            loadError => {
              this.fire('load-error', loadError);
              toastManager.hide();
              this.isReloading_ = false;
            });
  },

  /** @private */
  onRepairTap_() {
    this.delegate.repairItem(this.data.id);
  },

  /**
   * @return {boolean}
   * @private
   */
  isEnabled_() {
    return isEnabled(this.data.state);
  },

  /**
   * @return {boolean}
   * @private
   */
  isEnableToggleEnabled_() {
    return userCanChangeEnablement(this.data);
  },

  /**
   * Returns true if the reload button should be shown.
   * @return {boolean}
   * @private
   */
  showReloadButton_() {
    return getEnableControl(this.data) === EnableControl.RELOAD;
  },

  /**
   * Returns true if the repair button should be shown.
   * @return {boolean}
   * @private
   */
  showRepairButton_() {
    return getEnableControl(this.data) === EnableControl.REPAIR;
  },


  /**
   * Returns true if the enable toggle should be shown.
   * @return {boolean}
   * @private
   */
  showEnableToggle_() {
    return getEnableControl(this.data) === EnableControl.ENABLE_TOGGLE;
  },

  /**
   * return {string}
   * @private
   */
  computeClasses_() {
    let classes = this.isEnabled_() ? 'enabled' : 'disabled';
    if (this.inDevMode) {
      classes += ' dev-mode';
    }
    return classes;
  },

  /**
   * @return {string}
   * @private
   */
  computeSourceIndicatorIcon_() {
    switch (getItemSource(this.data)) {
      case SourceType.POLICY:
        return 'extensions-icons:business';
      case SourceType.SIDELOADED:
        return 'extensions-icons:input';
      case SourceType.UNKNOWN:
        // TODO(dpapad): Ask UX for a better icon for this case.
        return 'extensions-icons:input';
      case SourceType.UNPACKED:
        return 'extensions-icons:unpacked';
      case SourceType.WEBSTORE:
        return '';
    }
    assertNotReached();
  },

  /**
   * @return {string}
   * @private
   */
  computeSourceIndicatorText_() {
    if (this.data.locationText) {
      return this.data.locationText;
    }

    const sourceType = getItemSource(this.data);
    return sourceType === SourceType.WEBSTORE ? '' :
                                                getItemSourceString(sourceType);
  },

  /**
   * @return {boolean}
   * @private
   */
  computeInspectViewsHidden_() {
    return !this.data.views || this.data.views.length === 0;
  },

  /**
   * @return {string}
   * @private
   */
  computeFirstInspectTitle_() {
    // Note: theoretically, this wouldn't be called without any inspectable
    // views (because it's in a dom-if="!computeInspectViewsHidden_()").
    // However, due to the recycling behavior of iron list, it seems that
    // sometimes it can. Even when it is, the UI behaves properly, but we
    // need to handle the case gracefully.
    return this.data.views.length > 0 ?
        computeInspectableViewLabel(this.data.views[0]) :
        '';
  },

  /**
   * @return {string}
   * @private
   */
  computeFirstInspectLabel_() {
    const label = this.computeFirstInspectTitle_();
    return label && this.data.views.length > 1 ? label + ',' : label;
  },

  /**
   * @return {boolean}
   * @private
   */
  computeExtraViewsHidden_() {
    return this.data.views.length <= 1;
  },

  /**
   * @return {boolean}
   * @private
   */
  computeDevReloadButtonHidden_() {
    // Only display the reload spinner if the extension is unpacked and
    // enabled. There's no point in reloading a disabled extension, and we'll
    // show a crashed reload button if it's terminated.
    const showIcon =
        this.data.location === chrome.developerPrivate.Location.UNPACKED &&
        this.data.state === chrome.developerPrivate.ExtensionState.ENABLED;
    return !showIcon;
  },

  /**
   * @return {string}
   * @private
   */
  computeExtraInspectLabel_() {
    return this.i18n(
        'itemInspectViewsExtra', (this.data.views.length - 1).toString());
  },

  /**
   * @return {boolean}
   * @private
   */
  hasWarnings_() {
    return this.data.disableReasons.corruptInstall ||
        this.data.disableReasons.suspiciousInstall ||
        this.data.runtimeWarnings.length > 0 || !!this.data.blacklistText;
  },

  /**
   * @return {string}
   * @private
   */
  computeWarningsClasses_() {
    return this.data.blacklistText ? 'severe' : 'mild';
  },
});
