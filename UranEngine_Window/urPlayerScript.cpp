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
	PlayerScript::PlayerScript() :Script(), mState(eState::Idle), mAnimator(nullptr), mPart(nullptr) {
	}
	PlayerScript::~PlayerScript() { }
	void PlayerScript::Initialize() { }
	void PlayerScript::Update() {
		mAnimator = GetOwner()->GetComponent<Animator>();
		mPart = GetOwner()->GetComponentByType<Animator>(enums::eComponentType::PartAnimator);
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


	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::CreateCat() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		object::Instantiate<Cat>(enums::eLayerType::Animal, tr->GetPos());
	}
	void PlayerScript::Idle() {
		if (Input::GetKey(eKeyCode::Left)) {
			mAnimator->PlayAnimation(L"RunL");
			mPart->PlayAnimation(L"RunL");
			mState = eState::Walk;
		}
		if (Input::GetKey(eKeyCode::Right)) {
			mAnimator->PlayAnimation(L"RunR");
			mPart->PlayAnimation(L"RunR");
			mState = eState::Walk;
		}
		if (Input::GetKeyDown(eKeyCode::LButton)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 vect = Input::GetMousePosition() - Vector2{ 800, 450 };
			object::Instantiate<Cat>(enums::eLayerType::Animal, vect);
		}
	}
	void PlayerScript::move() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		float delta = 100.0f * Time::DeltaTime();
		Vector2 d = Input::GetVector() * delta;
		tr->SetPos(tr->GetPos() + d);
		if (Input::GetKeyUp(eKeyCode::Left)) {
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
}