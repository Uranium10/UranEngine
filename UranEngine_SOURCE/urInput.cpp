#include "urInput.h"
#include <algorithm>
#include "urApplication.h"

extern ur::Application application;
namespace ur {
	std::vector<Input::Key> Input::mKeys = {};
	Vector2 Input::mVector = Vector2::ZERO;
	Vector2 Input::mMousePosition = Vector2::ZERO;
	bool Input::mbChanged = false;
	int ASCII[(UINT)eKeyCode::End] = {
		'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'
		, VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, VK_SPACE, VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
	};
	void Input::GetMousePositionByWindow()
	{
		POINT mousePos = {};
		//LP�� �ٴ� �ڷ�����, �ش� �ڷ����� �����͸� �ǹ�
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);
		mMousePosition = mousePos;
	}
	void Input::Initialize() {
		CreateKeys();
	}

	void Input::Update() {
		UpdateKeys();
		Vector2 dir = Vector2::ZERO;
		if (IsKeyDown(eKeyCode::Down))
			dir.y += 1;
		if (IsKeyDown(eKeyCode::Up))
			dir.y -= 1;
		if (IsKeyDown(eKeyCode::Left))
			dir.x -= 1;
		if (IsKeyDown(eKeyCode::Right))
			dir.x += 1;
		if (dir != mVector) {
			mbChanged = true;
			mVector = dir;
		}
		else
			mbChanged = false;

			
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
		// 3���� ��츦 üũ�Ѵ�.
		// Ű�� ���ȴ��� �ƴ��� : GetAsyncKeyState�� char�� üũ�Ѵ�. ������ �츮�� Enum�� ���µ�,
		// �̿� �����ϱ� ���� ���ڸ� int �迭�� ����� �ε����� üũ�ϸ� Enum���� ���� üũ�� �ȴ�.
		std::for_each(mKeys.begin(), mKeys.end(),
			[](Key& key) -> void {
				UpdateKey(key);
			});
	}
	void Input::UpdateKey(Key& key) {
		if (!GetFocus()) {
			ClearKeys();
			return;
		}
		if (IsKeyDown(key.keyCode))
			UpdateKeyDown(key);
		else
			UpdateKeyUp(key);

		GetMousePositionByWindow();
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
	void Input::ClearKeys()
	{
		for (Key& key : mKeys) {
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
				key.state = eKeyState::Up;
			else if (key.state == eKeyState::Up)
				key.state = eKeyState::None;
			key.bPressed = false;
		}

	}
}
