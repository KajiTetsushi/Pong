//
//  p_ball.c
//  Pong
//
//  Created by Kaji Tetsushi on 5/6/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "pong_internal.h"

const unsigned int BALL_SIZE = 10;
const unsigned int BALL_SPEED = 120;

unsigned int p_ball_randomizeDirection(unsigned int speed) {
    int directionCoefficient = c_rng_flipCoin() ? 1 : -1;
    return speed * directionCoefficient;
}

void p_ball_initializeBall(RigidBody *ball) {
    Color color = C_COLOR_WHITE;

    float positionX = P_WINDOW_WIDTH / 2;
    float positionY = P_WINDOW_WIDTH / 2;
    Vector2 position = c_vector2_createVector2(positionX, positionY);

    float scaleX = BALL_SIZE;
    float scaleY = BALL_SIZE;
    Vector2 scale = c_vector2_createVector2(scaleX, scaleY);

    float velocityX = p_ball_randomizeDirection(BALL_SPEED);
    float velocityY = p_ball_randomizeDirection(BALL_SPEED);
    Vector2 velocity = c_vector2_createVector2(velocityX, velocityY);

    ball->color = color;
    ball->position = position;
    ball->scale = scale;
    ball->velocity = velocity;
}

void p_ball_renderBall(const RigidBody *ball) {
    SDL_Rect rect = {
        .x = ball->position.x - (ball->scale.x / 2),
        .y = ball->position.y - (ball->scale.y / 2),
        .w = ball->scale.x,
        .h = ball->scale.y,
    };

    SDL_SetRenderDrawColor(p_renderer_getRenderer(), ball->color.r, ball->color.g, ball->color.b, ball->color.a);
    SDL_RenderFillRect(p_renderer_getRenderer(), &rect);
}

void p_ball_updateBall(RigidBody *ball, const float timeElapsed) {
    ball->position.x += ball->velocity.x * timeElapsed;
    ball->position.y += ball->velocity.y * timeElapsed;

    // If ball hits x-axis bounds, then increment player score.

    // If ball hits x-axis bounds, then bounce ball off.
    int ballHalfSizeX = ball->scale.y / 2;
    if (ball->position.x < ballHalfSizeX) {
        ball->velocity.x = fabs(ball->velocity.x);
    }
    if (ball->position.x > P_WINDOW_WIDTH - ballHalfSizeX) {
        ball->velocity.x = -fabs(ball->velocity.x);
    }

    // If ball hits y-axis bounds, then bounce ball off.
    int ballHalfSizeY = ball->scale.y / 2;
    if (ball->position.y < ballHalfSizeY) {
        ball->velocity.y = fabs(ball->velocity.y);
    }
    if (ball->position.y > P_WINDOW_HEIGHT - ballHalfSizeY) {
        ball->velocity.y = -fabs(ball->velocity.y);
    }

    // If ball hits player N paddle, then bounce ball off.
}
