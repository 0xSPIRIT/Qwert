#include "Player.h"
#include "../maths/Maths.h"

Player::~Player() {
	SDL_DestroyTexture(sprite.getTexture());
}

void Player::init(SDL_Renderer* renderer) {
	originalX = rectangle.x;
	originalY = rectangle.y;
	isPlayer = true;
	sprite.init(renderer, "demTexturesYo/player/player.png", rectangle);
}


// WARNING: THIS UPDATE CODE IS VERY MESSY!
void Player::update(Input& input, float dt) {
	rectangle.y += velY;

	if (inMidAir || jumping) {
		velY += GRAVITY * dt;
	}

	up.set((rectangle.x + (rectangle.w / 2) - ((rectangle.w / 2) / 2)), rectangle.y, rectangle.w / 2, rectangle.h / 2);
	right.set((rectangle.x + rectangle.w - 5), rectangle.y + 5, 5, rectangle.h - 10);
	left.set(rectangle.x, rectangle.y + 5, 5, rectangle.h - 10);
	down.set((rectangle.x + (rectangle.w / 2) - ((rectangle.w / 2) / 2)), (rectangle.y + (rectangle.h / 2)), rectangle.w / 2, rectangle.h / 2);

	for (unsigned int i = 0; i < level->tiles.size(); i++) {
		if (level->tiles[i]->getRectangle().distance(rectangle) < 100) {
			if (level->tiles[i]->getRectangle().intersects(up)) {
				rectangle.y = level->tiles[i]->getRectangle().y + rectangle.h;
				velY = 0;
			}
			else if (level->tiles[i]->getRectangle().intersects(right)) {
				rectangle.x = level->tiles[i]->getRectangle().x - rectangle.w;
			}
			else if (level->tiles[i]->getRectangle().intersects(left)) {
				rectangle.x = level->tiles[i]->getRectangle().x + rectangle.w;
			}
			else if (level->tiles[i]->getRectangle().intersects(down)) {
				rectangle.y = level->tiles[i]->getRectangle().y - rectangle.h;
				velY = 0;
				inMidAir = false;
				jumping = false;
				pressDown = false;
			}
			else {
				inMidAir = true;
			}
		}
	}

	rectangle.x += abs(input.isKeyPressed(SDL_SCANCODE_D) + input.isKeyPressed(SDL_SCANCODE_RIGHT)) * spd * dt;
	rectangle.x -= abs(input.isKeyPressed(SDL_SCANCODE_A) + input.isKeyPressed(SDL_SCANCODE_LEFT)) * spd * dt;

	if ((input.isKeyPressed(SDL_SCANCODE_W) || input.isKeyPressed(SDL_SCANCODE_UP) || input.isKeyPressed(SDL_SCANCODE_SPACE)) && !jumping) {
		velY = -1.8f;
		jumping = true;
	}
	if ((input.isKeyPressed(SDL_SCANCODE_S) || input.isKeyPressed(SDL_SCANCODE_DOWN)) && !pressDown) {
		velY += 1.9f;
		pressDown = true;
	}

	if (input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
		rectangle.x = originalX;
		rectangle.y = originalY;
	}

	// SETTING UP THE CAMERA'S POSITION

	level->setCameraX(Maths::lerp(*level->getCameraX(), rectangle.x - (WINDOW_WIDTH / 2) + (rectangle.w / 2), 0.01f));
}

void Player::render(SDL_Renderer* renderer) {
	sprite.render(renderer, xOffset, yOffset);
}
