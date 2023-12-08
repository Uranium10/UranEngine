#pragma once

#include "..\\UranEngine_SOURCE\\urResources.h"
#include "..\\UranEngine_SOURCE\\urTexture.h"

namespace ur {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"BG", L"..\\Resources\\Stage\\Stage1.bmp");
		Resources::Load<graphics::Texture>(L"Marco_Top", L"..\\Resources\\MrTop.bmp");
		Resources::Load<graphics::Texture>(L"Marco_Top_Run", L"..\\Resources\\MrTop_Run.bmp");
		Resources::Load<graphics::Texture>(L"MarcoL_Top", L"..\\Resources\\MrTopL.bmp");
		Resources::Load<graphics::Texture>(L"MarcoL_Top_Run", L"..\\Resources\\MrTop_RunL.bmp");
		Resources::Load<graphics::Texture>(L"Marco_Leg", L"..\\Resources\\mleg.bmp");
		Resources::Load<graphics::Texture>(L"Marco_Leg_Run", L"..\\Resources\\mlegrun.bmp");
		Resources::Load<graphics::Texture>(L"MarcoL_Leg", L"..\\Resources\\mlegL.bmp");
		Resources::Load<graphics::Texture>(L"MarcoL_Leg_Run", L"..\\Resources\\mlegrunL.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\sample.png");
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\cat.bmp");
	}
}