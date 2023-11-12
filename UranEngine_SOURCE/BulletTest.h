#pragma once
#include "GameObject.h"
#include "commonInclude.h"

namespace ur {
	class BulletTest:public GameObject {
	public:
		void Update();
		void Render(HDC dc);
		void Initialize(float _x, float _y, float _dx, float _dy, int _w, int _h);
		bool CheckOutBound() { return mX < 0 || mY < 0 || mX > 1600 || mY > 900; }
	private:
		float mWidth, mHeight;
		float dX, dY;
		float mX, mY;
	};
}

