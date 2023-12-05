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
		//LP가 붙는 자료형은, 해당 자료형의 포인터를 의미
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
		// 키 갯수만큼 초기화
		// typedef int INT -> int를 INT라고 바꿔쓸 수 있게 된다.
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}
	void Input::UpdateKeys() {
		// 3가지 경우를 체크한다.
		// 키가 눌렸는지 아닌지 : GetAsyncKeyState는 char를 체크한다. 하지만 우리는 Enum을 쓰는데,
		// 이에 대응하기 위해 문자를 int 배열로 만들어 인덱스를 체크하면 Enum값에 대한 체크가 된다.
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
		if (key.bPressed)					// 이전에도 눌려있었고, 지금도 눌려있는 상태 - pressed
			key.state = eKeyState::Pressed;
		else									// 이전에 안눌려있었고, 지금 눌려짐 - down
			key.state = eKeyState::Down;
		key.bPressed = true;
	}
	void Input::UpdateKeyUp(Key& key) {
		if (key.bPressed)					// 이전에 눌려있었는데, 지금 뗌 - up
			key.state = eKeyState::Up;
		else									// 이전, 지금 모두 안눌려있음 - none
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
