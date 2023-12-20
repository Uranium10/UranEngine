#pragma once
#include "urScript.h"
#include "GameObject.h"

namespace ur {
	class CrabScript : public Script{
	public:
		CrabScript();
		~CrabScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


		void MeleeToIdle();

		void SetTarget(GameObject* target) { mTarget = target; }
		GameObject* GetTarget() { return mTarget; }
	private:
		GameObject* mTarget;
		class Animator* mAnimator;
		float mTime;
		float mAttackDelay;

		enum class eState {
			Idle,
			Walk,
			Melee,
		};
		enum class eDirection {
			Left,
			Right,
		};

		eState mState;
		eDirection mDir;

		void idle();
		void walk();
		void melee();

		Vector2 mPos;
		Vector2 mTargetPos;

		Transform* mTr;

	};
}

