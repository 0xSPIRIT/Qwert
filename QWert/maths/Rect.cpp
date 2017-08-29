#include "Rect.h"

Rect::Rect(float x, float y, float w, float h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Rect::set(float x, float y, float w, float h) {
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

bool Rect::intersects(Rect& other) {
	return (x + w > other.x && x < other.x + other.w) && (y < other.y + other.h && y + h > other.y);
}

bool Rect::intersects(const vec2& point) {
	return (point.x >= x) && (point.y <= x + w) && (point.y >= y) && (point.y <= y + h);
}

float Rect::distance(Rect& other) {
	return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
}