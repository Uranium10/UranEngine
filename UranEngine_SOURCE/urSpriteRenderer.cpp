#include "urSpriteRenderer.h"
#include "GameObject.h"
#include "urTransform.h"
#include "urTexture.h"

namespace ur {
	SpriteRenderer::SpriteRenderer() 
		: mTexture(nullptr){
		mSize = Vector2::ONE;
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize() {
		
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc) {
		// �ؽ�ó �����Ͻÿ�!
		if (mTexture == nullptr)
			assert(false);
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp) {
			// hdc, �׷��� ��ǥ, ����� �̹����� ũ��, 
			// �׷��� �̹����� �κ� ������ǥ, �׷��� �̹����� �߸� ũ��, ����ȭ�� ����(���� ����Ÿ)
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png) {
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}

		

		//HDC mHdc = hdc;
		//// ����ٰ� �׷��ش�
		//// WM_PAINT �̺�Ʈ�� ���� �� ���� �׷����� ���ʹ� �ٸ���, ��� ȣ���

		//HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // �Ķ� ���
		//// ���� ����� : brush
		//// DC ������ ����Ʈ ���� ��� ���, ������ ������ �Ǿ� �޸𸮿� ����Ǿ��ִ�.


		//HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, brush);
		//// ���� �Ķ� �귯���� �������ش�.
		//// HBRUSH�� GDI OBJECT�� ��ӹ޴´�.
		//// SelectObject�� ������ �ִ�, ��ü�� ���� ��ȯ���ش�. 
		//// ���� oldbrush�� �⺻���� �Ͼ� �귯���� ����ȴ�.

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//Rectangle(mHdc, pos.x, pos.y, 100 + pos.x, 100 + pos.y);
		//// �� ��, �⺻������ ������ �� �� ����� �޸𸮸� `�����ϰ� �ִ�.
		//// ���� �Ʊ� ���� �Ķ� ��� �귯���� �ٽ� ��� �⺻������ ��������, �Ķ� ����� �����Ѵ�.
		//// �̷� ������ �� ���� ĥ�ϰ� ���� ������ ����� �׶��׶� �������ش�.

		//SelectObject(mHdc, oldbrush);
		//// �ٽ� �� �� ���� �귯�� ����

		//DeleteObject(brush);

		//SelectObject(mHdc, oldPen);
		//DeleteObject(redPen);
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
	}
}
