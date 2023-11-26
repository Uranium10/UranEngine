#pragma once

namespace ur::math {
	struct Vector2 {
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
	};
	static Vector2 ZERO = Vector2(0, 0);
	static Vector2 LEFT = Vector2(-1, 0);
	static Vector2 RIGHT = Vector2(1, 0);
	static Vector2 UP = Vector2(0, -1);
	static Vector2 DOWN = Vector2(0, 1);
}

