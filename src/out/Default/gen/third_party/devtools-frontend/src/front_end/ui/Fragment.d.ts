export class Fragment {
    /**
     * @param {!Array<string>} strings
     * @param {...*} values
     * @return {!Fragment}
     */
    static build(strings: Array<string>, ...values: any[]): Fragment;
    /**
     * @param {!Array<string>} strings
     * @param {...*} values
     * @return {!Fragment}
     */
    static cached(strings: Array<string>, ...values: any[]): Fragment;
    /**
     * @param {!Array<string>} strings
     * @return {!_Template}
     * @suppressGlobalPropertiesCheck
     */
    static _template(strings: Array<string>): _Template;
    /**
     * @param {!_Template} template
     * @param {!Array<*>} values
     * @return {!Fragment}
     */
    static _render(template: _Template, values: Array<any>): Fragment;
    /**
     * @param {*} value
     * @return {!Node}
     */
    static _nodeForValue(value: any): Node;
    /**
     * @param {!Element} element
     */
    constructor(element: Element);
    _element: Element;
    /** @type {!Map<string, !Element>} */
    _elementsById: Map<string, Element>;
    /**
     * @return {!Element}
     */
    element(): Element;
    /**
     * @param {string} elementId
     * @return {!Element}
     */
    $(elementId: string): Element;
}
export const _textMarker: "{{template-text}}";
export function _attributeMarker(index: any): string;
export function html(strings: Array<string>, ...vararg: any[]): Element;
/**
  * @typedef {!{
  *   elementId: (string|undefined),
  *
  *   attr: (!{
  *     index: number,
  *     names: !Array<string>,
  *     values: !Array<string>
  *   }|undefined),
  *
  *   replaceNodeIndex: (number|undefined)
  * }}
  */
export let _Bind: any;
export type _Template = {
    template: Element;
    binds: Array<any>;
};
/**
 * @typedef {!{
  *   template: !Element,
  *   binds: !Array<!_Bind>
  * }}
  */
export let _Template: any;
/**
 * : (!{
 *     index: number,
 *     names: !Array<string>,
 *     values: !Array<string>
 *   }|undefined),
 *
 *   replaceNodeIndex: (number|undefined)
 * }}
 */
export type attr = {
    elementId: (string | undefined);
};
