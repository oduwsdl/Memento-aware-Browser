/**
 * @return {!CSSMetadata}
 */
export function cssMetadata(): CSSMetadata;
export class CSSMetadata {
    /**
     * @param {string} a
     * @param {string} b
     */
    static _sortPrefixesToEnd(a: string, b: string): 0 | 1 | -1;
    /**
     * @param {!Array<!CSSPropertyDefinition>} properties
     * @param {!Map<string, string>} aliasesFor
     */
    constructor(properties: Array<CSSPropertyDefinition>, aliasesFor: Map<string, string>);
    /** @type {!Array<string>} */
    _values: Array<string>;
    /** @type {!Map<string, !Array<string>>} */
    _longhands: Map<string, Array<string>>;
    /** @type {!Map<string, !Array<string>>} */
    _shorthands: Map<string, Array<string>>;
    /** @type {!Set<string>} */
    _inherited: Set<string>;
    /** @type {!Set<string>} */
    _svgProperties: Set<string>;
    /** @type {!Map<string, !Array<string>>} */
    _propertyValues: Map<string, Array<string>>;
    /** @type {!Map<string, string>} */
    _aliasesFor: Map<string, string>;
    _valuesSet: Set<string>;
    /** @type {!Array<string>} */
    _nameValuePresets: Array<string>;
    /** @type {!Array<string>} */
    _nameValuePresetsIncludingSVG: Array<string>;
    /**
     * @return {!Array<string>}
     */
    allProperties(): Array<string>;
    /**
     * @param {boolean=} includeSVG
     * @return {!Array<string>}
     */
    nameValuePresets(includeSVG?: boolean | undefined): Array<string>;
    /**
     * @param {string} name
     * @return {boolean}
     */
    isSVGProperty(name: string): boolean;
    /**
     * @param {string} shorthand
     * @return {?Array<string>}
     */
    longhands(shorthand: string): Array<string> | null;
    /**
     * @param {string} longhand
     * @return {?Array<string>}
     */
    shorthands(longhand: string): Array<string> | null;
    /**
     * @param {string} propertyName
     * @return {boolean}
     */
    isColorAwareProperty(propertyName: string): boolean;
    /**
     * @param {string} propertyName
     * @return {boolean}
     */
    isGridAreaDefiningProperty(propertyName: string): boolean;
    /**
     * @param {string} propertyName
     * @return {boolean}
     */
    isLengthProperty(propertyName: string): boolean;
    /**
     * @param {string} propertyName
     * @return {boolean}
     */
    isBezierAwareProperty(propertyName: string): boolean;
    /**
     * @param {string} propertyName
     * @return {boolean}
     */
    isCustomProperty(propertyName: string): boolean;
    /**
     * @param {string} propertyName
     * @return {boolean}
     */
    isShadowProperty(propertyName: string): boolean;
    /**
     * @param {string} propertyName
     * @return {boolean}
     */
    isStringProperty(propertyName: string): boolean;
    /**
     * @param {string} name
     * @return {string}
     */
    canonicalPropertyName(name: string): string;
    /**
     * @param {string} propertyName
     * @return {boolean}
     */
    isCSSPropertyName(propertyName: string): boolean;
    /**
     * @param {string} propertyName
     * @return {boolean}
     */
    isPropertyInherited(propertyName: string): boolean;
    /**
     * @param {string} propertyName
     * @return {!Array<string>}
     */
    _specificPropertyValues(propertyName: string): Array<string>;
    /**
     * @param {string} propertyName
     * @return {!Array<string>}
     */
    propertyValues(propertyName: string): Array<string>;
    /**
     * @param {string} property
     * @return {number}
     */
    propertyUsageWeight(property: string): number;
    /**
     * @param {string} key
     * @param {string} value
     * @return {?{text: string, startColumn: number, endColumn: number}}
     */
    getValuePreset(key: string, value: string): {
        text: string;
        startColumn: number;
        endColumn: number;
    } | null;
}
export const VariableRegex: RegExp;
export const URLRegex: RegExp;
/**
 * Matches an instance of a grid area 'row' definition.
 * 'grid-template-areas', e.g.
 *    "a a ."
 *
 * 'grid', 'grid-template', e.g.
 *    [track-name] "a a ." minmax(50px, auto) [track-name]
 */
export const GridAreaRowRegex: RegExp;
export type CSSPropertyDefinition = {
    name: string;
    longhands: Array<string> | null;
    inherited: boolean | null;
    svg: boolean | null;
};
/**
 * @typedef {{name: string, longhands: ?Array<string>, inherited: ?boolean, svg: ?boolean}}
 */
export let CSSPropertyDefinition: any;
