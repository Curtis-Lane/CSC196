#include <iostream>
#include "Core/Random.h"
#include "Core/FileIO.h"

using namespace std;

int main() {
	std::cout << ane::getFilePath() << std::endl;

	ane::seedRandom((unsigned int) time(nullptr));
	for (int i = 0; i < 10; i++) {
		std::cout << ane::random(10, 20) << std::endl;
	}
}