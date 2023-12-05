#include "urPlayer.h"
#include "urInput.h"
#include "urTransform.h"
#include "urTime.h"
#include "urSpriteRenderer.h"
#include "..\\UranEngine_Window\\urPlayerScript.h"
#include "urAnimator.h"

namespace ur {
	Player::Player() : GameObject() {
		GameObject::SetAnimation(L"DownWalk", L"Cat", Vector2::ZERO, Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		GameObject::SetAnimation(L"RightWalk", L"Cat", Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		GameObject::SetAnimation(L"UpWalk", L"Cat", Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		GameObject::SetAnimation(L"LeftWalk", L"Cat", Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		GameObject::SetAnimation(L"Idle", L"Cat", Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		GameObject::SetAnimation(L"Grooming", L"Cat", Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		PlayerScript* ps = this->AddComponent<PlayerScript>();
		GameObject::GetComponent<Transform>()->SetOffset(Vector2(16, 16));
		GameObject::GetComponent<Transform>()->SetScale(Vector2::ONE);
		Animator* am = GameObject::GetComponent<Animator>();
		am->PlayAnimation(L"Idle", false);
		// 다른 클래스의 멤버 함수에는 해당 객체의 주소가 암시적으로 넘겨진다.
		// 따라서 다른 곳에서 호출 시 해당 객체를 넘겨줘야 한다.
		am->GetCompleteEvent(L"Grooming") = std::bind(&PlayerScript::CreateCat, ps);
		int a = 0;
		
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
}
