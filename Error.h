#pragma once

#include <string>
#include <iostream>

#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

void fatalError(std::string string);

void warning_(std::string string, const char *file, int line);
#define warning(string) warning_(string, __FILE__, __LINE__);

GLenum glCheckError_(const char *file, int line);
#define glCheckError() glCheckError_(__FILE__, __LINE__)

