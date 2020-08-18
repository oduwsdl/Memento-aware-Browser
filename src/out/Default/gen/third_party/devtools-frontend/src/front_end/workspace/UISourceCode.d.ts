/**
 * @implements {TextUtils.ContentProvider.ContentProvider}
 * @unrestricted
 */
export class UISourceCode extends Common.ObjectWrapper.ObjectWrapper implements TextUtils.ContentProvider.ContentProvider {
    /**
     * @param {!Project} project
     * @param {string} url
     * @param {!Common.ResourceType.ResourceType} contentType
     */
    constructor(project: Project, url: string, contentType: Common.ResourceType.ResourceType);
    _project: Project;
    /** @type {string} */
    _url: string;
    _origin: string;
    _parentURL: string;
    _name: string;
    _contentType: Common.ResourceType.ResourceType;
    /** @type {?Promise<!TextUtils.ContentProvider.DeferredContent>} */
    _requestContentPromise: Promise<TextUtils.ContentProvider.DeferredContent> | null;
    /** @type {?Platform.Multimap<string, !LineMarker>} */
    _decorations: Platform.Multimap<string, LineMarker> | null;
    _hasCommits: boolean;
    /** @type {?Set<!Message>} */
    _messages: Set<Message> | null;
    _contentLoaded: boolean;
    /** @type {?TextUtils.ContentProvider.DeferredContent} */
    _content: TextUtils.ContentProvider.DeferredContent | null;
    _forceLoadOnCheckContent: boolean;
    _checkingContent: boolean;
    /** @type {?string} */
    _lastAcceptedContent: string | null;
    /** @type {?string} */
    _workingCopy: string | null;
    /** @type {?function() : string} */
    _workingCopyGetter: (() => string) | null;
    _disableEdit: boolean;
    /**
     * @return {!Promise<?UISourceCodeMetadata>}
     */
    requestMetadata(): Promise<UISourceCodeMetadata | null>;
    /**
     * @return {string}
     */
    name(): string;
    /**
     * @return {string}
     */
    mimeType(): string;
    /**
     * @return {string}
     */
    url(): string;
    /**
     * @return {string}
     */
    parentURL(): string;
    /**
     * @return {string}
     */
    origin(): string;
    /**
     * @return {string}
     */
    fullDisplayName(): string;
    /**
     * @param {boolean=} skipTrim
     * @return {string}
     */
    displayName(skipTrim?: boolean | undefined): string;
    /**
     * @return {boolean}
     */
    canRename(): boolean;
    /**
     * @param {string} newName
     * @return {!Promise<boolean>}
     */
    rename(newName: string): Promise<boolean>;
    remove(): void;
    /**
     * @param {string} name
     * @param {string} url
     * @param {!Common.ResourceType.ResourceType=} contentType
     */
    _updateName(name: string, url: string, contentType?: Common.ResourceType.ResourceType | undefined): void;
    /**
     * @override
     * @return {string}
     */
    contentURL(): string;
    /**
     * @override
     * @return {!Common.ResourceType.ResourceType}
     */
    contentType(): Common.ResourceType.ResourceType;
    /**
     * @override
     * @return {!Promise<boolean>}
     */
    contentEncoded(): Promise<boolean>;
    /**
     * @return {!Project}
     */
    project(): Project;
    /**
     * @override
     * @return {!Promise<!TextUtils.ContentProvider.DeferredContent>}
     */
    requestContent(): Promise<TextUtils.ContentProvider.DeferredContent>;
    /**
     * @returns {!Promise<!TextUtils.ContentProvider.DeferredContent>}
     */
    _requestContentImpl(): Promise<TextUtils.ContentProvider.DeferredContent>;
    _contentEncoded: boolean | undefined;
    checkContentUpdated(): Promise<void>;
    forceLoadOnCheckContent(): void;
    /**
     * @param {string} content
     */
    _commitContent(content: string): void;
    /**
     * @param {string} content
     * @param {boolean} committedByUser
     */
    _contentCommitted(content: string, committedByUser: boolean): void;
    /**
     * @param {string} content
     */
    addRevision(content: string): void;
    /**
     * @return {boolean}
     */
    hasCommits(): boolean;
    /**
     * @return {string}
     */
    workingCopy(): string;
    resetWorkingCopy(): void;
    _innerResetWorkingCopy(): void;
    /**
     * @param {string} newWorkingCopy
     */
    setWorkingCopy(newWorkingCopy: string): void;
    /**
     * @param {string} content
     * @param {boolean} isBase64
     */
    setContent(content: string, isBase64: boolean): void;
    /**
    * @param {function(): string } workingCopyGetter
    */
    setWorkingCopyGetter(workingCopyGetter: () => string): void;
    _workingCopyChanged(): void;
    removeWorkingCopyGetter(): void;
    commitWorkingCopy(): void;
    /**
     * @return {boolean}
     */
    isDirty(): boolean;
    /**
     * @return {string}
     */
    extension(): string;
    /**
     * @return {string}
     */
    content(): string;
    /**
     * @return {?string}
     */
    loadError(): string | null;
    /**
     * @override
     * @param {string} query
     * @param {boolean} caseSensitive
     * @param {boolean} isRegex
     * @return {!Promise<!Array<!TextUtils.ContentProvider.SearchMatch>>}
     */
    searchInContent(query: string, caseSensitive: boolean, isRegex: boolean): Promise<Array<TextUtils.ContentProvider.SearchMatch>>;
    /**
     * @return {boolean}
     */
    contentLoaded(): boolean;
    /**
     * @param {number} lineNumber
     * @param {number=} columnNumber
     * @return {!UILocation}
     */
    uiLocation(lineNumber: number, columnNumber?: number | undefined): UILocation;
    /**
     * @return {!Set<!Message>}
     */
    messages(): Set<Message>;
    /**
     * @param {!Message.Level} level
     * @param {string} text
     * @param {number} lineNumber
     * @param {number=} columnNumber
     * @return {!Message} message
     */
    addLineMessage(level: Message.Level, text: string, lineNumber: number, columnNumber?: number | undefined): Message;
    /**
     * @param {!Message.Level} level
     * @param {string} text
     * @param {!TextUtils.TextRange.TextRange} range
     * @return {!Message} message
     */
    addMessage(level: Message.Level, text: string, range: TextUtils.TextRange.TextRange): Message;
    /**
     * @param {!Message} message
     */
    removeMessage(message: Message): void;
    _removeAllMessages(): void;
    /**
     * @param {number} lineNumber
     * @param {string} type
     * @param {?} data
     */
    addLineDecoration(lineNumber: number, type: string, data: unknown): void;
    /**
     * @param {!TextUtils.TextRange.TextRange} range
     * @param {string} type
     * @param {?} data
     */
    addDecoration(range: TextUtils.TextRange.TextRange, type: string, data: unknown): void;
    /**
     * @param {string} type
     */
    removeDecorationsForType(type: string): void;
    /**
     * @return {!Array<!LineMarker>}
     */
    allDecorations(): Array<LineMarker>;
    removeAllDecorations(): void;
    /**
     * @param {string} type
     * @return {?Set<!LineMarker>}
     */
    decorationsForType(type: string): Set<LineMarker> | null;
    disableEdit(): void;
    /**
     * @return {boolean}
     */
    editDisabled(): boolean;
}
export type Events = symbol;
export namespace Events {
    export const WorkingCopyChanged: symbol;
    export const WorkingCopyCommitted: symbol;
    export const TitleChanged: symbol;
    export const MessageAdded: symbol;
    export const MessageRemoved: symbol;
    export const LineDecorationAdded: symbol;
    export const LineDecorationRemoved: symbol;
}
/**
 * @unrestricted
 */
