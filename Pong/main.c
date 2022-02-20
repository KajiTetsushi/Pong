//
//  main.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/12/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "pong.h"

int main(int argc, const char * argv[]) {
    atexit(p_game_shutdownGame);
    
    bool initialized = p_game_initializeGame();
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
        p_game_updateGame(timeElapsed);
        lastTick = currentTick;
    }
    
    p_subsystems_destroySubsystems();

    return 0;
}
