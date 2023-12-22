#include <GE3D/GameObject.h>
#include <GE3D/Cube.h>
#include <memory>
#include <exception>

int GameObject::idCounter = 0;

GameObject::GameObject() : name("NewGameObject"), selected(false), active(true), id(idCounter++)
{
    GameManager::allGameObjects.push_back(std::make_shared<GameObject>(*this));
    idCounter++;
}

GameObject::GameObject(const GameObject& copy) : active(copy.active), name(copy.name), selected(false)
{
    idCounter++;
}

void GameObject::Update(float& deltaTime)
{

}

void GameObject::AddComponent(Component* newComponent)
{
    if (newComponent->attachedGameObject == nullptr)
    {
        attached_components.push_back(newComponent);
        newComponent->attachedGameObject = this;
    }
    else
    {
        std::cerr << "You are trying to add a component that is already attached to another GameObject. This is not allowed." << std::endl;
    }
}

void GameObject::AddComponent(ComponentType componentType)
{
    Component* newComponent = nullptr;

    switch (componentType)
    {
    case ComponentType::RigidbodyComponent:
        newComponent = new RigidbodyComponent();  // Assuming RigidbodyComponent has a default constructor
        break;

    case ComponentType::TransformComponent:
        newComponent = new TransformComponent();  // Assuming TransformComponent has a default constructor
        break;

    case ComponentType::CubeComponent:
        newComponent = new Cube();  // Assuming CubeComponent has a default constructor
        break;

    default:
        std::cerr << "Unknown ComponentType\n";
        return;  // Do nothing for unknown component types
    }

    if (newComponent->attachedGameObject == nullptr)
    {
        attached_components.push_back(newComponent);
        newComponent->attachedGameObject = this;
    }
    else
    {
        std::cerr << "You are trying to add a component that is already attached to another GameObject. This is not allowed." << std::endl;
        delete newComponent;  // Clean up the allocated memory
    }
}

Component* GameObject::GetComponent(Component component)
{
    for (Component* attachedComponent : attached_components)
    {
        if (attachedComponent->GetName() == component.GetName())
        {
            return attachedComponent;
        }
    }

    return nullptr;
}