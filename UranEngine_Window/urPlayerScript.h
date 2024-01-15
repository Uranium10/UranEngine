#pragma once
#include "..\\UranEngine_SOURCE\\urScript.h"

namespace ur {
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void CreateCat();

		void TopTransitionToIdle();
		void TopTransitionToUpper();
		void TransitionToSit();
		void TransitionFromSit();
		void TransitionFromSitFire();
	private:
		enum class eState {
			Idle,
			Run,
			Sit,
			SitWalk,
			Jump,
			Transition,
			TransToSit,
			TransToStand,
		};
		enum class eLook {
			Front,
			Upper,
			Down,
			End
		};
		enum class eWeapon {
			Pistol,
		};
	private:
		eState mState;
		eLook mLook;
		eWeapon mWeapon;

		float atkDelay;
		bool mbMove;
		bool mbFire;

		class Animator* mAnimator;
		class Animator* mPart;
		class Transform* mTransform;

		void behaviorsForUpdate();
		void keyCheckForUpdate();

		void Idle();
		void move();
		void sit();
		void moveToIdle();
		void jump();
		void sitWalk();
		void transToSit();
		void transToStand();

		void frontTransitionAnimToIdle();

		void playAttackAnimation();
		void playBombAnimation();

		void pressUpKey();
		void releaseUpKey();
		void pressDownKey();
		void releaseDownKey();
	};
}
