/**
 * @template T
 * @unrestricted
 */
export class CharacterIdMap<T> {
    /** @type {!Map<T, string>} */
    _elementToCharacter: Map<T, string>;
    /** @type {!Map<string, T>} */
    _characterToElement: Map<string, T>;
    _charCode: number;
    /**
     * @param {T} object
     * @return {string}
     */
    toChar(object: T): string;
    /**
     * @param {string} character
     * @return {?T}
     */
    fromChar(character: string): T | null;
}
