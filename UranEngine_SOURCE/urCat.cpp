#include "urCat.h"
#include "urAnimator.h"
#include "..\\UranEngine_Window\\urCatScript.h"

namespace ur {
	Cat::Cat() : GameObject() {
		GameObject::SetAnimation(L"DownWalk", L"Cat", Vector2::ZERO, Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		GameObject::SetAnimation(L"RightWalk", L"Cat", Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		GameObject::SetAnimation(L"UpWalk", L"Cat", Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		GameObject::SetAnimation(L"LeftWalk", L"Cat", Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		GameObject::SetAnimation(L"Idle", L"Cat", Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		GameObject::SetAnimation(L"Grooming", L"Cat", Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::ZERO, 4, 0.1f);
		GameObject::AddComponent<CatScript>();
		GameObject::GetComponent<Transform>()->SetOffset(Vector2(16, 16));
		GameObject::GetComponent<Transform>()->SetScale(Vector2::ONE);
		GameObject::GetComponent<Animator>()->PlayAnimation(L"Idle", false);
	}
	Cat::~Cat() {
		GameObject::~GameObject();
	}
	void Cat::Initialize() {}
	void Cat::Update() {
		GameObject::Update();
	}
	void Cat::LateUpdate() {
		GameObject::LateUpdate();
	}
	void Cat::Render(HDC hdc) {
		GameObject::Render(hdc);
	}
}