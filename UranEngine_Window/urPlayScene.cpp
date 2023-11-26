#include "urPlayScene.h"
#include "GameObject.h"
#include "urPlayer.h"
#include "urTransform.h"
#include "urSpriteRenderer.h"
#include "urInput.h"
#include "urSceneManager.h"

namespace ur {
	PlayScene::PlayScene(){
		
	}
	PlayScene::~PlayScene(){

	}
	void PlayScene::Initialize() {
		mPlayer = new Player();
		AddGameObject(mPlayer, eLayerType::Background);
		Transform* tr = mPlayer->AddComponent<Transform>();
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		tr->SetPos(Vector2(100, 100));
		Player* pl2 = new Player();

		sr->ImageLoad(L"C:\\Users\\kdm10\\source\\repos\\UranEngine\\Resources\\bgimage.png");
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
		mPlayer->GetComponent<Transform>()->SetPos(Vector2(0, 0));
	}
}
