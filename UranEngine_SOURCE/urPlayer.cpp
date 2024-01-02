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
		PlayerScript* ps = this->AddComponent<PlayerScript>();
		GameObject::GetComponent<Transform>()->SetOffset(Vector2(32.0f, 32.0f));
		GameObject::GetComponent<Transform>()->SetScale(Vector2::ONE);
		Animator* am = GameObject::GetComponent<Animator>();
		am->PlayAnimation(L"IdleR");
		// 다른 클래스의 멤버 함수에는 해당 객체의 주소가 암시적으로 넘겨진다.
		// 따라서 다른 곳에서 호출 시 해당 객체를 넘겨줘야 한다.
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
