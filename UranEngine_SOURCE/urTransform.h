#pragma once
#include "urComponent.h"

namespace ur {
	using namespace math;
	class Transform : public Component{
	public:
		Transform(Vector2 pos = Vector2::ZERO);
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(Vector2 pos) { mPosition = pos; }
		Vector2 GetPos() { return mPosition; }
		
		void SetOffset(Vector2 pos) { mOffset = pos; }
		Vector2 GetOffset() { return mOffset; }

		void SetRotation(float rotation) { mRotation = rotation; }
		float GetRotation() { return mRotation; }

		void SetScale(Vector2 scale) { mScale = scale; }
		Vector2 GetScale() { return mScale; }
	private:
		Vector2 mPosition;
		Vector2 mOffset;
		Vector2 mScale;
		float mRotation;

	};
}

