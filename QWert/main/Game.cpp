#include "Game.h"
#include <iostream>
#include "../maths/vec2.h"

Game::Game(bool* running) : player(Rect(50, 50, 100, 100)) {
	this->running = running;
}

Game::~Game() {

}

void Game::update(float dt) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			*running = false;
			break;
		}
	}
	keyboard.setEvent(&event);
	player.update(keyboard, dt);
}

void Game::render(SDL_Renderer* renderer) {
	player.render(renderer);
}