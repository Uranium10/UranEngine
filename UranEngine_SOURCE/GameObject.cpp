#include "GameObject.h"
#include "urSpriteRenderer.h"
#include "urResources.h"
#include "urAnimator.h"

namespace ur {
	GameObject::GameObject() {
		mComponents.resize((UINT)enums::eComponentType::End);
		addInitializeTransForm();
	}
	GameObject::~GameObject() {
		// 동적 할당된 것들을 지워주지 않으면 메모리누수
		for (Component* comp : mComponents) {
			delete comp;
			comp = nullptr;
		}
	}
	void GameObject::Initialize() {
	}
	void GameObject::Update() {
		// 키보드 입력을 받고(VK_LEFT는 그냥 숫자) 입력시 0x8000을 반환
		// 이것을 함수로 묶어 단순화시켜야 한다
		// 프레임속도도 고정시켜야 한다.
		for (Component* comp : mComponents)
			if (comp)
				comp->Update();
	}
	void GameObject::LateUpdate() {
		for (Component* comp : mComponents)
			if (comp)
				comp->LateUpdate();
	}
	void GameObject::Render(HDC dc) {
		for (Component* comp : mComponents)
			if (comp)
				comp->Render(dc);
		/*
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
		*/
	}
	void GameObject::addInitializeTransForm() {
		AddComponent<Transform>();
	}
	void GameObject::SetTexture(const std::wstring& tex) {
		SpriteRenderer* sr;
		if (mComponents[(UINT)enums::eComponentType::SpriteRenderer] == nullptr)
			sr = AddComponent<SpriteRenderer>();
		else
			sr = dynamic_cast<SpriteRenderer*>(mComponents[(UINT)enums::eComponentType::SpriteRenderer]);
		sr->SetTexture(Resources::Find<graphics::Texture>(tex));
	}
	void GameObject::SetAnimation(const std::wstring& name, const std::wstring& tex, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		graphics::Texture* texture = Resources::Find<graphics::Texture>(tex);
		Animator* animator = GetComponent<Animator>();
		if (animator == nullptr)
			animator = AddComponent<Animator>();
		animator->CreateAnimation(name, texture, leftTop, size, offset, spriteLength, duration);
	}
}