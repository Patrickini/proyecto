#include<iostream>
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include<SOIL.h>



int main() {
	if (!glfwInit()) {
		fprintf(stderr, "no se pudo inicializar GLFW3\n");
		return 1;
	}
	GLFWwindow *window = glfwCreateWindow(640, 480, "Holi", NULL, NULL);
	if (!window) {
		fprintf(stderr, "no se pudo abrir ventana\n");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();


	const GLubyte* renderer = glGetString(GL_RENDERER);

	const GLubyte* version = glGetString(GL_RENDERER);

	printf("Renderer: %s\n", renderer);
	printf("Version: %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	GLfloat points[] = {
		
		-0.5f,  0.5f,
		0.5f,  0.5f,
		0.5f, -0.5f,
		-0.5f, -0.5f
	};
	GLfloat colorPoints[] = {

		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	};
	GLfloat texCoords[] = {

		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	GLfloat points2[] = {

		-0.5f,  0.5f,
		0.5f,  0.5f,
		0.5f, -0.5f,
		-0.5f, -0.5f
	};
	GLfloat colorPoints2[] = {

		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	};
	GLfloat texCoords2[] = {

		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};
	int width1, height1;
	unsigned char* imagen1 =
		SOIL_load_image("uno.png", &width1, &height1, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width1, height1, 0, GL_RGB,
		GL_UNSIGNED_BYTE, imagen1);
	SOIL_free_image_data(imagen1);

	int width2, height2;
	unsigned char* imagen2 =
		SOIL_load_image("dos.png", &width2, &height2, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB,
		GL_UNSIGNED_BYTE, imagen2);
	SOIL_free_image_data(imagen2);

	/*GLfloat points[] = {
		 0.5f, 0.5f, 0.0f,
		-0.5f,-0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f,-0.5f, 0.0f
	};*/
	/*GLfloat points2[] = {
		 0.5f, 0.5f, 0.0f,
		-0.5f,-0.5f, 0.0f,
		 0.5f,-0.5f, 0.0f
	};*/

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	

	const char* vertex_shader =

		"#version 410\n"

		"in vec2 texcoord;"
		"out vec3 Color;"
		"out vec2 Texcoord;"

		"in vec3 vp;"
		"void main(){"
		"Texcoord = texcoord;"
		"gl_Position = vec4 (vp, 1.0);"
		"}";

	const char* fragment_shader =
		"#version 410\n"
		"out vec4 frag_colour;"
		"void main (){"
		"frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
		"}";

	
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);
	

	/*GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);*/
	
	

	
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vs);
	glAttachShader(shaderProgram, fs);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), 0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

	GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));

	
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE,
		7 * sizeof(float), 0);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE,
		7 * sizeof(float), (void*)(2 * sizeof(float)));

	

	//////////////////////////////////////////////////////////////////////////////////
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//glBindTexture(GL_TEXTURE_2D, imagen1);//no porque se pasa directo al shader
		//glUseProgram(shader_programme);
		glUseProgram(shaderProgram);
		glBindVertexArray(vao);
		//glDrawArrays(GL_QUADS, 0, 2 * 2);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}