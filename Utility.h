#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

namespace Engine {
	std::string readFile(const std::string& fileName) {
		std::stringstream stringStream;
		std::ifstream file;

		try {
			file.open(fileName, std::ios::in);

			if (!file.fail()) {
				stringStream << file.rdbuf();
				std::cout << "Read file " << fileName << "\n";
			}
			else {
				std::cout << "Failed to read file " << fileName << "\n";
			}

			file.close();
		}
		catch (std::exception exception) {
			std::cerr << "Failed to load file " << fileName << "\n";
		}

		return stringStream.str();
	}
}