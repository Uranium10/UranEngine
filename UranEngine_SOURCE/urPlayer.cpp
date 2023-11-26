#include "urPlayer.h"
#include "urInput.h"
#include "urTransform.h"
#include "urTime.h"

namespace ur {
	Player::Player() : speed(250.0f) {
		GameObject::GameObject();
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
			d += math::LEFT;
		if (Input::GetKey(eKeyCode::Right))
			d += math::RIGHT;
		if (Input::GetKey(eKeyCode::Up))
			d += math::UP;
		if (Input::GetKey(eKeyCode::Down))
			d += math::DOWN;
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
