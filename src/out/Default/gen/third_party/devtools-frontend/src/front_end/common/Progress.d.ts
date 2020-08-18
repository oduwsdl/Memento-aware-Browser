/**
 * @interface
 */
export class Progress {
    /**
     * @param {number} totalWork
     */
    setTotalWork(totalWork: number): void;
    /**
     * @param {string} title
     */
    setTitle(title: string): void;
    /**
     * @param {number} worked
     * @param {string=} title
     */
    setWorked(worked: number, title?: string | undefined): void;
    /**
     * @param {number=} worked
     */
    worked(worked?: number | undefined): void;
    done(): void;
    /**
     * @return {boolean}
     */
    isCanceled(): boolean;
}
/**
 * @unrestricted
 */
export class CompositeProgress {
    /**
     * @param {!Progress} parent
     */
    constructor(parent: Progress);
    _parent: Progress;
    /** @type {!Array.<!SubProgress>} */
    _children: Array<SubProgress>;
    _childrenDone: number;
    _childDone(): void;
    /**
     * @param {number=} weight
     * @return {!SubProgress}
     */
    createSubProgress(weight?: number | undefined): SubProgress;
    _update(): void;
}
/**
 * @implements {Progress}
 * @unrestricted
 */
export class SubProgress implements Progress {
    /**
     * @param {!CompositeProgress} composite
     * @param {number=} weight
     */
    constructor(composite: CompositeProgress, weight?: number | undefined);
    _composite: CompositeProgress;
    _weight: number;
    _worked: number;
    /** @type {number} */
    _totalWork: number;
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
     */
    done(): void;
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
/**
 * @implements {Progress}
 * @unrestricted
 */
export class ProgressProxy implements Progress {
    /**
     * @param {?Progress=} delegate
     * @param {function():void=} doneCallback
     */
    constructor(delegate?: (Progress | null) | undefined, doneCallback?: (() => void) | undefined);
    _delegate: Progress | null | undefined;
    _doneCallback: (() => void) | undefined;
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
     */
    done(): void;
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
