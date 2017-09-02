#include "Level.h"

#include "../entities/Lava.h"
#include "../entities/Box.h"

Level::Level(FrameCounter& counter, const char* filePath) {
	this->counter = &counter;

	std::ifstream file;
	file.open(filePath);
	if (file.fail()) {
		Errors::FATAL("Failed to load " + std::string(filePath) + " Into the game!");
	}

	std::string tmp;

	while (std::getline(file, tmp)) {
		levelData.push_back(tmp);
	}

	insertEntities();
}

Level::~Level() {
	for (unsigned int i = 0; i < tiles.size(); i++) {
		delete tiles[i];
	}
}

void Level::init(SDL_Renderer* renderer) {
	for (unsigned int i = 0; i < entities.size(); i++) {
		entities[i]->init(renderer);
	}
}

void Level::update(Input& input, float dt) {
	for (unsigned int i = 0; i < entities.size(); i++) {
		entities[i]->update(input, dt);
	}
}

void Level::render(SDL_Renderer* renderer) {
	for (unsigned int i = 0; i < entities.size(); i++) {
		if (entities[i]->getScrollable()) {
			entities[i]->xOffset = cameraX;
			entities[i]->yOffset = cameraY;
		}
		if (entities[i]->isOnScreen(cameraX, cameraY)) {
			entities[i]->render(renderer);
		}
	}
}

int Level::getWidth() const {
	return fWidth * DEFAULT_TILE_SIZE;
}

int Level::getHeight() const {
	return height * DEFAULT_TILE_SIZE;
}

void Level::switchLevel(SDL_Renderer* renderer, const char* filePath) {
	levelData.clear();

	entities.clear();
	tiles.clear();

	std::ifstream file;
	file.open(filePath);
	if (file.fail()) {
		Errors::FATAL("Failed to load " + std::string(filePath) + " Into the game!");
	}

	std::string tmp;

	while (std::getline(file, tmp)) {
		levelData.push_back(tmp);
	}

	insertEntities();

	init(renderer);
}

void Level::insertEntities() {
	Player* player = nullptr;

	for (int y = 0; y < levelData.size(); y++) {
		height = levelData.size();
		for (int x = 0; x < levelData[y].size(); x++) {
			width.push_back(levelData[y].size());

			char currentChar = levelData[y][x];

			switch (currentChar) {
			case '@': {
				Player* player = new Player(this, Rect(x * DEFAULT_TILE_SIZE, y * DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE));
				entities.insert(entities.begin(), player);
				break;
			}
			case '#': {
				Ground* tile = new Ground(Rect(x * DEFAULT_TILE_SIZE, y * DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE));
				tiles.push_back(tile);
				entities.push_back(tile);
				break;
			}
			case '/': {
				Lava* lava = new Lava(player, Rect(x * DEFAULT_TILE_SIZE, y * DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE));
				tiles.push_back(lava);
				entities.push_back(lava);
				break;
			}
			case 'B': {
				Box* box = new Box(Rect(x * DEFAULT_TILE_SIZE, y * DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE), &entities, &tiles);
				entities.push_back(box);
				break;
			}
			}
		}
	}

	// For finding out the width of the level
	for (unsigned int i = 0; i < width.size(); i++) {
		if (i == 0) {
			fWidth = 0;
		}
		else if (width[i] > fWidth) {
			fWidth = width[i];
		}
	}
}