#include "FrameCounter.h"

void FrameCounter::update(float perSecond) {
	currentTime = SDL_GetTicks();
	dt = (currentTime - lastTime) / 1000;
	addedTime += dt;
	lastTime = currentTime;

	if (addedTime < perSecond) {
		frames++;
	} else {
		std::cout << "Frames Per " << perSecond << " second(s): " << frames << std::endl;
		addedTime = 0;
		frames = 0;
	}
}
