#include "urCatScript.h"
#include "GameObject.h"
#include "urAnimator.h"
#include "urTransform.h"

namespace ur {
	CatScript::CatScript() : Script(), mState(eState::Idle), mAnimator(nullptr), mTime(0.0f) {}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{
	}
	void CatScript::Update() {
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<Animator>();
		switch (mState)
		{
		case ur::CatScript::eState::Idle:
			Idle();
			break;
		case ur::CatScript::eState::Walk:
			move();
			break;
		case ur::CatScript::eState::Sleep:
			break;
		case ur::CatScript::eState::Attack:
			break;
		default:
			break;
		}

	}
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}
	void CatScript::Idle() {
		mTime += Time::DeltaTime();
		if (mTime > 3.0f) {
			mState = CatScript::eState::Walk;
			int direction = rand() % 4;
			mDirection = (eDirection)direction;
			PlayWalkAnimationByDirection(mDirection);
			mTime = 0.0f;
		}
	}
	void CatScript::move() {
		mTime += Time::DeltaTime();
		if (mTime > 3.0f) {
			mState = CatScript::eState::Idle;
			mTime = 0.0f;
			mAnimator->PlayAnimation(L"Idle", false);
			return;
		}
		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);
	}
	void CatScript::translate(Transform* tr) {
		float delta = 100.0f * Time::DeltaTime();
		Vector2 d = { 0,0 };
		switch (mDirection) {
		case ur::CatScript::eDirection::Left:
			d.x = -1;
			break;
		case ur::CatScript::eDirection::Right:
			d.x = 1;
			break;
		case ur::CatScript::eDirection::Up:
			d.y = -1;
			break;
		case ur::CatScript::eDirection::Down:
			d.y = 1;
			break;
		case ur::CatScript::eDirection::End:
			break;
		default:
			break;
		}
		tr->SetPos(tr->GetPos() + (d * delta));
	}
	void CatScript::PlayWalkAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case ur::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk");
			break;
		case ur::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk");
			break;
		case ur::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk");
			break;
		case ur::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk");
			break;
		default:
			break;
		}
	}
}