// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview
 * 'settings-ui' implements the UI for the Settings page.
 *
 * Example:
 *
 *    <settings-ui prefs="{{prefs}}"></settings-ui>
 */
import 'chrome://resources/cr_elements/cr_drawer/cr_drawer.m.js';
import 'chrome://resources/cr_elements/cr_page_host_style_css.m.js';
import 'chrome://resources/cr_elements/cr_toolbar/cr_toolbar.m.js';
import 'chrome://resources/cr_elements/icons.m.js';
import 'chrome://resources/cr_elements/shared_vars_css.m.js';
import 'chrome://resources/polymer/v3_0/paper-styles/color.js';
import '../icons.m.js';
import '../settings_main/settings_main.js';
import '../settings_menu/settings_menu.js';
import '../settings_shared_css.m.js';
import '../prefs/prefs.m.js';
import '../settings_vars_css.m.js';

import {CrContainerShadowBehavior} from 'chrome://resources/cr_elements/cr_container_shadow_behavior.m.js';
import {assert} from 'chrome://resources/js/assert.m.js';
import {isChromeOS} from 'chrome://resources/js/cr.m.js';
import {FindShortcutBehavior} from 'chrome://resources/js/find_shortcut_behavior.m.js';
import {listenOnce} from 'chrome://resources/js/util.m.js';
import {html, Polymer} from 'chrome://resources/polymer/v3_0/polymer/polymer_bundled.min.js';

import {resetGlobalScrollTargetForTesting, setGlobalScrollTarget} from '../global_scroll_target_behavior.m.js';
import {loadTimeData} from '../i18n_setup.js';
import {PageVisibility, pageVisibility} from '../page_visibility.js';
import {routes} from '../route.js';
import {Route, RouteObserverBehavior, Router} from '../router.m.js';

