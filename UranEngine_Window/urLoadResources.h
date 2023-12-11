#pragma once

#include "..\\UranEngine_SOURCE\\urResources.h"
#include "..\\UranEngine_SOURCE\\urTexture.h"

namespace ur {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"BG", L"..\\Resources\\Stage\\Stage1.bmp");
		Resources::Load<graphics::Texture>(L"Marco_Top", L"..\\Resources\\MrTop.bmp");
		Resources::Load<graphics::Texture>(L"Marco_Top_Run", L"..\\Resources\\MrTop_Run.bmp");
		Resources::Load<graphics::Texture>(L"Marco_Top_FP", L"..\\Resources\\MrTop_FirePistol.bmp");
		Resources::Load<graphics::Texture>(L"MarcoL_Top", L"..\\Resources\\MrTopL.bmp");
		Resources::Load<graphics::Texture>(L"MarcoL_Top_Run", L"..\\Resources\\MrTop_RunL.bmp");
		Resources::Load<graphics::Texture>(L"Marco_Top_Upper", L"..\\Resources\\MrTop_Upper.bmp");
		Resources::Load<graphics::Texture>(L"Marco_Top_FPUpper", L"..\\Resources\\MrTop_FPUpper.bmp");
		Resources::Load<graphics::Texture>(L"Marco_Leg", L"..\\Resources\\MrLeg.bmp");
		Resources::Load<graphics::Texture>(L"Marco_Leg_Run", L"..\\Resources\\MrLeg_Run.bmp");
		Resources::Load<graphics::Texture>(L"MarcoL_Leg", L"..\\Resources\\MrLegL.bmp");
		Resources::Load<graphics::Texture>(L"MarcoL_Leg_Run", L"..\\Resources\\MrLeg_RunL.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\sample.png");
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\cat.bmp");
	}
}