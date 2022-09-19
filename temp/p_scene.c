//
//  p_scene.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/21/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "pong.h"

void p_scene_runScene(const float timeElapsed, void (*)) {
    SDL_Renderer *renderer = p_renderer_getRenderer();
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // TODO: Add update and render logic for ball and paddles.
    
    SDL_RenderPresent(renderer);
}
