/**
 * @param {string} prefix
 * @return {string}
 */
export function nextId(prefix: string): string;
/**
 * @param {!Element} label
 * @param {!Element} control
 */
export function bindLabelToControl(label: Element, control: Element): void;
/**
 * @param {!Element} element
 */
export function markAsAlert(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsApplication(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsButton(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsCheckbox(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsCombobox(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsModalDialog(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsGroup(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsLink(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsMenuButton(element: Element): void;
/**
 * @param {!Element} element
 * @param {number=} min
 * @param {number=} max
 */
export function markAsProgressBar(element: Element, min?: number | undefined, max?: number | undefined): void;
/**
 * @param {!Element} element
 */
export function markAsTab(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsTablist(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsTabpanel(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsTree(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsTreeitem(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsTextBox(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsMenu(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsMenuItem(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsMenuItemSubMenu(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsList(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsListitem(element: Element): void;
/**
 * Must contain children whose role is option.
 * @param {!Element} element
 */
export function markAsListBox(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsMultiSelectable(element: Element): void;
/**
 * Must be contained in, or owned by, an element with the role listbox.
 * @param {!Element} element
 */
export function markAsOption(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsRadioGroup(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsHidden(element: Element): void;
/**
 * @param {!Element} element
 * @param {number=} min
 * @param {number=} max
 */
export function markAsSlider(element: Element, min?: number | undefined, max?: number | undefined): void;
/**
 * @param {!Element} element
 * @param {number} level
 */
export function markAsHeading(element: Element, level: number): void;
/**
 * @param {!Element} element
 * @param {boolean} isAtomic
 */
export function markAsPoliteLiveRegion(element: Element, isAtomic: boolean): void;
/**
 * @param {!Element} element
 * @return {boolean}
 */
export function hasRole(element: Element): boolean;
/**
 * @param {!Element} element
 */
export function removeRole(element: Element): void;
/**
 * @param {!Element} element
 * @param {?string} placeholder
 */
export function setPlaceholder(element: Element, placeholder: string | null): void;
/**
 * @param {!Element} element
 */
export function markAsPresentation(element: Element): void;
/**
 * @param {!Element} element
 */
export function markAsStatus(element: Element): void;
/**
 * @param {!Element} element
 */
export function ensureId(element: Element): void;
/**
 * @param {!Element} element
 * @param {string} valueText
 */
export function setAriaValueText(element: Element, valueText: string): void;
/**
 * @param {!Element} element
 * @param {string} value
 */
export function setAriaValueNow(element: Element, value: string): void;
/**
 * @param {!Element} element
 * @param {string} min
 * @param {string} max
 */
export function setAriaValueMinMax(element: Element, min: string, max: string): void;
/**
 * @param {!Element} element
 * @param {?Element} controlledElement
 */
export function setControls(element: Element, controlledElement: Element | null): void;
/**
 * @param {!Element} element
 * @param {boolean} value
 */
export function setChecked(element: Element, value: boolean): void;
/**
 * @param {!Element} element
 */
export function setCheckboxAsIndeterminate(element: Element): void;
/**
 * @param {!Element} element
 * @param {boolean} value
 */
export function setDisabled(element: Element, value: boolean): void;
/**
 * @param {!Element} element
 * @param {boolean} value
 */
export function setExpanded(element: Element, value: boolean): void;
/**
 * @param {!Element} element
 */
export function unsetExpandable(element: Element): void;
/**
 * @param {!Element} element
 * @param {boolean} value
 */
export function setHidden(element: Element, value: boolean): void;
/**
 * @param {!Element} element
 * @param {!AutocompleteInteractionModel=} interactionModel
 */
export function setAutocomplete(element: Element, interactionModel?: AutocompleteInteractionModel | undefined): void;
/**
 * @param {!Element} element
 * @param {boolean} value
 */
export function setSelected(element: Element, value: boolean): void;
export function clearSelected(element: any): void;
/**
 * @param {!Element} element
 * @param {boolean} value
 */
export function setInvalid(element: Element, value: boolean): void;
/**
 * @param {!Element} element
 * @param {boolean} value
 */
export function setPressed(element: Element, value: boolean): void;
/**
 * @param {!Element} element
 * @param {number} value
 */
export function setValueNow(element: Element, value: number): void;
export function setValueText(element: any, value: any): void;
/**
 * @param {!Element} element
 * @param {number} valueNow
 * @param {string=} valueText
 */
export function setProgressBarValue(element: Element, valueNow: number, valueText?: string | undefined): void;
/**
 * @param {!Element} element
 * @param {string} name
 */
export function setAccessibleName(element: Element, name: string): void;
/**
 * @param {!Element} element
 * @param {string} description
 */
export function setDescription(element: Element, description: string): void;
/**
 * @param {!Element} element
 * @param {?Element} activedescendant
 */
export function setActiveDescendant(element: Element, activedescendant: Element | null): void;
/**
 * @param {!Element} element
 * @param {number} size
 */
export function setSetSize(element: Element, size: number): void;
/**
 * @param {!Element} element
 * @param {number} position
 */
export function setPositionInSet(element: Element, position: number): void;
/**
 * This function is used to announce a message with the screen reader.
 * Setting the textContent would allow the SR to access the offscreen element via browse mode
 * Due to existing NVDA bugs (https://github.com/nvaccess/nvda/issues/10140), setting the
 * aria-label of the alert element results in the message being read twice.
 * The current workaround is to set the aria-describedby of the alert element
 * to a description element where the aria-label is set to the message.
 * @param {string} message
 * @param {!Element} element
 */
export function alert(message: string, element: Element): void;
export type AutocompleteInteractionModel = string;
export namespace AutocompleteInteractionModel {
    export const inline: string;
    export const list: string;
    export const both: string;
    export const none: string;
}
