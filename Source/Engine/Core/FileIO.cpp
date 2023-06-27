#include "FileIO.h"

namespace ane {
	std::string getFilePath() {
		return std::filesystem::current_path().string();
	}
}