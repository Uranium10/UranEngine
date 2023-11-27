#pragma once
#include"urLayer.h"
#include"GameObject.h"
#include"urComponent.h"
#include"urSceneManager.h"
#include"urScene.h"
#include"urTransform.h"

namespace ur::object {
	template <typename T>
	static T* Instantiate(enums::eLayerType type) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPos(Vector2::ZERO);

		return gameObject;
	}
	template <typename T>
	static T* Instantiate(enums::eLayerType type, math::Vector2 position) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPos(position);

		return gameObject;
	}
}