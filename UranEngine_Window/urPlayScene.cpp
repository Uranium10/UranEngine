#include "urPlayScene.h"
#include "GameObject.h"
#include "urPlayer.h"
#include "urTransform.h"
#include "urSpriteRenderer.h"
#include "urInput.h"
#include "urSceneManager.h"
#include "urObject.h"
#include "urBackground.h"
#include "urCamera.h"
#include "urRenderer.h"
#include "urPlayerScript.h"
#include "urCat.h"

extern float wWidth;
extern float wHeight;

namespace ur {
	PlayScene::PlayScene(){
		
	}
	PlayScene::~PlayScene(){

	}
	void PlayScene::Initialize() {
		// main camera : 실제로 표시하지 않을 카메라용 오브젝트를 만든다.
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);
		Camera* cameraComp = camera->AddComponent<Camera>();
		cameraComp->SetResolution(Vector2(wWidth, wHeight));
		renderer::mainCamera = cameraComp;

		mBg = object::Instantiate<BackGround>(enums::eLayerType::Background, Vector2(0.0f, 0.0f));
		Transform* tr = mBg->GetComponent<Transform>();
		tr->SetScale(Vector2(2.0f,2.0f));
		tr->SetPos(Vector2(-wWidth / 2.0f, -wHeight / 2.0f));

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(100.0f, 100.0f));

		//object::Instantiate<Cat>(enums::eLayerType::Animal, Vector2(200.0f, 200.0f));

		cameraComp->SetTarget(mPlayer);
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
