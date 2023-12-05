#pragma once

#include "..\\UranEngine_SOURCE\\urResources.h"
#include "..\\UranEngine_SOURCE\\urTexture.h"

namespace ur {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"BG", L"..\\Resources\\bgimage.png");
		Resources::Load<graphics::Texture>(L"Player", L"C:..\\Resources\\sample.png");
		Resources::Load<graphics::Texture>(L"Cat", L"C:..\\Resources\\cat.bmp");
	}
}