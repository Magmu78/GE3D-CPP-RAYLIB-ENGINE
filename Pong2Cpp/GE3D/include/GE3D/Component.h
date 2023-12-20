#pragma once

#include <cassert>
#include <memory>

class GameObject;

class Component
{
public:
	Component();

	const char* name;
	bool enabled;
	GameObject* attachedGameObject;

	virtual void Update(float deltaTime);
	virtual void AddCompToGlobalList();
};