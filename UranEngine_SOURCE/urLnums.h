#pragma once

namespace ur::enums {
	enum class eComponentType {
		Script,
		Transform,
		SpriteRenderer,
		Camera,
		End,
	};
	enum class eLayerType {
		None,
		Background,
		// Tree, character..
		Player,
		Max = 16,
	};

	enum class eResourceType {
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}