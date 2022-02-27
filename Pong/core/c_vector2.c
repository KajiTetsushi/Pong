//
//  c_vector2.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/28/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "c_vector2.h"

Vector2 c_vector2_createVector2(float x, float y) {
    Vector2 vector2 = {
        .x = x,
        .y = y,
    };
    
    return vector2;
}
