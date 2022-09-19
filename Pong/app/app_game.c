//
//  app_game.c
//  Pong
//
//  Created by Kaji Tetsushi on 9/19/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "app_game.h"

SDL_Renderer *renderer;
SDL_Window *window;

bool app_game_initializeGame(const char *title, const int w, const int h, void (*onGameInitialize)(void)) {
    // Initialize core subsystems.
    int initialized = SDL_Init(SDL_INIT_VIDEO);
    if (initialized != 0) {
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
        return false;
    }
    
    // Initialize window singleton.
    window = SDL_CreateWindow(title,
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              w, h,
                              SDL_WINDOW_SHOWN);
    if (!window) {
        return false;
    }
    
    // Initialize renderer singleton.
    renderer = SDL_CreateRenderer(window,
                                  -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        return false;
    }
    
    if (onGameInitialize) {
        onGameInitialize();
    }
    
    return true;
}

void app_game_updateGame(const float timeElapsed, void (*onGameUpdate)(const float timeElapsed, SDL_Renderer *renderer)) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    if (onGameUpdate) {
        onGameUpdate(timeElapsed, renderer);
    }
    
    SDL_RenderPresent(renderer);
}

void app_game_shutdownGame(void) {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    
    if (window) {
        SDL_DestroyWindow(window);
    }
    
    SDL_Quit();
}
