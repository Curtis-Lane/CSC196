#include "Memory.h"
#include <iostream>

ane::MemoryTracker ane::memoryTracker;

void* operator new (size_t size) {
	void* ptr = malloc(size);

	ane::memoryTracker.Add(ptr, size);
	//std::cout << "allocated: " << size << "\n" << std::endl;

	return ptr;
}

void operator delete (void* address, size_t size) {
	ane::memoryTracker.Remove(address, size);

	//std::cout << "deallocated: " << size << "\n" << std::endl;

	free(address);
}

namespace ane {
	void MemoryTracker::Add(void* address, size_t size) {
		this->bytesAllocated += size;
		this->numAllocations++;
	}

	void MemoryTracker::Remove(void* address, size_t size) {
		this->bytesAllocated -= size;
		this->numAllocations--;
	}

	void MemoryTracker::DisplayInfo() {
		std::cout << "current bytes allocated: " << this->bytesAllocated << std::endl;
		std::cout << "current number of allocations: " << this->numAllocations << std::endl;
	}
}