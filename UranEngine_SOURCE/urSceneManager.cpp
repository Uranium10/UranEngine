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
	Scene* SceneManager::LoadScene(const std::wstring& name) {
		if (mActiveScene)
			mActiveScene->OnExit();
		//std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);
		auto iter = mScene.find(name);

		// iterator는 포인터 주소를 받아옴. 해당 키에 대한 값이 없다면 end()를 반환
		if (iter == mScene.end())
			return nullptr;

		// iterator의 first는 key값, second는 value값을 받아옴
		mActiveScene = iter->second;
		mActiveScene->OnEnter();
		return iter->second;
	}
	void SceneManager::Release() {
		for (auto iter : mScene) {
			delete iter.second;
			iter.second = nullptr;
		}
	}
}