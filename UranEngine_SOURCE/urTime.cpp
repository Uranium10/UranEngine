#include "urTime.h"

namespace ur {
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;
	void Time::Initialize() {
		// Cpu ���� ������
		QueryPerformanceFrequency(&CpuFrequency);

		// ���α׷��� �������� �� ���� ������
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Update() {
		// �������� ���� �������� �����´�.
		// application�� Run ����Ŭ������ �������� �˰�ʹ�.
		// ����Ŭ ������ / CPU�������� �ϸ� �� ����Ŭ�� �ð��� ���´�.
		QueryPerformanceCounter(&CurrentFrequency);

		// ������ ���� : ����Ŭ �� ���������� ����Ŭ �� �������� ���� ����Ŭ������ �������� ���´�.
		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		//�� ����Ŭ(1������)�� �ɸ��� �ð� : ����Ŭ ������ / cpu ���� ������
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		
		// ���� �������� ���� �������� �������ش�.
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc) {
		static float time = 0.0f;

		// ���α׷� ����ð��� ��� ����
		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;
		
		// wchar�� 2����Ʈ¥���̴�. wchar ���ڿ��� �ʱ�ȭ�� ���ؼ� �տ� L�� �ٿ��� �Ѵ�(���ͷ�).
		wchar_t str[50] = L"";

		// time�� �����̹Ƿ�, �̸� ���ڿ��� ��ȯ���Ѿ� �Ѵ�.
		swprintf_s(str, 50, L"FPS : %d", (int)fps);
		// std::wcstout�� �ᵵ ������, �̴� ��� ������ 2����Ʈ ���ڿ��� �� �� �̸� ������� �ؼ� ������.
		
		// �� ���ڿ��� ���̸� ���ؾ� ��(���ڿ�, �ִ� ����)
		int len = wcsnlen_s(str, 50);

		// ȭ�鿡 �׷���
		TextOut(hdc, 0, 0, str, len);
	}
}