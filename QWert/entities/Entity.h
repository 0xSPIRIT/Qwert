#pragma once

#include "../maths/vec2.h"
#include "../maths/Rect.h"
#include "../input/Input.h"

#include <SDL.h>

class Entity {
public:
	Entity(const Rect& rectangle);
	~Entity();

	virtual void init(SDL_Renderer* renderer);

	virtual void update(Input& input, float dt);
	virtual void render(SDL_Renderer* renderer);

	bool isOnScreen() const;
protected:
	Rect rectangle;
	SDL_Color color;

	bool scrollable = true;
public: // GETTERS AND SETTERS:
	void setScrollable(bool s) { scrollable = s; }
	bool getScrollable() { return scrollable; }

	void setColor(const SDL_Color& color) { this->color = color; }
	const SDL_Color& getColor() { return color; }

	void setRectangle(const Rect& rect) { rectangle = rect; }
	Rect& getRectangle() { return rectangle; }
};