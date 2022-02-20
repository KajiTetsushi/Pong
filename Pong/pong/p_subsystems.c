//
//  p_subsystems.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/21/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "pong.h"

bool p_subsystems_initializeSubsystems(void) {
    return SDL_Init(SDL_INIT_VIDEO) == 0;
}

void p_subsystems_destroySubsystems(void) {
    SDL_Quit();
}
