#include "Input.h"

bool Input::isKeyPressed(const SDL_Scancode& code) {
	SDL_PumpEvents();
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	//continuous-response keys
	return keystate[code];
}

bool Input::isKeyReleased(const SDL_Keycode& code) {
	if (event->type == SDL_KEYUP) {
		return code == event->key.keysym.sym;
	}
	return false;
}

bool Input::isMousePressed(int button) {
	return (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button));
}

const vec2& Input::getMousePos() {
	SDL_GetMouseState(&pos.x, &pos.y);
	return vec2(pos.x, pos.y);
}
