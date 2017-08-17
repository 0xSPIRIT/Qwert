#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "../utils/FrameCounter.h"

#include "../entities/Entity.h"
#include "../entities/Ground.h"

#include "../utils/Errors.h"

#include "../main/Variables.h"

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

	int getWidth() const;
	int getHeight() const;

	void switchLevel(SDL_Renderer* renderer, const char* filePath);

	void insertEntities();
private:
	float cameraX = 0, cameraY = 0;

	std::vector<int> width;
	int fWidth;
	int height;

	std::vector<std::string> levelData;
public:
	FrameCounter* counter;

	std::vector<Tile*> tiles;
	std::vector<Entity*> entities;
};