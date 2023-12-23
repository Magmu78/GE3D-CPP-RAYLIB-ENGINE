#include <GE3D/TransformComponent.h>

TransformComponent::TransformComponent()
{
	name = "Transform";
	type = ComponentType::TransformComponent;
	position = { 0, 0, 0 };
	scale = { 1, 1, 1 };
	rotation = { 0, 0, 0, 0 };
}

void TransformComponent::Update(float deltaTime)
{

}