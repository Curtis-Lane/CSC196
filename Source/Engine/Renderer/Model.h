#pragma once

#include <vector>
#include "Core/Vector2.h"
#include "Renderer.h"

namespace ane {
	class Model {
		public:
			Model() = default;
			Model(const std::vector<vec2>& points) : points{points} {;}

			bool Load(const std::string& filename);
			void Draw(Renderer& renderer, const vec2& position, float scale);

		private:
			std::vector<vec2> points;
	};
}