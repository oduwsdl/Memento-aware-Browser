/**
 * @interface
 */
export class OutputStream {
    /**
     * @param {string} data
     * @return {!Promise.<void>}
     */
    write(data: string): Promise<void>;
    /**
     * @return {!Promise.<void>}
     */
    close(): Promise<void>;
}
/**
 * @implements {OutputStream}
 */
export class StringOutputStream implements OutputStream {
    _data: string;
    /**
     * @override
     * @param {string} chunk
     * @return {!Promise.<void>}
     */
    write(chunk: string): Promise<void>;
    /**
     * @override
     * @return {!Promise.<void>}
     */
    close(): Promise<void>;
    /**
     * @return {string}
     */
    data(): string;
}
