/**
 * @unrestricted
 */
export class Toolbar {
    /**
     * @param {!Action} action
     * @param {!Array<!ToolbarButton>} toggledOptions
     * @param {!Array<!ToolbarButton>} untoggledOptions
     * @return {!ToolbarButton}
     */
    static createLongPressActionButton(action: Action, toggledOptions: Array<ToolbarButton>, untoggledOptions: Array<ToolbarButton>): ToolbarButton;
    /**
     * @param {!Action} action
     * @param {!ToolbarButtonOptions=} options
     * @return {!ToolbarButton}
     */
    static createActionButton(action: Action, options?: ToolbarButtonOptions | undefined): ToolbarButton;
    /**
     * @param {string} actionId
     * @param {!ToolbarButtonOptions=} options
     * @return {!ToolbarButton}
     */
    static createActionButtonForId(actionId: string, options?: ToolbarButtonOptions | undefined): ToolbarButton;
    /**
     * @param {string} className
     * @param {!Element=} parentElement
     */
    constructor(className: string, parentElement?: Element | undefined);
    /** @type {!Array.<!ToolbarItem>} */
    _items: Array<ToolbarItem>;
    element: any;
    _enabled: boolean;
    _shadowRoot: DocumentFragment;
    _contentElement: any;
    _insertionPoint: any;
    /**
     * @return {!Element}
     */
    gripElementForResize(): Element;
    /**
     * @param {boolean=} growVertically
     */
    makeWrappable(growVertically?: boolean | undefined): void;
    makeVertical(): void;
    makeBlueOnHover(): void;
    makeToggledGray(): void;
    renderAsLinks(): void;
    /**
     * @return {boolean}
     */
    empty(): boolean;
    /**
     * @param {boolean} enabled
     */
    setEnabled(enabled: boolean): void;
    /**
     * @param {!ToolbarItem} item
     */
    appendToolbarItem(item: ToolbarItem): void;
    appendSeparator(): void;
    appendSpacer(): void;
    /**
     * @param {string} text
     */
    appendText(text: string): void;
    removeToolbarItems(): void;
    /**
     * @param {string} color
     */
    setColor(color: string): void;
    /**
     * @param {string} color
     */
    setToggledColor(color: string): void;
    _hideSeparatorDupes(): void;
    /**
     * @param {string} location
     * @return {!Promise<void>}
     */
    appendItemsAtLocation(location: string): Promise<void>;
}
export type ToolbarButtonOptions = {
    showLabel: boolean;
    userActionCode: (Host.UserMetrics.Action | undefined);
};
/**
 * @typedef {{
  *    showLabel: boolean,
  *    userActionCode: (!Host.UserMetrics.Action|undefined)
  * }}
  */
export let ToolbarButtonOptions: any;
/**
 * @unrestricted
 */
export class ToolbarItem extends Common.ObjectWrapper.ObjectWrapper {
    /**
     * @param {!Element} element
     */
    constructor(element: Element);
    element: Element;
    _visible: any;
    _enabled: any;
    /**
     * @param {string} title
     */
    setTitle(title: string): void;
    _title: any;
    /**
     * @param {boolean} value
     */
    setEnabled(value: boolean): void;
    /**
     * @param {boolean} enabled
     */
    _applyEnabledState(enabled: boolean): void;
    /**
     * @return {boolean} x
     */
    visible(): boolean;
    /**
     * @param {boolean} x
     */
    setVisible(x: boolean): void;
    setRightAligned(alignRight: any): void;
}
/**
 * @unrestricted
 */
export class ToolbarText extends ToolbarItem {
    /**
     * @param {string=} text
     */
    constructor(text?: string | undefined);
    /**
     * @return {string}
     */
    text(): string;
    /**
     * @param {string} text
     */
    setText(text: string): void;
}
/**
 * @unrestricted
 */
