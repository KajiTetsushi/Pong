//
//  gameObject2.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/20/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "gameObject2.h"

void go2_renderGameObject(SDL_Renderer *renderer, const GameObject2 *gameObject) {
    SDL_Rect rect = {
        .x = gameObject->position.x,
        .y = gameObject->position.y,
        .w = gameObject->scale.x,
        .h = gameObject->scale.y,
    };
    
    SDL_SetRenderDrawColor(renderer, gameObject->color.r, gameObject->color.g, gameObject->color.b, gameObject->color.a);
    SDL_RenderFillRect(renderer, &rect);
}
