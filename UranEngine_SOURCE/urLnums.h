#pragma once

namespace ur::enums {
	enum class eComponentType {
		Script,
		Transform,
		SpriteRenderer,
		Animator,
		Camera,
		End,
	};
	enum class eLayerType {
		None,
		Background,
		// Tree, character..
		Animal,
		Player,
		Particle,
		Max = 16,
	};

	enum class eResourceType {
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};
}