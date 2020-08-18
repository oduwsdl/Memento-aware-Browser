/**
 * @param {string} url
 * @return {!Promise.<string>}
 */
export function loadResourcePromise(url: string): Promise<string>;
/**
 * @unrestricted
 */
export class Runtime {
    /**
     * @param {{forceNew: ?boolean, moduleDescriptors: ?Array.<!ModuleDescriptor>}=} opts
     * @return {!Runtime}
     */
    static instance(opts?: {
        forceNew: boolean | null;
        moduleDescriptors: Array<ModuleDescriptor> | null;
    } | undefined): Runtime;
    /**
     * http://tools.ietf.org/html/rfc3986#section-5.2.4
     * @param {string} path
     * @return {string}
     */
    static normalizePath(path: string): string;
    /**
     * @param {string} name
     * @return {?string}
     */
    static queryParam(name: string): string | null;
    /**
     * @return {!Object<string,boolean>}
     */
    static _experimentsSetting(): {
        [x: string]: boolean;
    };
    /**
     * @param {*} value
     * @param {string} message
     */
    static _assert(value: any, message: string): void;
    /**
     * @param {string} platform
     */
    static setPlatform(platform: string): void;
    /**
     * @param {!ModuleDescriptor|!RuntimeExtensionDescriptor} descriptor
     * @return {boolean}
     */
    static _isDescriptorEnabled(descriptor: ModuleDescriptor | RuntimeExtensionDescriptor): boolean;
    /**
     * @param {string} path
     * @return {string}
     */
    static resolveSourceURL(path: string): string;
    /**
     * @param {function(string):string} localizationFunction
     */
    static setL10nCallback(localizationFunction: (arg0: string) => string): void;
    /**
     * @private
     * @param {!Array.<!ModuleDescriptor>} descriptors
     */
    private constructor();
    /** @type {!Array<!Module>} */
    _modules: Array<Module>;
    /** @type {!Object<string, !Module>} */
    _modulesMap: {
        [x: string]: Module;
    };
    /** @type {!Array<!Extension>} */
    _extensions: Array<Extension>;
    /** @type {!Object<string, function(new:Object):void>} */
    _cachedTypeClasses: {
        [x: string]: new () => Object;
    };
    /** @type {!Object<string, !ModuleDescriptor>} */
    _descriptorsMap: {
        [x: string]: ModuleDescriptor;
    };
    /**
     * @param {string} url
     * @return {!Promise.<!ArrayBuffer>}
     */
    loadBinaryResourcePromise(url: string): Promise<ArrayBuffer>;
    useTestBase(): void;
    /**
     * @param {string} moduleName
     * @return {!Module}
     */
    module(moduleName: string): Module;
    /**
     * @param {!ModuleDescriptor} descriptor
     */
    _registerModule(descriptor: ModuleDescriptor): void;
    /**
     * @param {string} moduleName
     * @return {!Promise.<boolean>}
     */
    loadModulePromise(moduleName: string): Promise<boolean>;
    /**
     * @param {!Array.<string>} moduleNames
     * @return {!Promise.<!Array.<*>>}
     */
    loadAutoStartModules(moduleNames: Array<string>): Promise<Array<any>>;
    /**
     * @param {!Extension} extension
     * @param {?function(function(new:Object)):boolean} predicate
     * @return {boolean}
     */
    _checkExtensionApplicability(extension: Extension, predicate: ((arg0: new () => Object) => boolean) | null): boolean;
    /**
     * @param {!Extension} extension
     * @param {?Object} context
     * @return {boolean}
     */
    isExtensionApplicableToContext(extension: Extension, context: Object | null): boolean;
    /**
     * @param {!Extension} extension
     * @param {!Set.<!Function>=} currentContextTypes
     * @return {boolean}
     */
    isExtensionApplicableToContextTypes(extension: Extension, currentContextTypes?: Set<Function> | undefined): boolean;
    /**
     * @param {*} type
     * @param {?Object=} context
     * @param {boolean=} sortByTitle
     * @return {!Array.<!Extension>}
     */
    extensions(type: any, context?: (Object | null) | undefined, sortByTitle?: boolean | undefined): Array<Extension>;
    /**
     * @param {*} type
     * @param {?Object=} context
     * @return {?Extension}
     */
    extension(type: any, context?: (Object | null) | undefined): Extension | null;
    /**
     * @param {*} type
     * @param {?Object=} context
     * @return {!Promise.<!Array.<!Object>>}
     */
    allInstances(type: any, context?: (Object | null) | undefined): Promise<Array<Object>>;
    /**
     * @param {string} typeName
     * @return {?function(new:Object)}
     */
    _resolve(typeName: string): (new () => Object) | null;
    /**
     * @param {function(new:T)} constructorFunction
     * @return {!T}
     * @template T
     */
    sharedInstance<T>(constructorFunction: new () => T): T;
}
/**
 * @unrestricted
 */
