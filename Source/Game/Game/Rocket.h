#pragma once

#include "Framework/Actor.h"
#include "Audio/AudioSystem.h"

class Rocket : public ane::Actor {
	public:
	Rocket(float speed, const ane::Transform& transform, const ane::Model& model) :
		ane::Actor(transform, model) {
		this->speed = speed;
		this->lifeSpan = 2.0f;
		ane::globalAudioSystem.PlayOneShot("hiss3");
	}

	void Update(float deltaTime) override;

	private:
	float speed = 0.0f;
	float turnRate = 0.0f;
};