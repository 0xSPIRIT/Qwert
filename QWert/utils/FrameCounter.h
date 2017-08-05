#pragma once

#include <SDL.h>

struct FrameCounter {
	int fps = 0;
	float dt = 0.01;
	float addedTime = 0;

	float currentTime = SDL_GetTicks();
	float lastTime = currentTime;

	void update();
};