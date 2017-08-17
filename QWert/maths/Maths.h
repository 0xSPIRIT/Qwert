#pragma once

static float lerp(float from, float to, float f) {
	return from + f * (to - from);
}

static int absolute(float x) {
	if (x < 0) return -1;
	if (x > 0) return 1;
	return 0;
}

static float clamp(float val, float min, float max) {
	if (val < min) { return min; }
	if (val > max) { return max; }
	return val;
}