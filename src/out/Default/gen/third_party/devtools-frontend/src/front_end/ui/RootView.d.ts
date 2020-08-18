/**
 * @unrestricted
 */
export class RootView extends VBox {
    /**
     * @param {!Document} document
     */
    attachToDocument(document: Document): void;
    _window: (Window & typeof globalThis) | null | undefined;
}
import { VBox } from "./Widget.js";
