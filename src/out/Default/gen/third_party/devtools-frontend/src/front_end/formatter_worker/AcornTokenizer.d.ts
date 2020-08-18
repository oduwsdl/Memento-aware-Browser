export type TokenOrComment = Acorn.Token | Acorn.Comment;
/**
 * @typedef {(!Acorn.Token|!Acorn.Comment)}
 */
export let TokenOrComment: any;
/**
 * @unrestricted
 */
export class AcornTokenizer {
    /**
     * @param {!Acorn.Token} token
     * @param {string=} values
     * @return {boolean}
     */
    static punctuator(token: Acorn.Token, values?: string | undefined): boolean;
    /**
     * @param {!Acorn.Token} token
     * @param {string=} keyword
     * @return {boolean}
     */
    static keyword(token: Acorn.Token, keyword?: string | undefined): boolean;
    /**
     * @param {!TokenOrComment} token
     * @param {string=} identifier
     * @return {boolean}
     */
    static identifier(token: TokenOrComment, identifier?: string | undefined): boolean;
    /**
     * @param {!TokenOrComment} token
     * @return {boolean}
     */
    static lineComment(token: TokenOrComment): boolean;
    /**
     * @param {!TokenOrComment} token
     * @return {boolean}
     */
    static blockComment(token: TokenOrComment): boolean;
    /**
     * @param {string} content
     */
    constructor(content: string);
    _content: string;
    /** @type {!Array<!Acorn.Comment>} */
    _comments: Array<Acorn.Comment>;
    _tokenizer: {
        getToken(): Acorn.Token;
        [Symbol.iterator](): Iterator<Acorn.Token, any, undefined>;
    };
    _textCursor: TextUtils.TextCursor.TextCursor;
    _tokenLineStart: number;
    _tokenLineEnd: number;
    _tokenColumnStart: number;
    /**
     * @return {!TokenOrComment}
     */
    _nextTokenInternal(): TokenOrComment;
    _bufferedToken: Acorn.Token | undefined;
    /**
     * @return {?TokenOrComment}
     */
    nextToken(): TokenOrComment | null;
    /**
     * @return {?TokenOrComment}
     */
    peekToken(): TokenOrComment | null;
    /**
     * @return {number}
     */
    tokenLineStart(): number;
    /**
     * @return {number}
     */
    tokenLineEnd(): number;
    /**
     * @return {number}
     */
    tokenColumnStart(): number;
}
export const ECMA_VERSION: 11;
import { Acorn } from "./Acorn.js";
import * as TextUtils from "../text_utils/text_utils.js";
