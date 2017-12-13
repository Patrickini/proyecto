#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "SceneManager.h"
#include "MainScene.h"
#include "Camera.h"

class Engine
{
private:
	static GLFWwindow *window;
	static int HEIGHT, WIDTH;
public:
	glm::vec3 tempX, tempY;
	static bool anguloH;
	static Camera** mainCamera;
	Engine();
	~Engine();
	static void App(int height, int width, char* name);
	
};
void keyInput(GLFWwindow *window, int key, int scancode, int action, int mods);

