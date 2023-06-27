#pragma once

#include <random>

namespace ane {
	void seedRandom(unsigned int seed) {srand(seed);}
	int random() {return rand();}
	int random(unsigned int max) {return rand() % max;} // 0 - (max - 1)
	int random(unsigned int min, unsigned int max) {return min + random((max + 1) - min);} // max - min
}