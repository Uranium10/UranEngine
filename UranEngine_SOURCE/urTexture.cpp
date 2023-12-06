#include "urTexture.h"
#include "urApplication.h"

// �ش� ���������� �������� �˸��� Ű����
extern ur::Application application;

namespace ur::graphics {
	Texture::Texture() : Resource(enums::eResourceType::Texture) {

	}
	Texture::~Texture() {
		Resource::~Resource();
	}
	HRESULT Texture::Load(const std::wstring& path)
	{
		//find_last_of�� . ���� ����, +1�� Ȯ���ڸ� ����
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		//bmp �� ��
		if (ext == L"bmp") {
			mType = eTextureType::Bmp;
			// bmp�̹��� �ҷ����� ( �ڵ�, ���(w_char*) )
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			// mBitmap���κ���, BITMAP ũ�� ��ŭ �����͸� info�� �־��ְڴ�.
			GetObject(mBitmap, sizeof(BITMAP), &info);
			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			if (info.bmBitsPixel == 32)
				mbAlpha = true;
			else if (info.bmBitsPixel == 24)
				mbAlpha = false;
			
			// ��Ʈ�� ���� ȭ�鿡 ������� DC�� �ʿ�
			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);
			// mHdc�� ��ȭ���� mBitmap���� �ٲٰ�, ������ �Ͼ� ��ȭ���� �����ش�.
			DeleteObject((HBITMAP)SelectObject(mHdc, mBitmap));
		}
		//png �� ��
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