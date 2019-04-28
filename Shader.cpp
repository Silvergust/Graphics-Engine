#include "Shader.h"
#include "Utility.h"
#include <GL\glew.h>
#include <iostream>
#include "Error.h"

namespace Engine {
	ShaderProgram::ShaderProgram()
	{
	}


	ShaderProgram::~ShaderProgram()
	{
	}

	bool ShaderProgram::setup(const char* vertexShaderFileName, const char* fragmentShaderFileName) {
		_id = glCreateProgram();
		if (!_id) {
			std::cerr << "glCreateProgram() failure\n";
			return false;
		}
		GLuint vertexShader;
		loadShader(vertexShaderFileName, VERTEX, vertexShader);
		glAttachShader(_id, vertexShader);

		GLuint fragmentShader;
		loadShader(fragmentShaderFileName, FRAGMENT, fragmentShader);
		glAttachShader(_id, fragmentShader);

		glLinkProgram(_id);

		checkLinkError(_id);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		glUseProgram(_id);
	}

	bool ShaderProgram::loadShader(const char* fileName, Shader_Type type, GLuint& shader) {
		//GLuint shader;

		switch (type) {
		case VERTEX:
			shader = glCreateShader(GL_VERTEX_SHADER);
			break;
		case FRAGMENT:
			shader = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		default:
			fatalError("Invalid Shader_Type argument in Shader::load().\n");
		}

		std::string shaderString = readFile(fileName);
		const GLchar* shaderSource = shaderString.c_str();

		glShaderSource(shader, 1, &shaderSource, NULL);

		glCompileShader(shader);

		checkCompileError(shader);

		return true;
	}

	void ShaderProgram::use() {
		glUseProgram(_id);
	}

	//bool ShaderProgram::checkError(GLuint shader, int errorCode) {
	//	if (errorCode == GL_FALSE) {
	//		GLint length = 0;
	//		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

	//		std::string log(length, ' ');
	//		glGetProgramInfoLog(shader, length, &length, &log[0]);
	//		std::cerr << "Failed to compile shader with error code "
	//			<< log << "\n";
	//		return false;
	//	}
	//	return true;
	//}

	void ShaderProgram::checkCompileError(GLuint shader) {
		int errorCode = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &errorCode);
		if (errorCode == GL_FALSE) {
			GLint length = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

			std::string errorLog(length, ' ');
			glGetShaderInfoLog(shader, length, &length, &errorLog[0]);
			std::cerr << "Shader compilation error. Error log: " << errorLog << "\n";
		}
	}

	void ShaderProgram::checkLinkError(GLuint id) {
		int errorCode;
		glGetProgramiv(id, GL_LINK_STATUS, &errorCode);
		if (errorCode == GL_FALSE) {
			GLint length = 0;
			glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);

			std::string errorLog(length, ' ');
			glGetProgramInfoLog(id, length, &length, &errorLog[0]);
			std::cerr << "Program linking error. Error log: " << errorLog << "\n";
		}
	}
}