#pragma once

#include <iostream>
#include <string>

class Errors {
public:
	static void FATAL(const std::string& message);
	static void WARN(const std::string& message);
};