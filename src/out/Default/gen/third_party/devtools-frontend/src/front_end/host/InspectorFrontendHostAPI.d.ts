export type Events = symbol;
export namespace Events {
    export const AppendedToURL: symbol;
    export const CanceledSaveURL: symbol;
    export const ContextMenuCleared: symbol;
    export const ContextMenuItemSelected: symbol;
    export const DeviceCountUpdated: symbol;
    export const DevicesDiscoveryConfigChanged: symbol;
    export const DevicesPortForwardingStatusChanged: symbol;
    export const DevicesUpdated: symbol;
    export const DispatchMessage: symbol;
    export const DispatchMessageChunk: symbol;
    export const EnterInspectElementMode: symbol;
    export const EyeDropperPickedColor: symbol;
    export const FileSystemsLoaded: symbol;
    export const FileSystemRemoved: symbol;
    export const FileSystemAdded: symbol;
    export const FileSystemFilesChangedAddedRemoved: symbol;
    export const IndexingTotalWorkCalculated: symbol;
    export const IndexingWorked: symbol;
    export const IndexingDone: symbol;
    export const KeyEventUnhandled: symbol;
    export const ReattachMainTarget: symbol;
    export const ReloadInspectedPage: symbol;
    export const RevealSourceLine: symbol;
    export const SavedURL: symbol;
    export const SearchCompleted: symbol;
    export const SetInspectedTabId: symbol;
    export const SetUseSoftMenu: symbol;
    export const ShowPanel: symbol;
}
export const EventDescriptors: (string | symbol | string[])[][];
/** @interface */
export class InspectorFrontendHostAPI {
    /**
     * @param {string=} type
     */
    addFileSystem(type?: string | undefined): void;
    loadCompleted(): void;
    /**
     * @param {number} requestId
     * @param {string} fileSystemPath
     * @param {string} excludedFolders
     */
    indexPath(requestId: number, fileSystemPath: string, excludedFolders: string): void;
    /**
     * Requests inspected page to be placed atop of the inspector frontend with specified bounds.
     * @param {{x: number, y: number, width: number, height: number}} bounds
     */
    setInspectedPageBounds(bounds: {
        x: number;
        y: number;
        width: number;
        height: number;
    }): void;
    /**
     * @param {!Array<string>} certChain
     */
    showCertificateViewer(certChain: Array<string>): void;
    /**
     * @param {string} shortcuts
     */
    setWhitelistedShortcuts(shortcuts: string): void;
    /**
     * @param {boolean} active
     */
    setEyeDropperActive(active: boolean): void;
    inspectElementCompleted(): void;
    /**
     * @param {string} url
     */
    openInNewTab(url: string): void;
    /**
     * @param {string} fileSystemPath
     */
    showItemInFolder(fileSystemPath: string): void;
    /**
     * @param {string} fileSystemPath
     */
    removeFileSystem(fileSystemPath: string): void;
    requestFileSystems(): void;
    /**
     * @param {string} url
     * @param {string} content
     * @param {boolean} forceSaveAs
     */
    save(url: string, content: string, forceSaveAs: boolean): void;
    /**
     * @param {string} url
     * @param {string} content
     */
    append(url: string, content: string): void;
    /**
     * @param {string} url
     */
    close(url: string): void;
    /**
     * @param {number} requestId
     * @param {string} fileSystemPath
     * @param {string} query
     */
    searchInPath(requestId: number, fileSystemPath: string, query: string): void;
    /**
     * @param {number} requestId
     */
    stopIndexing(requestId: number): void;
    bringToFront(): void;
    closeWindow(): void;
    /**
     * @param {?(string|undefined)} text
     */
    copyText(text: (string | undefined) | null): void;
    /**
     * @param {string} url
     */
    inspectedURLChanged(url: string): void;
    /**
     * @param {string} fileSystemId
     * @param {string} registeredName
     * @return {?FileSystem}
     */
    isolatedFileSystem(fileSystemId: string, registeredName: string): FileSystem | null;
    /**
     * @param {string} url
     * @param {string} headers
     * @param {number} streamId
     * @param {function(!LoadNetworkResourceResult):void} callback
     */
    loadNetworkResource(url: string, headers: string, streamId: number, callback: (arg0: LoadNetworkResourceResult) => void): void;
    /**
     * @param {function(!Object<string, string>):void} callback
     */
    getPreferences(callback: (arg0: {
        [x: string]: string;
    }) => void): void;
    /**
     * @param {string} name
     * @param {string} value
     */
    setPreference(name: string, value: string): void;
    /**
     * @param {string} name
     */
    removePreference(name: string): void;
    clearPreferences(): void;
    /**
     * @param {!FileSystem} fileSystem
     */
    upgradeDraggedFileSystemPermissions(fileSystem: FileSystem): void;
    /**
     * @return {string}
     */
    platform(): string;
    /**
     * @param {string} actionName
     * @param {number} actionCode
     * @param {number} bucketSize
     */
    recordEnumeratedHistogram(actionName: string, actionCode: number, bucketSize: number): void;
    /**
     * @param {string} histogramName
     * @param {number} duration
     */
    recordPerformanceHistogram(histogramName: string, duration: number): void;
    /**
     * @param {string} umaName
     */
    recordUserMetricsAction(umaName: string): void;
    /**
     * @param {string} message
     */
    sendMessageToBackend(message: string): void;
    /**
     * @param {!Adb.Config} config
     */
    setDevicesDiscoveryConfig(config: Adb.Config): void;
    /**
     * @param {boolean} enabled
     */
    setDevicesUpdatesEnabled(enabled: boolean): void;
    /**
     * @param {string} pageId
     * @param {string} action
     */
    performActionOnRemotePage(pageId: string, action: string): void;
    /**
     * @param {string} browserId
     * @param {string} url
     */
    openRemotePage(browserId: string, url: string): void;
    openNodeFrontend(): void;
    /**
     * @param {string} origin
     * @param {string} script
     */
    setInjectedScriptForOrigin(origin: string, script: string): void;
    /**
     * @param {boolean} isDocked
     * @param {function():void} callback
     */
    setIsDocked(isDocked: boolean, callback: () => void): void;
    /**
     * @return {number}
     */
    zoomFactor(): number;
    zoomIn(): void;
    zoomOut(): void;
    resetZoom(): void;
    /**
     * @param {number} x
     * @param {number} y
     * @param {!Array.<!ContextMenuDescriptor>} items
     * @param {!Document} document
     */
    showContextMenuAtPoint(x: number, y: number, items: Array<ContextMenuDescriptor>, document: Document): void;
    /**
     * @param {function():void} callback
     */
    reattach(callback: () => void): void;
    readyForTest(): void;
    connectionReady(): void;
    /**
     * @param {boolean} value
     */
    setOpenNewWindowForPopups(value: boolean): void;
    /**
     * @return {boolean}
     */
    isHostedMode(): boolean;
    /**
     * @param {function(!Root.Runtime.RuntimeExtensionDescriptor):void} callback
     */
    setAddExtensionCallback(callback: (arg0: Root.Runtime.RuntimeExtensionDescriptor) => void): void;
}
export type ContextMenuDescriptor = {
    type: string;
    id: (number | undefined);
    label: (string | undefined);
    enabled: (boolean | undefined);
    checked: (boolean | undefined);
    subItems: (Array<ContextMenuDescriptor> | undefined);
};
/** @typedef
{{
    type: string,
    id: (number|undefined),
    label: (string|undefined),
    enabled: (boolean|undefined),
    checked: (boolean|undefined),
    subItems: (!Array.<!ContextMenuDescriptor>|undefined)
}} */
export let ContextMenuDescriptor: any;
export type LoadNetworkResourceResult = {
    statusCode: number;
    headers: ({
        [x: string]: string;
    } | undefined);
    netError: (number | undefined);
    netErrorName: (string | undefined);
    urlValid: (boolean | undefined);
    messageOverride: (string | undefined);
};
/** @typedef
{{
    statusCode: number,
    headers: (!Object.<string, string>|undefined),
    netError: (number|undefined),
    netErrorName: (string|undefined),
    urlValid: (boolean|undefined),
    messageOverride: (string|undefined)
}} */
export let LoadNetworkResourceResult: any;
export type ExtensionDescriptor = {
    startPage: string;
    name: string;
    exposeExperimentalAPIs: boolean;
};
/** @typedef
{{
  startPage: string,
  name: string,
  exposeExperimentalAPIs: boolean
}} */
export let ExtensionDescriptor: any;
import * as Root from "../root/root.js";
