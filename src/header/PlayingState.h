//
// Created by ts on 4/24/2019.
//

#ifndef BRICKBREAKER_PLAYINGSTATE_H
#define BRICKBREAKER_PLAYINGSTATE_H

#include <SDL.h>
#include <memory.h>
#include "GameState.h"
#include "InputManager.h"
#include "Paddle.h"
#include "Renderer.h"
#include "Ball.h"
#include "Bricks.h"
#include "Brick.h"

class PlayingState : public GameState {
public:
    PlayingState();
    ~PlayingState();
    void update() override;
    void display(Renderer &renderer) override;
    void handleEvent() override;
    std::unique_ptr<GameState> nextState() override;
private:
    InputManager inputManager;

    Bricks bricks;
    Brick brick;
    Paddle paddle;
    Ball ball;

    SDL_Rect paddlePosition;
    SDL_Rect ballPosition;

    bool active = true; // temp
    bool isActive(); // temp

//    SDL_Event event;
//    void readEvent();
//    bool isKeyPressed(SDL_Keycode key) { return keymap[key]; }
//    std::map<int, bool> keymap;
//    bool KeyStillDown() {return event.key.repeat != 0;}
};


#endif //BRICKBREAKER_PLAYINGSTATE_H
