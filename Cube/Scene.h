#pragma once
class Scene
{
public:
	Scene();
	~Scene();

	virtual void start() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void destroyScene() = 0;
};

