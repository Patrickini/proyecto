#include "Engine.h"

GLFWwindow *Engine::window;
int Engine::HEIGHT;
int Engine::WIDTH;
bool Engine::anguloH;
bool Engine::anguloR;
double Engine::startX;
double Engine::startY;

void keyInput(GLFWwindow *window, int key, int scancode, int action, int mods) {
	std::cout << Engine::anguloH << "\n";

	const GLfloat speed = 10;

	if (key == GLFW_KEY_SPACE) {
		switch (action) {
		case(GLFW_PRESS):
			//std::cout << "INPUT spaceKey Press \n";
			break;
		case(GLFW_REPEAT):
			//std::cout << "INPUT spaceKey Hold\n";
			break;
		case(GLFW_RELEASE):
			//std::cout << "INPUT spaceKey Release\n";
			break;
		}

	}
	if (key == GLFW_KEY_ESCAPE) {
		switch (action) {
		case(GLFW_PRESS):
			exit(0);
			break;
		case(GLFW_REPEAT):
			//std::cout << "INPUT spaceKey Hold\n";
			break;
		case(GLFW_RELEASE):
			//std::cout << "INPUT spaceKey Release\n";
			break;
		}

	}
	if (key == GLFW_KEY_Q) {
		switch (action) {
		case(GLFW_PRESS):
			//std::cout << "INPUT Q Press: ClearScreen\n";
			//clearColor();
			//clearColorFlag = true;
			//clearColorFlag = false;
			break;
		case(GLFW_REPEAT):
			//std::cout << "INPUT Q Hold\n";
			break;
		case(GLFW_RELEASE):
			//std::cout << "INPUT Q Release\n";
			break;
		}

	}
	if (key == GLFW_KEY_O) {
		switch (action) {
		case(GLFW_PRESS):
			//std::cout << "INPUT O Press: ViewSwitch\n";
			//orthoSwitchFlag = true;
			//clearColorFlag = false;
			break;
		case(GLFW_REPEAT):
			//std::cout << "INPUT Q Hold\n";
			break;
		case(GLFW_RELEASE):
			//std::cout << "INPUT Q Release\n";
			break;
		}

	}
	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		switch (key) {
		case GLFW_KEY_UP:
			//rotationX -= speed;
			
			break;
		case GLFW_KEY_DOWN:
			//rotationX += speed;
			break;
		case GLFW_KEY_RIGHT:
			//rotationY += speed;
			Engine::anguloH = true;
			//tempX = tempX + glm::vec3(1, 0, 0);
			break;
		case GLFW_KEY_LEFT:
			Engine::anguloR = true;
			/*Engine::anguloH = true;*/
			//tempX = tempX - glm::vec3(1, 0, 0);
			//rotationY -= speed;
			break;
		}
	}
	if (action == GLFW_RELEASE)
	{
		switch (key) {
		case GLFW_KEY_RIGHT:
			//rotationY += speed;
			Engine::anguloH = false;
			//tempX = tempX + glm::vec3(1, 0, 0);
			break;
		case GLFW_KEY_LEFT:
			//rotationY += speed;
			Engine::anguloR = false;
			//tempX = tempX + glm::vec3(1, 0, 0);
			break;
		}
	}
}

static void cursorPosition(GLFWwindow*window, double xPos, double yPos) {
	std::cout << "INPUT  x:" << xPos << "y:" << yPos << "\n";
	Engine::startX = xPos;
	Engine::startY = yPos;
	
}
void cursorEnterCallBack(GLFWwindow *window, int enter) {
	if (enter) {
		std::cout << "Dentro Ventana \n";
	}
	else {
		std::cout << "Fuera ventana \n";
	}
}
void mouseButtonCallBack(GLFWwindow *window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		std::cout << "Mouse RightButton Pressed \n";
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
		std::cout << "Mouse RightButton Released \n";
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		std::cout << "Mouse LeftButton Pressed \n";
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
		std::cout << "Mouse LeftButton Released \n";
	}
}



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
	window = glfwCreateWindow(height, width, name, NULL, NULL);
	if (!window) {
		fprintf(stderr, "no se pudo abrir ventana\n");
		glfwTerminate();
	}
	//////////////KEYBOARD//////////
	glfwSetKeyCallback(window, keyInput);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	//////////////MOUSE///////////////
	glfwSetCursorPosCallback(window, cursorPosition);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	glfwSetCursorEnterCallback(window, cursorEnterCallBack);
	glfwSetMouseButtonCallback(window, mouseButtonCallBack);
	glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, 1);

	//////////////FIN VIEJO/////////////

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
	}

}

GLFWwindow *Engine::getWindow()
{
	return window;
}
	