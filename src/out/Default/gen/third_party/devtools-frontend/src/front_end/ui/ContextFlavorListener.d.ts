/**
 * @interface
 */
export class ContextFlavorListener {
    /**
     * @param {?Object} object
     */
    flavorChanged(object: Object | null): void;
}
