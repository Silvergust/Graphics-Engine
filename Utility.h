#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//#include "Error.h"

namespace Engine {
	std::string readFile(const std::string& fileName) {
		std::stringstream stringStream;
		std::ifstream file;

		try {
			file.open(fileName, std::ios::in);

			if (!file.fail()) {
				stringStream << file.rdbuf();
				std::cout << "Read file " << fileName << ", its contents are " << stringStream.str() << "\n";
			}
			else {
				std::cout << "Failure to read file " << fileName << "\n";
			}

			file.close();
		}
		catch (std::exception exception) {
			std::cerr << "Failed to load file " << fileName << "\n";
		}

		return stringStream.str();
	}
}