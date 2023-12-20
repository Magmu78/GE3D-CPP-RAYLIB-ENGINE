#pragma once

#include <GE3D/RigidbodyComponent.h>
#include <GE3D/GameObject.h>
#include <memory>
#include <vector>
#include "raylib.h"

class GameManager
{
public:
	GameManager();

	static std::vector<std::shared_ptr<Component>> allComponents;
	static std::vector<std::shared_ptr<GameObject>> allGameObjects;

	void InitAppWindow(int, int, const char*);
	
	void Loop();
	void Cleanup();
};