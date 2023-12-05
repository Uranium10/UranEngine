#include "urTransform.h"

namespace ur{
	Transform::Transform(Vector2 pos)
		: Component(enums::eComponentType::Transform)
		, mPosition(pos)
		, mOffset(Vector2::ZERO)
		, mScale(Vector2::ONE)
		, mRotation(0.0f) {}
	Transform::~Transform() {
	}
	void Transform::Initialize() {
	}
	void Transform::Update() {
	}
	void Transform::LateUpdate() {
	}
	void Transform::Render(HDC hdc) {
	}
}