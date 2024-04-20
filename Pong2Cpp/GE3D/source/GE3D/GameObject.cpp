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
    //std::cout << "Updated from GameObject::Update function" << std::endl;
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
        newComponent = new RigidbodyComponent();
        break;

    case ComponentType::TransformComponent:
        newComponent = new TransformComponent();
        break;

    case ComponentType::CubeComponent:
        newComponent = new Cube();
        break;

    default:
        std::cerr << "Unknown Component Type\n";
        return;
    }

    if (newComponent->attachedGameObject == nullptr)
    {
        attached_components.push_back(newComponent);
        newComponent->attachedGameObject = this;
        switch (newComponent->GetType())
        {
        case ComponentType::CubeComponent:
            std::cout << "The type of component added is a cube component added" << std::endl;
        case ComponentType::RigidbodyComponent:
            std::cout << "The type of component added is a rigidbody component" << std::endl;
        default:
            break;
        }
    }
    else
    {
        std::cerr << "You are trying to add a component that is already attached to another GameObject. This is not allowed." << std::endl;
        delete newComponent;
    }
}

Component* GameObject::GetComponent(Component* component)
{
    for (Component* attachedComponent : attached_components)
    {
        if (attachedComponent->GetType() == component->GetType())
        {
            return attachedComponent;
        }
    }

    return nullptr;
}

Component* GameObject::GetComponent(ComponentType type)
{
    for (Component* attachedComponent : attached_components)
    {
        if (attachedComponent->GetType() == type)
        {
            return attachedComponent;
        }
    }

    return nullptr;
}