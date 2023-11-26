#pragma once
#include "commonInclude.h"

namespace ur {
	class Entity {
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }

	private:
		// 디버깅을 쉽게 하기 위해 이름을 지어준다. 모든 개체들은 이 이름을 가지도록 상속시켜줌
		std::wstring mName;
	};
}

