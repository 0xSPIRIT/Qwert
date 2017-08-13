#include "Game.h"
#include <iostream>
#include "../maths/vec2.h"
#include "../utils/FrameCounter.h"

Game::Game(FrameCounter& counter, bool* running) : level(counter, "demTexturesYo/levelData/level.lvl") {
	this->running = running;
}

Game::~Game() { TTF_Quit(); }

void Game::initRender(SDL_Renderer* renderer) {
	level.init(renderer);
}

void Game::update(float dt) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			*running = false;
			break;
		}
	}
	input.setEvent(&event);
	level.update(input, dt);
}

void Game::render(SDL_Renderer* renderer) {
	level.render(renderer);
}