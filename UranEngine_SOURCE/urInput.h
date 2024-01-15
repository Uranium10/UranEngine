#pragma once
#include "commonInclude.h"

namespace ur {
	using namespace math;
	enum class eKeyState {
		Down,
		Pressed,
		Up,
		None
	};
	enum class eKeyCode {
		// 키를 문자로 처리하면 대소문자 구분이 필요하므로, 숫자로 처리
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M,
		Left, Right, Down, Up, Space,
		LButton, MButton, RButton,
		End,
	};
	class Input
	{
		// 키의 상태? Down, Stay, Up
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		// 특정 키들의 눌림 상태를 반환시킴
		static bool GetKeyDown(eKeyCode	code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }
		static bool GetKeyNone(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::None; }

		static Vector2 GetVector() { return mVector; }
		static bool GetChanged() { return mbChanged; }
		static Vector2 GetMousePosition() { return mMousePosition; }
		static void GetMousePositionByWindow();

		static void Initialize();
		// 매 프레임마다 키보드 상태를 전부 체크해줘야함
		static void Update();

	private:
		// 0, 1, 2	: 눌렸을때, 유지, 뗏을때 : 다만 숫자로 하면 알아보기 어려우므로, 숫자를 문자로(Enum) 바꿔줌
		//eKeyState mState[]; 
		static std::vector<Key> mKeys;
		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(Key& key);
		static bool IsKeyDown(eKeyCode code);
		static void UpdateKeyDown(Key& key);
		static void UpdateKeyUp(Key& key);
		static void ClearKeys();
		static Vector2 mVector;
		static bool mbChanged;
		static Vector2 mMousePosition;

		// 키처리는 전역으로 해야 하기 때문에 static을 붙여 정적변수로 선언
		// 캡슐화를 지키기 위해 - 데이터를 외부에서 접근시키지 않기 위해 전역 영역에 선언하지는 않는다.
	};
}

