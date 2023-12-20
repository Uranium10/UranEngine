#pragma once

#include "..\\UranEngine_SOURCE\\urResources.h"
#include "..\\UranEngine_SOURCE\\urTexture.h"

namespace ur {
	void LoadResources() {
		//Loading Map
		{
			Resources::Load<graphics::Texture>(L"BG", L"..\\Resources\\Stage\\Stage1.bmp");
			Resources::Load<graphics::Texture>(L"Stage1_Shore", L"..\\Resources\\Stage\\Anim\\Stage1_Shore.bmp");
		}
		// Loading Marco
		{
			Resources::Load<graphics::Texture>(L"Marco_Top", L"..\\Resources\\MrTop.bmp");
			Resources::Load<graphics::Texture>(L"Marco_Top_Run", L"..\\Resources\\MrTop_Run.bmp");
			Resources::Load<graphics::Texture>(L"Marco_Top_FP", L"..\\Resources\\MrTop_FirePistol.bmp");
			Resources::Load<graphics::Texture>(L"Marco_Top_BP", L"..\\Resources\\MrTop_BP.bmp");
			Resources::Load<graphics::Texture>(L"MarcoL_Top", L"..\\Resources\\MrTopL.bmp");
			Resources::Load<graphics::Texture>(L"MarcoL_Top_Run", L"..\\Resources\\MrTop_RunL.bmp");
			Resources::Load<graphics::Texture>(L"Marco_Top_Upper", L"..\\Resources\\MrTop_Upper.bmp");
			Resources::Load<graphics::Texture>(L"Marco_Top_FPUpper", L"..\\Resources\\MrTop_FPUpper.bmp");
			Resources::Load<graphics::Texture>(L"Marco_Leg", L"..\\Resources\\MrLeg.bmp");
			Resources::Load<graphics::Texture>(L"Marco_Leg_Run", L"..\\Resources\\MrLeg_Run.bmp");
			Resources::Load<graphics::Texture>(L"MarcoL_Leg", L"..\\Resources\\MrLegL.bmp");
			Resources::Load<graphics::Texture>(L"MarcoL_Leg_Run", L"..\\Resources\\MrLeg_RunL.bmp");
			Resources::Load<graphics::Texture>(L"Marco_To_Sit", L"..\\Resources\\Mr_ToSit.bmp");
			Resources::Load<graphics::Texture>(L"Marco_Sit", L"..\\Resources\\Mr_Sit.bmp");
			Resources::Load<graphics::Texture>(L"Marco_Sit_Walk", L"..\\Resources\\Mr_SitWalk.bmp");
			Resources::Load<graphics::Texture>(L"Marco_FPSit", L"..\\Resources\\Mr_FPSit.bmp");
			Resources::Load<graphics::Texture>(L"Marco_BPSit", L"..\\Resources\\Mr_BPSit.bmp");
		}
		// Loading Crab
		{
			Resources::Load<graphics::Texture>(L"Crab_Idle", L"..\\Resources\\npc\\Crab\\Idle.bmp");
			Resources::Load<graphics::Texture>(L"Crab_Walk", L"..\\Resources\\npc\\Crab\\Walk.bmp");
			Resources::Load<graphics::Texture>(L"Crab_Melee", L"..\\Resources\\npc\\Crab\\Melee.bmp");
		}
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\cat.bmp");
	}
}