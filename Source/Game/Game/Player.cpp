#include "Player.h"

#include "Input/InputSystem.h"
#include "Framework/Scene.h"
#include "Rocket.h"

void Player::Update(float deltaTime) {
	float rotate = 0.0f;
	if(ane::globalInputSystem.GetKeyDown(SDL_SCANCODE_A)) {
		rotate += -1.0f;
	} else if(ane::globalInputSystem.GetKeyDown(SDL_SCANCODE_D)) {
		rotate += 1.0f;
	}
	this->transform.rotation += rotate * turnRate * ane::globalTime.GetDeltaTime();

	float thrust = 0.0f;
	if(ane::globalInputSystem.GetKeyDown(SDL_SCANCODE_W)) {
		thrust = 1;
	} else if(ane::globalInputSystem.GetKeyDown(SDL_SCANCODE_S)) {
		thrust = -1;
	} else {
		thrust = 0;
	}

	// Fire weapon
	if(ane::globalInputSystem.GetKeyDown(SDL_SCANCODE_SPACE) && !ane::globalInputSystem.GetPreviousKeyDown(SDL_SCANCODE_SPACE)) {
		ane::Transform rocketTransform(this->transform.position, this->transform.rotation, this->transform.scale / 2);
		std::unique_ptr<Rocket> rocket = std::make_unique<Rocket>(400.0f, rocketTransform, this->model);
		this->scene->Add(std::move(rocket));
	}

	ane::vec2 forward = ane::vec2(0, -1).Rotate(this->transform.rotation);
	this->transform.position += forward * speed * thrust * ane::globalTime.GetDeltaTime();
	this->transform.position.x = ane::Wrap(this->transform.position.x, static_cast<float> (ane::globalRenderer.GetWidth()));
	this->transform.position.y = ane::Wrap(this->transform.position.y, static_cast<float> (ane::globalRenderer.GetHeight()));
}
 