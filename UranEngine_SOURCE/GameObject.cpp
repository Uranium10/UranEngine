#include "GameObject.h"
#include "urInput.h"

namespace ur {
	GameObject::GameObject() {

	}
	GameObject::~GameObject() {

	}
	void GameObject::Update(){
		const int speed = 100.0f;
		// 키보드 입력을 받고(VK_LEFT는 그냥 숫자) 입력시 0x8000을 반환
		// 이것을 함수로 묶어 단순화시켜야 한다
		// 프레임속도도 고정시켜야 한다.
		if (Input::GetKey(eKeyCode::Left)) {
			mX -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Right)) {
			mX += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down)) {
			mY += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up)) {
			mY -= speed * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate() {
	}
	void GameObject::Render(HDC dc) {
		HDC mHdc = dc;
		// 여기다가 그려준다
		// WM_PAINT 이벤트때 최초 한 번만 그려졌던 때와는 다르게, 계속 호출됨

		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // 파랑 배경
		// 색상 만들기 : brush
		// DC 도형의 디폴트 값은 흰색 배경, 검은색 선으로 되어 메모리에 적재되어있다.


		HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, brush);
		// 만든 파랑 브러쉬를 선택해준다.
		// HBRUSH는 GDI OBJECT를 상속받는다.
		// SelectObject는 기존에 있던, 대체될 값을 반환해준다. 
		// 따라서 oldbrush엔 기본값인 하얀 브러쉬가 저장된다.

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		Rectangle(mHdc, mX, mY, 100 + mX, 100 + mY);
		// 이 때, 기본적으로 설정된 흰 색 배경이 메모리를 낭비하고 있다.
		// 따라서 아까 만든 파란 배경 브러쉬를 다시 흰색 기본값으로 돌려놓고, 파란 배경은 삭제한다.
		// 이런 식으로 새 색을 칠하고 싶을 때마다 만들고 그때그때 삭제해준다.

		SelectObject(mHdc, oldbrush);
		// 다시 흰 색 원본 브러쉬 선택

		DeleteObject(brush);

		SelectObject(mHdc, oldPen);
		DeleteObject(redPen);
		// brush는 힙에 동적 할당되므로, API에서 지원해주는 삭제 메소드를 사용

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);
		//// 테두리는 HPEN으로 설정할 수 있다.

		//Ellipse(mHdc, 200, 200, 300, 300);

		//SelectObject(mHdc, oldPen);
		//DeleteObject(redPen);

		//// 기본적으로 많이 사용되는 오브젝트들은 DC안에 기본적으로 저장돼있다.
		//// 이를 스톡 오브젝트라고 한다 (하얀 배경, 검정 선 등)

		//HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		//oldbrush = (HBRUSH)SelectObject(mHdc, grayBrush);

		//Rectangle(mHdc, 300, 300, 400, 400);
		//SelectObject(mHdc, oldbrush);

		//Rectangle(mHdc, 500, 500, 600, 600);

		// 잔상을 해결해야 한다.
	}
}

