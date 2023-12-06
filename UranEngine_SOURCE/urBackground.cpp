#include "urBackground.h"
#include "urSpriteRenderer.h"

namespace ur {
	BackGround::BackGround() : GameObject() {
		GameObject::SetTexture(L"BG");
		GameObject::GetComponent<SpriteRenderer>()->SetView(Vector2(2, 2), Vector2(2888, 273));
	}
	BackGround::~BackGround() {
		GameObject::~GameObject();
	}
	void BackGround::Initialize() {
		GameObject::Initialize();
	}
	void BackGround::Update() {
		GameObject::Update();
	}
	void BackGround::LateUpdate() {
		GameObject::LateUpdate();
	}
	void BackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
