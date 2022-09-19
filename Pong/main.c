//
//  main.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/12/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "game/game.h"

const char* WINDOW_TITLE = "Pong";
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

#pragma mark Random Number Generator
//#region Random Number Generator
void rng_seedRand(void) {
    srand((unsigned int)time(NULL));
}

bool rng_flipCoin(void) {
    return rand() % 2 == 1 ? true : false;
}
//#endregion

#pragma mark Ball
//#region Ball
typedef struct Ball {
    float x;
    float y;
    float xSpeed;
    float ySpeed;
    int size;
    int r;
    int g;
    int b;
    int a;
} Ball;

bool served = false;

const int BALL_SIZE = 10;
const float BALL_SPEED = 120;
const int BALL_R = 255;
const int BALL_G = 255;
const int BALL_B = 255;
const int BALL_A = 255;

Ball ball;

Ball ball_createBall(int size, float speed, int r, int g, int b, int a) {
    Ball ball = {
        .x = WINDOW_WIDTH / 2 - size / 2,
        .y = WINDOW_HEIGHT / 2 - size / 2,
        .xSpeed = speed * (rng_flipCoin() ? 1 : -1),
        .ySpeed = speed * (rng_flipCoin() ? 1 : -1),
        .size = size,
        .r = r,
        .g = g,
        .b = b,
        .a = a,
    };
    return ball;
}

void ball_updateBall(Ball *ball, float timeElapsed) {
    if (!served) {
        ball->x = WINDOW_WIDTH / 2;
        ball->y = WINDOW_HEIGHT / 2;
        return;
    }
    
    ball->x += ball->xSpeed * timeElapsed;
    ball->y += ball->ySpeed * timeElapsed;
}

void ball_renderBall(SDL_Renderer *renderer, const Ball *ball) {
    int ballHalfSize = ball->size / 2;
    
    SDL_Rect rect = {
        .x = ball->x - ballHalfSize,
        .y = ball->y - ballHalfSize,
        .w = ball->size,
        .h = ball->size,
    };
    SDL_SetRenderDrawColor(renderer, ball->r, ball->g, ball->b, ball->a);
    SDL_RenderFillRect(renderer, &rect);
}
//#endregion

#pragma mark Player
//#region Player
typedef struct Player {
    float x;
    float y;
    int r;
    int g;
    int b;
    int a;
    int score;
    int up;
    int down;
    int left;
    int right;
} Player;

const int PLAYER_WIDTH = 20;
const int PLAYER_HEIGHT = 75;
const int PLAYER_MARGIN = 10;
const int PLAYER_SPEED = 150.0f;

const int P1_X = PLAYER_MARGIN;
const int P1_R = 255;
const int P1_G = 0;
const int P1_B = 0;
const int P1_A = 255;

const int P2_X = WINDOW_WIDTH - PLAYER_WIDTH - PLAYER_MARGIN;
const int P2_R = 0;
const int P2_G = 0;
const int P2_B = 255;
const int P2_A = 255;

Player player1;
Player player2;

Player player_createPlayer(int x, int r, int g, int b, int a, int up, int down, int left, int right) {
    Player player = {
        .score = 0,
        .x = x,
        .y = WINDOW_HEIGHT / 2,
        .r = r,
        .g = g,
        .b = b,
        .a = a,
        .up = up,
        .down = down,
        .left = left,
        .right = right,
    };
    return player;
}

void player_updatePlayer(Player *player, float timeElapsed) {
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    
    // Update player position.
    if (keyboardState[player->up]) {
        player->y -= PLAYER_SPEED * timeElapsed;
    }
    
    if (keyboardState[player->down]) {
        player->y += PLAYER_SPEED * timeElapsed;
    }
    
    // Check if player paddle goes out of bounds.
    if (player->y < PLAYER_HEIGHT / 2) {
        player->y = PLAYER_HEIGHT / 2;
    }
    
    if (player->y < PLAYER_HEIGHT / 2) {
        player->y = PLAYER_HEIGHT / 2;
    }
    
    if (player->y >= WINDOW_HEIGHT - PLAYER_HEIGHT / 2) {
        player->y = WINDOW_HEIGHT - PLAYER_HEIGHT / 2;
    }
}

void player_renderPlayer(SDL_Renderer *renderer, const Player *player) {
    SDL_SetRenderDrawColor(renderer, player->r, player->g, player->b, player->a);
    SDL_Rect rect = {
        .x = player->x,
        .y = player->y - PLAYER_HEIGHT / 2,
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT,
    };
    SDL_RenderFillRect(renderer, &rect);
}
//#endregion

#pragma mark Court
//#region Court
const int SCORE_POINTS = 100;

