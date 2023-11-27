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

namespace ur {
	PlayScene::PlayScene(){
		
	}
	PlayScene::~PlayScene(){

	}
	void PlayScene::Initialize() {
		// main camera : ������ ǥ������ ���� ī�޶�� ������Ʈ�� �����.
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		object::Instantiate<BackGround>(enums::eLayerType::Background, Vector2(0.0f, 0.0f));
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(100.0f, 100.0f));

		cameraComp->SetTarget(mPlayer);
	}

	void PlayScene::Update() {
		// �ڽ� �Լ����� �θ� �Լ��� ȣ���ϴ� �� : Ǯ���� �Է�
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
