#pragma once

#include <SDL.h>

struct FrameCounter {
	int fps = 0;
	float dt = 0.01;
	float addedTime = 0;

	int addedDT = dt;
	int counterDT = 0;
	int avgDT = 0;
	float anotherAddedTime = 0;

	float currentTime = SDL_GetTicks();
	float lastTime = currentTime;

	void update();
};