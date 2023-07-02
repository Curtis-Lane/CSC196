#include <iostream>
#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"

//using namespace std;

int main() {
	ane::CreateWindow("CSC196", 800, 600);
	std::cin.get();

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
}