//
//  p_game.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/20/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "pong_internal.h"

void p_game_handleSceneReady(const float timeElapsed, SDL_Renderer *renderer);

bool p_game_initializeGame(void) {
    bool subsystemsInitialized = p_subsystems_initializeSubsystems();
    if (!subsystemsInitialized) {
        return false;
    }
    
    bool windowInitialized = p_window_initializeWindow();
    if (!windowInitialized) {
        return false;
    }
    
    bool rendererInitialized = p_renderer_initializeRenderer(p_window_getWindow());
    if (!rendererInitialized) {
        return false;
    }
    
    bool windowReady = p_window_getWindow() ? true : false;
    if (!windowReady) {
        return false;
    }
    
    return true;
}

void p_game_updateGame(const float timeElapsed) {
    p_scene_runWithBackground(timeElapsed, p_game_handleSceneReady);
}

void p_game_shutdownGame(void) {
    p_renderer_destroyRenderer();
    p_window_destroyWindow();
    p_subsystems_destroySubsystems();
}

void p_game_handleSceneReady(const float timeElapsed, SDL_Renderer *renderer) {
    // TODO: Add update and render logic for ball and paddles.
}
