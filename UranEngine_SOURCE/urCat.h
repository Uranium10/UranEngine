#pragma once
#include "GameObject.h"

namespace ur {
	class Cat : public GameObject
	{
	public:
		Cat();
		~Cat();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		//df
	};
}

