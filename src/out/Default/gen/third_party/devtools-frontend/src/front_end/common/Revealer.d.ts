/**
 * @param {function(?Object, boolean=):!Promise.<undefined>} newReveal
 */
export function setRevealForTest(newReveal: (arg0: Object | null, arg1: boolean | undefined) => Promise<undefined>): void;
/**
 * @interface
 */
export class Revealer {
    /**
     * @param {!Object} object
     * @param {boolean=} omitFocus
     * @return {!Promise<void>}
     */
    reveal(object: Object, omitFocus?: boolean | undefined): Promise<void>;
}
export function reveal(revealable: Object | null, omitFocus?: boolean | undefined): Promise<undefined>;
export function revealDestination(revealable: Object | null): string | null;
