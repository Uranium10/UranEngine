#pragma once
#include "urEntity.h"
#include "commonInclude.h"
#include "GameObject.h"

namespace ur {
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();
		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);
	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};
}
