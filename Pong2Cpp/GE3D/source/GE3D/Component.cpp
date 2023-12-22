#include <GE3D/Component.h>
#include <GE3D/GameManager.h>

Component::Component()
{
	name = "defaultCompName";
	enabled = true;
	attachedGameObject = nullptr;

	AddCompToGlobalList();
}

void Component::Update(float deltaTime)
{
	assert(deltaTime >= 0 && "deltaTime is less than 0.");
}

void Component::AddCompToGlobalList()
{
	GameManager::allComponents.push_back(std::make_shared<Component>(*this));
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