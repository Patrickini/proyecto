#include "Shader_Loader.h"
#include <iostream>
#include <fstream>
#include <vector>


Core::Shader_Loader::Shader_Loader(void) 
{
}

Core::Shader_Loader::~Shader_Loader()
{
}

std::string Core::Shader_Loader::readShader(char *filename) {
	std::string shaderCode;
	std::ifstream file(filename, std::ios::in);// nuevo ifstream ios::in permite input operations

	if (!file.good()) {
		std::cout << "No se pudo leer el archivo" << filename << "\n";
		std::terminate();
	}

	file.seekg(0, std::ios::end);// seekg()[saltar a determinada posicion], 0,ios::end [ir al final del archivo]
	shaderCode.resize((unsigned int)file.tellg());// hacer shaderCode del tamaño de la posicion actual en el stream de file
	file.seekg(0, std::ios::beg); // (0,ios::beg) volver al principio
	file.read(&shaderCode[0], shaderCode.size()); //istream& read (char* s, streamsize n); extrae n caracteres y los guarda en s
	file.close();
	return shaderCode;
}

GLuint Core::Shader_Loader::createShader(GLenum shaderType, std::string source, char* shaderName) {

	int compile_result = 0;

	GLuint shader = glCreateShader(shaderType); //crea un objeto de shader vacio
	const char *shader_code_ptr = source.c_str(); //.c_str() extrae todos los caracteres no nulos del source en formato: const char *
	const int shader_code_size = source.size();

	glShaderSource(shader, 1, &shader_code_ptr, &shader_code_size); //glShaderSource(shader, count, shader_code, length) carga el objeto shader con el codigo, 1 es porque normalmente es un unico char array
	glCompileShader(shader); //compila el codigo
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_result);//checa errores y los muestra en consola

	//revisar en caso de error
	if (compile_result == GL_FALSE) {
		int info_log_length = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
		std::vector<char> shader_log(info_log_length);
		glGetShaderInfoLog(shader, info_log_length, NULL, &shader_log[0]);
		std::cout << "ERROR compiling shader: " << shaderName << std::endl << &shader_log[0] << std::endl;
		return 0;
	}
	return shader;
}
GLuint Core::Shader_Loader::createProgram(char* vertexShaderFilename, char* fragmentShaderFilename) {

	//leer los archivos de los shaders y guardar el codigo
	std::string vertex_shader_code = readShader(vertexShaderFilename);
	std::string fragment_shader_code = readShader(fragmentShaderFilename);

	GLuint vertex_shader = createShader(GL_VERTEX_SHADER, vertex_shader_code, "vertex shader");
	GLuint fragment_shader = createShader(GL_FRAGMENT_SHADER, fragment_shader_code, "fragment shader");

	int link_result = 0;

	//crear el programa, adjuntar los shaders y ligar el programa
	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_result); //revisa si se ligaron satisfactoriamente
	//revisar errores de link
	if (link_result == GL_FALSE) {
		int info_log_length = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);
		std::vector<char> program_log(info_log_length);
		glGetProgramInfoLog(program, info_log_length, NULL, &program_log[0]);
		std::cout << "Shader Loader : LINK ERROR \n" << &program_log[0] << "\n";
		return 0;
	}
	return program;
}
