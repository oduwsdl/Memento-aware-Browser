/**
 * @interface
 */
export class ProjectSearchConfig {
    /**
     * @return {string}
     */
    query(): string;
    /**
     * @return {boolean}
     */
    ignoreCase(): boolean;
    /**
     * @return {boolean}
     */
    isRegex(): boolean;
    /**
     * @return {!Array.<string>}
     */
    queries(): Array<string>;
    /**
     * @param {string} filePath
     * @return {boolean}
     */
    filePathMatchesFileQuery(filePath: string): boolean;
}
/**
 * @interface
 */
export class Project {
    /**
     * @return {!WorkspaceImpl}
     */
    workspace(): WorkspaceImpl;
    /**
     * @return {string}
     */
    id(): string;
    /**
     * @return {string}
     */
    type(): string;
    /**
     * @return {boolean}
     */
    isServiceProject(): boolean;
    /**
     * @return {string}
     */
    displayName(): string;
    /**
     * @param {!UISourceCode} uiSourceCode
     * @return {!Promise<?UISourceCodeMetadata>}
     */
    requestMetadata(uiSourceCode: UISourceCode): Promise<UISourceCodeMetadata | null>;
    /**
     * @param {!UISourceCode} uiSourceCode
     * @return {!Promise<!TextUtils.ContentProvider.DeferredContent>}
     */
    requestFileContent(uiSourceCode: UISourceCode): Promise<TextUtils.ContentProvider.DeferredContent>;
    /**
     * @return {boolean}
     */
    canSetFileContent(): boolean;
    /**
     * @param {!UISourceCode} uiSourceCode
     * @param {string} newContent
     * @param {boolean} isBase64
     * @return {!Promise<void>}
     */
    setFileContent(uiSourceCode: UISourceCode, newContent: string, isBase64: boolean): Promise<void>;
    /**
     * @param {!UISourceCode} uiSourceCode
     * @return {string}
     */
    fullDisplayName(uiSourceCode: UISourceCode): string;
    /**
     * @param {!UISourceCode} uiSourceCode
     * @return {string}
     */
    mimeType(uiSourceCode: UISourceCode): string;
    /**
     * @return {boolean}
     */
    canRename(): boolean;
    /**
     * @param {!UISourceCode} uiSourceCode
     * @param {string} newName
     * @param {function(boolean, string=, string=, !Common.ResourceType.ResourceType=):void} callback
     */
    rename(uiSourceCode: UISourceCode, newName: string, callback: (arg0: boolean, arg1: string | undefined, arg2: string | undefined, arg3: Common.ResourceType.ResourceType | undefined) => void): void;
    /**
     * @param {string} path
     */
    excludeFolder(path: string): void;
    /**
     * @param {string} path
     * @return {boolean}
     */
    canExcludeFolder(path: string): boolean;
    /**
     * @param {string} path
     * @param {?string} name
     * @param {string} content
     * @param {boolean=} isBase64
     * @return {!Promise<?UISourceCode>}
     */
    createFile(path: string, name: string | null, content: string, isBase64?: boolean | undefined): Promise<UISourceCode | null>;
    /**
     * @return {boolean}
     */
    canCreateFile(): boolean;
    /**
     * @param {!UISourceCode} uiSourceCode
     */
    deleteFile(uiSourceCode: UISourceCode): void;
    remove(): void;
    /**
     * @param {!UISourceCode} uiSourceCode
     * @param {string} query
     * @param {boolean} caseSensitive
     * @param {boolean} isRegex
     * @return {!Promise<!Array<!TextUtils.ContentProvider.SearchMatch>>}
     */
    searchInFileContent(uiSourceCode: UISourceCode, query: string, caseSensitive: boolean, isRegex: boolean): Promise<Array<TextUtils.ContentProvider.SearchMatch>>;
    /**
     * @param {!ProjectSearchConfig} searchConfig
     * @param {!Array.<string>} filesMathingFileQuery
     * @param {!Common.Progress.Progress} progress
     * @return {!Promise<!Array<string>>}
     */
    findFilesMatchingSearchRequest(searchConfig: ProjectSearchConfig, filesMathingFileQuery: Array<string>, progress: Common.Progress.Progress): Promise<Array<string>>;
    /**
     * @param {!Common.Progress.Progress} progress
     */
    indexContent(progress: Common.Progress.Progress): void;
    /**
     * @param {string} url
     * @return {?UISourceCode}
     */
    uiSourceCodeForURL(url: string): UISourceCode | null;
    /**
     * @return {!Array.<!UISourceCode>}
     */
    uiSourceCodes(): Array<UISourceCode>;
}
export type projectTypes = string;
export namespace projectTypes {
    export const Debugger: string;
    export const Formatter: string;
    export const Network: string;
    export const FileSystem: string;
    export const ContentScripts: string;
    export const Service: string;
}
/**
 * @unrestricted
 */
