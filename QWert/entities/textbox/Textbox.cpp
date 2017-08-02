#include "Textbox.h"

Textbox::Textbox(std::vector<Entity*> *listThatThisIsIn, const Rect& rect, const char* message) : Entity(rect) {
	font = TTF_OpenFont("demTexturesYo/fonts/LeelawUI.ttf", 24);
	SDL_Color white = { 255, 255, 255 };
	surfaceMessage = TTF_RenderText_Solid(font, message, white);
}

Textbox::~Textbox() {
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(text);
}

void Textbox::init(SDL_Renderer* renderer) {
	text = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
}

void Textbox::update(Input& input, float dt) {
	if (input.isKeyPressed(SDL_SCANCODE_RETURN) || input.isKeyPressed(SDL_SCANCODE_Z)) {
		for (unsigned int i = 0; i < listThatThisIsIn->size(); i++) {
			if (listThatThisIsIn->at(i) == this) {
				listThatThisIsIn->erase(listThatThisIsIn->begin() + i);
			}
		}
	}
}

void Textbox::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &rectangle.toSDLRect());
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &Rect(rectangle.x + 1, rectangle.y + 1, rectangle.w - 2, rectangle.h - 2).toSDLRect());

	SDL_RenderCopy(renderer, text, nullptr, &rectangle.toSDLRect());
}
