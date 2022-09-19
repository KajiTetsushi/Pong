//
//  ball.h
//  Pong
//
//  Created by Kaji Tetsushi on 2/13/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#ifndef ball_h
#define ball_h

#include "color.h"
#include "vector2.h"

#include <SDL2/SDL.h>

typedef struct Ball {
    Vector2 position;
    Vector2 velocity;
    Color color;
    int size;
} Ball;

Ball ball_createBall(const int size, const float x, const float y, const float speed);
void ball_updateBall(Ball *ball, float elapsed);
void ball_renderBall(SDL_Renderer *renderer, const Ball *ball);

int ball_getHalfSize(Ball *ball);

#endif /* ball_h */
