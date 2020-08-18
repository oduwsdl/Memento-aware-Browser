export function createSettingCheckbox(name: string, setting: Common.Settings.Setting<any>, omitParagraphElement?: boolean | undefined, tooltip?: string | undefined): Element;
export function bindCheckbox(input: Element, setting: Common.Settings.Setting<any>): void;
export function createCustomSetting(name: string, element: Element): Element;
export function createControlForSetting(setting: Common.Settings.Setting<any>, subtitle?: string | undefined): Element | null;
/**
 * @interface
 */
export class SettingUI {
    /**
     * @return {?Element}
     */
    settingElement(): Element | null;
}
import * as Common from "../common/common.js";
