#include "Ur_Application.h"
#include "urInput.h"
#include <algorithm>

namespace ur {
	// 기존에 쓰이는 다른 요소와 겹치지 않게 네임스페이스로 묶어줌 
	std::vector<BulletTest*> Application::mBullets = {};
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr) 
		, mSpeed(0.0f)
		, mWidth(0)
		, mHeight(0) 
		, mBackHdc(nullptr) 
		, mBackBuffer(nullptr)
		, mBulletsDeleteIndexes{} {}
	Application::~Application() {

	}
	void Application::Initialize(HWND hWnd, UINT width, UINT height) {
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);

		mWidth = width;
		mHeight = height;

		// 상단바를 뺀 실제 작업영역 해상도를 구해야함
		RECT rect = {0, 0, mWidth, mHeight};
		// 윈도우의 작업 영역 크기를 조정함 - 실제 크기보다 커짐
		AdjustWindowRect(&rect, WS_OVERLAPPED, false);

		// 윈도우 위치 설정, 5~6번째 인수는 길이(rect를 이용해 구함)
		SetWindowPos(mHwnd, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top, 0);

		// 바뀐 윈도우를 다시 보여줘야 함
		ShowWindow(mHwnd, true);

		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		// 백버퍼를 가르킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc); 
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);		// 기존의 흰색 비트맵을 지워줌

		Input::Initialize();
		Time::Initialize();

		mPlayer.setPosition(100, 100);
		mEnemy.Initialize(400, 400, 200.0f, 200.0f, 100, 100);
	}
	void Application::Run() {
		// 이 한 사이클이 1프레임이다. 
		// 컴퓨터마다 프레임을 측정하고 이동거리를 프레임수로 나눠주면 다른 사양에서 같은 속도를 낼 수 있다.
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update() {
		Input::Update();
		Time::Update();

		mPlayer.Update();
		mEnemy.Update();
		
		for (size_t i = 0; i < mBullets.size(); i++)
			if (mBullets[i]->CheckOutBound())
				mBulletsDeleteIndexes.push_back(i);
			else
				mBullets[i]->Update();
		for (int i = mBulletsDeleteIndexes.size() - 1; i >= 0; i--) {
			delete mBullets[mBulletsDeleteIndexes[i]];
			mBullets.erase(mBullets.begin() + mBulletsDeleteIndexes[i]);
		}
		mBulletsDeleteIndexes.clear();
	}
	void Application::LateUpdate() {

	}
	void Application::Render() {
		Rectangle(mBackHdc, 0, 0, mWidth, mHeight);
		// 잔상은 어떻게 처리하는가?
		// 그냥 큰 흰 사각형을 덮어씌우는 생각을 할 수 있으나, 빠르게 깜빡거리기만 한다.
		// 따라서 더블 버퍼링을 사용해야 한다. -> dc를 하나 더만든다
		// 눈에 안보이게끔 dc를 교체하여 지우고 다시 쓰는 과정을 안보이도록 한다.
		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);
		mEnemy.Render(mBackHdc);
		std::for_each(mBullets.begin(), mBullets.end(),
			[this](BulletTest* bul)->void {
				bul->Render(mBackHdc);
			});

		// 앞, 뒤의 길이 인수를 조정하여 원본 화면이 옮겨지는 위치를 지정 가능
		// 마지막 인수는 복사방법
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
	void Application::AssignBullet(BulletTest* bul) {
		mBullets.push_back(bul);
	}
}