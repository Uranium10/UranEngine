#pragma once

#include "commonInclude.h"
#include "urEntity.h"

namespace ur {
	class Scene : public Entity{
	public:
		Scene();
		~Scene();

		void setName(const std::wstring& name);
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:

	}; 
}

