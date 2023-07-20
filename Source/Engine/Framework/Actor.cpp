#include "Actor.h"

namespace ane {
	void Actor::Update(float deltaTime) {
		if(this->lifeSpan != -1.0f) {
			this->lifeSpan -= deltaTime;

			if(this->lifeSpan <= 0.0f) {
				this->destroyed = true;
			}
		}
	}

	void Actor::Draw(ane::Renderer& renderer) {
		this->model->Draw(renderer, this->transform);
	}
}
