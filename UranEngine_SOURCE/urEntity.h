#pragma once
#include "commonInclude.h"

// 디버깅을 편하게 해주기 위해 클래스를 만들어 상속시킴
namespace ur {
	class Entity {
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; };
	private:
		const std::wstring& mName;
	};
}

