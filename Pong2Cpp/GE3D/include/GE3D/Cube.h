#pragma once

#include <GE3D/Component.h>
#include "raylib.h"

class Cube : public Component
{
public:
	Color color;

	Cube();
	Cube(Color _color) : color(_color) {};

	void Update(float deltaTime) override;
	void Draw();

	void AddCompToGlobalList() override;

	//Cube(Vector3 position, Vector3 scale, Color color);
};