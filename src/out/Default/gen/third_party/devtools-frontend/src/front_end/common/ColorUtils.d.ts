/**
 * Combine the two given colors according to alpha blending.
 * @param {!Array<number>} fgRGBA
 * @param {!Array<number>} bgRGBA
 * @return {!Array<number>}
 */
export function blendColors(fgRGBA: Array<number>, bgRGBA: Array<number>): Array<number>;
/**
 * @param {!Array<number>} rgba
 * @return {!Array<number>}
 */
export function rgbaToHsla([r, g, b, a]: Array<number>): Array<number>;
/**
* Calculate the luminance of this color using the WCAG algorithm.
* See http://www.w3.org/TR/2008/REC-WCAG20-20081211/#relativeluminancedef
* @param {!Array<number>} rgba
* @return {number}
*/
export function luminance([rSRGB, gSRGB, bSRGB]: Array<number>): number;
/**
 * Calculate the contrast ratio between a foreground and a background color.
 * Returns the ratio to 1, for example for two two colors with a contrast ratio of 21:1, this function will return 21.
 * See http://www.w3.org/TR/2008/REC-WCAG20-20081211/#contrast-ratiodef
 * @param {!Array<number>} fgRGBA
 * @param {!Array<number>} bgRGBA
 * @return {number}
 */
export function contrastRatio(fgRGBA: Array<number>, bgRGBA: Array<number>): number;
