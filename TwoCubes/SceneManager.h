#pragma once
#include "Scene.h"

class SceneManager
{
private:
	static SceneManager* Instance;
	SceneManager();
	Scene* scene;
	Scene* nextScene;
public:
	
	~SceneManager();
	static SceneManager* GetInstance();
	void ChangeScene(Scene*const & _scene);

	bool isExecuting;
	void execution();
};

