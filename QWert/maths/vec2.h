#pragma once
#include <iostream>

struct vec2 {
	vec2(float X, float Y) : x(X), y(Y) {}
	vec2() { x = 0; y = 0; }

	vec2& Add(const vec2& other);
	vec2& Subtract(const vec2& other);
	vec2& Multiply(const vec2& other);
	vec2& Divide(const vec2& other);

	vec2& Add(float value);
	vec2& Subtract(float value);
	vec2& Multiply(float value);
	vec2& Divide(float value);

	friend vec2 operator+(vec2 left, const vec2& right);
	friend vec2 operator-(vec2 left, const vec2& right);
	friend vec2 operator*(vec2 left, const vec2& right);
	friend vec2 operator/(vec2 left, const vec2& right);

	friend vec2 operator+(vec2 left, float value);
	friend vec2 operator-(vec2 left, float value);
	friend vec2 operator*(vec2 left, float value);
	friend vec2 operator/(vec2 left, float value);

	bool operator==(const vec2& other) const;
	bool operator!=(const vec2& other) const;

	vec2& operator+=(const vec2& other);
	vec2& operator-=(const vec2& other);
	vec2& operator*=(const vec2& other);
	vec2& operator/=(const vec2& other);

	vec2& operator+=(float value);
	vec2& operator-=(float value);
	vec2& operator*=(float value);
	vec2& operator/=(float value);

	bool operator<(const vec2& other) const;
	bool operator<=(const vec2& other) const;
	bool operator>(const vec2& other) const;
	bool operator>=(const vec2& other) const;

	float x, y;
};

struct vec2i {
	vec2i(int X, int Y) : x(X), y(Y) {}

	int x, y;
};