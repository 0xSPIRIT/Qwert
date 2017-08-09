#pragma once
#include <SDL.h>
#include "vec2.h"

struct Rect {
	Rect(float x, float y, float w, float h);
	Rect() : x(0), y(0), w(0), h(0) {};
	float x, y, w, h;

	void set(float x, float y, float w, float h);
	SDL_Rect& toSDLRect();
	bool intersects(Rect& other);
	bool intersects(vec2& point);
	float distance(Rect& other);

	vec2& getPos() { return vec2(x, y); }
	void setPos(const vec2& pos) { x = pos.x; y = pos.y; }
	void setPos(float x, float y) { this->x = x; this->y = y; }
private:
	SDL_Rect sdl_rect;
};