export class ToolbarButton extends ToolbarItem {
    /**
     * @param {string} title
     * @param {string=} glyph
     * @param {string=} text
     */
    constructor(title: string, glyph?: string | undefined, text?: string | undefined);
    _glyphElement: Icon;
    _textElement: Element;
    /**
     * @param {string} text
     */
    setText(text: string): void;
    _text: any;
    /**
     * @param {string} glyph
     */
    setGlyph(glyph: string): void;
    _glyph: any;
    /**
     * @param {string} iconURL
     */
    setBackgroundImage(iconURL: string): void;
    setSecondary(): void;
    setDarkText(): void;
    turnIntoSelect(): void;
    /**
     * @param {!Event} event
     */
    _clicked(event: Event): void;
    /**
     * @param {!Event} event
     */
    _mouseDown(event: Event): void;
}
export namespace ToolbarButton {
    export namespace Events {
        export const Click: symbol;
        export const MouseDown: symbol;
    }
}
export class ToolbarInput extends ToolbarItem {
    /**
     * @param {string} placeholder
     * @param {string=} accessiblePlaceholder
     * @param {number=} growFactor
     * @param {number=} shrinkFactor
     * @param {string=} tooltip
     * @param {(function(string, string, boolean=):!Promise<!Suggestions>)=} completions
     */
    constructor(placeholder: string, accessiblePlaceholder?: string | undefined, growFactor?: number | undefined, shrinkFactor?: number | undefined, tooltip?: string | undefined, completions?: ((arg0: string, arg1: string, arg2: boolean | undefined) => Promise<Suggestions>) | undefined);
    _prompt: TextPrompt;
    _proxyElement: Element;
    /**
     * @param {string} value
     * @param {boolean=} notify
     */
    setValue(value: string, notify?: boolean | undefined): void;
    /**
     * @return {string}
     */
    value(): string;
    /**
     * @param {!Event} event
     */
    _onKeydownCallback(event: Event): void;
    _onChangeCallback(): void;
    _updateEmptyStyles(): void;
}
export namespace ToolbarInput {
    export namespace Event_1 {
        export const TextChanged: symbol;
    }
    export { Event_1 as Event };
}
/**
 * @unrestricted
 */
export class ToolbarToggle extends ToolbarButton {
    /**
     * @param {string} title
     * @param {string=} glyph
     * @param {string=} toggledGlyph
     */
    constructor(title: string, glyph?: string | undefined, toggledGlyph?: string | undefined);
    _toggled: any;
    _untoggledGlyph: string | undefined;
    _toggledGlyph: string | undefined;
    /**
     * @return {boolean}
     */
    toggled(): boolean;
    /**
     * @param {boolean} toggled
     */
    setToggled(toggled: boolean): void;
    /**
     * @param {boolean} withRedColor
     */
    setDefaultWithRedColor(withRedColor: boolean): void;
    /**
     * @param {boolean} toggleWithRedColor
     */
    setToggleWithRedColor(toggleWithRedColor: boolean): void;
}
/**
 * @unrestricted
 */
export class ToolbarMenuButton extends ToolbarButton {
    /**
     * @param {function(!ContextMenu):void} contextMenuHandler
     * @param {boolean=} useSoftMenu
     */
    constructor(contextMenuHandler: (arg0: ContextMenu) => void, useSoftMenu?: boolean | undefined);
    _contextMenuHandler: (arg0: ContextMenu) => void;
    _useSoftMenu: boolean;
    _triggerTimeout: number | undefined;
    /**
     * @param {!Event} event
     */
    _trigger(event: Event): void;
    _lastTriggerTime: number | undefined;
}
/**
 * @unrestricted
 */
export class ToolbarSettingToggle extends ToolbarToggle {
    /**
     * @param {!Common.Settings.Setting<boolean>} setting
     * @param {string} glyph
     * @param {string} title
     */
    constructor(setting: Common.Settings.Setting<boolean>, glyph: string, title: string);
    _defaultTitle: string;
    _setting: Common.Settings.Setting<boolean>;
    _settingChanged(): void;
}
/**
 * @unrestricted
 */
