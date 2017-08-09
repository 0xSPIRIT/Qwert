#pragma once

#include <SDL.h>
#include "../input/Input.h"
#include "../entities/Player.h"
#include "../entities/Ground.h"

#include "../level/Level.h"

#include "../textbox/Textbox.h"

#include "Macros.h"

class Game {
public:
	Game(FrameCounter& counter, bool* running);
	~Game();

	void initRender(SDL_Renderer* renderer);

	void update(float dt);
	void render(SDL_Renderer* renderer);
private:
	bool* running;

	Level level;
	Textbox* box = new Textbox;
public:
	Input input;
};

