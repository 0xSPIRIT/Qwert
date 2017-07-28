#include "Rect.h"

Rect::Rect(float x, float y, float w, float h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

SDL_Rect& Rect::toSDLRect() {
	sdl_rect.x = x;
	sdl_rect.y = y;
	sdl_rect.w = w;
	sdl_rect.h = h;
	return sdl_rect;
}
