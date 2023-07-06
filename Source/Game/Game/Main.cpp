#include <iostream>
#include <vector>
#include "Core/Core.h"
#include "Renderer/Renderer.h"

class Star {
	public:
		ane::Vector2 pos;
		ane::Vector2 vel;

	public:
		Star(const ane::Vector2& pos, const ane::Vector2& vel) : pos{pos}, vel{vel} {}

		void Update(int width, int height) {
			this->pos += this->vel;

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

	ane::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	std::vector<Star> stars;

	for(int i = 0; i < 5000; i++) {
		ane::Vector2 pos(ane::Vector2(ane::random(renderer.GetWidth()), ane::random(renderer.GetHeight())));
		ane::Vector2 vel(ane::randomf(1, 4), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	while(true) {
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		for(Star& star : stars) {
			star.Update(renderer.GetWidth(), renderer.GetHeight());

			renderer.SetColor(ane::random(0, 255), ane::random(0, 255), ane::random(0, 255), 0);
			star.Draw(renderer);
			//renderer.DrawPoint(star.pos.x, star.pos.y);
		}

		//for(int i = 0; i < 1000; i++) {
		//	ane::Vector2 pos(ane::random(renderer.GetWidth()), ane::random(renderer.GetHeight()));

		//	renderer.SetColor(ane::random(0, 255), ane::random(0, 255), ane::random(0, 255), 0);
		//	renderer.DrawPoint(pos.x, pos.y);
		//	//renderer.DrawLine(ane::random(0, renderer.GetWidth()), ane::random(0, renderer.GetHeight()), ane::random(0, renderer.GetWidth()), ane::random(0, renderer.GetHeight()));
		//}

		renderer.EndFrame();
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