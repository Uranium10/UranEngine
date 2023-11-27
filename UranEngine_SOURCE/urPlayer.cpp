#include "urPlayer.h"
#include "urInput.h"
#include "urTransform.h"
#include "urTime.h"

namespace ur {
	Player::Player() : GameObject(), speed(250.0f) {
		GameObject::SetTexture(L"Player");
	}
	Player::~Player() {
		GameObject::~GameObject();
	}

	void Player::Initialize() {
	}

	void Player::Update() {
		GameObject::Update();
		Transform* tr = GetComponent<Transform>();
		Vector2 d;
		float delta = speed * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::Left))
			d += Vector2::LEFT;
		if (Input::GetKey(eKeyCode::Right))
			d += Vector2::RIGHT;
		if (Input::GetKey(eKeyCode::Up))
			d += Vector2::UP;
		if (Input::GetKey(eKeyCode::Down))
			d += Vector2::DOWN;
		d *= delta;
		tr->SetPos(tr->GetPos() + d);
	}

	void Player::LateUpdate() {
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc) {
		GameObject::Render(hdc);
	}
}
