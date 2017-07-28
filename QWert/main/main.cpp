#include <iostream>
#include <SDL.h>

#include "Game.h"
#include "../utils/FrameCounter.h"

int main(int argc, char* argv[]) {
	
	SDL_Window* window;
	bool running = true;

	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "OH MAH GAHD SDL FAILLED TO INIT!" << std::endl;
		std::cin.get();
		return 1;
	}

	window = SDL_CreateWindow("This is not a window.", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 600, SDL_WINDOW_SHOWN);
	if (!window) {
		std::cerr << "OH MAH GAHD THE SDL WINDOW FAILED TO BE CREATED INTO EXISTENCE :(" << std::endl;
		std::cin.get();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Game game(&running);
	FrameCounter counter;

	while (running) {
		counter.update(1.f);
		game.update(counter.dt);

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