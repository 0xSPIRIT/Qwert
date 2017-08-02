#pragma once
#include "../maths/Rect.h"
#include <SDL_image.h>

struct Sprite {
public:
	Sprite() {}
	void init(SDL_Renderer* renderer, const char* filePath, Rect& rect);

	void render(SDL_Renderer* renderer, float xOffset, float yOffset);

	SDL_Texture* getTexture() { return texture; };
private:
	SDL_Texture* texture;
	Rect* rectangle;
};