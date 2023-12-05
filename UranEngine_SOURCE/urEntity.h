#pragma once
#include "commonInclude.h"

using namespace ur::math;
namespace ur {
	class Entity {
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }

	private:
		// ������� ���� �ϱ� ���� �̸��� �����ش�. ��� ��ü���� �� �̸��� �������� ��ӽ�����
		std::wstring mName;
	};
}

