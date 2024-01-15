#include "urStage1_1.h"
#include "urSpriteRenderer.h"

namespace ur {
	Stage1_1::Stage1_1() {
		GameObject::SetTexture(L"BG");

		SpriteRenderer* sr = GameObject::GetComponent<SpriteRenderer>();
		sr->SetView(Vector2(1, 1197), Vector2(1607, 221));
	}
	Stage1_1::~Stage1_1() {
		GameObject::~GameObject();
	}
	void Stage1_1::Initialize() {
		GameObject::Initialize();
	}
	void Stage1_1::Update() {
		GameObject::Update();
	}
	void Stage1_1::LateUpdate() {
		GameObject::LateUpdate();
	}
	void Stage1_1::Render(HDC hdc) {
		GameObject::Render(hdc);
	}
}