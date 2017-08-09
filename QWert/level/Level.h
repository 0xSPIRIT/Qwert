#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "../utils/FrameCounter.h"

#include "../entities/Entity.h"
#include "../entities/Ground.h"

#include "../utils/Errors.h"

#include "../main/Macros.h"

class Level {
public:
	Level(FrameCounter& counter, const char* filePath);
	~Level();

	void init(SDL_Renderer* renderer);

	void update(Input& input, float dt);
	void render(SDL_Renderer* renderer);

	float* getCameraX() { return &cameraX; }
	float* getCameraY() { return &cameraY; }

	void setCameraX(float x) { cameraX = x; }
	void setCameraY(float y) { cameraY = y; }

	void switchLevel(SDL_Renderer* renderer, const char* filePath);
private:
	std::vector<std::string> levelData;

	float cameraX = 0, cameraY = 0;
public:
	FrameCounter* counter;
	std::vector<Tile*> tiles;
	std::vector<Entity*> entities;
};