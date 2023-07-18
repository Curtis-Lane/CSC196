#pragma once

#include <memory>

namespace ane {
	struct MemoryAllocation {
		void* address;
		size_t size;
		MemoryAllocation* next;
	};

	class MemoryTracker {
		public:
			void Add(void* address, size_t size);
			void Remove(void* address, size_t size);
			void DisplayInfo();

		private:
			size_t bytesAllocated = 0;
			size_t numAllocations = 0;
	};

	extern MemoryTracker globalMemoryTracker;
}