#ifndef BRICKBREAKER_COLLISIONMANAGER_H
#define BRICKBREAKER_COLLISIONMANAGER_H

#include <SDL_rect.h>
#include <thread>
#include <vector>

#include "Brick.h"
#include "Ball.h"

class CollisionManager
{
public:
	CollisionManager() {
		SDL_Log("CollisionManager() constructor called");
	}
	void collision(Ball* ball, SDL_Rect paddleRect, std::vector<Brick>* bricks );
	int brickCollisions() { return brickCollisionCounter; }

private:
	int brickCollisionCounter = 0;
	static bool paddleCollision( int horizontal, int vertical, SDL_Rect paddleRect);
	static bool paddleCollisionAtEnd(int horizontal, int x, int w );
	static bool ballBrickCollisionDetected( SDL_Rect brickRect, SDL_Rect ballRect);
	bool ballBrickCollision( SDL_Rect ballRect, std::vector<Brick>* bricks);
};
#endif
