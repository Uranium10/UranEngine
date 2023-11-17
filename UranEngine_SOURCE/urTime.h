#pragma once
#include "commonInclude.h"

namespace ur {
	class Time {
		// �ð��� ��� �뵵�� CPU�� Ŭ�� ���� ����Ѵ�.
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static float DeltaTime() { return DeltaTimeValue;  };
	private:
		// CPU�� ���� ������
		static LARGE_INTEGER CpuFrequency;
		// ���� ����Ŭ�� ������
		static LARGE_INTEGER PrevFrequency;
		// ���� ������
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
		// 1�����Ӵ� �ɸ��� �ð��� �̵��ӵ��� �����ָ� ���ϴ� ����� ���´�
	};
}

