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

		// �ڽ� Ŭ������ �θ��� ���� �����Լ��� ������ ��ӹ޾ƾ� �������� �ȴ�.
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
		// ��Ʈ���� ��ġ�� �� dc�� �����ؾ� ��
		HDC mHdc;

		//PNG
		Gdiplus::Image* mImage;
		UINT mWidth;
		UINT mHeight;
	};
}