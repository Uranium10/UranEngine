#include "BulletTest.h"

namespace ur {
	void BulletTest::Update() {
		float xSpeed = dX * Time::DeltaTime();
		float ySpeed = dY * Time::DeltaTime();

		mX += xSpeed;
		mY += ySpeed;
	}

	void BulletTest::Render(HDC dc) {
		HDC mHdc = dc;

		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, brush);

		HPEN blankPen = (HPEN)GetStockObject(NULL_PEN);
		HPEN oldPen = (HPEN)SelectObject(mHdc, blankPen);

		Ellipse(mHdc, mX, mY, mWidth + mX, mHeight + mY);

		SelectObject(mHdc, oldbrush);
		DeleteObject(brush);

		SelectObject(mHdc, oldPen);
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
