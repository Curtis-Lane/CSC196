#pragma once

#include "Framework/Actor.h"

class Enemy : public ane::Actor {
	public:
	Enemy(float speed, float turnRate, const ane::Transform& transform, const ane::Model& model) :
		ane::Actor(transform, model) {
		this->speed = speed;
		this->turnRate = turnRate;
	}

	void Update(float deltaTime) override;

	private:
	float speed = 0.0f;
	float turnRate = 0.0f;
};