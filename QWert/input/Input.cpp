#include "Input.h"

bool Input::Keyboard::isKeyPressed(const SDL_Keycode& code) {
	if (event->type == SDL_KEYDOWN) {
		const char* current = SDL_GetKeyName(event->key.keysym.sym);
		const char* key = SDL_GetKeyName(code);
		if (!strcmp(current, key)) {
			pressed = true;
		}
	}
	if (event->type == SDL_KEYUP) {
		const char* current = SDL_GetKeyName(event->key.keysym.sym);
		const char* key = SDL_GetKeyName(code);
		if (!strcmp(current, key)) {
			pressed = false;
		}
	}
	return pressed;
}

bool Input::Keyboard::isKeyReleased(const SDL_Keycode& code) {
	if (event->type == SDL_KEYUP) {
		const char* current = SDL_GetKeyName(event->key.keysym.sym);
		const char* key = SDL_GetKeyName(code);
		return !strcmp(current, key);
	}
	return false;
}
