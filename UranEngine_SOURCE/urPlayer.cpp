#include "urPlayer.h"
#include "urInput.h"
#include "urTransform.h"
#include "urTime.h"
#include "urSpriteRenderer.h"
#include "..\\UranEngine_Window\\urPlayerScript.h"
#include "urAnimator.h"
#include "urResources.h"

namespace ur {
	Player::Player() : GameObject() {
		animationInit();
	}
	Player::~Player() {
		GameObject::~GameObject();
	}

	void Player::Initialize() {
	}

	void Player::Update() {
		GameObject::Update();
	}

	void Player::LateUpdate() {
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc) {
		GameObject::Render(hdc);
	}
	void Player::applyAnim(Animator* pa, WST& anim_name, WST& name, UINT frame, float dur) {
		graphics::Texture* texture = Resources::Find<graphics::Texture>(name);
		pa->CreateAnimation(anim_name, texture, Vector2(0.0f, 0.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, frame, dur);
	}
	void Player::animationInit() {
		SetAnimation(L"IdleR", L"Marco_Top", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 7, 0.1f);
		SetAnimation(L"RunR", L"Marco_Top_Run", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 12, 0.05f);
		SetAnimation(L"IdleL", L"MarcoL_Top", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 7, 0.1f);
		SetAnimation(L"RunL", L"MarcoL_Top_Run", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 12, 0.05f);
		SetAnimation(L"FPR", L"Marco_Top_FP", Vector2::ZERO, Vector2(128.0f, 64.0f), Vector2(-32.0f, 0.0f), 11, 0.025f);
		SetAnimation(L"FPL", L"Marco_Top_FP", Vector2(0.0f, 64.0f), Vector2(128.0f, 64.0f), Vector2(-32.0f, 0.0f), 11, 0.025f);
		SetAnimation(L"BPR", L"Marco_Top_BP", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2(0.0f, 0.0f), 6, 0.025f);
		SetAnimation(L"BPL", L"Marco_Top_BP", Vector2(0.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2(0.0f, 0.0f), 6, 0.025f);
		SetAnimation(L"UpperR", L"Marco_Top_Upper", Vector2(192.0f, 0.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 6, 0.05f);
		SetAnimation(L"UpperL", L"Marco_Top_Upper", Vector2(192.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 6, 0.05f);
		SetAnimation(L"ToUpperR", L"Marco_Top_Upper", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 2, 0.025f);
		SetAnimation(L"ToUpperL", L"Marco_Top_Upper", Vector2(0.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 2, 0.025f);
		SetAnimation(L"UpToFrontR", L"Marco_Top_Upper", Vector2(64.0f, 0.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 2, 0.025f);
		SetAnimation(L"UpToFrontL", L"Marco_Top_Upper", Vector2(64.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 2, 0.025f);
		SetAnimation(L"FPUR", L"Marco_Top_FPUpper", Vector2::ZERO, Vector2(64.0f, 128.0f), Vector2(0.0f, -64.0f), 10, 0.025f);
		SetAnimation(L"FPUL", L"Marco_Top_FPUpper", Vector2(0.0f, 128.0f), Vector2(64.0f, 128.0f), Vector2(0.0f, -64.0f), 10, 0.025f);
		SetAnimation(L"ToSitR", L"Marco_To_Sit", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 3, 0.05f);
		SetAnimation(L"ToSitL", L"Marco_To_Sit", Vector2(0.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 3, 0.05f);
		SetAnimation(L"SitToStandR", L"Marco_To_Sit", Vector2(128.0f, 0.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 3, 0.05f);
		SetAnimation(L"SitToStandL", L"Marco_To_Sit", Vector2(128.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 3, 0.05f);
		SetAnimation(L"SitR", L"Marco_Sit", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 6, 0.1f);
		SetAnimation(L"SitL", L"Marco_Sit", Vector2(0.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 6, 0.1f);
		SetAnimation(L"SitWalkR", L"Marco_Sit_Walk", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 7, 0.05f);
		SetAnimation(L"SitWalkL", L"Marco_Sit_Walk", Vector2(0.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 7, 0.05f);
		SetAnimation(L"SitFPR", L"Marco_FPSit", Vector2::ZERO, Vector2(128.0f, 64.0f), Vector2(-32.0f, 0.0f), 7, 0.05f);
		SetAnimation(L"SitFPL", L"Marco_FPSit", Vector2(0.0f, 64.0f), Vector2(128.0f, 64.0f), Vector2(-32.0f, -0.0f), 7, 0.05f);
		SetAnimation(L"SitBPR", L"Marco_BPSit", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2(0.0f, 0.0f), 6, 0.025f);
		SetAnimation(L"SitBPL", L"Marco_BPSit", Vector2(0.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2(0.0f, -0.0f), 6, 0.025f);
		
		Animator* pa = new Animator(enums::eComponentType::PartAnimator);
		applyAnim(pa, L"IdleR", L"Marco_Leg", 1, 0.1f);
		applyAnim(pa, L"IdleL", L"MarcoL_Leg", 1, 0.1f);
		applyAnim(pa, L"RunR", L"Marco_Leg_Run", 12, 0.05f);
		applyAnim(pa, L"RunL", L"MarcoL_Leg_Run", 12, 0.05f);
		applyAnim(pa, L"null", L" ", 12, 10.0f);
		pa->PlayAnimation(L"IdleR");
		AddComponentByParam(enums::eComponentType::PartAnimator, pa);

		animationEventInit();
	}
	void Player::animationEventInit() {
		// 다른 클래스의 멤버 함수에는 해당 객체의 주소가 암시적으로 넘겨진다.
		// 따라서 다른 곳에서 호출 시 해당 객체를 넘겨줘야 한다.
		//playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);
		PlayerScript* ps = this->AddComponent<PlayerScript>();
		GetComponent<Transform>()->SetOffset(Vector2(32.0f, 32.0f));
		GetComponent<Transform>()->SetScale(Vector2::ONE);
		Animator* am = GameObject::GetComponent<Animator>();
		am->PlayAnimation(L"IdleR");
		am->GetCompleteEvent(L"FPR") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"FPL") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"BPR") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"BPL") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"UpToFrontR") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"UpToFrontL") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"ToUpperL") = std::bind(&PlayerScript::TopTransitionToUpper, ps);
		am->GetCompleteEvent(L"ToUpperR") = std::bind(&PlayerScript::TopTransitionToUpper, ps);
		am->GetCompleteEvent(L"FPUR") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"FPUL") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"ToSitR") = std::bind(&PlayerScript::TransitionToSit, ps);
		am->GetCompleteEvent(L"ToSitL") = std::bind(&PlayerScript::TransitionToSit, ps);
		am->GetCompleteEvent(L"SitToStandR") = std::bind(&PlayerScript::TransitionFromSit, ps);
		am->GetCompleteEvent(L"SitToStandL") = std::bind(&PlayerScript::TransitionFromSit, ps);
		am->GetCompleteEvent(L"SitFPR") = std::bind(&PlayerScript::TransitionFromSitFire, ps);
		am->GetCompleteEvent(L"SitFPL") = std::bind(&PlayerScript::TransitionFromSitFire, ps);
		am->GetCompleteEvent(L"SitBPR") = std::bind(&PlayerScript::TransitionFromSitFire, ps);
		am->GetCompleteEvent(L"SitBPL") = std::bind(&PlayerScript::TransitionFromSitFire, ps);
	}
}
