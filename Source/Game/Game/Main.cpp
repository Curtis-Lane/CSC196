#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
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
	ane::seedRandom((unsigned int) time(nullptr));
	ane::setFilePath("assets");

	ane::globalRenderer.Initialize();
	ane::globalRenderer.CreateWindow("CSC196", 800, 600);

	ane::globalInputSystem.Initialize();

	ane::globalAudioSystem.Initialize();
	ane::globalAudioSystem.AddAudio("hiss3", "hiss3.wav");

	//std::vector<ane::vec2> points{{0, 0}, {0, 10}, {10, 0}, {0, 0}};
	ane::Model model;
	model.Load("creeper.txt");
	
	std::vector<Star> stars;

	for(int i = 0; i < 5000; i++) {
		ane::Vector2 pos(ane::Vector2(ane::random(ane::globalRenderer.GetWidth()), ane::random(ane::globalRenderer.GetHeight())));
		ane::Vector2 vel(ane::randomf(100, 250), 0.0f);

		stars.push_back(Star(pos, vel));
	}
	
	ane::Scene scene;

	scene.Add(new Player(200.0f, ane::Pi, {{400, 300}, 0.0f, 10.0f}, model));

	for(int i = 0; i < 10; i++) {
		Enemy* enemy = new Enemy(300, ane::DegreesToRadians(180.0f), {{ane::random(ane::globalRenderer.GetWidth()), ane::random(ane::globalRenderer.GetHeight())}, ane::randomf(ane::TwoPi), 6}, model);
		scene.Add(enemy);
	}

	// Main game loop
	bool quit = false;
	//ane::vec2 mouseCoords{0, 0};
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

		/*
		ane::globalRenderer.SetColor(ane::random(0, 255), 255, 0, 0);

		player.Draw(ane::globalRenderer);

		for(Enemy& enemy : enemies) {
			ane::globalRenderer.SetColor(ane::random(0, 100), ane::random(0, 100), ane::random(0, 100), 0);
			enemy.Draw(ane::globalRenderer);
		}
		*/

		ane::globalRenderer.SetColor(ane::random(0, 255), 255, 0, 0);

		scene.Draw(ane::globalRenderer);

		//model.Draw(ane::globalRenderer, transform.position, transform.rotation, transform.scale);

		
		for(Star& star : stars) {
			star.Update(ane::globalRenderer.GetWidth(), ane::globalRenderer.GetHeight());

			ane::globalRenderer.SetColor(ane::random(0, 255), ane::random(0, 255), ane::random(0, 255), 0);
			star.Draw(ane::globalRenderer);
		}
		
		ane::globalRenderer.EndFrame();
	}
	

	/*
	ane::memoryTracker.DisplayInfo();
	int* intPtr = new int;
	ane::memoryTracker.DisplayInfo();
	delete intPtr;
	ane::memoryTracker.DisplayInfo();

	ane::Time timer;
	for(int i = 0; i < 1000000; i++) {}
	std::cout << timer.GetElapsedSeconds() << std::endl;

	std::chrono::time_point start = std::chrono::high_resolution_clock::now();
	for(int i = 0; i < 10000000; i++) {}
	std::chrono::time_point end = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
	*/

	/*
	std::cout << ane::getFilePath() << std::endl;
	ane::setFilePath("Assets");
	std::cout << ane::getFilePath() << std::endl;

	size_t size = 0;
	ane::getFileSize("game.txt", size);
	std::cout << size << "\n" << std::endl;

	std::string buffer = "";
	ane::readFile("game.txt", buffer);
	std::cout << buffer << "\n" << std::endl;

	ane::seedRandom((unsigned int) time(nullptr));
	for (int i = 0; i < 10; i++) {
		std::cout << ane::random(10, 20) << std::endl;
	}
	*/
	return 0;
}