#include <iostream>
#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"

//using namespace std;

int main() {
	int* intPtr = new int;

	delete intPtr;

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
}