#include "urPlayer.h"
#include "urInput.h"
#include "urTransform.h"
#include "urTime.h"
#include "urSpriteRenderer.h"
#include "..\\UranEngine_Window\\urPlayerScript.h"

namespace ur {
	Player::Player() : GameObject() {
		GameObject::SetTexture(L"Player");
		GameObject::AddComponent<PlayerScript>();
		GameObject::GetComponent<Transform>()->SetOffset(Vector2(250, 100));
		GameObject::GetComponent<SpriteRenderer>()->SetSize(Vector2(2.0f, 1.0f));
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
