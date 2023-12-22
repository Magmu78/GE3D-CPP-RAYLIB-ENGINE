#include <GE3D/RigidbodyComponent.h>
#include <GE3D/GameObject.h>
#include <GE3D/GameManager.h>

RigidbodyComponent::RigidbodyComponent()
{
	name = "RigidbodyComponent";
	type = ComponentType::RigidbodyComponent;

	mass = 1;
	velocityY = 0;
	gravity = true;
	gravityStrength = 9.81f;
}

void RigidbodyComponent::Update(float deltaTime)
{
	if (attachedGameObject != nullptr)
	{
		if (gravity)
		{
			velocityY += mass * gravityStrength / 100 * deltaTime;
			attachedGameObject->transform.position.y -= velocityY;
		}
	}
}