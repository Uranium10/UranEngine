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

		// 애니메이션 이름, 한 줄(시트), 좌측상단 좌표, 한 프레임당 사이즈, 오프셋, 프레임수, 프레임당 시간
		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spritesheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLength
			, float duration);
		Animation* FindAnimation(const std::wstring& name);
		// 함수의 전달인자는 오른쪽부터 읽어오므로, 디폴트 값 설정할 인자는 오른쪽에 몰아줘야 함
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
		// 지금 재생되는 애니메이션을 루프할 것인가
		bool mbLoop;

		std::map<std::wstring, Events*> mEvents;
	};
}