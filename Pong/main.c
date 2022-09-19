//
//  main.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/12/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include <stdbool.h>
#include <SDL2/SDL.h>

//#region Game
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
//#endregion

const char* WINDOW_TITLE = "Pong";
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// TODO: Prepare ball, paddles, score, etc.
void main_handleGameInitialize() {
}

// TODO: Change ball position, paddle position, score value, etc.
void main_handleGameUpdate(const float timeElapsed, SDL_Renderer *renderer) {
}

int main(int argc, const char * argv[]) {
    atexit(app_game_shutdownGame);
    
    bool initialized = app_game_initializeGame(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, main_handleGameInitialize);
    if (!initialized) {
        exit(1);
    }

    bool quit = false;
    SDL_Event event;
    Uint32 lastTick = SDL_GetTicks();

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        Uint32 currentTick = SDL_GetTicks();
        float timeElapsed = (currentTick - lastTick) / 1000.0f;
        app_game_updateGame(timeElapsed, main_handleGameUpdate);
        lastTick = currentTick;
    }

    app_game_shutdownGame();
    
    return 0;
}
