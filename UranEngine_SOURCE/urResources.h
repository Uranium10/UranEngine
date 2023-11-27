#pragma once
#include "urResource.h"

namespace ur {
	// resource���� ������. GameObject ���� ���� ���ҽ��� ���� �ε��ϸ� ����.
	class Resources
	{
	public:
		template<typename T>
		static T* Find(const std::wstring& key) {
			auto iter = mResources.find(key);
			if (iter == mResources.end())
				return nullptr;

			return dynamic_cast<T*>(iter->second);
		}

		template<typename T>
		static T* Load(const std::wstring& key, const std::wstring& path) {
			T* resource = Find<T>(key);
			if (resource != nullptr)
				return resource;

			resource = new T();
			// HRESULT�� ��ȯ�� ����ϸ� ��� ������ ����
			if (FAILED(resource->Load(path)))
				assert(false);

			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));
		}
	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}