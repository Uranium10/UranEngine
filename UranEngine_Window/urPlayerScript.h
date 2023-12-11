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
		enum class eLook {
			Front,
			Upper,
			Down,
			End
		};
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void CreateCat();
		void TopTransitionToIdle();
		void TopTransitionToUpper();
	private:
		eState mState;
		eLook mLook;
		float atkDelay;
		int mSide;	// 0 : left, 1 : right
		class Animator* mAnimator;
		class Animator* mPart;
		class Transform* mTransform;

		void Idle();
		void move();
		void transition();
		void frontTransitionAnimToIdle();
		void playAttackAnimation();
	};
}
