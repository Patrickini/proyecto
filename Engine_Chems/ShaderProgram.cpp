#include "ShaderProgram.h"



void ShaderProgram::createProgram()
{
	program = glCreateProgram();
	if (fragment)
		glAttachShader(program, fragment->getShaderID());
	if (vertex)
		glAttachShader(program, vertex->getShaderID());
	if (tessellation)
		glAttachShader(program, tessellation->getShaderID());
	if (pixel)
		glAttachShader(program, pixel->getShaderID());
	glLinkProgram(program);

	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

void ShaderProgram::setShaders(Shader * vert, Shader * frag, Shader * tes, Shader * pix)
{
	vertex = vert;
	fragment = frag;
	tessellation = tes;
	pixel = pix;
}

void ShaderProgram::activateProgram()
{
	glUseProgram(program);
}

GLuint ShaderProgram::getProgram()
{
	return program;
}

ShaderProgram::ShaderProgram()
{
}


ShaderProgram::~ShaderProgram()
{
}
