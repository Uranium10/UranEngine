#pragma once

#include "commonInclude.h"
#include "GameObject.h"
#include "urSceneManager.h"

namespace ur {
	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND hWnd, UINT width, UINT height);
		void Update(); // 게임의 로직이 매 프레임 돌아가게 만듦
		void LateUpdate(); // 나중에 업데이트 되는 함수
		void Run();
		void Render(); // 뭔가를 그릴 때 사용

		HDC GetHdc() { return mHdc; }
	private:
		HWND mHwnd;	// 핸들
		HDC mHdc;

		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

		// dc에 사용되는 '도화지'의 개념의 자료형이 HBITMAP이다.
		// 지금까지 쓰던 기본 버퍼에 더해, 버퍼를 하나 더 만들어 더블 버퍼링을 사용
		// 그런데 매프레임 비트맵을 바꾸기 위해 selectObject를 쓰기엔 비효율적.
		// 그래서 DC를 그냥  하나 더만들고, 이 DC에 그린걸 원본 dc에 덮어씌우는 것을 반복
		HDC mBackHdc;
		HBITMAP mBackBuffer;

		// 플레이어의 변수
		float mSpeed;
		//float mx;
		//float my;
		// 해상도 : 실제 작업 영역은 위의 메뉴바의 높이를 뺀 만큼이다.
		UINT mWidth;
		UINT mHeight;

		std::vector<GameObject*> mGameObjects;
	};


}

