#pragma once
#include "commonInclude.h"

namespace ur {
	class Time {
		// 시간을 재는 용도로 CPU의 클럭 수를 사용한다.
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static float DeltaTime() { return DeltaTimeValue;  };
	private:
		// CPU의 고유 진동수
		static LARGE_INTEGER CpuFrequency;
		// 이전 사이클의 진동수
		static LARGE_INTEGER PrevFrequency;
		// 현재 진동수
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
		// 1프레임당 걸리는 시간을 이동속도에 곱해주면 원하는 결과가 나온다
	};
}

