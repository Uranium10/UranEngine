#include "EnemyTest.h"
namespace ur {
	void EnemyTest::Initialize(float _x, float _y, float _dx, float _dy, int _w, int _h) {
		mX = _x;
		mY = _y;
		dX = _dx;
		dY = _dy;
		mWidth = _w;
		mHeight = _h;
	}
	void EnemyTest::Update() {
		float xSpeed = dX * Time::DeltaTime();
		float ySpeed = dY * Time::DeltaTime();

		if (mX + mWidth + xSpeed >= 1600) {
			mX = 1600 - mWidth;
			dX = -dX;
		}
		else if (mX + xSpeed <= 0) {
			mX = 0;
			dX = -dX;
		}
		else {
			mX += xSpeed;
		}
		if (mY + mHeight + ySpeed >= 900) {
			mY = 900 - mHeight;
			dY = -dY;
		}
		else if (mY + ySpeed <= 0) {
			mY = 0;
			dY = -dY;
		}
		else {
			mY += ySpeed;
		}
	}
	void EnemyTest::Render(HDC dc) {
		HDC mHdc = dc;

		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, brush);

		HPEN blackPen = (HPEN)GetStockObject(BLACK_PEN);
		HPEN oldPen = (HPEN)SelectObject(mHdc, blackPen);

		Ellipse(mHdc, mX, mY, mWidth + mX, mHeight + mY);

		SelectObject(mHdc, oldbrush);
		DeleteObject(brush);
		//
		SelectObject(mHdc, oldPen);
	}
}