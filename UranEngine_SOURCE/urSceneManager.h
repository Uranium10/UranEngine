#pragma once
#include"commonInclude.h"
#include "urScene.h"

namespace ur {
	class SceneManager {
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			// Ʈ���� �� ����
			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		// ������ ��ȯ�� �ϴ� ���� : Ȯ�强 ���(�ش� ���� �޾Ƽ� ����� ��찡 ���� �� ����)
		static Scene* LoadScene(const std::wstring& name) {
			if (mActiveScene)
				mActiveScene->OnExit();
			std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);
			//auto iter = mScene.find(name);

			// iterator�� ������ �ּҸ� �޾ƿ�. �ش� Ű�� ���� ���� ���ٸ� end()�� ��ȯ
			if (iter == mScene.end())
				return nullptr;

			// iterator�� first�� key��, second�� value���� �޾ƿ�
			mActiveScene = iter->second;
			mActiveScene->OnEnter();
			return iter->second;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
	private:
		// map �� ���ڴ� �� �� ��<key, value>
		static std::map<std::wstring, Scene*> mScene;
		// ���� ����ǰ� �ִ� ��
		static Scene* mActiveScene;
	};
}

