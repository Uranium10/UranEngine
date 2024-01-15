#include "urCrab.h"
#include "urAnimator.h"
#include "..\\UranEngine_Window\urCrabScript.h"

namespace ur {
	Crab::Crab() : GameObject() {
		SetName(L"Crab");
		GameObject::SetAnimation(L"IdleL", L"Crab_Idle", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 7, 0.1f);
		GameObject::SetAnimation(L"IdleR", L"Crab_Idle", Vector2(0.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 7, 0.1f);
		GameObject::SetAnimation(L"WalkL", L"Crab_Walk", Vector2::ZERO, Vector2(64.0f, 64.0f), Vector2::ZERO, 7, 0.05f);
		GameObject::SetAnimation(L"WalkR", L"Crab_Walk", Vector2(0.0f, 64.0f), Vector2(64.0f, 64.0f), Vector2::ZERO, 7, 0.05f);
		GameObject::SetAnimation(L"MeleeL", L"Crab_Melee", Vector2::ZERO, Vector2(128.0f, 128.0f), Vector2(-32.0f, -32.0f), 13, 0.05f);
		GameObject::SetAnimation(L"MeleeR", L"Crab_Melee", Vector2(0.0f, 128.0f), Vector2(128.0f, 128.0f), Vector2(-32.0f, -32.0f), 13, 0.05f);
		CrabScript* cs = GameObject::AddComponent<CrabScript>();
		GameObject::GetComponent<Transform>()->SetOffset(Vector2(32, 32));
		Animator* am = GameObject::GetComponent<Animator>();
		am->PlayAnimation(L"IdleL");
		am->GetCompleteEvent(L"MeleeL") = std::bind(&CrabScript::MeleeToIdle, cs);
		am->GetCompleteEvent(L"MeleeR") = std::bind(&CrabScript::MeleeToIdle, cs);
	}
	Crab::~Crab() {
		GameObject::~GameObject();
	}
	void Crab::Initialize() {
		GameObject::Initialize();
	}
	void Crab::Update() {
		GameObject::Update();
	}
	void Crab::LateUpdate() {
		GameObject::LateUpdate();
	}
	void Crab::Render(HDC hdc) {
		GameObject::Render(hdc);
	}
	void Crab::SetTarget(GameObject* target) {
		mTarget = target;
		CrabScript* sc = dynamic_cast<CrabScript*>(GetComponent<Script>());
		if (sc)
			sc->SetTarget(target);
	}
}