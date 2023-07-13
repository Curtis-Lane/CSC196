#pragma once

#include "Actor.h"

class Enemy : public Actor {
	public:
	Enemy(float speed, float turnRate, const ane::Transform& transform, const ane::Model& model) :
		Actor(transform, model) {
		this->speed = speed;
		this->turnRate = turnRate;
	}

	void Update(float deltaTime) override;

	private:
	float speed = 0.0f;
	float turnRate = 0.0f;
};