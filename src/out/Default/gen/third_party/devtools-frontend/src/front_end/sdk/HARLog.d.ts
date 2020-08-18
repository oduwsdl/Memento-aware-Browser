export class HARLog {
    /**
     * @param {!NetworkRequest} request
     * @param {number} monotonicTime
     * @return {!Date}
     */
    static pseudoWallTime(request: NetworkRequest, monotonicTime: number): Date;
    /**
     * @param {!Array<!NetworkRequest>} requests
     * @return {!Promise<!HARLogDTO>}
     */
    static build(requests: Array<NetworkRequest>): Promise<HARLogDTO>;
    /**
     * @return {!Creator}
     */
    _creator(): Creator;
    /**
     * @param {!Array<!NetworkRequest>} requests
     * @return {!Array<!Page>}
     */
    _buildPages(requests: Array<NetworkRequest>): Array<Page>;
    /**
     * @param {!PageLoad} page
     * @param {!NetworkRequest} request
     * @return {!Page}
     */
    _convertPage(page: PageLoad, request: NetworkRequest): Page;
    /**
     * @param {!PageLoad} page
     * @param {number} time
     * @return {number}
     */
    _pageEventTime(page: PageLoad, time: number): number;
}
export class Entry {
    /**
     * @param {number} time
     * @return {number}
     */
    static _toMilliseconds(time: number): number;
    /**
     * @param {!NetworkRequest} request
     * @return {!Promise<!EntryDTO>}
     */
    static build(request: NetworkRequest): Promise<EntryDTO>;
    /**
     * @param {!NetworkRequest} request
     */
    constructor(request: NetworkRequest);
    _request: NetworkRequest;
    /**
     * @return {!Promise<!Request>}
     */
    _buildRequest(): Promise<Request>;
    /**
     * @return {!Response}
     */
    _buildResponse(): Response;
    /**
     * @return {!Content}
     */
    _buildContent(): Content;
    /**
     * @return {!Timing}
     */
    _buildTimings(): Timing;
    /**
     * @return {!Promise<?PostData>}
     */
    _buildPostData(): Promise<PostData | null>;
    /**
     * @param {!Array<!Parameter>} parameters
     * @return {!Array<!Parameter>}
     */
    _buildParameters(parameters: Array<Parameter>): Array<Parameter>;
    /**
     * @param {string} url
     * @return {string}
     */
    _buildRequestURL(url: string): string;
    /**
     * @param {!Array<!Cookie>} cookies
     * @return {!Array<!CookieDTO>}
     */
    _buildCookies(cookies: Array<Cookie>): Array<CookieDTO>;
    /**
     * @param {!Cookie} cookie
     * @return {!CookieDTO}
     */
    _buildCookie(cookie: Cookie): CookieDTO;
    /**
     * @return {!Promise<number>}
     */
    _requestBodySize(): Promise<number>;
    /**
     * @return {number}
     */
    get responseBodySize(): number;
    /**
     * @return {number|undefined}
     */
    get responseCompression(): number | undefined;
}
export type Timing = {
    blocked: number;
    dns: number;
    ssl: number;
    connect: number;
    send: number;
    wait: number;
    receive: number;
    _blocked_queueing: number;
    _blocked_proxy: (number | undefined);
};
/** @typedef {!{
  blocked: number,
  dns: number,
  ssl: number,
  connect: number,
  send: number,
  wait: number,
  receive: number,
  _blocked_queueing: number,
  _blocked_proxy: (number|undefined)
}} */
export let Timing: any;
export type Parameter = {
    name: string;
    value: string;
};
/** @typedef {{
  name: string,
  value: string,
}} */
export let Parameter: any;
export type Content = {
    size: number;
    mimeType: string;
    compression: (number | undefined);
};
/** @typedef {{
  size: number,
  mimeType: string,
  compression: (number|undefined),
}} */
export let Content: any;
export type Request = {
    method: string;
    url: string;
    httpVersion: string;
    headers: Object;
    queryString: Array<Parameter>;
    cookies: Array<CookieDTO>;
    headersSize: number;
    bodySize: number;
    postData: (PostData | undefined);
};
/** @typedef {!{
  method: string,
  url: string,
  httpVersion: string,
  headers: !Object,
  queryString: !Array<!Parameter>,
  cookies: !Array<!CookieDTO>,
  headersSize: number,
  bodySize: number,
  postData: (PostData|undefined),
}} */
export let Request: any;
export type Response = {
    status: number;
    statusText: string;
    httpVersion: string;
    headers: Object;
    cookies: Array<CookieDTO>;
    content: Content;
    redirectURL: string;
    headersSize: number;
    bodySize: number;
    _transferSize: number;
    _error: string | null;
};
/** @typedef {!{
  status: number,
  statusText: string,
  httpVersion: string,
  headers: !Object,
  cookies: !Array<!CookieDTO>,
  content: !Content,
  redirectURL: string,
  headersSize: number,
  bodySize: number,
  _transferSize: number,
  _error: ?string,
}} */
export let Response: any;
export type EntryDTO = {
    _fromCache: (string | undefined);
    _initiator: Protocol.Network.Initiator | null;
    _priority: Protocol.Network.ResourcePriority | null;
    _resourceType: string;
    _webSocketMessages: (Array<Object> | undefined);
    cache: Object;
    connection: (string | undefined);
    pageref: (string | undefined);
    request: Request;
    response: Response;
    serverIPAddress: string;
    startedDateTime: (Object | string);
    time: number;
    timings: Timing;
};
/** @typedef {!{
  _fromCache: (string|undefined),
  _initiator: ?Protocol.Network.Initiator,
  _priority: ?Protocol.Network.ResourcePriority,
  _resourceType: string,
  _webSocketMessages: (!Array<!Object>|undefined),
  cache: !Object,
  connection: (string|undefined),
  pageref: (string|undefined),
  request: !Request,
  response: !Response,
  serverIPAddress: string,
  startedDateTime: (!Object|string),
  time: number,
  timings: !Timing,
}} */
export let EntryDTO: any;
export type PostData = {
    mimeType: string;
    params: (Array<Parameter> | undefined);
    text: string;
};
/** @typedef {!{
  mimeType: string,
  params: (!Array<!Parameter>|undefined),
  text: string,
}} */
export let PostData: any;
export type CookieDTO = {
    name: string;
    value: string;
    path: string;
    domain: string;
    expires: Date | null;
    httpOnly: boolean;
    secure: boolean;
    sameSite: (Protocol.Network.CookieSameSite | undefined);
};
/** @typedef {!{
  name: string,
  value: string,
  path: string,
  domain: string,
  expires: ?Date,
  httpOnly: boolean,
  secure: boolean,
  sameSite: (Protocol.Network.CookieSameSite|undefined),
}} */
export let CookieDTO: any;
export type Page = {
    startedDateTime: (Object | string);
    id: string;
    title: string;
    pageTimings: {
        onContentLoad: number;
        onLoad: number;
    };
};
/** @typedef {!{
  startedDateTime: (!Object|string),
  id: string,
  title: string,
  pageTimings: !{
  onContentLoad: number,
  onLoad: number,
  }
}} */
export let Page: any;
export type Creator = {
    version: string;
    name: string;
};
/** @typedef {!{
  version: string,
  name: string,
}} */
export let Creator: any;
export type HARLogDTO = {
    version: string;
    creator: Creator;
    pages: Array<Page>;
    entries: Array<EntryDTO>;
};
/** @typedef {!{
  version: string,
  creator: !Creator,
  pages: !Array<!Page>,
  entries: !Array<!EntryDTO>,
}} */
export let HARLogDTO: any;
import { NetworkRequest } from "./NetworkRequest.js";
import { PageLoad } from "./NetworkLog.js";
import { Cookie } from "./Cookie.js";
