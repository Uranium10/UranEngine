#pragma once
#include "urEntity.h"
#include "commonInclude.h"

namespace ur {
	class Resource abstract : public Entity
	{
	public:
		// ��ӹ޾ƾ� �Ѵٸ� �Ҹ��ڿ� virtual ���
		Resource(enums::eResourceType type);
		virtual ~Resource();
		// fromfile�� ���� �޸𸮿� �̹����� �ø� �Լ�
		// ���� �����Լ�. ���� �޸� �Ҵ��� �Ұ���������. - �� �Լ��� �ϳ��� �ִٸ� �߻�Ŭ����
		// ��ӹ޾Ƽ��� �� �� �����Ƿ� ������ �ʿ� ����
		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}
