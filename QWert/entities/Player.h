#pragma once
#include "Entity.h"


class Player : public Entity {
public:
	Player(const Rect& rect);

	virtual void update(Input::Keyboard& keyboard, float dt);
	virtual void render(SDL_Renderer* renderer);
private:
	float spd = 250;
};