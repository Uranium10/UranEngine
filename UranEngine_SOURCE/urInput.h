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
		// Ű�� ���ڷ� ó���ϸ� ��ҹ��� ������ �ʿ��ϹǷ�, ���ڷ� ó��
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M,
		Left, Right, Down, Up, Space,
		LButton, MButton, RButton,
		End,
	};
	class Input
	{
		// Ű�� ����? Down, Stay, Up
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		// Ư�� Ű���� ���� ���¸� ��ȯ��Ŵ
		static bool GetKeyDown(eKeyCode	code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }
		static bool GetKeyNone(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::None; }

		static Vector2 GetVector() { return mVector; }
		static bool GetChanged() { return mbChanged; }
		static Vector2 GetMousePosition() { return mMousePosition; }
		static void GetMousePositionByWindow();

		static void Initialize();
		// �� �����Ӹ��� Ű���� ���¸� ���� üũ�������
		static void Update();

	private:
		// 0, 1, 2	: ��������, ����, ������ : �ٸ� ���ڷ� �ϸ� �˾ƺ��� �����Ƿ�, ���ڸ� ���ڷ�(Enum) �ٲ���
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

		// Űó���� �������� �ؾ� �ϱ� ������ static�� �ٿ� ���������� ����
		// ĸ��ȭ�� ��Ű�� ���� - �����͸� �ܺο��� ���ٽ�Ű�� �ʱ� ���� ���� ������ ���������� �ʴ´�.
	};
}

