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
	box->init(renderer, "Does this look like a nice textbox?", Rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 6), SDL_Color(), SDL_Color() = { 255, 255, 255 });
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
	box->update(input, dt);
}

void Game::render(SDL_Renderer* renderer) {
	level.render(renderer);
	box->render(renderer);

	if (input.isKeyPressed(SDL_SCANCODE_Q)) {
		level.switchLevel(renderer, "demTexturesYo/levelData/level2.lvl");
	}
}