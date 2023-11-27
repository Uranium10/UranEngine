#pragma once
#include "urComponent.h"

namespace ur {
	class Script : public Component {
	public:
		Script();
		~Script();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	};
}