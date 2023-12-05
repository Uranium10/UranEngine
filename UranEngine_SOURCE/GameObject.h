#pragma once
#include "commonInclude.h"
#include "urComponent.h"
#include "urTransform.h"

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

		template <typename T>
		T* GetComponent() {
			T* component = nullptr;
			for (Component* comp : mComponents) {
				// dynamic_cast�� �θ�-�ڽİ� ����ȯ ����. �߸��� ����ȯ�̸� NULL��ȯ
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}
	private:
		void addInitializeTransForm();
		std::vector<Component*> mComponents;
	};
}

