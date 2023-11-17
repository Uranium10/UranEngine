#pragma once
#include "commonInclude.h"

namespace ur {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void setPosition(float x, float y) {
			mX = x;
			mY = y;
		}
		float getPositionX() { return mX; }
		float getPositionY() { return mY; }

		void Update();
		void LateUpdate();
		void Render(HDC hdc);
	private:
		float mX;
		float mY;
	};
}

