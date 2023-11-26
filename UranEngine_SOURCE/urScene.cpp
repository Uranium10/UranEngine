#include "urScene.h"

namespace ur {
	Scene::Scene() 
		: mLayers{} {
		// 최대치까지 레이어 설정
		CreateLayers();
	}
	Scene::~Scene() {

	}
	void Scene::Initialize(){
		for (Layer* lay : mLayers)
			if (lay != nullptr)
				lay->Initialize();
	}
	void Scene::Update(){
		for (Layer* lay : mLayers)
			if (lay != nullptr)
				lay->Update();
	}
	void Scene::LateUpdate() {
		for (Layer* lay : mLayers)
			if (lay != nullptr)
				lay->LateUpdate();
	}
	void Scene::Render(HDC hdc) {
		for (Layer* lay : mLayers)
			if (lay != nullptr)
				lay->Render(hdc);
	}
	void Scene::OnEnter() {

	}
	void Scene::OnExit() {

	}
	void Scene::AddGameObject(GameObject* gameObj, const eLayerType type)	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}
	void Scene::CreateLayers() {
		mLayers.resize((UINT)eLayerType::Max);
		for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
			mLayers[i] = new Layer();
	}
}