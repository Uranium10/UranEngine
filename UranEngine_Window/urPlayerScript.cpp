#include "urPlayerScript.h"
#include "urInput.h"
#include "urTransform.h"
#include "urTime.h"
#include "GameObject.h"

namespace ur {
	PlayerScript::PlayerScript() :Script() {
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 d;
		float delta = 250.0f * Time::DeltaTime();
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
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}