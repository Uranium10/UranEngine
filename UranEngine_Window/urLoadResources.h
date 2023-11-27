#pragma once

#include "..\\UranEngine_SOURCE\\urResources.h"
#include "..\\UranEngine_SOURCE\\urTexture.h"

namespace ur {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\kdm10\\source\\repos\\UranEngine\\Resources\\bgimage.png");
		Resources::Load<graphics::Texture>(L"Player", L"C:\\Users\\kdm10\\source\\repos\\UranEngine\\Resources\\sample.png");
	}
}