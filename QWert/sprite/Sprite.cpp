#include "Sprite.h"

void Sprite::init(SDL_Renderer* renderer, const char* filePath, Rect& rectangle) {
	texture = IMG_LoadTexture(renderer, filePath);
	this->rectangle = &rectangle;
}

void Sprite::render(SDL_Renderer* renderer, float xOffset, float yOffset) {
	SDL_Rect r;
	r.x = rectangle->x - xOffset;
	r.y = rectangle->y - yOffset;
	r.w = rectangle->w;
	r.h = rectangle->h;
	SDL_RenderCopy(renderer, texture, nullptr, &r);
}