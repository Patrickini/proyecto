#include "SceneManager.h"

SceneManager* SceneManager::Instance = nullptr;
SceneManager* SceneManager::GetInstance() {
	return Instance == nullptr ? Instance = new SceneManager() : Instance;
}

void SceneManager::ChangeScene(Scene*const & _scene) {
	isExecuting = false;
	if (!scene)
	{
		scene = _scene;
		return;
	}
	nextScene = _scene;
}

void SceneManager::execution() {
	//isExecuting = false;
	if (!isExecuting) {
		scene->start();
		isExecuting = true;
	}
	scene->update();
	scene->draw();
	if (!isExecuting) {
		scene->destroyScene();
		delete scene;
		scene = nextScene;
		nextScene = nullptr;

	}
}

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
	if (scene) {
		delete scene;
	}
	if (nextScene) {
		delete nextScene;
	}
}
