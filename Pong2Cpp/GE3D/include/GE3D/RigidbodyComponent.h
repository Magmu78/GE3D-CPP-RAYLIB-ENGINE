#pragma once

#include <GE3D/Component.h>
#include "raylib.h"

class RigidbodyComponent : public Component
{
public:
    RigidbodyComponent();

	bool gravity;
    float gravityStrength;
    float mass;
    float velocityY;

    void Update(float deltaTime) override;
};