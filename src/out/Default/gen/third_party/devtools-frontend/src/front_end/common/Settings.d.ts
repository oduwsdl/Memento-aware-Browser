/**
 * @param {string} settingName
 * @return {!Setting<*>}
 */
export function moduleSetting(settingName: string): Setting<any>;
/**
 * @param {string} settingName
 * @return {!Setting<*>}
 */
export function settingForTest(settingName: string): Setting<any>;
/**
 * @param {!Color} color
 * @return {!Format}
 */
export function detectColorFormat(color: Color): Format;
/**
 * @unrestricted
 */
export class Settings {
    static hasInstance(): boolean;
    /**
     * @param {{forceNew: ?boolean, globalStorage: ?SettingsStorage, localStorage: ?SettingsStorage}} opts
     */
    static instance(opts?: {
        forceNew: boolean | null;
        globalStorage: SettingsStorage | null;
        localStorage: SettingsStorage | null;
    }): Settings;
    /**
     * @private
     * @param {!SettingsStorage} globalStorage
     * @param {!SettingsStorage} localStorage
     */
    private constructor();
    _globalStorage: SettingsStorage;
    _localStorage: SettingsStorage;
    _sessionStorage: SettingsStorage;
    _eventSupport: ObjectWrapper;
    /** @type {!Map<string, !Setting<*>>} */
    _registry: Map<string, Setting<any>>;
    /** @type {!Map<string, !Setting<*>>} */
    _moduleSettings: Map<string, Setting<any>>;
    /**
     * @param {!Root.Runtime.Extension} extension
     */
    _registerModuleSetting(extension: Root.Runtime.Extension): void;
    /**
     * @param {string} settingName
     * @return {!Setting<*>}
     */
    moduleSetting(settingName: string): Setting<any>;
    /**
     * @param {string} settingName
     * @return {!Setting<*>}
     */
    settingForTest(settingName: string): Setting<any>;
    /**
     * @param {string} key
     * @param {*} defaultValue
     * @param {!SettingStorageType=} storageType
     * @return {!Setting<*>}
     */
    createSetting(key: string, defaultValue: any, storageType?: SettingStorageType | undefined): Setting<any>;
    /**
     * @param {string} key
     * @param {*} defaultValue
     * @return {!Setting<*>}
     */
    createLocalSetting(key: string, defaultValue: any): Setting<any>;
    /**
     * @param {string} key
     * @param {string} defaultValue
     * @param {string=} regexFlags
     * @param {!SettingStorageType=} storageType
     * @return {!RegExpSetting}
     */
    createRegExpSetting(key: string, defaultValue: string, regexFlags?: string | undefined, storageType?: SettingStorageType | undefined): RegExpSetting;
    clearAll(): void;
    /**
     * @param {!SettingStorageType=} storageType
     * @return {!SettingsStorage}
     */
    _storageFromType(storageType?: SettingStorageType | undefined): SettingsStorage;
}
/**
 * @unrestricted
 */
export class SettingsStorage {
    /**
     * @param {!Object<string,string>} object
     * @param {function(string, string):void=} setCallback
     * @param {function(string):void=} removeCallback
     * @param {function(string=):void=} removeAllCallback
     * @param {string=} storagePrefix
     */
    constructor(object: {
        [x: string]: string;
    }, setCallback?: ((arg0: string, arg1: string) => void) | undefined, removeCallback?: ((arg0: string) => void) | undefined, removeAllCallback?: ((arg0: string | undefined) => void) | undefined, storagePrefix?: string | undefined);
    _object: {
        [x: string]: string;
    };
    _setCallback: (arg0: string, arg1: string) => void;
    _removeCallback: (arg0: string) => void;
    _removeAllCallback: (arg0?: string | undefined) => void;
    _storagePrefix: string;
    /**
     * @param {string} name
     * @param {string} value
     */
    set(name: string, value: string): void;
    /**
     * @param {string} name
     * @return {boolean}
     */
    has(name: string): boolean;
    /**
     * @param {string} name
     * @return {string}
     */
    get(name: string): string;
    /**
     * @param {string} name
     */
    remove(name: string): void;
    removeAll(): void;
    _dumpSizes(): void;
}
/**
 * @template V
 * @unrestricted
 */
