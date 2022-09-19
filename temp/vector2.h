//
//  vector2.h
//  Pong
//
//  Created by Kaji Tetsushi on 2/20/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#ifndef vector2_h
#define vector2_h

typedef struct Vector2 {
    float x, y;
} Vector2;

Vector2 vector2_createVector2(float x, float y);

#endif /* vector2_h */
