#pragma once

#include <GE3D/Component.h>
#include <GE3D/TransformComponent.h>
#include <GE3D/GameManager.h>
#include <iostream>
#include <vector>

class GameObject
{
public:
	GameObject();
	//GameObject(const GameObject& copy) = delete;

	TransformComponent transform;
	std::vector<Component*> attached_components;
	static int idCounter;
	const char* name;
	bool selected;
	bool active;
	int id;
	
	void Update(float &deltaTime);
	void AddComponent(Component* newComponent);
	Component* GetComponent(Component component);
};