#include <GE3D/GameObject.h>
#include <memory>

int GameObject::idCounter = 0;

GameObject::GameObject() : name("NewGameObject"), selected(false), active(true), id(idCounter++)
{
    GameManager::allGameObjects.push_back(std::make_shared<GameObject>(*this));
}

void GameObject::Update(float& deltaTime)
{

}

void GameObject::AddComponent(Component* newComponent)
{
	attached_components.push_back(newComponent);
    newComponent->attachedGameObject = this;
}

Component* GameObject::GetComponent(Component component)
{
    for (Component* attachedComponent : attached_components)
    {
        if (attachedComponent->name == component.name)
        {
            return attachedComponent;
        }
    }

    return nullptr;
}