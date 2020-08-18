/**
 * @interface
 */
export class JavaScriptMetaData {
    /**
     * @param {string} name
     * @return {?Array<!Array<string>>}
     */
    signaturesForNativeFunction(name: string): Array<Array<string>> | null;
    /**
     * @param {string} name
     * @param {string} receiverClassName
     * @return {?Array<!Array<string>>}
     */
    signaturesForInstanceMethod(name: string, receiverClassName: string): Array<Array<string>> | null;
    /**
     * @param {string} name
     * @param {string} receiverConstructorName
     * @return {?Array<!Array<string>>}
     */
    signaturesForStaticMethod(name: string, receiverConstructorName: string): Array<Array<string>> | null;
}
