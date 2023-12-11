#include "urPlayerScript.h"
#include "urInput.h"
#include "urTransform.h"
#include "urTime.h"
#include "GameObject.h"
#include "urPlayer.h"
#include "urAnimator.h"
#include "urCat.h"
#include "urObject.h"

namespace ur {
	const wchar_t* SIDES[2] = { L"L", L"R" };
	PlayerScript::PlayerScript() 
		: Script()
		, mState(eState::Idle)
		, mAnimator(nullptr)
		, mPart(nullptr)
		, atkDelay(0)
		, mSide(0)
		, mTransform(nullptr)
		, mLook(eLook::Front) { }
	PlayerScript::~PlayerScript() { }
	void PlayerScript::Initialize() { }
	void PlayerScript::Update() {
		mAnimator = GetOwner()->GetComponent<Animator>();
		mPart = GetOwner()->GetComponentByType<Animator>(enums::eComponentType::PartAnimator);
		mTransform = GetOwner()->GetComponent<Transform>();
		if (!mAnimator)
			return;
		switch (mState)
		{
		case ur::PlayerScript::eState::Idle:
			Idle();
			break;
		case ur::PlayerScript::eState::Walk:
			move();
			break;
		case ur::PlayerScript::eState::Transition:
			transition();
			break;
		case ur::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}
		std::wstring animIndex(L"");
		if (Input::GetKeyDown(eKeyCode::A)) {
			playAttackAnimation();
		}
		if (Input::GetKeyDown(eKeyCode::Up)) {
			mLook = eLook::Upper;
			animIndex.append(L"ToUpper");
			animIndex.append(SIDES[mSide]);
			mAnimator->PlayAnimation(animIndex, false);
		}
		if (Input::GetKeyUp(eKeyCode::Up)) {
			mLook = eLook::Front;
			animIndex.append(L"UpToFront");
			animIndex.append(SIDES[mSide]);
			mAnimator->PlayAnimation(animIndex, false);
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::CreateCat() {
		object::Instantiate<Cat>(enums::eLayerType::Animal, mTransform->GetPos());
	}
	void PlayerScript::Idle() {
		if (Input::GetKey(eKeyCode::Left)) {
			mAnimator->PlayAnimation(L"RunL");
			mPart->PlayAnimation(L"RunL");
			mSide = 0;
			mState = eState::Walk;
		}
		if (Input::GetKey(eKeyCode::Right)) {
			mAnimator->PlayAnimation(L"RunR");
			mPart->PlayAnimation(L"RunR");
			mSide = 1;
			mState = eState::Walk;
		}
		if (Input::GetKeyDown(eKeyCode::LButton)) {
			Vector2 vect = Input::GetMousePosition() - Vector2{ 800, 450 };
			object::Instantiate<Cat>(enums::eLayerType::Animal, vect);
		}
	}
	void PlayerScript::move() {
		float delta = 100.0f * Time::DeltaTime();
		Vector2 d = Input::GetVector() * delta;
		d = Vector2::VectorOfX(d);
		mTransform->SetPos(Vector2(d + mTransform->GetPos()));
		if (Input::GetKeyUp(eKeyCode::Left)) {
			//mAnimator->PlayAnimation(wcscat(const_cast<wchar_t>(L"Idle"), SIDES[mSide]));
			mAnimator->PlayAnimation(L"IdleL");
			mPart->PlayAnimation(L"IdleL");
			transition();
		}
		else if (Input::GetKeyUp(eKeyCode::Right)) {
			mAnimator->PlayAnimation(L"IdleR");
			mPart->PlayAnimation(L"IdleR");
			transition();
		}
	}
	void PlayerScript::transition() {
		mState = eState::Idle;
		if (Input::GetVector() != Vector2::ZERO)
			Idle();
	}

	void PlayerScript::frontTransitionAnimToIdle() {
		std::wstring animIndex = L"";
		switch (mState)
		{
		case ur::PlayerScript::eState::Idle:
			animIndex.append(L"Idle");
			break;
		case ur::PlayerScript::eState::Walk:
			animIndex.append(L"Run");
			break;
		default:
			animIndex.append(L"Run");
			break;
		}
		animIndex.append(SIDES[mSide]);
		mAnimator->PlayAnimation(animIndex.c_str(), mPart->GetIndex());
	}

	void PlayerScript::playAttackAnimation(){
		std::wstring animIndex(L"");
		if (mLook == eLook::Front)
			animIndex.append(L"FP");
		else if (mLook == eLook::Upper)
			animIndex.append(L"FPU");
		animIndex.append(SIDES[mSide]);
		mAnimator->PlayAnimation(animIndex.c_str(), false);
	}

	void PlayerScript::TopTransitionToIdle() {
		
		if (mLook == eLook::Front)
			frontTransitionAnimToIdle();
		else if (mLook == eLook::Upper)
			TopTransitionToUpper();
	}

	void PlayerScript::TopTransitionToUpper() {
		std::wstring animIndex = L"Upper";
		animIndex.append(SIDES[mSide]);
		mAnimator->PlayAnimation(animIndex);
	}
}