#include "urCamera.h"
#include "urTransform.h"
#include "GameObject.h"

extern float wWidth;
extern float wHeight;

namespace ur {
	Camera::Camera() 
		: Component(enums::eComponentType::Camera)
		, mDistance(Vector2::ONE)
		, mLookPosition(Vector2::ZERO)
		, mResolution(Vector2(wWidth, wHeight))
		, mTarget(nullptr) {
	}
	Camera::~Camera() {	}
	void Camera::Initialize() {}
	void Camera::Update() {
		if (mTarget) {
			Transform* tr = mTarget->GetComponent<Transform>();
			Vector2 charPos = tr->GetPos() + tr->GetOffset();
			Vector2 coord = Vector2::ZERO;
			if (charPos.x < wWidth / 2)
				coord.x = wWidth / 2;
			// 맵크기 넘어갈시의 카메라 이동 설정
			else
				coord.x = charPos.x;
			if (charPos.y > wHeight / 2)
				coord.y = wHeight / 2;
			// 맵크기 넘어갈시의 카메라 이동 설정
			else
				coord.y = charPos.y;
			mLookPosition = coord;
		}
		else {
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTr->GetPos();
		}
		mDistance = mLookPosition - (mResolution / 2.0f);
	}
	void Camera::LateUpdate() {
		
	}
	void Camera::Render(HDC hdc) {
	}
}