#include "urSceneManager.h"

namespace ur {
	// static ������ �ʱ�ȭ ���ϸ� LNK2001 ������ �߻��Ѵ�.
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

		// iterator�� ������ �ּҸ� �޾ƿ�. �ش� Ű�� ���� ���� ���ٸ� end()�� ��ȯ
		if (iter == mScene.end())
			return nullptr;

		// iterator�� first�� key��, second�� value���� �޾ƿ�
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