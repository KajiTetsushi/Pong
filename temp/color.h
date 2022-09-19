//
//  color.h
//  Pong
//
//  Created by Kaji Tetsushi on 2/20/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#ifndef color_h
#define color_h

typedef struct Color {
    int r, g, b, a;
} Color;

Color color_createColor(int r, int g, int b, int a);
Color color_createColorOpaque(int r, int g, int b);
Color color_createColorTransparent(void);

#endif /* color_h */
