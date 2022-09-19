//
//  c_rigidbody.h
//  Pong
//
//  Created by Kaji Tetsushi on 5/6/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#ifndef c_rigidbody_h
#define c_rigidbody_h

#include "c_color.h"
#include "c_vector2.h"

typedef struct RigidBody {
    Color color;
    Vector2 position;
    Vector2 scale;
    Vector2 velocity;
} RigidBody;

#endif /* c_rigidbody_h */
