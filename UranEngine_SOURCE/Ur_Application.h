#pragma once

#include "commonInclude.h"
#include "GameObject.h"
#include "EnemyTest.h"
#include "BulletTest.h"

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
		static void AssignBullet(BulletTest* bul);
	private:
		HWND mHwnd;	// �ڵ�
		HDC mHdc;

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
		GameObject mPlayer;
		EnemyTest mEnemy;
		
		// �ػ� : ���� �۾� ������ ���� �޴����� ���̸� �� ��ŭ�̴�.
		UINT mWidth;
		UINT mHeight;
		
		static std::vector<BulletTest*> mBullets;

		//std::vector<Scene*> mScene;
		std::vector<int> mBulletsDeleteIndexes;
	};


}

