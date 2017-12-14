#include "Engine.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

GLFWwindow *Engine::window;
int Engine::HEIGHT;
int Engine::WIDTH;
Camera** Engine::mainCamera;
Engine::Engine()
{
}


Engine::~Engine()
{
}

void Engine::App(int height, int width, char* name)
{
	
	HEIGHT = height;
	WIDTH = width;
	glfwInit();
	if (!glfwInit()) {
		fprintf(stderr, "no se pudo inicializar GLFW3\n");
	}
	window = glfwCreateWindow(width, height, name, NULL, NULL);
	if (!window) {
		fprintf(stderr, "no se pudo abrir ventana\n");
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();


	const GLubyte* renderer = glGetString(GL_RENDERER);

	const GLubyte* version = glGetString(GL_RENDERER);

	printf("Renderer: %s\n", renderer);
	printf("Version: %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glDepthFunc(GL_LESS);
	SceneManager::GetInstance()->ChangeScene(new MainScene());
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();
		
		SceneManager::GetInstance()->execution();
		glfwSwapBuffers(window);
		std::this_thread::sleep_for(32ms);
	}

}
	