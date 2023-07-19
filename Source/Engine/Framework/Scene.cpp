#include "Scene.h"

#include "Renderer/Renderer.h"
#include "Actor.h"

namespace ane {
	void Scene::Update(float deltaTime) {
		/*
		for(std::unique_ptr<Actor>& actor : this->actors) {
			actor->Update(deltaTime);
		}
		*/

		// Remove destroyed actors
		auto iter = this->actors.begin();
		while(iter != this->actors.end()) {
			(*iter)->Update(deltaTime);

			if((*iter)->destroyed) {
				iter = this->actors.erase(iter);
			} else {
				iter++;
			}
		}
	}

	void Scene::Draw(Renderer& renderer) {
		for(std::unique_ptr<Actor>& actor : this->actors) {
			actor->Draw(renderer);
		}
	}

	void Scene::Add(std::unique_ptr<Actor> actor) {
		actor->scene = this;
		this->actors.push_back(std::move(actor));
	}

	void Scene::RemoveAll() {
		this->actors.clear();
	}
}