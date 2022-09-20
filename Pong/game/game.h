//
//  game.h
//  Pong
//
//  Created by Kaji Tetsushi on 9/19/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#ifndef game_h
#define game_h

#include <SDL2/SDL.h>
#include <stdbool.h>

extern bool game_initializeGame(const char *title, const int w, const int h, void (*onGameInitialize)(SDL_Renderer *renderer, SDL_Window *window));
extern void game_updateGame(const float timeElapsed, void (*onGameUpdate)(SDL_Renderer *renderer, SDL_Window *window, const float timeElapsed));
extern void game_shutdownGame(void);

#endif /* game_h */
