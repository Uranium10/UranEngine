#pragma once

namespace ur::enums {
	enum class eComponentType {
		Script,
		Transform,
		SpriteRenderer,
		PartAnimator,
		Animator,
		Camera,
		End,
	};
	enum class eLayerType {
		None,
		FarBackground,
		Background,
		AnimatedBackGround,
		Terrain,
		AnimatedTerrain,
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