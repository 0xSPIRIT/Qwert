#include "Input.h"

bool Input::isKeyPressed(const SDL_Scancode& code) {
	SDL_PumpEvents();
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	//continuous-response keys
	return keystate[code];
}

bool Input::isKeyReleased(const SDL_Scancode& code) {
	if (Input::event->type == SDL_KEYUP) {
		return code == event->key.keysym.sym;
	}
	return false;
}

const vec2i& Input::getMousePos() {
	SDL_GetMouseState(&pos.x, &pos.y);
	return pos;
}
