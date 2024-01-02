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
		// ���� �Ҵ�� �͵��� �������� ������ �޸𸮴���
		for (Component* comp : mComponents) {
			delete comp;
			comp = nullptr;
		}
	}
	void GameObject::Initialize() {
	}
	void GameObject::Update() {
		// Ű���� �Է��� �ް�(VK_LEFT�� �׳� ����) �Է½� 0x8000�� ��ȯ
		// �̰��� �Լ��� ���� �ܼ�ȭ���Ѿ� �Ѵ�
		// �����Ӽӵ��� �������Ѿ� �Ѵ�.
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
		// ����ٰ� �׷��ش�
		// WM_PAINT �̺�Ʈ�� ���� �� ���� �׷����� ���ʹ� �ٸ���, ��� ȣ���

		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // �Ķ� ���
		// ���� ����� : brush
		// DC ������ ����Ʈ ���� ��� ���, ������ ������ �Ǿ� �޸𸮿� ����Ǿ��ִ�.


		HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, brush);
		// ���� �Ķ� �귯���� �������ش�.
		// HBRUSH�� GDI OBJECT�� ��ӹ޴´�.
		// SelectObject�� ������ �ִ�, ��ü�� ���� ��ȯ���ش�. 
		// ���� oldbrush�� �⺻���� �Ͼ� �귯���� ����ȴ�.

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		Rectangle(mHdc, mX, mY, 100 + mX, 100 + mY);
		// �� ��, �⺻������ ������ �� �� ����� �޸𸮸� �����ϰ� �ִ�.
		// ���� �Ʊ� ���� �Ķ� ��� �귯���� �ٽ� ��� �⺻������ ��������, �Ķ� ����� �����Ѵ�.
		// �̷� ������ �� ���� ĥ�ϰ� ���� ������ ����� �׶��׶� �������ش�.

		SelectObject(mHdc, oldbrush);
		// �ٽ� �� �� ���� �귯�� ����

		DeleteObject(brush);

		SelectObject(mHdc, oldPen);
		DeleteObject(redPen);
		// brush�� ���� ���� �Ҵ�ǹǷ�, API���� �������ִ� ���� �޼ҵ带 ���

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);
		//// �׵θ��� HPEN���� ������ �� �ִ�.

		//Ellipse(mHdc, 200, 200, 300, 300);

		//SelectObject(mHdc, oldPen);
		//DeleteObject(redPen);

		//// �⺻������ ���� ���Ǵ� ������Ʈ���� DC�ȿ� �⺻������ ������ִ�.
		//// �̸� ���� ������Ʈ��� �Ѵ� (�Ͼ� ���, ���� �� ��)

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