/**
 * @interface
 */
export class Runnable {
    /**
     * @return {!Promise.<void>}
     */
    run(): Promise<void>;
}
