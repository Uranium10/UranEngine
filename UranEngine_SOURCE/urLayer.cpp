#include "urLayer.h"

namespace ur {
	Layer::Layer() : mGameObjects{} {

	}
	Layer::~Layer() {
		for (GameObject* obj : mGameObjects) {
			if (obj != nullptr)
				delete obj;
				obj = nullptr;
			}
	}
	void Layer::Initialize(){
	}
	void Layer::Update() {
		/*for (GameObject* obj : mGameObjects)
			if (obj != nullptr)
				obj->Update();*/
		for (GameObject* obj : mGameObjects)
			if (obj != nullptr)
				obj->Update();
	}
	void Layer::LateUpdate() {
		for (GameObject* obj : mGameObjects)
			if (obj != nullptr)
				obj->LateUpdate();
	}
	void Layer::Render(HDC hdc) {
		for (GameObject* obj : mGameObjects)
			if (obj != nullptr)
				obj->Render(hdc);
	}
	void Layer::AddGameObject(GameObject* gameObject) {
		if (gameObject != nullptr)
			mGameObjects.push_back(gameObject);
	}
}