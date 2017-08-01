#include "Game.h"
#include <iostream>
#include "../maths/vec2.h"

Game::Game(bool* running) : level("demTexturesYo/levelData/level.lvl") {
	this->running = running;
}

Game::~Game() { }

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