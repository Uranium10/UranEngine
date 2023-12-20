#include "urScript.h"

namespace ur {
	Script::Script() : Component(enums::eComponentType::Script) {
	}
	Script::~Script() {
	}
	void Script::Initialize() {
	}
	void Script::Update() {
	}
	void Script::LateUpdate() {
	}
	void Script::Render(HDC hdc) {
	}
	void Script::PlayAnimationWithSide(WST& anim, Animator* am, bool loop) {
		std::wstring animIndex(anim);
		animIndex.append(SIDES[(UINT)mSide]);
		am->PlayAnimation(animIndex, loop);
	}
}