#include "urTexture.h"
#include "urApplication.h"

// 해당 전역변수가 존재함을 알리는 키워드
extern ur::Application application;

namespace ur::graphics {
	Texture::Texture() : Resource(enums::eResourceType::Texture) {

	}
	Texture::~Texture() {
		Resource::~Resource();
	}
	HRESULT Texture::Load(const std::wstring& path)
	{
		//find_last_of로 . 까지 추출, +1로 확장자만 추출
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		//bmp 일 때
		if (ext == L"bmp") {
			mType = eTextureType::Bmp;
			// bmp이미지 불러오기 ( 핸들, 경로(w_char*) )
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			// mBitmap으로부터, BITMAP 크기 만큼 데이터를 info에 넣어주겠다.
			GetObject(mBitmap, sizeof(BITMAP), &info);
			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			if (info.bmBitsPixel == 32)
				mbAlpha = true;
			else if (info.bmBitsPixel == 24)
				mbAlpha = false;
			
			// 비트맵 값을 화면에 출력해줄 DC가 필요
			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);
			// mHdc의 도화지를 mBitmap으로 바꾸고, 기존의 하얀 도화지를 지워준다.
			DeleteObject((HBITMAP)SelectObject(mHdc, mBitmap));
		}
		//png 일 때
		else if (ext == L"png") {
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());
			if (mImage == nullptr)
				return S_FALSE;
			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}
		return S_OK;
	}
}