Polymer({
  is: 'settings-ui',

  _template: html`<!--_html_template_start_-->
    <style include="cr-page-host-style settings-shared">
      :host {
        display: flex;
        flex-direction: column;
        height: 100%;
        --settings-menu-width: 250px;
        /* Centered cards has a max-width of var(--cr-centered-card-max-width)
         * and a width of a certain percentage. Therefore, to make room for the
         * cards to be at their max width, the flex-basis of #main needs to be
         * whatever value the percentage of would equal to the max width. */
        --settings-main-basis: calc(var(--cr-centered-card-max-width) /
            var(--cr-centered-card-width-percentage));
      }

      cr-toolbar {
        min-height: 56px;
        --cr-toolbar-center-basis: var(--settings-main-basis);
      }

      cr-toolbar:not([narrow]) {
        --cr-toolbar-left-spacer-width: var(--settings-menu-width);
      }

      @media (prefers-color-scheme: light) {
        cr-toolbar {
          --iron-icon-fill-color: white;
        }
      }

      #cr-container-shadow-top {
        /* Needs to be higher than #container's z-index to appear above
         * scrollbars. */
        z-index: 2;
      }

      #container {
        align-items: flex-start;
        display: flex;
        flex: 1;
        overflow: overlay;
        position: relative;
      }

      #left,
      #main,
      #right {
        flex: 1 1 0;
      }

      #left {
        height: 100%;
        position: sticky;
        top: 0;
      }

      #left settings-menu {
        max-height: 100%;
        overflow: auto;
        overscroll-behavior: contain;
        width: var(--settings-menu-width);
      }

      #main {
        flex-basis: var(--settings-main-basis);
      }

      /* The breakpoint of 980px was decided on by the rounded sum of
       * var(--settings-main-basis), var(--settings-menu-width), and
       * var(--cr-section-padding). */
      @media (max-width: 980px) {
        #left,
        #right {
          display: none;
        }

        #main {
          min-width: auto;
          /* Add some padding to make room for borders and to prevent focus
           * indicators from being cropped. */
          padding: 0 3px;
        }
      }
    </style>
    <settings-prefs id="prefs" prefs="{{prefs}}"></settings-prefs>
    <cr-toolbar page-name="$i18n{settings}"
        clear-label="$i18n{clearSearch}"
        search-prompt="$i18n{searchPrompt}"
        on-cr-toolbar-menu-tap="onMenuButtonTap_"
        spinner-active="[[toolbarSpinnerActive_]]"
        menu-label="$i18n{menuButtonLabel}"
        on-search-changed="onSearchChanged_"
        role="banner"
        narrow="{{narrow_}}"
        narrow-threshold="980"
        show-menu="[[narrow_]]">
    </cr-toolbar>
    <cr-drawer id="drawer" on-close="onMenuClose_" heading="$i18n{settings}"
        align="$i18n{textdirection}">
      <div class="drawer-content">
        <template is="dom-if" id="drawerTemplate">
          <settings-menu page-visibility="[[pageVisibility_]]"
              on-iron-activate="onIronActivate_"
              advanced-opened="{{advancedOpenedInMenu_}}">
          </settings-menu>
        </template>
      </div>
    </cr-drawer>
    <div id="container" class="no-outline">
      <div id="left">
        <settings-menu page-visibility="[[pageVisibility_]]"
            on-iron-activate="onIronActivate_"
            advanced-opened="{{advancedOpenedInMenu_}}">
        </settings-menu>
      </div>
      <settings-main id="main" prefs="{{prefs}}"
          toolbar-spinner-active="{{toolbarSpinnerActive_}}"
          page-visibility="[[pageVisibility_]]"
          advanced-toggle-expanded="{{advancedOpenedInMain_}}">
      </settings-main>
      <!-- An additional child of the flex #container to take up space,
           aligned with the right-hand child of the flex toolbar. -->
      <div id="right"></div>
    </div>
<!--_html_template_end_-->`,

  behaviors: [
    RouteObserverBehavior,
    CrContainerShadowBehavior,
    FindShortcutBehavior,
  ],

  properties: {
    /**
     * Preferences state.
     */
    prefs: Object,

    /** @private */
    advancedOpenedInMain_: {
      type: Boolean,
      value: false,
      notify: true,
      observer: 'onAdvancedOpenedInMainChanged_',
    },

    /** @private */
    advancedOpenedInMenu_: {
      type: Boolean,
      value: false,
      notify: true,
      observer: 'onAdvancedOpenedInMenuChanged_',
    },

    /** @private {boolean} */
    toolbarSpinnerActive_: {
      type: Boolean,
      value: false,
    },

    /** @private */
    narrow_: {
      type: Boolean,
      observer: 'onNarrowChanged_',
    },

    /**
     * @private {!PageVisibility}
     */
    pageVisibility_: {type: Object, value: pageVisibility},

    /** @private */
    lastSearchQuery_: {
      type: String,
      value: '',
    },
  },

  listeners: {
    'refresh-pref': 'onRefreshPref_',
  },

  /** @override */
  created() {
    Router.getInstance().initializeRouteFromUrl();
  },

  /**
   * @override
   * @suppress {es5Strict} Object literals cannot contain duplicate keys in
   * ES5 strict mode.
   */
  ready() {
    // Lazy-create the drawer the first time it is opened or swiped into view.
    listenOnce(this.$.drawer, 'cr-drawer-opening', () => {
      this.$.drawerTemplate.if = true;
    });

    window.addEventListener('popstate', e => {
      this.$.drawer.cancel();
    });

    window.CrPolicyStrings = {
      controlledSettingExtension:
          loadTimeData.getString('controlledSettingExtension'),
      controlledSettingExtensionWithoutName:
          loadTimeData.getString('controlledSettingExtensionWithoutName'),
      controlledSettingPolicy:
          loadTimeData.getString('controlledSettingPolicy'),
      controlledSettingRecommendedMatches:
          loadTimeData.getString('controlledSettingRecommendedMatches'),
      controlledSettingRecommendedDiffers:
          loadTimeData.getString('controlledSettingRecommendedDiffers'),
      // <if expr="chromeos">
      controlledSettingShared:
          loadTimeData.getString('controlledSettingShared'),
      controlledSettingWithOwner:
          loadTimeData.getString('controlledSettingWithOwner'),
      controlledSettingNoOwner:
          loadTimeData.getString('controlledSettingNoOwner'),
      controlledSettingParent:
          loadTimeData.getString('controlledSettingParent'),
      controlledSettingChildRestriction:
          loadTimeData.getString('controlledSettingChildRestriction'),
      // </if>
    };

    this.addEventListener('show-container', () => {
      this.$.container.style.visibility = 'visible';
    });

    this.addEventListener('hide-container', () => {
      this.$.container.style.visibility = 'hidden';
    });
  },

  /** @override */
  attached() {
    document.documentElement.classList.remove('loading');

    setTimeout(function() {
      chrome.send(
          'metricsHandler:recordTime',
          ['Settings.TimeUntilInteractive', window.performance.now()]);
    });

    // Preload bold Roboto so it doesn't load and flicker the first time used.
    document.fonts.load('bold 12px Roboto');
    setGlobalScrollTarget(
        /** @type {HTMLElement} */ (this.$.container));

    const scrollToTop = top => new Promise(resolve => {
      if (this.$.container.scrollTop === top) {
        resolve();
        return;
      }

      // When transitioning  back to main page from a subpage on ChromeOS,
      // using 'smooth' scroll here results in the scroll changing to whatever
      // is last value of |top|. This happens even after setting the scroll
      // position the UI or programmatically.
      const behavior = isChromeOS ? 'auto' : 'smooth';
      this.$.container.scrollTo({top: top, behavior: behavior});
      const onScroll = () => {
        this.debounce('scrollEnd', () => {
          this.$.container.removeEventListener('scroll', onScroll);
          resolve();
        }, 75);
      };
      this.$.container.addEventListener('scroll', onScroll);
    });
    this.addEventListener('scroll-to-top', e => {
      scrollToTop(e.detail.top).then(e.detail.callback);
    });
    this.addEventListener('scroll-to-bottom', e => {
      scrollToTop(e.detail.bottom - this.$.container.clientHeight)
          .then(e.detail.callback);
    });
  },

  /** @override */
  detached() {
    Router.getInstance().resetRouteForTesting();
    resetGlobalScrollTargetForTesting();
  },

  /** @param {!Route} route */
  currentRouteChanged(route) {
    const urlSearchQuery =
        Router.getInstance().getQueryParameters().get('search') || '';
    if (urlSearchQuery === this.lastSearchQuery_) {
      return;
    }

    this.lastSearchQuery_ = urlSearchQuery;

    const toolbar = /** @type {!CrToolbarElement} */ (this.$$('cr-toolbar'));
    const searchField =
        /** @type {CrToolbarSearchFieldElement} */ (toolbar.getSearchField());

    // If the search was initiated by directly entering a search URL, need to
    // sync the URL parameter to the textbox.
    if (urlSearchQuery !== searchField.getValue()) {
      // Setting the search box value without triggering a 'search-changed'
      // event, to prevent an unnecessary duplicate entry in |window.history|.
      searchField.setValue(urlSearchQuery, true /* noEvent */);
    }

    this.$.main.searchContents(urlSearchQuery);
  },

  // Override FindShortcutBehavior methods.
  handleFindShortcut(modalContextOpen) {
    if (modalContextOpen) {
      return false;
    }
    this.$$('cr-toolbar').getSearchField().showAndFocus();
    return true;
  },

  // Override FindShortcutBehavior methods.
  searchInputHasFocus() {
    return this.$$('cr-toolbar').getSearchField().isSearchFocused();
  },

  /**
   * @param {!CustomEvent<string>} e
   * @private
   */
  onRefreshPref_(e) {
    return /** @type {SettingsPrefsElement} */ (this.$.prefs).refresh(e.detail);
  },

  /**
   * Handles the 'search-changed' event fired from the toolbar.
   * @param {!Event} e
   * @private
   */
  onSearchChanged_(e) {
    const query = e.detail;
    Router.getInstance().navigateTo(
        routes.BASIC,
        query.length > 0 ?
            new URLSearchParams('search=' + encodeURIComponent(query)) :
            undefined,
        /* removeSearch */ true);
  },

  /**
   * Called when a section is selected.
   * @private
   */
  onIronActivate_() {
    this.$.drawer.close();
  },

  /** @private */
  onMenuButtonTap_() {
    this.$.drawer.toggle();
  },

  /**
   * When this is called, The drawer animation is finished, and the dialog no
   * longer has focus. The selected section will gain focus if one was
   * selected. Otherwise, the drawer was closed due being canceled, and the
   * main settings container is given focus. That way the arrow keys can be
   * used to scroll the container, and pressing tab focuses a component in
   * settings.
   * @private
   */
  onMenuClose_() {
    if (!this.$.drawer.wasCanceled()) {
      // If a navigation happened, MainPageBehavior#currentRouteChanged
      // handles focusing the corresponding section.
      return;
    }

    // Add tab index so that the container can be focused.
    this.$.container.setAttribute('tabindex', '-1');
    this.$.container.focus();

    listenOnce(this.$.container, ['blur', 'pointerdown'], () => {
      this.$.container.removeAttribute('tabindex');
    });
  },

  /** @private */
  onAdvancedOpenedInMainChanged_() {
    if (this.advancedOpenedInMain_) {
      this.advancedOpenedInMenu_ = true;
    }
  },

  /** @private */
  onAdvancedOpenedInMenuChanged_() {
    if (this.advancedOpenedInMenu_) {
      this.advancedOpenedInMain_ = true;
    }
  },

  /** @private */
  onNarrowChanged_() {
    if (this.$.drawer.open && !this.narrow_) {
      this.$.drawer.close();
    }
  },
});
