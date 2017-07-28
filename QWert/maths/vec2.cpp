#include "vec2.h"

vec2::vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

void vec2::print(const vec2& vec) {
	std::cout << "X: " << vec.x << "Y: " << vec.y << std::endl;
}