export class ModuleDescriptor {
    /**
     * @type {string}
     */
    name: string;
    /**
     * @type {!Array.<!RuntimeExtensionDescriptor>}
     */
    extensions: Array<RuntimeExtensionDescriptor>;
    /**
     * @type {!Array.<string>|undefined}
     */
    dependencies: Array<string> | undefined;
    /**
     * @type {!Array.<string>}
     */
    scripts: Array<string>;
    /**
     * @type {!Array.<string>}
     */
    modules: Array<string>;
    /**
     * @type {!Array.<string>}
     */
    resources: Array<string>;
    /**
     * @type {string|undefined}
     */
    condition: string | undefined;
    /**
     * @type {boolean|undefined}
     */
    remote: boolean | undefined;
    /** @type {string|null} */
    experiment: string | null;
}
/**
 * @unrestricted
 */
export class RuntimeExtensionDescriptor {
    /**
     * @type {string}
     */
    type: string;
    /**
     * @type {string|undefined}
     */
    className: string | undefined;
    /**
     * @type {string|undefined}
     */
    factoryName: string | undefined;
    /**
     * @type {!Array.<string>|undefined}
     */
    contextTypes: Array<string> | undefined;
    /**
     * @type {!Array.<!{
     *   shortcut: string,
     *   platform: (string|undefined),
     *   keybindSets: (!Array.<string>|undefined)
     * }>|
     * undefined}
     */
    bindings: {
        shortcut: string;
        platform: (string | undefined);
        keybindSets: (Array<string> | undefined);
    }[] | undefined;
    /** @type {number} */
    order: number;
    /** @type {string|null} */
    extension: string | null;
    /** @type {string|null} */
    actionId: string | null;
    /** @type {string|null} */
    experiment: string | null;
    /** @type {string|null} */
    condition: string | null;
    /** @type {string} */
    settingName: string;
    /** @type {string|null} */
    settingType: string | null;
    /** @type {string} */
    defaultValue: string;
    /** @type {string|null} */
    storageType: string | null;
    /** @type {string|null} */
    userActionCondition: string | null;
    /** @type {string|null} */
    startPage: string | null;
    /** @type {string|null} */
    name: string | null;
}
/**
 * @unrestricted
 */
export class Module {
    /**
     * @param {!Runtime} manager
     * @param {!ModuleDescriptor} descriptor
     */
    constructor(manager: Runtime, descriptor: ModuleDescriptor);
    _manager: Runtime;
    _descriptor: ModuleDescriptor;
    _name: string;
    /** @type {!Array<!Extension>} */
    _extensions: Array<Extension>;
    /** @type {!Map<string, !Array<!Extension>>} */
    _extensionsByClassName: Map<string, Array<Extension>>;
    _loadedForTest: boolean;
    /**
     * @return {string}
     */
    name(): string;
    /**
     * @return {boolean}
     */
    enabled(): boolean;
    /**
     * @param {string} name
     * @return {string}
     */
    resource(name: string): string;
    /**
     * @return {!Promise.<boolean>}
     */
    _loadPromise(): Promise<boolean>;
    _pendingLoadPromise: Promise<boolean> | undefined;
    /**
     * @return {!Promise.<void>}
     * @this {Module}
     */
    _loadResources(): Promise<void>;
    _loadModules(): any;
    /**
     * @return {!Promise.<void>}
     */
    _loadScripts(): Promise<void>;
    /**
     * @return {string}
     */
    _computeNamespace(): string;
    /**
     * @param {string} resourceName
     */
    _modularizeURL(resourceName: string): string;
    /**
     * @return {string|undefined}
     */
    _remoteBase(): string | undefined;
    /**
     * @param {string} resourceName
     * @return {!Promise.<string>}
     */
    fetchResource(resourceName: string): Promise<string>;
    /**
     * @param {string} value
     * @return {string}
     */
    substituteURL(value: string): string;
}
/**
 * @unrestricted
 */
