export class NodeURL {
    /**
     * @param {!{url: string}} object
     */
    static patch(object: {
        url: string;
    }): void;
    /**
     * @param {string} fileSystemPath
     * @param {boolean} isWindows
     * @return {boolean}
     */
    static _isPlatformPath(fileSystemPath: string, isWindows: boolean): boolean;
}
