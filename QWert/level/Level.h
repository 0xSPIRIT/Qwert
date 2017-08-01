#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "../entities/Entity.h"
#include "../entities/Ground.h"

#include "../utils/Errors.h"

#include "../main/Macros.h"

class Level {
public:
	Level(const char* filePath);
	~Level();

	void init(SDL_Renderer* renderer);

	void update(Input& input, float dt);
	void render(SDL_Renderer* renderer);
private:
	std::vector<std::string> levelData;
public:
	std::vector<Tile*> tiles;
	std::vector<Entity*> entities;
};