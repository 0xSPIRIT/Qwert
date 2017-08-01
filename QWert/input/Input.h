#pragma once
#include <SDL.h>
#include <iostream>

#include "../maths/vec2.h"

struct Input {
	Input() : pos(0, 0) {};

	bool isKeyPressed(const SDL_Scancode& code);
	bool isKeyReleased(const SDL_Scancode& code);
	bool pressed = false;
	
	void setEvent(SDL_Event* event) { this->event = event; }
	const vec2i& getMousePos();
private:
	vec2i pos;
	SDL_Event* event;
};