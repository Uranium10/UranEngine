#include "Ur_Application.h"
#include "urInput.h"
#include <algorithm>

namespace ur {
	// ������ ���̴� �ٸ� ��ҿ� ��ġ�� �ʰ� ���ӽ����̽��� ������ 
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

		// ��ܹٸ� �� ���� �۾����� �ػ󵵸� ���ؾ���
		RECT rect = {0, 0, mWidth, mHeight};
		// �������� �۾� ���� ũ�⸦ ������ - ���� ũ�⺸�� Ŀ��
		AdjustWindowRect(&rect, WS_OVERLAPPED, false);

		// ������ ��ġ ����, 5~6��° �μ��� ����(rect�� �̿��� ����)
		SetWindowPos(mHwnd, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top, 0);

		// �ٲ� �����츦 �ٽ� ������� ��
		ShowWindow(mHwnd, true);

		// ������ �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		// ����۸� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc); 
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);		// ������ ��� ��Ʈ���� ������

		Input::Initialize();
		Time::Initialize();

		mPlayer.setPosition(100, 100);
		mEnemy.Initialize(400, 400, 200.0f, 200.0f, 100, 100);
	}
	void Application::Run() {
		// �� �� ����Ŭ�� 1�������̴�. 
		// ��ǻ�͸��� �������� �����ϰ� �̵��Ÿ��� �����Ӽ��� �����ָ� �ٸ� ��翡�� ���� �ӵ��� �� �� �ִ�.
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
		// �ܻ��� ��� ó���ϴ°�?
		// �׳� ū �� �簢���� ������ ������ �� �� ������, ������ �����Ÿ��⸸ �Ѵ�.
		// ���� ���� ���۸��� ����ؾ� �Ѵ�. -> dc�� �ϳ� �������
		// ���� �Ⱥ��̰Բ� dc�� ��ü�Ͽ� ����� �ٽ� ���� ������ �Ⱥ��̵��� �Ѵ�.
		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);
		mEnemy.Render(mBackHdc);
		std::for_each(mBullets.begin(), mBullets.end(),
			[this](BulletTest* bul)->void {
				bul->Render(mBackHdc);
			});

		// ��, ���� ���� �μ��� �����Ͽ� ���� ȭ���� �Ű����� ��ġ�� ���� ����
		// ������ �μ��� ������
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
	void Application::AssignBullet(BulletTest* bul) {
		mBullets.push_back(bul);
	}
}