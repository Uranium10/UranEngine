#include "BulletTest.h"

namespace ur {
	void BulletTest::Update() {

	}

	void BulletTest::Render(HDC dc) {

	}

	void BulletTest::Initialize(float _x, float _y, float _dx, float _dy, int _w, int _h) {
		mX = _x;
		mY = _y;
		dX = _dx;
		dY = _dy;
		mWidth = _w;
		mHeight = _h;
	}
}
