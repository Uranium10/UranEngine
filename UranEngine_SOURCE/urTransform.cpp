#include "urTransform.h"

namespace ur{
	Transform::Transform() : Component(enums::eComponentType::Transform), mPosition(Vector2::ZERO), mOffset(Vector2::ZERO) {
	}
	Transform::Transform(Vector2 pos) : Component(enums::eComponentType::Transform), mPosition(pos), mOffset(Vector2::ZERO) {
	}
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