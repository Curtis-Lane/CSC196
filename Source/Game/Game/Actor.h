#pragma once

#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"

class Actor {
	public:
		Actor(const ane::Transform& transform, const ane::Model& model) {this->transform = transform; this->model = model;}

		virtual void Update(float deltaTime) = 0;
		virtual void Draw(ane::Renderer& renderer);

	protected:
		ane::Transform transform;
		ane::Model model;
};