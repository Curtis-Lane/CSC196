#pragma once

#include <random>

namespace ane {
	void seedRandom(unsigned int seed) {srand(seed);}
	int random() {return rand();}
	int random(unsigned int max) {return rand() % max;} // 0 - (max - 1)
	int random(unsigned int min, unsigned int max) {return min + random((max + 1) - min);} // max - min

	float randomf() {return ((float) random()) / RAND_MAX;}
	float randomf(float max) {return randomf() * max;}
	float randomf(float min, float max) {return min + (randomf() * (max - min));}
}