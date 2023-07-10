#include "Model.h"

namespace ane {
	void Model::Draw(Renderer& renderer) {
		for(size_t i = 0; i < (points.size() - 1); i++) {
			vec2 p1 = points[i];
			vec2 p2 = points[i + 1];

			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
}