#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <string>
#include <fstream>

enum Shadertype {vertex, fragment, tessellation, pixel};
class Shader
{
	GLuint shaderID;

	Shadertype currentType;
public:
	void loadFromFile(std::string str);
	void loadFromString(std::string str);
	void destroyShader();
	GLuint getShaderID();
	Shadertype getCurrentType();

	Shader() = delete;
	Shader(Shadertype type);
	~Shader();
};

