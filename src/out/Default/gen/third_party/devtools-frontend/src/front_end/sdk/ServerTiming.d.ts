export class ServerTiming {
    /**
     * @param {!Array<!NameValue>} headers
     * @return {?Array<!ServerTiming>}
     */
    static parseHeaders(headers: Array<NameValue>): Array<ServerTiming> | null;
    /**
     * TODO(crbug.com/1011811): Instead of using !Object<string, *> we should have a proper type
     *                          with name, desc and dur properties.
     * @param {string} valueString
     * @return {!Array<!Object<string, *>>}
     */
    static createFromHeaderValue(valueString: string): Array<{
        [x: string]: any;
    }>;
    /**
     * @param {string} paramName
     * @return {?function(!Object<string, *>, ?string):void}
     */
    static getParserForParameter(paramName: string): ((arg0: {
        [x: string]: any;
    }, arg1: string | null) => void) | null;
    /**
     * @param {string} msg
     */
    static showWarning(msg: string): void;
    /**
     * @param {string} metric
     * @param {?number} value
     * @param {?string} description
     */
    constructor(metric: string, value: number | null, description: string | null);
    metric: string;
    value: number | null;
    description: string | null;
}
import { NameValue } from "./NetworkRequest.js";
