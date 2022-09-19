//
//  app_game.h
//  Pong
//
//  Created by Kaji Tetsushi on 9/19/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#ifndef app_game_h
#define app_game_h

#include <SDL2/SDL.h>
#include <stdbool.h>

extern bool app_game_initializeGame(const char *title, const int w, const int h, void (*onGameInitialize)(void));
extern void app_game_updateGame(const float timeElapsed, void (*onGameUpdate)(const float timeElapsed, SDL_Renderer *renderer));
extern void app_game_shutdownGame(void);

#endif /* app_game_h */
