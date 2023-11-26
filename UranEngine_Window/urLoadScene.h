#pragma once
#include "..\\UranEngine_SOURCE\\urSceneManager.h"
#include "urPlayScene.h"
#include "urTitleScene.h"

namespace ur {
	void LoadScenes() {
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}