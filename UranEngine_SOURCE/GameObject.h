#pragma once
#include "commonInclude.h"
#include "urComponent.h"

namespace ur {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent() {
			T* comp = new T();
			comp->SetOwner(this);
			mComponents.push_back(comp);

			return comp;
		}

		template <typename T>
		T* GetComponent() {
			T* component = nullptr;
			for (Component* comp : mComponents) {
				// dynamic_cast는 부모-자식간 형변환 진행. 잘못된 형변환이면 NULL반환
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}
	private:
		std::vector<Component*> mComponents;
	};
}

