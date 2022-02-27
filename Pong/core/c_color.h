//
//  c_color.h
//  Pong
//
//  Created by Kaji Tetsushi on 2/28/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#ifndef c_color_h
#define c_color_h

typedef struct Color {
    int r;
    int g;
    int b;
    int a;
} Color;

extern const Color C_COLOR_BLACK;
extern const Color C_COLOR_GRAY;
extern const Color C_COLOR_WHITE;
extern const Color C_COLOR_CLEAR;
extern const Color C_COLOR_RED;
extern const Color C_COLOR_GREEN;
extern const Color C_COLOR_BLUE;
extern const Color C_COLOR_CYAN;
extern const Color C_COLOR_YELLOW;
extern const Color C_COLOR_MAGENTA;

extern Color c_color_createColor(int r, int g, int b, int a);
extern Color c_color_createColorSolid(int r, int g, int b);

#endif /* c_color_h */
