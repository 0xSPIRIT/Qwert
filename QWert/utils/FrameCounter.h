#pragma once

#include <SDL.h>
#include <iostream>

struct FrameCounter {
	unsigned int frames = 0;
	float dt = 0.001f;

	void update(float perSecond);
private:
	float addedTime = 0;

	float lastTime = SDL_GetTicks();
	float currentTime = lastTime;
};