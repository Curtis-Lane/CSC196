#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
#include <iostream>
#include <vector>
//#include <thread>


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

	ane::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	ane::InputSystem inputSystem;
	inputSystem.Initialize();

	//std::vector<ane::vec2> points{{0, 0}, {0, 10}, {10, 0}, {0, 0}};
	ane::Model model;
	model.Load("creeper.txt");
	
	std::vector<Star> stars;

	for(int i = 0; i < 5000; i++) {
		ane::Vector2 pos(ane::Vector2(ane::random(renderer.GetWidth()), ane::random(renderer.GetHeight())));
		ane::Vector2 vel(ane::randomf(100, 250), 0.0f);

		stars.push_back(Star(pos, vel));
	}
	


	ane::vec2 position(400, 300);
	float speed = 200.0f;

	// Main game loop
	bool quit = false;
	ane::vec2 mouseCoords{0, 0};
	while(!quit) {
		ane::globalTime.Tick();

		inputSystem.Update();
		if(inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}

		ane::vec2 direction;
		if(inputSystem.GetKeyDown(SDL_SCANCODE_W)) {
			direction.y = -1;
		} else if(inputSystem.GetKeyDown(SDL_SCANCODE_S)) {
			direction.y = 1;
		}
		if(inputSystem.GetKeyDown(SDL_SCANCODE_A)) {
			direction.x = -1;
		} else if(inputSystem.GetKeyDown(SDL_SCANCODE_D)) {
			direction.x = 1;
		}

		position += direction * speed * ane::globalTime.GetDeltaTime();

		/*
		if(inputSystem.GetMouseButtonDown(0)) {
			std::cout << "Left Mouse Pressed" << std::endl;
		} else if(inputSystem.GetMouseButtonDown(1)) {
			std::cout << "Middle Mouse Pressed" << std::endl;
		} else if(inputSystem.GetMouseButtonDown(2)) {
			std::cout << "Right Mouse Pressed" << std::endl;
		}

		if(mouseCoords.x != inputSystem.GetMousePosition().x && mouseCoords.y != inputSystem.GetMousePosition().y) {
			std::cout << "Mouse X: " << inputSystem.GetMousePosition().x << std::endl;
			std::cout << "Mouse Y: " << inputSystem.GetMousePosition().y << std::endl;
		}

		mouseCoords = inputSystem.GetMousePosition();
		*/

		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		renderer.SetColor(ane::random(0, 255), 255, 0, 0);
		model.Draw(renderer, position, 10.0f);

		
		for(Star& star : stars) {
			star.Update(renderer.GetWidth(), renderer.GetHeight());

			renderer.SetColor(ane::random(0, 255), ane::random(0, 255), ane::random(0, 255), 0);
			star.Draw(renderer);
			//renderer.DrawPoint(star.pos.x, star.pos.y);
		}
		
		renderer.EndFrame();

		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
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