//
//  color.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/20/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "color.h"

Color color_createColor(int r, int g, int b, int a) {
    Color color = {
        .r = r,
        .g = g,
        .b = b,
        .a = a,
    };
    
    return color;
}

Color color_createColorOpaque(int r, int g, int b) {
    return color_createColor(r, g, b, 255);
}

Color color_createColorTransparent(void) {
    return color_createColor(0, 0, 0, 0);
}
