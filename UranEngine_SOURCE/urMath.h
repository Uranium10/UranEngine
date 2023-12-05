#pragma once
#include "commonInclude.h"
namespace ur::math {
	struct Vector2 {
		static Vector2 ZERO;
		static Vector2 ONE;
		static Vector2 LEFT;
		static Vector2 RIGHT;
		static Vector2 UP;
		static Vector2 DOWN;

		float x;
		float y;
		Vector2() : x(0), y(0){};
		Vector2(float _x, float _y) : x(_x), y(_y) {}
		Vector2 operator+(const Vector2& vect) { return Vector2(x + vect.x, y + vect.y); }
		Vector2 operator-(const Vector2& vect) { return Vector2(x - vect.x, y - vect.y); }
		Vector2 operator*(float num) { return Vector2(x * num, y * num); }
		Vector2 operator/(float num) { return Vector2(x / num, y / num); }

		void operator+=(const Vector2& vect) { x += vect.x; y += vect.y; }
		void operator-=(const Vector2& vect) { x -= vect.x, y -= vect.y; }
		void operator*=(float num) { x *= num; y *= num; }
		void operator/=(float num) { x /= num; y /= num; }
		void operator=(const Vector2& vect) { x = vect.x; y = vect.y; }
		void operator=(const POINT& point) { x = point.x; y = point.y; }
		bool operator==(const Vector2& vect) { return (x == vect.x) && (y == vect.y); }
		bool operator==(Vector2& vect) { return (x == vect.x) && (y == vect.y); }
		bool operator!=(const Vector2& vect) { return (x != vect.x) || (y != vect.y); }
		bool operator!=(Vector2& vect) { return (x != vect.x) || (y != vect.y); }

	};
}

