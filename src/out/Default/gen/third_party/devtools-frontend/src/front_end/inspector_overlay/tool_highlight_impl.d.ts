export function doReset(): void;
export function drawHighlight(highlight: any, context: any): {
    bounds: {
        minX: number;
        minY: number;
        maxX: number;
        maxY: number;
        leftmostXForY: {};
        rightmostXForY: {};
        topmostYForX: {};
        bottommostYForX: {};
    };
};
