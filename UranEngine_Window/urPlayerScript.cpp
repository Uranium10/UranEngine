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
	PlayerScript::~PlayerScript(){ }
	void PlayerScript::Initialize(){ }
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
		case ur::PlayerScript::eState::Sleep:
			grooming();
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
			mAnimator->PlayAnimation(L"LeftWalk");
			mPart->PlayAnimation(L"Run");
			mState = eState::Walk;
		}
		if (Input::GetKey(eKeyCode::Right)) {
			mAnimator->PlayAnimation(L"RightWalk");
			mPart->PlayAnimation(L"Run");
			mState = eState::Walk;
		}
		if (Input::GetKey(eKeyCode::Up)) {
			mAnimator->PlayAnimation(L"UpWalk");
			mPart->PlayAnimation(L"Run");
			mState = eState::Walk;
		}
		if (Input::GetKey(eKeyCode::Down)) {
			mAnimator->PlayAnimation(L"DownWalk");
			mPart->PlayAnimation(L"Run");
			mState = eState::Walk;
		}
		if (Input::GetKey(eKeyCode::Space)) {
			mAnimator->PlayAnimation(L"Grooming", false);
			mState = eState::Sleep;
		}
		if (Input::GetKeyDown(eKeyCode::LButton)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 vect = Input::GetMousePosition() - Vector2{800, 450};
			object::Instantiate<Cat>(enums::eLayerType::Animal, vect);
		}
	}
	void PlayerScript::move() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		float delta = 100.0f * Time::DeltaTime();
		Vector2 d = Input::GetVector() * delta;
		tr->SetPos(tr->GetPos() + d);
		if (Input::GetKeyUp(eKeyCode::Down) 
			|| Input::GetKeyUp(eKeyCode::Up)
			|| Input::GetKeyUp(eKeyCode::Left)
			|| Input::GetKeyUp(eKeyCode::Right)) {
			mState = eState::Transition;
		}
	}
	void PlayerScript::transition() {
		mState = eState::Idle;
		if (Input::GetVector() == Vector2::ZERO) {
			mAnimator->PlayAnimation(L"Idle", false);

			mPart->PlayAnimation(L"Idle");
		}
		else
			Idle();
	}
	void PlayerScript::grooming() {
		if (mAnimator->IsCompleteAnimation()) {
			mAnimator->PlayAnimation(L"Idle", false);
			mPart->PlayAnimation(L"Idle");
			mState = eState::Idle;
		}
	}
}