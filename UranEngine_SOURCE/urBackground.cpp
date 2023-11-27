#include "urBackground.h"

namespace ur {
	BackGround::BackGround() {
		GameObject::GameObject();
		GameObject::SetTexture(L"BG");
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
