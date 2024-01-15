#pragma once
#include "urComponent.h"

namespace ur {
	using namespace math;
	class Camera : public Component
	{
	public:
		// ī�޶� vector��ŭ �̵���Ű��, ȭ����� ��ü�� -vector��ŭ �������� �Ѵ�.
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
		// ��� ���� ������Ʈ���� �о��ֱ� ���� �迭
		//std::vector<GameObject*> mGameObjects;
		// ī�޶� ��ġ
		Vector2 mDistance;
		// ȭ�� �ػ�
		Vector2 mResolution;
		// ī�޶� �ٶ󺸴� ��ġ
		Vector2 mLookPosition;
		// ī�޶� ���󰡴� Ÿ��
		class GameObject* mTarget;
	};
}
