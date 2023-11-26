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

			// 트리에 씬 삽입
			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		// 포인터 반환을 하는 이유 : 확장성 고려(해당 씬을 받아서 써야할 경우가 있을 수 있음)
		static Scene* LoadScene(const std::wstring& name) {
			if (mActiveScene)
				mActiveScene->OnExit();
			std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);
			//auto iter = mScene.find(name);

			// iterator는 포인터 주소를 받아옴. 해당 키에 대한 값이 없다면 end()를 반환
			if (iter == mScene.end())
				return nullptr;

			// iterator의 first는 key값, second는 value값을 받아옴
			mActiveScene = iter->second;
			mActiveScene->OnEnter();
			return iter->second;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
	private:
		// map 의 인자는 두 개 들어감<key, value>
		static std::map<std::wstring, Scene*> mScene;
		// 현재 실행되고 있는 씬
		static Scene* mActiveScene;
	};
}

