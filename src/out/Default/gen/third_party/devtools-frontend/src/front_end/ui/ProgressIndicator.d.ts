/**
 * @implements {Common.Progress.Progress}
 * @unrestricted
 */
export class ProgressIndicator implements Common.Progress.Progress {
    element: HTMLDivElement;
    _shadowRoot: DocumentFragment;
    _contentElement: any;
    _labelElement: any;
    _progressElement: any;
    _stopButton: any;
    _isCanceled: boolean;
    _worked: number;
    /**
     * @param {!Element} parent
     */
    show(parent: Element): void;
    /**
     * @override
     */
    done(): void;
    _isDone: boolean | undefined;
    cancel(): void;
    /**
     * @override
     * @return {boolean}
     */
    isCanceled(): boolean;
    /**
     * @override
     * @param {string} title
     */
    setTitle(title: string): void;
    /**
     * @override
     * @param {number} totalWork
     */
    setTotalWork(totalWork: number): void;
    /**
     * @override
     * @param {number} worked
     * @param {string=} title
     */
    setWorked(worked: number, title?: string | undefined): void;
    /**
     * @override
     * @param {number=} worked
     */
    worked(worked?: number | undefined): void;
}
import * as Common from "../common/common.js";
