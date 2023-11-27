#pragma once
#include "urEntity.h"
#include "commonInclude.h"

namespace ur {
	class Resource abstract : public Entity
	{
	public:
		// 상속받아야 한다면 소멸자에 virtual 사용
		Resource(enums::eResourceType type);
		virtual ~Resource();
		// fromfile을 통해 메모리에 이미지를 올릴 함수
		// 순수 가상함수. 실제 메모리 할당이 불가능해진다. - 이 함수가 하나라도 있다면 추상클래스
		// 상속받아서만 쓸 수 있으므로 구현부 필요 없음
		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}
