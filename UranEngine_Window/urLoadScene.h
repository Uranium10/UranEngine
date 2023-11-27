#pragma once
#include "..\\UranEngine_SOURCE\\urSceneManager.h"
#include "urPlayScene.h"
#include "urTitleScene.h"

namespace ur {
	void LoadScenes() {
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}