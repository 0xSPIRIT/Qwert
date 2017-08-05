#include "FrameCounter.h"
#include <iostream>

void FrameCounter::update() {
	currentTime = SDL_GetTicks();
	dt = (currentTime - lastTime) / 1000;
	lastTime = currentTime;

	addedTime += dt;

	if (addedTime < 1) {
		fps++;
	} else {
		std::cout << "FPS: " << fps << std::endl;
		fps = 0;
		addedTime = 0;
	}
}
