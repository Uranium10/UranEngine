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
			mActiveScene = scene;
			scene->Initialize();

			// Ʈ���� �� ����
			mScene.insert(std::make_pair(name, scene));
			return scene;
		}

		// ������ ��ȯ�� �ϴ� ���� : Ȯ�强 ���(�ش� ���� �޾Ƽ� ����� ��찡 ���� �� ����)
		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return mActiveScene; };

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Release();
	private:
		// map �� ���ڴ� �� �� ��<key, value>
		static std::map<std::wstring, Scene*> mScene;
		// ���� ����ǰ� �ִ� ��
		static Scene* mActiveScene;
	};
}

