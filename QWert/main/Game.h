#pragma once

#include <SDL.h>
#include "../input/Input.h"
#include "../entities/Player.h"

class Game {
public:
	Game(bool* running);
	~Game();

	void update(float dt);
	void render(SDL_Renderer* renderer);
private:
	bool* running;

	Player player;
public:
	Input::Keyboard keyboard;
};

