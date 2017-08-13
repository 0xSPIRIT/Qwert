#include "TextboxBatch.h"

void TextboxBatch::init(SDL_Renderer* renderer, const std::vector<const char*>& messages, std::vector<SDL_Color*>& outlineColors, std::vector<SDL_Color*>& bgColors) {
	for (unsigned int i = 0; i < messages.size(); i++) {
		Textbox* textbox = new Textbox();
		textbox->init(renderer, messages[i], Rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 6), *bgColors[i], *outlineColors[i]);
		textboxes.push_back(textbox);
	}
	current = 0;
	done = false;
}
// I HOPE I DONT HAVE TO CHANGE ONE OF THESE
void TextboxBatch::init(SDL_Renderer* renderer, const std::vector<const char*>& messages, SDL_Color& outlineColorsForAll, SDL_Color& bgColorsForAll) {
	for (unsigned int i = 0; i < messages.size(); i++) {
		Textbox* textbox = new Textbox();
		textbox->init(renderer, messages[i], Rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 6), bgColorsForAll, outlineColorsForAll);
		textboxes.push_back(textbox);
	}
	current = 0;
	done = false;
}

void TextboxBatch::update(Input& input, float dt) {
	if (done) return;

	textboxes[current]->update(input, dt);
	if (textboxes[current]->done) {
		if (current < textboxes.size() - 1) {
			current++;
		} else {
			current = textboxes.size() - 1;
			done = true;
		}
	}
}

void TextboxBatch::render(SDL_Renderer* renderer) {
	if (done) return;

	textboxes[current]->render(renderer);
}
