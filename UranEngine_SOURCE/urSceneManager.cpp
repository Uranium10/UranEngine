#include "urSceneManager.h"

namespace ur {
	// static 변수를 초기화 안하면 LNK2001 에러가 발생한다.
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize() {

	}
	void SceneManager::Update() {
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate() {
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc) {
		mActiveScene->Render(hdc);
	}
}