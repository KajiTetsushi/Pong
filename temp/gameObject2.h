//
//  gameObject2.h
//  Pong
//
//  Created by Kaji Tetsushi on 2/20/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#ifndef gameObject_h
#define gameObject_h

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "color.c"
#include "vector2.h"

typedef struct GameObject2 {
    Vector2 position;
    Vector2 velocity;
    Vector2 scale;
    Color color;
    /**
     * @brief Determines whether the object can collide with other objects.
     * 
     */
    bool collides;
} GameObject2;

void go2_renderGameObject(SDL_Renderer *renderer, const GameObject2 *gameObject);

#endif /* gameObject2_h */
