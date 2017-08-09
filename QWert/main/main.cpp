#include <iostream>
#include <SDL.h>

#include "Game.h"
#include "../utils/FrameCounter.h"

int main(int argc, char** argv) {
	
	SDL_Window* window;
	bool running = true;

	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "OH MAH GAHD SDL FAILLED TO INIT!" << std::endl;
		std::cin.get();
		return 1;
	}

	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) {
		std::cerr << "OH MAH GAHD THE SDL WINDOW FAILED TO BE CREATED INTO EXISTENCE :(" << std::endl;
		std::cin.get();
		return 1;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	FrameCounter counter;
	Game game(counter, &running);

	game.initRender(renderer);

	while (running) {
		counter.update();
 		game.update(counter.dt);
		// TODO: ADD IN PRESET COLOR SCHEMES
		SDL_SetRenderDrawColor(renderer, 226, 226, 226, 255);
		SDL_RenderClear(renderer);
		/////////////////////////
		game.render(renderer);
		/////////////////////////
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}