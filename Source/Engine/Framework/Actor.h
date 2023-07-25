#pragma once

#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"

#include <memory>

namespace ane {
	class Actor {
		public:
			Actor() = default;
			Actor(const ane::Transform& transform, std::shared_ptr<Model> model) {this->transform = transform; this->model = model;}

			virtual void Update(float deltaTime);
			virtual void Draw(ane::Renderer& renderer);

			float GetRadius() {return this->model->GetRadius() * this->transform.scale;}
			virtual void OnCollision(Actor* other) {;}

			class Scene* scene = nullptr;

			class Game* game = nullptr;

			friend class Scene;
			ane::Transform transform;
			std::string tag;

		protected:
			bool destroyed = false;
			float lifeSpan = -1.0f;

			std::shared_ptr<Model> model;
	};
}