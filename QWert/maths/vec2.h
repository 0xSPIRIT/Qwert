#pragma once
#include <iostream>

struct vec2 {
	vec2(float x, float y);

	float x, y;

	static void print(const vec2& vec);
};