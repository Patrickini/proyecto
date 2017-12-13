#pragma once
#include "shader.h"
class ShaderProgram
{
private:
	GLuint program;
	Shader* vertex;
	Shader* fragment;
	Shader* tessellation;
	Shader* pixel;

	
	

public:
	void createProgram();
	void setShaders(Shader* vert, Shader*frag, Shader* tes, Shader* pix);
	void activateProgram();
	GLuint getProgram();

	ShaderProgram();
	~ShaderProgram();
};

