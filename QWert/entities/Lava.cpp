#include "Lava.h"

Lava::Lava(Player* player, const Rect& rect) : Tile(rect) {
	this->player = player;
}

Lava::~Lava() {
	SDL_DestroyTexture(sprite.getTexture());
}

void Lava::init(SDL_Renderer* renderer) {
	sprite.init(renderer, "demTexturesYo/ground/ground.png", rectangle);
	SDL_SetTextureColorMod(sprite.getTexture(), 200, 5, 5);
}

void Lava::update(Input& input, float dt) {
	if (player->getRectangle().distance(rectangle) < 55) {
		player->getRectangle().setPos(player->getOriginalX(), player->getOriginalY());
	}
}

void Lava::render(SDL_Renderer* renderer) {
	sprite.render(renderer, xOffset, yOffset);
}
