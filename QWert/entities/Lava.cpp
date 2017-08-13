#include "Lava.h"

Lava::Lava(Player* player, const Rect& rect) : Tile(rect) {
	this->player = player;
}

Lava::~Lava() {
	SDL_DestroyTexture(sprite.getTexture());
}

void Lava::init(SDL_Renderer* renderer) {
	sprite.init(renderer, "demTexturesYo/ground/ground.png", rectangle);
	SDL_SetTextureColorMod(sprite.getTexture(), 150, 5, 5);
}

void Lava::update(Input& input, float dt) {
	Rect r(rectangle.x - 1, rectangle.y - 1, rectangle.w + 1, rectangle.h + 1);
	if (player->getRectangle().intersects(r)) {
		player->getRectangle().setPos(player->getOriginalX(), player->getOriginalY());
	}
}

void Lava::render(SDL_Renderer* renderer) {
	sprite.render(renderer, xOffset, yOffset);
}
