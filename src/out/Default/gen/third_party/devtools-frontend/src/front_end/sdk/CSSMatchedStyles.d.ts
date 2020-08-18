export class CSSMatchedStyles {
    /**
     * @param {!CSSModel} cssModel
     * @param {!DOMNode} node
     * @param {?Protocol.CSS.CSSStyle} inlinePayload
     * @param {?Protocol.CSS.CSSStyle} attributesPayload
     * @param {!Array.<!Protocol.CSS.RuleMatch>} matchedPayload
     * @param {!Array.<!Protocol.CSS.PseudoElementMatches>} pseudoPayload
     * @param {!Array.<!Protocol.CSS.InheritedStyleEntry>} inheritedPayload
     * @param {!Array.<!Protocol.CSS.CSSKeyframesRule>} animationsPayload
     */
    constructor(cssModel: CSSModel, node: DOMNode, inlinePayload: Protocol.CSS.CSSStyle | null, attributesPayload: Protocol.CSS.CSSStyle | null, matchedPayload: Array<Protocol.CSS.RuleMatch>, pseudoPayload: Array<Protocol.CSS.PseudoElementMatches>, inheritedPayload: Array<Protocol.CSS.InheritedStyleEntry>, animationsPayload: Array<Protocol.CSS.CSSKeyframesRule>);
    _cssModel: CSSModel;
    _node: DOMNode;
    /** @type {!Map<!CSSStyleDeclaration, !DOMNode>} */
    _addedStyles: Map<CSSStyleDeclaration, DOMNode>;
    /** @type {!Map<!Protocol.DOM.NodeId, !Map<string, boolean>>} */
    _matchingSelectors: Map<Protocol.DOM.NodeId, Map<string, boolean>>;
    /** @type {!Array.<!CSSKeyframesRule>} */
    _keyframes: Array<CSSKeyframesRule>;
    /** @type {!Map<!CSSStyleDeclaration, ?DOMNode>} */
    _nodeForStyle: Map<CSSStyleDeclaration, DOMNode | null>;
    /** @type {!Set<!CSSStyleDeclaration>} */
    _inheritedStyles: Set<CSSStyleDeclaration>;
    _mainDOMCascade: DOMInheritanceCascade;
    _pseudoDOMCascades: Map<Protocol.DOM.PseudoType, DOMInheritanceCascade>;
    /** @type {!Map<!CSSStyleDeclaration, !DOMInheritanceCascade>} */
    _styleToDOMCascade: Map<CSSStyleDeclaration, DOMInheritanceCascade>;
    /**
     * @param {?Protocol.CSS.CSSStyle} inlinePayload
     * @param {?Protocol.CSS.CSSStyle} attributesPayload
     * @param {!Array.<!Protocol.CSS.RuleMatch>} matchedPayload
     * @param {!Array.<!Protocol.CSS.InheritedStyleEntry>} inheritedPayload
     * @return {!DOMInheritanceCascade}
     */
    _buildMainCascade(inlinePayload: Protocol.CSS.CSSStyle | null, attributesPayload: Protocol.CSS.CSSStyle | null, matchedPayload: Array<Protocol.CSS.RuleMatch>, inheritedPayload: Array<Protocol.CSS.InheritedStyleEntry>): DOMInheritanceCascade;
    /**
     * @param {!Array.<!Protocol.CSS.PseudoElementMatches>} pseudoPayload
     * @return {!Map<!Protocol.DOM.PseudoType, !DOMInheritanceCascade>}
     */
    _buildPseudoCascades(pseudoPayload: Array<Protocol.CSS.PseudoElementMatches>): Map<Protocol.DOM.PseudoType, DOMInheritanceCascade>;
    /**
     * @param {!DOMNode} node
     * @param {!CSSStyleRule} rule
     * @param {!Array<number>} matchingSelectorIndices
     * @this {CSSMatchedStyles}
     */
    _addMatchingSelectors(node: DOMNode, rule: CSSStyleRule, matchingSelectorIndices: Array<number>): void;
    /**
     * @return {!DOMNode}
     */
    node(): DOMNode;
    /**
     * @return {!CSSModel}
     */
    cssModel(): CSSModel;
    /**
     * @param {!CSSStyleRule} rule
     * @return {boolean}
     */
    hasMatchingSelectors(rule: CSSStyleRule): boolean;
    /**
     * @param {!CSSStyleRule} rule
     * @return {!Array<number>}
     */
    matchingSelectors(rule: CSSStyleRule): Array<number>;
    /**
     * @param {!CSSStyleRule} rule
     * @return {!Promise<?>}
     */
    recomputeMatchingSelectors(rule: CSSStyleRule): Promise<unknown>;
    /**
     * @param {!CSSStyleRule} rule
     * @param {!DOMNode} node
     * @return {!Promise<?>}
     */
    addNewRule(rule: CSSStyleRule, node: DOMNode): Promise<unknown>;
    /**
     * @param {!DOMNode} node
     * @param {string} selectorText
     * @param {boolean} value
     */
    _setSelectorMatches(node: DOMNode, selectorText: string, value: boolean): void;
    /**
     * @param {!CSSStyleDeclaration} style
     * @return {boolean}
     */
    mediaMatches(style: CSSStyleDeclaration): boolean;
    /**
     * @return {!Array<!CSSStyleDeclaration>}
     */
    nodeStyles(): Array<CSSStyleDeclaration>;
    /**
     * @return {!Array.<!CSSKeyframesRule>}
     */
    keyframes(): Array<CSSKeyframesRule>;
    /**
     * @param {!Protocol.DOM.PseudoType} pseudoType
     * @return {!Array<!CSSStyleDeclaration>}
     */
    pseudoStyles(pseudoType: Protocol.DOM.PseudoType): Array<CSSStyleDeclaration>;
    /**
     * @return {!Set<!Protocol.DOM.PseudoType>}
     */
    pseudoTypes(): Set<Protocol.DOM.PseudoType>;
    /**
     * @param {!CSSStyleDeclaration} style
     * @return {boolean}
     */
    _containsInherited(style: CSSStyleDeclaration): boolean;
    /**
     * @param {!CSSStyleDeclaration} style
     * @return {?DOMNode}
     */
    nodeForStyle(style: CSSStyleDeclaration): DOMNode | null;
    /**
     * @param {!CSSStyleDeclaration} style
     * @return {!Array<string>}
     */
    availableCSSVariables(style: CSSStyleDeclaration): Array<string>;
    /**
     * @param {!CSSStyleDeclaration} style
     * @param {string} variableName
     * @return {?string}
     */
    computeCSSVariable(style: CSSStyleDeclaration, variableName: string): string | null;
    /**
     * @param {!CSSStyleDeclaration} style
     * @param {string} value
     * @return {?string}
     */
    computeValue(style: CSSStyleDeclaration, value: string): string | null;
    /**
     * @param {!CSSStyleDeclaration} style
     * @return {boolean}
     */
    isInherited(style: CSSStyleDeclaration): boolean;
    /**
     * @param {!CSSProperty} property
     * @return {?PropertyState}
     */
    propertyState(property: CSSProperty): PropertyState | null;
    resetActiveProperties(): void;
}
export type PropertyState = string;
export namespace PropertyState {
    export const Active: string;
    export const Overloaded: string;
}
import { CSSModel } from "./CSSModel.js";
import { DOMNode } from "./DOMModel.js";
import { CSSStyleDeclaration } from "./CSSStyleDeclaration.js";
import { CSSKeyframesRule } from "./CSSRule.js";
declare class DOMInheritanceCascade {
    /**
     * @param {!Array<!NodeCascade>} nodeCascades
     */
    constructor(nodeCascades: Array<NodeCascade>);
    _nodeCascades: NodeCascade[];
    /** @type {!Map<!CSSProperty, !PropertyState>} */
    _propertiesState: Map<CSSProperty, PropertyState>;
    /** @type {!Map<!NodeCascade, !Map<string, string>>} */
    _availableCSSVariables: Map<NodeCascade, Map<string, string>>;
    /** @type {!Map<!NodeCascade, !Map<string, ?string>>} */
    _computedCSSVariables: Map<NodeCascade, Map<string, string | null>>;
    _initialized: boolean;
    /** @type {!Map<!CSSStyleDeclaration, !NodeCascade>} */
    _styleToNodeCascade: Map<CSSStyleDeclaration, NodeCascade>;
    /**
     * @param {!CSSStyleDeclaration} style
     * @return {!Array<string>}
     */
    availableCSSVariables(style: CSSStyleDeclaration): Array<string>;
    /**
     * @param {!CSSStyleDeclaration} style
     * @param {string} variableName
     * @return {?string}
     */
    computeCSSVariable(style: CSSStyleDeclaration, variableName: string): string | null;
    /**
     * @param {!CSSStyleDeclaration} style
     * @param {string} value
     * @return {?string}
     */
    computeValue(style: CSSStyleDeclaration, value: string): string | null;
    /**
     * @param {!Map<string, string>} availableCSSVariables
     * @param {!Map<string, ?string>} computedCSSVariables
     * @param {string} variableName
     * @return {?string}
     */
    _innerComputeCSSVariable(availableCSSVariables: Map<string, string>, computedCSSVariables: Map<string, string | null>, variableName: string): string | null;
    /**
     * @param {!Map<string, string>} availableCSSVariables
     * @param {!Map<string, ?string>} computedCSSVariables
     * @param {string} value
     * @return {?string}
     */
    _innerComputeValue(availableCSSVariables: Map<string, string>, computedCSSVariables: Map<string, string | null>, value: string): string | null;
    /**
     * @return {!Array<!CSSStyleDeclaration>}
     */
    styles(): Array<CSSStyleDeclaration>;
    /**
     * @param {!CSSProperty} property
     * @return {?PropertyState}
     */
    propertyState(property: CSSProperty): PropertyState | null;
    reset(): void;
    _ensureInitialized(): void;
}
import { CSSStyleRule } from "./CSSRule.js";
import { CSSProperty } from "./CSSProperty.js";
declare class NodeCascade {
    /**
     * @param {!CSSMatchedStyles} matchedStyles
     * @param {!Array<!CSSStyleDeclaration>} styles
     * @param {boolean} isInherited
     */
    constructor(matchedStyles: CSSMatchedStyles, styles: Array<CSSStyleDeclaration>, isInherited: boolean);
    _matchedStyles: CSSMatchedStyles;
    _styles: CSSStyleDeclaration[];
    _isInherited: boolean;
    /** @type {!Map<!CSSProperty, !PropertyState>} */
    _propertiesState: Map<CSSProperty, PropertyState>;
    /** @type {!Map.<string, !CSSProperty>} */
    _activeProperties: Map<string, CSSProperty>;
    _computeActiveProperties(): void;
}
export {};
