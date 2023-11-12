#include "GameObject.h"
#include "urInput.h"

namespace ur {
	GameObject::GameObject() {

	}
	GameObject::~GameObject() {

	}
	void GameObject::Update(){
		const int speed = 100.0f;
		// Ű���� �Է��� �ް�(VK_LEFT�� �׳� ����) �Է½� 0x8000�� ��ȯ
		// �̰��� �Լ��� ���� �ܼ�ȭ���Ѿ� �Ѵ�
		// �����Ӽӵ��� �������Ѿ� �Ѵ�.
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

		// �ܻ��� �ذ��ؾ� �Ѵ�.
	}
}

