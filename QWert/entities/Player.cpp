#include "Player.h"

Player::Player(const Rect& rect) : Entity(rect) {

}

void Player::update(Input::Keyboard& keyboard, float dt) {
	rectangle.x += keyboard.isKeyPressed(SDLK_ESCAPE) * spd * dt;
}

void Player::render(SDL_Renderer* renderer) {
	Entity::render(renderer);
}