export class UILocation {
    /**
     * @param {!UILocation} location1
     * @param {!UILocation} location2
     * @return {number}
     */
    static comparator(location1: UILocation, location2: UILocation): number;
    /**
     * @param {!UISourceCode} uiSourceCode
     * @param {number} lineNumber
     * @param {number} columnNumber
     */
    constructor(uiSourceCode: UISourceCode, lineNumber: number, columnNumber: number);
    uiSourceCode: UISourceCode;
    lineNumber: number;
    columnNumber: number;
    /**
     * @param {boolean=} skipTrim
     * @return {string}
     */
    linkText(skipTrim?: boolean | undefined): string;
    /**
     * @return {string}
     */
    id(): string;
    /**
     * @return {string}
     */
    lineId(): string;
    /**
     * @return {string}
     */
    toUIString(): string;
    /**
     * @param {!UILocation} other
     * @return {number}
     */
    compareTo(other: UILocation): number;
}
/**
 * @unrestricted
 */
export class Message {
    /**
     * @param {!UISourceCode} uiSourceCode
     * @param {!Message.Level} level
     * @param {string} text
     * @param {!TextUtils.TextRange.TextRange} range
     */
    constructor(uiSourceCode: UISourceCode, level: Message.Level, text: string, range: TextUtils.TextRange.TextRange);
    _uiSourceCode: UISourceCode;
    _level: string;
    _text: string;
    _range: TextUtils.TextRange.TextRange;
    /**
     * @return {!UISourceCode}
     */
    uiSourceCode(): UISourceCode;
    /**
     * @return {!Message.Level}
     */
    level(): Message.Level;
    /**
     * @return {string}
     */
    text(): string;
    /**
     * @return {!TextUtils.TextRange.TextRange}
     */
    range(): TextUtils.TextRange.TextRange;
    /**
     * @return {number}
     */
    lineNumber(): number;
    /**
     * @return {(number|undefined)}
     */
    columnNumber(): (number | undefined);
    /**
     * @param {!Message} another
     * @return {boolean}
     */
    isEqual(another: Message): boolean;
    remove(): void;
}
export namespace Message {
    export namespace Level {
        export const Error: string;
        export const Warning: string;
    }
    export type Level = string;
}
/**
 * @unrestricted
 */
export class LineMarker {
    /**
     * @param {!TextUtils.TextRange.TextRange} range
     * @param {string} type
     * @param {?} data
     */
    constructor(range: TextUtils.TextRange.TextRange, type: string, data: unknown);
    _range: TextUtils.TextRange.TextRange;
    _type: string;
    _data: any;
    /**
     * @return {!TextUtils.TextRange.TextRange}
     */
    range(): TextUtils.TextRange.TextRange;
    /**
     * @return {string}
     */
    type(): string;
    /**
     * @return {*}
     */
    data(): any;
}
/**
 * @unrestricted
 */
export class UISourceCodeMetadata {
    /**
     * @param {?Date} modificationTime
     * @param {?number} contentSize
     */
    constructor(modificationTime: Date | null, contentSize: number | null);
    modificationTime: Date | null;
    contentSize: number | null;
}
import * as Common from "../common/common.js";
import * as TextUtils from "../text_utils/text_utils.js";
import { Project } from "./WorkspaceImpl.js";
import * as Platform from "../platform/platform.js";
