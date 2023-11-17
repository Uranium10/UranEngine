#pragma once
#include "commonInclude.h"

// ������� ���ϰ� ���ֱ� ���� Ŭ������ ����� ��ӽ�Ŵ
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

