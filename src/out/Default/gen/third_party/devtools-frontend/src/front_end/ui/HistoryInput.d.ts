export class HistoryInput extends HTMLInputElement {
    /**
     * @return {!HistoryInput}
     */
    static create(): HistoryInput;
    _history: string[];
    _historyPosition: number;
    /**
     * @param {!Event} event
     */
    _onInput(event: Event): void;
    /**
     * @param {!Event} event
     */
    _onKeyDown(event: Event): void;
    _saveToHistory(): void;
}
