#include "urApplication.h"
#include "urInput.h"
#include <algorithm>

namespace ur {
	// ������ ���̴� �ٸ� ��ҿ� ��ġ�� �ʰ� ���ӽ����̽��� ������ 
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(nullptr)
		, mBackBuffer(nullptr)
		, mGameObjects{} {

	}
	Application::~Application() {

	}
	void Application::Initialize(HWND hWnd, UINT width, UINT height) {
		adjustWindowRect(hWnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		SceneManager::Initialize();
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

		SceneManager::Update();
	}
	void Application::LateUpdate() {
		SceneManager::LateUpdate();
	}
	void Application::Render() {
		clearRenderTarget();
		// �ܻ��� ��� ó���ϴ°�?
		// �׳� ū �� �簢���� ������ ������ �� �� ������, ������ �����Ÿ��⸸ �Ѵ�.
		// ���� ���� ���۸��� ����ؾ� �Ѵ�. -> dc�� �ϳ� �������
		// ���� �Ⱥ��̰Բ� dc�� ��ü�Ͽ� ����� �ٽ� ���� ������ �Ⱥ��̵��� �Ѵ�.
		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);
		copyRenderTarget(mBackHdc, mHdc);
	}
	
	void Application::clearRenderTarget() {
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);
	}
	void Application::copyRenderTarget(HDC source, HDC dest) {
		// ��, ���� ���� �μ��� �����Ͽ� ���� ȭ���� �Ű����� ��ġ�� ���� ����
		// ������ �μ��� ������
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
	void Application::adjustWindowRect(HWND hWnd, UINT width, UINT height) {
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);

		mWidth = width;
		mHeight = height;

		// ��ܹٸ� �� ���� �۾����� �ػ󵵸� ���ؾ���
		RECT rect = { 0, 0, mWidth, mHeight };
		// �������� �۾� ���� ũ�⸦ ������ - ���� ũ�⺸�� Ŀ��
		AdjustWindowRect(&rect, WS_OVERLAPPED, false);

		// ������ ��ġ ����, 5~6��° �μ��� ����(rect�� �̿��� ����)
		SetWindowPos(mHwnd, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top, 0);

		// �ٲ� �����츦 �ٽ� ������� ��
		ShowWindow(mHwnd, true);
	}
	void Application::createBuffer(UINT width, UINT height) {
		// ������ �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		// ����۸� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);
		//��HDC�� ����۸� ����
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);		// ������ ��� ��Ʈ���� ������
	}
	void Application::initializeEtc() {
		Input::Initialize();
		Time::Initialize();
	}
}