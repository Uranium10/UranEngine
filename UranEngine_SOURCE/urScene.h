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
		//자식 클래스에서 부모의 private 요소에 접근할 수 있게 하기 위해 만든 함수
	private:
		void CreateLayers();

		std::vector<Layer*> mLayers;
	};
}

