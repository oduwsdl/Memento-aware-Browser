/**
 * @unrestricted
 */
export class ReportView extends VBox {
    /**
     * @param {string=} title
     */
    constructor(title?: string | undefined);
    _contentBox: HTMLElement;
    _headerElement: HTMLElement;
    _titleElement: HTMLElement;
    _sectionList: HTMLElement;
    /**
     * @param {string} title
     */
    setTitle(title: string): void;
    /**
     * @param {string} subtitle
     */
    setSubtitle(subtitle: string): void;
    _subtitleElement: HTMLElement | undefined;
    /**
     * @param {?Element} link
     */
    setURL(link: Element | null): void;
    _urlElement: HTMLElement | undefined;
    /**
     * @return {!Toolbar}
     */
    createToolbar(): Toolbar;
    /**
     * @param {string} title
     * @param {string=} className
     * @return {!Section}
     */
    appendSection(title: string, className?: string | undefined): Section;
    /**
     * @param {function(!Section, !Section): number} comparator
     */
    sortSections(comparator: (arg0: Section, arg1: Section) => number): void;
    /**
     * @param {boolean} visible
     */
    setHeaderVisible(visible: boolean): void;
    /**
     * @param {boolean} scrollable
     */
    setBodyScrollable(scrollable: boolean): void;
}
export class Section extends VBox {
    /**
     * @param {string} title
     * @param {string=} className
     */
    constructor(title: string, className?: string | undefined);
    _headerElement: HTMLElement;
    _titleElement: HTMLElement;
    _fieldList: HTMLElement;
    /** @type {!Map.<string, !Element>} */
    _fieldMap: Map<string, Element>;
    /**
     * @return {string}
     */
    title(): string;
    /**
     * @param {string} title
     */
    setTitle(title: string): void;
    /**
     * Declares the overall container to be a group and assigns a title.
     * @param {string} groupTitle
     */
    setUiGroupTitle(groupTitle: string): void;
    /**
     * @return {!Toolbar}
     */
    createToolbar(): Toolbar;
    /**
     * @param {string} title
     * @param {string=} textValue
     * @return {!Element}
     */
    appendField(title: string, textValue?: string | undefined): Element;
    /**
    * @param {string} title
    * @param {string=} textValue
    * @return {!Element}
    */
    appendFlexedField(title: string, textValue?: string | undefined): Element;
    /**
     * @param {string} title
     */
    removeField(title: string): void;
    /**
     * @param {string} title
     * @param {boolean} visible
     */
    setFieldVisible(title: string, visible: boolean): void;
    /**
     * @param {string} title
     * @return {?Element}
     */
    fieldValue(title: string): Element | null;
    /**
     * @return {!Element}
     */
    appendRow(): Element;
    /**
     * @return {!Element}
     */
    appendSelectableRow(): Element;
    clearContent(): void;
    markFieldListAsGroup(): void;
    /**
     * @param {boolean} masked
     */
    setIconMasked(masked: boolean): void;
}
import { VBox } from "./Widget.js";
import { Toolbar } from "./Toolbar.js";
