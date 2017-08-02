#include "Ground.h"

Ground::Ground(const Rect& rect) : Tile(rect) { }

Ground::~Ground() {
	SDL_DestroyTexture(grdSprite.getTexture());
}

void Ground::init(SDL_Renderer* renderer) {
	grdSprite.init(renderer, "demTexturesYo/ground/ground.png", rectangle);
}

void Ground::update(float dt) { }

void Ground::render(SDL_Renderer* renderer) {
	grdSprite.render(renderer, xOffset, yOffset);
}
