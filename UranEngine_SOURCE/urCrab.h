#pragma once
#include "GameObject.h"

namespace ur {
	class Crab : public GameObject{
	public:
		Crab();
		~Crab();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		
		void SetTarget(GameObject* target);
		GameObject* GetTarget() { return mTarget; }
	private:
		GameObject* mTarget;
	};
}