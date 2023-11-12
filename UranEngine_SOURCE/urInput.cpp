#include "urInput.h"
#include <algorithm>

namespace ur {
	std::vector<Input::Key> Input::mKeys = {};
	int ASCII[(UINT)eKeyCode::End] = {
		'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M', VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, VK_SPACE
	};
	void Input::Initialize() {
		CreateKeys();
	}

	void Input::Update() {
		// 3���� ��츦 üũ�Ѵ�.

		// Ű�� ���ȴ��� �ƴ��� : GetAsyncKeyState�� char�� üũ�Ѵ�. ������ �츮�� Enum�� ���µ�,
		// �̿� �����ϱ� ���� ���ڸ� int �迭�� ����� �ε����� üũ�ϸ� Enum���� ���� üũ�� �ȴ�.
		UpdateKeys();
			
	}
	void Input::CreateKeys() {
		// Ű ������ŭ �ʱ�ȭ
		// typedef int INT -> int�� INT��� �ٲ㾵 �� �ְ� �ȴ�.
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}
	void Input::UpdateKeys() {
		std::for_each(mKeys.begin(), mKeys.end(),
			[](Key& key) -> void {
				UpdateKey(key);
			});
	}
	void Input::UpdateKey(Key& key) {
		if (IsKeyDown(key.keyCode))
			UpdateKeyDown(key);
		else
			UpdateKeyUp(key);
	}
	bool Input::IsKeyDown(eKeyCode code) {
		return GetAsyncKeyState(ASCII[(UINT)code]);
	}
	void Input::UpdateKeyDown(Key& key) {
		if (key.bPressed)					// �������� �����־���, ���ݵ� �����ִ� ���� - pressed
			key.state = eKeyState::Pressed;
		else									// ������ �ȴ����־���, ���� ������ - down
			key.state = eKeyState::Down;
		key.bPressed = true;
	}
	void Input::UpdateKeyUp(Key& key) {
		if (key.bPressed)					// ������ �����־��µ�, ���� �� - up
			key.state = eKeyState::Up;
		else									// ����, ���� ��� �ȴ������� - none
			key.state = eKeyState::None;
		key.bPressed = false;
	}
}
