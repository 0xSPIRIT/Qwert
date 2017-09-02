#pragma once

#include "Entity.h"
#include "Player.h"

#include <vector>

class Box : public Entity {
public:
	Box(const Rect& rect, std::vector<Entity*> *entities, std::vector<Tile*> *tiles);

	virtual void init(SDL_Renderer* renderer);

	virtual void update(Input& input, float dt);
	virtual void render(SDL_Renderer* renderer);
private:
	vec2 vel;

	std::vector<Entity*> *entities;
	std::vector<Tile*> *tiles;

	Player* player;

	float addedTime = 0.f;

	bool col = false;
	bool inMidAir = true;

	bool pickedUp = false;
	bool previouslyPressedEnter = false;

	Rect up, down, left, right;

	Sprite sprite;
};