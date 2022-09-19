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

extern const int P_WINDOW_WIDTH;
extern const int P_WINDOW_HEIGHT;

SDL_Window * p_window_getWindow(void);
extern void p_window_destroyWindow(void);
extern bool p_window_initializeWindow(void);

extern void p_scene_runWithBackground(const float timeElapsed, void (*onSceneReady)(const float timeElapsed, SDL_Renderer *renderer));

extern bool p_subsystems_initializeSubsystems(void);
extern void p_subsystems_destroySubsystems(void);

extern const unsigned int BALL_SIZE;
extern const unsigned int BALL_SPEED;

unsigned int p_ball_randomizeDirection(unsigned int speed);
void p_ball_initializeBall(RigidBody *ball);
void p_ball_renderBall(const RigidBody *ball);
void p_ball_updateBall(RigidBody *ball, const float timeElapsed);

// TODO: Use window dimensions as map boundaries for game objects. See p_window.c

#endif /* pong_internal_h */
