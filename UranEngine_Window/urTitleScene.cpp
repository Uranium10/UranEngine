#include "urTitleScene.h"
#include "urInput.h"
#include "urSceneManager.h"

namespace ur {
	TitleScene::TitleScene() {
	}
	TitleScene::~TitleScene() {
	}
	void TitleScene::Initialize() {
	}
	void TitleScene::Update() {
		Scene::Update();
	}
	void TitleScene::LateUpdate() {
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
			SceneManager::LoadScene(L"PlayScene");
	}
	void TitleScene::Render(HDC hdc) {
		Scene::Render(hdc);
		wchar_t str[50] = L"Title scene";
		TextOut(hdc, 0, 0, str, lstrlenW(str));
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}