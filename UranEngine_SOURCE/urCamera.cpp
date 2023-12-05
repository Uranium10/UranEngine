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
			mLookPosition = tr->GetPos() + tr->GetOffset();
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