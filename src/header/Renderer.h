#ifndef BRICKBREAKER_RENDERER_H
#define BRICKBREAKER_RENDERER_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <sstream>
#include "Bricks.h"
#include "Status.h"

class Renderer {
public:
    void initialize();
	void initializeMainMenu();
    void initializeGame();

    void destroy();
    void destroyMainMenu();
    void destroyGame();

    void drawPaddle(SDL_Rect rect);
    void drawBall(SDL_Rect rect);
    void drawBrick(int health, SDL_Rect rect);
    void drawBricks(Bricks &bricks);
	void drawStatusBar(int health, int score, Status status);

    void drawMenuItems(int highlightedItem);
    void drawMenuTitle();

    int getWindowHeight() { return HEIGHT; };
    int getWindowWidth() { return WIDTH; };

    SDL_Renderer* getRenderer() { return renderer; };
private:
    int WIDTH = 800;
    int HEIGHT = 600;

	TTF_Font *FONT_LARGE;
	TTF_Font *FONT_SMALL;
	TTF_Font *FONT_SCORE;

	SDL_Color COLOR_WHITE = { 255, 255, 255 };
	SDL_Color COLOR_GREEN = { 141, 182, 0 };

	std::vector<SDL_Surface*> brickSurfaceVector;
	std::vector<SDL_Texture*> brickTextureVector;

    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Surface *ballSurface;
    SDL_Texture *ballTexture;

    SDL_Surface *paddleSurface;
    SDL_Texture *paddleTexture;

	SDL_Surface *hartSurface;
	SDL_Texture *hartTexture;

	SDL_Surface *titleSurface;
	SDL_Texture *titleTexture;

	int titleWidth = 0;
	int titleHeight = 0;

	int menuItems[4] = {0,0,0,0};

	SDL_Rect titlePosition;

	SDL_Surface* menuItemOne;
	SDL_Texture* menuItemOneTexture;

	SDL_Surface* menuItemTwo;
	SDL_Texture* menuItemTwoTexture;

	SDL_Rect firstOptionPosition;
	SDL_Rect secondOptionPosition;
};

#endif
