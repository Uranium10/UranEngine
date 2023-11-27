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
		void Update(); // ������ ������ �� ������ ���ư��� ����
		void LateUpdate(); // ���߿� ������Ʈ �Ǵ� �Լ�
		void Run();
		void Render(); // ������ �׸� �� ���

		HDC GetHdc() { return mHdc; }
	private:
		HWND mHwnd;	// �ڵ�
		HDC mHdc;

		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

		// dc�� ���Ǵ� '��ȭ��'�� ������ �ڷ����� HBITMAP�̴�.
		// ���ݱ��� ���� �⺻ ���ۿ� ����, ���۸� �ϳ� �� ����� ���� ���۸��� ���
		// �׷��� �������� ��Ʈ���� �ٲٱ� ���� selectObject�� ���⿣ ��ȿ����.
		// �׷��� DC�� �׳�  �ϳ� �������, �� DC�� �׸��� ���� dc�� ������ ���� �ݺ�
		HDC mBackHdc;
		HBITMAP mBackBuffer;

		// �÷��̾��� ����
		float mSpeed;
		//float mx;
		//float my;
		// �ػ� : ���� �۾� ������ ���� �޴����� ���̸� �� ��ŭ�̴�.
		UINT mWidth;
		UINT mHeight;

		std::vector<GameObject*> mGameObjects;
	};


}

