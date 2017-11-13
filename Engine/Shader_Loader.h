#pragma once
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
#include<string>

namespace Core {
	class Shader_Loader
	{
	private:
		std::string readShader(char *fileName);
		GLuint createShader(GLenum shaderType, std::string source, char* shaderName);
	public:
		Shader_Loader(void);
		~Shader_Loader(void);
		GLuint createProgram(char* VertexShaderFilename, char* FragmentShaderFilename);
	};
}


