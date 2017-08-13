#pragma once

#include <SDL_image.h>
#include "Entity.h"
#include "../main/Variables.h"
#include "../sprite/Sprite.h"
#include "../level/Level.h"

class Player : public Entity {
public:
	Player(Level* lvl, const Rect& rect) : level(lvl), Entity(rect), 
		up((rectangle.x + (rectangle.w / 2) - ((rectangle.w / 2) / 2)), rectangle.y, rectangle.w / 2, rectangle.h / 2),
		right((rectangle.x + rectangle.w - 5), rectangle.y + 5, 5, rectangle.h - 10),
		left(rectangle.x, rectangle.y + 5, 5, rectangle.h - 10),
		down((rectangle.x + (rectangle.w / 2) - ((rectangle.w / 2) / 2)), (rectangle.y + (rectangle.h / 2)), rectangle.w / 2, rectangle.h / 2) { }
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
	const float JUMPSPEED = 2.f;
	float jumpspeed = JUMPSPEED;
	const float SPD = 800.f;
	float spd = SPD;
	bool colliding = false;
	bool inMidAir = true;
	bool jumping = false;
	bool pressDown = false;
	float velY = 0;

	float originalX, originalY;
	
	Sprite sprite;
	Level* level;

	Rect up, right, left, down;
};