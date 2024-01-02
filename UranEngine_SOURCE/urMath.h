#pragma once
#include "commonInclude.h"

namespace ur::math {
#define PI 3.141592f
	static float DegToRad(float deg) {
		return deg / 180 * PI;
	}
	static float RadToDeg(int rad) {
		return rad * 180 / PI;
	}
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

		void Clear() { x = 0.0f; y = 0.0f; }
		float Distance() { return sqrtf(x * x + y * y); }
		Vector2 Normalize() {
			float dist = Distance();
			return Vector2(x / dist, y / dist);
		}
		static float Dot(Vector2& v1, Vector2& v2) { return v1.x * v2.x + v1.y * v2.y; }
		// 2차원 가위곱은 그 크기만 제공
		static float Cross(Vector2& v1, Vector2& v2) { return v1.x * v2.y - v1.y * v2.x; }
		static Vector2 Rotate(Vector2& vector, float degree) {
			float rad = (degree / 180.0f) * PI;
			Vector2 v = vector.Normalize();
			float x = cosf(rad) * v.x - sinf(rad) * v.y;
			float y = sinf(rad) * v.x + cosf(rad) * v.y;
			return Vector2(x, y);
		}
		static float AngleBetween(Vector2& v1, Vector2& v2) {
			Vector2 vv1 = v1.Normalize();
			Vector2 vv2 = v2.Normalize();
			return acosf(Dot(vv1, vv2));
		}
	};
}

