#pragma once
#include "urComponent.h"
#include "urAnimator.h"

namespace ur {
	class Script : public Component {
	public:
		Script();
		~Script();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void PlayAnimationWithSide(WST& anim, Animator* am, bool loop = true);

		const wchar_t* SIDES[2] = { L"L", L"R" };
		enum class eSide {
			Left,
			Right,
		};

		eSide mSide;
	private:

	};
}