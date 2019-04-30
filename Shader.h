#pragma once

#include <string>
#include <GL\glew.h>
#include <glm\glm.hpp>

namespace Engine {

	class ShaderProgram
	{
	public:
		ShaderProgram();
		~ShaderProgram();

		bool setup(const char* vertexShaderFileName, const char* fragmentShaderFileName);

		enum Shader_Type { VERTEX, FRAGMENT };

		bool loadShader(const char* fileName, Shader_Type type, GLuint& shader);

		void use();

		void setUniform(const std::string &name, const glm::mat4 &mat);
	private:
		GLuint _id;

		void checkCompileError(GLuint shader);
		void checkLinkError(GLuint shader);
	};

}