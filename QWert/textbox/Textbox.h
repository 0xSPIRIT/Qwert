#pragma once

#include "../maths/Rect.h"
#include "../utils/Errors.h"
#include "../input/Input.h"
#include "../maths/Maths.h"

#include <SDL_ttf.h>

class Textbox {
public:
	Textbox() {}
	~Textbox();

	void init(SDL_Renderer* renderer, const char* message, const Rect& rect, SDL_Color& bgColor, SDL_Color& outlineColor);

	void update(Input& input, float dt);
	void render(SDL_Renderer* renderer);
public:
	bool done = false;
private:
	const char* message;

	int fw, fh, fs;

	SDL_Color backgroundColor, outlineColor;
	SDL_Color black = {0  , 0  , 0  , 255};
	SDL_Color white = {255, 255, 255, 255};

	Rect rectangle;

	TTF_Font* font;
	SDL_Texture* text;

	SDL_Surface* surface;
};