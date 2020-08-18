export class UserMetrics {
    _panelChangedSinceLaunch: boolean;
    _firedLaunchHistogram: boolean;
    _launchPanelName: string;
    /**
     * @param {string} panelName
     */
    panelShown(panelName: string): void;
    /**
     * @param {string} drawerId
     */
    drawerShown(drawerId: string): void;
    /**
     * @param {string} settingsViewId
     */
    settingsPanelShown(settingsViewId: string): void;
    /**
     * @param {!Action} action
     */
    actionTaken(action: Action): void;
    /**
     * @param {string} panelName
     * @param {string} histogramName
     * @suppressGlobalPropertiesCheck
     */
    panelLoaded(panelName: string, histogramName: string): void;
    /**
     * @param {?string} panelName
     */
    setLaunchPanel(panelName: string | null): void;
    /**
     * @param {string} keybindSet
     */
    keybindSetSettingChanged(keybindSet: string): void;
    /**
     * @param {string} actionId
     */
    keyboardShortcutFired(actionId: string): void;
    /**
     * @param {!IssueOpener} issueOpener
     */
    issuesPanelOpenedFrom(issueOpener: IssueOpener): void;
    /**
     * @param {!DualScreenDeviceEmulated} emulationAction
     */
    dualScreenDeviceEmulated(emulationAction: DualScreenDeviceEmulated): void;
}
export type Action = number;
/** @enum {number} */
export const Action: {
    WindowDocked: number;
    WindowUndocked: number;
    ScriptsBreakpointSet: number;
    TimelineStarted: number;
    ProfilesCPUProfileTaken: number;
    ProfilesHeapProfileTaken: number;
    'LegacyAuditsStarted-deprecated': number;
    ConsoleEvaluated: number;
    FileSavedInWorkspace: number;
    DeviceModeEnabled: number;
    AnimationsPlaybackRateChanged: number;
    RevisionApplied: number;
    FileSystemDirectoryContentReceived: number;
    StyleRuleEdited: number;
    CommandEvaluatedInConsolePanel: number;
    DOMPropertiesExpanded: number;
    ResizedViewInResponsiveMode: number;
    TimelinePageReloadStarted: number;
    ConnectToNodeJSFromFrontend: number;
    ConnectToNodeJSDirectly: number;
    CpuThrottlingEnabled: number;
    CpuProfileNodeFocused: number;
    CpuProfileNodeExcluded: number;
    SelectFileFromFilePicker: number;
    SelectCommandFromCommandMenu: number;
    ChangeInspectedNodeInElementsPanel: number;
    StyleRuleCopied: number;
    CoverageStarted: number;
    LighthouseStarted: number;
    LighthouseFinished: number;
    ShowedThirdPartyBadges: number;
    LighthouseViewTrace: number;
    FilmStripStartedRecording: number;
    CoverageReportFiltered: number;
    CoverageStartedPerBlock: number;
    SettingsOpenedFromGear: number;
    SettingsOpenedFromMenu: number;
    SettingsOpenedFromCommandMenu: number;
    TabMovedToDrawer: number;
    TabMovedToMainPanel: number;
};
/** @type {!Object<string, number>} */
export const PanelCodes: {
    [x: string]: number;
};
/** @type {!Object<string, number>} */
export const KeybindSetSettings: {
    [x: string]: number;
};
/** @type {!Object<string, number>} */
export const KeyboardShortcutAction: {
    [x: string]: number;
};
export type IssueOpener = number;
export namespace IssueOpener {
    export const ConsoleInfoBar: number;
    export const LearnMoreLinkCOEP: number;
    export const StatusBarIssuesCounter: number;
    export const HamburgerMenu: number;
    export const Adorner: number;
}
export type DualScreenDeviceEmulated = number;
export namespace DualScreenDeviceEmulated {
    export const DualScreenDeviceSelected: number;
    export const SpanButtonClicked: number;
    export const PlatformSupportUsed: number;
}
