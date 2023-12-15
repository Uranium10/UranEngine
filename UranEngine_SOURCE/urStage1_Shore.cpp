#include "urStage1_Shore.h"
#include "urAnimator.h"

namespace ur {
	Stage1_Shore::Stage1_Shore() : GameObject(){
		SetAnimation(L"Idle", L"Stage1_Shore", Vector2::ZERO, Vector2(563.0f, 64.0f), Vector2::ZERO, 8, 0.25f);
		Animator* am = GetComponentByType<Animator>(enums::eComponentType::Animator);
		am->PlayAnimation(L"Idle");

	}
	Stage1_Shore::~Stage1_Shore() {
		GameObject::~GameObject();
	}
	void Stage1_Shore::Initialize() {
		GameObject::Initialize();
	}
	void Stage1_Shore::Update() {
		GameObject::Update();
	}
	void Stage1_Shore::LateUpdate() {
		GameObject::LateUpdate();
	}
	void Stage1_Shore::Render(HDC hdc) {
		GameObject::Render(hdc);
	}
}