//
//  ball.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/13/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "ball.h"

Ball ball_createBall(const int size, const float x, const float y, const float speed) {
    Vector2 position = vector2_createVector2(x, y);
    Vector2 velocity = vector2_createVector2(0, 0);
    Color color = color_createColorOpaque(255, 255, 255);
    
    Ball ball = {
        .position = position,
        .velocity = velocity,
        .color = color,
        .size = size,
    };
    
    return ball;
}

void ball_updateBall(Ball *ball, float elapsed) {
    // Move ball in the direction
    ball->position.x += ball->velocity.x * elapsed;
    ball->position.y += ball->velocity.y * elapsed;
}

void ball_renderBall(SDL_Renderer *renderer, const Ball *ball) {
    int ballHalfSize = ball->size / 2;
    SDL_Rect rect = {
        .x = ball->position.x - ballHalfSize,
        .y = ball->position.y - ballHalfSize,
        .w = ball->size,
        .h = ball->size,
    };
    SDL_SetRenderDrawColor(renderer, ball->color.r, ball->color.g, ball->color.b, ball->color.a);
    SDL_RenderFillRect(renderer, &rect);
}

int ball_getHalfSize(Ball *ball) {
    int ballHalfSize = ball->size / 2;
    
    return ballHalfSize;
}
