#pragma once
#include "commonInclude.h"
#include "urEntity.h"
#include "GameObject.h"
#include "urLayer.h"

namespace ur {
	class Scene  : public Entity {
	public:
		Scene();
		~Scene();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const eLayerType type);
		//�ڽ� Ŭ�������� �θ��� private ��ҿ� ������ �� �ְ� �ϱ� ���� ���� �Լ�
	private:
		void CreateLayers();

		std::vector<Layer*> mLayers;
	};
}

