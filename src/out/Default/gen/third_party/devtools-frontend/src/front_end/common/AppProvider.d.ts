/**
 * @interface
 */
export class AppProvider {
    /**
     * @return {!App}
     */
    createApp(): App;
}
import { App } from "./App.js";
