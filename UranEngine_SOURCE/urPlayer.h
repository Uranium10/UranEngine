#pragma once
#include "GameObject.h"
#include "urAnimator.h"

namespace ur {
	class Player : public GameObject {
	public:
		Player();
		~Player();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
		Animator* getPart() { return GetComponentByType<Animator>(enums::eComponentType::PartAnimator); }
	};
}

