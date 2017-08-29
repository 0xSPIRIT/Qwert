#pragma once

#include <SDL_image.h>
#include "Entity.h"
#include "../main/Variables.h"
#include "../sprite/Sprite.h"
#include "../level/Level.h"
#include "../maths/vec2.h"

class Player : public Entity {
public:
	Player(Level* lvl, const Rect& rect) : level(lvl), Entity(rect),
		up((rectangle.x + (rectangle.w / 2) - 1), rectangle.y, 2, rectangle.h / 2),
		right((rectangle.x + rectangle.w - 20), rectangle.y + 5, 20, rectangle.h - 10),
		left(rectangle.x, rectangle.y + 5, 20, rectangle.h - 10),
		down((rectangle.x + (rectangle.w / 2) - 1), (rectangle.y + (rectangle.h / 2)), 2, rectangle.h / 2) { }
	~Player();

	virtual void init(SDL_Renderer* renderer);

	virtual void update(Input& input, float dt);
	virtual void render(SDL_Renderer* renderer);

	Sprite& getSprite() { return sprite; }
	void setSprite(Sprite& sprite) { this->sprite = sprite; }

	float getOriginalX() const { return originalX; }
	float getOriginalY() const { return originalY; }

	float getSpd() const { return spd; }
	float getOriginalSpd() const { return SPD; }
	void setSpd(float s) { spd = s; }

	float getJumpSpeed() const { return jumpspeed; }
	float getOriginalJumpSpeed() const { return JUMPSPEED; }
	void setJumpSpeed(float js) { jumpspeed = js; }

	Level* getLevel() const { return level; }
	void setLevel(Level* level) { this->level = level; }
private:
	float JUMPSPEED;
	float jumpspeed;
	float SPD;
	float spd;
	bool colliding;
	bool inMidAir;
	bool jumping;
	bool pressDown;

	vec2 vel;

	float originalX, originalY;

	Sprite sprite;
	Level* level;

	Rect up, right, left, down;
};