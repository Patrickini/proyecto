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
	static Camera** mainCamera;
	Engine();
	~Engine();
	static void App(int height, int width, char* name);
	static int getWidth() { return WIDTH; }
	static int getHeight() { return HEIGHT; }
	static GLFWwindow* getWindow() { return window; }
	
};

