//
//  pong_internal.h
//  Pong
//
//  Created by Kaji Tetsushi on 2/21/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#ifndef pong_internal_h
#define pong_internal_h

#include "pong_includes.h"

SDL_Renderer * p_renderer_getRenderer(void);
extern void p_renderer_destroyRenderer(void);
extern bool p_renderer_initializeRenderer(SDL_Window *window);

SDL_Window * p_window_getWindow(void);
extern void p_window_destroyWindow(void);
extern bool p_window_initializeWindow(void);

extern void p_scene_runWithBackground(const float timeElapsed, void (*onSceneReady)(const float timeElapsed, SDL_Renderer *renderer));

extern bool p_subsystems_initializeSubsystems(void);
extern void p_subsystems_destroySubsystems(void);

// TODO: Use window dimensions as map boundaries for game objects. See p_window.c

#endif /* pong_internal_h */
