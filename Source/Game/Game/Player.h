#pragma once

#include "Framework/Actor.h"

class Player : public ane::Actor {
	public:
		Player(float speed, float turnRate, const ane::Transform& transform, const ane::Model& model) :
			ane::Actor(transform, model) {
			this->speed = speed;
			this->turnRate = turnRate;
		}

		void Update(float deltaTime) override;

	private:
		float speed = 0.0f;
		float turnRate = 0.0f;
};