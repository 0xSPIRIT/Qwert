#pragma once

#include "Textbox.h"
#include "../main/Macros.h"

#include <vector>

class TextboxBatch {
public:
	void init(SDL_Renderer* renderer, const std::vector<const char*>& messages, std::vector<SDL_Color*>& outlineColors, std::vector<SDL_Color*>& bgColors);
	void init(SDL_Renderer* renderer, const std::vector<const char*>& messages, SDL_Color& outlineColorsForAll, SDL_Color& bgColorsForAll);

	void update(Input& input, float dt);
	void render(SDL_Renderer* renderer);
public:
	bool done;
private:
	int current;
	std::vector<Textbox*> textboxes;
	std::vector<SDL_Color*> outlineColors, bgColors;
};