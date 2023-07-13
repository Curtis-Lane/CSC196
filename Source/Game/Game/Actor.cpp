#include "Actor.h"

void Actor::Draw(ane::Renderer& renderer) {
	this->model.Draw(renderer, this->transform);
}
