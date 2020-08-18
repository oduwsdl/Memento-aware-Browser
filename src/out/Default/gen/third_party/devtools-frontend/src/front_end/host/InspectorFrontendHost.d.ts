/**
 * @param {!Object<string, string>=} prefs
 * @return {boolean}
 */
export function isUnderTest(prefs?: {
    [x: string]: string;
} | undefined): boolean;
/**
 * @implements {InspectorFrontendHostAPI}
 * @unrestricted
 */
export class InspectorFrontendHostStub implements InspectorFrontendHostAPI {
    /**
     * @type {!Map<string, !Array<string>>}
     */
    _urlsBeingSaved: Map<string, Array<string>>;
    /**
     * @type {!Common.EventTarget.EventTarget}
     */
    events: Common.EventTarget.EventTarget;
    /**
     * @override
     * @return {string}
     */
    platform(): string;
    /**
     * @override
     */
    loadCompleted(): void;
    /**
     * @override
     */
    bringToFront(): void;
    _windowVisible: boolean | undefined;
    /**
     * @override
     */
    closeWindow(): void;
    /**
     * @override
     * @param {boolean} isDocked
     * @param {function():void} callback
     */
    setIsDocked(isDocked: boolean, callback: () => void): void;
    /**
     * Requests inspected page to be placed atop of the inspector frontend with specified bounds.
     * @override
     * @param {{x: number, y: number, width: number, height: number}} bounds
     */
    setInspectedPageBounds(bounds: {
        x: number;
        y: number;
        width: number;
        height: number;
    }): void;
    /**
     * @override
     */
    inspectElementCompleted(): void;
    /**
     * @override
     * @param {string} origin
     * @param {string} script
     */
    setInjectedScriptForOrigin(origin: string, script: string): void;
    /**
     * @override
     * @param {string} url
     * @suppressGlobalPropertiesCheck
     */
    inspectedURLChanged(url: string): void;
    /**
     * @override
     * @param {?(string|undefined)} text
     * @suppressGlobalPropertiesCheck
     */
    copyText(text: (string | undefined) | null): void;
    /**
     * @override
     * @param {string} url
     */
    openInNewTab(url: string): void;
    /**
     * @override
     * @param {string} fileSystemPath
     */
    showItemInFolder(fileSystemPath: string): void;
    /**
     * @override
     * @param {string} url
     * @param {string} content
     * @param {boolean} forceSaveAs
     */
    save(url: string, content: string, forceSaveAs: boolean): void;
    /**
     * @override
     * @param {string} url
     * @param {string} content
     */
    append(url: string, content: string): void;
    /**
     * @override
     * @param {string} url
     */
    close(url: string): void;
    /**
     * @override
     * @param {string} message
     */
    sendMessageToBackend(message: string): void;
    /**
     * @override
     * @param {string} actionName
     * @param {number} actionCode
     * @param {number} bucketSize
     */
    recordEnumeratedHistogram(actionName: string, actionCode: number, bucketSize: number): void;
    /**
     * @override
     * @param {string} histogramName
     * @param {number} duration
     */
    recordPerformanceHistogram(histogramName: string, duration: number): void;
    /**
     * @override
     * @param {string} umaName
     */
    recordUserMetricsAction(umaName: string): void;
    /**
     * @override
     */
    requestFileSystems(): void;
    /**
     * @override
     * @param {string=} type
     */
    addFileSystem(type?: string | undefined): void;
    /**
     * @override
     * @param {string} fileSystemPath
     */
    removeFileSystem(fileSystemPath: string): void;
    /**
     * @override
     * @param {string} fileSystemId
     * @param {string} registeredName
     * @return {?FileSystem}
     */
    isolatedFileSystem(fileSystemId: string, registeredName: string): FileSystem | null;
    /**
     * @override
     * @param {string} url
     * @param {string} headers
     * @param {number} streamId
     * @param {function(!LoadNetworkResourceResult):void} callback
     */
    loadNetworkResource(url: string, headers: string, streamId: number, callback: (arg0: LoadNetworkResourceResult) => void): void;
    /**
     * @override
     * @param {function(!Object<string, string>):void} callback
     */
    getPreferences(callback: (arg0: {
        [x: string]: string;
    }) => void): void;
    /**
     * @override
     * @param {string} name
     * @param {string} value
     */
    setPreference(name: string, value: string): void;
    /**
     * @override
     * @param {string} name
     */
    removePreference(name: string): void;
    /**
     * @override
     */
    clearPreferences(): void;
    /**
     * @override
     * @param {!FileSystem} fileSystem
     */
    upgradeDraggedFileSystemPermissions(fileSystem: FileSystem): void;
    /**
     * @override
     * @param {number} requestId
     * @param {string} fileSystemPath
     * @param {string} excludedFolders
     */
    indexPath(requestId: number, fileSystemPath: string, excludedFolders: string): void;
    /**
     * @override
     * @param {number} requestId
     */
    stopIndexing(requestId: number): void;
    /**
     * @override
     * @param {number} requestId
     * @param {string} fileSystemPath
     * @param {string} query
     */
    searchInPath(requestId: number, fileSystemPath: string, query: string): void;
    /**
     * @override
     * @return {number}
     */
    zoomFactor(): number;
    /**
     * @override
     */
    zoomIn(): void;
    /**
     * @override
     */
    zoomOut(): void;
    /**
     * @override
     */
    resetZoom(): void;
    /**
     * @override
     * @param {string} shortcuts
     */
    setWhitelistedShortcuts(shortcuts: string): void;
    /**
     * @override
     * @param {boolean} active
     */
    setEyeDropperActive(active: boolean): void;
    /**
     * @param {!Array<string>} certChain
     * @override
     */
    showCertificateViewer(certChain: Array<string>): void;
    /**
     * @override
     * @param {function():void} callback
     */
    reattach(callback: () => void): void;
    /**
     * @override
     */
    readyForTest(): void;
    /**
     * @override
     */
    connectionReady(): void;
    /**
     * @override
     * @param {boolean} value
     */
    setOpenNewWindowForPopups(value: boolean): void;
    /**
     * @override
     * @param {!Adb.Config} config
     */
    setDevicesDiscoveryConfig(config: Adb.Config): void;
    /**
     * @override
     * @param {boolean} enabled
     */
    setDevicesUpdatesEnabled(enabled: boolean): void;
    /**
     * @override
     * @param {string} pageId
     * @param {string} action
     */
    performActionOnRemotePage(pageId: string, action: string): void;
    /**
     * @override
     * @param {string} browserId
     * @param {string} url
     */
    openRemotePage(browserId: string, url: string): void;
    /**
     * @override
     */
    openNodeFrontend(): void;
    /**
     * @override
     * @param {number} x
     * @param {number} y
     * @param {!Array.<!ContextMenuDescriptor>} items
     * @param {!Document} document
     */
    showContextMenuAtPoint(x: number, y: number, items: Array<ContextMenuDescriptor>, document: Document): void;
    /**
     * @override
     * @return {boolean}
     */
    isHostedMode(): boolean;
    /**
     * @override
     * @param {function(!Root.Runtime.RuntimeExtensionDescriptor):void} callback
     */
    setAddExtensionCallback(callback: (arg0: Root.Runtime.RuntimeExtensionDescriptor) => void): void;
}
/**
 * @type {!InspectorFrontendHostStub}
 */
export let InspectorFrontendHostInstance: InspectorFrontendHostStub;
import { InspectorFrontendHostAPI } from "./InspectorFrontendHostAPI.js";
import * as Common from "../common/common.js";
import { LoadNetworkResourceResult } from "./InspectorFrontendHostAPI.js";
import { ContextMenuDescriptor } from "./InspectorFrontendHostAPI.js";
import * as Root from "../root/root.js";
