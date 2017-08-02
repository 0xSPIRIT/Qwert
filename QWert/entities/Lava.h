#pragma once

#include "Tile.h"
#include "Player.h"

class Lava : public Tile {
public:
	Lava(Player* player, const Rect& rect);
	~Lava();

	virtual void init(SDL_Renderer* renderer);

	virtual void update(Input& input, float dt);
	virtual void render(SDL_Renderer* renderer);
private:
	Player* player;
	Sprite sprite;
};