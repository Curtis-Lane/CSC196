#include "Scene.h"

#include "Renderer/Renderer.h"
#include "Actor.h"

namespace ane {
	void Scene::Update(float deltaTime) {
		for(Actor* actor : this->actors) {
			actor->Update(deltaTime);
		}
	}

	void Scene::Draw(Renderer& renderer) {
		for(Actor* actor : this->actors) {
			actor->Draw(renderer);
		}
	}

	void Scene::Add(Actor* actor) {
		actor->scene = this;
		this->actors.push_back(actor);
	}

	void Scene::Remove(Actor* actor) {
		this->actors.remove(actor);
	}

	void Scene::RemoveAll() {
		this->actors.clear();
	}
}