// Editor_Windows.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Editor_Windows.h"

#include "..\\UranEngine_SOURCE\\urApplication.h"
#include "..\\UranEngine_Window\\urLoadResources.h"
#include "..\\UranEngine_Window\\urLoadScene.h"

ur::Application application;
float wWidth = 1600, wHeight = 900;

ULONG_PTR gpToken;
Gdiplus::GdiplusStartupInput gpsi;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
												// WCHAR : 한글/한자를 담을 수 있는 2바이트 변수
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//메인 함수
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // 프로그램의 인스턴스 핸들
					 _In_opt_ HINSTANCE hPrevInstance,  // 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들, 없을우에는 NULL
														// 지금은 신경쓰지 않아도 되는 값
					 _In_ LPWSTR    lpCmdLine,  // 명령행으로 입력된 프로그램 인수
					 _In_ int       nCmdShow)   // 프로그램이 실행될 형태이며, 보통 모양 정보등이 전달됨.
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(254);
	// TODO: 여기에 코드를 입력합니다.

	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);             // 창 이름이 szTitle로 들어감
	LoadStringW(hInstance, IDC_EDITORWINDOWS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 애플리케이션 초기화를 수행합니다:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOWS));

	MSG msg;

	// 기본 메시지 루프입니다: 
	
	// // winclass 생성 - createWindow 창 생성 - showWindow 창 표시 - 메세지 루프
	// 메세지 기반 명령어 처리 방식의 경우 메세지가 없으면 가만히 있다. - 게임엔 부적합하다.
	// 따라서 getmessage를 쓰는 while문 구조 자체의 변경이 필요
	
	// GetMassage : 메세지 큐에 들어온 메세지를 처리하는 함수
	// 메세지 큐에 아무것도 없다면 아무 메세지도 가져오지 않게 된다
	
	// PeekMessage : 메세지 큐에 메세지 유무 상관 없이 함수가 리턴됨
	//				리턴 값이 true일 경우 메세지가 있고 false인 경우는 메세지가 없다고 가르쳐줌
	// 
	while (true)	// 게임이니 항상 돌림
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) // PM_REMOVE : 메세지를 읽었으면 삭제 
		{
			if (msg.message == WM_QUIT) // 메세지가 종료명령이면 루프를 빠져나감
				break;

			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) // 이외의 메세지는 번역해서 보내준다.
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else 
		{
			// 메세지가 없는 경우 여기서 처리
			// 게임 로직이 여기에 들어가면 된다.
			application.Run();
		}
	}


	//while (GetMessage(&msg, nullptr, 0, 0))
	//{
	//	if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
	//	{
	//		TranslateMessage(&msg);
	//		DispatchMessage(&msg);
	//	}
	//}
	Gdiplus::GdiplusShutdown(gpToken);
	application.Release();
	return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = WndProc;							// 메세지 루프 함수가 들어감
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOWS));
	wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITORWINDOWS);
	wcex.lpszClassName  = szWindowClass;	// 램에 등록된 윈도우 이름 : EDITORWINDOW
	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);		// 해당 함수를 통해 램에 윈도우를 등록함
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	  CW_USEDEFAULT, 0, wWidth, wHeight, nullptr, nullptr, hInstance, nullptr);
   // 윈도우 생성 - 핸들 반환
   // CreateWindowW 함수에서 szWindowClass에 들어간 이름을 사용하는 윈도우가 생성됨(메모리에 올라감)
   // WS_OVERLAPPEDWINDOW : 창이 뜨는 형태
   // CW_USEDEFAULT, 0, CW_USEDEFAULT, 0 : 처음 두 숫자는 시작 좌표, 나중 두 숫자는 크기(x, y, width, height)
   // hWnd에는 생성된 윈도우의 핸들이 반환됨

   application.Initialize(hWnd, wWidth, wHeight);
   // 핸들은 포인터이므로 복사되지 않는다.

   if (!hWnd)
   {
	  return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);	// 윈도우를 화면에 표시
   UpdateWindow(hWnd);

   Gdiplus::GdiplusStartup(&gpToken, &gpsi, NULL);
	
   int a = 0;
   srand((UINT)(&a));

   ur::LoadResources();
   ur::LoadScenes();

   return TRUE;
}

//
//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:			// 상단 메뉴
		{
			int wmId = LOWORD(wParam);
			// 메뉴 선택을 구문 분석합니다:
			switch (wmId)
			{
			case IDM_ABOUT:		// 메뉴의 정보를 누르면 다이얼로그 박스를 만듦
				DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				break;
			case IDM_EXIT:		// 끝내기
				DestroyWindow(hWnd);
				break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			
			HDC hdc = BeginPaint(hWnd, &ps);
			// dc란, 화면 출력에 필요한 모든 정보를 가지는 데이터 구조체다.
			// GDI 모듈에 의해 관리된다.
			// 어떤 폰트, 어떤 선의 굵기, 어떤 색상으로 그릴건지 등을 관리
			// 화면 출력에 필요한 모든 경우는 WINAPI에서 DC를 통해 작업 진행
			// 각 화면의 DC를 이용해 해당 화면에 그릴 수 있음 - 어떤 DC인지를 명확히 밝혀야 함
			// 
			// 
			// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

			

			EndPaint(hWnd, &ps);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

