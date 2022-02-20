//
//  pong.h
//  Pong
//
//  Created by Kaji Tetsushi on 2/20/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#ifndef pong_h
#define pong_h

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

extern bool p_game_initializeGame(void);
extern void p_game_updateGame(const float timeElapsed);
extern void p_game_shutdownGame(void);

#endif /* pong_h */
