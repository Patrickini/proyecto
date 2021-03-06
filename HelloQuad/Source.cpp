#include<iostream>
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#include "Setup.h"


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
		 0.5f, 0.5f, 0.0f,
		-0.5f,-0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f,-0.5f, 0.0f
	};
	GLfloat points2[] = {
		 0.5f, 0.5f, 0.0f,
		-0.5f,-0.5f, 0.0f,
		 0.5f,-0.5f, 0.0f
	};

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
		"in vec3 vp;"
		"void main(){"
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
	

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);
	

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shader_programme);
		glBindVertexArray(vao);
		glDrawArrays(GL_QUADS, 0, 2 * 2);




		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}