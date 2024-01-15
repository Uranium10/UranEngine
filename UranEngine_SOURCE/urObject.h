#pragma once
#include"urLayer.h"
#include"GameObject.h"
#include"urComponent.h"
#include"urSceneManager.h"
#include"urScene.h"
#include"urTransform.h"

namespace ur::object {
	template <typename T>
	static T* Instantiate(enums::eLayerType type, math::Vector2 position = Vector2::ZERO) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		gameObject->SetLayer(type);
		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPos(position);

		return gameObject;
	}
}