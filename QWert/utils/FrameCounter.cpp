#include "FrameCounter.h"
#include <iostream>

void FrameCounter::update() {
	currentTime = SDL_GetTicks();
	dt = (currentTime - lastTime) / 1000;
	lastTime = currentTime;

	addedTime += dt;
	anotherAddedTime += dt;

	addedDT += dt;
	counterDT++;

	if (anotherAddedTime > 10) {
		anotherAddedTime = 0;
		avgDT = addedDT / counterDT;
	}

	if (addedTime < 1) {
		fps++;
	} else {
		std::cout << "FPS: " << fps << std::endl;
		fps = 0;
		addedTime = 0;
	}
}
