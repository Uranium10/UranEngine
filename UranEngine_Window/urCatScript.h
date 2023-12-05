#pragma once
#include "..\\UranEngine_SOURCE\\urScript.h"

namespace ur
{
	class Transform;
	class CatScript : public Script
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
		enum class eDirection {
			Left,
			Right,
			Up,
			Down,
			End,
		};
		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;
		float mTime;

		void Idle();
		void move();
		void translate(Transform* tr);
		void PlayWalkAnimationByDirection(eDirection dir);
	private:

	};
}