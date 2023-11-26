#include "urTime.h"

namespace ur {
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;
	void Time::Initialize() {
		// Cpu 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작했을 때 앞전 진동수
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Update() {
		// 돌때마다 현재 진동수를 가져온다.
		// application의 Run 사이클동안의 진동수를 알고싶다.
		// 사이클 진동수 / CPU진동수를 하면 한 사이클의 시간이 나온다.
		QueryPerformanceCounter(&CurrentFrequency);

		// 진동수 차이 : 사이클 후 진동수에서 사이클 전 진동수를 빼면 사이클동안의 진동수가 나온다.
		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		//한 사이클(1프레임)에 걸리는 시간 : 사이클 진동수 / cpu 고유 진동수
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		
		// 현재 진동수를 이전 진동수로 설정해준다.
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc) {
		static float time = 0.0f;

		// 프로그램 실행시간을 계속 저장
		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;
		
		// wchar는 2바이트짜리이다. wchar 문자열의 초기화를 위해선 앞에 L을 붙여야 한다(리터럴).
		wchar_t str[50] = L"";

		// time은 숫자이므로, 이를 문자열로 변환시켜야 한다.
		swprintf_s(str, 50, L"FPS : %d", (int)fps);
		// std::wcstout을 써도 되지만, 이는 어느 나라의 2바이트 문자열을 쓸 지 미리 정해줘야 해서 복잡함.
		
		// 위 문자열의 길이를 구해야 함(문자열, 최대 길이)
		int len = wcsnlen_s(str, 50);

		// 화면에 그려줌
		TextOut(hdc, 0, 0, str, len);
	}
}