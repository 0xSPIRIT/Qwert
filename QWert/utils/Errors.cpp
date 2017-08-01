#include "Errors.h"

void Errors::FATAL(const std::string& message) {
	std::cerr << "FATAL ERROR: " << message << std::endl;
	std::cout << "Press enter to break the program..." << std::endl;
	std::cin.get();
	exit(EXIT_FAILURE);
}

void Errors:: WARN(const std::string& message) {
	std::cerr << "Warning: " << message << std::endl;
}
