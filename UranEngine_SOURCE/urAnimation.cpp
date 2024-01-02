#include "urAnimation.h"
#include "urTime.h"
#include "urTransform.h"
#include "GameObject.h"
#include "urAnimator.h"
#include "urRenderer.h"
#include "urCamera.h"

namespace ur {
	Animation::Animation() : Resource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false) { }
	Animation::~Animation()
	{
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Update() {
		if (mbComplete)
			return;
		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime) {
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}
	void Animation::Render(HDC hdc) {
		// 알파블렌드를 쓸 수 있는 조건 : 해당 이미지에 알파채널 존재 (32bit BMP or PNG)

		if (mTexture == nullptr)
			return;

		GameObject* obj = mAnimator->GetOwner();
		Transform* tr = obj->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		Vector2 scale = tr->GetScale();
		float rot = tr->GetRotation();
		Vector2 os = tr->GetOffset();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		Sprite sprite = mAnimationSheet[mIndex];
		graphics::Texture::eTextureType type = mTexture->GetTextureType();

		if (type == graphics::Texture::eTextureType::Bmp) {
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255; // 0(Transparent) ~ 255(opacue)

			HDC imgHdc = mTexture->GetHdc();

			AlphaBlend(hdc
				// 그릴 위치
				, pos.x - os.x + sprite.offset.x
				, pos.y - os.y + sprite.offset.y
				// 그릴 크기
				, sprite.size.x * scale.x
				, sprite.size.y * scale.y
				, imgHdc
				, sprite.leftTop.x, sprite.leftTop.y  // 어디서부터 자를 것인가
				, sprite.size.x, sprite.size.y		// 얼마만큼 자를 것인가
				, func);
		}
		else if (type == graphics::Texture::eTextureType::Png) {
			// 내가 원하는 픽셀을 투명화 시킬 때 필요
			Gdiplus::ImageAttributes imgAtt = {};

			// 투명화 시킬 픽셀의 색 범위
			//imgAtt.SetColorKey(Gdiplus::Color(255, 0, 255), Gdiplus::Color(255, 0, 255));

			Gdiplus::Graphics graphics(hdc);
			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect (
					pos.x - os.x + sprite.offset.x
					, pos.y - os.y + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x	//	좌표를 정확히 지정함
				, sprite.size.y
				, Gdiplus::UnitPixel	// 투명화 옵션
				, nullptr
			);

		}
		
	}
	void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spritesheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration) {
		mTexture = spritesheet;
		for (size_t i = 0; i < spriteLength; i++) {
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;
			mAnimationSheet.push_back(sprite);
		}
	}
	void Animation::Reset() {
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}