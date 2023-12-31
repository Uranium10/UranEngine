#include "urSpriteRenderer.h"
#include "GameObject.h"
#include "urTransform.h"
#include "urTexture.h"
#include "urRenderer.h"

namespace ur {
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::ONE)
		, mLeftTop(Vector2::ZERO)
		, mView(Vector2::ZERO) {}
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
		// 텍스처 세팅하시오!
		if (mTexture == nullptr)
			assert(false);
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		Vector2 scale = tr->GetScale();
		float rot = tr->GetRotation();
		Vector2 os = tr->GetOffset();

		pos = renderer::mainCamera->CalculatePosition(pos);

		if (!std::wcscmp(GetOwner()->GetName().c_str(), L"FarBG"))
			pos.x /= 2;

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp) {
			if (mTexture->IsAlpha()) {
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)
				// hdc, 그려줄 좌표, 출력할 이미지의 크기, 
				// 그려줄 이미지의 부분 시작좌표, 그려줄 이미지의 잘릴 크기, 투명화할 색깔(보통 마젠타)
				AlphaBlend(hdc, pos.x - os.x, pos.y - os.y
					, mView.x * mSize.x * scale.x, mView.y * mSize.y * scale.y
					, mTexture->GetHdc(), mLeftTop.x, mLeftTop.y, mView.x, mView.y
					, func);
			}
			else {
				TransparentBlt(hdc, pos.x - os.x, pos.y - os.y
					, mView.x * mSize.x * scale.x, mView.y * mSize.y * scale.y
					, mTexture->GetHdc(), mLeftTop.x, mLeftTop.y, mView.x, mView.y
					, RGB(255, 0, 255));
			}
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png) {
			Gdiplus::ImageAttributes imgAtt = {};
			// 투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(255, 0, 255), Gdiplus::Color(255, 0, 255));
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(
					pos.x - os.x
					, pos.y - os.y
					, mView.x * mSize.x * scale.x
					, mView.y * mSize.y * scale.y
				)
				, mLeftTop.x, mLeftTop.y
				, mView.x, mView.y
				, Gdiplus::UnitPixel	// 투명화 옵션
				, &imgAtt
			);
			/*Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));*/
		}

		

		//HDC mHdc = hdc;
		//// 여기다가 그려준다
		//// WM_PAINT 이벤트때 최초 한 번만 그려졌던 때와는 다르게, 계속 호출됨

		//HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // 파랑 배경
		//// 색상 만들기 : brush
		//// DC 도형의 디폴트 값은 흰색 배경, 검은색 선으로 되어 메모리에 적재되어있다.


		//HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, brush);
		//// 만든 파랑 브러쉬를 선택해준다.
		//// HBRUSH는 GDI OBJECT를 상속받는다.
		//// SelectObject는 기존에 있던, 대체될 값을 반환해준다. 
		//// 따라서 oldbrush엔 기본값인 하얀 브러쉬가 저장된다.

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//Rectangle(mHdc, pos.x, pos.y, 100 + pos.x, 100 + pos.y);
		//// 이 때, 기본적으로 설정된 흰 색 배경이 메모리를 `낭비하고 있다.
		//// 따라서 아까 만든 파란 배경 브러쉬를 다시 흰색 기본값으로 돌려놓고, 파란 배경은 삭제한다.
		//// 이런 식으로 새 색을 칠하고 싶을 때마다 만들고 그때그때 삭제해준다.

		//SelectObject(mHdc, oldbrush);
		//// 다시 흰 색 원본 브러쉬 선택

		//DeleteObject(brush);

		//SelectObject(mHdc, oldPen);
		//DeleteObject(redPen);
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
	}
}
