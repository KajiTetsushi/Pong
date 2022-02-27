//
//  c_color.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/28/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "c_color.h"

const Color C_COLOR_BLACK = {
    .r = 0,
    .g = 0,
    .b = 0,
    .a = 255,
};

const Color C_COLOR_GRAY = {
    .r = 128,
    .g = 128,
    .b = 128,
    .a = 255,
};

const Color C_COLOR_WHITE = {
    .r = 255,
    .g = 255,
    .b = 255,
    .a = 255,
};

const Color C_COLOR_CLEAR = {
    .r = 0,
    .g = 0,
    .b = 0,
    .a = 0,
};

const Color C_COLOR_RED = {
    .r = 255,
    .g = 0,
    .b = 0,
    .a = 255,
};

const Color C_COLOR_GREEN = {
    .r = 0,
    .g = 255,
    .b = 0,
    .a = 255,
};

const Color C_COLOR_BLUE = {
    .r = 0,
    .g = 0,
    .b = 255,
    .a = 255,
};

const Color C_COLOR_CYAN = {
    .r = 0,
    .g = 255,
    .b = 255,
    .a = 255,
};

const Color C_COLOR_YELLOW = {
    .r = 255,
    .g = 255,
    .b = 0,
    .a = 255,
};

const Color C_COLOR_MAGENTA = {
    .r = 255,
    .g = 0,
    .b = 255,
    .a = 255,
};

/**
 * @brief Creates a color with given r, g, b, a components.
 * @param r Red component.
 * @param g Green component.
 * @param b Blue component.
 * @param a Alpha component.
 * @return A color.
 */
Color c_color_createColor(int r, int g, int b, int a) {
    Color color = {
        .r = r,
        .g = g,
        .b = b,
        .a = a,
    };
    
    return color;
}

/**
 * @brief Creates a color with given r, g, b components and sets a to 255.
 * @param r Red component.
 * @param g Green component.
 * @param b Blue component.
 * @return A fully-opaque color.
 */
Color c_color_createColorSolid(int r, int g, int b) {
    return c_color_createColor(r, g, b, 255);
}
