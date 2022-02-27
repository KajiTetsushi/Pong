//
//  c_vector2.h
//  Pong
//
//  Created by Kaji Tetsushi on 2/28/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#ifndef c_vector2_h
#define c_vector2_h

typedef struct Vector2 {
    float x;
    float y;
} Vector2;

Vector2 c_vector2_createVector2(float x, float y);

#endif /* c_vector2_h */
