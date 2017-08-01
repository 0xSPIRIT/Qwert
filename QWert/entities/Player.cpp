#include "Player.h"

void Player::init(SDL_Renderer* renderer) {
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
			if (level->tiles[i]->getRectangle().intersects(right)) {
				rectangle.x = level->tiles[i]->getRectangle().x - rectangle.w;
			}
			if (level->tiles[i]->getRectangle().intersects(left)) {
				rectangle.x = level->tiles[i]->getRectangle().x + rectangle.w;
			}
			if (level->tiles[i]->getRectangle().intersects(down)) {
				rectangle.y = level->tiles[i]->getRectangle().y - rectangle.h;
				velY = 0;
				inMidAir = false;
				jumping = false;
			}
			else {
				inMidAir = true;
			}
		}
	}

	rectangle.x += abs(input.isKeyPressed(SDL_SCANCODE_D) + input.isKeyPressed(SDL_SCANCODE_RIGHT)) * spd * dt;
	rectangle.x -= abs(input.isKeyPressed(SDL_SCANCODE_A) + input.isKeyPressed(SDL_SCANCODE_LEFT)) * spd * dt;

	if ((input.isKeyPressed(SDL_SCANCODE_W) || input.isKeyPressed(SDL_SCANCODE_UP) || input.isKeyPressed(SDL_SCANCODE_SPACE)) && !jumping) {
		velY = -1.5;
		jumping = true;
	}
}

void Player::render(SDL_Renderer* renderer) {
	sprite.render(renderer);
}
