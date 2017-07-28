#pragma once
#include <SDL.h>

struct Rect {
	Rect(float x, float y, float w, float h);
	float x, y, w, h;

	SDL_Rect& toSDLRect();
private:
	SDL_Rect sdl_rect;
};