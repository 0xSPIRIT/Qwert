#pragma once
#include <SDL.h>
#include <iostream>

namespace Input {
	struct Keyboard {
		void setEvent(SDL_Event* event) { this->event = event; }

		bool isKeyPressed(const SDL_Keycode& code);
		bool isKeyReleased(const SDL_Keycode& code);
		bool pressed = false;
	private:
		SDL_Event* event;
	};
	struct Mouse {

	};
}