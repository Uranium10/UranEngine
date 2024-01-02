#pragma once
#include "urComponent.h"
#include "urTexture.h"

namespace ur {
	using namespace math;
	class SpriteRenderer : public Component {
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void SetTexture(graphics::Texture* texture) { 
			mTexture = texture;
			mView.x = mTexture->GetWidth(); 
			mView.y = mTexture->GetHeight(); 
		}
		void SetSize(Vector2 size) { mSize = size; }
		void SetView(Vector2 leftTop, Vector2 view) { mLeftTop = leftTop; mView= view; }

		//void SetSize(Vector2 size) { mSize = size; }
	private:
		graphics::Texture* mTexture;
		Vector2 mSize;
		Vector2 mLeftTop;
		Vector2 mView;
	};
}

