#include "urComponent.h"

namespace ur {
	Component::Component(enums::eComponentType type) : mOwner(nullptr), mType(type) {
	}
	Component::~Component()
	{
	}
	void Component::Initialize() {
		
	}
	void Component::Update()
	{
	}
	void Component::LateUpdate()
	{
	}
	void Component::Render(HDC hdc)
	{
	}
}