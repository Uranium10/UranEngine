#pragma once
#include "urResource.h"
#include "urTexture.h"

namespace ur {
	class Animation : public Resource
	{
	public:
		// �̹��� �ϳ�, �̰��� ���� ���� ��������Ʈ ��Ʈ
		struct  Sprite {
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;
			Sprite() 
				: leftTop(Vector2::ZERO)
				, size(Vector2::ZERO)
				, offset(Vector2::ZERO)
				, duration(0.0f){}
		};

		Animation();
		~Animation();

		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spritesheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLength
			, float duration);
		void Reset();
		bool IsComplete() { return mbComplete; }
		void SetAnimator(class Animator* animator) { mAnimator = animator; }
	private:
		// ������� �ִϸ�����
		class Animator* mAnimator;
		graphics::Texture* mTexture;
		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		float mTime;
		bool mbComplete;
	};
}
