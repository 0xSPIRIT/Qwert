#include "Sprite.h"

void Sprite::init(SDL_Renderer* renderer, const char* filePath, Rect& rectangle) {
	texture = IMG_LoadTexture(renderer, filePath);
	this->rectangle = &rectangle;
}

void Sprite::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, nullptr, &rectangle->toSDLRect());
}