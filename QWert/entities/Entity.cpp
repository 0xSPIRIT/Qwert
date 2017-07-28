#include "Entity.h"

Entity::Entity(const Rect& rect) : rectangle(rect) {
	color.r = color.g = color.b = 0;
	color.a = 255;
}

Entity::~Entity() { }

// DEFAULT

void Entity::update(Input::Keyboard& keyboard, float dt) { }

void Entity::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rectangle.toSDLRect());
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, color.a);
}