export class ProjectStore {
    /**
     * @param {!WorkspaceImpl} workspace
     * @param {string} id
     * @param {projectTypes} type
     * @param {string} displayName
     */
    constructor(workspace: WorkspaceImpl, id: string, type: projectTypes, displayName: string);
    _workspace: WorkspaceImpl;
    _id: string;
    _type: string;
    _displayName: string;
    /** @type {!Map.<string, !{uiSourceCode: !UISourceCode, index: number}>} */
    _uiSourceCodesMap: Map<string, {
        uiSourceCode: UISourceCode;
        index: number;
    }>;
    /** @type {!Array.<!UISourceCode>} */
    _uiSourceCodesList: Array<UISourceCode>;
    _project: Project;
    /**
     * @return {string}
     */
    id(): string;
    /**
     * @return {string}
     */
    type(): string;
    /**
     * @return {string}
     */
    displayName(): string;
    /**
     * @return {!WorkspaceImpl}
     */
    workspace(): WorkspaceImpl;
    /**
     * @param {string} url
     * @param {!Common.ResourceType.ResourceType} contentType
     * @return {!UISourceCode}
     */
    createUISourceCode(url: string, contentType: Common.ResourceType.ResourceType): UISourceCode;
    /**
     * @param {!UISourceCode} uiSourceCode
     * @return {boolean}
     */
    addUISourceCode(uiSourceCode: UISourceCode): boolean;
    /**
     * @param {string} url
     */
    removeUISourceCode(url: string): void;
    removeProject(): void;
    /**
     * @param {string} url
     * @return {?UISourceCode}
     */
    uiSourceCodeForURL(url: string): UISourceCode | null;
    /**
     * @return {!Array.<!UISourceCode>}
     */
    uiSourceCodes(): Array<UISourceCode>;
    /**
     * @param {!UISourceCode} uiSourceCode
     * @param {string} newName
     */
    renameUISourceCode(uiSourceCode: UISourceCode, newName: string): void;
}
/**
 * @unrestricted
 */
export class WorkspaceImpl extends Common.ObjectWrapper.ObjectWrapper {
    /**
     * @param {{forceNew: ?boolean}} opts
     */
    static instance(opts?: {
        forceNew: boolean | null;
    }): WorkspaceImpl;
    /** @type {!Map<string, !Project>} */
    _projects: Map<string, Project>;
    _hasResourceContentTrackingExtensions: boolean;
    /**
     * @param {string} projectId
     * @param {string} url
     * @return {?UISourceCode}
     */
    uiSourceCode(projectId: string, url: string): UISourceCode | null;
    /**
     * @param {string} url
     * @return {?UISourceCode}
     */
    uiSourceCodeForURL(url: string): UISourceCode | null;
    /**
     * @param {string} type
     * @return {!Array.<!UISourceCode>}
     */
    uiSourceCodesForProjectType(type: string): Array<UISourceCode>;
    /**
     * @param {!Project} project
     */
    addProject(project: Project): void;
    /**
     * @param {!Project} project
     */
    _removeProject(project: Project): void;
    /**
     * @param {string} projectId
     * @return {?Project}
     */
    project(projectId: string): Project | null;
    /**
     * @return {!Array.<!Project>}
     */
    projects(): Array<Project>;
    /**
     * @param {string} type
     * @return {!Array.<!Project>}
     */
    projectsForType(type: string): Array<Project>;
    /**
     * @return {!Array.<!UISourceCode>}
     */
    uiSourceCodes(): Array<UISourceCode>;
    /**
     * @param {boolean} hasExtensions
     */
    setHasResourceContentTrackingExtensions(hasExtensions: boolean): void;
    /**
     * @return {boolean}
     */
    hasResourceContentTrackingExtensions(): boolean;
}
export type Events = symbol;
export namespace Events {
    export const UISourceCodeAdded: symbol;
    export const UISourceCodeRemoved: symbol;
    export const UISourceCodeRenamed: symbol;
    export const WorkingCopyChanged: symbol;
    export const WorkingCopyCommitted: symbol;
    export const WorkingCopyCommittedByUser: symbol;
    export const ProjectAdded: symbol;
    export const ProjectRemoved: symbol;
}
import { UISourceCode } from "./UISourceCode.js";
import { UISourceCodeMetadata } from "./UISourceCode.js";
import * as TextUtils from "../text_utils/text_utils.js";
import * as Common from "../common/common.js";
