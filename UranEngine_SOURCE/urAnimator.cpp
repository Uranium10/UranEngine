#include "urAnimator.h"
#include "urComponent.h"

namespace ur {
	Animator::Animator(enums::eComponentType type)
		: Component(type)
		, mAnimations{}
		, mActiveAnimation(nullptr)
		, mbLoop(false)
		, mEvents{} {}
	Animator::~Animator(){
		for (auto& iter : mEvents) {
			delete iter.second;
			iter.second = nullptr;
		}
		for (auto& iter : mAnimations) {
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void Animator::Initialize(){}
	void Animator::Update() {
		if (mActiveAnimation) {
			mActiveAnimation->Update();
			Events* events = FindEvents(mActiveAnimation->GetName());
			
			if (mActiveAnimation->IsComplete())
			{
				if (events)
					events->completeEvent();
				
				if (mbLoop)
					mActiveAnimation->Reset();
			}
			
		}
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render(HDC hdc) {
		if (mActiveAnimation)
			mActiveAnimation->Render(hdc);
	}
	void Animator::CreateAnimation(const std::wstring& name
		, graphics::Texture* spritesheet
		, Vector2 leftTop, Vector2 size
		, Vector2 offset
		, UINT spriteLength
		, float duration) {
		Animation* animation = nullptr;
		// 이미 해당 이름을 가지고있는 애니메이션이 있는지 확인.
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->SetName(name);
		animation->CreateAnimation(name, spritesheet, leftTop, size, offset, spriteLength, duration);
		animation->SetAnimator(this);

		Events* events = new Events();
		mEvents.insert(std::make_pair(name, events));

		mAnimations.insert(std::make_pair(name, animation));
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		auto iter = mAnimations.find(name);
		if (iter == mAnimations.end())
			return nullptr;
		return iter->second;
	}
	void Animator::PlayAnimation(const std::wstring& name, bool loop, int index) {
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		if (mActiveAnimation) {
			// 원래 있던 애니메이션의 endevent
			Events* currentEvents = FindEvents(mActiveAnimation->GetName());
			if (currentEvents)
				currentEvents->endEvent();
		}

		Events* nextEvents = FindEvents(animation->GetName());
		if (nextEvents)
			nextEvents->startEvent();

		// 이전에 플레이중이었던 애니메이션일 수도 있으니 리셋
		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mActiveAnimation->SetIndex(index);
		mbLoop = loop;
	}
	Animator::Events* Animator::FindEvents(const std::wstring& name) {
		auto iter = mEvents.find(name);
		if (iter == mEvents.end()) {
			return nullptr;
		}
		return iter->second;
	}
	std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->startEvent.mEvent;
	}
	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->completeEvent.mEvent;
	}
	std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->endEvent.mEvent;
	}
}