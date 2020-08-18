/**
 * @type {number}
 */
export const _Eps: number;
export class Vector {
    /**
     * @param {number} x
     * @param {number} y
     * @param {number} z
     */
    constructor(x: number, y: number, z: number);
    x: number;
    y: number;
    z: number;
    /**
     * @return {number}
     */
    length(): number;
    normalize(): void;
}
export class Point {
    /**
     * @param {number} x
     * @param {number} y
     */
    constructor(x: number, y: number);
    x: number;
    y: number;
    /**
     * @param {!Point} p
     * @return {number}
     */
    distanceTo(p: Point): number;
    /**
     * @param {!Point} line
     * @return {!Point}
     */
    projectOn(line: Point): Point;
    /**
     * @param {number} scalar
     * @return {!Point}
     */
    scale(scalar: number): Point;
    /**
     * @override
     * @return {string}
     */
    toString(): string;
}
export class CubicBezier {
    /**
     * @param {string} text
     * @return {?CubicBezier}
     */
    static parse(text: string): CubicBezier | null;
    /**
     * @param {!Point} point1
     * @param {!Point} point2
     */
    constructor(point1: Point, point2: Point);
    controlPoints: Point[];
    /**
     * @param {number} t
     * @return {!Point}
     */
    evaluateAt(t: number): Point;
    /**
     * @return {string}
     */
    asCSSText(): string;
}
export namespace CubicBezier {
    export const Regex: RegExp;
    export const KeywordValues: {
        linear: string;
        ease: string;
        'ease-in': string;
        'ease-in-out': string;
        'ease-out': string;
    };
}
export class EulerAngles {
    /**
     * @param {!CSSMatrix} rotationMatrix
     * @return {!EulerAngles}
     */
    static fromRotationMatrix(rotationMatrix: any): EulerAngles;
    /**
     * @param {number} alpha
     * @param {number} beta
     * @param {number} gamma
     */
    constructor(alpha: number, beta: number, gamma: number);
    alpha: number;
    beta: number;
    gamma: number;
    /**
     * @return {string}
     */
    toRotate3DString(): string;
}
export function scalarProduct(u: Vector, v: Vector): number;
export function crossProduct(u: Vector, v: Vector): Vector;
export function subtract(u: Vector, v: Vector): Vector;
export function multiplyVectorByMatrixAndNormalize(v: Vector, m: any): Vector;
export function calculateAngle(u: Vector, v: Vector): number;
export function degreesToRadians(deg: number): number;
export function radiansToDegrees(rad: number): number;
export function boundsForTransformedPoints(matrix: any, points: Array<number>, aggregateBounds?: {
    minX: number;
    maxX: number;
    minY: number;
    maxY: number;
} | undefined): {
    minX: number;
    maxX: number;
    minY: number;
    maxY: number;
};
export class Size {
    /**
     * @param {number} width
     * @param {number} height
     */
    constructor(width: number, height: number);
    width: number;
    height: number;
    /**
     * @param {?Size=} size
     * @return {!Size}
     */
    clipTo(size?: (Size | null) | undefined): Size;
    /**
     * @param {number} scale
     * @return {!Size}
     */
    scale(scale: number): Size;
    /**
     * @param {?Size} size
     * @return {boolean}
     */
    isEqual(size: Size | null): boolean;
    /**
   * @param {!Size|number} size
   * @return {!Size}
   */
    widthToMax(size: Size | number): Size;
    /**
   * @param {!Size|number} size
   * @return {!Size}
   */
    addWidth(size: Size | number): Size;
    /**
     * @param {!Size|number} size
     * @return {!Size}
     */
    heightToMax(size: Size | number): Size;
    /**
     * @param {!Size|number} size
     * @return {!Size}
     */
    addHeight(size: Size | number): Size;
}
export class Insets {
    /**
     * @param {number} left
     * @param {number} top
     * @param {number} right
     * @param {number} bottom
     */
    constructor(left: number, top: number, right: number, bottom: number);
    left: number;
    top: number;
    right: number;
    bottom: number;
    /**
     * @param {?Insets} insets
     * @return {boolean}
     */
    isEqual(insets: Insets | null): boolean;
}
export class Rect {
    /**
     * @param {number} left
     * @param {number} top
     * @param {number} width
     * @param {number} height
     */
    constructor(left: number, top: number, width: number, height: number);
    left: number;
    top: number;
    width: number;
    height: number;
    /**
     * @param {?Rect} rect
     * @return {boolean}
     */
    isEqual(rect: Rect | null): boolean;
    /**
     * @param {number} scale
     * @return {!Rect}
     */
    scale(scale: number): Rect;
    /**
     * @return {!Size}
     */
    size(): Size;
    /**
     * @param {!Rect} origin
     * @return {!Rect}
     */
    relativeTo(origin: Rect): Rect;
    /**
     * @param {!Rect} origin
     * @return {!Rect}
     */
    rebaseTo(origin: Rect): Rect;
}
export class Constraints {
    /**
     * @param {!Size=} minimum
     * @param {?Size=} preferred
     */
    constructor(minimum?: Size | undefined, preferred?: (Size | null) | undefined);
    /**
     * @type {!Size}
     */
    minimum: Size;
    /**
     * @type {!Size}
     */
    preferred: Size;
    /**
     * @param {?Constraints} constraints
     * @return {boolean}
     */
    isEqual(constraints: Constraints | null): boolean;
    /**
     * @param {!Constraints|number} value
     * @return {!Constraints}
     */
    widthToMax(value: Constraints | number): Constraints;
    /**
     * @param {!Constraints|number} value
     * @return {!Constraints}
     */
    addWidth(value: Constraints | number): Constraints;
    /**
     * @param {!Constraints|number} value
     * @return {!Constraints}
     */
    heightToMax(value: Constraints | number): Constraints;
    /**
     * @param {!Constraints|number} value
     * @return {!Constraints}
     */
    addHeight(value: Constraints | number): Constraints;
}