void court_incrementPlayerScore(SDL_Window *window, Player *player, int points) {
    player->score += points;
    
    char *fmt = "Player 1: %d | Player 2: %d";
    int len = snprintf(NULL, 0, fmt, player1.score, player2.score);
    char buf[len + 1];
    snprintf(buf, len + 1, fmt, player1.score, player2.score);
    SDL_SetWindowTitle(window, buf);
}

void court_updateCourt(SDL_Window *window, Ball *ball, float timeElapsed) {
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    
    if (keyboardState[SDL_SCANCODE_SPACE]) {
        served = true;
    }
    
    int ballHalfSize = ball->size / 2;
    
    // Check if ball rect overlaps with either player's rect
    SDL_Rect ballRect = {
        .x = ball->x - ballHalfSize,
        .y = ball->y - ballHalfSize,
        .w = ball->size,
        .h = ball->size,
    };
    
    SDL_Rect player1Rect = {
        .x = P1_X,
        .y = (int)(player1.y) - PLAYER_HEIGHT / 2,
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT,
    };
    
    if (SDL_HasIntersection(&ballRect, &player1Rect)) {
        // TODO: Branch out here. When the ball collides with the sides instead of the face the paddle, flip ySpeed instead of xSpeed.
        // Ball goes to the right, but doesn't change vertical direction.
        ball->xSpeed = fabs(ball->xSpeed);
    }
    
    SDL_Rect player2Rect = {
        .x = P2_X,
        .y = (int)(player2.y) - PLAYER_HEIGHT / 2,
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT,
    };
    
    if (SDL_HasIntersection(&ballRect, &player2Rect)) {
        // TODO: Branch out here. When the ball collides with the sides instead of the face the paddle, flip ySpeed instead of xSpeed.
        // Ball goes to the left, but doesn't change vertical direction.
        ball->xSpeed = -fabs(ball->xSpeed);
    }
    
    if (ball->x < ballHalfSize) {
        served = false;
        ball->xSpeed = fabs(ball->xSpeed) * (rng_flipCoin() ? 1 : -1);
        ball->ySpeed = fabs(ball->ySpeed) * (rng_flipCoin() ? 1 : -1);
        court_incrementPlayerScore(window, &player2, SCORE_POINTS);
        return;
    }
    if (ball->x > WINDOW_WIDTH - ballHalfSize) {
        served = false;
        ball->xSpeed = fabs(ball->xSpeed) * (rng_flipCoin() ? 1 : -1);
        ball->ySpeed = fabs(ball->ySpeed) * (rng_flipCoin() ? 1 : -1);
        court_incrementPlayerScore(window, &player1, SCORE_POINTS);
        return;
    }
    
    if (ball->y < ballHalfSize) {
        ball->ySpeed = fabs(ball->ySpeed);
    }
    if (ball->y > WINDOW_HEIGHT - ballHalfSize) {
        ball->ySpeed = -fabs(ball->ySpeed);
    }
}
//#endregion

#pragma mark Main

// TODO: Prepare ball, paddles, score, etc.
void main_handleGameInitialize(SDL_Renderer *renderer, SDL_Window *window) {
    ball = ball_createBall(BALL_SIZE, BALL_SPEED, BALL_R, BALL_G, BALL_B, BALL_A);
    player1 = player_createPlayer(P1_X, P1_R, P1_G, P1_B, P1_A, SDL_SCANCODE_W, SDL_SCANCODE_S, 0, 0);
    player2 = player_createPlayer(P2_X, P2_R, P2_G, P2_B, P2_A, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, 0, 0);
}

// TODO: Change ball position, paddle position, score value, etc.
void main_handleGameUpdate(SDL_Renderer *renderer, SDL_Window *window, const float timeElapsed) {
    ball_updateBall(&ball, timeElapsed);
    ball_renderBall(renderer, &ball);
    
    player_updatePlayer(&player1, timeElapsed);
    player_renderPlayer(renderer, &player1);
    
    player_updatePlayer(&player2, timeElapsed);
    player_renderPlayer(renderer, &player2);
    
    court_updateCourt(window, &ball, timeElapsed);
}

int main(int argc, const char * argv[]) {
    rng_seedRand();
    atexit(game_shutdownGame);
    
    bool initialized = game_initializeGame(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, main_handleGameInitialize);
    if (!initialized) {
        exit(1);
    }

    bool quit = false;
    SDL_Event event;
    Uint32 lastTick = SDL_GetTicks();

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        Uint32 currentTick = SDL_GetTicks();
        float timeElapsed = (currentTick - lastTick) / 1000.0f;
        game_updateGame(timeElapsed, main_handleGameUpdate);
        lastTick = currentTick;
    }

    game_shutdownGame();
    
    return 0;
}
