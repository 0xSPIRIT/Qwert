#include "Box.h"

Box::Box(const Rect& rect, std::vector<Entity*> *entities, std::vector<Tile*> *tiles) : Entity(rect),
	up((rectangle.x + (rectangle.w / 2) - 1), rectangle.y, 2, rectangle.h / 2),
	right((rectangle.x + rectangle.w - 20), rectangle.y + 5, 20, rectangle.h - 10),
	left(rectangle.x, rectangle.y + 5, 20, rectangle.h - 10),
	down((rectangle.x + (rectangle.w / 2) - 1), (rectangle.y + (rectangle.h / 2)), 2, rectangle.h / 2)
{
	this->entities = entities;
	this->tiles = tiles;
}

void Box::init(SDL_Renderer* renderer) { 
	for (unsigned int i = 0; i < entities->size(); i++) {
		if (entities->at(i)->isPlayer) player = (Player*)entities->at(i);
	}

	sprite.init(renderer, "demTexturesYo/box/box.png", rectangle);
}

void Box::update(Input& input, float dt) {
	addedTime += dt;

	rectangle.x += vel.x;
	rectangle.y += vel.y;

	// Collisions
	{
		col = rectangle.intersects(player->getRectangle());
		
		up.set((rectangle.x + (rectangle.w / 2) - 1), rectangle.y, 2, rectangle.h / 2);
		right.set((rectangle.x + rectangle.w - 20), rectangle.y + 5, 20, rectangle.h - 10);
		left.set(rectangle.x, rectangle.y + 5, 20, rectangle.h - 10);
		down.set((rectangle.x + (rectangle.w / 2) - 1), (rectangle.y + (rectangle.h / 2)), 2, rectangle.h / 2);

		for (unsigned int i = 0; i < tiles->size(); i++) {
			if (tiles->at(i)->getRectangle().distance(rectangle) < 100) {
				if (tiles->at(i)->getRectangle().intersects(up)) {
					rectangle.y = tiles->at(i)->getRectangle().y + rectangle.h;
					vel.y = 0;
				}
				else if (tiles->at(i)->getRectangle().intersects(right)) {
					rectangle.x = tiles->at(i)->getRectangle().x - rectangle.w;
					vel.x = 0;
				}
				else if (tiles->at(i)->getRectangle().intersects(left)) {
					rectangle.x = tiles->at(i)->getRectangle().x + rectangle.w;
					vel.x = 0;
				}
				else if (tiles->at(i)->getRectangle().intersects(down)) {
					rectangle.y = tiles->at(i)->getRectangle().y - rectangle.h;
					vel.y = 0;
					vel.x *= 1 - (FLOOR_FRICTION * dt); // This is actually phisx doe
					inMidAir = false;
				}
				else {
					inMidAir = true;
				}
			}
		}
	}

	// Physics
	{
		vel.x *= 1 - (AIR_RESISTANCE * dt);

		if (inMidAir && !pickedUp) {
			vel.y += GRAVITY;
		}

		if (col && input.isKeyPressed(SDL_SCANCODE_RETURN) && !previouslyPressedEnter) {
			switch (pickedUp) {
			case true: {
				pickedUp = false;
				vel.x = player->getVel().x;
				vel.y = player->getVel().y;
				break;
			}
			case false: {
				pickedUp = true;
				break;
			}
			}
			previouslyPressedEnter = true;
		}

		if (addedTime > 1 /*seconds*/) {
			previouslyPressedEnter = false;
			addedTime = 0;
		}

		if (pickedUp) {
			rectangle.x = player->getRectangle().x;
			rectangle.y = player->getRectangle().y - rectangle.h + 5; // +5 is to make sure that they are always colliding
		}
	}

}

void Box::render(SDL_Renderer* renderer) {
	sprite.render(renderer, xOffset, yOffset);
}
