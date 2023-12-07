#pragma once
#include "urEntity.h"

namespace ur {
	// ���� ����(���������� ���縸 �˷��ش�)
	class GameObject;
	class Component : public Entity {
	public:
		Component(enums::eComponentType type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { mOwner = owner; }
		GameObject* GetOwner() { return mOwner; }
		enums::eComponentType GetType() { return mType; }
		void ChangeType(enums::eComponentType type) { mType = type; }
	private:
		GameObject* mOwner;
		enums::eComponentType mType;
	};
}

