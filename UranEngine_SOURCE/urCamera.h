#pragma once
#include "urComponent.h"

namespace ur {
	using namespace math;
	class Camera : public Component
	{
	public:
		// 카메라를 vector만큼 이동시키면, 화면안의 물체는 -vector만큼 움직여야 한다.
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { mTarget = target; }
		void SetResolution(Vector2 res) { mResolution = res; }

	private:
		// 모든 게임 오브젝트들을 밀어주기 위한 배열
		//std::vector<GameObject*> mGameObjects;
		// 카메라 위치
		Vector2 mDistance;
		// 화면 해상도
		Vector2 mResolution;
		// 카메라가 바라보는 위치
		Vector2 mLookPosition;
		// 카메라가 따라가는 타겟
		class GameObject* mTarget;
	};
}
