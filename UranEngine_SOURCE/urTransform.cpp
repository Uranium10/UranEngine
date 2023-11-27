#include "urTransform.h"

namespace ur{
	Transform::Transform() : Component(), mPosition(Vector2::ZERO) {
	}
	Transform::Transform(Vector2 pos) : Component(), mPosition(pos) {
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