#pragma once

#include <cassert>
#include <memory>
#include <string>
#include <GE3D/GE3DPrereqs.h>

class GameObject;

class Component
{
public:
	Component();

	bool enabled;

	GameObject* attachedGameObject;

	virtual void Update(float deltaTime) = 0;
	virtual void AddCompToGlobalList();
	
	//Sets the name of the component to the passed "newName" argument
	void SetName(std::string newName);
	//Returns the name of the component
	std::string GetName();
	//Returns the type of the component
	ComponentType GetType();
protected:
	//Name in the editor
	std::string name;
	//Type of the component (Rigidbody, Transform, etc...)
	ComponentType type;
};