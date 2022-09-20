//
//  main.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/12/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "game/game.h"

const char* WINDOW_TITLE = "Pong";
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// TODO: Prepare ball, paddles, score, etc.
void main_handleGameInitialize(SDL_Renderer *renderer, SDL_Window *window) {
}

// TODO: Change ball position, paddle position, score value, etc.
void main_handleGameUpdate(const float timeElapsed, SDL_Renderer *renderer, SDL_Window *window) {
}

int main(int argc, const char * argv[]) {
    atexit(game_shutdownGame);
    
    bool initialized = game_initializeGame(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, main_handleGameInitialize);
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
        game_updateGame(timeElapsed, main_handleGameUpdate);
        lastTick = currentTick;
    }

    game_shutdownGame();
    
    return 0;
}
