#include "Enemy.h"
#include "Player.h"
#include "Rocket.h"
#include "Framework/Scene.h"

void Enemy::Update(float deltaTime) {
	Actor::Update(deltaTime);

	Player* player = this->scene->GetActor<Player>();
	if(player != nullptr) {
		ane::Vector2 direction = player->transform.position - this->transform.position;
		this->transform.rotation = direction.Angle() + ane::HalfPi;
	}

	ane::vec2 forward = ane::vec2(0, -1).Rotate(this->transform.rotation);
	this->transform.position += forward * speed * ane::globalTime.GetDeltaTime();
	this->transform.position.x = ane::Wrap(this->transform.position.x, static_cast<float> (ane::globalRenderer.GetWidth()));
	this->transform.position.y = ane::Wrap(this->transform.position.y, static_cast<float> (ane::globalRenderer.GetHeight()));

	this->fireTimer -= deltaTime;
	if(this->fireTimer <= 0) {
		this->fireTimer = this->fireRate;
		// Fire weapon
		ane::Transform rocketTransform(this->transform.position, this->transform.rotation, this->transform.scale * 0.66f);
		std::unique_ptr<Rocket> rocket = std::make_unique<Rocket>(400.0f, rocketTransform, this->model);
		rocket->tag = "Enemy";
		this->scene->Add(std::move(rocket));
	}
}

void Enemy::OnCollision(Actor* other) {
	if(dynamic_cast<Rocket*>(other) != nullptr && other->tag == "Player") {
		health -= 10;
	}
	if(health <= 0) {
		this->destroyed = true;
	}
}
