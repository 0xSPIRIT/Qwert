#pragma once

#include <SDL.h>
#include "../input/Input.h"
#include "../entities/Player.h"

static const char* WINDOW_TITLE = "This is the title of the window";
static const int WINDOW_WIDTH = 900;
static const int WINDOW_HEIGHT = 600;

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

