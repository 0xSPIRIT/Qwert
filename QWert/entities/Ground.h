#pragma once

#include "Tile.h"
#include "../maths/rect.h"
#include "../sprite/Sprite.h"

class Ground : public Tile {
public:
	Ground(const Rect& rect);
	
	virtual void init(SDL_Renderer* renderer);

	virtual void update(float dt);
	virtual void render(SDL_Renderer* renderer);
private:
	Sprite grdSprite;
};