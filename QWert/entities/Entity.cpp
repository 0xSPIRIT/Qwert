#include "Entity.h"
#include "../main/Game.h"

Entity::Entity(const Rect& rect) : rectangle(rect) {
	color.r = color.g = color.b = 0;
	color.a = 255;
}

Entity::~Entity() { }

void Entity::init(SDL_Renderer* renderer) { }

// DEFAULT

void Entity::update(Input& input, float dt) { }

void Entity::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rectangle.toSDLRect());
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, color.a);
}

bool Entity::isOnScreen() const {
	return (rectangle.x > -rectangle.w) && (rectangle.x < WINDOW_WIDTH + rectangle.w) && (rectangle.y > -rectangle.h) && (rectangle.y < WINDOW_HEIGHT + rectangle.h);
}