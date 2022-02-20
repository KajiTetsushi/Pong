//
//  p_window.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/20/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "pong_internal.h"

SDL_Window *window;

SDL_Window * p_window_getWindow(void) {
    return window;
}

void p_window_destroyWindow(void) {
    if (window) {
        SDL_DestroyWindow(window);
    }
}

const char* P_WINDOW_TITLE = "Pong";
const int P_WINDOW_X = SDL_WINDOWPOS_UNDEFINED;
const int P_WINDOW_Y = SDL_WINDOWPOS_UNDEFINED;
const int P_WINDOW_WIDTH = 600;
const int P_WINDOW_HEIGHT = 480;
const Uint32 P_WINDOW_FLAGS = SDL_WINDOW_SHOWN;

bool p_window_initializeWindow(void) {
    window = SDL_CreateWindow(P_WINDOW_TITLE,
                              P_WINDOW_X, P_WINDOW_Y,
                              P_WINDOW_WIDTH, P_WINDOW_HEIGHT,
                              P_WINDOW_FLAGS);
    
    return window ? true : false;
}