export class Extension {
    /**
    * @param {!Module} moduleParam
    * @param {!RuntimeExtensionDescriptor} descriptor
    */
    constructor(moduleParam: Module, descriptor: RuntimeExtensionDescriptor);
    _module: Module;
    _descriptor: RuntimeExtensionDescriptor;
    _type: string;
    _hasTypeClass: boolean;
    /**
    * @type {?string}
    */
    _className: string | null;
    _factoryName: string | null;
    /**
    * @return {!RuntimeExtensionDescriptor}
    */
    descriptor(): RuntimeExtensionDescriptor;
    /**
    * @return {!Module}
    */
    module(): Module;
    /**
    * @return {boolean}
    */
    enabled(): boolean;
    /**
    * @return {?function(new:Object)}
    */
    _typeClass(): (new () => Object) | null;
    /**
    * @param {?Object} context
    * @return {boolean}
    */
    isApplicable(context: Object | null): boolean;
    /**
    * @return {!Promise.<!Object>}
    */
    instance(): Promise<Object>;
    /**
    * @return {boolean}
    */
    canInstantiate(): boolean;
    /**
    * @return {!Object}
    */
    _createInstance(): Object;
    /**
    * @return {string}
    */
    title(): string;
    /**
    * @param {function(new:Object)} contextType
    * @return {boolean}
    */
    hasContextType(contextType: new () => Object): boolean;
}
/**
* @unrestricted
*/
export class ExperimentsSupport {
    /** @type {!Array<!Experiment>} */
    _experiments: Array<Experiment>;
    /** @type {!Object<string,boolean>} */
    _experimentNames: {
        [x: string]: boolean;
    };
    /** @type {!Object<string,boolean>} */
    _enabledTransiently: {
        [x: string]: boolean;
    };
    /** @type {!Set<string>} */
    _serverEnabled: Set<string>;
    /**
    * @return {!Array.<!Experiment>}
    */
    allConfigurableExperiments(): Array<Experiment>;
    /**
    * @param {!Object} value
    */
    _setExperimentsSetting(value: Object): void;
    /**
    * @param {string} experimentName
    * @param {string} experimentTitle
    * @param {boolean=} unstable
    */
    register(experimentName: string, experimentTitle: string, unstable?: boolean | undefined): void;
    /**
    * @param {string} experimentName
    * @return {boolean}
    */
    isEnabled(experimentName: string): boolean;
    /**
    * @param {string} experimentName
    * @param {boolean} enabled
    */
    setEnabled(experimentName: string, enabled: boolean): void;
    /**
    * @param {!Array.<string>} experimentNames
    */
    setDefaultExperiments(experimentNames: Array<string>): void;
    /**
    * @param {!Array.<string>} experimentNames
    */
    setServerEnabledExperiments(experimentNames: Array<string>): void;
    /**
    * @param {string} experimentName
    */
    enableForTest(experimentName: string): void;
    clearForTest(): void;
    cleanUpStaleExperiments(): void;
    /**
    * @param {string} experimentName
    */
    _checkExperiment(experimentName: string): void;
}
export const experiments: ExperimentsSupport;
/**
* @unrestricted
*/
declare class Experiment {
    /**
    * @param {!ExperimentsSupport} experiments
    * @param {string} name
    * @param {string} title
    * @param {boolean} unstable
    */
    constructor(experiments: ExperimentsSupport, name: string, title: string, unstable: boolean);
    name: string;
    title: string;
    unstable: boolean;
    _experiments: ExperimentsSupport;
    /**
    * @return {boolean}
    */
    isEnabled(): boolean;
    /**
    * @param {boolean} enabled
    */
    setEnabled(enabled: boolean): void;
}
export {};
