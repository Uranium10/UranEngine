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
		// �ٸ� Ŭ������ ��� �Լ����� �ش� ��ü�� �ּҰ� �Ͻ������� �Ѱ�����.
		// ���� �ٸ� ������ ȣ�� �� �ش� ��ü�� �Ѱ���� �Ѵ�.
		am->GetCompleteEvent(L"Grooming") = std::bind(&PlayerScript::CreateCat, ps);
		Animator* pa = new Animator(enums::eComponentType::PartAnimator);
		graphics::Texture* texture = Resources::Find<graphics::Texture>(L"Ml");
		pa->CreateAnimation(L"Idle", texture, Vector2(0.0f, 0.0f), Vector2(64.0f, 64.0f), Vector2::DOWN * 100, 1, 0.1f);
		graphics::Texture* texture2 = Resources::Find<graphics::Texture>(L"Mlr");
		pa->CreateAnimation(L"Run", texture2, Vector2(0.0f, 0.0f), Vector2(64.0f, 64.0f), Vector2::DOWN * 100, 12, 0.05f);
		pa->PlayAnimation(L"Idle");
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
}
