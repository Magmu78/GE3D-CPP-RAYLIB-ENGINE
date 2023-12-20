#pragma once

#include <GE3D/Component.h>
#include "raylib.h"

class TransformComponent : public Component
{
public:
	TransformComponent();

	Vector3 position;
	Quaternion rotation;
	Vector3 scale;
};