/**
 * Metadata to map between bytecode offsets and line numbers in the
 * disassembly for WebAssembly modules.
 */
export class WasmDisassembly {
    /**
     * @param {!Array<number>} offsets mapping of line numbers to bytecode offsets
     * @param {!Array<{start: number, end: number}>} functionBodyOffsets mapping of function indices to start/end bytecode offsets
     */
    constructor(offsets: Array<number>, functionBodyOffsets: Array<{
        start: number;
        end: number;
    }>);
    _offsets: number[];
    _functionBodyOffsets: {
        start: number;
        end: number;
    }[];
    /** @return {number} */
    get lineNumbers(): number;
    /**
     * @param {number} bytecodeOffset
     * @return {number}
     */
    bytecodeOffsetToLineNumber(bytecodeOffset: number): number;
    /**
     * @param {number} lineNumber
     * @return {number}
     */
    lineNumberToBytecodeOffset(lineNumber: number): number;
    /**
     * @return {!Iterable<number>} an iterable enumerating all the non-breakable line numbers in the disassembly
     */
    nonBreakableLineNumbers(): Iterable<number>;
}
