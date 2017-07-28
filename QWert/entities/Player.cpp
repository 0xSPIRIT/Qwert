#include "Player.h"

Player::Player(const Rect& rect) : Entity(rect) {

}

void Player::update(Input::Keyboard& keyboard, float dt) {
	rectangle.x += keyboard.isKeyPressed(SDL_SCANCODE_D) * spd * dt;
	rectangle.x -= keyboard.isKeyPressed(SDL_SCANCODE_A) * spd * dt;
	rectangle.y += keyboard.isKeyPressed(SDL_SCANCODE_S) * spd * dt;
	rectangle.y -= keyboard.isKeyPressed(SDL_SCANCODE_W) * spd * dt;
}

void Player::render(SDL_Renderer* renderer) {
	Entity::render(renderer);
}