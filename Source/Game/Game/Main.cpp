#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Framework/Scene.h"
#include "Player.h"
#include "Enemy.h"

#include <iostream>
#include <vector>

class Star {
	public:
		ane::Vector2 pos;
		ane::Vector2 vel;

	public:
		Star(const ane::Vector2& pos, const ane::Vector2& vel) : pos{pos}, vel{vel} {}

		void Update(int width, int height) {
			this->pos += this->vel * ane::globalTime.GetDeltaTime();

			if(this->pos.x > width) {
				this->pos.x = 0;
			} else if(this->pos.x < 0) {
				this->pos.x = width;
			}

			if(this->pos.y > height) {
				this->pos.y = 0;
			} else if(this->pos.y < 0) {
				this->pos.y = height;
			}
		}

		void Draw(ane::Renderer& renderer) {
			renderer.DrawPoint(this->pos.x, this->pos.y);
		}
};

int main(int argc, char* argv[]) {
	ane::MemoryTracker::Initialize();

	int* p = new int;
	delete p;

	ane::seedRandom((unsigned int) time(nullptr));
	ane::setFilePath("assets");

	ane::globalRenderer.Initialize();
	ane::globalRenderer.CreateWindow("CSC196", 800, 600);

	ane::globalInputSystem.Initialize();

	ane::globalAudioSystem.Initialize();
	ane::globalAudioSystem.AddAudio("hiss3", "hiss3.wav");

	std::shared_ptr<ane::Font> font = std::make_shared<ane::Font>("ArcadeClassic.ttf", 24);

	std::unique_ptr<ane::Text> text = std::make_unique<ane::Text>(font);
	text->Create(ane::globalRenderer, "NEUMONT", ane::Color(1.0f, 1.0f, 1.0f, 1.0f));

	ane::Model model;
	model.Load("creeper.txt");
	
	std::vector<Star> stars;

	for(int i = 0; i < 5000; i++) {
		ane::Vector2 pos(ane::Vector2(ane::random(ane::globalRenderer.GetWidth()), ane::random(ane::globalRenderer.GetHeight())));
		ane::Vector2 vel(ane::randomf(100, 250), 0.0f);

		stars.push_back(Star(pos, vel));
	}
	
	ane::Scene scene;

	std::unique_ptr<Player> player = std::make_unique<Player>(200.0f, ane::Pi, ane::Transform(ane::vec2(400, 300), 0.0f, 10.0f), model);

	scene.Add(std::move(player));

	for(int i = 0; i < 10; i++) {
		std::unique_ptr enemy = std::make_unique<Enemy>(ane::randomf(75.0f, 150.0f), ane::Pi, ane::Transform(ane::vec2(ane::random(ane::globalRenderer.GetWidth()), ane::random(ane::globalRenderer.GetHeight())), ane::randomf(ane::TwoPi), 6), model);
		scene.Add(std::move(enemy));
	}

	// Main game loop
	bool quit = false;
	while(!quit) {
		ane::globalTime.Tick();

		ane::globalInputSystem.Update();

		ane::globalAudioSystem.Update();
		 
		if(ane::globalInputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}

		scene.Update(ane::globalTime.GetDeltaTime());

		ane::globalRenderer.SetColor(0, 0, 0, 0);
		ane::globalRenderer.BeginFrame();

		ane::globalRenderer.SetColor(ane::random(0, 255), 255, 0, 0);

		scene.Draw(ane::globalRenderer);

		text->Draw(ane::globalRenderer, 400, 300);
		
		for(Star& star : stars) {
			star.Update(ane::globalRenderer.GetWidth(), ane::globalRenderer.GetHeight());

			ane::globalRenderer.SetColor(ane::random(0, 255), ane::random(0, 255), ane::random(0, 255), 0);
			star.Draw(ane::globalRenderer);
		}
		
		ane::globalRenderer.EndFrame();
	}
	
	stars.clear();
	scene.RemoveAll();

	return 0;
}