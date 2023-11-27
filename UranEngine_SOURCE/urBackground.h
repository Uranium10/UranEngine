#pragma once
#include "GameObject.h"

namespace ur {
	class BackGround : public GameObject
	{
	public:
		BackGround();
		~BackGround();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	};
}
