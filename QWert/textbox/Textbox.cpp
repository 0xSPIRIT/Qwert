#include "Textbox.h"

Textbox::~Textbox() {
	SDL_DestroyTexture(text);
	TTF_CloseFont(font);
}

void Textbox::init(SDL_Renderer* renderer, const char* message, const Rect& rect, SDL_Color& bgColor, SDL_Color& outlineColor) {
	this->message = message;
	this->backgroundColor = bgColor;
	this->outlineColor = outlineColor;
	rectangle = rect;
	if (TTF_Init() < 0) {
		Errors::FATAL("poo. sdl_ttf has failed to init!");
	}
	fs = 12;
	font = TTF_OpenFont("demTexturesYo/fonts/font.TTF", fs);
	
	surface = TTF_RenderText_Solid(font, message, this->outlineColor);

	text = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	fh = fs * 3;
	fw = strlen(message) * (fs * 1.5);
}

void Textbox::update(Input& input, float dt) {
	if (done) return;

	done = absolute(input.isKeyPressed(SDL_SCANCODE_RETURN) + input.isKeyPressed(SDL_SCANCODE_Z) + input.isKeyPressed(SDL_SCANCODE_Y));
}

void Textbox::render(SDL_Renderer* renderer) {
	if (done) return;

	SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
	SDL_RenderFillRect(renderer, &rectangle.toSDLRect());

	SDL_SetRenderDrawColor(renderer, outlineColor.r, outlineColor.g, outlineColor.b, outlineColor.a);
	SDL_RenderDrawRect(renderer, &rectangle.toSDLRect());

	SDL_Rect temp = { rectangle.x + rectangle.w / 2 - fw / 2, (rectangle.h - fh) / 2 , fw, fh };
	SDL_RenderCopy(renderer, text, NULL, &temp);
}