#pragma once

#include <list>
#include "Actor.h"

namespace ane {
	class Renderer;

	class Scene {
		public:
			Scene() = default;

			void Update(float deltaTime);
			void Draw(Renderer& renderer);

			void Add(Actor* actor);
			void Remove(Actor* actor);
			void RemoveAll();

			//friend class Actor;

		private:
			std::list<Actor*> actors;
	};
}