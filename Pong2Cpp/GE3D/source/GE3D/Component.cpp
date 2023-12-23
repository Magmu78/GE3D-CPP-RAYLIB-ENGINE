#include <GE3D/Component.h>
#include <GE3D/GameManager.h>

Component::Component()
{
	name = "defaultCompName";
	enabled = true;
	attachedGameObject = nullptr;
}

void Component::Update(float deltaTime)
{
	assert(deltaTime >= 0 && "deltaTime is less than 0.");
}

void Component::AddCompToGlobalList()
{
	std::cout << "AddCompToGlobalList executed (from Component.cpp)" << std::endl;
}

void Component::SetName(std::string newName)
{
	name = newName;
}

std::string Component::GetName()
{
	return name;
}

ComponentType Component::GetType()
{
	return type;
}