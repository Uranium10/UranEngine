#pragma once
#include"urResource.h"

namespace ur::graphics {
	class Texture : public Resource
	{
	public:
		enum class eTextureType {
			Bmp,
			Png,
			None,
		};
		Texture();
		~Texture();

		// 자식 클래스는 부모의 순수 가상함수를 무조건 상속받아야 컴파일이 된다.
		HRESULT Load(const std::wstring& path) override;
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }
	private:
		eTextureType mType;
		//BMP
		HBITMAP mBitmap;
		// 비트맵을 설치해 줄 dc도 설정해야 함
		HDC mHdc;

		//PNG
		Gdiplus::Image* mImage;
		UINT mWidth;
		UINT mHeight;
	};
}