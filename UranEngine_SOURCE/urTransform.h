#pragma once
#include "urComponent.h"

namespace ur {
	using namespace math;
	class Transform : public Component{
	public:
		Transform();
		Transform(Vector2 pos);
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(Vector2 pos) { mPosition = pos; }
		Vector2 GetPos() { return mPosition; }
	private:
		Vector2 mPosition;
	};
}

