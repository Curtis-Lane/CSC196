#pragma once

#include "Framework/Actor.h"

class Enemy : public ane::Actor {
	public:
	Enemy(float speed, float turnRate, const ane::Transform& transform, const ane::Model& model) :
		ane::Actor(transform, model) {
		this->speed = speed;
		this->turnRate = turnRate;
		this->fireRate = 2.0f;
		this->fireTimer = this->fireRate;
	}

	void Update(float deltaTime) override;

	private:
		float speed = 0.0f;
		float turnRate = 0.0f;

		float fireRate = 0.0f;
		float fireTimer = 0.0f;
};