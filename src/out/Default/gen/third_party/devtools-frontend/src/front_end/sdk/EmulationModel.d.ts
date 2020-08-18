export class EmulationModel extends SDKModel {
    /**
     * @param {!Target} target
     */
    constructor(target: Target);
    _emulationAgent: any;
    _pageAgent: ProtocolProxyApi.PageApi;
    _deviceOrientationAgent: any;
    _cssModel: any;
    _overlayModel: any;
    _mediaConfiguration: Map<string, any>;
    _touchEnabled: boolean;
    _touchMobile: boolean;
    _customTouchEnabled: boolean;
    _touchConfiguration: {
        enabled: boolean;
        configuration: Protocol.Emulation.SetEmitTouchEventsForMouseRequestConfiguration;
        scriptId: string;
    };
    /**
     * @return {boolean}
     */
    supportsDeviceEmulation(): boolean;
    /**
     * @return {!Promise<?>}
     */
    resetPageScaleFactor(): Promise<unknown>;
    /**
     * @param {?Protocol.Page.SetDeviceMetricsOverrideRequest} metrics
     * @return {!Promise<?>}
     */
    emulateDevice(metrics: Protocol.Page.SetDeviceMetricsOverrideRequest | null): Promise<unknown>;
    /**
     * @return {?OverlayModel}
     */
    overlayModel(): OverlayModel | null;
    /**
     * @param {?Location} location
     */
    emulateLocation(location: Location | null): Promise<[any, any, any, any] | undefined>;
    /**
     * @param {?DeviceOrientation} deviceOrientation
     */
    emulateDeviceOrientation(deviceOrientation: DeviceOrientation | null): void;
    /**
     * @param {string} type
     * @param {!Array<{name: string, value: string}>} features
     */
    _emulateCSSMedia(type: string, features: Array<{
        name: string;
        value: string;
    }>): void;
    /**
     * @param {!Protocol.Emulation.SetEmulatedVisionDeficiencyRequestType} type
     */
    _emulateVisionDeficiency(type: Protocol.Emulation.SetEmulatedVisionDeficiencyRequestType): void;
    /**
     * @param {number} rate
     */
    setCPUThrottlingRate(rate: number): void;
    /**
     * @param {boolean} enabled
     * @param {boolean} mobile
     */
    emulateTouch(enabled: boolean, mobile: boolean): void;
    /**
     * @param {boolean} enabled
     */
    overrideEmulateTouch(enabled: boolean): void;
    _updateTouch(): void;
    _updateCssMedia(): void;
}
export class Location {
    /**
     * @return {!Location}
     */
    static parseSetting(value: any): Location;
    /**
     * @param {string} latitudeString
     * @param {string} longitudeString
     * @param {string} timezoneId
     * @return {?Location}
     */
    static parseUserInput(latitudeString: string, longitudeString: string, timezoneId: string, locale: any): Location | null;
    /**
     * @param {string} value
     * @return {{valid: boolean, errorMessage: (string|undefined)}}
     */
    static latitudeValidator(value: string): {
        valid: boolean;
        errorMessage: (string | undefined);
    };
    /**
     * @param {string} value
     * @return {{valid: boolean, errorMessage: (string|undefined)}}
     */
    static longitudeValidator(value: string): {
        valid: boolean;
        errorMessage: (string | undefined);
    };
    /**
     * @param {string} value
     * @return {{valid: boolean, errorMessage: (string|undefined)}}
     */
    static timezoneIdValidator(value: string): {
        valid: boolean;
        errorMessage: (string | undefined);
    };
    /**
     * @param {string} value
     * @return {{valid: boolean, errorMessage: (string|undefined)}}
     */
    static localeValidator(value: string): {
        valid: boolean;
        errorMessage: (string | undefined);
    };
    /**
     * @param {number} latitude
     * @param {number} longitude
     * @param {string} timezoneId
     * @param {string} locale
     * @param {boolean} error
     */
    constructor(latitude: number, longitude: number, timezoneId: string, locale: string, error: boolean);
    latitude: number;
    longitude: number;
    timezoneId: string;
    locale: string;
    error: boolean;
    /**
     * @return {string}
     */
    toSetting(): string;
}
export namespace Location {
    export const DefaultGeoMockAccuracy: number;
}
export class DeviceOrientation {
    /**
     * @return {!DeviceOrientation}
     */
    static parseSetting(value: any): DeviceOrientation;
    /**
     * @return {?DeviceOrientation}
     */
    static parseUserInput(alphaString: any, betaString: any, gammaString: any): DeviceOrientation | null;
    /**
     * @param {string} value
     * @return {{valid: boolean, errorMessage: (string|undefined)}}
     */
    static validator(value: string): {
        valid: boolean;
        errorMessage: (string | undefined);
    };
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
    toSetting(): string;
}
import { SDKModel } from "./SDKModel.js";
import { OverlayModel } from "./OverlayModel.js";
import { Target } from "./SDKModel.js";
