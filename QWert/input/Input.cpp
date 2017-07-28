#include "Input.h"

bool Input::Keyboard::isKeyPressed(const SDL_Scancode& code) {
	SDL_PumpEvents();
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	//continuous-response keys
	return keystate[code];
}

bool Input::Keyboard::isKeyReleased(const SDL_Scancode& code) {
	if (event->type == SDL_KEYUP) {
		return code == event->key.keysym.sym;
	}
	return false;
}