export class Setting<V> {
    /**
     * @param {!Settings} settings
     * @param {string} name
     * @param {V} defaultValue
     * @param {!ObjectWrapper} eventSupport
     * @param {!SettingsStorage} storage
     */
    constructor(settings: Settings, name: string, defaultValue: V, eventSupport: ObjectWrapper, storage: SettingsStorage);
    _settings: Settings;
    _name: string;
    _defaultValue: V;
    _eventSupport: ObjectWrapper;
    _storage: SettingsStorage;
    /** @type {string} */
    _title: string;
    /** @type {?Root.Runtime.Extension} */
    _extension: Root.Runtime.Extension | null;
    /**
     * @param {function(!EventTargetEvent):void} listener
     * @param {!Object=} thisObject
     * @return {!EventDescriptor}
     */
    addChangeListener(listener: (arg0: EventTargetEvent) => void, thisObject?: Object | undefined): EventDescriptor;
    /**
     * @param {function(!EventTargetEvent):void} listener
     * @param {!Object=} thisObject
     */
    removeChangeListener(listener: (arg0: EventTargetEvent) => void, thisObject?: Object | undefined): void;
    get name(): string;
    /**
     * @return {string}
     */
    title(): string;
    /**
     * @param {string} title
     */
    setTitle(title: string): void;
    /**
     * @param {boolean} requiresUserAction
     */
    setRequiresUserAction(requiresUserAction: boolean): void;
    _requiresUserAction: boolean | undefined;
    /**
     * @return {V}
     */
    get(): V;
    _value: any;
    /**
     * @param {V} value
     */
    set(value: V): void;
    _hadUserAction: boolean | undefined;
    remove(): void;
    /**
     * @return {?Root.Runtime.Extension}
     */
    extension(): Root.Runtime.Extension | null;
    /**
     * @param {string} message
     * @param {string} name
     * @param {string} value
     */
    _printSettingsSavingError(message: string, name: string, value: string): void;
}
/**
 * @unrestricted
 * @extends Setting<*>
 */
export class RegExpSetting extends Setting<any> {
    /**
     * @param {!Settings} settings
     * @param {string} name
     * @param {string} defaultValue
     * @param {!ObjectWrapper} eventSupport
     * @param {!SettingsStorage} storage
     * @param {string=} regexFlags
     */
    constructor(settings: Settings, name: string, defaultValue: string, eventSupport: ObjectWrapper, storage: SettingsStorage, regexFlags?: string | undefined);
    _regexFlags: string | undefined;
    /**
     * @return {!Array.<{pattern: string, disabled: (boolean|undefined)}>}
     */
    getAsArray(): Array<{
        pattern: string;
        disabled: (boolean | undefined);
    }>;
    /**
     * @param {!Array.<{pattern: string, disabled: (boolean|undefined)}>} value
     */
    setAsArray(value: Array<{
        pattern: string;
        disabled: (boolean | undefined);
    }>): void;
    /**
     * @return {?RegExp}
     */
    asRegExp(): RegExp | null;
    _regex: RegExp | null | undefined;
}
/**
 * @unrestricted
 */
export class VersionController {
    static get _currentVersionName(): string;
    static get currentVersion(): number;
    updateVersion(): void;
    /**
     * @param {number} oldVersion
     * @param {number} currentVersion
     */
    _methodsToRunToUpdateVersion(oldVersion: number, currentVersion: number): string[];
    _updateVersionFrom0To1(): void;
    _updateVersionFrom1To2(): void;
    _updateVersionFrom2To3(): void;
    _updateVersionFrom3To4(): void;
    _updateVersionFrom4To5(): void;
    _updateVersionFrom5To6(): void;
    _updateVersionFrom6To7(): void;
    _updateVersionFrom7To8(): void;
    _updateVersionFrom8To9(): void;
    _updateVersionFrom9To10(): void;
    _updateVersionFrom10To11(): void;
    _updateVersionFrom11To12(): void;
    _updateVersionFrom12To13(): void;
    _updateVersionFrom13To14(): void;
    _updateVersionFrom14To15(): void;
    _updateVersionFrom15To16(): void;
    _updateVersionFrom16To17(): void;
    _updateVersionFrom17To18(): void;
    _updateVersionFrom18To19(): void;
    _updateVersionFrom19To20(): void;
    _updateVersionFrom20To21(): void;
    _updateVersionFrom21To22(): void;
    _updateVersionFrom22To23(): void;
    _updateVersionFrom23To24(): void;
    _updateVersionFrom24To25(): void;
    _updateVersionFrom25To26(): void;
    _updateVersionFrom26To27(): void;
    _updateVersionFrom27To28(): void;
    _updateVersionFrom28To29(): void;
    _updateVersionFrom29To30(): void;
    _migrateSettingsFromLocalStorage(): void;
    /**
     * @param {!Setting<*>} breakpointsSetting
     * @param {number} maxBreakpointsCount
     */
    _clearBreakpointsWhenTooMany(breakpointsSetting: Setting<any>, maxBreakpointsCount: number): void;
}
export type SettingStorageType = symbol;
export namespace SettingStorageType {
    export const Global: symbol;
    export const Local: symbol;
    export const Session: symbol;
}
import { Color } from "./Color.js";
import { Format } from "./Color.js";
import { ObjectWrapper } from "./Object.js";
import * as Root from "../root/root.js";
import { EventTargetEvent } from "./EventTarget.js";
import { EventDescriptor } from "./EventTarget.js";
