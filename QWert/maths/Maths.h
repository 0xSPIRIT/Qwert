#pragma once

class Maths {
public:
	static float lerp(float from, float to, float f) {
		return from + f * (to - from);
	}
};