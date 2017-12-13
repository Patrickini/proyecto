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
	static bool anguloR;
	static double startX, startY;
	static Camera** mainCamera;
	Engine();
	~Engine();
	static void App(int height, int width, char* name);
	static GLFWwindow *getWindow();
};
static void cursorPosition(GLFWwindow*window, double xPos, double yPos);
void cursorEnterCallBack(GLFWwindow *window, int enter);
void mouseButtonCallBack(GLFWwindow *window, int button, int action, int mods);
void keyInput(GLFWwindow *window, int key, int scancode, int action, int mods);

