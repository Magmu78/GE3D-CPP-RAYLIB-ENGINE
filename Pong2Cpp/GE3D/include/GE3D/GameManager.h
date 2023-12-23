#pragma once

#include <GE3D/RigidbodyComponent.h>
#include <GE3D/GameObject.h>
#include <GE3D/Cube.h>
#include <GE3D/Component.h>
#include <memory>
#include <vector>
#include "raylib.h"

class GameManager
{
public:
	GameManager();

	static std::vector<std::shared_ptr<RigidbodyComponent>> allRigidbodies;
	static std::vector<std::shared_ptr<Cube>> allCubes;
	static std::vector<std::shared_ptr<GameObject>> allGameObjects;

	void InitAppWindow(int, int, const char*);
	
	void Loop();
	void Cleanup();
};