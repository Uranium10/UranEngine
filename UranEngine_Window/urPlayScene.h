#pragma once
#include "..\\UranEngine_SOURCE\\urScene.h"
#include "..\\UranEngine_SOURCE\\urBackground.h"

namespace ur {
	class Player;
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;
	private:
		Player* mPlayer;
		BackGround* mBg;
	};
}