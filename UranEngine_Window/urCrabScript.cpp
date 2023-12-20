#include "urCrabScript.h"
#include "urCrab.h"
#include "urTransform.h"
#include "urAnimator.h"
#include "urTime.h"

namespace ur {
	CrabScript::CrabScript() 
		: mTarget(nullptr)
		, mAnimator(nullptr)
		, mTime(0)
		, mState(eState::Idle)
		, mDir(eDirection::Left)
		, mPos(Vector2::ZERO)
		, mTargetPos(Vector2::ZERO)
		, mTr(nullptr)
		, mAttackDelay(0){}
	CrabScript::~CrabScript() {}
	void CrabScript::Initialize() {
	}
	void CrabScript::Update() {
		//mTime += Time::DeltaTime();
		Transform* targTr = mTarget->GetComponent<Transform>();
		mTr = GetOwner()->GetComponent<Transform>();
		mTargetPos = mTarget ? targTr->GetPos(): Vector2::ZERO;
		mPos = mTr->GetPos();
		mAnimator = GetOwner()->GetComponent<Animator>();
		mAttackDelay = min(mAttackDelay + Time::DeltaTime(), 1.0f);
		switch (mState) {
		case ur::CrabScript::eState::Idle:
			idle();
			break;
		case ur::CrabScript::eState::Walk:
			walk();
			break;
		default:
			break;
		}
	}
	void CrabScript::LateUpdate() {
	}
	void CrabScript::Render(HDC hdc) {
	}
	void CrabScript::idle() {
		if (!mTarget)
			return;

		if (mSide != (eSide)(mPos.x < mTargetPos.x)) {
			mSide = (eSide)(mPos.x < mTargetPos.x);
			PlayAnimationWithSide(L"Idle", mAnimator);
		}
		float dist = Vector2::DistanceToward(mPos, mTargetPos);
		if (dist < 200.0f && dist > 56.0f) {
			PlayAnimationWithSide(L"Walk", mAnimator);
			mState = eState::Walk;
		}
		else if (dist <= 56.0f && mAttackDelay == 1.0f) {
			// 공격 상태,애니메이션 들어가야함
			mState = eState::Melee;
			PlayAnimationWithSide(L"Melee", mAnimator);
			return;
		}

	}
	void CrabScript::walk() {
		if (mSide != (eSide)(mPos.x < mTargetPos.x)) {
			mSide = (eSide)(mPos.x < mTargetPos.x);
			PlayAnimationWithSide(L"Walk", mAnimator);
		}
		float dist = Vector2::DistanceToward(mPos, mTargetPos);
		if (!mTarget || dist >= 200.0f || dist <= 56.0f) {
			mState = eState::Idle;
			PlayAnimationWithSide(L"Idle", mAnimator);
			return;
		}
		Vector2 moveDir(0.0f, 0.0f);
		float speed = 75;
		moveDir.x = (UINT)mSide ? 1 : -1;
		moveDir = (moveDir * speed * Time::DeltaTime()) + mPos;
		mTr->SetPos(moveDir);
		
	}
	void CrabScript::melee() {

	}
	void CrabScript::MeleeToIdle() {
		mState = eState::Idle;
		PlayAnimationWithSide(L"Idle", mAnimator);
		mAttackDelay = 0;
	}
}