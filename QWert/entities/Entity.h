#pragma once
#include "../maths/vec2.h"
#include "../maths/Rect.h"
#include "../input/Input.h"
#include <SDL.h>

class Entity {
public:
	Entity(const Rect& rect);
	~Entity();

	virtual void update(Input::Keyboard& keyboard, float dt);
	virtual void render(SDL_Renderer* renderer);
protected:
	Rect rectangle;
	SDL_Color color;
public: // GETTERS AND SETTERS:
	void setColor(const SDL_Color& color) { this->color = color; }
	const SDL_Color& getColor() { return color; }

	void setRectangle(const Rect& rect) { rectangle = rect; }
	const Rect& getRectangle() { return rectangle; }
};