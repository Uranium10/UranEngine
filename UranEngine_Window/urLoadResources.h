#pragma once

#include "..\\UranEngine_SOURCE\\urResources.h"
#include "..\\UranEngine_SOURCE\\urTexture.h"

namespace ur {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"BG", L"..\\Resources\\Stage\\Stage1.bmp");
		Resources::Load<graphics::Texture>(L"Ml", L"..\\Resources\\mleg.bmp");
		Resources::Load<graphics::Texture>(L"Mlr", L"..\\Resources\\mlegrun.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\sample.png");
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\cat.bmp");
	}
}