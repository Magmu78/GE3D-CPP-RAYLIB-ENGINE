#pragma once

#include <GE3D/Component.h>
#include "raylib.h"

class Cube : public Component
{
public:
	Color color;

	Cube();

	void Update(float deltaTime) override;
	void Draw();
	//Cube(Vector3 position, Vector3 scale, Color color);
};

class Component;