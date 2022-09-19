//
//  p_game.c
//  Pong
//
//  Created by Kaji Tetsushi on 2/20/22.
//  Copyright © 2022 Kaji Tetsushi. All rights reserved.
//

#include "pong_internal.h"

// TODO: Add ball and players states.

RigidBody ball;

typedef struct Player {
    int number;
    int score;
    RigidBody paddle;
} Player;

Player player1;
Player player2;

void p_player_initializePlayer(Player *player);
void p_player_renderPlayer(const Player *player);
void p_player_updatePlayer(Player *player, const float timeElapsed);

void p_game_handleSceneReady(const float timeElapsed, SDL_Renderer *renderer);

bool p_game_initializeGame(void) {
    bool subsystemsInitialized = p_subsystems_initializeSubsystems();
    if (!subsystemsInitialized) {
        return false;
    }
    
    bool windowInitialized = p_window_initializeWindow();
    if (!windowInitialized) {
        return false;
    }
    
    bool rendererInitialized = p_renderer_initializeRenderer(p_window_getWindow());
    if (!rendererInitialized) {
        return false;
    }
    
    bool windowReady = p_window_getWindow() ? true : false;
    if (!windowReady) {
        return false;
    }
    
    // TODO: Initialize game state, i.e. place ball at center, place players in opposing sides, etc.
    p_ball_initializeBall(&ball);
    p_player_initializePlayer(&player1);
    p_player_initializePlayer(&player2);
    
    return true;
}

void p_game_updateGame(const float timeElapsed) {
    p_scene_runWithBackground(timeElapsed, p_game_handleSceneReady);
}

void p_game_shutdownGame(void) {
    p_renderer_destroyRenderer();
    p_window_destroyWindow();
    p_subsystems_destroySubsystems();
}

void p_game_handleSceneReady(const float timeElapsed, SDL_Renderer *renderer) {
    // TODO: Add update and render logic for ball and paddles.
    p_ball_updateBall(&ball, timeElapsed);
    p_ball_renderBall(&ball);
    
    p_player_renderPlayer(&player1);
    p_player_renderPlayer(&player2);
}

void p_player_initializePlayer(Player *player) {
    
}

void p_player_renderPlayer(const Player *player) {
    SDL_Rect rect = {
    };
    SDL_SetRenderDrawColor(p_renderer_getRenderer(), player->paddle.color.r, player->paddle.color.g, player->paddle.color.b, player->paddle.color.a);
    SDL_RenderFillRect(p_renderer_getRenderer(), &rect);
}

void p_player_updatePlayer(Player *player, const float timeElapsed) {

}
