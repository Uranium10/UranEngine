#pragma once

namespace ur::enums {
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