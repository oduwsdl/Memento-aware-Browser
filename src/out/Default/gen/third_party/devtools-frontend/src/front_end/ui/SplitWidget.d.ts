export class SplitWidget extends Widget {
    /**
     * @param {boolean} isVertical
     * @param {boolean} secondIsSidebar
     * @param {string=} settingName
     * @param {number=} defaultSidebarWidth
     * @param {number=} defaultSidebarHeight
     * @param {boolean=} constraintsInDip
     */
    constructor(isVertical: boolean, secondIsSidebar: boolean, settingName?: string | undefined, defaultSidebarWidth?: number | undefined, defaultSidebarHeight?: number | undefined, constraintsInDip?: boolean | undefined);
    _sidebarElement: HTMLElement;
    _mainElement: HTMLElement;
    _resizerElement: HTMLElement;
    _resizerElementSize: number | null;
    _resizerWidget: SimpleResizerWidget;
    _defaultSidebarWidth: number;
    _defaultSidebarHeight: number;
    _constraintsInDip: boolean;
    _resizeStartSizeDIP: number;
    _setting: Common.Settings.Setting<any> | null;
    _totalSizeCSS: number;
    _totalSizeOtherDimensionCSS: number;
    /** @type {?Widget} */
    _mainWidget: Widget | null;
    /** @type {?Widget} */
    _sidebarWidget: Widget | null;
    _animationFrameHandle: number;
    /** @type {?function():void} */
    _animationCallback: (() => void) | null;
    _showHideSidebarButtonTitle: string;
    /** @type {?ToolbarButton} */
    _showHideSidebarButton: ToolbarButton | null;
    _isVertical: boolean;
    _sidebarMinimized: boolean;
    _detaching: boolean;
    _sidebarSizeDIP: any;
    _savedSidebarSizeDIP: any;
    _secondIsSidebar: any;
    _shouldSaveShowMode: boolean;
    /** @type {?number} */
    _savedVerticalMainSize: number | null;
    /** @type {?number} */
    _savedHorizontalMainSize: number | null;
    _showMode: any;
    _savedShowMode: any;
    /**
     * @return {boolean}
     */
    isVertical(): boolean;
    /**
     * @param {boolean} isVertical
     */
    setVertical(isVertical: boolean): void;
    /**
     * @param {boolean} isVertical
     */
    _innerSetVertical(isVertical: boolean): void;
    /**
     * @param {boolean=} animate
     */
    _updateLayout(animate?: boolean | undefined): void;
    /**
     * @param {!Widget} widget
     */
    setMainWidget(widget: Widget): void;
    /**
     * @param {!Widget} widget
     */
    setSidebarWidget(widget: Widget): void;
    /**
     * @return {?Widget}
     */
    mainWidget(): Widget | null;
    /**
     * @return {?Widget}
     */
    sidebarWidget(): Widget | null;
    /**
     * @return {boolean}
     */
    isSidebarSecond(): boolean;
    enableShowModeSaving(): void;
    /**
     * @return {string}
     */
    showMode(): string;
    /**
     * @param {boolean} secondIsSidebar
     */
    setSecondIsSidebar(secondIsSidebar: boolean): void;
    /**
     * @return {?string}
     */
    sidebarSide(): string | null;
    /**
     * @return {!Element}
     */
    resizerElement(): Element;
    /**
     * @param {boolean=} animate
     */
    hideMain(animate?: boolean | undefined): void;
    /**
     * @param {boolean=} animate
     */
    hideSidebar(animate?: boolean | undefined): void;
    /**
     * @param {boolean} minimized
     */
    setSidebarMinimized(minimized: boolean): void;
    /**
     * @return {boolean}
     */
    isSidebarMinimized(): boolean;
    /**
     * @param {?Widget} sideToShow
     * @param {?Widget} sideToHide
     * @param {!Element} shadowToShow
     * @param {!Element} shadowToHide
     * @param {boolean=} animate
     */
    _showOnly(sideToShow: Widget | null, sideToHide: Widget | null, shadowToShow: Element, shadowToHide: Element, animate?: boolean | undefined): void;
    _showFinishedForTest(): void;
    _removeAllLayoutProperties(): void;
    /**
     * @param {boolean=} animate
     */
    showBoth(animate?: boolean | undefined): void;
    /**
     * @param {boolean} resizable
     */
    setResizable(resizable: boolean): void;
    /**
     * @return {boolean}
     */
    isResizable(): boolean;
    /**
     * @param {number} size
     */
    setSidebarSize(size: number): void;
    /**
     * @return {number}
     */
    sidebarSize(): number;
    /**
     * Returns total size in DIP.
     * @return {number}
     */
    _totalSizeDIP(): number;
    /**
     * @param {string} showMode
     */
    _updateShowMode(showMode: string): void;
    /**
     * @param {number} sizeDIP
     * @param {boolean} animate
     * @param {boolean=} userAction
     */
    _innerSetSidebarSizeDIP(sizeDIP: number, animate: boolean, userAction?: boolean | undefined): void;
    /**
     * @param {boolean} reverse
     * @param {function():void=} callback
     */
    _animate(reverse: boolean, callback?: (() => void) | undefined): void;
    _cancelAnimation(): void;
    /**
     * @param {number} sidebarSize
     * @param {boolean=} userAction
     * @return {number}
     */
    _applyConstraints(sidebarSize: number, userAction?: boolean | undefined): number;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onResizeStart(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onResizeUpdate(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onResizeEnd(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {boolean=} noSplitter
     */
    hideDefaultResizer(noSplitter?: boolean | undefined): void;
    /**
     * @param {!Element} resizerElement
     */
    installResizer(resizerElement: Element): void;
    /**
     * @param {!Element} resizerElement
     */
    uninstallResizer(resizerElement: Element): void;
    /**
     * @return {boolean}
     */
    hasCustomResizer(): boolean;
    /**
     * @param {!Element} resizer
     * @param {boolean} on
     */
    toggleResizer(resizer: Element, on: boolean): void;
    /**
     * @return {?SettingForOrientation}
     */
    _settingForOrientation(): SettingForOrientation | null;
    /**
     * @return {number}
     */
    _preferredSidebarSizeDIP(): number;
    _restoreSidebarSizeFromSettings(): void;
    _restoreAndApplyShowModeFromSettings(): void;
    _saveShowModeToSettings(): void;
    _saveSetting(): void;
    _forceUpdateLayout(): void;
    /**
     * @param {!Common.EventTarget.EventTargetEvent} event
     */
    _onZoomChanged(event: Common.EventTarget.EventTargetEvent): void;
    /**
     * @param {string} title
     * @return {!ToolbarButton}
     */
    createShowHideSidebarButton(title: string): ToolbarButton;
    _updateShowHideSidebarButton(): void;
}
export namespace ShowMode {
    export const Both: string;
    export const OnlyMain: string;
    export const OnlySidebar: string;
}
export type Events = symbol;
export namespace Events {
    export const SidebarSizeChanged: symbol;
    export const ShowModeChanged: symbol;
}
export type SettingForOrientation = {
    showMode: string;
    size: number;
};
/** @typedef {{showMode: string, size: number}} */
export let SettingForOrientation: any;
import { Widget } from "./Widget.js";
import { SimpleResizerWidget } from "./ResizerWidget.js";
import * as Common from "../common/common.js";
import { ToolbarButton } from "./Toolbar.js";
