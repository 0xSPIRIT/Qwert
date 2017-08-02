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
	SDL_Rect r;
	r.x = rectangle.x - xOffset;
	r.y = rectangle.y - yOffset;
	r.w = rectangle.w;
	r.h = rectangle.h;
	SDL_RenderFillRect(renderer, &r);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, color.a);
}

bool Entity::isOnScreen(float cameraX, float cameraY) const {
	return (rectangle.x > cameraX - rectangle.w) && (rectangle.x < cameraX + WINDOW_WIDTH + rectangle.w) && (rectangle.y > cameraY - rectangle.h) && (rectangle.y < cameraY + WINDOW_HEIGHT + rectangle.h);
}