#pragma once

#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"

namespace ane {
	class Actor {
		public:
			Actor() = default;
			Actor(const ane::Transform& transform, const ane::Model& model) {this->transform = transform; this->model = model;}

			virtual void Update(float deltaTime);
			virtual void Draw(ane::Renderer& renderer);

			class Scene* scene = nullptr;

			friend class Scene;
			ane::Transform transform;

		protected:
			bool destroyed = false;
			float lifeSpan = -1.0f;

			ane::Model model;
	};
}