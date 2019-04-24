//
// Created by ts on 4/24/2019.
//

#ifndef BRICKBREAKER_GAMESTATE_H
#define BRICKBREAKER_GAMESTATE_H

#include <SDL.h>
#include <memory>
#include "Renderer.h"

class GameState {
public:
    virtual void update() = 0;
    virtual void display(Renderer &renderer) = 0;
    virtual void handleEvent() = 0;
    virtual std::unique_ptr<GameState> nextState() = 0;

    virtual bool isActive() = 0; // temp
};

#endif //BRICKBREAKER_GAMESTATE_H
