#pragma once
#include "GameObject.h"

namespace ur {
	class Stage1_1 : public GameObject
	{
	public:
		Stage1_1();
		~Stage1_1();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	};
}

