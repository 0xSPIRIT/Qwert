#include "Player.h"
#include "../maths/Maths.h"

Player::~Player() { SDL_DestroyTexture(sprite.getTexture()); }

void Player::init(SDL_Renderer* renderer) {
	originalX = rectangle.x;
	originalY = rectangle.y;

	isPlayer = true;
	colliding = false;
	inMidAir = true;
	jumping = false;
	pressDown = false;

	SPD = 550.f; // This is the speed that is going to be constant.
	spd = SPD;

	intervalTimeForGravity = 0;
	intervalBoolForGravity = false;

	JUMPSPEED = 2.f;
	jumpspeed = JUMPSPEED;

	sprite.init(renderer, "demTexturesYo/player/player.png", rectangle);
}

// WARNING: THIS UPDATE CODE IS VERY MESSY!
void Player::update(Input& input, float dt) {
	rectangle.y += vel.y;

	if ((input.isKeyPressed(SDL_SCANCODE_W) || input.isKeyPressed(SDL_SCANCODE_UP)) && !intervalBoolForGravity) {
		input.GRAVITY_DIRECTION = Direction::Up;
		intervalBoolForGravity = true;
	}

	if ((input.isKeyPressed(SDL_SCANCODE_S) || input.isKeyPressed(SDL_SCANCODE_DOWN)) && !intervalBoolForGravity) {
		input.GRAVITY_DIRECTION = Direction::Down;
		intervalBoolForGravity = true;
	}

	intervalTimeForGravity += dt;

	if (intervalTimeForGravity > 0.1f) {
		intervalTimeForGravity = 0.f;
		intervalBoolForGravity = false;
	}
	
	// Collisions
	{
		if (inMidAir || jumping) {
			if (input.GRAVITY_DIRECTION == Direction::Down) {
				vel.y += GRAVITY * dt;
			}
			if (input.GRAVITY_DIRECTION == Direction::Up) {
				vel.y -= GRAVITY * dt;
			}
		}

		up.set((rectangle.x + (rectangle.w / 2) - 1), rectangle.y, 2, rectangle.h / 2);
		right.set((rectangle.x + rectangle.w - 20), rectangle.y + 5, 20, rectangle.h - 10);
		left.set(rectangle.x, rectangle.y + 5, 20, rectangle.h - 10);
		down.set((rectangle.x + (rectangle.w / 2) - 1), (rectangle.y + (rectangle.h / 2)), 2, rectangle.h / 2);

		for (unsigned int i = 0; i < level->tiles.size(); i++) {
			if (level->tiles[i]->getRectangle().distance(rectangle) < 100) {
				if (level->tiles[i]->getRectangle().intersects(up)) {
					if (input.GRAVITY_DIRECTION == Direction::Down) {
						rectangle.y = level->tiles[i]->getRectangle().y + rectangle.h;
						vel.y = 0;
					}
					if (input.GRAVITY_DIRECTION == Direction::Up) {
						rectangle.y = level->tiles[i]->getRectangle().y + rectangle.h;
						vel.y = 0;
						inMidAir = false;
						jumping = false;
						pressDown = false;
					}
				}
				else if (level->tiles[i]->getRectangle().intersects(right)) {
					rectangle.x = level->tiles[i]->getRectangle().x - rectangle.w;
					vel.x = 0;
				}
				else if (level->tiles[i]->getRectangle().intersects(left)) {
					rectangle.x = level->tiles[i]->getRectangle().x + rectangle.w;
					vel.x = 0;
				}
				else if (level->tiles[i]->getRectangle().intersects(down)) {
					if (input.GRAVITY_DIRECTION == Direction::Down) {
						rectangle.y = level->tiles[i]->getRectangle().y - rectangle.h;
						vel.y = 0;
						inMidAir = false;
						jumping = false;
						pressDown = false;
					}
					if (input.GRAVITY_DIRECTION == Direction::Up) {
						rectangle.y = level->tiles[i]->getRectangle().y - rectangle.h;
						vel.y = 0;
					}
				}
				else {
					inMidAir = true;
				}
			}
		}
	}

	if (input.isKeyPressed(SDL_SCANCODE_D) || input.isKeyPressed(SDL_SCANCODE_RIGHT)) {
		rectangle.x += dt * spd;
		vel.x = dt * spd;
	}
	else if (input.isKeyPressed(SDL_SCANCODE_A) || input.isKeyPressed(SDL_SCANCODE_LEFT)) {
		rectangle.x -= dt * spd;
		vel.x = dt * -spd;
	}
	else {
		vel.x = 0;
	}

#if 0
	if ((input.isKeyPressed(SDL_SCANCODE_W) || input.isKeyPressed(SDL_SCANCODE_UP) || input.isKeyPressed(SDL_SCANCODE_SPACE)) && !jumping) {
		vel.y -= jumpspeed;
		jumping = true;
	}
	if ((input.isKeyPressed(SDL_SCANCODE_S) || input.isKeyPressed(SDL_SCANCODE_DOWN)) && !pressDown) {
		vel.y += (jumpspeed != 0) ? jumpspeed + 0.1f : 0;
		pressDown = true;
	}
#endif

	if (input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
		rectangle.x = originalX;
		rectangle.y = originalY;
	}

	if (input.isKeyPressed(SDL_SCANCODE_LEFTBRACKET)) {
		DEBUG = false;
	}
	if (input.isKeyPressed(SDL_SCANCODE_RIGHTBRACKET)) {
		DEBUG = true;
	}

	// SETTING UP THE CAMERA'S POSITION

	level->setCameraX(clamp(lerp(*level->getCameraX(), rectangle.x - (WINDOW_WIDTH / 2) + (rectangle.w / 2), 0.01f), 0, level->getWidth() - WINDOW_WIDTH));
}

void Player::render(SDL_Renderer* renderer) {
	sprite.render(renderer, xOffset, yOffset);

	if (DEBUG) {
		SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);

		SDL_Rect u = {up.x - xOffset, up.y - yOffset, up.w, up.h};
		SDL_RenderDrawRect(renderer, &u);
		SDL_Rect d = { down.x - xOffset, down.y - yOffset, down.w, down.h };
		SDL_RenderDrawRect(renderer, &d);
		SDL_Rect l = { left.x - xOffset, left.y - yOffset, left.w, left.h };
		SDL_RenderDrawRect(renderer, &l);
		SDL_Rect r = { right.x - xOffset, right.y - yOffset, right.w, right.h };
		SDL_RenderDrawRect(renderer, &r);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	}
}