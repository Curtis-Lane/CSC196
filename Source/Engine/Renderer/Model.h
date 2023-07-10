#pragma once

#include <vector>
#include "Core/Vector2.h"
#include "Renderer.h"

namespace ane {
	class Model {
		public:
			Model() = default;
			Model(const std::vector<vec2>& points) : points{points} {;}

			void Draw(Renderer& renderer);

		private:
			std::vector<vec2> points;
	};
}