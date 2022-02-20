//
//  p_scene.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/21/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "pong_internal.h"

const int P_SCENE_R = 0;
const int P_SCENE_G = 0;
const int P_SCENE_B = 0;
const int P_SCENE_A = 255;

/**
 * @brief Runs the entire game scene with a fixed colored background.
 * @param timeElapsed The number of seconds elapsed since last frame.
 * @param onSceneReady A handler to call when the game scene is ready to draw graphics.
 */
void p_scene_runWithBackground(const float timeElapsed, void (*onSceneReady)(const float timeElapsed, SDL_Renderer *renderer)) {
    SDL_Renderer *renderer = p_renderer_getRenderer();

    SDL_SetRenderDrawColor(renderer, P_SCENE_R, P_SCENE_G, P_SCENE_B, P_SCENE_A);
    SDL_RenderClear(renderer);
    
    onSceneReady(timeElapsed, renderer);
    
    SDL_RenderPresent(renderer);
}
