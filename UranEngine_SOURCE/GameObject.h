#pragma once
#include "commonInclude.h"
#include "urComponent.h"
#include "urTransform.h"
#include "urEntity.h"
#include <typeinfo>

namespace ur {
	class GameObject : public Entity
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void SetTexture(const std::wstring& tex);
		virtual void SetAnimation(const std::wstring& name
			, const std::wstring& tex
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLength
			, float duration);
		template <typename T>
		T* AddComponent() {
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			
			mComponents[(UINT)comp->GetType()] = comp;
			return comp;
		}

		void AddComponentByParam(enums::eComponentType type, Component* comp) {
			comp->Initialize();
			comp->SetOwner(this);
			mComponents[(UINT)type] = comp;
		}

		template <typename T>
		T* GetComponent() {
			T* component = nullptr;
			for (Component* comp : mComponents) {
				// dynamic_cast는 부모-자식간 형변환 진행. 잘못된 형변환이면 NULL반환
				component = dynamic_cast<T*>(comp);
				if (component)
					if (comp->GetType() != enums::eComponentType::PartAnimator)
						break;
			}
			return component;
		}
		template <typename T>
		T* GetComponentByType(enums::eComponentType type) {
			return dynamic_cast<T*>(mComponents[(UINT)type]);
		}

		void SetLayer(enums::eLayerType type) { mLayer = type; }
		enums::eLayerType GetLayer() { return mLayer; }
	private:
		void addInitializeTransForm();
		std::vector<Component*> mComponents;
		enums::eLayerType mLayer;
	};
}

