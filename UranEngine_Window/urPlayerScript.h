#pragma once
#include "..\\UranEngine_SOURCE\\urScript.h"

namespace ur {
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			Attack,
			Transition,
		};
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void CreateCat();
	private:
		eState mState;
		class Animator* mAnimator;
		class Animator* mPart;

		void Idle();
		void move();
		void transition();
		void grooming();
	};
}
