#pragma once

#include "Entity.h"

class Tile : public Entity {
public:
	Tile(const Rect& rect) : Entity(rect) {}

	virtual void init(SDL_Renderer* renderer) {}

	virtual void update(Input input, float dt) {}
	virtual void render(SDL_Renderer* renderer) {}
};