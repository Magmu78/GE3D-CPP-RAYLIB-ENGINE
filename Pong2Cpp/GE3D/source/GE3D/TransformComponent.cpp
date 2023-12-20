#include <GE3D/TransformComponent.h>

TransformComponent::TransformComponent()
{
	name = "Transform";
	position = { 0, 0, 0 };
	scale = { 1, 1, 1 };
	rotation = { 0, 0, 0, 0 };
}