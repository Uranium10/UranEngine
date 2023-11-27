#include "urCamera.h"
#include "urTransform.h"
#include "GameObject.h"

namespace ur {
	Camera::Camera() 
		: Component(enums::eComponentType::Camera)
		, mDistance(Vector2::ONE)
		, mLookPosition(Vector2::ZERO)
		, mResolution(Vector2(1600.0f, 900.0f))
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