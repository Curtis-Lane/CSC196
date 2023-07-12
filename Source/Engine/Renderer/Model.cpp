#include "Model.h"
#include "Core/FileIO.h"
#include <sstream>

namespace ane {
	bool Model::Load(const std::string& filename) {
		std::string buffer;
		ane::readFile(filename, buffer);

		std::istringstream stream(buffer);

		std::string line;
		std::getline(stream, line);

		int numPoints = std::stoi(line);
		for(int i = 0; i < numPoints; i++) {
			vec2 point;

			stream >> point;

			this->points.push_back(point);
		}

		return true;
	}

	void Model::Draw(Renderer& renderer, const vec2& position, float rotation, float scale) {
		if(points.empty()) {
			return;
		}

		for(size_t i = 0; i < (points.size() - 1); i++) {
			vec2 p1 = (points[i] * scale).Rotate(rotation) + position;
			vec2 p2 = (points[i + 1] * scale).Rotate(rotation) + position;

			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
}