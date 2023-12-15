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
		, mSide(1)
		, mTransform(nullptr)
		, mLook(eLook::Front)
		, mbMove(false)
		, mbFire(false)
		, mWeapon(eWeapon::Pistol) { }
	PlayerScript::~PlayerScript() { }

	void PlayerScript::Initialize() { }
	void PlayerScript::Update() {
		mAnimator = GetOwner()->GetComponent<Animator>();
		mPart = GetOwner()->GetComponentByType<Animator>(enums::eComponentType::PartAnimator);
		mTransform = GetOwner()->GetComponent<Transform>();
		if (!mAnimator)
			return;
		behaviorsForUpdate();

		keyCheckForUpdate();
		
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
	void PlayerScript::behaviorsForUpdate() {
		switch (mState) {
		case ur::PlayerScript::eState::Idle: Idle(); break;
		case ur::PlayerScript::eState::Run: move(); break;
		case ur::PlayerScript::eState::Sit: sit(); break;
		case ur::PlayerScript::eState::SitWalk: sitWalk(); break;
		case ur::PlayerScript::eState::Jump: jump(); break;
		case ur::PlayerScript::eState::Transition: break;
		case ur::PlayerScript::eState::TransToSit: transToSit(); break;
		case ur::PlayerScript::eState::TransToStand: transToStand(); break;
		default: break;
		}
	}
	void PlayerScript::keyCheckForUpdate() {
		if (Input::GetKey(eKeyCode::Up))
			pressUpKey();
		if (Input::GetKeyUp(eKeyCode::Up))
			releaseUpKey();
		if (Input::GetKey(eKeyCode::Down))
			pressDownKey();
		if (!Input::GetKey(eKeyCode::Down))
			releaseDownKey();
		if (Input::GetKeyDown(eKeyCode::A))
			playAttackAnimation();
		if (Input::GetKeyDown(eKeyCode::D))
			playBombAnimation();
	}
	void PlayerScript::Idle() {
		if (Input::GetKey(eKeyCode::Left)) {
			if (mSide == 1)
				mbFire = false;
			if (!mbFire) {
				if (mLook == eLook::Front)
					mAnimator->PlayAnimation(L"RunL");
				if (mSide == 1 && mLook == eLook::Upper)
					mAnimator->PlayAnimation(L"UpperL");
			}
			mPart->PlayAnimation(L"RunL");
			mSide = 0;
			mState = eState::Run;
		}
		if (Input::GetKey(eKeyCode::Right)) {
			if (mSide == 0)
				mbFire = false;
			if (!mbFire) {
				if (mLook == eLook::Front)
					mAnimator->PlayAnimation(L"RunR");
				if (mSide == 0 && mLook == eLook::Upper)
					mAnimator->PlayAnimation(L"UpperR");
			}
			mPart->PlayAnimation(L"RunR");
			mSide = 1;
			mState = eState::Run;
		}
		/*
		if (Input::GetKeyDown(eKeyCode::LButton)) {
			Vector2 vect = Input::GetMousePosition() - Vector2{ 800, 450 };
			object::Instantiate<Cat>(enums::eLayerType::Animal, vect);
		}*/
		
	}
	void PlayerScript::move() {
		float delta = 100.0f * Time::DeltaTime();
		Vector2 d = Input::GetVector() * delta;
		d = Vector2::VectorOfX(d) + mTransform->GetPos();
		d.x = max(16, d.x);
		mTransform->SetPos(d);
		if (Input::GetKeyUp(eKeyCode::Left)) {
			//mAnimator->PlayAnimation(wcscat(const_cast<wchar_t>(L"Idle"), SIDES[mSide]));
			if (mLook == eLook::Front)
				mAnimator->PlayAnimation(L"IdleL");
			mPart->PlayAnimation(L"IdleL");
			moveToIdle();
		}
		else if (Input::GetKeyUp(eKeyCode::Right)) {
			if (mLook == eLook::Front)
				mAnimator->PlayAnimation(L"IdleR");
			mPart->PlayAnimation(L"IdleR");
			moveToIdle();
		}
	}
	void PlayerScript::sit() {
		Vector2 d = Input::GetVector();
		if (Vector2::VectorOfX(d) != Vector2::ZERO) {
			if (!mbFire || Input::GetKeyDown(eKeyCode::A)) {
				mSide = d.x == 1;
				playAnimationWithSide(L"SitWalk", mAnimator);
				mState = eState::SitWalk;
			}
		}
		/*if (!Input::GetKey(eKeyCode::Down)) {
			mbFire = false;
			releaseDownKey();
		}*/
	}
	void PlayerScript::sitWalk() {
		float delta = 50.0f * Time::DeltaTime();
		Vector2 d = Input::GetVector() * delta;
		d = Vector2::VectorOfX(d);
		if (d == Vector2::ZERO) {
			playAnimationWithSide(L"Sit", mAnimator);
			mState = eState::Sit;
		}
		d += mTransform->GetPos();
		d.x = max(16, d.x);
		mTransform->SetPos(d);
		/*if (Input::GetKeyUp(eKeyCode::Down) && !mbFire)
			mState = eState::Sit;*/
		/*if (!Input::GetKey(eKeyCode::Down)) {
			mbFire = false;
			releaseDownKey();
		}*/
	}
	void PlayerScript::transToSit() {
	}
	void PlayerScript::transToStand() {
	}
	void PlayerScript::moveToIdle() {
		mState = eState::Idle;
		Vector2 x = Input::GetVector();
		if (Vector2::VectorOfX(x) != Vector2::ZERO)
			Idle();
	}
	void PlayerScript::jump() {

	}


	void PlayerScript::frontTransitionAnimToIdle() {
		std::wstring animIndex = L"";
		switch (mState) {
		case ur::PlayerScript::eState::Idle:
			animIndex.append(L"Idle");
			break;
		case ur::PlayerScript::eState::Run:
			animIndex.append(L"Run");
			break;
		default:
			animIndex.append(L"Run");
			break;
		}
		animIndex.append(SIDES[mSide]);
		mAnimator->PlayAnimation(animIndex.c_str(), mPart->GetIndex());
	}

	void PlayerScript::TransitionToSit() {
		playAnimationWithSide(L"Sit", mAnimator);
		mState = eState::Sit;
	}

	void PlayerScript::TransitionFromSit(){
		mState = eState::Idle;
		playAnimationWithSide(L"Idle", mAnimator);
		playAnimationWithSide(L"Idle", mPart, false);
	}

	void PlayerScript::TransitionFromSitFire() {
		mState = eState::Sit;
		playAnimationWithSide(L"Sit", mAnimator);
		mbFire = false;
	}

	void PlayerScript::playAnimationWithSide(WST& anim, Animator* am, bool loop) {
		std::wstring animIndex(anim);
		animIndex.append(SIDES[mSide]);
		am->PlayAnimation(animIndex, loop);
	}

	void PlayerScript::playAttackAnimation() {
		switch (mState) {
		case ur::PlayerScript::eState::TransToStand:
			playAnimationWithSide(L"Idle", mPart, false);
			mState = eState::Idle;
		case ur::PlayerScript::eState::Idle:
		case ur::PlayerScript::eState::Run:
			if (mLook == eLook::Front)
				playAnimationWithSide(L"FP", mAnimator, false);
			else if (mLook == eLook::Upper)
				playAnimationWithSide(L"FPU", mAnimator, false);
			mbFire = true;
			break;
		case ur::PlayerScript::eState::SitWalk:
		case ur::PlayerScript::eState::TransToSit:
			mbFire = true;
			mState = eState::Sit;
		case ur::PlayerScript::eState::Sit:
			playAnimationWithSide(L"SitFP", mAnimator, false);
			break;
		case ur::PlayerScript::eState::Jump:
			break;
		case ur::PlayerScript::eState::Transition:
			break;
		default:
			break;
		}
	}

	void PlayerScript::playBombAnimation() {
		switch (mState) {

		case ur::PlayerScript::eState::TransToStand:
			playAnimationWithSide(L"Idle", mPart, false);
			mState = eState::Idle;
		case ur::PlayerScript::eState::Idle:
			playAnimationWithSide(L"BP", mAnimator, false);
			return;
		case ur::PlayerScript::eState::Run:
			playAnimationWithSide(L"BP", mAnimator, false);
			mbFire = true;
			break;
		case ur::PlayerScript::eState::SitWalk:
		case ur::PlayerScript::eState::TransToSit:
			mbFire = true;
			mState = eState::Sit;
		case ur::PlayerScript::eState::Sit:
			playAnimationWithSide(L"SitBP", mAnimator, false);
			break;
		case ur::PlayerScript::eState::Jump:
			break;
		case ur::PlayerScript::eState::Transition:
			break;
		default:
			break;
		}
	}

	void PlayerScript::pressUpKey() {
		switch (mState) {
		case ur::PlayerScript::eState::Idle:
		case ur::PlayerScript::eState::Run:
			if (mLook != eLook::Upper) {
				mLook = eLook::Upper;
				playAnimationWithSide(L"ToUpper", mAnimator, false);
			}
			break;
		case ur::PlayerScript::eState::Sit:
			break;
		case ur::PlayerScript::eState::Jump:
			break;
		case ur::PlayerScript::eState::Transition:
			break;
		default:
			break;
		}
	}

	void PlayerScript::releaseUpKey() {
		switch (mState) {
		case ur::PlayerScript::eState::Idle:
		case ur::PlayerScript::eState::Run:
			mLook = eLook::Front;
			playAnimationWithSide(L"UpToFront", mAnimator, false);
			break;
		case ur::PlayerScript::eState::Sit:
			break;
		case ur::PlayerScript::eState::Jump:
			break;
		case ur::PlayerScript::eState::Transition:
			break;
		default:
			break;
		}
	}

	void PlayerScript::pressDownKey() {
		switch (mState) {
		case ur::PlayerScript::eState::Idle:
		case ur::PlayerScript::eState::Run:
			mLook = eLook::Front;
			mState = eState::TransToSit;
			playAnimationWithSide(L"ToSit", mAnimator, false);
			mPart->PlayAnimation(L"null", false);
			break;
		case ur::PlayerScript::eState::Sit:
			break;
		case ur::PlayerScript::eState::Jump:
			break;
		case ur::PlayerScript::eState::Transition:
			break;
		default:
			break;
		}
		
	}

	void PlayerScript::releaseDownKey() {
		switch (mState) {
		case ur::PlayerScript::eState::Idle:
		case ur::PlayerScript::eState::Run:
			break;
		case ur::PlayerScript::eState::Sit:
		case ur::PlayerScript::eState::SitWalk:
			mState = eState::TransToStand;
			mLook = eLook::Front;
			playAnimationWithSide(L"SitToStand", mAnimator, false);
			break;
		case ur::PlayerScript::eState::Jump:
			break;
		case ur::PlayerScript::eState::Transition:
			break;
		default:
			break;
		}

	}

	void PlayerScript::TopTransitionToIdle() {
		switch (mState) {
		case ur::PlayerScript::eState::Idle:
		case ur::PlayerScript::eState::Run:
			if (mLook == eLook::Front)
				frontTransitionAnimToIdle();
			else if (mLook == eLook::Upper)
				TopTransitionToUpper();
			break;
		case ur::PlayerScript::eState::Sit:
			break;
		case ur::PlayerScript::eState::Jump:
			break;
		case ur::PlayerScript::eState::Transition:
			break;
		default:
			break;
		}
		mbFire = false;
	}

	void PlayerScript::TopTransitionToUpper() {
		playAnimationWithSide(L"Upper", mAnimator);
	}
}