#pragma once
#include "urComponent.h"
#include "urAnimation.h"

namespace ur {
	class Animator : public Component {
	public:
		struct Event {
			void operator= (std::function<void()> func) {
				mEvent = std::move(func);
			}
			std::function<void()> mEvent;
			void operator() () {
				if (mEvent)
					mEvent();
			}
		};
		struct Events {
			//Event
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};
		Animator(enums::eComponentType type = enums::eComponentType::Animator);
		~Animator ();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		// �ִϸ��̼� �̸�, �� ��(��Ʈ), ������� ��ǥ, �� �����Ӵ� ������, ������, �����Ӽ�, �����Ӵ� �ð�
		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spritesheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLength
			, float duration);
		Animation* FindAnimation(const std::wstring& name);
		// �Լ��� �������ڴ� �����ʺ��� �о���Ƿ�, ����Ʈ �� ������ ���ڴ� �����ʿ� ������� ��
		void PlayAnimation(const std::wstring& name, bool loop = true, int index = 0);
		int GetIndex() { return mActiveAnimation->GetIndex(); }
		
		Events* FindEvents(const std::wstring& name);

		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);

		bool IsCompleteAnimation() { return mActiveAnimation->IsComplete(); }
	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		// ���� ����Ǵ� �ִϸ��̼��� ������ ���ΰ�
		bool mbLoop;

		std::map<std::wstring, Events*> mEvents;
	};
}