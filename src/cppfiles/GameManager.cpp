#include "../header/GameManager.h"
#include "../header/GameState.h"
#include "../header/PlayingState.h"
#include "../header/MainMenuState.h"

void GameManager::init() {
	stateRenderer->initialize();
}

void GameManager::play() {

	SDL_Log("Making currentState...");
	std::unique_ptr<GameState> currentState(new MainMenuState(stateRenderer));

	while(currentState->isActive()) {
		currentState->handleEvent();
		currentState->update();
		currentState->display();

		SDL_Delay(2);

		if(currentState->nextState()) {
			std::unique_ptr<GameState> nextState = currentState->nextState();
			std::swap(currentState, nextState);
		}
	}

	gameEnded = true;
}

void GameManager::quit() {
	stateRenderer->destroy();
    SDL_Quit();
}
