/**
 * @param {function(string, ?Object<string, string>, function(boolean, !Object<string, string>, string, !LoadErrorDescription): void): void} newLoad
 */
export function setLoadForTest(newLoad: (arg0: string, arg1: {
    [x: string]: string;
} | null, arg2: (arg0: boolean, arg1: {
    [x: string]: string;
}, arg2: string, arg3: LoadErrorDescription) => void) => void): void;
export const ResourceLoader: {};
export function streamWrite(id: number, chunk: string): void;
export type LoadErrorDescription = {
    statusCode: number;
    netError: (number | undefined);
    netErrorName: (string | undefined);
    urlValid: (boolean | undefined);
    message: (string | undefined);
};
/** @typedef
{{
    statusCode: number,
    netError: (number|undefined),
    netErrorName: (string|undefined),
    urlValid: (boolean|undefined),
    message: (string|undefined)
}} */
export let LoadErrorDescription: any;
export function load(url: string, headers: {
    [x: string]: string;
} | null, callback: (arg0: boolean, arg1: {
    [x: string]: string;
}, arg2: string, arg3: LoadErrorDescription) => void): void;
export function loadAsStream(url: string, headers: {
    [x: string]: string;
} | null, stream: Common.StringOutputStream.OutputStream, callback?: ((arg0: boolean, arg1: {
    [x: string]: string;
}, arg2: LoadErrorDescription) => void) | undefined): void;
import * as Common from "../common/common.js";
