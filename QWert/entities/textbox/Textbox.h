#pragma once

#include "../Entity.h"
#include <SDL_ttf.h>

#include <vector>

class Textbox : public Entity {
public:
	Textbox(std::vector<Entity*> *listThatThisIsIn, const Rect& rect, const char* message);
	~Textbox();

	virtual void init(SDL_Renderer* renderer);

	virtual void update(Input& input, float dt);
	virtual void render(SDL_Renderer* renderer);
private:
	const char* message;
	TTF_Font* font;
	SDL_Texture* text;
	SDL_Surface* surfaceMessage;

	std::vector<Entity*> *listThatThisIsIn;
};