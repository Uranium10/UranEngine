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
		GameObject::SetAnimation(L"IdleR", L"Marco_Top", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 7, 0.1f);
		GameObject::SetAnimation(L"RunR", L"Marco_Top_Run", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 12, 0.05f);
		GameObject::SetAnimation(L"IdleL", L"MarcoL_Top", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 7, 0.1f);
		GameObject::SetAnimation(L"RunL", L"MarcoL_Top_Run", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 12, 0.05f);
		GameObject::SetAnimation(L"FPR", L"Marco_Top_FP", Vector2::ZERO, Vector2(128.0f, 64.0f), Vector2(-32.0f,0.0f), 11, 0.025f);
		GameObject::SetAnimation(L"FPL", L"Marco_Top_FP", Vector2(0.0f,64.0f), Vector2(128.0f, 64.0f), Vector2(-32.0f,0.0f), 11, 0.025f);
		GameObject::SetAnimation(L"UpperR", L"Marco_Top_Upper", Vector2(192.0f, 0.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 6, 0.05f);
		GameObject::SetAnimation(L"UpperL", L"Marco_Top_Upper", Vector2(192.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 6, 0.05f);
		GameObject::SetAnimation(L"ToUpperR", L"Marco_Top_Upper", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 2, 0.025f);
		GameObject::SetAnimation(L"ToUpperL", L"Marco_Top_Upper", Vector2(0.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 2, 0.025f);
		GameObject::SetAnimation(L"UpToFrontR", L"Marco_Top_Upper", Vector2(64.0f, 0.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 2, 0.025f);
		GameObject::SetAnimation(L"UpToFrontL", L"Marco_Top_Upper", Vector2(64.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 2, 0.025f);
		GameObject::SetAnimation(L"FPUR", L"Marco_Top_FPUpper", Vector2::ZERO, Vector2(64.0f, 128.0f), Vector2(0.0f, -64.0f), 10, 0.025f);
		GameObject::SetAnimation(L"FPUL", L"Marco_Top_FPUpper", Vector2(0.0f, 128.0f), Vector2(64.0f, 128.0f), Vector2(0.0f, -64.0f), 10, 0.025f);
		PlayerScript* ps = this->AddComponent<PlayerScript>();
		GameObject::GetComponent<Transform>()->SetOffset(Vector2(32.0f, 32.0f));
		GameObject::GetComponent<Transform>()->SetScale(Vector2::ONE);
		Animator* am = GameObject::GetComponent<Animator>();
		am->PlayAnimation(L"IdleR");
		am->GetCompleteEvent(L"FPR") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"FPL") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"UpToFrontR") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"UpToFrontL") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"ToUpperL") = std::bind(&PlayerScript::TopTransitionToUpper, ps);
		am->GetCompleteEvent(L"ToUpperR") = std::bind(&PlayerScript::TopTransitionToUpper, ps);
		am->GetCompleteEvent(L"FPUR") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		am->GetCompleteEvent(L"FPUL") = std::bind(&PlayerScript::TopTransitionToIdle, ps);
		// 다른 클래스의 멤버 함수에는 해당 객체의 주소가 암시적으로 넘겨진다.
		// 따라서 다른 곳에서 호출 시 해당 객체를 넘겨줘야 한다.
		//playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);
		Animator* pa = new Animator(enums::eComponentType::PartAnimator);
		applyAnim(pa, L"IdleR", L"Marco_Leg", 1, 0.1f);
		applyAnim(pa, L"IdleL", L"MarcoL_Leg", 1, 0.1f);
		applyAnim(pa, L"RunR", L"Marco_Leg_Run", 12, 0.05f);
		applyAnim(pa, L"RunL", L"MarcoL_Leg_Run", 12, 0.05f);
		
		pa->PlayAnimation(L"IdleR");
		AddComponentByParam(enums::eComponentType::PartAnimator, pa);
		int a = 1;
		
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
}
