#include "urPlayScene.h"
#include "GameObject.h"
#include "urPlayer.h"
#include "urTransform.h"
#include "urSpriteRenderer.h"
#include "urInput.h"
#include "urSceneManager.h"
#include "urObject.h"
#include "urBackground.h"

namespace ur {
	PlayScene::PlayScene(){
		
	}
	PlayScene::~PlayScene(){

	}
	void PlayScene::Initialize() {
		object::Instantiate<BackGround>(enums::eLayerType::Background, Vector2(0.0f, 0.0f));
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(100.0f, 100.0f));
	}

	void PlayScene::Update() {
		// 자식 함수에서 부모 함수를 호출하는 법 : 풀네임 입력
		Scene::Update();
	}

	void PlayScene::LateUpdate() {
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
			SceneManager::LoadScene(L"TitleScene");
	}

	void PlayScene::Render(HDC hdc) {
		Scene::Render(hdc);
		wchar_t str[50] = L"Play scene";
		TextOut(hdc, 0, 0, str, lstrlenW(str));
	}
	void PlayScene::OnEnter() {
	}
	void PlayScene::OnExit() {
		//mPlayer->GetComponent<Transform>()->SetPos(Vector2(0, 0));
	}
}
