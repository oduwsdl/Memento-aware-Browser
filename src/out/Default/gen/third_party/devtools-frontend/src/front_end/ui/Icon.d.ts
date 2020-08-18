export class Icon extends HTMLSpanElement {
    /**
     * @param {string=} iconType
     * @param {string=} className
     * @return {!Icon}
     */
    static create(iconType?: string | undefined, className?: string | undefined): Icon;
    /** @type {?Descriptor} */
    _descriptor: Descriptor | null;
    /** @type {?SpriteSheet} */
    _spriteSheet: SpriteSheet | null;
    /** @type {string} */
    _iconType: string;
    /**
     * @param {string} iconType
     */
    setIconType(iconType: string): void;
    /**
     * @param {boolean} value
     */
    _toggleClasses(value: boolean): void;
    /**
     * @return {string}
     */
    _propertyValue(): string;
}
export type Descriptors = {
    position: string;
    spritesheet: string;
    isMask: (boolean | undefined);
    coordinates: ({
        x: number;
        y: number;
    } | undefined);
    invert: (boolean | undefined);
};
/** @enum {!Descriptor} */
export const Descriptors: {
    'smallicon-bezier': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-checkmark': {
        position: string;
        spritesheet: string;
    };
    'smallicon-checkmark-square': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-checkmark-behind': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-command-result': {
        position: string;
        spritesheet: string;
    };
    'smallicon-contrast-ratio': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-cross': {
        position: string;
        spritesheet: string;
    };
    'smallicon-device': {
        position: string;
        spritesheet: string;
    };
    'smallicon-error': {
        position: string;
        spritesheet: string;
    };
    'smallicon-expand-less': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-expand-more': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-green-arrow': {
        position: string;
        spritesheet: string;
    };
    'smallicon-green-ball': {
        position: string;
        spritesheet: string;
    };
    'smallicon-info': {
        position: string;
        spritesheet: string;
    };
    'smallicon-inline-breakpoint-conditional': {
        position: string;
        spritesheet: string;
    };
    'smallicon-inline-breakpoint': {
        position: string;
        spritesheet: string;
    };
    'smallicon-no': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-orange-ball': {
        position: string;
        spritesheet: string;
    };
    'smallicon-red-ball': {
        position: string;
        spritesheet: string;
    };
    'smallicon-shadow': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-step-in': {
        position: string;
        spritesheet: string;
    };
    'smallicon-step-out': {
        position: string;
        spritesheet: string;
    };
    'smallicon-text-prompt': {
        position: string;
        spritesheet: string;
    };
    'smallicon-thick-left-arrow': {
        position: string;
        spritesheet: string;
    };
    'smallicon-thick-right-arrow': {
        position: string;
        spritesheet: string;
    };
    'smallicon-triangle-down': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-triangle-right': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-triangle-up': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-user-command': {
        position: string;
        spritesheet: string;
    };
    'smallicon-warning': {
        position: string;
        spritesheet: string;
    };
    'smallicon-network-product': {
        position: string;
        spritesheet: string;
    };
    'smallicon-clear-warning': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-clear-info': {
        position: string;
        spritesheet: string;
    };
    'smallicon-clear-error': {
        position: string;
        spritesheet: string;
    };
    'smallicon-account-circle': {
        position: string;
        spritesheet: string;
    };
    'smallicon-videoplayer-paused': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-videoplayer-playing': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-videoplayer-destroyed': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'smallicon-issue-yellow-text': {
        position: string;
        spritesheet: string;
    };
    'smallicon-issue-blue-text': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-clear-storage': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-cookie': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-database': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-info': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-manifest': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-service-worker': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-table': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-arrow-in-circle': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-file-sync': {
        position: string;
        spritesheet: string;
        invert: boolean;
    };
    'mediumicon-file': {
        position: string;
        spritesheet: string;
        invert: boolean;
    };
    'mediumicon-gray-cross-active': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-gray-cross-hover': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-red-cross-active': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-red-cross-hover': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-search': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-replace': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-account-circle': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-warning-triangle': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-error-circle': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-info-circle': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-bug': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-list': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-warning': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-sync': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-fetch': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-cloud': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-bell': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-payment': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-schedule': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'badge-navigator-file-sync': {
        position: string;
        spritesheet: string;
    };
    'largeicon-activate-breakpoints': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-add': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-camera': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-center': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-checkmark': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-chevron': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-clear': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-copy': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-deactivate-breakpoints': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-delete': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-dock-to-bottom': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-dock-to-left': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-dock-to-right': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-download': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-edit': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-eyedropper': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-filter': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-hide-bottom-sidebar': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-hide-left-sidebar': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-hide-right-sidebar': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-hide-top-sidebar': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-large-list': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-layout-editor': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-load': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-longclick-triangle': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-menu': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-navigator-domain': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-navigator-file': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-navigator-file-sync': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-navigator-folder': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-navigator-frame': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-navigator-snippet': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-navigator-worker': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-node-search': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-pan': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-pause-animation': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-pause': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-pause-on-exceptions': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-phone': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-play-animation': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-play-back': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-play': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-pretty-print': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-refresh': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-replay-animation': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-resume': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-rotate': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-rotate-screen': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-search': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-settings-gear': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-show-bottom-sidebar': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-show-left-sidebar': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-show-right-sidebar': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-show-top-sidebar': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-start-recording': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-step-into': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-step-out': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-step-over': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-step': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-stop-recording': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-terminate-execution': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-trash-bin': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-undo': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-undock': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-visibility': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-waterfall': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-breaking-change': {
        position: string;
        spritesheet: string;
    };
    'largeicon-link': {
        position: string;
        spritesheet: string;
    };
    'largeicon-dual-screen': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'largeicon-experimental-api': {
        position: string;
        spritesheet: string;
        isMask: boolean;
    };
    'mediumicon-arrow-top': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-arrow-bottom': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-arrow-left': {
        position: string;
        spritesheet: string;
    };
    'mediumicon-arrow-right': {
        position: string;
        spritesheet: string;
    };
};
export type Descriptor = {
    position: string;
    spritesheet: string;
    isMask: (boolean | undefined);
    coordinates: ({
        x: number;
        y: number;
    } | undefined);
    invert: (boolean | undefined);
};
/** @typedef {{position: string, spritesheet: string, isMask: (boolean|undefined), coordinates: ({x: number, y: number}|undefined), invert: (boolean|undefined)}} */
export let Descriptor: any;
export type SpriteSheet = {
    cellWidth: number;
    cellHeight: number;
    padding: number;
};
/** @typedef {{cellWidth: number, cellHeight: number, padding: number}} */
export let SpriteSheet: any;
export type SpriteSheets = {
    cellWidth: number;
    cellHeight: number;
    padding: number;
};
