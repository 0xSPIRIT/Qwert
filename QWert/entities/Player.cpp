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

	SPD = 800.f; // This is the speed that is going to be constant.
	spd = SPD;

	JUMPSPEED = 2.f;
	jumpspeed = JUMPSPEED;

	// Powerups
	teleportPower = true;
	pressingLeft = false;

	time = 0; // A time variable for whenever I need it

	sprite.init(renderer, "demTexturesYo/player/player.png", rectangle);
}

// WARNING: THIS UPDATE CODE IS VERY MESSY!
void Player::update(Input& input, float dt) {
	rectangle.y += vel.y;
	rectangle.x += vel.x;
	
	// Collisions
	{
		if (inMidAir || jumping) {
			vel.y += GRAVITY;
		}

		up.set((rectangle.x + (rectangle.w / 2) - ((rectangle.w / 2) / 2)), rectangle.y, rectangle.w / 2, rectangle.h / 2);
		right.set((rectangle.x + rectangle.w - 5), rectangle.y + 5, 5, rectangle.h - 10);
		left.set(rectangle.x, rectangle.y + 5, 5, rectangle.h - 10);
		down.set((rectangle.x + (rectangle.w / 2) - ((rectangle.w / 2) / 2)), (rectangle.y + (rectangle.h / 2)), rectangle.w / 2, rectangle.h / 2);

		for (unsigned int i = 0; i < level->tiles.size(); i++) {
			if (level->tiles[i]->getRectangle().distance(rectangle) < 100) {
				if (level->tiles[i]->getRectangle().intersects(up)) {
					rectangle.y = level->tiles[i]->getRectangle().y + rectangle.h;
					vel.y = 0;
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
					rectangle.y = level->tiles[i]->getRectangle().y - rectangle.h;
					vel.y = 0;
					inMidAir = false;
					jumping = false;
					pressDown = false;
				}
				else {
					inMidAir = true;
				}
			}
		}
	}

	if (input.isKeyPressed(SDL_SCANCODE_D) || input.isKeyPressed(SDL_SCANCODE_RIGHT)) {
		rectangle.x += spd * dt;
		vel.x = 0;
	}
	if (input.isKeyPressed(SDL_SCANCODE_A) || input.isKeyPressed(SDL_SCANCODE_LEFT)) {
		rectangle.x -= spd * dt;
		vel.x = 0;
	}

	if ((input.isKeyPressed(SDL_SCANCODE_W) || input.isKeyPressed(SDL_SCANCODE_UP) || input.isKeyPressed(SDL_SCANCODE_SPACE)) && !jumping) {
		vel.y -= jumpspeed;
		jumping = true;
	}
	if ((input.isKeyPressed(SDL_SCANCODE_S) || input.isKeyPressed(SDL_SCANCODE_DOWN)) && !pressDown) {
		vel.y += (jumpspeed != 0) ? jumpspeed + 0.1f : 0;
		pressDown = true;
	}

	if (input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
		rectangle.x = originalX;
		rectangle.y = originalY;
	}

	// Teleportation

	if (teleportPower) {
		if (!input.isMousePressed(MOUSE_LEFT)) {
			pressingLeft = false;
		}
		if (input.isMousePressed(MOUSE_LEFT) && !pressingLeft) {
			rectangle.setPos(input.getMousePos().x + xOffset, input.getMousePos().y + yOffset);
			vel.x = 0;
			vel.y = 0;
			pressingLeft = true;
			inMidAir = true;
		}
	}

	// SETTING UP THE CAMERA'S POSITION

	if (!pressingLeft || pressingLeft) {
		level->setCameraX(clamp(lerp(*level->getCameraX(), rectangle.x - (WINDOW_WIDTH / 2) + (rectangle.w / 2), 0.01f), 0, level->getWidth() - WINDOW_WIDTH));
	}
}

void Player::render(SDL_Renderer* renderer) {
	sprite.render(renderer, xOffset, yOffset);
}
