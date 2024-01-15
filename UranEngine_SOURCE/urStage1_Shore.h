#pragma once
#include "GameObject.h"

namespace ur {
	class Stage1_Shore : public GameObject {
	public:
		Stage1_Shore();
		~Stage1_Shore();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	};
}