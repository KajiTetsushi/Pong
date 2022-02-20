//
//  p_renderer.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/20/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "pong_internal.h"

SDL_Renderer *renderer;

SDL_Renderer * p_renderer_getRenderer(void) {
    return renderer;
}

void p_renderer_destroyRenderer(void) {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
}

const int P_RENDERER_INDEX = -1;
const Uint32 P_RENDERER_FLAGS = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

bool p_renderer_initializeRenderer(SDL_Window *window) {
    renderer = SDL_CreateRenderer(window,
                                  P_RENDERER_INDEX,
                                  P_RENDERER_FLAGS);
    
    return renderer ? true : false;
}