export class ToolbarSeparator extends ToolbarItem {
    /**
     * @param {boolean=} spacer
     */
    constructor(spacer?: boolean | undefined);
}
/**
 * @interface
 */
export class Provider {
    /**
     * @return {?ToolbarItem}
     */
    item(): ToolbarItem | null;
}
/**
 * @interface
 */
export class ItemsProvider {
    /**
     * @return {!Array<!ToolbarItem>}
     */
    toolbarItems(): Array<ToolbarItem>;
}
/**
 * @unrestricted
 */
export class ToolbarComboBox extends ToolbarItem {
    /**
     * @param {?function(!Event):void} changeHandler
     * @param {string} title
     * @param {string=} className
     */
    constructor(changeHandler: ((arg0: Event) => void) | null, title: string, className?: string | undefined);
    _selectElement: Element;
    /**
     * @return {!HTMLSelectElement}
     */
    selectElement(): HTMLSelectElement;
    /**
     * @return {number}
     */
    size(): number;
    /**
     * @return {!Array.<!Element>}
     */
    options(): Array<Element>;
    /**
     * @param {!Element} option
     */
    addOption(option: Element): void;
    /**
     * @param {string} label
     * @param {string=} value
     * @return {!Element}
     */
    createOption(label: string, value?: string | undefined): Element;
    /**
     * @param {!Element} option
     */
    removeOption(option: Element): void;
    removeOptions(): void;
    /**
     * @return {?Element}
     */
    selectedOption(): Element | null;
    /**
     * @param {!Element} option
     */
    select(option: Element): void;
    /**
     * @param {number} index
     */
    setSelectedIndex(index: number): void;
    /**
     * @return {number}
     */
    selectedIndex(): number;
    /**
     * @param {number} width
     */
    setMaxWidth(width: number): void;
    /**
     * @param {number} width
     */
    setMinWidth(width: number): void;
}
/**
 * @unrestricted
 */
export class ToolbarSettingComboBox extends ToolbarComboBox {
    /**
     * @param {!Array<!{value: string, label: string}>} options
     * @param {!Common.Settings.Setting<*>} setting
     * @param {string} accessibleName
     */
    constructor(options: Array<{
        value: string;
        label: string;
    }>, setting: Common.Settings.Setting<any>, accessibleName: string);
    _options: {
        value: string;
        label: string;
    }[];
    _setting: Common.Settings.Setting<any>;
    /**
     * @param {!Array<!{value: string, label: string}>} options
     */
    setOptions(options: Array<{
        value: string;
        label: string;
    }>): void;
    /**
     * @return {string}
     */
    value(): string;
    _settingChanged(): void;
    /**
     * @param {!Event} event
     */
    _valueChanged(event: Event): void;
    _muteSettingListener: boolean | undefined;
}
/**
 * @unrestricted
 */
export class ToolbarCheckbox extends ToolbarItem {
    /**
     * @param {string} text
     * @param {string=} tooltip
     * @param {function():void=} listener
     */
    constructor(text: string, tooltip?: string | undefined, listener?: (() => void) | undefined);
    inputElement: any;
    /**
     * @return {boolean}
     */
    checked(): boolean;
    /**
     * @param {boolean} value
     */
    setChecked(value: boolean): void;
}
export class ToolbarSettingCheckbox extends ToolbarCheckbox {
    /**
     * @param {!Common.Settings.Setting<*>} setting
     * @param {string=} tooltip
     * @param {string=} alternateTitle
     */
    constructor(setting: Common.Settings.Setting<any>, tooltip?: string | undefined, alternateTitle?: string | undefined);
}
import { Action } from "./Action.js";
import * as Host from "../host/host.js";
import * as Common from "../common/common.js";
import { Icon } from "./Icon.js";
import { TextPrompt } from "./TextPrompt.js";
import { Suggestions } from "./SuggestBox.js";
import { ContextMenu } from "./ContextMenu.js";
