/**
 * @param {string} localName
 * @param {string} typeExtension
 * @param {function(new:HTMLElement, *):void} definition
 * @return {function():void}
 * @suppressGlobalPropertiesCheck
 */
export function registerCustomElement(localName: string, typeExtension: string, definition: new (arg1: any) => HTMLElement): () => void;
