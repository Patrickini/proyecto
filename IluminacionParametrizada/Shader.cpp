#include "Shader.h"



void Shader::loadFromFile(std::string str)
{
	std::string theFile;
	std::string line;
	std::ifstream myfile(str);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			theFile.append(line + '\n');
		}
		myfile.close();
	}
	else
		std::cout << "Unable to open file";

	loadFromString(theFile);

}

void Shader::loadFromString(std::string str)
{
	GLuint shader_t;
	switch (currentType)
	{
	case vertex: shader_t = GL_VERTEX_SHADER;
		break;
	case fragment: shader_t = GL_FRAGMENT_SHADER;
		break;
	case tessellation:
		break;
	case pixel:
		break;
	}
	shaderID = glCreateShader(shader_t);
	const char *strFileData = str.c_str();
	glShaderSource(shaderID, 1, &strFileData, NULL);

	glCompileShader(shaderID);

	GLint status;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(shaderID, infoLogLength, NULL, strInfoLog);

		const char *strShaderType = NULL;
		switch (shader_t)
		{
		case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
			//case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
		case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
		
		}

		fprintf(stderr, "Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog);
		delete[] strInfoLog;
	}

}

void Shader::destroyShader()
{
	glDeleteShader(shaderID);
}

GLuint Shader::getShaderID()
{
	return shaderID;
}

Shadertype Shader::getCurrentType()
{
	return currentType;
}

Shader::Shader(Shadertype type)
{
	currentType = type;
}



Shader::~Shader()
{
}
